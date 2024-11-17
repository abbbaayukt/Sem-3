#include<stdio.h>
#include<stdlib.h>

struct node{
    int row;
    int col;
    int data;
    struct node* next;
}
struct node *create_node(){
    struct node *temp = (struct node*)malloc(sizeof (struct node));
    printf("\nEnter the row : ");
    scanf("%d",temp->row);
    printf("\nEnter the column : ");
    scanf("%d",temp->col);
    printf("\nEnter the value : ");
    scanf("%d",temp->data);
    temp->next = NULL;
    return temp;
};
struct node *createll(int n){
    struct node *head = create_node();
    struct node *h1 = head;
    for(int i = 1;i<n;i++){
        struct node *temp = create_node();
        while (h1->next->next != NULL){
            while((h1->next->row<temp->row)&&(h1->next ==NULL)){
                h1 = h1->next;
            }
            if(h1->next->row>temp->row){
                temp->next = h1->next;
                h1->next = temp;
            }
            else{
                 while((h1->next->col<temp->col)&&(h1->next->row==temp->row)){
                    h1 = h1->next;
                 }
                 if(h1->col==temp->col){
                    h1->data= h1->data + temp->data;
                 }
                 else{
                    temp->next = h1->next;
                    h1->next = temp;
                 }
            }
            while((h1->next->col<temp->col)&&(h1->next->row==temp->row)){
                    h1 = h1->next;
                 }
                 if(h1->col==temp->col){
                    h1->data= h1->data + temp->data;
                 }
                 else{
                    temp->next = h1->next;
                    h1->next = temp;
                 }
        }
    }


}