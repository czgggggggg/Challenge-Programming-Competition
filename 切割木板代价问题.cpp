//�и�ľ���������
//����������һ��ľ��Ҫ�и��n�鳤�ȷֱ�ΪL1��L2��L3��...��Ln��ľ�壬ÿ���и�һ������Ϊ����ľ��ĳ��ȣ�����С�ܴ���Ϊ���٣� 
#include<iostream>
using namespace std;
typedef long long ll;
const int MAX_N=20000;
int L[MAX_N];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>L[i];
	}
	int min1,min2;//���ľ�塢�ζ�ľ��
	
	int ans=0;
	int temp;
	while(n>1){
		min1=0,min2=1;
		if(L[min1]>L[min2]){
			swap(L[min1],L[min2]);
		}
		
		for(int i=2;i<n;i++){                    //ע��Ҳ����ֱ�ӽ����±� 
			if(L[i]<L[min1]){
				temp=L[min2];
				L[min2]=L[min1];
				L[min1]=L[i];
				L[i]=temp;
			}
			else{
				if(L[i]<L[min2]){
					temp=L[min2];
					L[min2]=L[i];
					L[i]=temp;
				}
			}
		}
		
		int t=L[min1]+L[min2];//�ϲ���̺ʹζ̵�ľ��
		ans+=t; 
		
		if(min1==n-1){
			swap(min1,min2);
		}
		L[min1]=t;
		L[min2]=L[n-1];
        
		n--;//ÿ�κϲ�����ľ������һ�� 
	}
	
	cout<<ans<<endl;
	return 0;
} 


//������3
//      8 5 8
//�����34
 
