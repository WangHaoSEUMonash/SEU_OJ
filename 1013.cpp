#include<iostream>
using namespace std;
#define MAX_VALUE 12343564
int Count_Reversations(int *A, int n);
int Merge_Reversations(int *A, int p, int r);
/*int main(){
     int a[6] = { 85,16,44,99,66,1 };
     cout << Count_Reversations(a, 6) << endl;
     return 0;
}*/
int main()
{
    int M = 0, N = 0, a[50001] = { 0 };
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> N;
        for(int j = 0; j < N; j++)
            cin >> a[j];
        cout << Count_Reversations(a, N) << endl;
        N = 0;
    }
    return 0;
}
int Count_Reversations(int*A, int n){ //接口函数
     return Merge_Reversations(A, 0, n - 1);
}
int Merge_Reversations(int *A, int p, int r){
     if (p>=r)
          return 0;
     int i, j, k,mid,n1,n2, reversations = 0;
     mid = (p + r) >> 1;
     int next_count= Merge_Reversations(A, p, mid) + Merge_Reversations(A, mid + 1, r);
     n1 = mid - p + 1;
     n2 = r - mid;
     int *R = new int[n2 + 1];
     int *L = new int[n1 + 1];
     for (i = 0; i < n1; i++)
          L[i] = A[i + p];
     for (j = 0; j < n2; j++)
          R[j] = A[j + mid + 1];
     L[n1] = R[n2] = MAX_VALUE; //设置为最大值，当做哨兵
     i = j = 0;
     for (k = p; k <= r; k++){
          if (L[i]>R[j]){
                 reversations +=n1-i;
                 A[k] = R[j++];
     }
     else
         A[k] = L[i++];
}
    delete[]R, L;
    return reversations +next_count;
}
