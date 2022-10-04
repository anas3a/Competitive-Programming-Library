// Bellman Ford SSSP - O(NM)

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

struct edge
{
    int a, b;
    ll cost;
};
vector<edge> e;
vector<ll> d;
void BellmanFord(int s, int n, int m)
{
    d.clear();
    d.resize(n, LLONG_MAX);
    d[s] = 0;
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < m; j++)
        {
            if (d[e[j].a] < LLONG_MAX && d[e[j].b] > d[e[j].a] + e[j].cost)
            {
                d[e[j].b] = max(-LLONG_MAX, d[e[j].a] + e[j].cost);
                p[e[j].b] = e[j].a;
                x = e[j].b;
            }
        }
    }
    if (x == -1)
        cout << "No negative cycle from " << s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    e.resize(m);
    for (int i = 0; i < m; i++)
        cin >> e[i].a >> e[i].b >> e[i].cost;
    return 0;
}
