#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

class node {

	public:
		string data;
		node * next;
	node(){
		data="";
		next=NULL;
	}
};

class link_list{
	public :
	node * head;
	link_list(){
		head = new node ();
		}
	void addlast(string d){			// Adding new node in link list
		node * temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		node * n=new node ();
		n->data=d;
		temp->next=n;
	}
	
	int search(string element){
		int index=0;
		node * temp = head;
		while(temp->next!=NULL){
			temp=temp->next;
			index=index+1;
			if(temp->data==element)
				return index;
		}
	}
	
	void display(){				
		node * temp;
		temp=head->next;
		while(temp!=NULL){
			std::cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

int ReturnASCIISum(char* String,int len)
{
   int TotalSum = 0;
   for(int i=0; i<len; i++)
   {
      TotalSum += (int)String[i];
   }
   return TotalSum;
};


int main(int argc,char * argv[])
 {		int i,j,sum=0;
		char strarr[50];
		
		vector <string> words; // Vector to hold our words we read in.
		vector <int>::size_type siz;
		string str; // Temp string to
		cout << "Read from a file!" << std::endl;
		ifstream fin(argv[1]); // Open it up!
		while (fin >> str) // Will read up to eof() and stop at every
		{                  // whitespace it hits. (like spaces!)
			words.push_back(str);
		}
		fin.close(); // Close that file!
		siz=words.size();
			
		link_list * l1[siz];
		for(i=0;i<siz;i++)
			l1[i] = new link_list();
			
		cout<<"Total Charactor Strings are : "<<siz<<endl;
		int hash_table; //size of hash table
		hash_table = (siz * 0.75);
		cout<<"So size of the Hash Table will be 75 % of total and that is "<<hash_table<<endl;
		int hash[siz]; //array containing all elements
		
		string a[siz];	
		for (i = 0; i < siz; ++i){
			a[i]=words.at(i);
			cout<<a[i]<<"-->";
			
			string s = a[i];
			int len = s.length();
			for(j = 0;j < len;j++){
				strarr[j] = s[j];
				sum = ReturnASCIISum(strarr,len);
			}
			cout<<sum<<endl;
			hash[i] = sum;
		}
		cout<<endl;
	 		 	
	 	for(i=0;i<siz;i++){
			int temp;
			temp = hash[i]%hash_table;
			l1[temp] -> addlast(a[i]);
		}
		
		cout<<"Saperate Chaining"<<endl;
		for(i=0;i<hash_table;i++){
			cout<<"Node "<<i<<"-> ";
			l1[i]->display();
			cout<<endl;
		}
		
		cout<<endl<<"Saperate Chaining Hash-Table Indexing"<<endl;
		for(i=0;i<siz;i++){
			int temp,index;
			temp = hash[i]%hash_table;
			index = l1[temp] -> search(a[i]);
			cout<<a[i]<<" --> Node "<<temp<<":: Index : "<<index<<endl;
		}
		
		string openarr[hash_table]; //array will handle perticuler element
		for(i=0;i<hash_table;i++){
			openarr[i] = "EMPTY";
			//cout<<openarr[i];
		}
		cout<<endl<<"Open Addressing without replacement "<<endl;
		for(i=0;i<=hash_table;i++){
			int temp;
			int flag=0;
			temp = hash[i]%hash_table;
			if(openarr[temp]=="EMPTY"){
			openarr[temp] = a[i];
			}
			else{
				for(j=temp+1;j<hash_table;j++){
					if(openarr[j]=="EMPTY"){
						openarr[j] = a[i];
						flag=1;
						break;
					}
				}
				if(flag==0){
				for(j=0;j<temp;j++){
							if(openarr[j]=="EMPTY"){
								openarr[j] = a[i];
								break;
							}
						}
					}
				}
			}		
		for(i=0;i<hash_table;i++){
			cout<<"Node "<<i<<"-> "<<openarr[i]<<endl;
		}	
		cout<<endl<<"Open Addressing Indexing"<<endl;
		for(i=0;i<=hash_table;i++){
			for(j=0;j<=hash_table;j++){
				if(a[i]==openarr[j]){
					cout<<a[i]<<" --> Node "<<j<<endl;
				}
			}
		}	
		return 0;
}
