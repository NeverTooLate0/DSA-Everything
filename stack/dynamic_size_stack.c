#include<stdio.h>
#include<stdlib.h>
#define newnode (struct node *)malloc(sizeof(struct node))
struct node
{
    int data;
    struct node *next;
};
struct node *top,*H;
void init()
{
    H=top=NULL;
}
int is_empty()
{
    return (H==NULL)?1:0;
}
void push(int data)
{
    struct node *s;
    s = newnode;
    if(s!=NULL)
    {
        s->data =data;
        s->next = NULL;
        if(H==NULL)
        {
            H=top=s;
            top=s;
        }
        else
        {
            top->next = s;
            top =s;
        }
    }
    else
    {
        printf("Stack is full!!!\n");
    }
}
int pop()
{
    int data;
    struct node *s=H;
    if(top!=H)
    {
        while(s->next!=top)
        {
            s=s->next;
        }
    }
    data = top->data;
    s->next = NULL;
    if(H==top)
        H=s=NULL;
    free(top);
    top=s;
    return data;
}
int main()
{
    int ch,data;
    init();
    while(1)
    {
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty?\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data: ");
                    scanf("%d",&data);
                    push(data);
                    break;
            case 2: if(!is_empty())
                    {
                        data = pop();
                        printf("Data: %d\n",data);
                    }
                    else
                    {
                        printf("Stack is Empty!!!\n");
                    }
                    break;
            case 3: if(is_empty())
                    {
                        printf("Stack is empty!!!\n");
                    }
                    else
                    {
                        printf("Stack is not empty!!!\n");
                    }
                    break;
            case 4: exit(0);
            default: printf("Enter correct choice!\n");
        }
    }
}
