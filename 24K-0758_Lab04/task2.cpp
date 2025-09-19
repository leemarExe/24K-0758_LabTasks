#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int selectionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    return comparisons;
}

int shellSort(int arr[], int n) {
    int comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else break;
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}

int main() {
    srand(time(0));

    int n1 = 20, n2 = 100;
    int arr1[20], arr2[100];

    for (int i = 0; i < n1; i++) arr1[i] = rand() % 100 + 1;
    for (int i = 0; i < n2; i++) arr2[i] = rand() % 100 + 1;

    cout << "Original 20 elements: ";
    printArray(arr1, n1);

    int temp[100];

    copyArray(arr1, temp, n1);
    cout << "\nBubble Sort (20 elements):\n";
    cout << "Comparisons: " << bubbleSort(temp, n1) << endl;
    printArray(temp, n1);

    copyArray(arr1, temp, n1);
    cout << "\nInsertion Sort (20 elements):\n";
    cout << "Comparisons: " << insertionSort(temp, n1) << endl;
    printArray(temp, n1);

    copyArray(arr1, temp, n1);
    cout << "\nSelection Sort (20 elements):\n";
    cout << "Comparisons: " << selectionSort(temp, n1) << endl;
    printArray(temp, n1);

    copyArray(arr1, temp, n1);
    cout << "\nShell Sort (20 elements):\n";
    cout << "Comparisons: " << shellSort(temp, n1) << endl;
    printArray(temp, n1);

    copyArray(arr2, temp, n2);
    cout << "\nBubble Sort (100 elements):\n";
    cout << "Comparisons: " << bubbleSort(temp, n2) << endl;

    copyArray(arr2, temp, n2);
    cout << "\nInsertion Sort (100 elements):\n";
    cout << "Comparisons: " << insertionSort(temp, n2) << endl;

    copyArray(arr2, temp, n2);
    cout << "\nSelection Sort (100 elements):\n";
    cout << "Comparisons: " << selectionSort(temp, n2) << endl;

    copyArray(arr2, temp, n2);
    cout << "\nShell Sort (100 elements):\n";
    cout << "Comparisons: " << shellSort(temp, n2) << endl;

    return 0;
}
