#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    char        *name;
    int         index;
    char        *value;
    struct node *left;
    struct node *right;
    struct node *next;
    struct node *top;
};


void print_nodes(struct node *nodes) {
    struct node *tmp_nodes;
    int i = 0;

    tmp_nodes = nodes->top;
    printf("-----------------\n");
    while (tmp_nodes != NULL) {
        printf("index: %d\t| name: \"%s\"\t| value: \"%s\" \t| addr: %p\n", tmp_nodes->index, tmp_nodes->name, tmp_nodes->value, tmp_nodes);
        tmp_nodes = tmp_nodes->next;
        i++;
    }
    printf("-----------------\n\n");
}

struct node *get_last_node(struct node *node) {
    struct node *tmp_node = node->top;

    while (tmp_node->next != NULL) {
        tmp_node = tmp_node->next;
    }
    return (tmp_node);
}

int get_last_index(struct node *node) {
    int index = 0;
    struct node *tmp_node = node->top;

    while (tmp_node != NULL) {
        tmp_node = tmp_node->next;
        index++;
    }
    return (index);
}

void fill_node(struct node *node, struct node *top_node, char *name, char *value, int index) {
    //printf("\nsrc: %s | dest: %s\n", name, node->name);
    node->name = malloc(sizeof(char *) * strlen(name));
    node->value = malloc(sizeof(char *) * strlen(value));
    strcpy(node->name, name);
    strcpy(node->value, value);
    node->index = index >= 0 ? index : get_last_index(top_node);
    node->top = top_node;
    node->next = NULL;
    node->left = NULL;
    node->right = NULL;
}

void add_node(struct node *nodes, char *name, char *value) {
    struct node *new_node = malloc(sizeof(struct node));
    struct node *last_node;

    fill_node(new_node, nodes->top, name, value, -1);
    last_node = get_last_node(nodes);
    last_node->next = new_node;
    printf("+ adding new node at the end of the list with name: \"%s\" and value: \"%s\"\n\n", name, value);
    print_nodes(nodes);
}

struct node *get_previous_node(struct node *nodes, int index) {
    struct node *tmp_node = nodes->top;

    while (tmp_node->index < index - 1) {
        tmp_node = tmp_node->next;
    }
    return (tmp_node);
}

struct node *get_next_node(struct node *nodes, int index) {
    struct node *tmp_node = nodes->top;

    while (tmp_node->index <= index - 1) {
        tmp_node = tmp_node->next;
    }
    return (tmp_node);
}

void set_new_indexes_inc(struct node *node) {
    struct node *tmp_node = node->next;

    while (tmp_node != NULL) {
        tmp_node->index++;
        tmp_node = tmp_node->next;
    }
}

void set_new_indexes_dec(struct node *node) {
    struct node *tmp_node = node->next;

    while (tmp_node != NULL) {
        tmp_node->index--;
        tmp_node = tmp_node->next;
    }
}

void delete_node(struct node *nodes, int index) {
    struct node *previous_node;
    struct node *next_node;

    if (index < 0) {
        previous_node = get_previous_node(nodes, get_last_index(nodes) - 1);
        previous_node->next = NULL;
        printf("- deleting node at end of the list\n\n");
    } else {
        printf("- deleting node at index %d the list\n\n", index);
        previous_node = get_previous_node(nodes, index);
        next_node = get_next_node(nodes, index + 1);
        previous_node->next = next_node;
        set_new_indexes_dec(nodes);
    }
    print_nodes(nodes);
}

void insert_node(struct node *nodes, char *name, char *value, int index) {
    struct node *new_node = malloc(sizeof(struct node));
    struct node *previous_node = get_previous_node(nodes, index);
    struct node *next_node = get_next_node(nodes, index);

    fill_node(new_node, nodes->top, name, value, index);
    new_node->next = next_node;
    previous_node->next = new_node;
    set_new_indexes_inc(new_node);
    printf("> inserting new node at index %d of the list with name: \"%s\" and value: \"%s\"\n\n", index, name, value);
    print_nodes(nodes);
}

int main(void) {
    struct node nodes;

    nodes.top = &nodes;
    fill_node(&nodes, nodes.top, "node 1", "created with fill_node()", 0);
    add_node(&nodes, "node 2", "created with add_node() v1");
    add_node(&nodes, "node 3", "created with add_node() v2");
    insert_node(&nodes, "node 4", "inserted() at index 1", 1);
    delete_node(&nodes, -1);
    delete_node(&nodes, 1);
    return (0);
}