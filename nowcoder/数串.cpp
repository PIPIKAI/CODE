#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    return a+b > b+a;
}
int main()
{
    string s[200];
    int n;
    while(cin>>n)
    {
       for(int i=0;i<n;i++) cin>>s[i];
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++) cout<<s[i];
        cout<<endl;
    }
    return 0;
}
