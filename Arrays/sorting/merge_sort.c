#include <stdio.h>

void accept(int a[10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[10], int lb, int mid, int ub) {
    int b[10], i, j, n1, n2, k;
    i = lb;
    j = mid + 1;
    k = lb;
    n1 = mid;
    n2 = ub;

    while (i <= n1 && j <= n2) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            j++;
            k++;
        }
        
    }

    while (i <= n1) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= n2) {
        b[k] = a[j];
        j++;
        k++;
    }

    k = 0;
    for (i = lb; i <= ub; i++) {
        a[i] = b[i];
    }
}

void mergesort(int a[10], int lb, int ub) {
    int mid;
    if (lb < ub) {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int a[10], n;
    printf("How many elements do you want in the array? ");
    scanf("%d", &n);
    accept(a, n);
    
    printf("Unsorted elements: ");
    display(a, n);
    
    mergesort(a, 0, n - 1);
    
    printf("Sorted elements: ");
    display(a, n);
    
    return 0;
}
