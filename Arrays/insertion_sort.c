#include <stdio.h>

void accept(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

void i_sort(int arr[], int n) {  
    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  
    }
}

int main() {
    int a[10], n;
    
    printf("How many elements do you want in the array? (Max 10): ");
    scanf("%d", &n);
    

    accept(a, n);
    
    printf("Unsorted elements:\n");
    display(a, n);
    
    i_sort(a, n); 
    
    printf("Sorted elements:\n");
    display(a, n);

    return 0;
}
