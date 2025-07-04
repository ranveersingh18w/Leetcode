#include <stdio.h>
#include <stdlib.h>

// You must declare the function before main so that main knows about it.
int* suming(int a[], int target, int size);

int main() {
    int elements;

    printf("How many elemts: ");
    scanf("%d", &elements);
    printf("Enter the %d elemetns\n", elements);

    int a[elements], value, target;

    for (int i = 0; i < elements; i++) {
        printf("Enter the value %d: ", i + 1);
        scanf("%d", &value);
        a[i] = value;
    }

    printf("Enter the target: ");
    scanf("%d", &target);

    int arrsize = sizeof(a) / sizeof(a[0]);
    // The line below is now removed from here.
    // printf("size is %d", arrsize);

    // This line calls the function and gets a memory address (or NULL)
    int* fun = suming(a, target, arrsize);

    // ALWAYS check if the pointer is valid before using it!
    if (fun != NULL) {
        // This is the correct line that prints the two numbers
        printf("Pair found: %d and %d\n", fun[0], fun[1]);
    } else {
        // Handle the case where no pair was found
        printf("No pair was found that sums to the target.\n");
    }
    
    // The return statement now correctly sits at the end of the program.
    return 0;
}

int* suming(int a[], int target, int size) {
    static int array[2];
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] + a[j] == target) {
                array[0] = i;
                array[1] = j;
                return array;
            }
        }
    }
    return NULL;
}