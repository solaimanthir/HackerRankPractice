#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[101] = {0};
    int N;
    int k;
    int i;
    scanf("%d", &N);
    scanf("%s", str);
    scanf("%d", &k);
    
    for(i = 0; i < N; ++i) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            int rem = k%26;
            if(((str[i]-'a') + rem) >= 26)
                str[i] = (((str[i]-'a') + rem)%26)+'a';
            else
                str[i] = ((str[i]-'a') + rem)+'a';
        }
        if(str[i] >= 'A' && str[i] <= 'Z') {
            int rem = k%26;
            if(((str[i]-'A') + rem) >= 26)
                str[i] = (((str[i]-'A') + rem)%26)+'A';
            else
                str[i] = ((str[i]-'A') + rem)+'A';
        }
    }
    printf("%s", str);
    return 0;
}
