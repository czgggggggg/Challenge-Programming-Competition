//���ֺ����⣨����������ȱ����㷨DFS�� 
//����n����������������е����ĺ��Ƿ��ܹ�Ϊm�� 
#include<cstdio>
using namespace std;
const int MAX_N=25;
int n,m;
int a[MAX_N];
bool dfs(int i,int sum){//ǰi���еĲ��ֺ�Ϊsum 
	if(i==n)//n��Ԫ�ز��ֺ� 
	    return sum==m;
	if(dfs(i+1,sum))//������a[i]����� 
	    return true;
	if(dfs(i+1,sum+a[i+1]))//����a[i]����� 
	    return true;
	return false;//����a[i]��������a[i]������������㣬�򷵻�false��������ǰ�����֧�� 
} 
int main(){
	scanf("%d%d",&n,&m);
	int num=0;//��ʼ��Ϊ0 
	a[0]=0;//ע�������±�Ϊ���Ԫ��ֵ����Ϊ0��
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	bool f=dfs(0,0);
	if(f)
	    printf("Yes.\n");
	else
	    printf("No.\n");
	return 0;
}
