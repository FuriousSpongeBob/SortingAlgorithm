#include<iostream>
#include<algorithm>
using namespace std;

void max_heapify(int A[],int low,int high){
	int parent=low;
	int child=parent*2+1;
	while(child<=high){
		if(child+1<=high&&A[child]<A[child+1])child++;//比较两子，选最大
		if(A[parent]>A[child]) return;//若父节点大于子节点代表调整完毕，直接跳出函数
		else{//否则交换父子内容再继续子节点和孙系节点比较
			swap(A[parent],A[child]);
			parent=child;
			child=child*2+1;
		}
	}
}

void HeapSort(int A[],int n){
	for(int i=n/2-1;i>=0;i--) max_heapify(A,i,n-1);	//初始化，从最后一个父节点开始调整
	for(int i=n-1;i>=0;i--){//将最后一个元素和大根堆的根元素交换，再重新调整
		swap(A[0],A[i]);
		max_heapify(A,0,i-1);
	}
}

int main(int argc, char const *argv[])
{
	int A[]={1,10,2,9,3,8,4,7,5,6};
	HeapSort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}