#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>


#define MAX_X 60
#define MAX_Y 30

/*Глобальная переменная для паузы*/
int PAUSE = 0;


/*Структура описывающая "хвост змейки" */
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

/*Структура описывающая змейку*/	
typedef struct snake_t{
	int x;
	int y;
	int score;
	struct tail_t * tail;
	size_t tsize;
	Direction direction;
}  snake_t;
 
/*Структура для еды*/
typedef struct food_t{
    int x;
    int y;
    int isEaten;
} food_t;

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
	snake.direction = LEFT;  //задали начальное движение
	return snake;
}

/*Ф-ция иниц. еды*/
food_t initFood(){
    food_t food;
    food.x = rand () % MAX_X;
    food.y = rand () % MAX_Y;
    food.isEaten = 0;
    return food;
}

/* Рисуем змейку вида: @** */
void printSnake(struct snake_t snake, struct snake_t snake2, food_t food){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i)
		{
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
			}
		}
		
        matrix[food.x][food.y] = 'Q';

		matrix[snake.x][snake.y] = '@';
		matrix[snake2.x][snake2.y] = '&';
        for(int i = 0; i < snake.tsize; ++i){
            matrix[snake.tail[i].x][snake.tail[i].y] = '*';
        }
		for(int i = 0; i < snake2.tsize; ++i){
            matrix[snake2.tail[i].x][snake2.tail[i].y] = '+';
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
	
/*Движение змейки*/
snake_t move(snake_t snake, food_t *food){
    for(int i = snake.tsize; i > 0; i--){
        snake.tail[i] = snake.tail[i-1];
    }

    snake.tail[0].x = snake.x;
    snake.tail[0].y = snake.y;

    switch (snake.direction)
    {
    case UP:
        snake.y = snake.y - 1;
        if (snake.y < 0){
            snake.y = MAX_Y - 1;
        }
        break;
    case DOWN:
        snake.y = snake.y + 1;
        if (snake.y == MAX_Y){
            snake.y = 0;
        }
        break;
    case LEFT:
        snake.x = snake.x - 1;
        if (snake.x < 0){
            snake.x = MAX_X - 1;
        }
        break;
    case RIGHT:
        snake.x = snake.x + 1;
        if (snake.x == MAX_X){
            snake.x = 0;
        }
        break;
    }
    if(snake.x == food -> x && snake.y == food -> y){
        food -> isEaten = 1;
        snake.tsize++;
		snake.score++;
    }
    return snake;
}

//для управления второй змейкой убрать комментарии ниже:
/*Ф-ция движения*/
void input(snake_t *snake){//, snake_t *snake2){
    if(_kbhit()){
        switch (_getch())
		{
			case 'a':
			case 'A':
                snake->direction = LEFT;
				break;
			case 'w':
			case 'W':
                snake->direction = UP;
				break;
    		case 'd':
			case 'D':
			    snake->direction = RIGHT;	
				break;
			case 's':
			case 'S':
				snake->direction = DOWN;
				break;
			case 'p':
			case 'P':
				PAUSE = 1;
				break;
			// case 'j':
			// case 'J':
            //     snake2->direction = LEFT;
			// 	break;
			// case 'i':
			// case 'I':
            //     snake2->direction = UP;
			// 	break;
    		// case 'l':
			// case 'L':
			//     snake2->direction = RIGHT;	
			// 	break;
			// case 'k':
			// case 'K':
			// 	snake2->direction = DOWN;
			// 	break;
        }
    }
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
}

/*Бот для второй змейки*/
void generateSnakeDirection(snake_t *snake, food_t food){
	if ((snake->direction == LEFT || snake->direction == RIGHT) && snake->y == food.y){
		return;
	}
	if ((snake->direction == LEFT || snake->direction == RIGHT) && snake->y != food.y){
		if (food.x == snake->x){
			if(abs(food.y - snake->y) <= MAX_Y/2)
			{
				snake->direction = food.y - snake->y > 0? DOWN:UP;
			} else {
				snake->direction = food.y - snake->y > 0? UP:DOWN;
			}
		}
		return;
	}
	if ((snake->direction == UP || snake->direction == DOWN) && snake->x == food.x){
		return;
	}
	if ((snake->direction == UP || snake->direction == DOWN) && snake->x != food.x){
		if (food.y == snake->y){
			if(abs(food.x - snake->x) <= MAX_X/2)
			{
				snake->direction = food.x - snake->x > 0? RIGHT:LEFT;
			} else {
				snake->direction = food.x - snake->x > 0? LEFT:RIGHT;
			}
		}
		return;
	}
}


int main(){
	int exit_while = 0, close = 0;
	char key_menu;
	
	struct snake_t snake = initSnake( 10, 5, 2);
	struct snake_t snake2 = initSnake( 15, 17, 2);
	snake.score = 0;
	snake2.score = 0;
	food_t food = initFood();
	printSnake(snake, snake2, food);
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
				input(&snake);//, &snake2);
                snake = move(snake, &food);
				snake2 = move(snake2, &food);
				generateSnakeDirection(&snake2, food);
                if(food.isEaten){
                    food = initFood();
                }
				if(PAUSE == 1){
					printf("Pause!\n Your score: %d\n Bot score: %d\n", snake.score, snake2.score);
					printf("Press P to continue or E to exit\n");
					while (PAUSE != 0)
					{
						if(_kbhit()){
        					switch (_getch()){
								case 'P':
								case 'p':
									PAUSE = 0;
									break;
								case 'e':
								case 'E':
									exit_while = 1;
									PAUSE = 0;
									break;
							}
						}
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
                printSnake(snake, snake2, food);
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