#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void next(int num, int player);

void play(int num, int player)
{
    int guess;

    cout << "Player " << player << ", enter guess: ";
    cin >> guess;

    if (guess == num)
    {
        cout << "Player " << player << " wins!";
        return;
    }

    if (guess > num)
        cout << "Too high\n";
    else
        cout << "Too low\n";

    next(num, player + 1);
}

void next(int num, int player)
{
    play(num, player);
}

int main()
{
    srand(time(0));
    int num = rand() % 100 + 1;

    play(num, 1);

    return 0;
}
