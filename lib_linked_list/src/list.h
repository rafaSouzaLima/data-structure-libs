/**
 * Copyright (c) 2025 Rafael S Lima
 * 
 * This software is licensed under the MIT License. 
 * See the LICENSE file for more details.
 */

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    void *data;
    struct node *next;
};

struct linked_list {
    int count;
    struct node *begin;
    struct node *end;
};

int linked_list_init(struct linked_list *list);

int linked_list_add(struct linked_list *list, struct node *element);

bool linked_list_empty(struct linked_list *list);

int linked_list_remove(struct linked_list *list, struct node *element);

int linked_list_print(struct linked_list *list, void (*print_callback)(struct node *));

#endif