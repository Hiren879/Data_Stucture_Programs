#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
void quick(int a[],int left,int right);
int main(int argc, char* argv[]){
	int i,size,t,right,left;
	ifstream fin(argv[1]);	
	
	if(fin){
		fin>>size;
	}
	int a[size];	
	for(i=0;i<size;i++){
		fin>>t;
		a[i]=t;
	}
	
	left=0;
	right=size-1;
	quick(a,left,right);
	for(i=0;i<size;i++){
		std::cout<<a[i]<<"\n";
	}
}

void quick(int a[],int left,int right){
	int i,j;
	i=left;
	j=right;
			int pivot=a[(left+right)/2];
			
			while(i<=j){
				while(a[i]<pivot)
					i++;
				while(a[j]>pivot)
					j--;
				if(i<=j){
					int temp;
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					i++;
					j--;
				}
			};
			
			if(left<j)
				quick(a,left,j);
			if(i<right)
				quick(a,i,right);
	}
