#include <iostream>
using namespace std;

char forest[5][5] = {
    {'S', 'A', 'T', 'G', 'A'},
    {'A', 'G', 'A', 'T', 'G'},
    {'T', 'A', 'G', 'A', 'F'},
    {'G', 'T', 'A', 'G', 'A'},
    {'A', 'G', 'T', 'A', 'G'}
};

int used[5][5];
int sol[5][5];
int path[25][2];
int len;
int items;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool solve(int r, int c, char target, int total)
{
    if (r < 0 || r >= 5 || c < 0 || c >= 5)
        return false;

    if (forest[r][c] == 'T' || used[r][c] == 1)
        return false;

    used[r][c] = 1;
    sol[r][c] = 1;

    path[len][0] = r;
    path[len][1] = c;
    len++;

    if (forest[r][c] == target)
        items++;

    if (items == total)
        return true;

    for (int i = 0; i < 4; i++)
    {
        if (solve(r + dr[i], c + dc[i], target, total))
            return true;
    }

    if (forest[r][c] == target)
        items--;

    len--;
    used[r][c] = 0;
    sol[r][c] = 0;

    return false;
}

void reset()
{
    len = 0;
    items = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            used[i][j] = 0;
            sol[i][j] = 0;
        }
}

void show(char name)
{
    cout << name << " path:\n";

    for (int i = 0; i < len; i++)
        cout << "(" << path[i][0] << ","
             << path[i][1] << ") ";

    cout << "\nItems collected = " << items << endl;

    cout << "Output array:\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << sol[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    reset();

    if (solve(0, 0, 'A', 7))
        show('S');
    else
        cout << "Squirrel could not collect all acorns\n";

    reset();

    if (solve(2, 4, 'G', 6))
        show('F');
    else
        cout << "Fox could not collect all gems\n";

    return 0;
}
