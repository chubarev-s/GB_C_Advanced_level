/*
Задание 1. Сколько раз встречается максимум
На стандартном потоке ввода задается натуральное число N (N > 0), после
которого следует последовательность из N целых чисел.
На стандартный поток вывода напечатайте, сколько раз в этой
последовательности встречается максимум.
Указание: использовать массивы запрещается.
Данные на входе: Натуральное число N (N > 0), после которого следует
последовательность из N целых чисел.
Данные на выходе: Одно целое число.
Пример №1
Данные на входе: 6 1 2 3 2 0 3
Данные на выходе: 2
Пример №2
Данные на входе: 3 5 2 -1
Данные на выходе: 1
*/

#include "stdio.h"
#include "stdlib.h"

//Объявим int синонимом datatype
typedef int datatype; 
//создаём структуру буфера(листа и т.п.)
typedef struct list {
    datatype value;
    struct list * next;
}stack;
/*Функция добавления данных в наш буфер(стек)*/
void push(stack **p,datatype data)
{
    stack *ptmp;
    ptmp = malloc(sizeof(stack));
    ptmp->value = data;
    ptmp->next = *p;
    *p = ptmp;
}
/*Функция опустошения буфера*/
_Bool empty_stack(stack *p) 
{
    return p==NULL;
}
/*Функция чтение из буфера*/
datatype pop(stack **p)
{
    stack *ptmp = *p;
    datatype c;
    if(empty_stack(*p)){
        printf("!!! Попытка взять из пустого стека !!!\n");
        exit (1);
    }
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp); 
    return c;
}

int main()
{
    int N = 0, count = 0;
    int num = 0;
    int max = 0, count_max = 1, read_num = 0;
    stack *buf_num = NULL;
    printf("Введите кол-во чисел: ");
    scanf("%d", &N);
    printf("Введите последовательность чисел: ");
    while (count != N)
    {
        scanf("%d", &num);
        push(&buf_num, num);
        count++;
    }
    max = pop(&buf_num);
    printf("max = %d\n", max);
    for(int i = 0; i < N-1; i++)
    {
        read_num = pop(&buf_num);
        if(read_num > max)
        {
            max = read_num;
            count_max = 1;
        }
        else if(read_num == max)
        {
            count_max++;
        }
    }
    printf("Наибольшее число: %d\nВстречается в последовательности \"%d\" раз\n", max, count_max);

    return 0;
}