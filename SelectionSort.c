#include <stdio.h>
#define MAX 100
#define STOP getchar()

void selectionSort(int arr[], int n);
void displayArray(int arr[], int n);

int main()
{
    int arr[MAX], i, n;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display unsorted list
    printf("Unsorted list is: \n");
    displayArray(arr, n);

    // Perform selection sort
    selectionSort(arr, n);

    // Display sorted list
    printf("\nSorted list is: ");
    displayArray(arr, n);
    printf("\n");

    return 0;
}

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
    int i, j, k, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        printf("\nPASS %d - \n", i + 1);
        printf("Elements are: ");
        displayArray(arr, n);

        // Find the index of the smallest element
        printf("\nFind the smallest element from { ");
        for(k = i; k < n; k++)
            printf("%d ", arr[k]);
        printf("}\n");

        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }

        printf("Smallest element is %d and its index is %d\n", arr[min], min);

        // Swap the found smallest element with the first element of the unsorted part
        if(i != min)
        {
            printf("Exchange arr[%d] = %d and arr[%d] = %d\n", i, arr[i], min, arr[min]);
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        else
        {
            printf("%d is already at its proper place, no exchange needed\n", arr[i]);
        }

        printf("After Pass %d, elements are: ", i + 1);
        displayArray(arr, n);
        printf("\n");

        STOP;  // Wait for user input to proceed
    }
}

// Function to display the array
void displayArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
