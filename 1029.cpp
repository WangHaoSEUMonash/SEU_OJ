#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans;
struct node
{
	int f,t,d;
}a[200005];//��ߣ�Kruskal���ý�ͼ
bool cmp(node x,node y){return x.d<y.d;}
struct bin
{
	int w[5005];
	int find(int x)
	{
   		if(x==w[x]) return x;
	    w[x]=find(w[x]);
   		return w[x];
	}
	void add(int x,int y)
	{
    	w[find(x)]=find(y);
   		return ;
	}
	bool ask(int x,int y)
	{
   		if(find(x)==find(y)) return true;
    	else return false;
	}
}b;//���鼯
int main()
{
    int M;
    scanf("%d", &M);
    for(int ab = 0; ab < M; ab++)
    {
    ans = 0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].f,&a[i].t,&a[i].d);
	for(int i=1;i<=n;i++) b.w[i]=i;//���鼯��ʼ��
	sort(a+1,a+m+1,cmp);//����Ȩ����
	for(int i=1;i<=m;i++)//ö��ÿ����
	{
		if(b.ask(a[i].f,a[i].t)) continue;//��ͨ������
		ans+=a[i].d;//�����¼
		b.add(a[i].f,a[i].t);//��Ϊ��ͨ
	}
	for(int i=2;i<=n;i++)
		if(!b.ask(1,n))
		{
			printf("-1\n");
			break;
		}//�ж��Ƿ���ͨ
    if(b.ask(1,n))
        printf("%d\n",ans);
    }
	return 0;
}
