#include <iostream>
#include <string>
#include <stack>
using namespace std;

void LCS(string s1,string s2)
{
    int m=s1.length()+1;
    int n=s2.length()+1;
    int **c;
    int **b;
    c=new int* [m];
    b=new int* [m];
    for(int i=0;i<m;i++)
    {
        c[i]=new int [n];
        b[i]=new int [n];
        for(int j=0;j<n;j++)
            b[i][j]=0;
    }
    for(int i=0;i<m;i++)
        c[i][0]=0;
    for(int i=0;i<n;i++)
        c[0][i]=0;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s1[i]==s2[j])
            {
                c[i+1][j+1]=c[i][j]+1;
                b[i+1][j+1]=1;          //1表示箭头为  左上
            }
            else if(c[i][j+1]>=c[i+1][j])
            {
                c[i+1][j+1]=c[i][j+1];
                b[i+1][j+1]=2;          //2表示箭头向  上
            }
            else
            {
                c[i+1][j+1]=c[i+1][j];
                b[i+1][j+1]=3;          //3表示箭头向  左
            }
        }
    }
    cout << c[m - 1][n -1] << endl;
    stack<char> same;                   //存LCS字符
    stack<int> same1,same2;             //存LCS字符在字符串1和字符串2中对应的下标，方便显示出来
    for(int i = m-1,j = n-1;i >= 0 && j >= 0; )
    {
        if(b[i][j] == 1)
        {
            i--;
            j--;
            same.push(s1[i]);
            same1.push(i);
            same2.push(j);
        }
        else if(b[i][j] == 2)
                i--;
             else
                j--;
    }

    for (int i = 0; i<m; i++)
    {
        delete [] c[i];
        delete [] b[i];
    }
    delete []c;
    delete []b;
}

int main()
{
    int M, i, j;
    string s1, s2;
    cin >> M;
    for(i = 0; i < M; i++)
    {
        cin >> s1 >> s2;
        LCS(s1, s2);
    }
    return 0;
}
