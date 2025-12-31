#include <stdio.h>

// Function to swap using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr;

    // Swap two numbers
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap: x=%d, y=%d\n", x, y);

    // Print addresses and values
    printf("\nAddress of x: %p, Value: %d\n", (void*)&x, x);
    printf("Address of y: %p, Value: %d\n", (void*)&y, y);

    // Traverse array using pointers (no indexing)
    printf("\nArray elements using pointers:\n");
    ptr = arr;  // point to first element
    for (int i = 0; i < 5; i++) {
        printf("Address: %p, Value: %d\n", (void*)(ptr + i), *(ptr + i));
    }

    return 0; // good practice to return 0
}
