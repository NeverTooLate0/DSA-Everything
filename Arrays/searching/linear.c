#include <stdio.h>

void accept(int a[10], int n)
{
 int i;
 for (i = 0; i < n; i++)
 {
  printf("Enter a[%d]: ", i);
  scanf("%d", &a[i]);
 }
}

int lsearch(int a[10], int n, int x)
{
 int i;
 for (i = 0; i < n; i++)
 {
  if (a[i] == x)
  {
   return i;
  }
 }
 return n;
}

int main()
{
 int a[10], n, i, x, p;

 printf("How many elements you want in array?: ");
 scanf("%d", &n);

 accept(a, n);

 printf("Enter value for searching: ");
 scanf("%d", &x);

 p = lsearch(a, n, x);

 if (p == n)
 {
  printf("%d is not found in an array\n", x);
 }
 else
 {
  printf("%d is found at a[%d] position\n", x, p);
 }

 return 0;
}
