//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int dp[maxn];
int dd[maxn];
vector <pii> canh[maxn];
void dfs(int u)
{
    dp[u] = 0;
    dd[u] = 1;
    for (int i = 0; i < sz(canh[u]); i ++)
    {
        int v = canh[u][i].F;
        int w = canh[u][i].S;
        if(!dd[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + w);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        canh[u].PB({v, w});
    }
    for (int i = 1; i <= n; i ++)
        if(!dd[i]) dfs(i);
    cout << *max_element(dp + 1, dp + n + 1);
}
