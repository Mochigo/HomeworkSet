#include <stdio.h>
#include "p1.h"

// 变量名必须以字母开头

Word *curWord;
int kk;

void lrparser();
void yucu();
void statement();
void expression();
void term();
void factor();

int main()
{
    curWord = (Word *)malloc(sizeof(Word));
    kk = 0;
    FILE *read = NULL;
    read = fopen("./data.txt", "r");
    if (!read)
    {
        return 0;
    }

    fscanf(read, "%[^#]s", input);
    fclose(read);

    lrparser();

    return 0;
}

void lrparser()
{
    curWord = scanner();
    // 1 对应 begin
    if (curWord->typeNum == 1)
    {
        curWord = scanner();
        yucu();
        // 6 对应 end
        if (curWord->typeNum == 6)
        {
            curWord = scanner();
            // 1000 代表 结束符
            if (curWord->typeNum == 1000 && kk == 0)
            {
                printf("success");
            }
        }
        else
        {
            if (kk != 1)
            {
                printf("缺少end");
                kk = 1;
            }
        }
    }
    else
    {
        printf("缺乏begin");
        kk = 1;
    }
    return;
}

void yucu()
{
    statement();
    // 34 对应 ;
    while (curWord->typeNum == 34)
    {
        curWord = scanner();
        statement();
    }

    return;
}

void statement()
{
    // 10 对应 标识符
    if (curWord->typeNum == 10)
    {
        curWord = scanner();
        // 42 对应 :=
        if (curWord->typeNum == 42)
        {
            curWord = scanner();
            expression();
        }
        else
        {
            printf("赋值符号错误");
            kk = 1;
        }
    }
    else
    {
        // 如果刚好就是结束符, 退出
        if (curWord->typeNum == 6)
        {
            return;
        }
        printf("赋值语句错误");
        kk = 1;
    }
    return;
}

void expression()
{
    term();
    // 22 对应 + 23 对应 -
    while (curWord->typeNum == 22 || curWord->typeNum == 23)
    {
        curWord = scanner();
        term();
    }
    return;
}

void term()
{
    factor();
    // 24 对应 * 25 对应 /
    while (curWord->typeNum == 24 || curWord->typeNum == 25)
    {
        curWord = scanner();
        factor();
    }

    return;
}

void factor()
{
    // 10 对应 变量名（标识符） 20 对应 数字
    if (curWord->typeNum == 10 || curWord->typeNum == 20)
    {
        curWord = scanner();
    }
    // 26 对应 (
    else if (curWord->typeNum == 26)
    {
        curWord = scanner();
        expression();
        if (curWord->typeNum == 27)
        {
            curWord = scanner();
        }
        else
        {
            printf("缺少)");
            kk = 1;
        }
    }
    else
    {
        printf("表达式错误");
        kk = 1;
    }

    return;
}