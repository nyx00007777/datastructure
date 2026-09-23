#include <stdio.h>
#include <string.h>  // 用于strlen等基础函数
#define MAXSIZE 100  


typedef struct {
    char ch[MAXSIZE];  // 字符数组存储串
    int length;       // 串的实际长度
} SqString;

//初始化
void InitString(SqString *s) {
    s->length = 0;
}


// 3. 字符串赋值（将常量字符串赋给顺序串
void StrAssign(SqString *s, char *str) {
    int i = 0;
    // 逐个赋值字符，不超过最大长度
    while (str[i] != '\0' && i < MAXSIZE - 1) {
        s->ch[i] = str[i];
        i++;
    }
    s->ch[i] = '\0';  // 字符串结束符
    s->length = i;    // 更新串长度
}


// 4. 求串的长度
int StrLength(SqString s) {
    return s.length;
}

// 5. 串复制（将s2复制到s1）
void StrCopy(SqString *s1, SqString s2) {
    for (int i = 0; i < s2.length; i++) {
        s1->ch[i] = s2.ch[i];
    }
    s1->ch[s2.length] = '\0';
    s1->length = s2.length;
}

// 6. 判断串是否为空（空返回1，非空返回0
int StrEmpty(SqString s) {
    return s.length == 0 ? 1 : 0;
}

// ==============================================
// 7. 串比较（s1>s2返回正数，s1<s2返回负数，相等返回0）
// ==============================================
int StrCompare(SqString s1, SqString s2) {
    int minLen = s1.length < s2.length ? s1.length : s2.length;
    // 逐个字符比较
    for (int i = 0; i < minLen; i++) {
        if (s1.ch[i] != s2.ch[i]) {
            return s1.ch[i] - s2.ch[i];
        }
    }
    // 前minLen个字符相等，比较长度
    return s1.length - s2.length;
}

// ==============================================
// 8. 串拼接（将s2拼接到s1后面，结果存在s1）
// ==============================================
int StrConcat(SqString *s1, SqString s2) {
    // 检查拼接后是否超出最大长度
    if (s1->length + s2.length >= MAXSIZE) {
        printf("拼接失败：超出最大长度！\n");
        return 0;
    }
    // 逐个拼接字符
    for (int i = 0; i < s2.length; i++) {
        s1->ch[s1->length + i] = s2.ch[i];
    }
    s1->length += s2.length;
    s1->ch[s1->length] = '\0';
    return 1;
}

// ==============================================
// 9. 截取子串（从s的第pos个位置，截取len个字符到sub）
// pos：起始位置（从1开始），len：截取长度
// ==============================================
int SubString(SqString *sub, SqString s, int pos, int len) {
    // 合法性判断
    if (pos < 1 || pos > s.length || len < 0 || pos + len - 1 > s.length) {
        printf("截取失败：参数非法！\n");
        return 0;
    }
    // 截取字符
    for (int i = 0; i < len; i++) {
        sub->ch[i] = s.ch[pos - 1 + i];
    }
    sub->length = len;
    sub->ch[len] = '\0';
    return 1;
}

// ==============================================
// 10. 查找子串（朴素匹配算法）
// 在s中查找t第一次出现的位置，找到返回起始下标（从1开始），没找到返回0
// ==============================================
int StrIndex(SqString s, SqString t) {
    int i = 0, j = 0;
    // 朴素匹配核心逻辑
    while (i < s.length && j < t.length) {
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;  // 回退主串指针
            j = 0;          // 重置子串指针
        }
    }
    // 匹配成功
    if (j == t.length) {
        return i - j + 1;
    }
    return 0;
}

// ==============================================
// 11. 插入子串（在s的第pos个位置插入t）
// ==============================================
int StrInsert(SqString *s, int pos, SqString t) {
    // 合法性+长度判断
    if (pos < 1 || pos > s->length + 1 || s->length + t.length >= MAXSIZE) {
        printf("插入失败：参数非法或超出长度！\n");
        return 0;
    }
    // 字符后移，腾出空间
    for (int i = s->length - 1; i >= pos - 1; i--) {
        s->ch[i + t.length] = s->ch[i];
    }
    // 插入子串
    for (int i = 0; i < t.length; i++) {
        s->ch[pos - 1 + i] = t.ch[i];
    }
    s->length += t.length;
    s->ch[s->length] = '\0';
    return 1;
}

// ==============================================
// 12. 删除子串（从s的第pos个位置，删除len个字符）
// ==============================================
int StrDelete(SqString *s, int pos, int len) {
    // 合法性判断
    if (pos < 1 || len < 0 || pos + len - 1 > s->length) {
        printf("删除失败：参数非法！\n");
        return 0;
    }
    // 字符前移覆盖
    for (int i = pos + len - 1; i < s->length; i++) {
        s->ch[i - len] = s->ch[i];
    }
    s->length -= len;
    s->ch[s->length] = '\0';
    return 1;
}

// ==============================================
// 辅助函数：打印顺序串
// ==============================================
void StrPrint(SqString s) {
    if (StrEmpty(s)) {
        printf("空串\n");
        return;
    }
    for (int i = 0; i < s.length; i++) {
        printf("%c", s.ch[i]);
    }
    printf("\n");
}

// ==============================================
// 测试主函数
// ==============================================
int main() {
    SqString s1, s2, sub;
    // 初始化
    InitString(&s1);
    InitString(&s2);
    InitString(&sub);

    // 赋值
    StrAssign(&s1, "hello");
    StrAssign(&s2, " world");
    printf("s1："); StrPrint(s1);
    printf("s2："); StrPrint(s2);

    // 求长度
    printf("s1长度：%d\n", StrLength(s1));

    // 拼接
    StrConcat(&s1, s2);
    printf("拼接后s1："); StrPrint(s1);

    // 截取子串（从第1个位置截取5个字符）
    SubString(&sub, s1, 1, 5);
    printf("截取子串："); StrPrint(sub);

    // 查找子串
    SqString t; InitString(&t); StrAssign(&t, "world");
    int pos = StrIndex(s1, t);
    printf("'world'在s1中的位置：%d\n", pos);

    // 插入子串（在第6个位置插入" my"）
    SqString insertStr; InitString(&insertStr); StrAssign(&insertStr, " my");
    StrInsert(&s1, 6, insertStr);
    printf("插入后s1："); StrPrint(s1);

    // 删除子串（从第1个位置删除6个字符）
    StrDelete(&s1, 1, 6);
    printf("删除后s1："); StrPrint(s1);

    // 比较串
    int cmp = StrCompare(s1, s2);
    printf("s1和s2比较结果：%d\n", cmp);

    return 0;
}