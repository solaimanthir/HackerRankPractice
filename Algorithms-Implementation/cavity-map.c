/*Link to problem statement:
https://www.hackerrank.com/challenges/cavity-map 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    if(N) {
        char map[N][N+1];
        int i, j;
        for(i = 0; i <= (N-1); ++i) {
            scanf("%s", map[i]);
        }
        
        for(i = 0; i <= (N-1); ++i) {
            for(j= 0; j<= (N-1); ++j) {
                if(!i || !j || (i == N-1) || (j == N-1))
                    printf("%c", map[i][j]);
                else
                    {
                    if(map[i-1][j] < map[i][j] && map[i+1][j] < map[i][j] &&
                      map[i][j-1] < map[i][j] && map[i][j+1] < map[i][j])
                        printf("X");
                    else
                        printf("%c", map[i][j]);
                }
            }
            if(j == N)
                printf("\n");
        }
    }
    
    return 0;
}
