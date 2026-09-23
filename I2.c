#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pos;
    char dir;
    char name[15];
    int time;
} Ant;

int cmp_pos(const void *a, const void *b) {
    Ant *antA = (Ant *)a;
    Ant *antB = (Ant *)b;
    return antA->pos - antB->pos;
}
int cmp_time(const void *a, const void *b) {
    Ant *antA = (Ant *)a;
    Ant *antB = (Ant *)b;
    return antA->time - antB->time;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n, L;
        scanf("%d %d", &n, &L);
        Ant ants[105]; 
        Ant res[105];    

        for (int i = 0; i < n; i++) {
            scanf("%s %d %c", ants[i].name, &ants[i].pos, &ants[i].dir);
            
            if (ants[i].dir == 'L') {
                ants[i].time = ants[i].pos;
            } else {
                ants[i].time = L - ants[i].pos;
            }
            res[i] = ants[i];        
        }

        qsort(ants, n, sizeof(Ant), cmp_pos);
        qsort(res, n, sizeof(Ant), cmp_time);

        printf("Case #%d:\n", caseNum);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (res[i].dir == 'L') {
                printf("%d %s\n", res[i].time, ants[left++].name);
            } else {
                printf("%d %s\n", res[i].time, ants[right--].name);
            }
        }
    }
    return 0;
}