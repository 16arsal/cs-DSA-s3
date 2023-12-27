#include <iostream>

void merge(int arr[], int left, int mid, int right) {
	

    int n1 = mid - left + 1;//creating sizes 
    int n2 = right - mid;//creating sizes

    // Create temporary arrays
    int leftArray[n1];
    int rightArray[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left...right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        int mid = (left + right ) / 2;
        
        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    std::cout<<arrSize<<std::endl;

    std::cout << "Original array: ";
    for (int i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Perform merge sort
    mergeSort(arr, 0, arrSize - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

