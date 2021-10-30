#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _KEY_WORD_END "waiting for your expanding"

typedef struct Word
{
    int typeNum;
    char *word;
} Word;

char input[255];
char token[255] = "";
char binary[33] = "";
int p_input;
int p_token;

char ch;
char *rwtab[] = {"begin", "if", "then", "while", "do", "end", _KEY_WORD_END};

Word *scanner();

// void main()
// {
//     int over = 1;
//     Word *oneWord = (Word *)malloc(sizeof(Word));

//     FILE *read = NULL;
//     read = fopen("./data.txt", "r");
//     if (!read)
//     {
//         return;
//     }

//     fscanf(read, "%[^#]s", input);
//     fclose(read);

//     FILE *write = NULL;
//     write = fopen("./output.txt", "w+");
//     if (!write)
//     {
//         return;
//     }

//     // printf("Enter Your words(end with #):");
//     // scanf("%[^#]s", input);
//     p_input = 0;
//     fprintf(write, "Your words: \n%s\n", input);

//     while (over < 1000 && over != -1)
//     {
//         oneWord = scanner();
//         if (oneWord->typeNum < 1000)
//         {
//             fprintf(write, "(%d, %s)\n", oneWord->typeNum, oneWord->word);
//         }
//         over = oneWord->typeNum;
//     }
//     fclose(write);
//     // printf("\npress # to exit:");
//     // scanf("%[^#]s", input);
//     free(oneWord);
// }

char m_getch()
{
    ch = input[p_input];
    p_input++;
    return ch;
}

void getbc()
{
    while (ch == ' ' || ch == 10)
    {
        ch = input[p_input];
        p_input++;
    }
}

void concat()
{
    token[p_token] = ch;
    p_token++;
    token[p_token] = '\0';
}

int letter()
{
    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    return 0;
}

int digit()
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

int reserve()
{
    int i = 0;
    while (strcmp(rwtab[i], _KEY_WORD_END))
    {
        if (!strcmp(rwtab[i], token))
        {
            return i + 1;
        }
        i++;
    }
    return 10;
}

void retract()
{
    p_input--;
}

char *dtb()
{
    int num = atoi(token);
    int i = 0, j;
    char tmp;

    memset(binary, '\0', sizeof(binary));
    if (num == 0)
    {
        binary[0] = '0';
        return binary;
    }

    while (num != 0)
    {
        binary[i++] = num % 2 + '0';
        num /= 2;
    }

    for (j = 0; j < i / 2; j++)
    {
        tmp = binary[j];
        binary[j] = binary[i - 1 - j];
        binary[i - 1 - j] = tmp;
    }

    return binary;
}

Word *scanner()
{
    Word *myWord = (Word *)malloc(sizeof(Word));
    myWord->typeNum = 10;
    myWord->word = "";

    p_token = 0;
    m_getch();
    getbc();
    if (letter())
    {
        while (letter() || digit())
        {
            concat();
            m_getch();
        }
        retract();
        myWord->typeNum = reserve();
        myWord->word = token;
        return myWord;
    }
    else if (digit())
    {
        while (digit())
        {
            concat();
            m_getch();
        }
        retract();
        myWord->typeNum = 20;
        myWord->word = dtb();
        return myWord;
    }
    else
    {
        switch (ch)
        {
        case '=':
            m_getch();
            if (ch == '=')
            {
                myWord->typeNum = 39;
                myWord->word = "==";
                return myWord;
            }
            retract();
            myWord->typeNum = 21;
            myWord->word = "=";
            return myWord;
            break;
        case '+':
            myWord->typeNum = 22;
            myWord->word = "+";
            return myWord;
            break;
        case '-':
            myWord->typeNum = 23;
            myWord->word = "-";
            return myWord;
            break;
        case '*':
            myWord->typeNum = 24;
            myWord->word = "*";
            return myWord;
            break;
        case '/':
            myWord->typeNum = 25;
            myWord->word = "/";
            return myWord;
            break;
        case '(':
            myWord->typeNum = 26;
            myWord->word = "(";
            return myWord;
            break;
        case ')':
            myWord->typeNum = 27;
            myWord->word = ")";
            return myWord;
            break;
        case '[':
            myWord->typeNum = 28;
            myWord->word = "[";
            return myWord;
            break;
        case ']':
            myWord->typeNum = 29;
            myWord->word = "]";
            return myWord;
            break;
        case '{':
            myWord->typeNum = 30;
            myWord->word = "{";
            return myWord;
            break;
        case '}':
            myWord->typeNum = 31;
            myWord->word = "}";
            return myWord;
            break;
        case ',':
            myWord->typeNum = 32;
            myWord->word = ",";
            return myWord;
            break;
        case ':':
            m_getch();
            if (ch == '=')
            {
                myWord->typeNum = 42;
                myWord->word = ":=";
                return myWord;
            }
            retract();
            myWord->typeNum = 33;
            myWord->word = ":";
            return myWord;
            break;
        case ';':
            myWord->typeNum = 34;
            myWord->word = ";";
            return myWord;
            break;
        case '>':
            m_getch();
            if (ch == '=')
            {
                myWord->typeNum = 37;
                myWord->word = ">=";
                return myWord;
            }
            retract();
            myWord->typeNum = 35;
            myWord->word = ">";
            return myWord;
            break;
        case '<':
            m_getch();
            if (ch == '=')
            {
                myWord->typeNum = 38;
                myWord->word = "<=";
                return myWord;
            }
            else if (ch == '>')
            {
                myWord->typeNum = 41; //新的识别码！
                myWord->word = "<>";
                return myWord;
            }
            retract();
            myWord->typeNum = 36;
            myWord->word = "<";
            return myWord;
            break;
        case '!':
            m_getch();
            if (ch == '=')
            {
                myWord->typeNum = 40;
                myWord->word = "!=";
                return myWord;
            }
            retract();
            myWord->typeNum = -1;
            myWord->word = "ERROR";
            return myWord;
            break;
        case '\0':
            myWord->typeNum = 1000;
            myWord->word = "OVER";
            return myWord;
            break;
        default:
            myWord->typeNum = -1;
            myWord->word = "ERROR";
            return myWord;
        }
    }
}