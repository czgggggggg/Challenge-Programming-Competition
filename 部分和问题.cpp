//部分和问题（采用深度优先遍历算法DFS） 
//共有n个数，问任意个其中的数的和是否能够为m？ 
#include<cstdio>
using namespace std;
const int MAX_N=25;
int n,m;
int a[MAX_N];
bool dfs(int i,int sum){//前i项中的部分和为sum 
	if(i==n)//n个元素部分和 
	    return sum==m;
	if(dfs(i+1,sum))//不加上a[i]的情况 
	    return true;
	if(dfs(i+1,sum+a[i+1]))//加上a[i]的情况 
	    return true;
	return false;//加上a[i]，不加上a[i]的情况都不满足，则返回false，放弃当前这个分支。 
} 
int main(){
	scanf("%d%d",&n,&m);
	int num=0;//初始和为0 
	a[0]=0;//注意数组下标为零的元素值设置为0；
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
