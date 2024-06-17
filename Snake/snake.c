#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>


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
	int score;
	int eat;
	int food_x; 
	int food_y;
	struct tail_t * tail;
	size_t tsize;
}  snake_t;

/*Ф-ция возвращающая структуру змейки */
struct snake_t initSnake(int x, int y, size_t tsize){
	struct snake_t snake;
	snake.x = x;
	snake.y = y;
	snake.tsize = tsize;
	snake.eat = 0;
	snake.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		snake.tail[i].x = x + i +1;
		snake.tail[i].y = y;
		}
	return snake;
}

/*задаём функцию случайной генерации чисел*/
int getRandomNumber(int min, int max) {
 	return min + rand() % (max - min +1);
}
	
/*Функция инициализации символа "Q", еды*/
void initFoodPosition(snake_t *snake) {
	snake->food_x = getRandomNumber(0, (MAX_X-1));
	snake->food_y = getRandomNumber(0, (MAX_Y-1));
}

/* Рисуем змейку вида: @** */
uint8_t printSnake(struct snake_t *snake){
		char matrix[MAX_X][MAX_Y];
		uint8_t ex_w = 0, r_x = 0, r_y = 0;
		for (int i = 0; i < MAX_X; ++i)
		{
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
			}
		}
		
		for (int i = 0; i < snake->tsize; ++i)
		{
			matrix[snake->tail[i].x][snake->tail[i].y] = '*';
		}
		
		matrix[snake->food_x][snake->food_y] = 'Q'; 

		switch (matrix[snake->x][snake->y])
		{
			case ' ':
				matrix[snake->x][snake->y] = '@'; 
				for (int j = 0; j < MAX_Y; ++j)
				{
					for (int i = 0; i < MAX_X; ++i)
					{
						printf("%c", matrix[i][j]);
					}
					printf("\n");
				}
				break;
			case '*':
				printExit(snake);
				return 1;
				break;
			case 'Q':
				snake->tsize = snake->tsize + 1;
				snake->score = snake->score + 1;
				matrix[snake->food_x][snake->food_y] = ' ';
				matrix[snake->x][snake->y] = '@';
				for (int j = 0; j < MAX_Y; ++j)
				{
					for (int i = 0; i < MAX_X; ++i)
					{
						printf("%c", matrix[i][j]);
					}
					printf("\n");
				}
				snake->eat = 0;
				initFoodPosition(snake); // Генерируем новое положение символа "Q"
				break;
			default:
				printf("error, %c", matrix[snake->x][snake->y]);
				break;
		}
		return 0;
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


/*Функция выхода*/
void printExit(snake_t *head){
	char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i)
		{
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
			}
		}
	
	printf("GAME OWER! Your score %d\n", head->score);
	*head = initSnake( 10, 5, 5);
	printSnake(head);
}

int main(){
	int a = 0, exit_while = 0, close = 0;
	char key, last_key = 'a', key_menu;
	struct snake_t snake = initSnake( 10, 5, 1);
	snake.score = 0;
	initFoodPosition(&snake);
	printSnake(&snake);
	while (close != 1)
	{
		printf("1. Start game\n");
		printf("2. Exit\n");
		key_menu = getch();
		switch (key_menu)
		{
		case '1':
			exit_while = 0;
			while(exit_while != 1)
			{
				if(kbhit())
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
				}
				else if(key == 'p'){
					printf("Pause\nYour score: %d\nClick any key for contine or \"e\" for exit\n", snake.score);
					key = getch();
					if(key == 'e')
						exit_while = 1;
				}else 
					{  
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
				if(snake.score < 4){
					usleep(400000);
				}
				if((snake.score >= 4)&&(snake.score < 7)){
					usleep(250000);
				}
				if((snake.score >= 7)&&(snake.score < 10)){
					usleep(100000);
				}
				if(snake.score >= 10){
					usleep(50000);
				}
				system("cls");
				if(exit_while !=1 )
				{
					exit_while = printSnake(&snake);
				}
			}
			break;
		case '2':
			close = 1;
		default:
			break;
		}
		
	}
	return 0;
}