#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct {
	struct Node *head;
	struct Node *tail;
	int nodeCount;
}LinkedList;

// function prototypes
void initList(LinkedList *);
void insertOrder(LinkedList *, int);
void printList(LinkedList *);
// Precondition: LinkedList object pointed by listptr must be existing.
// Return Value: Nothing
void initList(LinkedList *lstPtr){
	lstPtr->head = NULL;
	lstPtr->tail = NULL;
	lstPtr->nodeCount = 0;
}

void printList(LinkedList *lstPtr){
	if (lstPtr->nodeCount == 0){
		printf("Linked list is empty\n");
		return;
	}
	Node *current = lstPtr->head;
	while(current != NULL){
		printf("%d\n", current->data);
		current = current->next;
	}
} // end of printList

void insertOrder(LinkedList *listPtr, int v){
	Node * newNode, * currentNode;
	newNode = (Node*)malloc(sizeof(Node));
	currentNode = (Node*)malloc(sizeof(Node));
	newNode->data = v;
	newNode->next = NULL;

	if(listPtr->nodeCount == 0){
		listPtr->head = newNode;
		listPtr->tail = newNode;
	}
	else{
		currentNode = listPtr->head;
		while(1){
			if(newNode->data <= currentNode->data && currentNode == listPtr->head){
				// printf("It's case 1: We're inserting before first node.\n");
				// printf("%d is less than %d and it is first node.\n", newNode->data, currentNode->data , currentNode->data);
				// printf("We've inserted %d: \n", newNode->data);
				newNode->next = currentNode;
				listPtr->head = newNode;
				break;
			}
			else if(newNode->data >= currentNode->data && newNode->data <= currentNode->next->data){
				// printf("It's case 2: we're somewhere is the middle of list.\n");
				// printf("%d is greater than %d and less than %d\n", newNode->data, currentNode->data, currentNode->next->data);
				// printf("We've inserted %d: \n", newNode->data);
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				break;
			}
			else if(newNode->data >= currentNode->data && currentNode->next->next == NULL){
				// printf("It's case 3: we're inserting at the end of list.\n");
				// printf("%d is greater than %d and it is last node.\n", newNode->data, currentNode->data);
				// printf("We've inserted %d: \n", newNode->data);
				listPtr->tail->next = newNode;
				listPtr->tail = newNode;
				break;
			}
			else{
				currentNode = currentNode->next;
				// printf("%p\n", currentNode);
			}
		}
	}
	listPtr->nodeCount++;
	// printf("%d\n", listPtr->nodeCount++);
}

Node * find(LinkedList *listPtr, int target){
  Node * currentNode = listPtr->head;
  while(currentNode != NULL){
    if(currentNode->data == target){
      break;
    }
    currentNode = currentNode->next;
  }
  return currentNode;
}

int main(){
	int element = 200;
	LinkedList ordList;
	initList(&ordList);
	insertOrder(&ordList, 100);
	insertOrder(&ordList, 10);
	insertOrder(&ordList, 200);
	insertOrder(&ordList, 70);
	insertOrder(&ordList, 80);
	insertOrder(&ordList, 50);
	// insertOrder(&ordList, 5);
	// insertOrder(&ordList, 50);
	// insertOrder(&ordList, 2);
	printList(&ordList);//should print: 10 50 70 80 100 200 
	// printf("%d\n", ordList.nodeCount);
	find(&ordList, element) != NULL?printf("%d found.\n", element):printf("%d not found.\n", element);

	return 0;
}