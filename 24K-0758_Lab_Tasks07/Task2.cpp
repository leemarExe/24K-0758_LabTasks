#include<iostream>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner leftArr[10], rightArr[10];

    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(leftArr[i].time <= rightArr[j].time) {
            arr[k] = leftArr[i];
            i = i + 1;
        }
        else {
            arr[k] = rightArr[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < n1) {
        arr[k] = leftArr[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < n2) {
        arr[k] = rightArr[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(Runner arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Runner runners[10] = {
        {"Ali", 375}, {"Sara", 420}, {"Hassan", 355},
        {"Aisha", 500}, {"Bilal", 390}, {"Omar", 340},
        {"Fatima", 460}, {"Zain", 310}, {"Usman", 330},
        {"Hira", 370}
    };

    mergeSort(runners, 0, 9);

    cout << "Top 5 Fastest Runners:" << endl;
    for(int i = 0; i < 5; i++)
        cout << runners[i].name << " - " << runners[i].time << "s" << endl;

    return 0;
}
