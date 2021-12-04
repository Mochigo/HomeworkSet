#include <stdio.h>
#include "p1.h"

// 变量名必须以字母开头

Word* curWord;
int kk;
int k, qid;

struct {
    char result[12];
    char ag1[12];
    char op[12];
    char ag2[12];
} quad[20];

void lrparser();
void yucu();
void statement();
char* expression();
char* term();
char* factor();
char* newtemp();
void emit(char* result, char* ag1, char* op, char* ag2);

int main() {
    curWord = (Word*)malloc(sizeof(Word));
    kk = 0;
    k = 0;
    qid = 0;
    FILE* read = NULL;
    read = fopen("./data.txt", "r");
    if (!read) {
        return 0;
    }

    fscanf(read, "%[^#]s", input);
    fclose(read);

    lrparser();

    for (int i = 0; i < qid; i++) {
        printf("(%d) %s = %s %s %s\n", i + 1, quad[i].result, quad[i].ag1, quad[i].op, quad[i].ag2);
    }

    return 0;
}

void lrparser() {
    curWord = scanner();
    // 1 对应 begin
    if (curWord->typeNum == 1) {
        curWord = scanner();
        yucu();
        // 6 对应 end
        if (curWord->typeNum == 6) {
            curWord = scanner();
            // 1000 代表 结束符
            if (curWord->typeNum == 1000 && kk == 0) {
                printf("success\n");
            }
        } else {
            if (kk != 1) {
                printf("缺少end\n");
                kk = 1;
            }
        }
    } else {
        printf("缺乏begin\n");
        kk = 1;
    }
    return;
}

void yucu() {
    int schain = 0;
    statement();
    // 34 对应 ;
    while (curWord->typeNum == 34) {
        curWord = scanner();
        statement();
    }

    return;
}

void statement() {
    char tt[12], eplace[12];
    // 10 对应 标识符
    if (curWord->typeNum == 10) {
        strcpy(tt, curWord->word);  // 把当前的标识符复制到tt中
        curWord = scanner();
        // 42 对应 :=
        if (curWord->typeNum == 42) {
            curWord = scanner();
            strcpy(eplace, expression());
            emit(tt, eplace, "", "");
        } else {
            printf("赋值符号错误\n");
            kk = 1;
        }
    } else {
        // 如果刚好就是结束符, 退出
        if (curWord->typeNum == 6) {
            return;
        }
        printf("赋值语句错误\n");
        kk = 1;
    }
    return;
}

char* expression() {
    char *tp, *ep2, *eplace, *tt;
    tp = (char*)malloc(12);
    ep2 = (char*)malloc(12);
    tt = (char*)malloc(12);
    eplace = (char*)malloc(12);
    strcpy(eplace, term());
    // 22 对应 + 23 对应 -
    while (curWord->typeNum == 22 || curWord->typeNum == 23) {
        strcpy(tt, curWord->word);
        curWord = scanner();
        strcpy(ep2, term());
        strcpy(tp, newtemp());
        emit(tp, eplace, tt, ep2);
        strcpy(eplace, tp);
    }
    return eplace;
}

char* term() {
    char *tp, *ep2, *eplace, *tt;
    tp = (char*)malloc(12);
    ep2 = (char*)malloc(12);
    tt = (char*)malloc(12);
    eplace = (char*)malloc(12);
    strcpy(eplace, factor());
    // 24 对应 * 25 对应 /
    while (curWord->typeNum == 24 || curWord->typeNum == 25) {
        strcpy(tt, curWord->word);
        curWord = scanner();
        strcpy(ep2, factor());
        strcpy(tp, newtemp());
        emit(tp, eplace, tt, ep2);
        strcpy(eplace, tp);
    }
    return eplace;
}

char* factor() {
    char* fplace;
    fplace = (char*)malloc(12);
    strcpy(fplace, "");
    // 10 对应 变量名（标识符） 20 对应 数字
    if (curWord->typeNum == 10 || curWord->typeNum == 20) {
        strcpy(fplace, curWord->word);
        curWord = scanner();
    }
    // 26 对应 (
    else if (curWord->typeNum == 26) {
        curWord = scanner();
        fplace = expression();
        if (curWord->typeNum == 27) {
            curWord = scanner();
        } else {
            printf("缺少)\n");
            kk = 1;
        }
    } else {
        printf("出错时:%d\n", curWord->typeNum);
        printf("缺少(\n");
        kk = 1;
    }

    return fplace;
}

char* newtemp() {
    char* p;
    char m[12];
    p = (char*)malloc(12);
    k++;
    sprintf(m, "%d", k);
    strcpy(p + 1, m);
    p[0] = 't';
    return p;
}

void emit(char* result, char* ag1, char* op, char* ag2) {
    strcpy(quad[qid].result, result);
    strcpy(quad[qid].ag1, ag1);
    strcpy(quad[qid].op, op);
    strcpy(quad[qid].ag2, ag2);

    qid++;
}