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

void initList(LinkedList *);
int loadFromFile(LinkedList *, char *);
void insertAtTail(LinkedList *, int);
void printList(LinkedList *);
int reverseList(LinkedList *);


void initList(LinkedList *listPtr){
  listPtr->head = NULL;
  listPtr->tail = NULL;
  listPtr->nodeCount = 0;
}

int loadFromFile(LinkedList *listPtr, char *fileName){
  FILE *fp = fopen(fileName, "r");
  if(fp == NULL){
    return 0;
  }
  int data;
  fscanf(fp, "%d", &data);
  while(!feof(fp)){
    insertAtTail(listPtr, data);
    fscanf(fp, "%d", &data);
  }
  fclose(fp);
  return 1;
}

void insertAtTail(LinkedList *listPtr, int data){
  Node *newNode = (Node *)malloc(sizeof(Node));
  if(newNode == NULL){
    printf("Unable to create new node because of insufficient memory.\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  if(listPtr->nodeCount == 0){
    listPtr->head = newNode;
    listPtr->tail = newNode;
  }
  else{
    listPtr->tail->next = newNode;
    listPtr->tail = newNode;
  }
  listPtr->nodeCount++;
}

void printList(LinkedList *listPtr){
  if(listPtr->nodeCount == 0){
    printf("List is empty.\n");
    return;
  }
  Node * currentNode = listPtr->head;
  while(currentNode != NULL){
    printf("%d\n", currentNode->data);
    currentNode = currentNode->next;
  }
}

int reverseList(LinkedList *listPtr){
	Node *temp;
	listPtr->head->next->next = listPtr->head->next;
	listPtr->head->next = NULL;

	temp = listPtr->tail;
	listPtr->tail = listPtr->head;
	listPtr->head = temp;
}

int main(){
	LinkedList list1;
	initList(&list1);

	printf("Loading from file. PRESSANY.\n");
	getch();

	loadFromFile(&list1, "D:\\file1.txt");

	printf("Succesfully loaded from file now printing list. PRESSANY\n");
	getch();

	printf("List before reverseList() operation: \n");
	printList(&list1);

	printf("List is printed now reverseList. PRESSANY.\n");
	getch();

	reverseList(&list1);
	printf("List after reverseList() operation: \n");
	printList(&list1);
}