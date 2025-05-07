#include <stdio.h>
#include <stdlib.h>

#define newnode (struct node *)malloc(sizeof(struct node))

struct node
{
     struct node *prev;
    int data;
    struct node *next;
};

struct node *create(struct node *H, int n)
{
    struct node *s;
    int i;
    H = newnode;
    printf("Enter data: ");
    scanf("%d", &H->data);
    H->next = H;
    H->prev = H;
    s = H;
    for (i = 1; i < n; i++)
    {
      
         s->next = newnode ; 
         s->next->prev=s ;
         s=s->next; 
         printf("Enter data: ");
         scanf("%d", &s->data);
         s->next=H ; 
         H->prev=s ;
    }
    return H;
}

void display(struct node *H)
{
    struct node *s ;
    s= H;
    printf("Linked list: ");
    do
    {
        printf("%d ", s->data);
        s = s->next;
    } while (s != H);
    printf("\n");
}



int length(struct node *H)
{
    struct node *s = H;
    int l = 0;
    do
    {
        l++;
        s = s->next;
    } while (s != H);
    return l;
}


void revdisplay(struct node *H) {
 
 struct node *s = H->prev; 
 printf("Reversed Linked list: ");
 
 struct node *t = s; 
 do {
     printf("%d ", s->data);
     s = s->prev;
 } while (s != t);  
 
 printf("\n");
}


struct node *insert(struct node *H, int x, int pos)
{
    struct node *t;
    t=newnode;
    t->data = x;
    int l = length(H);
    struct node *s = H;
    if (pos == 1)
    {
        t->next = H;
        t->prev = H->prev;
        H->prev->next = t;
        H->prev = t;
        H = t;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
            s = s->next;
        t->next = s->next;
        t->prev = s;
        s->next->prev = t;
        s->next = t;
    }
    return H;
}

struct node *deleteNode(struct node *H, int pos)
{

    struct node *s = H;
    int l = length(H);
     int i ; 
    if (pos == 1)
    {
        if (H->next == H)
        {
            free(H);
            return NULL;
        }
        H->prev->next = H->next;
        H->next->prev = H->prev;
        struct node *t = H;
        H = H->next;
        free(t);
    }
    else
    {
        for (int i = 1; i < pos; i++)
            s = s->next;
        s->prev->next = s->next;
        s->next->prev = s->prev;
        free(s);
    }
    return H;
}

struct node *erase(struct node *H)
{
    struct node *s = H->next;
    while (s != H)
    {
        struct node *t = s;
        s = s->next;
        free(t);
    }
    free(H);
    return NULL;
}

int main()
{
    int n, l, x, pos, ch;
    struct node *H = NULL;
    while (1)
    {
            printf("Menu\n");
            printf("1. Create\n");
            printf("2. reverse output\n");
            printf("3. Display\n");
            printf("4. Length\n");
            printf("5. Insert\n");
            printf("6. Delete\n");
            printf("7. Erase\n");
            printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("How many nodes in list: ");
            scanf("%d", &n);
            H = create(H, n);
            break;
             case 2:
               revdisplay(H);
            break;
        case 3:
            display(H);
            break;
        case 4:
            l = length(H);
            printf("Length of list: %d\n", l);
            break;
        case 5:
            printf("Enter the position to insert the data: ");
            scanf("%d", &pos);
            l = length(H);
            if (pos < 1 || pos > l + 1)
            {
                printf("Invalid Position!\n");
            }
            else
            {
                printf("Enter data: ");
                scanf("%d", &x);
                H = insert(H, x, pos);
            }
            break;
        case 6:
            printf("Enter position to delete data: ");
            scanf("%d", &pos);
            l = length(H);
            if (pos < 1 || pos > l)
            {
                printf("Invalid Position!\n");
            }
            else
            {
                H = deleteNode(H, pos);
            }
            break;
        case 7:
            H = erase(H);
            printf("Linked list erased.\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Enter correct choice!\n");
        }
    }
    return 0;
}

