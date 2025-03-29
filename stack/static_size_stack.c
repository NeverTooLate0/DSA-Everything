#include <stdio.h>
#include <stdlib.h>

#define max 5  

int top, bottom, stack[max];

void init() {
    top = -1;     
    bottom = -1;   
}

int is_empty() {
    return (top == bottom) ? 1 : 0;
}

int is_full() {
    return (top == max - 1) ? 1 : 0;
}

void push(int data) {
    
        stack[++top] = data;
}

int pop() {
   
        return stack[top--];
      
}

int peep() {
   
        return top ;
    
    }
/*int peep() {
    if (!is_empty()) {
        return stack[top]; // Returning the top element instead of the index
    } else {
        printf("Stack is empty!\n");
        return -1;
    }*/

int main() {
    int ch, data;
    init();
    while (1) {
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Full?\n");
        printf("4. Is Empty?\n");
        printf("5. Peep\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                if (!is_full()) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    push(data);
                } else {
                    printf("Stack is full!!!\n");
                }
                break;

            case 2:
                if (!is_empty()) {
                    data = pop();
                    printf("Data: %d\n", data);
                } else {
                    printf("Stack is Empty!!!\n");
                }
                break;

            case 3:
                if (is_full()) {
                    printf("Stack is full!!!\n");
                } else {
                    printf("Stack is not full!!!\n");
                }
                break;

            case 4:
                if (is_empty()) {
                    printf("Stack is empty!!!\n");
                } else {
                    printf("Stack is not empty!!!\n");
                }
                break;

            case 5:
                data = peep();
                if (data != -1) {
                    printf("Top element is %d\n", data);
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Enter correct choice!\n");
        }
    }
}
