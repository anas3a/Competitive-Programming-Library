// Maximum flow - Edmonds-Karp - O(VE^2)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int n;
vector<vector<ll>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, ll>> q;
    q.push({s, LLONG_MAX});
    while (!q.empty())
    {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

ll EdmondKarp(int s, int t)
{
    ll flow = 0;
    vector<int> parent(n);
    ll new_flow;
    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;
    adj.resize(n);
    capacity.resize(n, vll(n, 0));
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b] += c;
    }
    cout << EdmondKarp(0, n - 1) << nl;
    return 0;
}
