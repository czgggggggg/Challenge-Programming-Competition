//版本一：三重循环、算法复杂度O(n*w^2) 
/*#include<iostream>
using namespace std;
const int MAX_N=100,MAX_W=10000;//最大种类数为100，最大重量为10000
int dp[MAX_N+1][MAX_W+1];//dp数组 
int W[MAX_N],V[MAX_N];//每种物品的价值和重量 
//dp[i+1][j]为从前i种物品中挑选出总重量不超过j时总价值的最大值 

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
//测试数据
//输入：3 7
//      3 4  4 5  2 3
//输出：10

//版本二：版本一中有多余的计算、通过变换递推式，可以将时间复杂度降低到O(n*w) 
/*#include<iostream>
using namespace std;
const int MAX_N=100,MAX_W=10000;//最大种类数为100，最大重量为10000
int dp[MAX_N+1][MAX_W+1];//dp数组 
int W[MAX_N],V[MAX_N];//每种物品的价值和重量 
//dp[i+1][j]为从前i种物品中挑选出总重量不超过j时总价值的最大值 

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






