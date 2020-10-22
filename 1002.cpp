#include <iostream>
#include <algorithm>
using namespace std;

int main()
 {
    int n,i,a[100],m;
    cin >> m;
    for(int j = 0; j < m; j++)
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        unique(a,a+n);
        cout<<a[1]<<endl;
    }
    return 0;
 }
