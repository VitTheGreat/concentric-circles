#include <iostream>

using namespace std;

int m = -1;
int n = -1;

int c = 0;
int k = -1;

void check(int* A, int X, int Y, int* M)
{
    for (int cX = X - 1; cX <= X + 1; cX++)
    {
        for (int cY = Y - 1; cY <= Y + 1; cY++)
        {
            if (cX == X and cY == Y)
                continue;
            else if (A[cX * (n + 2) + cY] == 0)
            {
                A[cX * (n + 2) + cY] = A[X * (n + 2) + Y] + 1;
                M[c] = cX * (n + 2) + cY;
                c++;
            }
        }
    }

    k++;
    if (k <= m * n - 2)
        check(A, M[k] / (n + 2), M[k] % (n + 2), M);
    else
        return;
    
}

int main()
{
    cout << "A[m*n]" << endl << "Enter m, n: ";
    cin >> m >> n;

    int* A = new int[(m + 2) * (n + 2)]; // m = строки, n = столбцы

    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            A[i * (n + 2) + j] = -1;
    }

    cout << endl;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            A[i * (n + 2) + j] = 0;
            cout << A[i * (n + 2) + j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int x = -1, y = -1;
    while (x<0 or y<0 or x>n or y>m)
    {
        cout << "Enter x, y: ";
        cin >> x >> y;
    }
    x++;
    y++;

    A[x * (n + 2) + y] = 1;

    int* M = new int[m * n];
    for (c = 0;c < m * n;c++)
        M[c] = -1;
    c = 0;

    check(A, x, y, M);

    cout << endl;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            cout << A[i * (n + 2) + j] << " ";
        cout << endl;
    }

    delete[] A;
    delete[] M;
    return 0;
}