#include <iostream>
using namespace std;

int Partition(int A[],int low,int high){
	int pivot=A[low];
	while(low<high){
		while(low<high&&A[high]>=pivot){
			--high;
		}
		A[low]=A[high];
		while(low<high&&A[low]<=pivot){
			++low;
		}
		A[high]=A[low];
	}
	A[low]=pivot;
	return low;
}

void QuickSort(int A[],int low,int high){
	if(low<high){
		int pivot=Partition(A,low,high);
		QuickSort(A,low,pivot-1);
		QuickSort(A,pivot+1,high);
	}
}

int main(int argc, char const *argv[])
{
	int A[]={1,10,2,9,3,8,4,7,5,6};
	QuickSort(A,0,9);
	for(int i=0;i<10;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}