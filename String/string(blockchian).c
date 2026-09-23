#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4   // 每个块存4个字符（可自定义）

// 块结点
typedef struct Block {
    char ch[BLOCK_SIZE];
    struct Block *next;
} Block;

// 块链串
typedef struct {
    Block *head;
    Block *tail;
    int length;     // 实际有效字符长度
} BLString;

//========================= 1. 初始化 =========================
void InitString(BLString *s) {
    s->head = s->tail = NULL;
    s->length = 0;
}

//========================= 2. 赋值：C字符串→块链串 =========================
int StrAssign(BLString *s, const char *str) {
    InitString(s);
    int n = strlen(str);
    if (n == 0) return 1;

    for (int i = 0; i < n; i += BLOCK_SIZE) {
        Block *p = (Block *)malloc(sizeof(Block));
        if (!p) return 0;
        p->next = NULL;

        int k;
        for (k = 0; k < BLOCK_SIZE && i + k < n; k++)
            p->ch[k] = str[i + k];
        // 不足补占位符
        for (; k < BLOCK_SIZE; k++)
            p->ch[k] = '#';

        if (!s->head)
            s->head = s->tail = p;
        else {
            s->tail->next = p;
            s->tail = p;
        }
    }
    s->length = n;
    return 1;
}

//========================= 3. 求长度 =========================
int StrLength(BLString s) {
    return s.length;
}

//========================= 4. 判断空串 =========================
int StrEmpty(BLString s) {
    return s.length == 0;
}

//========================= 5. 打印串（跳过#） =========================
void StrPrint(BLString s) {
    Block *p = s.head;
    int cnt = 0;
    while (p && cnt < s.length) {
        for (int i = 0; i < BLOCK_SIZE && cnt < s.length; i++, cnt++)
            putchar(p->ch[i]);
        p = p->next;
    }
    putchar('\n');
}

//========================= 6. 串复制 s2→s1 =========================
int StrCopy(BLString *s1, BLString s2) {
    InitString(s1);
    Block *p = s2.head;
    while (p) {
        Block *q = (Block *)malloc(sizeof(Block));
        memcpy(q->ch, p->ch, BLOCK_SIZE);
        q->next = NULL;

        if (!s1->head)
            s1->head = s1->tail = q;
        else {
            s1->tail->next = q;
            s1->tail = q;
        }
        p = p->next;
    }
    s1->length = s2.length;
    return 1;
}

//========================= 7. 串比较 =========================
int StrCompare(BLString s1, BLString s2) {
    if (s1.length != s2.length)
        return s1.length - s2.length;

    Block *p1 = s1.head, *p2 = s2.head;
    int i1 = 0, i2 = 0, cnt = 0;
    int len = s1.length;

    while (cnt < len) {
        if (p1->ch[i1] != p2->ch[i2])
            return p1->ch[i1] - p2->ch[i2];

        cnt++; i1++; i2++;
        if (i1 == BLOCK_SIZE) { p1 = p1->next; i1 = 0; }
        if (i2 == BLOCK_SIZE) { p2 = p2->next; i2 = 0; }
    }
    return 0;
}

//========================= 8. 串拼接 s1+s2→t =========================
int StrConcat(BLString *t, BLString s1, BLString s2) {
    InitString(t);
    StrCopy(t, s1);

    Block *p = s2.head;
    while (p) {
        Block *q = (Block *)malloc(sizeof(Block));
        memcpy(q->ch, p->ch, BLOCK_SIZE);
        q->next = NULL;
        t->tail->next = q;
        t->tail = q;
        p = p->next;
    }
    t->length = s1.length + s2.length;
    return 1;
}

//========================= 9. 取子串 sub=s[pos,len] pos从1开始 =========================
int SubString(BLString *sub, BLString s, int pos, int len) {
    InitString(sub);
    if (pos < 1 || len < 0 || pos + len - 1 > s.length)
        return 0;

    char *tmp = (char *)malloc(len + 1);
    Block *p = s.head;
    int cnt = 0, idx = 0;

    while (p && cnt < s.length) {
        for (int i = 0; i < BLOCK_SIZE && cnt < s.length; i++, cnt++) {
            if (cnt >= pos - 1 && cnt < pos - 1 + len)
                tmp[idx++] = p->ch[i];
        }
        p = p->next;
    }
    tmp[idx] = '\0';
    StrAssign(sub, tmp);
    free(tmp);
    return 1;
}

//========================= 10. 查找子串（朴素匹配） =========================
int StrIndex(BLString s, BLString t) {
    int n = s.length, m = t.length;
    if (m == 0 || m > n) return 0;

    BLString sub;
    for (int i = 1; i <= n - m + 1; i++) {
        SubString(&sub, s, i, m);
        if (StrCompare(sub, t) == 0) return i;
    }
    return 0;
}

//========================= 11. 销毁串 =========================
void DestroyString(BLString *s) {
    Block *p = s->head, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    s->head = s->tail = NULL;
    s->length = 0;
}

//========================= 测试主函数 =========================
int main() {
    BLString s1, s2, t, sub;
    InitString(&s1);
    InitString(&s2);

    StrAssign(&s1, "hello");
    StrAssign(&s2, "world");

    printf("s1: "); StrPrint(s1);
    printf("s2: "); StrPrint(s2);

    StrConcat(&t, s1, s2);
    printf("s1+s2: "); StrPrint(t);

    SubString(&sub, t, 3, 4);
    printf("从3开始取4个: "); StrPrint(sub);

    BLString pat;
    StrAssign(&pat, "wor");
    int pos = StrIndex(t, pat);
    printf("'wor'位置: %d\n", pos);

    DestroyString(&s1);
    DestroyString(&s2);
    DestroyString(&t);
    DestroyString(&sub);
    DestroyString(&pat);

    return 0;
}