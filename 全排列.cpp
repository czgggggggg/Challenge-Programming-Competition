//��0,1,2,..,n-1����ȫ���У���������е���������� 
#include<iostream>
using namespace std;
const int MAX_N=100;                                    //Ϊʲôȫ�ֱ�������һ��Ҫʹ��const�ؼ��֣� 
bool used[MAX_N];//���һ�������е�Ԫ���Ƿ��Ѿ���ʹ��     
int perm[MAX_N];//�����¼һ��ȫ���� 

void permutation1(int pos,int n){//��posλ�÷���һ��û��ʹ�õ�Ԫ�� 
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
			permutation1(pos+1,n);//��pos����һ��λ������һ��δʹ�õ�Ԫ�أ�ע���ʱi�Ѿ���ʹ�á���������������permutation������i��ʹ�õ�����µķ�֧ 
			used[i]=false;//ʹ�ú��˳�����������Ϊfalse  //��֤��ǰiʹ��������Ԫ�أ�����iΪ����Ԫ�صķ�֧�£���ǰ�˳���Ԫ�ػ����ٱ�ʹ�á�       
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
