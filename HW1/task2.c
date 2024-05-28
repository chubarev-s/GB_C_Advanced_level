/*
Задание 2. Инверсия старших
На вход программе подается беззнаковое 32-битное целое число N. Требуется
изменить значения всех битов старшего байта числа на противоположные и
вывести полученное таким образом число.
Данные на входе: Беззнаковое 32-битное целое число N
Данные на выходе: Одно целое число.
Пример №1
Данные на входе: 1
Данные на выходе: 4278190081
Пример №2
Данные на входе: 4278190081
Данные на выходе: 1
*/

#include "stdio.h"
#include "stdint.h"

int main()
{
    uint32_t num = 0x00000000;
    uint8_t swap = 0x00, swap_num = 0x00;
    
    printf("Введите число: ");
    scanf("%u", &num);
    swap_num = num >> 24;
    swap = ~swap_num;
    /*Освободим первый байт для дальнейшего сложения*/
    num = num << 8;
    num = num >> 8; 
    num = num + (swap << 24);
    printf("Число с инверсным первым байтом: %u\n", num);

    return 0;
}
