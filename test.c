#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int k=0;
    long long power=1; 
    while ((power-1)/2<n) {
        power*=3;
        k++;
    }
    printf("%d\n",k);
    return 0;
}