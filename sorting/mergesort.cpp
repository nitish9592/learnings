#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    // Remaining elements
    while (left <= mid) {
        temp.push_back(arr[left++]);
    }
    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive merge sort
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);        // Sort left half
    mergeSort(arr, mid + 1, high);   // Sort right half
    merge(arr, low, mid, high);      // Merge both halves
}

int main() {
    vector<int> arr = {5, 2, 4, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr)
        cout << num << " ";
    return 0;
}
