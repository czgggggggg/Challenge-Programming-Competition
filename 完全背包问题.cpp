//�汾һ������ѭ�����㷨���Ӷ�O(n*w^2) 
/*#include<iostream>
using namespace std;
const int MAX_N=100,MAX_W=10000;//���������Ϊ100���������Ϊ10000
int dp[MAX_N+1][MAX_W+1];//dp���� 
int W[MAX_N],V[MAX_N];//ÿ����Ʒ�ļ�ֵ������ 
//dp[i+1][j]Ϊ��ǰi����Ʒ����ѡ��������������jʱ�ܼ�ֵ�����ֵ 

int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i]>>V[i];
	}
	for(int j=0;j<=w;j++){
		dp[0][j]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			for(int k=0;k*W[i]<=j;k++){
				dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*W[i]]+k*V[i]);
			}
		}
	}
	cout<<dp[n][w]<<endl;
	return 0;
}*/
//��������
//���룺3 7
//      3 4  4 5  2 3
//�����10

//�汾�����汾һ���ж���ļ��㡢ͨ���任����ʽ�����Խ�ʱ�临�ӶȽ��͵�O(n*w) 
/*#include<iostream>
using namespace std;
const int MAX_N=100,MAX_W=10000;//���������Ϊ100���������Ϊ10000
int dp[MAX_N+1][MAX_W+1];//dp���� 
int W[MAX_N],V[MAX_N];//ÿ����Ʒ�ļ�ֵ������ 
//dp[i+1][j]Ϊ��ǰi����Ʒ����ѡ��������������jʱ�ܼ�ֵ�����ֵ 

int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i]>>V[i];
	}
	for(int j=0;j<=w;j++){
		dp[0][j]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			if(j<W[i]){
				dp[i+1][j]=dp[i][j];
			}
			else{
				dp[i+1][j]=max(dp[i][j],dp[i+1][j-W[i]]+V[i]);
			}
		}
	}
	cout<<dp[n][w]<<endl;
	return 0;
}*/






