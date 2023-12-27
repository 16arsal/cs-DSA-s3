#include <iostream>
using namespace std;

// Function to merge two subarrays into a single sorted array
void merge(int array[], int const left, int const mid, int const right)
{
    // Calculate the sizes of the two subarrays to be merged
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temporary arrays for the subarrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temporary arrays
    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    // Variables to track the current index of each subarray and the merged array
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temporary arrays back into the original array
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of the left subarray, if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of the right subarray, if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    // Deallocate the memory used for the temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Function to implement the merge sort algorithm
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
    {
        return; // Base case: the array is already sorted if it has 0 or 1 elements
    }

    // Calculate the middle point of the array
    int mid = begin + (end - begin) / 2;
    // Recursively sort the two halves of the array
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    // Merge the sorted halves
    merge(array, begin, mid, end);
}

// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Initialize the array to be sorted
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Given array is \n";
    printArray(arr, arr_size);

    // Sort the array using merge sort
    mergeSort(arr, 0, arr_size - 1);

    // Print the sorted array
    cout << "\nSorted Array is \n";
    printArray(arr, arr_size);

    return 0;
}