//�����������
//������������n�����ÿ�����Siʱ��ʼ����Eiʱ�����������ڱ�֤ÿ���ʱ�䲻�ص�������£�����ܹ���ɼ������
//��������̰���㷨
//ÿ��ѡȡ������ѡȡ����ʱ��������������
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=100000;
int S[MAX_N],E[MAX_N];
pair<int,int> P[MAX_N];//pair������������������ʱ������ 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	for(int i=0;i<n;i++){
		cin>>E[i];
	}
	for(int i=0;i<n;i++){
		P[i].first=E[i];//ע�����ʱ����ǰ������ʱ���յ�һ��Ĵ�С�������� 
		P[i].second=S[i];
	}
	sort(P,P+n);
	
	int t=0,ans=0;
	for(int i=0;i<n;i++){
		if(t<P[i].second){
			t=P[i].first;
			ans++;
		}
	}
	
	cout<<ans<<endl;
	return 0;
} 
