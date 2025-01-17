//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn];
void dfs(int now,int vis,int select){
	if(now >=n){
		if(select == m){
			for(int i=0;i<n;i++){
				if(vis >> i & 1){
					cout<<i+1<<" ";
				}
			}
			cout<<endl;
		}
		return ;
	}
	dfs(now+1,vis | 1<<now , select+1);
	dfs(now+1,vis,select);
}
int main(int argc, char * argv[]) 
{
    cin>>n>>m;
    dfs(0,0,0);
    return 0;
}