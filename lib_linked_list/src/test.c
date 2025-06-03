/*
    Copyright (c) 2025 Rafael S Lima

    This software is licensed under the MIT License.
    See the LICENSE file for more details.
*/

#include "list.h"

#define LIST_SIZE 10

void print_element(struct node *element) {
    printf("[%d]", *(int *)(element->data));
}

int main() {
    struct linked_list list;
    struct node nodes[100];
    int integers[100];

    for (int i = 0; i < 100; i++) {
        integers[i] = i + 1;
        nodes[i].data = &integers[i];
    }

    linked_list_init(&list);

    linked_list_print(&list, print_element); puts("\n");

    for (int i = 0; i < LIST_SIZE; i++)
        linked_list_add(&list, &nodes[i]);

    linked_list_print(&list, print_element); puts("\n");

    linked_list_remove(&list, list.begin);
    linked_list_print(&list, print_element); puts("\n");

    linked_list_remove(&list, list.end);
    linked_list_print(&list, print_element); puts("\n");

    linked_list_remove(&list, &nodes[5]);
    linked_list_print(&list, print_element); puts("\n");

    linked_list_remove(&list, &nodes[50]); // Trying to remove a element that is not inside the list.

    while(!linked_list_empty(&list))
        linked_list_remove(&list, list.begin);

    linked_list_print(&list, print_element); puts("\n");
    linked_list_remove(&list, &nodes[50]); // Trying to remove an element with empty list.

    return 0;
}