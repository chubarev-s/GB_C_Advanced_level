#include "config.h"

/*Ручное управление дроном*/
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
	if(snake.matrix_direct[snake.x][snake.y] == food -> isEaten[snake.x][snake.y]){
		food -> isEaten[snake.x][snake.y] = 1;
        snake.tsize++;
		snake.score++;
		all_eat++;
	}
    return snake;
}

/*Ф-ция движения*/
void input(snake_t *snake){
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
        }
    }
}
int k_1 = 2, k_2 = 2, flag = 0, s1_exit = 0;
int s2_1 = 0, s2_2 = 0, s2_flag = 0, s2_exit = 0;
int s3_1 = 0, s3_2 = 0, s3_flag = 0, s3_exit = 0;
int s4_1 = 0, s4_2 = 0, s4_flag = 0, s4_exit = 0;
int s5_1 = 0, s5_2 = 0, s5_flag = 0, s5_exit = 0;
/*Бот для дрона*/
void generateSnakeDirection(snake_t *snake, snake_t *snake2, snake_t *snake3, snake_t *snake4,snake_t *snake5, food_t food, int count_snake, int s1_auto_pil){
	if(s1_auto_pil == 1){
		
		if(count_snake == 1){
				//выезд из ангара:
			if(snake->y == (MAX_Y-1)){
				snake->direction = UP;
			}
			if(snake->y == (MAX_Y-3)){
				snake->direction = RIGHT;
			}
			//--------------------
			if(s1_exit == 0){
				if(snake->x == (SIZE_X-k_1)&&(flag == 0)){snake->direction = UP;}
				if((snake->y == 1)&&(snake->x == (SIZE_X-k_1))){snake->direction = LEFT; k_2++; flag = 1;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == 1)&&(flag == 1)){snake->direction = DOWN; k_1++;}
				if((snake->y == (SIZE_Y-1))&&(snake->x == (SIZE_X-k_1))&&(flag == 1)){snake->direction = LEFT;k_2++;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == (SIZE_Y-1))&&(flag == 1)){snake->direction = UP;k_1++;}
				if(k_1 == SIZE_X){k_1 = k_2 = 2; flag = 0; s1_exit = 1;}
			} else {
				if(snake->y > (SIZE_Y)){
					if((snake->x < (SIZE_X))){snake->direction = LEFT;}
					if(snake->x == 0){snake->direction = DOWN;}
				}
				if((snake->x == 0)&&(snake->y == (SIZE_Y))){snake->tsize = 0; s1_exit = 0;}
			}
		}
		if(count_snake == 2){
				//выезд из ангара:
			if(snake->y == (MAX_Y-1)){
				snake->direction = UP;
			}
			if(snake->y == (MAX_Y-3)){
				snake->direction = RIGHT;
			}
			if(snake2->y == (MAX_Y-1)){
				snake2->direction = UP;
			}
			if(snake2->y == (MAX_Y-2)){
				snake2->direction = RIGHT;
			}
			//--------------------
			if(s1_exit == 0){
				if(snake->x == (SIZE_X-k_1)&&(flag == 0)){snake->direction = UP;}
				if((snake->y == 1)&&(snake->x == (SIZE_X-k_1))){snake->direction = LEFT; k_2++; flag = 1;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == 1)&&(flag == 1)){snake->direction = DOWN; k_1++;}
				if((snake->y == (SIZE_Y-1))&&(snake->x == (SIZE_X-k_1))&&(flag == 1)){snake->direction = LEFT;k_2++;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == (SIZE_Y-1))&&(flag == 1)){snake->direction = UP;k_1++;}
				if(k_1 == TWO_DRONE+1){k_1 = k_2 = 2; flag = 0; s1_exit = 1;}
			} else {
				if(snake->y > (SIZE_Y)){
					if((snake->x < (SIZE_X))){snake->direction = LEFT;}
					if(snake->x == 0){snake->direction = DOWN;}
				}
				if((snake->x == 0)&&(snake->y == (SIZE_Y))){snake->tsize = 0; s1_exit = 0;}
			}
			//--------------------
			if(s2_exit == 0){
				if(snake2->x == (TWO_DRONE-s2_1)&&(s2_flag == 0)){snake2->direction = UP;}
				if((snake2->y == 1)&&(snake2->x == (TWO_DRONE-s2_1))){snake2->direction = LEFT; s2_2++; s2_flag = 1;}
				if((snake2->x == (TWO_DRONE-s2_2))&&(snake2->y == 1)&&(s2_flag == 1)){snake2->direction = DOWN; s2_1++;}
				if((snake2->y == (SIZE_Y-1))&&(snake2->x == (TWO_DRONE-s2_1))&&(s2_flag == 1)){snake2->direction = LEFT;s2_2++;}
				if((snake2->x == (TWO_DRONE-s2_2))&&(snake2->y == (SIZE_Y-1))&&(s2_flag == 1)){snake2->direction = UP;s2_1++;}
				if(s2_1 == (TWO_DRONE - 1)){s2_1 = s2_2 = 2; s2_flag = 0; s2_exit = 1;}
			} else {
				if(snake2->y > (SIZE_Y)){
					if((snake2->x < (SIZE_X))){snake2->direction = LEFT;}
					if(snake2->x == 0){snake2->direction = DOWN;}
				}
				if((snake2->x == 0)&&(snake2->y == (SIZE_Y))){snake2->tsize = 0; s2_exit = 0;}
			}
		}
		if(count_snake == 3){
				//выезд из ангара:
			if(snake->y == (MAX_Y-1)){
				snake->direction = UP;
			}
			if(snake->y == (MAX_Y-4)){
				snake->direction = RIGHT;
			}
			if(snake2->y == (MAX_Y-1)){
				snake2->direction = UP;
			}
			if(snake2->y == (MAX_Y-3)){
				snake2->direction = RIGHT;
			}
			if(snake3->y == (MAX_Y-1)){
				snake3->direction = UP;
			}
			if(snake3->y == (MAX_Y-2)){
				snake3->direction = RIGHT;
			}
			//--------------------
			if(s1_exit == 0){
				if(snake->x == (SIZE_X-k_1)&&(flag == 0)){snake->direction = UP;}
				if((snake->y == 1)&&(snake->x == (SIZE_X-k_1))){snake->direction = LEFT; k_2++; flag = 1;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == 1)&&(flag == 1)){snake->direction = DOWN; k_1++;}
				if((snake->y == (SIZE_Y-1))&&(snake->x == (SIZE_X-k_1))&&(flag == 1)){snake->direction = LEFT;k_2++;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == (SIZE_Y-1))&&(flag == 1)){snake->direction = UP;k_1++;}
				if(k_1 == (THREE_DRONE+2)){k_1 = k_2 = 2; flag = 0; s1_exit = 1;}
			} else {
				if(snake->y > (SIZE_Y)){
					if((snake->x < (SIZE_X))){snake->direction = LEFT;}
					if(snake->x == 0){snake->direction = DOWN;}
				}
				if((snake->x == 0)&&(snake->y == (SIZE_Y))){snake->tsize = 0; s1_exit = 0;}
			}
			//--------------------
			if(s2_exit == 0){
				if(snake2->x == (2*THREE_DRONE-s2_1)&&(s2_flag == 0)){snake2->direction = UP;}
				if((snake2->y == 1)&&(snake2->x == (2*THREE_DRONE-s2_1))){snake2->direction = LEFT; s2_2++; s2_flag = 1;}
				if((snake2->x == (2*THREE_DRONE-s2_2))&&(snake2->y == 1)&&(s2_flag == 1)){snake2->direction = DOWN; s2_1++;}
				if((snake2->y == (SIZE_Y-1))&&(snake2->x == (2*THREE_DRONE-s2_1))&&(s2_flag == 1)){snake2->direction = LEFT;s2_2++;}
				if((snake2->x == (2*THREE_DRONE-s2_2))&&(snake2->y == (SIZE_Y-1))&&(s2_flag == 1)){snake2->direction = UP;s2_1++;}
				if(s2_1 == (THREE_DRONE)){s2_1 = s2_2 = 0; s2_flag = 0; s2_exit = 1;}
			} else {
				if(snake2->y > (SIZE_Y)){
					if((snake2->x < (SIZE_X))){snake2->direction = LEFT;}
					if(snake2->x == 0){snake2->direction = DOWN;}
				}
				if((snake2->x == 0)&&(snake2->y == (SIZE_Y))){snake2->tsize = 0; s2_exit = 0;}
			}
			if(s3_exit == 0){
				if(snake3->x == (THREE_DRONE-s3_1)&&(s3_flag == 0)){snake3->direction = UP;}
				if((snake3->y == 1)&&(snake3->x == (THREE_DRONE-s3_1))){snake3->direction = LEFT; s3_2++; s3_flag = 1;}
				if((snake3->x == (THREE_DRONE-s3_2))&&(snake3->y == 1)&&(s3_flag == 1)){snake3->direction = DOWN; s3_1++;}
				if((snake3->y == (SIZE_Y-1))&&(snake3->x == (THREE_DRONE-s3_1))&&(s3_flag == 1)){snake3->direction = LEFT;s3_2++;}
				if((snake3->x == (THREE_DRONE-s3_2))&&(snake3->y == (SIZE_Y-1))&&(s3_flag == 1)){snake3->direction = UP;s3_1++;}
				if(s3_1 == (THREE_DRONE - 1)){s3_1 = s3_2 = 0; s3_flag = 0; s3_exit = 1;}
			} else {
				if(snake3->y > (SIZE_Y)){
					if((snake3->x < (SIZE_X))){snake3->direction = LEFT;}
					if(snake3->x == 0){snake3->direction = DOWN;}
				}
				if((snake3->x == 0)&&(snake3->y == (SIZE_Y))){snake3->tsize = 0; s3_exit = 0;}
			}
		}
		if(count_snake == 4){
				//выезд из ангара:
			if(snake->y == (MAX_Y-1)){
				snake->direction = UP;
			}
			if(snake->y == (MAX_Y-5)){
				snake->direction = RIGHT;
			}
			if(snake2->y == (MAX_Y-1)){
				snake2->direction = UP;
			}
			if(snake2->y == (MAX_Y-4)){
				snake2->direction = RIGHT;
			}
			if(snake3->y == (MAX_Y-1)){
				snake3->direction = UP;
			}
			if(snake3->y == (MAX_Y-3)){
				snake3->direction = RIGHT;
			}
			if(snake4->y == (MAX_Y-1)){
				snake4->direction = UP;
			}
			if(snake4->y == (MAX_Y-2)){
				snake4->direction = RIGHT;
			}
			//--------------------
			if(s1_exit == 0){
				if(snake->x == (SIZE_X-k_1)&&(flag == 0)){snake->direction = UP;}
				if((snake->y == 1)&&(snake->x == (SIZE_X-k_1))){snake->direction = LEFT; k_2++; flag = 1;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == 1)&&(flag == 1)){snake->direction = DOWN; k_1++;}
				if((snake->y == (SIZE_Y-1))&&(snake->x == (SIZE_X-k_1))&&(flag == 1)){snake->direction = LEFT;k_2++;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == (SIZE_Y-1))&&(flag == 1)){snake->direction = UP;k_1++;}
				if(k_1 == (FOUR_DRONE+3)){k_1 = k_2 = 2; flag = 0; s1_exit = 1;}
			} else {
				if(snake->y > (SIZE_Y)){
					if((snake->x < (SIZE_X))){snake->direction = LEFT;}
					if(snake->x == 0){snake->direction = DOWN;}
				}
				if((snake->x == 0)&&(snake->y == (SIZE_Y))){snake->tsize = 0; s1_exit = 0;}
			}
			//--------------------
			if(s2_exit == 0){
				if(snake2->x == (3*FOUR_DRONE-s2_1)&&(s2_flag == 0)){snake2->direction = UP;}
				if((snake2->y == 1)&&(snake2->x == (3*FOUR_DRONE-s2_1))){snake2->direction = LEFT; s2_2++; s2_flag = 1;}
				if((snake2->x == (3*FOUR_DRONE-s2_2))&&(snake2->y == 1)&&(s2_flag == 1)){snake2->direction = DOWN; s2_1++;}
				if((snake2->y == (SIZE_Y-1))&&(snake2->x == (3*FOUR_DRONE-s2_1))&&(s2_flag == 1)){snake2->direction = LEFT;s2_2++;}
				if((snake2->x == (3*FOUR_DRONE-s2_2))&&(snake2->y == (SIZE_Y-1))&&(s2_flag == 1)){snake2->direction = UP;s2_1++;}
				if(s2_1 == (FOUR_DRONE+1)){s2_1 = s2_2 = 0; s2_flag = 0; s2_exit = 1;}
			} else {
				if(snake2->y > (SIZE_Y)){
					if((snake2->x < (SIZE_X))){snake2->direction = LEFT;}
					if(snake2->x == 0){snake2->direction = DOWN;}
				}
				if((snake2->x == 0)&&(snake2->y == (SIZE_Y))){snake2->tsize = 0; s2_exit = 0;}
			}
			if(s3_exit == 0){
				if(snake3->x == (2*FOUR_DRONE-s3_1)&&(s3_flag == 0)){snake3->direction = UP;}
				if((snake3->y == 1)&&(snake3->x == (2*FOUR_DRONE-s3_1))){snake3->direction = LEFT; s3_2++; s3_flag = 1;}
				if((snake3->x == (2*FOUR_DRONE-s3_2))&&(snake3->y == 1)&&(s3_flag == 1)){snake3->direction = DOWN; s3_1++;}
				if((snake3->y == (SIZE_Y-1))&&(snake3->x == (2*FOUR_DRONE-s3_1))&&(s3_flag == 1)){snake3->direction = LEFT;s3_2++;}
				if((snake3->x == (2*FOUR_DRONE-s3_2))&&(snake3->y == (SIZE_Y-1))&&(s3_flag == 1)){snake3->direction = UP;s3_1++;}
				if(s3_1 == (FOUR_DRONE+1)){s3_1 = s3_2 = 0; s3_flag = 0; s3_exit = 1;}
			} else {
				if(snake3->y > (SIZE_Y)){
					if((snake3->x < (SIZE_X))){snake3->direction = LEFT;}
					if(snake3->x == 0){snake3->direction = DOWN;}
				}
				if((snake3->x == 0)&&(snake3->y == (SIZE_Y))){snake3->tsize = 0; s3_exit = 0;}
			}
			if(s4_exit == 0){
				if(snake4->x == (FOUR_DRONE-s4_1)&&(s4_flag == 0)){snake4->direction = UP;}
				if((snake4->y == 1)&&(snake4->x == (FOUR_DRONE-s4_1))){snake4->direction = LEFT; s4_2++; s4_flag = 1;}
				if((snake4->x == (FOUR_DRONE-s4_2))&&(snake4->y == 1)&&(s4_flag == 1)){snake4->direction = DOWN; s4_1++;}
				if((snake4->y == (SIZE_Y-1))&&(snake4->x == (FOUR_DRONE-s4_1))&&(s4_flag == 1)){snake4->direction = LEFT;s4_2++;}
				if((snake4->x == (FOUR_DRONE-s4_2))&&(snake4->y == (SIZE_Y-1))&&(s4_flag == 1)){snake4->direction = UP;s4_1++;}
				if(s4_1 == (FOUR_DRONE - 1)){s4_1 = s4_2 = 0; s4_flag = 0; s4_exit = 1;}
			} else {
				if(snake4->y > (SIZE_Y)){
					if((snake4->x < (SIZE_X))){snake4->direction = LEFT;}
					if(snake4->x == 0){snake4->direction = DOWN;}
				}
				if((snake4->x == 0)&&(snake4->y == (SIZE_Y))){snake4->tsize = 0; s4_exit = 0;}
			}
		}
		if(count_snake == 5){
				//выезд из ангара:
			if(snake->y == (MAX_Y-1)){
				snake->direction = UP;
			}
			if(snake->y == (MAX_Y-6)){
				snake->direction = RIGHT;
			}
			if(snake2->y == (MAX_Y-1)){
				snake2->direction = UP;
			}
			if(snake2->y == (MAX_Y-5)){
				snake2->direction = RIGHT;
			}
			if(snake3->y == (MAX_Y-1)){
				snake3->direction = UP;
			}
			if(snake3->y == (MAX_Y-4)){
				snake3->direction = RIGHT;
			}
			if(snake4->y == (MAX_Y-1)){
				snake4->direction = UP;
			}
			if(snake4->y == (MAX_Y-3)){
				snake4->direction = RIGHT;
			}
			if(snake5->y == (MAX_Y-1)){
				snake5->direction = UP;
			}
			if(snake5->y == (MAX_Y-2)){
				snake5->direction = RIGHT;
			}
			//--------------------
			if(s1_exit == 0){
				if(snake->x == (SIZE_X-k_1)&&(flag == 0)){snake->direction = UP;}
				if((snake->y == 1)&&(snake->x == (SIZE_X-k_1))){snake->direction = LEFT; k_2++; flag = 1;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == 1)&&(flag == 1)){snake->direction = DOWN; k_1++;}
				if((snake->y == (SIZE_Y-1))&&(snake->x == (SIZE_X-k_1))&&(flag == 1)){snake->direction = LEFT;k_2++;}
				if((snake->x == (SIZE_X-k_2))&&(snake->y == (SIZE_Y-1))&&(flag == 1)){snake->direction = UP;k_1++;}
				if(k_1 == (FIVE_DRONE+4)){k_1 = k_2 = 2; flag = 0; s1_exit = 1;}
			} else {
				if(snake->y > (SIZE_Y)){
					if((snake->x < (SIZE_X))){snake->direction = LEFT;}
					if(snake->x == 0){snake->direction = DOWN;}
				}
				if((snake->x == 0)&&(snake->y == (SIZE_Y))){snake->tsize = 0; s1_exit = 0;}
			}
			//--------------------
			if(s2_exit == 0){
				if(snake2->x == (4*FIVE_DRONE-s2_1)&&(s2_flag == 0)){snake2->direction = UP;}
				if((snake2->y == 1)&&(snake2->x == (4*FIVE_DRONE-s2_1))){snake2->direction = LEFT; s2_2++; s2_flag = 1;}
				if((snake2->x == (4*FIVE_DRONE-s2_2))&&(snake2->y == 1)&&(s2_flag == 1)){snake2->direction = DOWN; s2_1++;}
				if((snake2->y == (SIZE_Y-1))&&(snake2->x == (4*FIVE_DRONE-s2_1))&&(s2_flag == 1)){snake2->direction = LEFT;s2_2++;}
				if((snake2->x == (4*FIVE_DRONE-s2_2))&&(snake2->y == (SIZE_Y-1))&&(s2_flag == 1)){snake2->direction = UP;s2_1++;}
				if(s2_1 == (FIVE_DRONE+1)){s2_1 = s2_2 = 0; s2_flag = 0; s2_exit = 1;}
			} else {
				if(snake2->y > (SIZE_Y)){
					if((snake2->x < (SIZE_X))){snake2->direction = LEFT;}
					if(snake2->x == 0){snake2->direction = DOWN;}
				}
				if((snake2->x == 0)&&(snake2->y == (SIZE_Y))){snake2->tsize = 0; s2_exit = 0;}
			}
			if(s3_exit == 0){
				if(snake3->x == (3*FIVE_DRONE-s3_1)&&(s3_flag == 0)){snake3->direction = UP;}
				if((snake3->y == 1)&&(snake3->x == (3*FIVE_DRONE-s3_1))){snake3->direction = LEFT; s3_2++; s3_flag = 1;}
				if((snake3->x == (3*FIVE_DRONE-s3_2))&&(snake3->y == 1)&&(s3_flag == 1)){snake3->direction = DOWN; s3_1++;}
				if((snake3->y == (SIZE_Y-1))&&(snake3->x == (3*FIVE_DRONE-s3_1))&&(s3_flag == 1)){snake3->direction = LEFT;s3_2++;}
				if((snake3->x == (3*FIVE_DRONE-s3_2))&&(snake3->y == (SIZE_Y-1))&&(s3_flag == 1)){snake3->direction = UP;s3_1++;}
				if(s3_1 == (FIVE_DRONE+1)){s3_1 = s3_2 = 0; s3_flag = 0; s3_exit = 1;}
			} else {
				if(snake3->y > (SIZE_Y)){
					if((snake3->x < (SIZE_X))){snake3->direction = LEFT;}
					if(snake3->x == 0){snake3->direction = DOWN;}
				}
				if((snake3->x == 0)&&(snake3->y == (SIZE_Y))){snake3->tsize = 0; s3_exit = 0;}
			}
			if(s4_exit == 0){
				if(snake4->x == (2*FIVE_DRONE-s4_1)&&(s4_flag == 0)){snake4->direction = UP;}
				if((snake4->y == 1)&&(snake4->x == (2*FIVE_DRONE-s4_1))){snake4->direction = LEFT; s4_2++; s4_flag = 1;}
				if((snake4->x == (2*FIVE_DRONE-s4_2))&&(snake4->y == 1)&&(s4_flag == 1)){snake4->direction = DOWN; s4_1++;}
				if((snake4->y == (SIZE_Y-1))&&(snake4->x == (2*FIVE_DRONE-s4_1))&&(s4_flag == 1)){snake4->direction = LEFT;s4_2++;}
				if((snake4->x == (2*FIVE_DRONE-s4_2))&&(snake4->y == (SIZE_Y-1))&&(s4_flag == 1)){snake4->direction = UP;s4_1++;}
				if(s4_1 == (FIVE_DRONE)){s4_1 = s4_2 = 0; s4_flag = 0; s4_exit = 1;}
			} else {
				if(snake4->y > (SIZE_Y)){
					if((snake4->x < (SIZE_X))){snake4->direction = LEFT;}
					if(snake4->x == 0){snake4->direction = DOWN;}
				}
				if((snake4->x == 0)&&(snake4->y == (SIZE_Y))){snake4->tsize = 0; s4_exit = 0;}
			}
			if(s5_exit == 0){
				if(snake5->x == (FIVE_DRONE-s5_1)&&(s5_flag == 0)){snake5->direction = UP;}
				if((snake5->y == 1)&&(snake5->x == (FIVE_DRONE-s5_1))){snake5->direction = LEFT; s5_2++; s5_flag = 1;}
				if((snake5->x == (FIVE_DRONE-s5_2))&&(snake5->y == 1)&&(s5_flag == 1)){snake5->direction = DOWN; s5_1++;}
				if((snake5->y == (SIZE_Y-1))&&(snake5->x == (FIVE_DRONE-s5_1))&&(s5_flag == 1)){snake5->direction = LEFT;s5_2++;}
				if((snake5->x == (FIVE_DRONE-s5_2))&&(snake5->y == (SIZE_Y-1))&&(s5_flag == 1)){snake5->direction = UP;s5_1++;}
				if(s5_1 == (FIVE_DRONE - 1)){s5_1 = s5_2 = 0; s5_flag = 0; s5_exit = 1;}
			} else {
				if(snake5->y > (SIZE_Y)){
					if((snake5->x < (SIZE_X))){snake5->direction = LEFT;}
					if(snake5->x == 0){snake5->direction = DOWN;}
				}
				if((snake5->x == 0)&&(snake5->y == (SIZE_Y))){snake5->tsize = 0; s5_exit = 0;}
			}
		}
	}
}