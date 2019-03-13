//01背包问题
//问题描述：有n个物品，它们各自的重量和价值分别是w1,w2,...,wn,v1,v2,...vn。
//          有一个容量为w的背包，问这个背包最多能装入多少价值的物品。 

//版本1 
//深度优先遍历、递归函数 
//时间复杂度O(2^n) 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
int W[MAX_N+1],V[MAX_N+1];//分别记录所有物品的重量和价值 
int n;//注意因为在主函数外定义的rec函数中要用到n，所以这里设置一个全局变量。 
	
	//从第i个物品开始（0~i-1已经被挑选）挑选总重量小于等于j的物品
	int rec(int i,int j){//递归函数 
	    int res=0;//注意res变量在rec函数内定义 
		if(i==n){
			res=0;
		}
		else if(j<W[i]){//背包目前无法放进W[i]重量的物品 
			res=rec(i+1,j);//则不放入i物品，继续进行递归。 
		}
		else{//背包目前能够放进W[i]重量的物品 
			res=max(rec(i+1,j),rec(i+1,j-W[i])+V[i]);//则比较不放入和放入的总价值 
		}
		return res;
	} 
	
int main(){
	int w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i];
	}
	for(int i=0;i<n;i++){
		cin>>V[i];
	}

	cout<<rec(0,w)<<endl;//从0个物品开始放入重量不超过w的物品。
	
	return 0;
}*/
//测例：
//输入：4 5
//      2 1 3 2
//      3 2 4 2 
//输出：7 



//版本2：利用记忆化数组
//深度优先遍历、递归函数、利用记忆化数组避免重复递归相同的情况 
// 时间复杂度O(n*w)
/*#include<iostream>
#include<string.h>//memset函数原型在此头文件中 
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//分别记录所有物品的重量和价值 
int dp[MAX_N+1][MAX_W+1];//记忆化数组 
int n;

	//从第i个物品开始（0~i-1已经被挑选）挑选总重量小于等于j的物品
	int rec(int i,int j){//递归函数 
	    if(dp[i][j]>=0){//如果之前已经计算过，则直接使用已经保留着的结果。 
	    	return dp[i][j];
	    }
	    int res=0;//注意res变量在rec函数内定义 
		if(i==n){
			res=0;
		}
		else if(j<W[i]){//背包目前无法放进W[i]重量的物品 
			res=rec(i+1,j);//则不放入i物品，继续进行递归。 
		}
		else{//背包目前能够放进W[i]重量的物品 
			res=max(rec(i+1,j),rec(i+1,j-W[i])+V[i]);//则比较不放入和放入的总价值 
		}
		return dp[i][j]=res;//将结果保存到记忆化数组中并返回。 
	} 

int main(){
	int w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i];
	}
	for(int i=0;i<n;i++){
		cin>>V[i];
	}
	
	memset(dp,-1,sizeof(dp));//-1表示未计算过，初始化整个数组。 
	
    cout<<rec(0,w)<<endl;
	
	return 0;
} 
*/ 
 
 

//版本3 
//不写递归函数，直接用递推式将各项的值计算出来、简单的利用二重循环。                 //版本3中i的循环是逆向的，即由大到小。 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//分别记录所有物品的重量和价值 
int dp[MAX_N+1][MAX_W+1];//记忆化数组 

int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i];
	}
	for(int i=0;i<n;i++){
		cin>>V[i];
	}
	
	for(int i=n;i>=0;i--){
		for(int j=0;j<=w;j++){
			if(i==n){
				dp[i][j]=0;//从n物品开始放入重量小于等于j的物品。因为n物品不存在，所以初始化为0。 
			}
			else if(j<W[i]){
				dp[i][j]=dp[i+1][j];
			}
			else{
				dp[i][j]=max(dp[i+1][j],dp[i+1][j-W[i]]+V[i]); 
			}
		}
	}
	
	cout<<dp[0][w]<<endl;
	
	return 0;
}*/


//版本4
//同版本3、这里i是正向的。            //输出有问题，测例应该输出7，这里只是输出6。暂时还没有发现有什么错误，日后再改。 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//分别记录所有物品的重量和价值 
int dp[MAX_N+1][MAX_W+1];//记忆化数组 

int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>W[i];
	}
	for(int i=0;i<n;i++){
		cin>>V[i];
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0){
				dp[i][j]=0;//从0~i-1这i个物品（不包括物品i）开始放入重量小于等于j的物品。因为小于0的物品不存在，所以初始化为0。 
			}
			else if(j<W[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+V[i]); 
			}
		}
	}
	
	cout<<dp[n][w]<<endl;
	
	return 0;
}*/
 
 
 
 
 
