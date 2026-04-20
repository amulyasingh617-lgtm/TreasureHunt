#include <iostream>
#include "maze.h"
#include "bfs.h"
#include "dfs.h"

using namespace std;

int main()
{
    cout << "=== TREASURE HUNT MAZE GAME ===" << endl;

    Maze maze;
    maze.createMaze();

    int choice;
    cout << "\nChoose Algorithm to find Treasure:" << endl;
    cout << "1. BFS (Shortest Path)" << endl;
    cout << "2. DFS (Any Path)" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nUsing BFS to find treasure...\n";
        BFS bfs;
        bfs.findTreasure(maze);
    }
    else if (choice == 2)
    {
        cout << "\nUsing DFS to find treasure...\n";
        DFS dfs;
        dfs.findTreasure(maze);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
