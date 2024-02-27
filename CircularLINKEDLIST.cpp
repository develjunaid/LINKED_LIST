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
		ptr->next=*head;
	}
	else{
		Record* curr=*head;  
		while(curr->next!=*head){ 
			curr=curr->next;   
			
			
		}
		curr->next=ptr; 
		ptr->next=*head;
		   
	}
	
}
void search(Record ** head){
	int tosearch;
	cout<<"enter Roll NUMBER to search"<<endl;
	cout<<endl;
	cin>>tosearch;
	Record*curr=*head;
	int count=0;

	while(curr->next!=*head){
		if(curr->rollNo==tosearch){
			cout<<"found"<<endl;
			count++;
			break;
		}
		else{
			curr=curr->next;
		}

	}
	
	while(curr->next==*head){
		if(curr->rollNo==tosearch){
			cout<<"found"<<endl;
			break;
		}
		else{
				
		cout<<"your Roll Number is not in the list"<<endl;
		break;
		}
	}
	
}

void print(Record **head){
	if(*head==NULL){
		cout<<"list is empty";
	}
	
	Record *curr=*head;
	do{
		
		cout<<"ROLL NUMBER IS "<<curr->rollNo<<endl;
		cout<<"GP IS "<<curr->gp<<endl;
		cout<<endl;
		cout<<endl;
		curr=curr->next;
	
	}
	while(curr!=*head);
	
	
	
}


void Delete(Record ** head){
	if(*head==NULL){
		cout<<"list is empty";
		return ;
	}
	int toDel;
	cout<<"Enter a number to delete";
	cin>>toDel;
	Record*curr=*head;
	
	//agr 1 hi element ho list m
	if((*head)->next==*head){
		if((*head)->rollNo==toDel){
			free(*head);
			*head=NULL;   
			cout<<"deleted"<<endl;
			return;
		}
		else{
			cout<<"ROLL NUMBER IS NOT IN THE LIST FOR DELETE";
		}
	}
	Record*last=*head;
	while(last->next!=*head){
		last=last->next;  //last element = last
	}	
	//agr head m srf 2 element hu 
	if((*head)->rollNo==toDel){
		*head=(*head)->next;
		free(curr);
		last->next=*head;
		cout<<"delleted"<<endl;
		return;
	}
	Record *prev=*head;
	curr=prev->next;
	while(curr!=*head){
		if(curr->rollNo==toDel){
			prev->next=curr->next;
			free(curr);
			cout<<"delleted"<<endl;
			return;
	}
		curr=curr->next;
		prev=prev->next;
	}
	
	
	
}


void deleteAll(Record ** head){
	Record*last=*head;
	while(last->next!=*head){
		last=last->next;  //last element = last
	}
	Record *curr=*head;
	while(curr!=*head){
		*head=curr->next;
		free(curr);
		curr=*head;
		last->next=curr;
	}
	*head=NULL;
	return;
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
