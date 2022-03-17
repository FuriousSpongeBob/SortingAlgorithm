#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A,int low,int mid,int high){
	vector<int> LA(A.begin()+low,A.begin()+mid+1);// Copy A[low ... mid] to LA
	vector<int> RA(A.begin()+mid+1,A.begin()+high+1);// Copy A[mid+1 ... high] to RA
	int leftidx=0,rightidx=0;
	LA.insert(LA.end(),numeric_limits<int>::max());
	RA.insert(RA.end(),numeric_limits<int>::max());
	for(int i=low;i<=high;i++){
		if(LA[leftidx]<RA[rightidx]){
			A[i]=LA[leftidx];
			leftidx++;
		}else{
			A[i]=RA[rightidx];
			rightidx++;
		}
	}
}

void MergeSort(vector<int> &A,int low,int high){
	if(low>=high) return;
	int mid=(low+high)/2;
	MergeSort(A,low,mid);
	MergeSort(A,mid+1,high);
	Merge(A,low,mid,high);
}

int main(int argc, char const *argv[])
{
	// int A[]={1,10,2,9,3,8,4,7,5,6};
	vector<int> A={1,10,2,9,3,8,4,7,5,6};
	MergeSort(A,0,9);
	for(int i=0;i<10;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}