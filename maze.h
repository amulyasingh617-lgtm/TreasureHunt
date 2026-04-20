#ifndef MAZE_H
#define MAZE_H

#include <vector>
using namespace std;

struct Point {
    int x, y;
};

class Maze {
public:
    int rows, cols;
    vector<vector<char>> grid;
    Point start, treasure;

    Maze(int r, int c);

    void generateMaze();
    void displayMaze();
    bool isValid(int x, int y);
};

#endif
