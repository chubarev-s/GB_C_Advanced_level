/*
Задание 3. Префикс и суффикс

Реализовать программу 3-го практического задания более эффективным способом со сложностью О(n) (см. код в лекции).


Пример №1
Данные на вход:

don't_panic
nick_is_a_mastodon
Данные на выход: 3

Пример №2
Данные на вход:

monty_python
python_has_list_comprehensions
Данные на выход: 6
*/

#include "stdio.h"
#include "stdint.h"
#include "inttypes.h"
#include "string.h"

#define SIZE 1000

void zFunc(char *s, int z[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        while ( (i+z[i] < n) && (s[z[i]] == s[i+z[i]]))
        {
            z[i]++;
        }
        
    }
    
}


int main()
{
    char t[SIZE] = {0};
    char p[SIZE] = {0};
    char s[SIZE + SIZE] = {0};
    int z[SIZE + SIZE] = {0};
    printf("input text: ");
    scanf("%s", t);
    printf("\ninput word: ");
    scanf("%s", p);
    size_t tlen = strlen(t);
    size_t plen = strlen(p);
    sprintf(s, "%s#%s", p,t);
    zFunc(s,z);
    for(size_t i=0; i<tlen; i++){
        if(z[i+plen] == plen)
            printf("find world in position %zu\n", i);
    }
    return 0;
}








