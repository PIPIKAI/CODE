#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,f[100002];
    for(i=0;i<n;i++)
        cin>>f[i];

    sort(f,f+n);
    for(i=0;i<n;i++)
        cout<<f[i]<<" ";
    return 0;
}
