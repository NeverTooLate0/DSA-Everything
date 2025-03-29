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

void display(int a[10], int n)
{
 int i;
 for (i = 0; i < n; i++)
 {
  printf("%d ", a[i]);
 }
 printf("\n");
}

int partition(int a[10], int lb, int ub)
{
 int p, i, j, t;
 p = a[lb];
 i = lb + 1;
 j = ub;

 while (i <= j)
 {
  while (p >= a[i] && i <= ub)
  {
   i++;
  }
  while (p < a[j] && j >= lb)
  {
   j--;
  }
  if (i < j)
  {
   t = a[i];
   a[i] = a[j];
   a[j] = t;
  }
 }

 a[lb] = a[j];
 a[j] = p;
 return j;
}

void quicksort(int a[10], int lb, int ub)
{
 int j;
 if (lb < ub)
 {
  j = partition(a, lb, ub);
  quicksort(a, lb, j - 1);
  quicksort(a, j + 1, ub);
 }
}

int main()
{
 int a[10], n;

 printf("How many elements you want in array?: ");
 scanf("%d", &n);

 accept(a, n);

 printf("Unsorted elements: ");
 display(a, n);

 quicksort(a, 0, n - 1);

 printf("Sorted elements: ");
 display(a, n);

 return 0;
}
