//�Թ����·������
//����BFS�㷨 
#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
const int INF=100000000;
const int MAX_N=100,MAX_M=100;
char maze[MAX_N][MAX_M];
int d[MAX_N][MAX_M];
int N,M;
typedef pair<int,int> P;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//���������ĸ����� 
int sx,sy,gx,gy;//���s��g����̾��� 

int bfs(){
	queue<P> que;//���д洢����pair<int,int>���͵����� 
	d[sx][sy]=0;
	que.push(P(sx,sy));
	
	while(que.size()){
		P p=que.front();
		que.pop();
		//if(maze[p.first][p.second]=='G')
		if(p.first==gx&&p.second==gy)
            break;
		for(int i=0;i<4;i++){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
				d[nx][ny]=d[p.first][p.second]+1;
				que.push(P(nx,ny));
			}
		}
	}
	return d[gx][gy];
	
} 


int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			//scanf("%c",&maze[i][j]);              //��֣�Ϊʲô��scanf�������룬ֻ������N-1�����ݣ� 
			cin>>maze[i][j];
			if(maze[i][j]=='S'){
				sx=i;
				sy=j;
			}
			else if(maze[i][j]=='G'){
				gx=i;
				gy=j;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			d[i][j]=INF;
		}
	}
	
	int res=bfs();
	
	printf("%d\n",res);
	
	return 0; 
} 

//����
/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G# 
*/ 

//��Ϊ22
//����ͨ�� 






