#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class qu{
		public:
               int front,rear,i;
               int a[100];

		qu(){
			front=rear=0;
		}
        bool isEmpty(){
		  return(front==rear);
        }
        bool isFull(){
		  return((rear+1)%100==front);
        }
        void add(int x){
		  if(isFull()){
			std::cout<<"Q is full";
			return;
		  }
		  else{
			a[rear] = x;
			rear=rear+1;
		  }
         }

		int delet(){
			if(isEmpty()){
				std::cout<<"Q is empty";
			}
			int par;
			par = a[front];
			front=front+1;
			return par;
		}
};

class stack{
	public:
		int top;
		int a[100];

	stack(){
		top=-1;
	}

	bool isEmpty(){
		return(top==-1);
	}
	void push(int t){
		top=top+1;
		a[top]=t;
	}

	int pop(){
			int par = a[top];
			top=top-1;
			return par;
		}
	int pick(){
		int par = a[top];
		return (par);
	}

};

int main (int argc, char *argv[]){
		ifstream infile("input");
		int a;
		infile>>a;
		int n = a+1;
		int arr[n][n];
		qu *q = new qu();
		cout<<"Adjacency Matrix :"<<endl;
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				infile>>arr[i][j];
				cout<<arr[i][j]<<" ";
				}
			cout<<endl;
		}
		int i=1;
		q->add(i);
		int flag[n];
		for(int x=1;x<n;x++){
				flag[x] = 100;                  // 100-> Not visited
			}
		flag[i] = 10;
		cout<<"Assuming that starting node is 1 in both the case : "<<endl;
		cout<<endl<<"BFS is : ";
		while(!(q->isEmpty())){
			int temp = q->delet();
			cout<<temp<<" ";
			for(int j=1;j<n;j++){               // creating adj matrix
				if(arr[temp][j]==1 && flag[j]!=10){
					q->add(j);
					flag[j] = 10;
				}
			}
		}
		stack *s = new stack();
		i=1;
		s->push(i);
		for(int x=1;x<n;x++){
				flag[x] = 100;                  // 100-> Not visited
			}
		flag[i] = 10;
		cout<<endl<<"DFS is : ";
		while(!(s->isEmpty())){
			int temp;
			temp = s->pop();
			cout<<temp<<" ";
			for(int j=1;j<n;j++){
				if(arr[temp][j]==1 && flag[j]!=10){
					s->push(j);
					flag[j] = 10;
				}
			}
		}
		cout<<endl;
		return 0;
}
