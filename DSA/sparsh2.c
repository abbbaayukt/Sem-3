#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int data;
    struct node *next;
};
struct node* create_node(int row, int col, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->row = row;
    temp->col = col;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct node* insert_node(struct node *head, int row, int col, int data) {
    struct node *temp = create_node(row, col, data);

    if (head == NULL) {
        return temp;
    }
    if (row < head->row || (row == head->row && col < head->col)) {
        temp->next = head;
        return temp;
    }
    struct node *current = head;
    struct node *prev = NULL;
    while (current != NULL && (current->row < row || (current->row == row && current->col < col))) {
        prev = current;
        current = current->next;
    }
    if (current != NULL && current->row == row && current->col == col) {
        current->data += data;
        free(temp); 
    } else {
        prev->next = temp;
        temp->next = current;
    }
    return head;
}
struct node* create_sparse_matrix(int non_zero_elements) {
    struct node *head = NULL;
    int row, col, data;
    printf("Enter the row, column, and value of non-zero elements:\n");
    for (int i = 0; i < non_zero_elements; i++) {
        printf("Element %d:\n", i + 1);
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        printf("Value: ");
        scanf("%d", &data);
        head = insert_node(head, row, col, data);
    }
    return head;
}
void display(struct node *head) {
    if (head == NULL) {
        printf("The matrix is empty or has no non-zero elements.\n");
        return;
    }
    struct node *temp = head;
    printf("\nLinked list representation of the sparse matrix:\n");
    while (temp != NULL) {
        printf("Row: %d, Col: %d, Data: %d\n", temp->row, temp->col, temp->data);
        temp = temp->next;
    }
}

int main() {
    int s;
    printf("Enter the number of non zero elemnts: ");
    scanf("%d", &s);
    struct node *head = create_sparse_matrix(s);
    display(head);
    return 0;
}
