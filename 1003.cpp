#include <iostream>
using namespace std;

int main()
 {
    int n, i, j, a[101], m;
    cin >> m;
    for(int j = 0; j < m; j++)
    {
        cin >> n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i = 0; i < n; i++)
        {
            if(i < n - 1 && a[i] > a[i +1])
            {
                int temp = a[i];
                a[i] = a[i +1];
                a[i + 1] = temp;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i == n-1) cout << a[i] << endl;
            else cout << a[i] << ' ';
        }
    }
    return 0;
 }
