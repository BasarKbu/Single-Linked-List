#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Linked list 

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

Node* head = NULL;
Node* temp = NULL;

void AddToStart(int n){
	temp =(struct node*)malloc(sizeof(struct node));
	temp -> data = n;
	temp -> next = head;
	head = temp;
	
}

void AddToEnd(int n){
	temp = head;
	if(temp == NULL)
	AddToStart(n); // We will send it to the start I explained this with a simple sentence in the AddToBetween.
	else{
	  Node* addNode =(Node*)malloc(sizeof(Node));	
	  addNode -> data = n;
	  addNode ->next = NULL;	
	  while(temp -> next != NULL)
	  	temp = temp -> next;
	  
		temp ->next = addNode;
		
	}
	
}

void AddToBetween(int n,int data2){
	
	if(head == NULL)
	AddToStart(n); // if the indivual first choose the AddToBetween beacuse there is no nodes we will send it to the AddToStart. 
	else{
	 Node* addNode =(Node*)malloc(sizeof(Node));	
	 addNode -> data = n;	
	 temp = head;	
	 while(temp->next->data != data2)
	 	 temp = temp ->next;
	 	 
	 	 Node* temp2 = (Node*)malloc(sizeof(Node));
         temp2 = temp ->next;
		 temp -> next = addNode;
		 addNode -> next = temp2;
	}
	
}

void DeleteStart(){
	temp = head;
	if(temp == NULL)
	printf("Your list is empty. \n");
	else{
		temp = head -> next;
		free(head);
		head = temp;
	}
	
}

void DeleteBetween(int x){
	temp = head;
	if(temp == NULL)
	printf("List is empty. \n");
	else if(temp->data == x)
	free(temp);
	else{
		Node* temp2;
		while(temp->next->data != x)
		temp = temp -> next;
		
		temp2 = temp -> next;
		temp -> next = temp->next->next;
		free(temp2);
	}
	
	
}

void DeleteEnd(){
	temp = head;
	if(temp == NULL)
	printf("Your list is empty. \n");
	else{
		
		while(temp -> next -> next != NULL)
		temp = temp ->next;
		
		free(temp->next->next);
		temp -> next = NULL;
	}
	
}

void Reverse(){
	temp = head;
	if(temp == NULL)
	printf("There is no element to reverse. \n");
	else{
	  Node* temp2 = NULL;
	  Node* prev = NULL;	
	  
	  while(temp != NULL){
	  	temp2 = temp -> next;
	  	temp->next = prev;
	  	prev = temp;
	  	temp = temp2;
	  }	
	 head = prev;	
		
	}
	
	
	
}

void Node_count(){
	temp = head;
	if(temp == NULL)
	printf("Your list is empty so basically you don't have a node. \n");
	else{
	int cnt = 1;	
		
	while(temp ->next != NULL){
		temp = temp ->next;
		cnt++;
	}
		
	printf("Element count is:%d ",cnt);
		
	}
	
}

void SumOfData() {
    temp = head;
    if (temp == NULL)
        printf("Your list is empty. So the sum is 0. \n");
    else {
        int sum = temp->data;

        while (temp->next != NULL) {
            temp = temp->next;
            sum += temp->data;
        }

       
        printf("The sum of the List is: %d \n", sum);
    }
}

	



void print(){
	system("cls");
	temp = head;
	if(temp == NULL)
	printf("List is empty. \n");
	
	else{
		
	while(temp -> next != NULL){
		printf("%d ",temp->data);
		temp = temp -> next;
	}	
		printf("%d ",temp->data);
		
	}
 printf("\n \n");	
	
}


int main(){
	int x,option,prev,deleted;
	
	while(1){
	printf("\n \n");
	printf("1->Adds a node to the start. \n");
	printf("2->Adds a node between nodes. \n");
	printf("3->Adds a node to the end. \n");
	printf("4->Deletes a node from the start. \n");
	printf("5->Deletes a node from the between. \n");
	printf("6->Deletes the last node. \n");
	printf("7->Reverses the elements of the list. \n");
	printf("8->Calculates the element count in the list. \n");
	printf("9->Computes the sum of the list. \n");
	printf("10->Prints the data of the nodes. \n");
	printf("-1->Exits from the program. \n");
	printf("\n \n");
	
	printf("Enter your option: \n"); scanf("%d",&option);
	
	
	switch(option){
		
	 case 1:
	 printf("Enter a number: \n"); scanf("%d",&x);
	 AddToStart(x); 
	 break;
	 
	 case 2:
	 printf("Enter the nodes data: \n"); scanf("%d",&prev);
	 printf("Enter a number: \n"); scanf("%d",&x);
	 AddToBetween(x,prev);
	 break;
	 
	 case 3:
	 printf("Enter a number: \n"); scanf("%d",&x);
	 AddToEnd(x);
	 break;
	 
	 case 4:
	 printf("Start node is getting deleted. \n");	
	 DeleteStart();
	 break;
	 
	 case 5:
	 printf("Enter the data of the node that you want deleted. \n"); scanf("%d",&deleted);
	 DeleteBetween(deleted);
	 break;
	 
	 case 6:
	 printf("Last node is getting deleted. \n");
	 DeleteEnd();
	 break;
	 
	 case 7:
	 printf("The elements are getting reversed. \n");
	 Reverse();
	 break;
	 
	 case 8:
	 printf("The element count is getting calculated. \n");
	 Node_count();
	 break;
	 
	 case 9:
	 printf("The sum of the list is getting computed. \n");
	 SumOfData();
	 break;
	 
	 case 10:
	 printf("List \n");
	 print();
	 break;
	 
	 case -1:
	 printf("You are exiting the program ... \n");
	 exit(0);
	 
	 default:printf("There isn't a option such as this. \n"); 
	         printf(" \n \n");         	
}
	
	
	
   }
   
   
    getch();   
	return 0;
}
