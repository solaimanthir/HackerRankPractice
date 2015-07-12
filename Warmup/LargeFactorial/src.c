#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int *multiplicand = NULL;
    int i, N, f_len;
    scanf("%d", &N);
    multiplicand = malloc(1*sizeof(int));
    if(!multiplicand)
        return 0;
    multiplicand[0] = 1;
    f_len = 1;
    if(N == 1)
        printf("1");
    for(i = 2; i <= N; ++i) {
        int *fact = NULL;
        int multiplier[3];
        int start_pos = 0;
        int m_len = 0, temp = i, ind;
        while(temp) {
            multiplier[m_len++] = temp%10;
            temp /= 10;
        }
        
        fact = malloc((f_len+m_len)*sizeof(int));
        if(!fact)
            return 0;
        
        for(ind = 0; ind<(f_len+m_len); ++ind)
            fact[ind] = -1;
        
        for(ind = 0; ind < m_len; ++ind) {
            int carry = 0;
            int j, k = start_pos;
            for(j = 0; j < f_len; ++j) {
                temp = multiplicand[j]*multiplier[ind]+carry;
                if(fact[k]!= -1)
                {
                    temp+=fact[k];
                }
                fact[k] = temp%10;
                carry = temp/10;
                ++k;
            }
            if(carry) {
                fact[k] = carry;
            }
            ++start_pos;
        }
        temp = 0;
        for(ind = (f_len+m_len-1); ind>=0; --ind) {
            if(fact[ind] != -1) {
                if(i == N)
                    printf("%d", fact[ind]);
                ++temp;
            }
        }
        f_len = temp;
        free(multiplicand);
        multiplicand = malloc(temp*sizeof(int));
        for(ind = 0; ind < temp; ++ind)
            multiplicand[ind] = fact[ind];
        free(fact);
    }
    free(multiplicand);
    return 0;
}
