#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
string s[8]={"00000000","00001111","00111100","00110011","01100110","01101001","01011010","01010101"};
int main()
{
    std::ios::sync_with_stdio(false);
   
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
          cout<<s[i][j]<<"  ";
      }
      cout<<endl;
   }
    return 0;
}