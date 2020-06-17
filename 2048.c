#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4


int grid[N][N] = {0};

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

int main(){
    place_nums();
    print_grid();

    return EXIT_SUCCESS;
}