//�㷨˼�����Ƕ��ˣ����ǲ���һֱ���󣬺����ϵĴ�����ȫû�г��룬���˰��Сʱ�������Ҳ���������������⡣ 
//�պ���д��ʱ��ϣ���ܹ����֡� 
//���ĵ�ë��һ��Ҫ�ı䣬��Ϊ��ĸ�����ų������˺ܾá� 
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
			    //field[nx][ny]='.';//��仰���࣬����Ҫ 
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
