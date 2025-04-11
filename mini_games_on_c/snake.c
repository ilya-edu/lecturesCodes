//Собрать через: gcc snake.c -o snake -lncurses
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define INITIAL_SNAKE_LENGTH 3

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[WIDTH * HEIGHT];
    int length;
    char direction;
} Snake;

void init_game(Snake *snake, Point *food, int *score);
void draw_game(Snake *snake, Point *food, int score);
void move_snake(Snake *snake, Point *food, int *score, int *game_over);
int check_collision(Snake *snake);
void generate_food(Point *food, Snake *snake);

int main() {
    Snake snake;
    Point food;
    int score, game_over = 0;
    
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    
    init_game(&snake, &food, &score);
    
    while (1) {
        clear();
        draw_game(&snake, &food, score);
        move_snake(&snake, &food, &score, &game_over);
        refresh();
        napms(100);
        
        if (game_over) {
            mvprintw(HEIGHT / 2, WIDTH / 2 - 4, "Game Over!");
            mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 10, "Press ENTER to restart");
            mvprintw(HEIGHT / 2 + 2, WIDTH / 2 - 10, "Any key to exit");
            timeout(-1);
            int ch = getch();
            if (ch == '\n') {
                init_game(&snake, &food, &score);
                game_over = 0;
                nodelay(stdscr, TRUE);
            } else {
                break;
            }
        }
    }
    
    endwin();
    return 0;
}

void init_game(Snake *snake, Point *food, int *score) {
    snake->length = INITIAL_SNAKE_LENGTH;
    snake->direction = 'R';
    for (int i = 0; i < snake->length; i++) {
        snake->body[i].x = WIDTH / 2 - i;
        snake->body[i].y = HEIGHT / 2;
    }
    *score = 0;
    generate_food(food, snake);
}

void draw_game(Snake *snake, Point *food, int score) {
    for (int i = 0; i < WIDTH + 2; i++) {
        mvprintw(0, i, "-");
        mvprintw(HEIGHT + 1, i, "-");
    }
    for (int i = 0; i < HEIGHT + 2; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, WIDTH + 1, "|");
    }
    attron(COLOR_PAIR(2));
    mvprintw(food->y + 1, food->x + 1, "O");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->body[i].y + 1, snake->body[i].x + 1, "#");
    }
    attroff(COLOR_PAIR(1));
    mvprintw(0, WIDTH - 10, "Score: %d", score);
}

void move_snake(Snake *snake, Point *food, int *score, int *game_over) {
    int ch = getch();
    if (ch == KEY_UP && snake->direction != 'D') snake->direction = 'U';
    if (ch == KEY_DOWN && snake->direction != 'U') snake->direction = 'D';
    if (ch == KEY_LEFT && snake->direction != 'R') snake->direction = 'L';
    if (ch == KEY_RIGHT && snake->direction != 'L') snake->direction = 'R';
    
    Point new_head = snake->body[0];
    if (snake->direction == 'U') new_head.y--;
    if (snake->direction == 'D') new_head.y++;
    if (snake->direction == 'L') new_head.x--;
    if (snake->direction == 'R') new_head.x++;
    
    if (check_collision(snake)) {
        *game_over = 1;
        return;
    }
    
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    snake->body[0] = new_head;
    
    if (new_head.x == food->x && new_head.y == food->y) {
        snake->length++;
        (*score)++;
        generate_food(food, snake);
    }
}

int check_collision(Snake *snake) {
    if (snake->body[0].x < 0 || snake->body[0].x >= WIDTH || snake->body[0].y < 0 || snake->body[0].y >= HEIGHT) {
        return 1;
    }
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
            return 1;
        }
    }
    return 0;
}

void generate_food(Point *food, Snake *snake) {
    int valid;
    srand(time(NULL));
    do {
        valid = 1;
        food->x = rand() % WIDTH;
        food->y = rand() % HEIGHT;
        for (int i = 0; i < snake->length; i++) {
            if (food->x == snake->body[i].x && food->y == snake->body[i].y) {
                valid = 0;
                break;
            }
        }
    } while (!valid);
}

