#include<iostream>
#include<stdlib.h>
using namespace std;
struct Record{   
	int rollNo;  
	float gp;  
	Record *next; 
	Record *prev;
};
void insert(Record ** head){
	Record*ptr=(Record*)malloc(sizeof(Record));  
	cout<<"enter roll number"<<endl;     
	cout<<endl;
	cin>>ptr->rollNo;     
	
	cout<<"enter gp"<<endl;
	cout<<endl;    
	cin>>ptr->gp;
	
	ptr->prev=NULL;
	ptr->next=NULL;
	if(NULL==*head){
		*head=ptr;
	}
	else{
		Record *curr=*head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=ptr;
		ptr->prev=curr;
		
	}
}
void search(Record ** head){
	int tosearch;
	cout<<"enter Roll NUMBER to search"<<endl;
	cout<<endl;
	cin>>tosearch;
	Record*curr=*head;
	int count =0;
	while(curr!=NULL){
		if(curr->rollNo==tosearch){
			cout<<"found"<<endl;
			count++;
			break;
			return;
		}
		else{
			curr=curr->next;
		}
	}
	if(count==0){
		cout<<"ROLL NUMBER NOT FOUND"<<endl;
		return;
	}
}
void print(Record ** head){
		if(*head==NULL){
		cout<<"list is empty";
	}

	Record *curr=*head;
	while(curr!=NULL){
		cout<<"ROLL NUM IS :"<<curr->rollNo<<endl;
		cout<<"STD GP IS :"<<curr->gp<<endl;
		cout<<endl;
		curr=curr->next;
	}
}

void Delete(Record ** head){
	if(*head==NULL){
		cout<<"list is empty";
		return ;
	}
	int toDel;
	cout<<"Enter a number to delete"<<endl;
	cin>>toDel;
	Record*curr=*head;
	if(curr->rollNo==toDel){
		*head=(*head)->next;
		free(curr);
		curr=*head;
		return;
	}
	if(curr->next==*head){
		free(*head);
		*head=NULL;
		return;
	}
		while(curr!=NULL){
		if(curr->rollNo=toDel){
			curr->prev->next=curr->next;
			curr->next->prev=curr->prev;
			free(curr);
		}
		curr=curr->next;
		
	}
	
}
void deleteAll(Record ** head){
	Record *curr=*head;
	while(curr!=NULL){
		*head=(*head)->next;
		free(curr);
		curr=*head;
	}
	cout<<"Deleted all"<<endl;
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
