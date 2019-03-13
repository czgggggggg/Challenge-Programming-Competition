//��������������⣨LCS���⣩ 
#include<iostream>
using namespace std;
const int MAX_N=1000,MAX_M=1000;
char s[MAX_N],t[MAX_M];
int dp[MAX_N+1][MAX_M+1];    //dp[i][j]��Ӧt1t2...ti��s1s2...si�Ĺ��������г���     ע��t1��t[0]��ʾ��ǧ��ע���±꺬�塣 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	
	//��ʼ������dp 
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
				dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);  //������� 
			}
		}
	}
	
	cout<<dp[n][m]<<endl;
	
	return 0;
}


//������
//���룺4 4
//      abcd
//      becd
//�����3





