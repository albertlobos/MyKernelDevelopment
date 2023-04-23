#ifndef LINK_H
#define LINK_H

#include "../cpu/types.h"
#include "mem.h"

typedef struct _node {
unsigned int base_address;
unsigned int limit_offset;
unsigned int id;
struct _node *next;
struct _node *previous;
}node;


void add(node *head, unsigned int base, unsigned int limit);
void sort_by_id(node *list);
void printAddr(node *current);
void printNode(node *pointer);
void printList(node *head);

#endif
