#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record{ 
	int rollNo;    
	float gp; 
	Record *next;   
};

void insert(Record**head){    
	
	Record*ptr=(Record*)malloc(sizeof(Record));  
	cout<<"enter roll number"<<endl;     
	cout<<endl;
	cin>>ptr->rollNo;   
	
	cout<<"enter gp"<<endl;
	cout<<endl;   
	cin>>ptr->gp;    
	
	ptr->next=NULL;    
	if(*head==NULL){    
		*head=ptr; 
	}
	else{
		Record* curr=*head;    
		while(curr->next!=NULL){  
			curr=curr->next; 
		}
		curr->next=ptr;   
	}
	
}
void search(Record ** head){
	int tosearch;
	cout<<"enter Roll NUMBER to search"<<endl;
	cout<<endl;
	cin>>tosearch;
	Record*curr=*head;
	int count=0;
	while(curr!=NULL){
		if(curr->rollNo==tosearch){
			cout<<"FOUND"<<endl;
			cout<<endl;
			count++;
			break;
		}
		else{
			curr=curr->next;
		}
			
		
	}
	if(count==0){
		cout<<"NOT FOUND BRUH";
		cout<<endl;
		
	}

}
void print(Record **head){
	
	Record *curr=*head;
	if(curr==NULL){
		cout<<"NO ELEMENT FOUND"<<endl;
		cout<<endl;
	}
	while(curr!=NULL){
		cout<<"ROLL NUMBER IS "<<curr->rollNo<<endl;
		cout<<"GP IS "<<curr->gp<<endl;
		cout<<endl;
		cout<<endl;
		curr=curr->next;
	}
}

void Delete(Record ** head){
	Record*curr=*head;
	Record*prev;
	cout<<"ENTER A ROLL NUMBER TO DELETE";
	cout<<endl;
	int toDel;
	cin >>toDel;
		if(curr->rollNo==toDel){
			*head=curr->next;
			free(curr);
		}
		
		else{
			curr=curr->next;
			prev=curr;
			while(curr!=NULL){
				if(curr->rollNo==toDel){
					prev->next=curr->next;
					free(curr);
					
				}
				else{
					curr=curr->next;
					prev=prev->next;
				}
			}
				
		}
	
}
void deleteAll(Record ** head){
	Record *curr=*head;
	while(curr!=NULL){
		*head=curr->next;
		free(curr);
		curr=*head;
	}
	free(*head);
}

int main(){
	Record *head=NULL;
	int a;
	while(a!=6){
	cout<<"press 1 for insert\n 2 for search\n 3 for print \n 4 for delete an element \n  5 for deleteAll \n 6 for exit"<<endl;
	cin>>a;
		if(a==1){
			insert(&head);
		}
		if(a==2){
			search(&head);
		}
		if(a==3){
			print(&head);
		}
		if(a==4){
			Delete(&head);
		}
		if(a==5){
			deleteAll(&head);
		}
		
		if(a==6){
			cout<<"EXIT FROM PROGRAM \n THANKYEWW";
		}
	}
}
