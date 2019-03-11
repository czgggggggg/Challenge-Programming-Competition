//算法思想我是懂了，但是测试一直错误，和书上的代码完全没有出入，花了半个小时，就是找不出来是哪里的问题。 
//日后再写的时候希望能够发现。 
//粗心的毛病一定要改变，因为字母、符号出错耽搁了很久。 
#include<cstdio>
using namespace std;
const int MAX_N=100,MAX_M=100;
int n,m;
int res;
char field[MAX_N][MAX_M];

void dfs(int x,int y){
	field[x][y]='.';
	for(int dx=-1;dx<=1;dx++){
		for(int dy=-1;dy<=1;dy++){
			int nx=x+dx,ny=y+dy;
			if(0<=nx&&nx<n&&0<=ny&&ny<m&&field[nx][ny]=='W'){
			    //field[nx][ny]='.';//这句话多余，不需要 
			    dfs(nx,ny);
			}
		}
	}
	return;
} 

int solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(field[i][j]=='W'){
				dfs(i,j);
				//printf("Hello:%d,%d\n",i,j);
				res++;
			}
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&field[i][j]);
		}
	}
	
	res=0;
	
	res=solve();
	
	printf("%d\n",res);
	
	return 0;
} 
