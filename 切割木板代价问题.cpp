//切割木板代价问题
//问题描述：一块木板要切割成n块长度分别为L1、L2、L3、...、Ln的木板，每次切割一刀代价为所切木板的长度，问最小总代价为多少？ 
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
	int min1,min2;//最短木板、次短木板
	
	int ans=0;
	int temp;
	while(n>1){
		min1=0,min2=1;
		if(L[min1]>L[min2]){
			swap(L[min1],L[min2]);
		}
		
		for(int i=2;i<n;i++){                    //注意也可以直接交换下标 
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
		
		int t=L[min1]+L[min2];//合并最短和次短的木板
		ans+=t; 
		
		if(min1==n-1){
			swap(min1,min2);
		}
		L[min1]=t;
		L[min2]=L[n-1];
        
		n--;//每次合并后，总木板数减一。 
	}
	
	cout<<ans<<endl;
	return 0;
} 


//测例：3
//      8 5 8
//结果：34
 
