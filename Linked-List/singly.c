
#include <stdio.h>
#include <stdlib.h>

#define newnode (struct node *)malloc(sizeof(struct node))

struct node
{
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
 H->next = NULL;
 s = H;
 for (i = 1; i < n; i++)
 {
  s->next = newnode;
  s = s->next;
  printf("Enter data: ");
  scanf("%d", &s->data);
 }
 s->next = NULL;
 return H;
}

void display(struct node *H)
{
 struct node *s = H;
 printf("Linked list: ");
 while (s != NULL)
 {
  printf("%d ", s->data);
  s = s->next;
 }
 printf("\n");
}

int length(struct node *H)
{
 struct node *s = H;
 int l = 0;
 while (s != NULL)
 {
  l++;
  s = s->next;
 }
 return l;
}

struct node *insert(struct node *H, int x, int pos)
{
 int i;
 struct node *s, *t;
 t = newnode;
 t->data = x;
 t->next = NULL;
 s = H;
 if (pos == 1)
 {
  t->next = H;
  H = t;
 }
 else
 {
  for (i = 1; i < pos - 1; i++)
  {
   s = s->next;
  }
  t->next = s->next;
  s->next = t;
 }
 return H;
}

struct node *deleteNode(struct node *H, int pos)
{
 struct node *s, *t;
 int i;
 s = H;
 if (pos == 1)
 {
  H = H->next;
  free(s);
 }
 else
 {
  for (i = 1; i < pos - 1; i++)
  {
   s = s->next;
  }
  t = s->next;
  s->next = t->next;
  free(t);
 }
 return H;
}

struct node *erase(struct node *H)
{
 struct node *s;
 while (H!= NULL)
 {
  s = H;
  H = H->next;
  free(s);
 }
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
  printf("2. Display\n");
  printf("3. Length\n");
  printf("4. Insert\n");
  printf("5. Delete\n");
  printf("6. Erase\n");
  printf("7. Exit\n");
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
   display(H);
   break;
  case 3:
   l = length(H);
   printf("Length of list: %d\n", l);
   break;
  case 4:
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
  case 5:
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
  case 6:
   H = erase(H);
   printf("Linked list erased.\n");
   break;
  case 7:
   exit(0);
  default:
   printf("Enter correct choice!\n");
  }
 }
 return 0;
}
