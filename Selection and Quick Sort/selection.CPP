#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char* argv[]){
	int i,j,imin,size,t;

	ifstream fin(argv[1]);	
	
	if(fin){
		fin>>size;
	}
	int a[size];	
	for(i=0;i<size;i++){
		fin>>t;
		a[i]=t;
	}

	for(j=0;j<size;j++){
		
		imin=j;
		for(i=j+1;i<size;i++){
			if(a[i]<a[imin]){
				imin=i;
			}
		} 
		if(imin!=j){
			int temp;
			temp=a[imin];
			a[imin]=a[j];
			a[j]=temp;
		}

	}
	for(int k=0;k<size;k++){
		std::cout<<a[k]<<"\n";
	}
}
