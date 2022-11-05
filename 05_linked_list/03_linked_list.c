#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void createListFromRandomNumbers(LinkedList *, int);
void insertAtHead(LinkedList *, int);
void insertAtTail(LinkedList *, int);
void printListDetail(LinkedList *);
void printList(LinkedList *);
Node * find(LinkedList *, int, Node **);
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);////////////
int reverseList(LinkedList *);

void initList(LinkedList *listPtr){
  listPtr->head = NULL;
  listPtr->tail = NULL;
  listPtr->nodeCount = 0;
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

void insertAtHead(LinkedList *listPtr, int data){
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
    newNode->next = listPtr->head;
    listPtr->head = newNode;
  }
  listPtr->nodeCount++;
}

void printListDetail(LinkedList *listPtr){
  if(listPtr->nodeCount == 0){
    printf("List is empty.\n");
    return;
  }
  printf("Printing linked list in details.\n");
  printf("HEAD: %p\n", listPtr->head);
  Node * currentNode = listPtr->head;
  int counter = 1;
  while(currentNode != NULL){
    printf("%d. (%p)[%d|%p]\n", counter++, currentNode, currentNode->data, currentNode->next);
    currentNode = currentNode->next;
  }
  printf("TAIL: %p\n", listPtr->tail);
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

Node * find(LinkedList *listPtr, int target, Node **previousNode){
  *previousNode = NULL;
  Node * currentNode = listPtr->head;
  while(currentNode != NULL){
    if(currentNode->data == target){
      break;
    }
    *previousNode = currentNode;
    currentNode = currentNode->next;
  }
  return currentNode;
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

void createListFromRandomNumbers(LinkedList *listPtr, int nums){
  int i;
  srand(time(NULL));
  for(i = 0; i<nums; ++i){
    int randomNumber = rand() % 1000;
    insertAtTail(listPtr, randomNumber);
  }
}

int deleteFirst(LinkedList *listPtr){
  if(listPtr->nodeCount == 0){
    return -9999;
  }
  int data = listPtr->head->data;
  Node *firstNode = listPtr->head;
  if(listPtr->nodeCount == 1){
    listPtr->head = NULL;
    listPtr->tail = NULL;
  }
  else{
    listPtr->head = listPtr->head->next;
  }
  free(firstNode);
  listPtr->nodeCount--;
  return data;
}

int deleteLast(LinkedList *listPtr){
  if(listPtr->nodeCount == 0){
    return -9999;
  }
  Node * currentNode = listPtr->head, *lastNode = listPtr->tail;
  int data = lastNode->data;
  if(listPtr->nodeCount == 1){
    listPtr->head = NULL;
    listPtr->tail = NULL;
  }
  else{
    while(currentNode->next != lastNode){
      currentNode = currentNode->next;
    }
    listPtr->tail = currentNode;
    listPtr->tail->next = NULL;
  }
  free(lastNode);
  listPtr->nodeCount--;
  return data;
}

int deleteTarget(LinkedList *listPtr, int targetData){
  Node *currentNode = NULL, *previousNode = NULL;
  currentNode = find(listPtr, targetData, &previousNode);
  if(listPtr->nodeCount == 1){
    listPtr->head = NULL;
    listPtr->tail = NULL;
  }else if(currentNode == listPtr->head){
    listPtr->head = currentNode->next;
  }else if(currentNode == listPtr->tail){
    listPtr->tail = previousNode;
    previousNode->next = NULL;
  }else{
    previousNode->next = currentNode->next;
  }
  free(currentNode);
  listPtr->nodeCount--;
  return 1;
}

int reverseList(LinkedList *listPtr){
  Node *currentNode, *previousNode, *nextNode/**temp*/;

  previousNode = NULL;
  currentNode = listPtr->head;
  nextNode = currentNode->next;

  while(1){
    currentNode->next = previousNode;
    if(currentNode == listPtr->tail)
      break;
    previousNode = currentNode;
    currentNode = nextNode;
    nextNode = nextNode->next;
  }

  // temp = listPtr->tail;
  listPtr->tail = listPtr->head;
  listPtr->head = currentNode;
  return 1;
}
/*{// this is very trivial approach also but very bad choice
  //beacause it very computational intensive. lot's of traversing and function call is present in it.  
  // Node *temp, *currentNode = NULL, *previousNode = NULL;
  // currentNode = listPtr->tail;
  // while(currentNode != listPtr->head){
  //   if(find(listPtr, currentNode->data, &previousNode) == NULL){
  //     printf("there is something wrong in getting previousNode.\n");
  //     printf("finding previousNode failed.\n");
  //     return 0;
  //   }
  //   currentNode->next = previousNode;
  //   currentNode = previousNode;
  // }
  // currentNode->next = NULL;
  // temp = listPtr->tail;
  // listPtr->tail = listPtr->head;
  // listPtr->head = temp;
  // return 1;}*/

void menu(){
  printf("    Singly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("01. Load from file\n");          // load integer data from file and will create the list
  printf("02. Create list from random numbers\n");// by using insert_at_tail operation (menu option 3)  
  printf("03. Insert at head\n");          // inserting a new node as the first node
  printf("04. Insert at tail\n");          // inserting a new node as the last node
  printf("05. Print List (detail)\n");     // printing the linked list in details,
  printf("06. Print List (data only)\n");  // prints the integer data in each node
  printf("07. Find\n");                    // finds if an integer exisits in a node from
  printf("08. Delete first\n");            // deletes the first node
  printf("09. Delete last\n");             // deletes the last node
  printf("10. Delete a target node\n");    // deletes a particular node, if that exists
  printf("11. Reverse list\n");                 // will physically reverse the list
  printf("12. Quit\n");                   // to terminate each node
}

int main(){
  LinkedList list;
  initList(&list);

  int choice, quit = 0, data, n, target, success;
  Node *current = NULL, *prev = NULL;

  menu();
  while(!quit){
    printf("Please input your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1: 
              success = loadFromFile(&list, "D:\\file1.txt");
              (success == 1) ? printf("successfully loaded file.\n"):printf("Error loading file.\n");
              break;
      case 2: 
              printf("Enter how many random numbers you want: \n");
              scanf("%d", &n);
              createListFromRandomNumbers(&list, n);
              break;
      case 3:
              printf("Input data to insert at head (as first node): ");
              scanf("%d", &data);
              insertAtHead(&list, data);
              break;
      case 4:
              printf("Input data to insert at tail (as last node): ");
              scanf("%d", &data);
              insertAtTail(&list, data);
              break;
      case 5: 
              printListDetail(&list);
              break;
      case 6:
              printList(&list);
              break;
      case 7: 
              if(list.nodeCount == 0){
                printf("List is empty.\n");
                break;
              }else{
                printf("Enter the value you want to find: ");
                scanf("%d", &target);
                if(find(&list, target, &prev) == NULL){
                  printf("%d is not present in the list.\n", target);
                }
                else{
                  printf("%d is found in the list\n", target);
                }
                break;
              }
      case 8: 
              data = deleteFirst(&list);
              if(data == -9999){
                printf("List is empty.\n");
              }
              else{
                printf("%d data was fisrt node and deleted now.\n", data);
              }
              break;
      case 9: 
              data = deleteLast(&list);
              if(data == -9999){
                printf("List is empty.\n");
              }
              else{
                printf("%d data was last node and now deleted.\n", data);
              }
              break;
      case 10: 
              if(list.nodeCount == 0){
                printf("List is empty.\n");
                break;
              }else{
                printf("Enter target node value you want to delete: ");
                scanf("%d", &target);
                printf("You want to delete: %d\n", target);

                if(find(&list, target, &prev) == NULL){
                  printf("%d is not present in the list and cannot be deleted.\n", target);
                  break;
                }else{
                  printf("%d is present in the list now deleting it.\n", target);
                  success = deleteTarget(&list, target);
                }

                if (success == 1)
                  printf("%d is deleted and list is updated.\n", target);
                else
                  printf("There is some error in deleting the value from list.\n");
                break;
              }
      case 11:
              success = reverseList(&list);
              if(success == 1) printf("successfully reversed list.\n");
              else printf("something's wrong, failed to reverseList.\n");
              break;
      case 12:
              quit = 1;
              break;
      default:
              printf("Invalid option chosen, valid option is from 1 - 11\n");
              break;
    }
  }
  return 0;
}
