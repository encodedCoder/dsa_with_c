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
Node * find(LinkedList *, int);
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);////////////
void reverse(LinkedList *);

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

Node * find(LinkedList *listPtr, int target){
  Node * currentNode = listPtr->head;
  while(currentNode->next != NULL){
    if(currentNode->data == target){
      break;
    }
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
  printf("deleteTarget is reached.\n");
  Node *currentNode = listPtr->head;
  if(listPtr->nodeCount == 1){
    if(currentNode->data == targetData){
      listPtr->head = NULL;
      listPtr->tail = NULL;
      listPtr->nodeCount--;
      free(currentNode);
      return 1;
    }
  }
  else{
    if(targetData == currentNode->data){
      listPtr->head = currentNode->next;
      listPtr->nodeCount--;
      free(currentNode);
      return 1;
    }
    else if(targetData == listPtr->tail->data){
      while(currentNode->next != listPtr->tail){
        currentNode = currentNode->next;
      }
      listPtr->tail = currentNode;
      if(currentNode->data == targetData){
        listPtr->nodeCount--;
        free(currentNode);
        return 1;
      }
    }
    else{
      while(currentNode->next != listPtr->tail){
        if(targetData = currentNode->data){
          listPtr->nodeCount--;
          free(currentNode);
          return 1;
        }
        else{
          currentNode = currentNode->next;
        }
      }
    }
  }
  return 0;
}

void menu(){
  printf("    Singly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("1. Load from file\n");          // load integer data from file and will create the list
  printf("2. Create list from random numbers\n");// by using insert_at_tail operation (menu option 3)  
  printf("3. Insert at head\n");          // inserting a new node as the first node
  printf("4. Insert at tail\n");          // inserting a new node as the last node
  printf("5. Print List (detail)\n");     // printing the linked list in details,
  printf("6. Print List (data only)\n");  // prints the integer data in each node
  printf("7. Find\n");                    // finds if an integer exisits in a node from
  printf("8. Delete first\n");            // deletes the first node
  printf("9. Delete last\n");             // deletes the last node
  printf("10. Delete a target node\n");    // deletes a particular node, if that exists
  printf("11. Reverse list\n");                 // will physically reverse the list
  printf("12. Quit\n");                   // to terminate each node
}

int main(){
  LinkedList list;
  initList(&list);

  int choice, quit = 0, data, n, target, success;
  menu();
  Node *current = NULL, *prev = NULL;
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
              printf("Will be implemented in next lectures of the section 7.\n");
              break;
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
              }
              printf("Enter target node value you want to delete: ");
              scanf(" %d", target);
              printf("now deleteTarget() is called to delete the target.\n");
              success = deleteTarget(&list, target);
              if(success == 1){
                printf("\n%d is found and deleted.\n", target);
              }else{
                printf("%d not found therefore there is no deletion.\n", target);
              }
              break;
      case 11:
              printf("Will be implemented in next lectures of the section 7.\n");
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
