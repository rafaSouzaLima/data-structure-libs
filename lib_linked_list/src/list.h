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

/**
 * @brief Initialize a linked list.
 * 
 * This function initializes a linked list through its pointer, and must be 
 * called before using any of the other linked_list_* functions.
 * 
 * @param list Pointer to the linked list. It must not be NULL.
 * 
 * @return 0 on sucess, or 1 in case of an error (e.g. if a NULL pointer is passed).
 */
int linked_list_init(struct linked_list *list);

/**
 * @brief Add a element to the end of the linked list.
 * 
 * This function appends the `element` node to the end of the
 * passed `list`.
 * 
 * @param list Pointer to the linked list. It must not be NULL.
 * @param element Pointer to node that must not be present on list and must not be NULL.
 * 
 * @return 0 on sucess, or 1 in case of an error (e.g. if a NULL pointer is passed).
 */
int linked_list_add(struct linked_list *list, struct node *element);

/**
 * @brief Checks if the list is empty.
 *
 * This function verifies whether the linked list pointed to by `list` 
 * contains any elements.
 *
 * @param list Pointer to the linked list to check. Must not be NULL.
 *
 * @return `true` if the list is empty, `false` otherwise.
 */
bool linked_list_empty(struct linked_list *list);


/**
 * @brief Removes an element from the linked list.
 * 
 * This function removes the specified `element` from the linked list
 * pointed to by `list`. The list must be properly initialized, and 
 * both `list` and `element` must not be NULL.
 * 
 * @param list Ponter to the linked list from which the element will be removed. 
 * Must not be NULL.
 * @param element Pointer to the node to remove from the list. Must not be NULL and 
 * must belong to the list.
 * 
 * @return 0 on sucess, or 1 if an error occurs (e.g. NULL pointers or element not found
 * in the list). 
 */
int linked_list_remove(struct linked_list *list, struct node *element);

/**
 * @brief Prints the content of the linked list.
 * 
 * This function traverses the linked list pointed to by `list` and 
 * calls the `print_callback` function on each node.
 * 
 * @param list Pointer to the linked list to print. Must not be NULL.
 * @param print_callback Function pointer to a callback that receives 
 * each node to handle its printing. Must not be NULL.
 * 
 * @return 0 on success, or 1 if an error occurs (e.g., if `list` or 
 * `print_callback` is NULL).
 */
int linked_list_print(struct linked_list *list, void (*print_callback)(struct node *));

#endif