#include<bits/stdc++.h>
using namespace std;
const int maxn=20+7,maxm=1<<20;
int n;
int dp[maxm][maxn],w[maxn][maxn];
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>w[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++){
			if(i>>j & 1){
				for(int k=0;k<n;k++){
					if(i^(1<<j) >> k & 1){
						dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+w[k][j]);
					}
				}
			}
		}
	}
	cout<<dp[(1<<n)-1][n-1]<<endl;
	return 0;
}