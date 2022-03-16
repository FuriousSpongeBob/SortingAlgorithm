#include <iostream>
#include <stack>
using namespace std;

int partition(int A[],int low,int high){
	if(low>=high) return low;
	int pivot=A[low];
	while(low<high){
		while(low<high&&pivot<=A[high])high--;
		A[low]=A[high];
		while(low<high&&pivot>=A[low])low++;
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}

int _pop(stack<int> &s){
	int top=s.top();
	s.pop();
	return top;
}

void QuickSort(int A[],int n){
	stack<int> s;
	s.push(n-1);
	s.push(0);
	while(!s.empty()){
		int low=_pop(s);
		int high=_pop(s);
		if(low<high){ 
			int pivot=partition(A,low,high);
			s.push(pivot-1);
			s.push(low);
			s.push(high);
			s.push(pivot+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[]={1,10,2,9,3,8,4,7,5,6};
	QuickSort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}