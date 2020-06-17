#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4


int grid[N][N] = {0};
void rotate_left();

void place_nums(){
    int i = rand()%N;
    int j = rand()%N;

    while (grid[i][j]){
        i = rand()%N;
        j = rand()%N;
    } 

    if (rand()%2){
        grid[i][j] = 2;
    } else{
        grid[i][j] = 4;
    }
}

void print_grid(){
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
}

void welcome(){
    printf("%s\n", "Welcome to 2048. Use the following input keys:");
    printf("%*s\n", 5, "Up = \'w\' ");
    printf("%*s\n", 5, "Left = \'a\' ");
    printf("%*s\n", 5, "Down = \'s\' ");
    printf("%*s\n", 5, "Right = \'d\' ");
    printf("%*s\n", 5, "Quit = \'q\' ");

}

void process_cmd(char c){
    getchar();
    switch(c){
        case 'w':
            printf("%s\n", "UP");
            rotate_left();
            break;
        
        case 'a':
            printf("%s\n", "LEFT");
            break;
        
        case 's':
            printf("%s\n", "DOWN");
            break;
        
        case 'd':
            printf("%s\n", "RIGHT");
            break;
        
        case 'q':
            printf("%s\n", "QUIT");
            break;
        
    }
}

void rotate_left(){
    int copy[N][N] = {0};
    memcpy(&copy, &grid, sizeof(grid));

    for (int i= 0; i<N; i++){
        for (int j = 0; j<N; j++){
            grid[N-j-1][i] = copy[i][j];
        }
    }
}

int main(){
    welcome();
    place_nums();
    place_nums();
    print_grid();
    char c;
    while ((c = getchar()) != 'q'){
        process_cmd(c);
        place_nums();
        print_grid();
    }

    return EXIT_SUCCESS;
}