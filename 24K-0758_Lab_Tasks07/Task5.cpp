#include<iostream>
#include<cstdlib>
using namespace std;

int comparisons = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionFunc(int A[], int left, int right, int pivotIndex) {
    int pivot = A[pivotIndex];
    swap(A[pivotIndex], A[right]);
    int i = left - 1;
    for(int j = left; j < right; j++) {
        comparisons++;
        if(A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[right]);
    return i + 1;
}

int firstPivot(int left) {
    return left;
}

int randomPivot(int left, int right) {
    return left + rand() % (right - left + 1);
}

int middlePivot(int left, int right) {
    return (left + right) / 2;
}

int medianOfThreePivot(int A[], int left, int right) {
    int mid = (left + right) / 2;
    int a = A[left], b = A[mid], c = A[right];
    if((a > b) != (a > c)) return left;
    else if((b > a) != (b > c)) return mid;
    else return right;
}

void quickSort(int A[], int left, int right, int pivotType) {
    if(left < right) {
        int pivotIndex;
        if(pivotType == 1)
            pivotIndex = firstPivot(left);
        else if(pivotType == 2)
            pivotIndex = randomPivot(left, right);
        else if(pivotType == 3)
            pivotIndex = middlePivot(left, right);
        else
            pivotIndex = medianOfThreePivot(A, left, right);
        int pi = partitionFunc(A, left, right, pivotIndex);
        quickSort(A, left, pi - 1, pivotType);
        quickSort(A, pi + 1, right, pivotType);
    }
}

void copyArray(int src[], int dest[], int n) {
    for(int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int arr[] = {9, 4, 8, 3, 1, 2, 5, 7, 6};
    int n = 9;
    int temp[9];

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 1);
    cout << "First Element Pivot Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 2);
    cout << "Random Pivot Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 3);
    cout << "Middle Element Pivot Comparisons: " << comparisons << endl;

    copyArray(arr, temp, n);
    comparisons = 0;
    quickSort(temp, 0, n - 1, 4);
    cout << "Median of Three Pivot Comparisons: " << comparisons << endl;

    return 0;
}
