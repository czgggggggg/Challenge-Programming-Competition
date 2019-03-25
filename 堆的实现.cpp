#include<iostream>
using namespace std;
const int MAX_N=1000;
int heap[MAX_N];
int size=0;

void push(int x){
	int i=size++;
	while(i>0){//i大于0有父节点的情况 
		int p=(i-1)/2;//找到父节点
		if(heap[p]<=x){//注意父节点值小或等于，立马退出 
            break;
		} 
		heap[i]=heap[p];//父节点值大，交换
		i=p;
	}
	heap[i]=x;//i等于0的情况直接跳过while循环，放入数值。 
}

int pop(){
	int ret=heap[0];
	int x=heap[--size];//取堆的最后一个元素
	int i=0; 
	while(i*2+1<size){//保证左孩子节点在堆范围内 
	    int a=i*2+1;//当前左孩子节点 
	    int b=i*2+2;//当前右孩子节点
		if(b<size&&heap[b]<heap[a]){//右孩子节点在堆范围内，并且右孩子的值小于左孩子
		    a=b;//a有记录孩子最小值的作用 
		}
		if(heap[a]>=x)//没有颠倒则退出 
		    break; 
		heap[i]=heap[a];//颠倒则孩子小的值提上来 
		i=a;//颠倒则把值小的孩子节点下标赋给i 
	}
	heap[i]=x; 
	return ret;//返回最小值 
}

int main(){
	int x1;
	for(int i=0;i<6;i++){//输入初始堆数据 
		cin>>x1;
		push(x1);
	}
	cout<<"初始堆："; 
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	
	cout<<"输入要插入的数："; 
	cin>>x1;//输入要入堆的数
	push(x1);
	cout<<"插入数据后的堆：";
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	} 
	cout<<endl;
	
	cout<<"取出当前堆中最小的元素为："; 
	cout<<pop()<<endl;//输出要出堆的数 
	cout<<"取出最小值后的堆：";
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	} 
	cout<<endl;
	
	return 0;
}

//测试数据
//输入： 
//1 2 4 7 8 5
//3
//输出：
//1 2 4 7 8 5
//1 2 3 7 8 5 4
//1
//2 4 3 7 8 5

//C++标准库中优先级队列的使用
/*#include<cstdio>
#include<queue>
using namespace std;
int main(){
	
	priority_queue<int> pqueue;
	pqueue.push(3);
	pqueue.push(5);
	pqueue.push(1);
	while(!pqueue.empty()){
		//取出并删除最大值 
		printf("%d ",pqueue.top()); 
		pqueue.pop();
	}
	printf("\n");
	
	queue<int>q;     //注意优先级队列和队列的区别 
	q.push(3);
	q.push(5);
	q.push(1);
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
	}
	printf("\n");
	
	return 0;
}*/








 





