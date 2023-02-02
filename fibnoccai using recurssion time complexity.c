#include<stdio.h>

int main() {
  int a = 0; 
  int b = 1; 
  int i, result;
  int n = 5;

  printf("The fibonacci series is :\n");

  for (i = 0; i < n; i++) {
    printf("%d ", a);
    result = a + b;
    a = b;
    b = result;
  }
}

