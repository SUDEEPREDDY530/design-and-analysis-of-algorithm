#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

// Returns the minimum value in int array a[] of size n
int minValue(int a[], int n) {
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
        if (a[i] < minimum)
            minimum = a[i];
    return minimum;
}

// Returns the minimum value in int array a[] of size n
int maxValue(int a[], int n) {
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
        if (a[i] > maximum)
            maximum = a[i];
    return maximum;
}

// Returns the index of the first element in row[] that is 0
int firstZero(int row[N]) {
    for (int i = 0; i < N; i++)
        if (row[i] == 0)
            return i;
    return -1;
}

// If there is an augmenting path, returns true and sets the values of row[] and col[]
bool augmentPath(int cost[N][N], int row[N], int col[N], int z[N]) {
    int l[N];
    for (int i = 0; i < N; i++) {
        row[i] = col[i] = -1;
        l[i] = INT_MAX;
    }
    int j0 = -1;
    for (int i = 0; i < N; i++) {
        int min = INT_MAX;
        int j = -1;
        for (int k = 0; k < N; k++)
            if (col[k] == -1)
                if (cost[i][k] - z[i] - z[k] < min) {
                    j = k;
                    min = cost[i][k] - z[i] - z[k];
                }
        if (col[j] == -1) {
            col[j] = i;
            row[i] = j;
            if (j0 == -1 || l[j] < l[j0])
                j0 = j;
        }
        else {
            int i1 = col[j];
            col[j] = -1;
            for (int k = 0; k < N; k++)
                if (col[k] == i1) {
                    if (l[k] > cost[i][k] - z[i] - z[k]) {
                        l[k] = cost[i][k] - z[i] - z[k];
                        row[k] = i;
                        col[k] = -1;
                    }
                }
            for (int k = 0; k < N; k++) {
                if (row[k] == -1)
                    z[k] += l[k] - minValue(l, N);
                if (row[k] != -1)
                    z[k] -= minValue(l, N);
            }
            i--;

