#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** data;
    int rows, cols;

    void allocate(int r, int c) {
        data = new int*[r];
        for (int i = 0; i < r; i++) {
            data[i] = new int[c]{};
        }
    }

    void deallocate() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    DynamicMatrix(int r, int c) : rows(r), cols(c) {
        allocate(rows, cols);
    }

    ~DynamicMatrix() {
        deallocate();
    }

    void resize(int newRows, int newCols, int fillValue = 0) {
        int** newData = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newData[i] = new int[newCols];
        }

        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newData[i][j] = data[i][j];
                } else {
                    newData[i][j] = fillValue;
                }
            }
        }

        deallocate();

        data = newData;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** newData = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newData[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                newData[j][i] = data[i][j];
            }
        }

        deallocate();

        data = newData;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = i * cols + j;
                if (idx % 2 == 1) {
                    cout << data[i][j] + 2 << " ";
                } else {
                    cout << data[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }
};

int main() {
    DynamicMatrix mat(3, 3);

    int val = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            mat.set(i, j, val++);

    cout << "Original matrix:" << endl;
    mat.print();

    mat.resize(4, 5, 0);
    cout << "\nAfter resize to 4x5 with fill 0:" << endl;
    mat.print();

    mat.transpose();
    cout << "\nAfter transpose:" << endl;
    mat.print();

    return 0;
}
