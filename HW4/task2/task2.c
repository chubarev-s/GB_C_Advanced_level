/*Задание 2. Обратная польская запись

Написать алгоритм перевода из инфиксной записи в обратную польскую. Для его реализации нужны данные по приоритетам операций. Реализовать алгоритм, используя побитовые операции (&, |, ^).

Пример №1
Данные на вход: ( 3 & 5 ) ^ 4 | 9
Данные на выход: 3 5 & 4 ^ 9 |

Пример №2
Данные на вход: 8 ^ 2 & 5 | ( 6 & 1 )
Данные на выход: 8 2 5 & ^ 6 1 & |
*/

// #include "stack.h"
#include "stdio.h"
#include "stdlib.h"


#define MAX_STACK_SIZE 255
#define BUFF_SIZE 255



char op[MAX_STACK_SIZE] = {0}; // массив - стек

int pst = 0; // заполненность стека

void push(char v) 
{
    op[pst++] = v;
}

char pop(void)
{
    if(pst <= 0 || pst >= MAX_STACK_SIZE) {
        fprintf(stderr, "Error. Stack overflow");
        return 1;
    }
    pst--;
    return op[pst];
}

int isEmpty(void) // определяет пустой ли стек st
{
    return (pst <= 0);
}
int priority(char c){
    if(c == '&')
        return 3;
    if(c == '^')
        return 2;
    if(c == '|')
        return 1;
    
    return 0;
    
}

_Bool isDigit(char c) // проверяем является ли символ цифрой
{
    return ((c>='0')&&(c<='9'));
}

_Bool isOperator(char c){
    return c == '&' || c == '^' || c == '|';
}

int main(void)
{
    int pos = 0;
    char answer[BUFF_SIZE] = {0};
    char str[1000];
    int len = 0;
    char c;
    printf("Input inverse string: ");
    while( (c = getchar()) != '\n' ) 
    {
        str[len++] = c;
    }
    str[len] = 0;
    for(int i = 0; i < len; i++)
    {
        if(isDigit(str[i])) 
        {
            int number, size = 0;
            for(number = 0; isDigit(str[i]); i++, size++){
                number = number*10 + str[i] - '0';
            }
            sprintf(answer+pos, "%d ", number);
            pos += size + 1;
        } else {
            if(i >= len)
                break;
            c = str[i];
            if(isOperator(c))
            {
                while (!isEmpty())
                {
                    char top = pop();
                    if(priority(top) >= priority(c)){
                        sprintf(answer+pos, "%c ", top);
                        pos += 2;
                    } else {
                        push(top);
                        break;
                    }
                }
                push(c);
            } else if(c == ' ('){
                push(c);
            } else if(c == ') '){
                while ((c=pop()) != '(')
                {
                    sprintf(answer+pos, "%c ", c);
                    pos += 2;
                }
                
            }
        }
    }
    while (!isEmpty())
    {
        sprintf(answer+pos, "%c ", pop());
        pos += 2; 
    }
    
    printf("answer = %s\n", answer);
    return 0;
}
