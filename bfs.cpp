#include "bfs.h"
#include <queue>
#include <iostream>

bool BFS::findPath(Maze &maze) {
    int rows = maze.rows;
    int cols = maze.cols;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<Point> q;

    q.push(maze.start);
    visited[maze.start.x][maze.start.y] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        if(curr.x == maze.treasure.x && curr.y == maze.treasure.y) {
            cout << "Treasure found using BFS! " << endl;
            return true;
        }

        for(int i=0;i<4;i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(maze.isValid(nx, ny) && !visited[nx][ny] && maze.grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << "No path found using BFS " << endl;
    return false;
}
