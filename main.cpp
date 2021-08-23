//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,-1,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD 1000000007
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int dp[maxn];
int dd[maxn];
vector <int> canh[maxn];
void add (int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
void dfs(int u)
{
    dp[u] = 0;
    dd[u] = 1;
    for (int i = 0; i < sz(canh[u]); i ++)
    {
        int v = canh[u][i];
        if(!dd[v]) dfs(v);
        add(dp[u], dp[v] + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        canh[u].PB(v);
    }
    for (int i = 1; i <= n; i ++)
        if(!dd[i]) dfs(i);
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        add(sum, dp[i]);
    cout << sum;
}
