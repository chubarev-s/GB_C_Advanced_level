/*
Задание 3. Не пара
Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000)
натуральных чисел, не превосходящих 1 000 000. Известно, что ровно одно
число в этом наборе встречается один раз, а остальные — ровно по два раза.
Помогите им найти это число. Входные данные: в первой входной строке
вводится число N, затем по одному числу в строке вводятся N натуральных
чисел, не превосходящих 2 000 000 000. Выходные данные: ваша программа
должна определить число, встречающееся один раз, и вывести его на экран.
Указание: использовать массивы запрещается.
Данные на входе: Натуральное число N (N > 0), после которого следует
последовательность из N целых чисел.
Данные на выходе: Одно целое число.
Пример №1
Данные на входе: 3 12 15 12
Данные на выходе: 15
Пример №2
Данные на входе: 5 1 2 0 2 1
Данные на выходе: 0
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
    int num = 0, count = 0, num_one;
    char exit;
    stack *buf_num = NULL;
    printf("Введите числа: ");
    while (exit != '\n')
    {
        scanf("%d", &num);
        exit = getchar();  //ps, понимаю что не очень вариант, но так проще :)
        if(num != '\n')
        {
            push(&buf_num, num);
            count++;
        }
    }
    num = pop(&buf_num); //считываем в переменную первое значение, чтоб было с чем сравнивать
    for(size_t i = 0; i < count-1; i++)
    {
        num ^= pop(&buf_num);
    }
    
    printf("Единственное число из последовательности - %d\n", num);


    return 0;
}