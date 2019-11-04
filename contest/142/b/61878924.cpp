#include <stdio.h>
int main(){
    int n, m, t;
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 1){
        printf("%d\n", n + m - 1);
    }else if (n == 2 || m == 2){
        n = n + m - 2;
        t = n / 4 * 2;
        if (n % 4 == 3){
            n--;
        }
        t += n % 4;
        printf("%d\n", t * 2);
    }else{
        printf("%d\n", (n * m + 1) / 2);
    }
    return 0;
}