#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void MergeSort(int A[],int n){
	vector<int> ans(n);
	for(int seg=1;seg<n;seg+=seg){
		for(int beg=0;beg<n;beg+=seg+seg){
			int low=beg,mid=min(beg+seg,n),high=min(beg+seg+seg,n);
			int i=low,j=mid,k=low;
			while(i<mid&&j<high)ans[k++]=(A[i]>A[j])?A[j++]:A[i++];
			while(i<mid)ans[k++]=A[i++];
			while(j<high)ans[k++]=A[j++];
			for(k=beg;k<high;++k)A[k]=ans[k];
		}
	}
}

int main(int argc, char const *argv[])
{
	int A[]={1,10,2,9,3,8,4,7,5,6};
	// vector<int> A={1,10,2,9,3,8,4,7,5,6};
	MergeSort(A,10);
	for(int i=0;i<10;i++){
		cout<<A[i]<<endl;
	}
	return 0;
}