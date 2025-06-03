/*
    Copyright (c) 2025 Rafael S Lima

    This software is licensed under the MIT License.
    See the LICENSE file for more details.
*/

#include "list.h"

int linked_list_init(struct linked_list *list) {
    if (!list) {
        fprintf(stderr, "linked_list_init error: NULL parameter passed!\n");
        return 1;
    }
    list->begin = NULL;
    list->end = NULL;
    list->count = 0;
    return 0;
}

int linked_list_add(struct linked_list *list, struct node *element) {
    if (!list || !element) {
        fprintf(stderr, "linked_list_add error: NULL parameters passed!\n");
        return 1;
    }
    
    element->next = NULL;
    if (linked_list_empty(list))
        list->begin = element;
    else
        list->end->next = element;
    list->end = element;
    list->count++;
    return 0;
}

bool linked_list_empty(struct linked_list *list) {
    return !list || list->count == 0;
}

int linked_list_remove(struct linked_list *list, struct node *element) {
    if (!list || !element) {
        fprintf(stderr, "linked_list_remove error: NULL parameters passed!\n");
        return 1;
    }

    if (linked_list_empty(list)) {
        fprintf(stderr, "linked_list_remove error: Linked list is empty!\n");
        return 1;
    }

    struct node *current = list->begin, *previous = NULL;
    while (current != NULL && current != element) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "linked_list_remove error: Element does not exist in the list passed!\n");
        return 1;
    }

    if (current == list->end)
        list->end = previous;

    if (previous == NULL)
        list->begin = current->next;
    else 
        previous->next = current->next;

    current->next = NULL;
    list->count--;
    return 0;
}

int linked_list_print(struct linked_list *list, void (*print_callback)(struct node *)) {
    if (!list || !print_callback) {
        fprintf(stderr, "linked_list_print error: NULL parameter passed!\n");
        return 1;
    }

    for (struct node *i = list->begin ; i != NULL ; i = i->next)
        print_callback(i);
    return 0;
}