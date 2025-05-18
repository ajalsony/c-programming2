#include <stdio.h>
#include <stdlib.h>

struct Node {
	int expo;
	int coeff;
	struct Node* next;
}p1,p2,result;

struct Node* head = NULL;

struct Node* createNode(int coeff,int expo) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL){
		printf("Memory Allocation failed");
		exit(1);
		
	}
	
	newNode -> coeff = coeff;
	newNode -> expo = expo;
	newNode -> next = NULL;
	return newNode;
}
void insertNode(struct Node** head, int expo, int coeff){
	struct Node* newNode = createNode(expo,coeff);
	if(*head==NULL){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while(temp->next!=NULL){
		temp = temp->next;
	
	}
	temp->next=newNode;
}

void displayPoly(struct Node* poly){
	while(poly!=NULL){
		printf("%dx^%d",poly->coeff,poly->expo);
		if(poly!=NULL){
			printf("+");
		}
		
		poly = poly->next;
		
	}
	printf("\n");
}
struct Node* addPoly(struct Node* p1,struct Node* p2){
	struct Node* result = NULL;
	
	while(p1!=NULL & p2!=NULL){
		if(p1->expo==p2->expo){
			insertNode(&result,p1->coeff+p2->coeff,p1->expo);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->expo > p2->expo){
			insertNode(&result,p1->coeff,p1->expo);
			p1=p1->next;
		}
		else{
			insertNode(&result,p2->coeff,p2->expo);
			p2=p2->next;
		}	
	}
	while(p1!=NULL){
		insertNode(&result,p1->coeff,p1->expo);
		p1=p1->next;
	}
	while(p2!=NULL){
		insertNode(&result,p2->coeff,p2->expo);
		p2=p2->next;
	}
	return result;
}
void inputPoly(struct Node** poly){
	int n,coeff,expo;
	printf("Num of terms: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		printf("Enter coeff amd expo: ");
		scanf("%d %d",&coeff,&expo);
		insertNode(poly,coeff,expo);
	}
}


int main(){
	struct Node* p1 = NULL;
	struct Node* p2  = NULL;
	
	inputPoly(&p1);
	inputPoly(&p2);
	
	struct Node* result = addPoly(p1,p2);
	displayPoly(result);
	
	
}
