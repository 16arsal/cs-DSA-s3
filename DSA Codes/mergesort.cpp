#include <iostream>

using namespace std;

// Function to merge two sorted subarrays into a single sorted array
void merge(int array[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// Function to implement the merge sort algorithm
void mergeSort(int array[], int left, int right)
{
    if (left >= right)
    {
        return; // Base case: the array is already sorted if it has 0 or 1 elements
    }

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// Function to print an array
void printArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array is: ";
    printArray(arr, size);

    return 0;
}