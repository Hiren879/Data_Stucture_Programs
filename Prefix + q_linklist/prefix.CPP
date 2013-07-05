#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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
	node <T1> *head;

	link_list(){
		s=0;
		head=new node<T1>();
		}
		
void push(int a){
		if(head->next!=NULL){
			node <T1>*temp;
			temp = head->next;
			node <T1>*n1 = new node<T1>();
			n1->data = a;
			head->next = n1;
			n1->next = temp;

		}
		else{
			node <T1>*n1 = new node<T1>();
			n1->data = a;
			n1->next = NULL;
			head->next = n1;
		}
	}

	int pop(){
		node <T1> *temp;
		temp = head->next;
		head->next = temp->next;
		int d=temp->data;
		delete(temp);
		s--;
		return d;
		}

	void display(){
		node <T1> *temp;
		temp=head->next;
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	int result(char op,int num1,int num2)
	{
		  int res;
		     switch(op)
		     {
		      case '+': res=num1+num2;
		      break;
		      case '-': res=num1-num2;
		      break;
		      case '*': res=num1*num2;
		      break;
		      case '/': res=num1/num2;
		      break;
		      case '^': res=pow(num1,num2);
		      break;
		      case '%': res=(num1%num2);
		      break;
		     }
		  return(res);
	}

	int result(int no){
		return -no;
	}
	char gt(char c)
			{
			switch(c)
			      {
				 case '+': return 'b';
				 case '-': return 'b';
				 case '*': return 'b';
				 case '/': return 'b';
				 case '%': return 'b';
				 case '^': return 'b';
				 case '!': return 'x';
			      }
				return 'a';
			}

	void check(string pre,int l){
		int num1,num2,re;
		int arr[10];
		char a[10];
		int val[10];
		int ans,flag=0,index=0;
		for(int i=l-1;i>=0;i--){
		switch(gt(pre[i]))
        	{
          		case 'a' :
			for(int z=0;z<=l;z++){
			if(a[z]==pre[i]){
				flag=1;
				ans=val[z];
				this->push(ans);
			}
			}
			if(flag==0){
				a[index]=pre[i];
				std::cout<<"Enter value for ::"<<a[index]<<"::";
				int value;
				std::cin>>value;
				val[index]=value;
				index++;
				this->push(value);
			}
			break;

	       		case 'b' : 
			num1=this->pop();
		        num2=this->pop();
	          	re=result(pre[i],num1,num2);
			this->push(re);
			break;

			case 'x' :
			int num1=this->pop();
			re=result(num1);
			this->push(re);
			break;
			
	 	}
		}
	}
};

int main(){
	link_list <int> *l1=new link_list<int>();
	int l,temp,element,len;
	string pre;
	std::cout<<"Enter valid prefix expression: ";
	std::cin>>pre;
	l=pre.length();
	l1->check(pre,l);
	std::cout<<"Answer is::";
	l1->display();
	std::cout<<"\n";
	return (0);
}
