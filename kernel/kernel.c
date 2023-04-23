#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/link.h"
#include "../libc/mem.h"
#include "../cpu/types.h"


node *head = 0;
u32 global_id = 0;

void _start() {
    free_mem_addr = 0x5000;
    unsigned int number = (unsigned int)kmalloc(20, 0, (u32 *) &head);
    head -> base_address = number;
    head -> id = global_id++;
    printInt(head -> id);
    kprint("\n");
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\n"
        "Type END to halt the CPU\n> ");
}




void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    if (strcmp(input, "HI") == 0) {
        kprint("HEY!!!\n");
	printNode(head);
    }    
    if (strcmp(input, "ADD") == 0) {
	kprint("Will start to add node to list \n");
	add(head, 20000,30);
	kprint("Done adding \n");

    }
    if (strcmp(input, "ADD2") == 0) {
	kprint("Will start to add node to list \n");
	add(head, 10000,70);
	kprint("Done adding \n");

    }

    if (strcmp(input, "ADD3") == 0) {
	add(head, 15000, 40);

    }
    if (strcmp(input, "PRINT") == 0) {
	printList(head);

    }
	if(strcmp(input, "SORT") == 0) {
	kprint("About to sort");
	sort_by_id(head);
	}
	
    kprint("\nYou said: ");
    kprint(input);
    kprint("\n> ");
}
