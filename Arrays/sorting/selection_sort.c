
#include <stdio.h>

void accept(int a[], int n) {
    int i; 
    for (i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);  
    }
    printf("\n");
}

void s_sort(int a[], int n) {
    int i, j, minIndex, t;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {  // Find the minimum element
                minIndex = j;
            }
        }
        // Swap only if a new minimum is found
            t = a[minIndex];
            a[minIndex] = a[i];
            a[i] = t;
        }
    }
}

int main() {
    int a[10], n; 
    printf("How many elements you want in the array? (Max 10): ");
    scanf("%d", &n);

    accept(a, n);
    printf("Unsorted elements: ");
    display(a, n);

    s_sort(a, n);
    printf("Sorted elements: ");
    display(a, n);

    return 0;
}
