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
 s->next = H; // first change
 return H;
}

void display(struct node *H)
{
 struct node *s = H;
 printf("Linked list: ");
 do // from while to do while
 {
  printf("%d ", s->data);
  s = s->next;
 } while (s != H); // from null to H ;
}

int length(struct node *H)
{
 struct node *s = H;
 int l = 0;
 do // from while to do while
 {
  l++;
  s = s->next;
 } while (s != H);
 return l;
}

struct node *insert(struct node *H, int x, int pos)
{

 struct node *s, *t;
 int i, l;
 l = length(H);

 t = newnode;
 t->data = x;
 s = H;

 if (pos == 1 || pos == l + 1)
 {
  for (i = 1; i < l; i++)
  {
   s = s->next;
  }
  t->next = H;
  s->next = t;
  if (pos == 1)
  {
   H = t;
  }
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
 int i, l;
 l = length(H);
 s = H;

 if (pos == 1)
 {
  for (i = 1; i < l; i++)
  {
   s = s->next;
  }

  t = H;
  H = H->next;
  free(t);
  s->next = H;
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
 struct node *s, *t;
 s = H->next;

 while (s != H)
 {
  t = s;
  s = s->next;
  free(t);
 }
 free(H);
 return NULL; // or retrun H ; both would work .
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
