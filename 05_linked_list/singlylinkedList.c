#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct{
	Node *head;
	Node *tail;
	int nodeCount;
}LinkedList;

void menu(void);

int main(void){
	while(1){

	}
	return 1;
}

void menu(void){
  printf("    Singly Linked List Operations\n");
  printf("----------------------------------------\n");
  printf("1. Load from file\n");          // load integer data from file and will create the list
                                          // by using insert_at_tail operation (menu option 3)  
  printf("2. Insert at head\n");          // inserting a new node as the first node
  printf("3. Insert at tail\n");          // inserting a new node as the last node
  printf("4. Print List (detail)\n");     // printing the linked list in details,
                                          // including the data and pointer in each node
  printf("5. Print List (data only)\n");  // prints the integer data in each node
  printf("6. Find\n");                    // finds if an integer exisits in a node from
                                          // the start in the list
  printf("7. Delete first\n");            // deletes the first node
  printf("8. Delete last\n");             // deletes the last node
  printf("9. Delete a target node\n");    // deletes a particular node, if that exists
  printf("10.Reverse\n");                 // will physically reverse the list
  printf("11. Quit\n");                   // to terminate each node
}
}