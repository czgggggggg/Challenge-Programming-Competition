//区间调度问题
//问题描述：有n项工作，每项工作在Si时开始，在Ei时结束。请问在保证每项工作时间不重叠的情况下，最多能够完成几项工作。
//本例采用贪心算法
//每次选取工作是选取结束时间最近的那项工作。
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=100000;
int S[MAX_N],E[MAX_N];
pair<int,int> P[MAX_N];//pair数组用来按照最近完成时间排序 

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
		P[i].first=E[i];//注意完成时间在前，排序时按照第一项的大小进行排序。 
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
