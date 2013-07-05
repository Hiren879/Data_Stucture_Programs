#include <iostream>
#include <math.h>
#include <stdlib.h>

template  <class T1>
class node {

	public:
		T1 data;
		node<T1>* next,*prev;
	node(){
		data=NULL;
		next=NULL;
		prev=NULL;
	}
};

template <class T1>
class link_list{

	public :
	node<T1>* front,*rear;
	link_list(){
		front=rear=NULL;
		}

	bool IsEmpty(){
		return (front==NULL);
	}

	void insert(T1 i){

			node<T1>* n1 = new node<T1> ();
			n1->data = i;
			if(front!=NULL){
				rear->next=n1;
				n1->prev=rear;
				rear=n1;
			}
			else{
				front=rear=n1;
			}
		}

	T1 delet(){
		if(IsEmpty()){
		std::cout<<"Empty..!!!";		
		return(-99);
		}
		else{
		node <T1>*p=front;
		if(front==rear){
			T1 x=front->data;
			front=rear=NULL;
			return x;
		}
		if(front->next!=NULL){
		front=front->next;
		front->prev=NULL;
		T1 x=p->data;	
		delete(p);
		return x;
		}
		else
		return(-99);
		}
	}

	void display(){
		node<T1>* temp;
		temp=front;
		if(temp!=NULL){
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			temp=temp->next;
		}}
		else{
			std::cout<<"Nothing to Display...Q is empty..!!";
		}
	}
	
	void displayrev(){
		node<T1>* temp;
		temp=rear;
		if(temp!=NULL){
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			temp=temp->prev;
		}}
		else{
			std::cout<<"Nothing to Display...Q is empty..!!";
		}
	}

};

int main(){
	link_list <int> *l1=new link_list<int>();
	int i,temp,size,choice;
	
	
	do{
		std::cout<<"\n1 : Insert Element\n";
		std::cout<<"2 : Delete element\n";
		std::cout<<"3 : Display elements\n";
		std::cout<<"4 : Display in Reverse Order\n";
		std::cout<<"5 : Exit\n";
		std::cout<<"Enter your choice:\n";
		std::cin>>choice;		
		
		switch(choice){
			case 1:
				std::cout<<"Enter element :";
				std::cin>>i;				
				l1->insert(i);
				break;

			case 2:
				i=l1->delet();
				if(i!=-99){
				std::cout<<"You have just deleted "<<i<<" from the FRONT\n";
				//std::cout<<"Your new Q is :";
				//l1->display();
				break;
				}
				else{
				std::cout<<"Q is Empty.. Nothing to delete..!!\n";
				break;
				}
			case 3:
				l1->display();
				break;

			case 4:
				l1->displayrev();
				break;
			case 5:
				exit(5);
		}
	}while(temp!=5);
	
}
