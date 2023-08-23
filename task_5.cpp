#include <iostream>
using namespace std;
void initMtrx(bool arr[][12], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            arr[i][j] = true;
        }
    }
}
void displyMtrx(bool arr[][12], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void inputRange(bool arr[][12], int size1, int size2, int i1, int j1, int i2, int j2)
{
    if (((i1 >= 0 && i1 < size1) && (i2 >= 0 && i2 < size1)) && ((j1 >= 0 && j1 < size2) && (j2 >= 0 && j2 < size2)))
    {
        for (int i = i1; i <= i2; i++)
        {
            for (int j = j1; j <= j2; j++)
            {
                arr[i][j] = false;
                cout << "Pop!.." << endl;
            }
        }
    }
    else
    {
        cout << "Введенные координаты выходят за рамки массива!" << endl;
    }
}
bool gameAnalis(bool arr[][12], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr[i][j])
                return true;
        }
    }
    return false;
}
int main()
{
    bool matrix[12][12];
    initMtrx(matrix, 12, 12);
    bool gameOver = true;
    int i = 0;
    int j = 0;
    int i2 = 0;
    int j2 = 0;
    while (gameOver)
    {
        displyMtrx(matrix, 12, 12);
        cout << "Ввести координаты диапазона: " << endl;
        cin >> i >> j >> i2 >> j2;
        inputRange(matrix, 12, 12, i, j, i2, j2);
        
        gameOver = gameAnalis(matrix, 12, 12);
    }
    displyMtrx(matrix, 12, 12);
    cout << "Game Over!";
}