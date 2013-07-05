#include <iostream>
#include <math.h>
#include <stdlib.h>

template <class T1>
class node{
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
	public:
		node <T1>* top;
		link_list(){
			top = new node <T1>;
		}

	void push(int no){
		node <T1>*n1 = new node<T1>;
		n1->data=no;
		if(top->next==NULL){
			top->next=n1;
		}
		else{
			node <T1>* temp = top->next;
			top->next= n1;
			n1->next = temp;
		}
	}
	
	void pop(){
		node <T1>* n1 = top->next;
		T1 d = n1->data;
		top->next=top->next->next;
		delete n1;
		std::cout<<"You have deleted::"<<d<<"\n";
	}

	void display(){
			node <T1>* temp = top->next;
			while(temp!=NULL){
				std::cout<<temp->data<<"\n";
				temp=temp->next;
			}
		}
};

int main(){
	link_list <int>* l1 = new link_list<int>();
	l1->push(10);
	l1->push(20);
	l1->push(30);
	l1->push(40);
	l1->pop();
	l1->display();	
}
