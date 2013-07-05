#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

template  <class T1>
class node {

	public:
		T1 data;
		node<T1>* next;
	node(){
		data=NULL;
		next=NULL;
	}
};
template <class T1>
class link_list{
	public :
	int s;
	node<T1>* head;
	link_list(){
		s=0;
		head = new node<T1>();
		}
	void addlast(int d){			// Adding new node in link list
		node<T1>* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		node<T1>* n=new node<T1>();
		n->data=d;
		temp->next=n;
		s++;
	}
	T1 delete_first(){			// deleting from the the link list and adding it into array
		node<T1>* temp;
		temp = head->next;
		head->next = temp->next;
		T1 d=temp->data;
		delete(temp);
		s--;
		return d;
	}
	void display(){				
		node<T1>* temp;
		temp=head->next;
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	int getsize(){
		return s;
	}
};
int main(int argc,char* argv[]){
	int i=0,d,temp,a[10];	
	fstream fin;
	fin.open(argv[1]);	
	if(fin.is_open()){
		while(fin.good()){
			fin>>d;
			a[i]=d;
			i++;
		}
	}
	link_list <int>* l1[10];
	for(i=0;i<10;i++)
		l1[i]=new link_list<int>();
	
	for(int x=0;x<3;x++){
		for(i=0;i<10;i++)
		{
		       int r=a[i];
		       for(int y=0;y<x;y++){
				  r=int(floor(r/10));
				  }
		       temp=int(floor(r%10));
		       l1[temp]->addlast(a[i]);
		}
		int k=0;
		for(i=0;i<10;i++){
			while(l1[i]->getsize()!=0){
			       a[k]=l1[i]->delete_first();			       
				k++;
			}
		}
		for(i=0;i<10;i++)
		std::cout<<a[i]<<"|";
		std::cout<<"\n";
	}
	
	return 0;
}
