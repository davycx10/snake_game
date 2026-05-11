#include <termios.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define HEIGHT 20
#define WIDTH 40

int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
int gameover, key, score;
int x, y, fruitx, fruity;

void enableRawMode(){
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ICANON | ECHO);
    // desactive l'attente de ligne et l'echo pour une lecture instantanée des touches
    tcsetattr(STDIN_FILENO, TCIFLUSH, &raw);
}

void disableRawMode(){
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


int kbhit(){
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
    
}


// Function to move cursor to (0,0) to prevent flickering
void goToXY(int x, int y) {
    printf("\033[%d;%dH", y+1, x+1);
}

void setup() {
    srand(time(NULL));
    gameover = 0;
    score = 0;
    snakeTailLen = 0;
    
    // position 
    x = WIDTH / 2;
    y = HEIGHT / 2;
    
    // direction initial (0 = stopped)
    key = 0; 

    // position initial du fruit
    fruitx = rand() % (WIDTH - 2) + 1;
    fruity = rand() % (HEIGHT - 2) + 1;
}

void draw() {
    goToXY(0, 0); // remet le curseur en haut à gauche pour éviter le flickering

    for (int i = 0; i < WIDTH + 2; i++) printf("-");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            if (j == 0 || j == WIDTH) {
                printf("#");
            }
            if (i == y && j == x) {
                printf("O"); // Head
            } else if (i == fruity && j == fruitx) {
                printf("*"); // Fruit
            } else {
                int prTail = 0;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        printf("o"); // Body
                        prTail = 1;
                        break;
                    }
                }
                if (!prTail) printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("-");
    printf("\nScore: %d\n", score);
    printf("Controls: Z, A, S, D | X to Quit\n");
}

void input() {
    if(kbhit()){
        int ch = getchar();
        // gestion des touche special
        if (ch == 0 || ch == 225){
            ch = getchar();
            switch(ch){
                // fleche gauche
                case 75: if (key != 2) key = 1; break;

                // fleche droite
                case 77: if (key != 1) key = 2; break;

                // fleche haut
                case 72: if (key != 4) key = 3; break;

                // fleche bas
                case 80: if (key != 3) key = 4; break;
            }
        }
        else {
            //  ZQSD
            switch (tolower(ch)){
                case 'q': if (key != 2) key = 1;  break;
                case 'd': if (key != 1) key = 2; break;
                case 'z': if (key != 4) key = 3; break;
                case 's': if (key != 3) key = 4; break;
                case 'x': gameover = 5;  break;
            }
        }
    }
}

void logic() {
    // 1. Logic for tail following
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // 2. Direction movement
    switch (key) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
    }

    // 3. Wall Collision
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameover = 1;

    // 4. Tail Collision
    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            gameover = 1;
    }

    // 5. Eating Fruit
    if (x == fruitx && y == fruity) {
        score += 10;
        snakeTailLen++;
        fruitx = rand() % (WIDTH - 2) + 1;
        fruity = rand() % (HEIGHT - 2) + 1;
    }
}

int main() {
    // Clear screen once at the start
    enableRawMode();
    system("clear");
    setup();

    while (!gameover) {
        draw();
        input();
        logic();
        usleep(40000); // Controls game speed
    }
    
    getchar(); // Wait for user input before closing window
    disableRawMode();
    return 0;
}
