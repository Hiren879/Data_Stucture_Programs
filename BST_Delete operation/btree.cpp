/*
* Name : Hiren Savalia
* Code : Code of  creation of Binary Search Tree with deletion of 
* 	1. in-order successor (smallest element from right sub-tree)
*   2. in-order predecessor (largest element from left sub-tree)
*/
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib> 

int myrandom (int i) { return std::rand()%i;}
class nodeTree{
	public:
		int data;
		nodeTree *left,*right;
		nodeTree(){
			left=right=NULL;
		}
};
class queue{
		public:
               int front,rear,i;
               nodeTree *a[100];
               
		queue(){
			front=rear=0;
		}
        bool isEmpty(){
		  return(front==rear);
        }
        bool isFull(){
		  return((rear+1)%100==front);
        }
        void add(nodeTree *x){
		  if(isFull()){
			std::cout<<"Q is full";
			return;
		  }		
		  else{
			a[rear] = x;
			rear=rear+1;
		  }  
         }

		void delet(nodeTree **par){
			if(isEmpty()){
				std::cout<<"Q is empty";
			}
			*par = a[front];
			front=front+1;
		}
};
class stack{
	public:
		int top;
		nodeTree *a[100];
		
	stack(){
		top=-1;
	}
	
	bool isEmpty(){
		return(top==-1);
	}
	void push(nodeTree *t){
		top=top+1;
		a[top]=t;
	}
	
	nodeTree * pop(){
			nodeTree *par = a[top];
			top=top-1;
			return par;
		}
	
};

class BST{
	
	public:
		nodeTree *root;
		stack *st;
		queue *ql;
		BST(){
			root = new nodeTree();
			st = new stack();
			ql = new queue();
		}

	void insertBST(int *words,int siz){
		int i=0;		
		root->data = words[0];
		i++;
		nodeTree *temp;
		while(i<siz){
			temp=root;
				while(temp!=NULL){
					if(words[i]<temp->data){
					  if(temp->left==NULL){
						nodeTree *n = new nodeTree();
						n->data=words[i]; 
						temp->left = n;
						i++;	
						break;
					}	
					temp=temp->left;	
				}
				else{	if(temp->right==NULL){
						nodeTree *n = new nodeTree();
						n->data=words[i]; 
						temp->right = n;
						i++;	
						break;
					}	
					temp=temp->right;	
				}
			}
		}
	}
    void inorder(){
		nodeTree *temp = root;
		while(temp!=NULL || !(st->isEmpty())){
			if(temp!=NULL ){
				st->push(temp);
				temp=temp->left;
			}
			else{
				temp=st->pop();
				std::cout<<temp->data<<" ";
				temp=temp->right;
			}
		}		
	}
	
	void in_succ(){
		nodeTree *temp = root;
		nodeTree *temp1 = new nodeTree();
		temp1 = root->right;
		nodeTree *temp3;
		if(temp1==NULL){
			std::cout<<"\n"<<"!!!!....Nothing to delete..There no right tree..!!!!";
			return;
		}
		if(temp1->right==NULL && temp1->left==NULL){
			temp1->left = temp->left;
			temp1->right = NULL;
			delete root;
			root=temp1;
			return;
			
		}
		if(temp1->left==NULL && temp1->right!=NULL){
			temp1->left = root->left;
			delete root;
			root = temp1;
			return;
		}
		else{
			while(temp1->left!=NULL)
			{
				temp=temp1;
				temp1=temp1->left;
			}
			if(temp1->right!=NULL)
			{
				temp3 = temp1->right;
				temp1->right = root->right;
				temp1->left = root->left;
				delete root;
				root = temp1;
				temp->left = temp3;
				return;
			}
			else{
				temp1->right = root->right;
				temp1->left = root->left;
				delete root;
				root=temp1;
				temp->left=NULL;
				return;
			}
	}
	
}

	void in_prede(){
		nodeTree *temp = root;
		nodeTree *temp1;
		nodeTree *temp3;
		temp1 = root->left;
		if(temp1==NULL){
			std::cout<<"\n"<<"!!!!....Nothing to delete..There is no left tree..!!!!";
			return;
		}
		if(temp1->right==NULL && temp1->left==NULL){
			temp1->right = temp->right;
			temp1->left = NULL;
			delete root;
			root=temp1;
			return;	
		}
		if(temp1->right==NULL && temp1->left!=NULL){
			temp1->right = root->right;
			delete root;
			root = temp1;
			return;
		}
		else{
			while(temp1->right!=NULL)
			{
				temp=temp1;
				temp1=temp1->right;
			}
			if(temp1->left!=NULL)
			{
				temp3 = temp1->left;
				temp1->right = root->right;
				temp1->left = root->left;
				root = temp1;
				temp->right = temp3;
				return;
			}
			else{
				temp1->left = root->left;
				temp1->right = root->right;
				root=temp1;
				temp->right=NULL;
				return;
			}
	}
}
	
	void level_wise(){
		nodeTree *t = root;
		if(t==NULL)return;
		while(t){
			std::cout<<t->data<<" ";
			if(t->left)
				ql->add(t->left);
			if(t->right)
				ql->add(t->right);
			
			if(ql->isEmpty())
				break;
			ql->delet(&t);
		}
	}
};

int main(int argc,char * argv[])
{
	 BST *b = new BST();
	 BST *h = new BST();	
	 int siz,i=0;
	 std::vector <int> words; // Vector to hold our words we read in.
	 int str; // Temp string to
	 std::cout <<"\n" <<"Read from a file-> ORIGINAL INPUT :" << std::endl;
	 std::ifstream fin(argv[1]); // Open it up!
	 while (fin >> str) // Will read up to eof() and stop at every
	 {                  // whitespace it hits. (like spaces!)
		words.push_back(str);
	 }
	 fin.close(); // Close that file!
	 siz=words.size();
	 std::srand ( unsigned ( std::time(0) ) );
	 std::random_shuffle (words.begin(),words.end() );
	 int a[siz];
	 //int b1[siz];
	 int c1[siz];
	 
	 for(i=0;i<siz;i++){
		 std::cout<<words[i]<<" ";
		 a[i]=words.at(i);
		 c1[i]=words.at(i);
	 }	 
	 b->insertBST(a,siz);
	 std::cout<<"\n\n"<<"Level_wise tree to check insertion : "<<"\n";
	 b->level_wise();
	 std::cout<<"\n\n"<<"Inorder tree (sorted) :"<<"\n";
	 b->inorder();
	
	 std::cout<<"\n\n"<<"*****************After deleting root (in-order succesor)*********************";
	 b->in_succ();
	 std::cout<<"\n"<<"Level_wise tree to check deletion in_successor :"<<"\n";
	 b->level_wise();
	 std::cout<<"\n\n"<<"In-order (newly sorted) :"<<"\n";
	 b->inorder();
	 
	 
	 std::cout<<"\n\n"<<"*************Doing operation on ORIGINAL TREE********************";
	 h->insertBST(c1,siz);
	 std::cout<<"\n"<<"*****************After deleting root (pre deccesor)*********************"<<"\n";
	 h->in_prede();
	 std::cout<<"\n"<<"Level_wise tree to check deletion in_successor :"<<"\n";
	 h->level_wise();
	 std::cout<<"\n\n"<<"In-order (newly sorted) :"<<"\n";
	 h->inorder();
	 std::cout<<"\n\n";
	 return 0;
}
