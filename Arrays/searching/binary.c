
#include <stdio.h>


void accept(int a[10], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}


void display(int a[10], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void bsort(int a[10], int n) {
    int t, i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - (i + 1); j++) {
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}


int bsearch(int a[10], int x, int lb, int ub) {
    int mid;
    if (lb <= ub) {
        mid = (lb + ub) / 2;

        if (x == a[mid]) {
            return mid;
        }  else{
        
        
        if (x > a[mid]) {
            return bsearch(a, x, mid + 1, ub);
        } else {
            return bsearch(a, x, lb, mid - 1);
        }
        
    }
    }
    return -1;
}


int main() {
    int a[10], n, x, p;

    printf("How many elements you want in the array? (Max 10): ");
    scanf("%d", &n);

    accept(a, n);
    bsort(a, n);
    display(a, n);

    printf("Enter value for searching: ");
    scanf("%d", &x);

    p = bsearch(a, x, 0, n - 1);

    if (p == -1) {
        printf("%d is not found in the array\n", x);
    } else {
        printf("%d is found at a[%d] position\n", x, p);
    }

    return 0;
}
