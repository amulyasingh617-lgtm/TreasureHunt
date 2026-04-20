#include "dfs.h"
#include <stack>
#include <iostream>

bool DFS::findPath(Maze &maze) {
    int rows = maze.rows;
    int cols = maze.cols;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    stack<Point> st;

    st.push(maze.start);

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!st.empty()) {
        Point curr = st.top();
        st.pop();

        if(visited[curr.x][curr.y]) continue;
        visited[curr.x][curr.y] = true;

        if(curr.x == maze.treasure.x && curr.y == maze.treasure.y) {
            cout << "Treasure found using DFS! 🎉" << endl;
            return true;
        }

        for(int i=0;i<4;i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(maze.isValid(nx, ny) && !visited[nx][ny] && maze.grid[nx][ny] != '#') {
                st.push({nx, ny});
            }
        }
    }

    cout << "No path found using DFS ❌" << endl;
    return false;
}
