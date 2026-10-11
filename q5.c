#include <iostream>
using namespace std;

int pos[16];
int count = 0;

bool safe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (pos[i] == col)
            return false;

        if (row - i == col - pos[i] ||
            row - i == pos[i] - col)
            return false;
    }

    return true;
}

bool solve(int row)
{
    if (row == 16)
        return true;

    for (int col = 0; col < 16; col++)
    {
        if (safe(row, col))
        {
            pos[row] = col;

            if (solve(row + 1))
                return true;
        }
    }

    return false;
}

int main()
{
    if (solve(0))
    {
        cout << "Maximum flags = 16\n";

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (pos[i] == j)
                    cout << "1 ";
                else
                    cout << "0 ";
            }

            cout << endl;
        }
    }

    return 0;
}
