#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int p;
        scanf("%d", &p);
        int r = 0;
        char res[10000] = {0};  
        int len = 0;
        while (1) {
            r = r * 10 + 1;              
            int digit = r / p;           
            if (digit != 0 || len != 0) { 
                res[len++] = digit + '0';
            }
            r = r % p;                  
            if (r == 0) break;           
        }
        res[len] = '\0';
        printf("%s\n", res);
    }
    return 0;
}