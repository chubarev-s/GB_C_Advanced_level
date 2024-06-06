#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <inttypes.h>

#define MAX_X 15
#define MAX_Y 15
/*Структура описывающая "хвост змейки" */
typedef struct tail_t{
	int x;
	int y;
} tail_t;

/*Структура описывающая змейку*/	
typedef struct snake_t{
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
}  snake_t;

/*Ф-ция возвращающая структуру змейки */
struct snake_t initSnake(int x, int y, size_t tsize){
	struct snake_t snake;
	snake.x = x;
	snake.y = y;
	snake.tsize = tsize;
	snake.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		snake.tail[i].x = x + i +1;
		snake.tail[i].y = y;
		}
	return snake;
}

	
/* Рисуем змейку вида: @** */
void printSnake(struct snake_t snake){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i)
		{
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
			}
		}
		
		for (int i = 0; i < snake.tsize; ++i)
		{
			matrix[snake.tail[i].x][snake.tail[i].y] = '*';
		}
		if(matrix[snake.x][snake.y] != '*'){
			
			matrix[snake.x][snake.y] = '@';
			for (int j = 0; j < MAX_Y; ++j)
			{
				for (int i = 0; i < MAX_X; ++i)
				{
					printf("%c", matrix[i][j]);
				}
				printf("\n");
			}
		} else {
			printf("X", matrix[snake.x][snake.y]);
			printf("GAME OWER!");
			snake = initSnake( 10, 5, 5);
			printSnake(snake);
		}
		
	}
	
/*Движение змейки влево*/
snake_t moveLeft(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--)
	{
		snake.tail[i] = snake.tail[i-1];          //теряем последнюю "часть" хвоста, сдвигая всё влево
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.x = snake.x - 1;	
	/*чтобы змейка не исчезала (и не словили ошибку фрагминтации, т.к. это уход за выделенную память), а выходила с другого края:*/
	if (snake.x < 0)
	{
		snake.x = MAX_X - 1;
	}
	 return snake;
}	

/*Движение змейки вправо*/
snake_t moveRight(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--)
	{
		snake.tail[i] = snake.tail[i-1];          
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.x = snake.x + 1;	
	/*чтобы змейка не исчезала (и не словили ошибку фрагминтации, т.к. это уход за выделенную память), а выходила с другого края:*/
	if (snake.x > MAX_X - 1)
	{
		snake.x = 0;
	}
	 return snake;
}	

/*Движение змейки вниз*/
snake_t moveDown(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--)
	{
		snake.tail[i] = snake.tail[i-1];          
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.y = snake.y + 1;	
	/*чтобы змейка не исчезала (и не словили ошибку фрагминтации, т.к. это уход за выделенную память), а выходила с другого края:*/
	if (snake.y > MAX_Y - 1)
	{
		snake.y = 0;
	}
	 return snake;
}	

/*Движение змейки вверх*/
snake_t moveUp(snake_t snake){
	for (int i = snake.tsize - 1; i > 0; i--)
	{
		snake.tail[i] = snake.tail[i-1];          
	}
	snake.tail[0].x = snake.x;
	snake.tail[0].y = snake.y;
	
	snake.y = snake.y - 1;	
	/*чтобы змейка не исчезала (и не словили ошибку фрагминтации, т.к. это уход за выделенную память), а выходила с другого края:*/
	if (snake.y < 0)
	{
		snake.y = MAX_Y - 1;
	}
	 return snake;
}	


int main(){
	int a = 0;
	char key, last_key = 'a';
	struct snake_t snake = initSnake( 10, 5, 5);
	printSnake(snake);
	while(1)
	{
		key = getch(); 
		if ((key == 'w')||(key == 'W')||(key == 'a')||(key == 'A')||(key == 's')||(key == 'S')||(key == 'd')||(key == 'D'))
		{
			switch (key)
			{
			case 'a':
			case 'A':
				snake = moveLeft(snake);
				last_key = 'a';
				break;
			case 'w':
			case 'W':
				snake = moveUp(snake);
				last_key = 'w';
				break;
			case 'd':
			case 'D':
				snake = moveRight(snake);
				last_key = 'd';
				break;
			case 's':
			case 'S':
				snake = moveDown(snake);
				last_key = 's';
				break;
			default:
				break;
			}
		}
		else {  
			switch (last_key)
			{
			case 'a':
			case 'A':
				snake = moveLeft(snake);
				key = 'a';
				break;
			case 'w':
			case 'W':
				snake = moveUp(snake);
				key = 'w';
				break;
			case 'd':
			case 'D':
				snake = moveRight(snake);
				key = 'd';
				break;
			case 's':
			case 'S':
				snake = moveDown(snake);
				key = 's';
				break;
			default:
				break;
			}
		}
		system("cls");
		printSnake(snake);
		
	}
	return 0;
}