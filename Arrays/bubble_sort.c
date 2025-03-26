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

void b_sort(int a[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {  // Swap if needed
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
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

    b_sort(a, n);
    printf("Sorted elements: ");
    display(a, n);

    return 0;
}
