/*
 * Name: Hiren Savalia
 * No: 201212024
*/
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>

class minheap{
	public:
		int *arr,*arr1;
		int hs, maxs, link;	
	minheap(int size){
		arr = new int [size+1];
		arr1 = new int [size+1];
		hs=0;
		maxs=size;
	}
	bool isFull(){
		return(hs==maxs);
	}	
	bool isEmpty(){
		return(hs<=0);
	}
	int par(int child){
		return floor(child/2);
	}
	void insert_heap(int element){
		if(isFull()){return;}
		int curr;
		curr = ++hs;
		for(;curr>1 && element<arr[par(curr)];curr = par(curr)){
				arr[curr] = arr[par(curr)];
			}
			arr[curr] = element;
	}
	void show_heap(){
		for(int i=1;i<=hs;i++){
			std::cout<<arr[i]<<"|";
		}
	}                     
	void delete_root(){
		if(isEmpty()){
			std::cout<<"Heap is empty..!!";
		}
		else{
			++link;
			arr1[link]=arr[1];
			arr[1]=arr[hs];
			hs--;
			per_down(1);
		}
	}
	
	void per_down(int x){
		int temp,child;
		temp=arr[x];
		for(;x*2<=hs;x=child){
			child=2*x;
			if(arr[child+1]<arr[child]){
				child++;
			}
			if(arr[child]<temp){
				arr[x]=arr[child];
			}
			else{
				break;
			}
		}
		arr[x]=temp;
	}
	
	int k_find(int index){
		return(arr1[index]);
	}
	
	void sorted(){
		std::cout<<"Sorted Array after DELETION..!!\n";
		for(int i=1;i<=maxs;i++){
			std::cout<<arr1[i]<<"|";
		}
	}
	
	void dis(){
		std::cout<<"\n";
		for(int i=1;i<=maxs;i++){
			std::cout<<i<<"->"<<arr1[i]<<"\n";
		}
	}
	
	void median(){
		int med,temp;
		if(maxs%2!=0){
		temp=maxs+1;	
		med=arr1[temp/2];
		}
		else{
			temp=maxs/2;
			med=(arr1[temp]+arr1[(temp+1)])/2;
		}
		std::cout<<"\nMedian is : "<<med;
	}
};

int main(int argc,char * argv[])
{
	int i,size,t;
	std::ifstream fin(argv[1]);	
	
	if(fin){
		fin>>size;
	}
	minheap *m1 = new minheap(size);
	int a[size];	
	for(i=0;i<size;i++){
		fin>>t;
		a[i]=t;
	}	
	//ORIGINAL ARRAY
	std::cout<<"Original Array:"<<"\n";
	for(i=0;i<size;i++){
		std::cout<<a[i]<<"|";
	}
	std::cout<<"\n";	 
	//HEAP ARRAY
	std::cout<<"\nAfter inserting in HEAP printed LEVEL VISE ";
	for (i = 0; i < size; ++i){
		m1->insert_heap(a[i]);
	 }	 
	 std::cout<<"\n";
	 std::cout<<"\n";
	 m1->show_heap();
	 std::cout<<"\n";
	 std::cout<<"\n";
	 std::cout<<"This seuqnce contains LEVEL VISE rearrenged HEAP after each deletion :: \n";
					m1->show_heap();
					std::cout<<"\n";	
					for(i=0;i<size;i++){
					m1->delete_root();
					m1->show_heap();
					std::cout<<"\n";
					}
					m1->sorted();
	 	
	 int temp=0,k,no;
	do{
		std::cout<<"\n1. for K th smallest element\n";
		std::cout<<"2. for MEDIAN of array\n";
		std::cout<<"3. for EXIT\n";
		std::cout<<"Enter your choice: ";
		std::cin>>temp;
		switch(temp){			
			case 1:
					std::cout<<"Enter K:\n";
					std::cin>>k;
					if(k>size){
						std::cout<<"Out of range.Enter K between 1 to "<<size<<"\n";
					}else{
					no=m1->k_find(k);
					std::cout<<"\nYour "<<k<<" th smallest no is: "<<no<<"\n";
					std::cout<<"Check here: ";
					m1->dis();
					}
					break;
			case 2:
					m1->median();
		}
	}while(temp!=3);	
}
