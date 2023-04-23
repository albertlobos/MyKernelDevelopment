//Linked list file
#include "mem.h"
#include "../libc/string.h"
#include "../drivers/screen.h"
#include "../cpu/ports.h"
#include "../cpu/types.h"


typedef struct _node {
unsigned int base_address;
unsigned int limit_offset;
unsigned int id;
struct _node *next;
struct _node *previous;
}node;

void printNode(node *pointer){
	char str[20];
	int_to_ascii(pointer -> base_address,str);
	kprint(str);
	kprint("this is the base address");
}

void printAddr(node *current){
	char str[20];
	int_to_ascii((int) current, str);
	kprint(str);
}




void add(node *head, unsigned int base, unsigned int limit){
	node *current = head;
	
	//Got to create newNode in here so that passed parameters can stick
	node *newNode = 0;
	kmalloc(20, 0, (u32 *) &newNode);
	newNode -> base_address = base;
	newNode -> limit_offset = limit;
	newNode -> id = global_id++;
	newNode -> next = 0;
	newNode -> next = 0;

	
	if(current -> next == 0){
	current -> next = newNode;
	newNode -> previous = head;
	kprint("Params in the while loop... --> base_address of next: ");
	printInt(current -> next -> base_address);
	kprint("base + Limit: ");
	printInt(base+limit);

	kprint("\n in the first if statement \n");
	return;
}




	kprint("Params in the while loop... --> base_address of next: ");
	printInt(current -> next -> base_address);
	kprint("base + Limit: ");
	printInt(base+limit);


while(current -> next != 0 && current -> next -> base_address > (base + limit)){
	kprint("Params in the while loop... --> base_address of next: ");
	printInt(current -> next -> base_address);
	kprint("base + Limit: ");
	printInt(base+limit);
	kprint("\n");

	current = current -> next;	
	kprint("\n in the while loop \n");

	kprint("Params in the while loop... --> base_address of next: ");
	printInt(current -> next -> base_address);
	kprint("base + Limit: ");
	printInt(base+limit);
	kprint("\n");
}

if(current -> next == 0){
	current -> next = newNode;
	newNode -> previous = current;
	return;
}

	newNode -> next = current -> next;
	current -> next -> previous = newNode;
	newNode -> previous = current;
	current -> next = newNode;


}

void sort_by_id(node *list){
	//node *current = list;
	if (list == 0){
	return;
	}
	int boolean = 0;
	node *current = list;

	kprint("Entering the do-while loop\n");
	do{
		//node *temp = current;
	  	while(current -> next != 0){
			node *before = current -> previous;
			node *after = current -> next;
			node *after2 = current -> next -> next;		

								if(current -> id > after -> id){
									before -> next = after;
									after -> previous = before;
									after2 -> previous = current;
									after -> next = current;
									current -> previous = after;
									current -> next = after2;
									boolean = 1;
								}

			current = current -> next; 

			}
		//boolean == 0;
	} while(boolean == 0);

	kprint("out of the do-while loop");
	
	
}
/*
void sortList(node *head) {
    if (head == 0) {
        return;
    }
    int swapped = 0; //false
    node *ptr1;
    node *lptr = 0;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->id > ptr1->next->id) {
                int temp = ptr1->id;
                ptr1->id = ptr1->next->id;
                ptr1->next->id = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped = 1);
}
*/




void printList(node *head){

	node *current = head;
	if(current == 0){
		kprint("head is empty\n");
		return;
	}
	else if(current -> next == 0){
		printAddr(head);
		return;
	}
	else {

		while(current != 0){
			kprint("Current ID of node is -->");
			printInt(current -> id);
			kprint(" and is in addres: ");
			printAddr(current);
			kprint("-->  \n");
			current = current -> next;
		}

		return;
	}

}






