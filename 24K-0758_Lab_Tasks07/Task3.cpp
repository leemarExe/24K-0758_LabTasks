#include<iostream>
using namespace std;

struct Product {
    string name;
    double price;
    string description;
    string availability;
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partitionFunc(Product A[], int left, int right, double pivot) {
    int leftPointer = left - 1;
    int rightPointer = right;
    while(true) {
        while(A[++leftPointer].price < pivot) {}
        while(rightPointer > 0 && A[--rightPointer].price > pivot) {}
        if(leftPointer >= rightPointer)
            break;
        else
            swap(A[leftPointer], A[rightPointer]);
    }
    swap(A[leftPointer], A[right]);
    return leftPointer;
}

void quickSort(Product A[], int left, int right) {
    if(left >= right)
        return;
    double pivot = A[right].price;
    int partitionPoint = partitionFunc(A, left, right, pivot);
    quickSort(A, left, partitionPoint - 1);
    quickSort(A, partitionPoint + 1, right);
}

int main() {
    Product arr[3];

    arr[0].name = "Laptop";
    arr[0].price = 95000;
    arr[0].description = "Gaming Laptop";
    arr[0].availability = "In Stock";

    arr[1].name = "Headphones";
    arr[1].price = 5500;
    arr[1].description = "Wireless Headphones";
    arr[1].availability = "In Stock";

    arr[2].name = "Smartwatch";
    arr[2].price = 22000;
    arr[2].description = "Fitness Smartwatch";
    arr[2].availability = "Out of Stock";

    quickSort(arr, 0, 2);

    for(int i = 0; i < 3; i++) {
        cout << arr[i].name << " - " << arr[i].price << " - " 
             << arr[i].description << " - " << arr[i].availability << endl;
    }

    return 0;
}
