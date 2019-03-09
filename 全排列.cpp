//对0,1,2,..,n-1进行全排列，并输出所有的排列情况。 
#include<iostream>
using namespace std;
const int MAX_N=100;                                    //为什么全局变量定义一定要使用const关键字？ 
bool used[MAX_N];//标记一组数据中的元素是否已经被使用     
int perm[MAX_N];//数组记录一组全排列 

void permutation1(int pos,int n){//在pos位置放置一个没有使用的元素 
	if(pos==n){
	    for(int i=0;i<n;i++){
	    	cout<<perm[i]<<" ";
	    }
	    cout<<endl;
	    return ;	
	}
	
	for(int i=0;i<n;i++){
		if(!used[i]){
			perm[pos]=i;
			used[i]=true;
			permutation1(pos+1,n);//在pos的下一个位置设置一个未使用的元素，注意此时i已经被使用。接下来继续调用permutation函数是i被使用的情况下的分支 
			used[i]=false;//使用后退出，重新设置为false  //保证当前i使用其他的元素，而在i为其他元素的分支下，当前退出的元素还能再被使用。       
		}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		used[i]=false;
	}
	permutation1(0,n);
	return 0;
}
