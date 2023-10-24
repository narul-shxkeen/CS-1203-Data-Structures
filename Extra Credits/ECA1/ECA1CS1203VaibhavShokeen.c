#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;   
    *a = *b;       
    *b = temp;      
}

//print an array of integers
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1 ? "\n" : ","));
    }
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);  // Input the integer n

    // Ensure the input is less than 9, since it is too large to calculate permutations(3,62,880) and device will crash..
    if (n < 1 || n > 8) {
        printf("Please enter an integer between 1 and 8.");
        return 0;  // Exit the program
    }

    // Creating array with numbers from 1 to 'n'
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Generate and print all permutations
    while (1) {
        printArray(arr, n);  // Call the printArray function to print the current permutation

        int i = n - 1;
        while (i > 0 && arr[i - 1] >= arr[i]) {
            i--;  // Finding largest index 'i' such that arr[i-1] < arr[i]
        }

        if (i <= 0) {
            break;  // exit the loop if no such i is found, that means are permutations have been printed.
        }

        int j = n - 1;
        while (arr[j] <= arr[i - 1]) {
            j--;  // Finding the largest index 'j' such that arr[j] > arr[i-1]
        }

        swap(&arr[i - 1], &arr[j]);  // Swaping arr[i-1] and arr[j] to create the next permutation

        j = n - 1;
        while (i < j) {
            swap(&arr[i], &arr[j]);  // Reversing the elements from arr[i] to arr[j] to complete the permutation.
            i++;
            j--;
        }
    }

    return 0;
}
