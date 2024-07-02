#include "config.h"
int PAUSE = 0;
int all_eat = 0;
int main(){
	int exit_while = 0, close = 0, count_drons = 1, while_drons = 0;
	char key_menu, drons;
    PAUSE = 0;
	struct snake_t snake  = initSnake( 1, MAX_Y-1, 0);
	struct snake_t snake2 = initSnake( 2, MAX_Y-1, 0);
    struct snake_t snake3 = initSnake( 3, MAX_Y-1, 0);
	struct snake_t snake4 = initSnake( 4, MAX_Y-1, 0);
    struct snake_t snake5 = initSnake( 5, MAX_Y-1, 0);
	snake.score = 0;
	snake2.score = 0;
    snake3.score = 0;
    snake4.score = 0;
    snake5.score = 0;
	food_t food = initFood();
	while (close != 1)
	{
		printf("1. Start game\n");
		printf("2. Exit\n");
		key_menu = getch();
		switch (key_menu)
		{
		case '1':
			exit_while = 0;
			printf("Select the number of drones from 1 to 5: ");
			while(while_drons != 1){
				if(_kbhit()){
					switch (_getch()){
						case '1':
							count_drons = 1;
							while_drons = 1;
							break;
						case '2':
							count_drons = 2;
							while_drons = 1;
							break;
						case '3':
							count_drons = 3;
							while_drons = 1;
							break;
						case '4':
							count_drons = 4;
							while_drons = 1;
							break;
						case '5':
							count_drons = 5;
							while_drons = 1;
							break;
					}
				}
			}
			while_drons = 0;
			printSnake(snake, snake2, snake3, snake4, snake5, food, count_drons);
			while(exit_while != 1)
			{
				input(&snake);
                snake = move(snake, &food);
				//generateSnakeDirection(&snake, &snake2, &snake3, &snake4, &snake5, food, count_drons, 1);
				if(count_drons > 1)
				{
					snake2 = move(snake2, &food);
					//generateSnakeDirection(&snake2, food);
					
					if(count_drons > 2){
						snake3 = move(snake3, &food);
						//generateSnakeDirection(&snake3, food);
						
						if(count_drons > 3){
							snake4 = move(snake4, &food);
							//generateSnakeDirection(&snake4, food);
							
							if(count_drons > 4){
								snake5 = move(snake5, &food);
								//generateSnakeDirection(&snake5, food);
							}
						}
					}
				}
				generateSnakeDirection(&snake, &snake2, &snake3, &snake4, &snake5, food, count_drons, 1);
                if(all_eat == food.count_food){
                    food = initFood();
					all_eat = 0;
                }
				if(PAUSE == 1){
					printf("Pause!\n"); 
                    printf("Pumpkins collected by the first drone: %d\n", snake.score);
					if(count_drons > 1){
							printf("Pumpkins collected by the second drone: %d\n", snake2.score);
						if(count_drons > 2){
								printf("Pumpkins collected by the third drone: %d\n", snake3.score);
							if(count_drons > 3){
									printf("Pumpkins collected by the fourth drone: %d\n", snake4.score);
								if(count_drons > 4){
									printf("Pumpkins collected by the fifth drone: %d\n", snake5.score);
								}
							}
						}
					}
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
									count_drons = 0;
									break;
							}
						}
					}
					
				}
                usleep(200);
				system("cls");
                printSnake(snake, snake2, snake3, snake4, snake5, food, count_drons);
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