//时间复杂度为O(n^4) 
/*#include<cstdio>
#include<iostream>
using namespace std;
const int MAX_N=50;
int main(){
	int n,m,k[MAX_N];
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	
	bool f=false;
	
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			for(int c=0;c<n;c++){
				for(int d=0;d<n;d++){
					if(k[a]+k[b]+k[c]+k[d]==m){
						f=true;
					}
				}
			}
		}
	}
	
	if(f){
		puts("Yes");
	}
	else{ 
		puts("No");
	}
	return 0;
}*/

//改进
//采用二分搜索算法O(logn)
//排序时间复杂度O(nlogn)、 循环时间复杂度O((n^3) logn)--三重循环内一个二叉搜索算法 
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=50;

	bool binary_search(int x,int *k,int n){                //数组通过指针（数组名）、数组长度传入 
		int l=0,r=n;
		
		while(r-l>=1){
			int i=(l+r)/2;
			if(k[i]==x){
				return true;
			}
			else if(x<k[i]){
				r=i;     //因为下标r的元素是不需要查找的 
			}
			else if(x>k[i]){
				l=i+1;   //因为下标l的元素是需要查找的 
			}
		}
		
		return false;
	}
	
int main(){
	int n,m,k[MAX_N];
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	

	
	//void solve(){
	    sort(k,k+n);      //为了执行二分查找需要先排序   [0,n) 
	
	    bool f=false;
	
	    for(int a=0;a<n;a++){
		    for(int b=0;b<n;b++){
			    for(int c=0;c<n;c++){
				    if(binary_search(m-k[a]-k[b]-k[c],k,n)){
					    f=true;
				    }
			    }
		    }
	    }
	
	    if(f){
		    puts("Yes");
	    }
	    else{
		    puts("No");
	    }
    //}
    
	return 0;
} 


//还需优化
 






 
