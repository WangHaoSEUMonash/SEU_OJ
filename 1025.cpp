#include<cstdio>
#include<algorithm>
using namespace std;

int a[40005];
int d[40005];

int main()
{
    int M, n;
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if (n==0)  //0��Ԫ������һ��
        {
            printf("0\n");
            return 0;
        }
        d[1]=a[1];  //��ʼ��
        int len=1;
        for (int i=2;i<=n;i++)
        {
            if (a[i]>=d[len]) d[++len]=a[i];  //������Խ���len����ͽ���
            else  //�������һ������滻���滻��
            {
                int j=upper_bound(d+1,d+len+1,a[i])-d;  //�ҵ���һ����������d���±�
                d[j]=a[i];
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
