#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef unsigned long long int ull;

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ull r, c;
    scanf("%llu%llu", &r, &c);
    if(r&1)
        printf("%llu", 5*(r-1)+((c-1)*2));
    else
        printf("%llu", 5*(r-2)+1+((c-1)*2));
    return 0;
}
