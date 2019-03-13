//01��������
//������������n����Ʒ�����Ǹ��Ե������ͼ�ֵ�ֱ���w1,w2,...,wn,v1,v2,...vn��
//          ��һ������Ϊw�ı�������������������װ����ټ�ֵ����Ʒ�� 

//�汾1 
//������ȱ������ݹ麯�� 
//ʱ�临�Ӷ�O(2^n) 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
int W[MAX_N+1],V[MAX_N+1];//�ֱ��¼������Ʒ�������ͼ�ֵ 
int n;//ע����Ϊ���������ⶨ���rec������Ҫ�õ�n��������������һ��ȫ�ֱ����� 
	
	//�ӵ�i����Ʒ��ʼ��0~i-1�Ѿ�����ѡ����ѡ������С�ڵ���j����Ʒ
	int rec(int i,int j){//�ݹ麯�� 
	    int res=0;//ע��res������rec�����ڶ��� 
		if(i==n){
			res=0;
		}
		else if(j<W[i]){//����Ŀǰ�޷��Ž�W[i]��������Ʒ 
			res=rec(i+1,j);//�򲻷���i��Ʒ���������еݹ顣 
		}
		else{//����Ŀǰ�ܹ��Ž�W[i]��������Ʒ 
			res=max(rec(i+1,j),rec(i+1,j-W[i])+V[i]);//��Ƚϲ�����ͷ�����ܼ�ֵ 
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

	cout<<rec(0,w)<<endl;//��0����Ʒ��ʼ��������������w����Ʒ��
	
	return 0;
}*/
//������
//���룺4 5
//      2 1 3 2
//      3 2 4 2 
//�����7 



//�汾2�����ü��仯����
//������ȱ������ݹ麯�������ü��仯��������ظ��ݹ���ͬ����� 
// ʱ�临�Ӷ�O(n*w)
/*#include<iostream>
#include<string.h>//memset����ԭ���ڴ�ͷ�ļ��� 
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//�ֱ��¼������Ʒ�������ͼ�ֵ 
int dp[MAX_N+1][MAX_W+1];//���仯���� 
int n;

	//�ӵ�i����Ʒ��ʼ��0~i-1�Ѿ�����ѡ����ѡ������С�ڵ���j����Ʒ
	int rec(int i,int j){//�ݹ麯�� 
	    if(dp[i][j]>=0){//���֮ǰ�Ѿ����������ֱ��ʹ���Ѿ������ŵĽ���� 
	    	return dp[i][j];
	    }
	    int res=0;//ע��res������rec�����ڶ��� 
		if(i==n){
			res=0;
		}
		else if(j<W[i]){//����Ŀǰ�޷��Ž�W[i]��������Ʒ 
			res=rec(i+1,j);//�򲻷���i��Ʒ���������еݹ顣 
		}
		else{//����Ŀǰ�ܹ��Ž�W[i]��������Ʒ 
			res=max(rec(i+1,j),rec(i+1,j-W[i])+V[i]);//��Ƚϲ�����ͷ�����ܼ�ֵ 
		}
		return dp[i][j]=res;//��������浽���仯�����в����ء� 
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
	
	memset(dp,-1,sizeof(dp));//-1��ʾδ���������ʼ���������顣 
	
    cout<<rec(0,w)<<endl;
	
	return 0;
} 
*/ 
 
 

//�汾3 
//��д�ݹ麯����ֱ���õ���ʽ�������ֵ����������򵥵����ö���ѭ����                 //�汾3��i��ѭ��������ģ����ɴ�С�� 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//�ֱ��¼������Ʒ�������ͼ�ֵ 
int dp[MAX_N+1][MAX_W+1];//���仯���� 

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
				dp[i][j]=0;//��n��Ʒ��ʼ��������С�ڵ���j����Ʒ����Ϊn��Ʒ�����ڣ����Գ�ʼ��Ϊ0�� 
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


//�汾4
//ͬ�汾3������i������ġ�            //��������⣬����Ӧ�����7������ֻ�����6����ʱ��û�з�����ʲô�����պ��ٸġ� 
/*#include<iostream>
using namespace std;
const int MAX_N=100;
const int MAX_W=10000;
int W[MAX_N+1],V[MAX_N+1];//�ֱ��¼������Ʒ�������ͼ�ֵ 
int dp[MAX_N+1][MAX_W+1];//���仯���� 

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
				dp[i][j]=0;//��0~i-1��i����Ʒ����������Ʒi����ʼ��������С�ڵ���j����Ʒ����ΪС��0����Ʒ�����ڣ����Գ�ʼ��Ϊ0�� 
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
 
 
 
 
 
