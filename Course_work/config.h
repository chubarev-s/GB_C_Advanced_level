#ifndef __CONFIG_H
#define __CONFIG_H


//Подключаемые библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>

//Определяем границы экрана
#define MAX_X 60
#define MAX_Y 25
//Определяем границы поля, для генерации тыкв
#define SIZE_X 60
#define SIZE_Y 17
#define COUNT_XY 	((SIZE_Y-2)*(SIZE_X-2))
#define TWO_DRONE 	((SIZE_X-1)/2)
#define THREE_DRONE ((SIZE_X-1)/3)
#define FOUR_DRONE 	((SIZE_X-1)/4)
#define FIVE_DRONE 	((SIZE_X-1)/5)

/*Глобальная переменная для паузы*/
extern int PAUSE;
extern int all_eat;

/*Структура описывающая тележки */
typedef struct tail_t{
	int x;
	int y;
} tail_t;

/*Пречисление направлений*/
typedef enum{
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

/*Структура описывающая дрона*/	
typedef struct snake_t{
	int x;
	int y;
	int score;
	int matrix_direct[SIZE_X][SIZE_Y];
	struct tail_t * tail;
	size_t tsize;
	Direction direction;
}  snake_t;

/*Структура для тыкв*/
typedef struct food_t{
    int x[COUNT_XY];
    int y[COUNT_XY];
    int isEaten[SIZE_X][SIZE_Y];
	int count_food;
} food_t;


//Функции:
struct snake_t initSnake(int x, int y, size_t tsize);
food_t initFood();
void printSnake(struct snake_t snake, struct snake_t snake2, struct snake_t snake3,
                        struct snake_t snake4, struct snake_t snake5, food_t food, int count_drons);
snake_t move(snake_t snake, food_t *food);
void input(snake_t *snake);
void printExit(snake_t *head);
//void generateSnakeDirection(snake_t *snake, food_t food);
void generateSnakeDirection(snake_t *snake1, snake_t *snake2, snake_t *snake3, snake_t *snake4,snake_t *snake5, food_t food, int count_snake, int s1_auto_pil);
int getRandomNumber(int min, int max);


#endif // __CONFIG_H