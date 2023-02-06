#include <stdio.h>

void get_factors(int n) {
    printf("Factors of %d: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    get_factors(n);
    return 0;
}

