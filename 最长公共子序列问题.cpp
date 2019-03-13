//最长公共子序列问题（LCS问题） 
#include<iostream>
using namespace std;
const int MAX_N=1000,MAX_M=1000;
char s[MAX_N],t[MAX_M];
int dp[MAX_N+1][MAX_M+1];    //dp[i][j]对应t1t2...ti和s1s2...si的公共子序列长度     注意t1用t[0]表示，千万注意下标含义。 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	
	//初始化部分dp 
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int j=0;j<=m;j++){
		dp[0][j]=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i]==t[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}
			else{
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);  //还需理解 
			}
		}
	}
	
	cout<<dp[n][m]<<endl;
	
	return 0;
}


//测例：
//输入：4 4
//      abcd
//      becd
//输出：3





