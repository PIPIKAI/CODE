#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e4+7;
const int inf = 0x3f3f3f3f;
int f[107],dp[maxn];
int n,sum,ans;
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>f[i];
        sum+=f[i];
    }
    for(int i=0;i<n;i++){
        for(int V=(sum/2);V>=f[i];V--){
            int vv=abs(V-f[i]);// 体积，f[i] 为价值
            dp[V]=max(dp[V],dp[vv]+f[i]);
            ans=max(ans,dp[V]);// 找到体积为sum/2，的最大的价值
        }
    }
    cout<<abs(ans*2-sum)<<'\n';
    return 0;
}