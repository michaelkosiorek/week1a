#include <iostream>

#include "linked_list.h"

using namespace std;

/*
build_new_linked_list:
	returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return null
*/
struct node * build_new_linked_list(int total_new_elements) {
    if (0 == total_new_elements) {
        return NULL;
    } else {
        struct node * root = new node;
        root->data = -1;
        struct node * linked_list = root;

        for (int i = 0 ; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->data = i+1;
            linked_list = linked_list->next;
        }
        linked_list->next=nullptr;

        return root;
    }
}

/*
get_linked_list_data_item_value:
    returns -1 if not enough nodes
*/
int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements || total_elements==0) 
        return -1;

    struct node * linked_list = start;

    for (int i = 0; i < node_number-1; i++) {
        linked_list = linked_list->next;
    }

    return linked_list->data;

}

void print_linked_list(struct node * start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements or total_elements==0
	Returns true otherwise
*/
bool update_data_in_linked_list(struct node * start, 
    int node_to_update, 
    int update_val, 
    int total_elements) {

    if ((node_to_update > total_elements) || total_elements==0)
        return false;

    struct node *current_node = start;
    for (int i=0; i<node_to_update; i++) {
        current_node = current_node->next;
    }

    current_node->data = update_val;
    return true;
}

void delete_linked_list(struct node * start) {
    if (start==nullptr)
        return;
    else {

        struct node *node_to_delete;
        struct node *next_node = start;

        do {
            node_to_delete = next_node;
            next_node = node_to_delete->next;
            delete node_to_delete;
        } while(next_node!=nullptr);

    }
}