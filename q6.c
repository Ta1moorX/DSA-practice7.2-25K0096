#include <iostream>
using namespace std;

char grid[6][6] = {
    {'D', 'S', 'F', 'S', 'S', 'S'},
    {'S', 'S', 'F', 'S', 'F', 'S'},
    {'F', 'S', 'S', 'S', 'F', 'S'},
    {'S', 'F', 'F', 'S', 'S', 'S'},
    {'S', 'S', 'S', 'F', 'S', 'F'},
    {'F', 'S', 'S', 'S', 'S', 'H'}
};

int vis[6][6] = {0};
int path[36][2];
int best[36][2];
int len = 0, bestlen = 0;
int winds = 0, bestwinds = 1000;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void solve(int r, int c)
{
    if (r < 0 || r >= 6 || c < 0 || c >= 6)
        return;

    if (grid[r][c] == 'F' || vis[r][c] == 1)
        return;

    if (grid[r][c] == 'D' && !(r == 0 && c == 0))
        winds++;

    vis[r][c] = 1;
    path[len][0] = r;
    path[len][1] = c;
    len++;

    if (grid[r][c] == 'H')
    {
        if (winds < bestwinds)
        {
            bestwinds = winds;
            bestlen = len;

            for (int i = 0; i < len; i++)
            {
                best[i][0] = path[i][0];
                best[i][1] = path[i][1];
            }
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
            solve(r + dr[i], c + dc[i]);
    }

    len--;
    vis[r][c] = 0;

    if (grid[r][c] == 'D' && !(r == 0 && c == 0))
        winds--;
}

int main()
{
    solve(0, 0);

    cout << "Blocked cells:\n";

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (grid[i][j] == 'F')
                cout << "(" << i << "," << j << ")\n";

    if (bestlen == 0)
    {
        cout << "No path found";
        return 0;
    }

    cout << "Safest path:\n";

    for (int i = 0; i < bestlen; i++)
        cout << "(" << best[i][0] << "," << best[i][1] << ") ";

    cout << "\nHigh wind cells = " << bestwinds;

    return 0;
}
