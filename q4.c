#include <iostream>
using namespace std;

int maze[5][5] = {
    {1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1}
};

int sol[5][5] = {0};

bool solve(int r, int c)
{
    if (r == 4 && c == 4 && maze[r][c] == 1)
    {
        sol[r][c] = 1;
        return true;
    }

    if (r < 0 || r >= 5 || c < 0 || c >= 5)
        return false;

    if (maze[r][c] == 0 || sol[r][c] == 1)
        return false;

    sol[r][c] = 1;

    if (solve(r + 1, c))
        return true;

    if (solve(r, c + 1))
        return true;

    if (solve(r - 1, c))
        return true;

    if (solve(r, c - 1))
        return true;

    sol[r][c] = 0;
    return false;
}

int main()
{
    if (solve(0, 0))
    {
        cout << "Solution:\n";

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cout << sol[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No path found";
    }

    return 0;
}
