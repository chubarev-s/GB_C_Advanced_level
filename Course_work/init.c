#include "config.h"

/*Ф-ция инициализации дрона */
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
	snake.direction = LEFT;  //задали начальное движение
	for (int i = 0; i < SIZE_X; ++i)
		{
			for (int j = 0; j < SIZE_Y; ++j)
			{
				snake.matrix_direct[i][j] = 0;
			}
		}
	return snake;
}

/*Ф-ция рандома*/
int getRandomNumber(int min, int max) {
 	return min + rand() % (max - min +1);
}

/*Ф-ция иниц. тыкв*/
food_t initFood(){
    food_t food;
	for (int i = 0; i < SIZE_X; ++i)
		{
			for (int j = 0; j < SIZE_Y; ++j)
			{
				food.isEaten[i][j] = 1;
			}
		}
	for(int i = 0; i < COUNT_XY; i++){
		food.x[i] = 0;
		food.y[i] = 0;
	}
	food.count_food = getRandomNumber(3, 10);//(COUNT_XY - 1));
	for (int i = 0; i < food.count_food; i++)
	{
		food.x[i] = getRandomNumber(1, (SIZE_X - 1));
		food.y[i] = getRandomNumber(1, (SIZE_Y - 1));
    	if(food.isEaten[food.x[i]][food.y[i]] == 1)
			{
				food.isEaten[food.x[i]][food.y[i]] = 0;
			}
	}
    return food;
}

/* Рисуем дрон */
void printSnake(struct snake_t snake, struct snake_t snake2, struct snake_t snake3,
                        struct snake_t snake4, struct snake_t snake5, food_t food, int count_drons){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i)
		{
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
			}
		}
		
		for (int i = 0; i < SIZE_X; ++i)
		{
			for (int j = 0; j < SIZE_Y; ++j)
			{
				if(food.isEaten[i][j] == 0){
						matrix[i][j] = 'o';
				}
				else {
						matrix[i][j] = ' ';
				}

			}
		}
		 for (int i = 0; i < MAX_X; ++i){
            matrix[i][SIZE_Y] = '^';
			matrix[i][0] = '#';
        }
		for (int i = 1; i < SIZE_Y; ++i){
            matrix[0][i] = '#';
			matrix[MAX_X-1][i] = '#';
        }
		for(int i = 0; i < 10; i++){
			 matrix[i][MAX_Y-6] = '^';
		}
		for(int i = (MAX_Y-1); i > (MAX_Y-6); --i){
			 matrix[9][i] = '^';
		}

		/*Для отрисовки самих дронов, сделал костыль, из-за ограниченности свободного времени, так проще :)*/
		switch (count_drons)
		{
		case 1:
			matrix[snake.x][snake.y] = '@';
			for(int i = 0; i < snake.tsize; ++i){
				if((snake.x == snake.tail[i].x)&&(snake.y == snake.tail[i].y))
				{	PAUSE = 1; 
					count_drons = 0; 
					printf("The drone is broken, press the E button to reboot!\n\n\n\n");
					break;
				}
				matrix[snake.tail[i].x][snake.tail[i].y] = '+';
			}
			break;
		
		case 2:
			matrix[snake.x][snake.y] = '@';
        	matrix[snake2.x][snake2.y] = '%';
			for(int i = 0; i < snake.tsize; ++i){
            	if((snake.x == snake.tail[i].x)&&(snake.y == snake.tail[i].y))
				{	PAUSE = 1; 
					count_drons = 0; 
					printf("The drone is broken, press the E button to reboot!\n\n\n\n");
					break;
				}
				matrix[snake.tail[i].x][snake.tail[i].y] = '+';
			}
			for(int i = 0; i < snake2.tsize; ++i){
				matrix[snake2.tail[i].x][snake2.tail[i].y] = '*';
			}
			break;

		case 3:
			matrix[snake.x][snake.y] = '@';
			matrix[snake2.x][snake2.y] = '%';
			matrix[snake3.x][snake3.y] = '&';
			for(int i = 0; i < snake.tsize; ++i){
            	if((snake.x == snake.tail[i].x)&&(snake.y == snake.tail[i].y))
				{	PAUSE = 1; 
					count_drons = 0; 
					printf("The drone is broken, press the E button to reboot!\n\n\n\n");
					break;
				}
				matrix[snake.tail[i].x][snake.tail[i].y] = '+';
			}
			for(int i = 0; i < snake2.tsize; ++i){
				matrix[snake2.tail[i].x][snake2.tail[i].y] = '*';
			}
			for(int i = 0; i < snake3.tsize; ++i){
				matrix[snake3.tail[i].x][snake3.tail[i].y] = 'C';
			}
			break;
		
		case 4:
			matrix[snake.x][snake.y] = '@';
			matrix[snake2.x][snake2.y] = '%';
			matrix[snake3.x][snake3.y] = '&';
			matrix[snake4.x][snake4.y] = '~';
			for(int i = 0; i < snake.tsize; ++i){
            	if((snake.x == snake.tail[i].x)&&(snake.y == snake.tail[i].y))
				{	PAUSE = 1; 
					count_drons = 0; 
					printf("The drone is broken, press the E button to reboot!\n\n\n\n");
					break;
				}
				matrix[snake.tail[i].x][snake.tail[i].y] = '+';
			}
			for(int i = 0; i < snake2.tsize; ++i){
				matrix[snake2.tail[i].x][snake2.tail[i].y] = '*';
			}
			for(int i = 0; i < snake3.tsize; ++i){
				matrix[snake3.tail[i].x][snake3.tail[i].y] = 'C';
			}
			for(int i = 0; i < snake4.tsize; ++i){
				matrix[snake4.tail[i].x][snake4.tail[i].y] = '=';
			}
			break;
		
		case 5:
			matrix[snake.x][snake.y] = '@';
			matrix[snake2.x][snake2.y] = '%';
			matrix[snake3.x][snake3.y] = '&';
			matrix[snake4.x][snake4.y] = '~';
			matrix[snake5.x][snake5.y] = 'Q';
			for(int i = 0; i < snake.tsize; ++i){
				if((snake.x == snake.tail[i].x)&&(snake.y == snake.tail[i].y))
				{	PAUSE = 1; 
					count_drons = 0; 
					printf("The drone is broken, press the E button to reboot!\n\n\n\n");
					break;
				}
				matrix[snake.tail[i].x][snake.tail[i].y] = '+';
			}
			for(int i = 0; i < snake2.tsize; ++i){
				matrix[snake2.tail[i].x][snake2.tail[i].y] = '*';
			}
			for(int i = 0; i < snake3.tsize; ++i){
				matrix[snake3.tail[i].x][snake3.tail[i].y] = 'C';
			}
			for(int i = 0; i < snake4.tsize; ++i){
				matrix[snake4.tail[i].x][snake4.tail[i].y] = '=';
			}
			for(int i = 0; i < snake5.tsize; ++i){
				matrix[snake5.tail[i].x][snake5.tail[i].y] = 'D';
			}
			break;
		}
		
		for (int j = 0; j < MAX_Y; ++j)
		{
			for (int i = 0; i < MAX_X; ++i)
			{
				printf("%c", matrix[i][j]);
			}
            printf("\n");
		}
}