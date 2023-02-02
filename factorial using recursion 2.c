#include <stdio.h>
int main()
{
int x = 7;
printf("The factorial of the number is %d", fact(x));
return 0;
}
int fact(int y){
if (y == 0)
return 1;
return y * fact(y - 1);

}
