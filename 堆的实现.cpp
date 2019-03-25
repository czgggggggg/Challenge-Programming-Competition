#include<iostream>
using namespace std;
const int MAX_N=1000;
int heap[MAX_N];
int size=0;

void push(int x){
	int i=size++;
	while(i>0){//i����0�и��ڵ����� 
		int p=(i-1)/2;//�ҵ����ڵ�
		if(heap[p]<=x){//ע�⸸�ڵ�ֵС����ڣ������˳� 
            break;
		} 
		heap[i]=heap[p];//���ڵ�ֵ�󣬽���
		i=p;
	}
	heap[i]=x;//i����0�����ֱ������whileѭ����������ֵ�� 
}

int pop(){
	int ret=heap[0];
	int x=heap[--size];//ȡ�ѵ����һ��Ԫ��
	int i=0; 
	while(i*2+1<size){//��֤���ӽڵ��ڶѷ�Χ�� 
	    int a=i*2+1;//��ǰ���ӽڵ� 
	    int b=i*2+2;//��ǰ�Һ��ӽڵ�
		if(b<size&&heap[b]<heap[a]){//�Һ��ӽڵ��ڶѷ�Χ�ڣ������Һ��ӵ�ֵС������
		    a=b;//a�м�¼������Сֵ������ 
		}
		if(heap[a]>=x)//û�еߵ����˳� 
		    break; 
		heap[i]=heap[a];//�ߵ�����С��ֵ������ 
		i=a;//�ߵ����ֵС�ĺ��ӽڵ��±긳��i 
	}
	heap[i]=x; 
	return ret;//������Сֵ 
}

int main(){
	int x1;
	for(int i=0;i<6;i++){//�����ʼ������ 
		cin>>x1;
		push(x1);
	}
	cout<<"��ʼ�ѣ�"; 
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	
	cout<<"����Ҫ���������"; 
	cin>>x1;//����Ҫ��ѵ���
	push(x1);
	cout<<"�������ݺ�Ķѣ�";
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	} 
	cout<<endl;
	
	cout<<"ȡ����ǰ������С��Ԫ��Ϊ��"; 
	cout<<pop()<<endl;//���Ҫ���ѵ��� 
	cout<<"ȡ����Сֵ��Ķѣ�";
	for(int i=0;i<size;i++){
		cout<<heap[i]<<" ";
	} 
	cout<<endl;
	
	return 0;
}

//��������
//���룺 
//1 2 4 7 8 5
//3
//�����
//1 2 4 7 8 5
//1 2 3 7 8 5 4
//1
//2 4 3 7 8 5

//C++��׼�������ȼ����е�ʹ��
/*#include<cstdio>
#include<queue>
using namespace std;
int main(){
	
	priority_queue<int> pqueue;
	pqueue.push(3);
	pqueue.push(5);
	pqueue.push(1);
	while(!pqueue.empty()){
		//ȡ����ɾ�����ֵ 
		printf("%d ",pqueue.top()); 
		pqueue.pop();
	}
	printf("\n");
	
	queue<int>q;     //ע�����ȼ����кͶ��е����� 
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








 





