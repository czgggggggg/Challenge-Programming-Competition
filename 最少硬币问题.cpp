//Ӳ������
//̰���㷨
//#include<cstdio>
#include<iostream>
using namespace std;
const int V[6]={1,5,10,50,100,500};

int main(){
	int C[6];
	for(int i=0;i<6;i++){
		//scanf("%d",&C[i]);
		cin>>C[i];
	}
	int Money;
	//scanf("%d",&Money);
	cin>>Money;
	
	int ans=0;//ʹ��Ӳ��ö�� 
	for(int i=5;i>=0;i--){
		int t=min(Money/V[i],C[i]);
		ans+=t;
		Money-=(t*V[i]);
	}
	
	//printf("%d\n",ans);
	cout<<ans<<endl;
	return 0;
}


//��������
// ���룺3 2 1 3 0 2    620
// �����6 

