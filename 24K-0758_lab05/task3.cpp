#include <iostream>
using namespace std;

#define N 7

int maze[N][N] = {
    {1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1}
};

int sol[N][N] = {0};
int visited[N][N] = {0};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

bool solveMazeUtil(int x, int y) {
    cout << "Visiting: (" << x << "," << y << ")\n";
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        visited[x][y] = 1;
        sol[x][y] = 1;

        if (solveMazeUtil(x + 1, y)) return true;
        if (solveMazeUtil(x, y + 1)) return true;
        if (solveMazeUtil(x - 1, y)) return true;
        if (solveMazeUtil(x, y - 1)) return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

void solveMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    if (!solveMazeUtil(0, 0)) {
        cout << "No solution exists\n";
        return;
    }

    printSolution();
}

int main() {
    solveMaze();
    return 0;
}
