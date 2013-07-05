#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

class nodeTree {

	public:
		int data;
		nodeTree *left,*right;
		nodeTree(){
		left=NULL;
		right=NULL;
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
				//std::cout<<"Q is empty";
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

class link_list_T{
	public:
	
		queue *q,*ql;
		stack *st;
		link_list_T(){
			q = new queue();
			st = new stack();
			ql = new queue();
			
		}
	nodeTree *root;

	void create_root(int val,int flag1,int left,int flag2,int right){
		root = new nodeTree();
		root->data=val;
		
		if(flag1!=0){
			nodeTree *l = new nodeTree();
			l->data=left;
			root->left=l;
			q->add(l);
		}
		if(flag2!=0){
			nodeTree *r = new nodeTree();
			r->data=right;
			root->right=r;
			q->add(r);
		}		
	}
	
	void insert_tree(int flag1,int left,int flag2, int right){
	  nodeTree *par = new nodeTree(); 
	  q->delet(&par);
	  if(flag1!=0){
	    nodeTree *l = new nodeTree();
	    l->data=left;
	    par->left=l;
	    q->add(l);
	  }
	  if(flag2!=0){
	    nodeTree *r = new nodeTree();
	    r->data=right;
	    par->right=r;
	    q->add(r);
	  }
	}
	
	void preorder(){
		nodeTree *t = root;
		if(t==NULL)return;
		st->push(t);
		while(!st->isEmpty()){
			t=st->pop();
			std::cout<<t->data<<" ";
			if(t->right)
				st->push(t->right);
			if(t->left)
				st->push(t->left);
		}
	}
	
	void level_wise(){
		nodeTree *t = root;
		if(t==NULL)return;
		int l=0;
		int child=0;
		while(t){
			std::cout<<t->data<<"|";
			if(t->left){
				child++;
				ql->add(t->left);
			}
			if(t->right){
				child++;
				ql->add(t->right);
			}
			if(l==0){
				std::cout<<"\n";
				l=child;
				child=0;
			}
			ql->delet(&t);
			l--;
			
		}
		
	}
	
};	


int main(int argc,char * argv[])
{
	 int i=0;
	 std::vector <int> words; // Vector to hold our words we read in.
	 std::vector <int>::size_type siz;
	 int str; // Temp string to
	 std::cout << "Read from a file!" << std::endl;
	 std::ifstream fin(argv[1]); // Open it up!
	 
	 while (fin >> str) // Will read up to eof() and stop at every
	 {                  // whitespace it hits. (like spaces!)
		words.push_back(str);
	 }
	 fin.close(); // Close that file!
	 siz=words.size();
	 int a[siz];	
		
	 for (int i = 0; i < siz; ++i){
		a[i]=words.at(i);
	 }
	 	
	link_list_T *tree = new link_list_T();
	tree->create_root(a[0],a[1],a[2],a[3],a[4]);
	for(i=5;i<siz;i=i+4){
	tree->insert_tree(a[i],a[i+1],a[i+2],a[i+3]);
	}
	std::cout<<"\nPreorder is : ";
	tree->preorder();
	std::cout<<"\nLevel Wise : "<<"\n";
	tree->level_wise();
	return 0;
}

 
