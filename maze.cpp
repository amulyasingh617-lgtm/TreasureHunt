#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Maze::Maze(int r, int c) {
    rows = r;
    cols = c;
    grid.resize(rows, vector<char>(cols, '#'));
    srand(time(0));
}

bool Maze::isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < rows && y < cols);
}

void Maze::generateMaze() {
    
    // simple random maze
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(rand()%3 == 0)
                grid[i][j] = '#'; // wall
            else
                grid[i][j] = '.'; // path
        }
    }
    // Start & Treasure
    start = {0,0};
    treasure = {rows-1, cols-1};
    grid[start.x][start.y] = 'S';
    grid[treasure.x][treasure.y] = 'T';
}

void Maze::displayMaze() {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
