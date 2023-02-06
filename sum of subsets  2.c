#include <stdio.h>
#define MAX 10
int w[MAX], x[MAX];
int n, W, total = 0;
void print_solution() {
    printf("Selected items: ");
    for (int i = 0; i < n; i++)
        if (x[i]) printf("%d ", w[i]);
    printf("\n");
}
void sum_of_subsets(int s, int k, int r) {
    x[k] = 1;
    if (s + w[k] == W) {
        print_solution();
    }
    else if (s + w[k] + w[k+1] <= W) {
        sum_of_subsets(s + w[k], k+1, r-w[k]);
    }
    if ((s + r - w[k] >= W) && (s + w[k+1] <= W)) {
        x[k] = 0;
        sum_of_subsets(s, k+1, r-w[k]);
    }
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of each item: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("Enter the maximum weight: ");
    scanf("%d", &W);
    sum_of_subsets(0, 0, total);
    return 0;
}

