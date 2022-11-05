#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}Node;

void addnode(Node **head)
{
	int x = 0;
	
	while(1)
	{
    	printf("Enter the value you want to add/terminate by -1 : ");
		scanf("%d",&x);

		if(x != -1){
			if(*head == NULL){
				Node* temp = (Node *)malloc(sizeof(Node)); 
				temp->info = x;
				temp->next = NULL;
				*head = temp;
				printf("new node is created and it's value is: %d\n", (*head)->info);
			}
			else{
				Node *prv = NULL, *nxt = *head;
				while(nxt != NULL)
				{
					prv = nxt;
					nxt = nxt->next;
				}
				nxt = (Node *)malloc(sizeof(Node));
				nxt->info = x;
				nxt->next = NULL;
				prv->next = nxt;
			}
		}else
			return;
	}
}


void displaynodes(Node *head)
{
	printf("displaynodes() is called.\n");
	
	if(head != NULL){

		printf("if condition is checked and true.\n");
		Node *temp = head;
		while(temp != NULL)
		{
			printf("%d ",temp->info);
			temp = temp->next;
		}
	}
	else
		printf("List is empty.\n");
}


int main()
{
	Node *head = NULL;
	int x;
	while(1)
	{
		printf("\n1. Add node\n2. Delete node\n3. Search node\n4. Display node\n5. Count nodes\nGive your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				addnode(&head);
				break;
			case 2:
				// deletenode(list);
				break;
			case 3:
				// searchnode(list);
				break;
			case 4:
				displaynodes(head);
				break;
			case 5:
				// printf("%d",countnodes(list));
				break;
			case 6:
				exit(1);
			default:
				printf("WRONG CHOICE\n");
		}
	}
	return 0;
}