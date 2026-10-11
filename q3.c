#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim)
{
    if (dim == 0)
        return 0;

    int sum = 0;

    for (int i = 0; i < sizes[dim - 1]; i++)
        sum += arr[dim - 1][i];

    return sum + recursiveArraySum(arr, sizes, dim - 1);
}

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5};
    int c[] = {6, 7, 8, 9};

    int* arr[] = {a, b, c};
    int sizes[] = {3, 2, 4};

    cout << "Sum = "
         << recursiveArraySum(arr, sizes, 3);

    return 0;
}
