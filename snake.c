#include <stdio.h>
#include <stdlib.h>

struct snake{
    int xprev;
    int yprev;
    int x;
    int y;
    struct snake *next;
};

struct snake* create_snake(int length){
    struct snake *snake = malloc(length * sizeof(struct snake));
    struct snake *head = (snake + 0);

    int i;

    for(i = 1; i < length; i++){
        head -> next = (snake+i);
        head -> x = i;
        head -> y = i;
        head -> xprev = i;
        head -> yprev = i;
        head = head -> next;
        //printf("ran"); 
    }
    printf("\n");

    (snake+i-1) -> next = NULL;
    (snake+i-1) -> x = i;
    (snake+i-1) -> y = i;

    return (snake+0);
}

void snake_shift(struct snake *head){
    struct snake *temp = head;
    while (temp != NULL){
        if(temp->next != NULL){
        temp -> next -> xprev = temp -> next -> x;
        temp -> next -> yprev = temp -> next -> y; 
        temp -> next -> x = temp -> xprev;
        temp -> next -> y = temp -> yprev;
        }
        temp = temp -> next;
    }
}

void add_snake(struct snake *head, int x, int y){
    struct snake *new_block = malloc(sizeof(struct snake));
    new_block -> next = head -> next;
    head -> next = new_block;
    new_block -> x = x;
    new_block -> y = y;
    new_block -> xprev = x;
    new_block -> yprev = y; 
}

void print_snake(struct snake *head){
    struct snake *temp = head;
    while (temp != NULL){
        printf("x: %i y: %i \n", temp->x, temp->y);
        temp = temp -> next;
    }

}


int main(){
    int length = 5;
    struct snake *head = create_snake(length);
    print_snake(head);
    add_snake(head, 6, 6);
    print_snake(head);
    snake_shift(head);
    print_snake(head);
}
