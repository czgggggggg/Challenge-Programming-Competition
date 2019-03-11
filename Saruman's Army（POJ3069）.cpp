/*#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=1000;
int x[MAX_N];

int main(){
	int n;//输入直线上点的个数 
	cin>>n;
	int r;//输入半径 
	cin>>r;
	for(int i=0;i<n;i++){//输入所有点的下标 
		cin>>x[i];
	} 
	sort(x,x+n);//将所有点从大到小排序 

	
	int ans=0;
	
	int i=0; 
	while(i<n){
		int s=x[i++];//s是从左边起第一个半径r范围内没有标记点的点。
		while(i<n&&x[i]<=s+r){//和s的距离小于等于r 
			i++;
		}
		//此时x[i]的已经在s半径r范围之外，且是第一个点。
		int p=x[i-1];//在s点添加笔记以后，p点是s点半径r范围内最远能接触到的点。即p点不需要标记。
		//注意此时想x[i]是p点下一点的坐标。 
		while(i<n&&x[i]<=p+r){//如果满足该条件的点添加了标记，则p还能被右侧标记点触及到。 
			i++;
		} 
		//此时i代表的点添加了标记也无法触及到p点。
		//此时i-1代表的点能够触及到p点，如果该点添加了标记，则p和i之间的点都能满足条件。 
		ans++;//此时为s点添加标记 
	}
	
	cout<<ans<<endl;
	return 0;
}*/


//下面的代码实现测试多组数据，直到输入n=-1&&r==-1为止。 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=1000;
int x[MAX_N];

int main(){
	int r;//输入半径 
	cin>>r;
	int n;//输入直线上点的个数 
	cin>>n;

while(r!=-1&&n!=-1){
	for(int i=0;i<n;i++){//输入所有点的下标 
		cin>>x[i];
	} 
	sort(x,x+n);//将所有点从大到小排序 

	
	int ans=0;
	
	int i=0; 
	while(i<n){
		int s=x[i++];//s是从左边起第一个半径r范围内没有标记点的点。
		while(i<n&&x[i]<=s+r){//和s的距离小于等于r 
			i++;
		}
		//此时x[i]的已经在s半径r范围之外，且是第一个点。
		int p=x[i-1];//在s点添加笔记以后，p点是s点半径r范围内最远能接触到的点。即p点不需要标记。
		//注意此时想x[i]是p点下一点的坐标。 
		while(i<n&&x[i]<=p+r){//如果满足该条件的点添加了标记，则p还能被右侧标记点触及到。 
			i++;
		} 
		//此时i代表的点添加了标记也无法触及到p点。
		//此时i-1代表的点能够触及到p点，如果该点添加了标记，则p和i之间的点都能满足条件。 
		ans++;//此时为s点添加标记 
	}
	
	cout<<ans<<endl;
	cin>>r>>n;
}
	return 0;
}

//测试数据：6
//          10
//          1 7 15 20 30 50
//测试结果：3 
