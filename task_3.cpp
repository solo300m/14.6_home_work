#include <iostream>
using namespace std;

static bool compareTo(int arr[][4], int arr2[][4], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}
static void diagonalMtrx(int arr[][4], int rez[][4], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                rez[i][j] = arr[i][j];
                // rez[i][j] = 1;
            }
            else
            {
                rez[i][j] = 0;
            }
        }
    }
}
void displyMtrx(int arr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void inputMtrx(int arr[][4], int size)
{
    cout << "Введите последовательно значения матрицы 4х4: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Элемент [" << i << "][" << j << "] -> ";
            cin >> arr[i][j];
        }
    }    
}

int main()
{
    // для тестирования
    /*int matrixA[4][4] = {{2, 3, 5, 6},
                         {2, 3, 5, 6},
                         {2, 3, 5, 6},
                         {2, 3, 5, 6}};
    int matrixB[4][4] = {{2, 3, 5, 6},
                         {2, 3, 5, 6},
                         {2, 3, 5, 6},
                         {2, 3, 5, 6}};*/
    int matrixA[4][4];
    int matrixB[4][4];
    int matrixC[4][4];
    inputMtrx(matrixA, 4);
    inputMtrx(matrixB, 4);
    cout << "Введены массивы: " << endl;
    displyMtrx(matrixA);
    displyMtrx(matrixB);
    if (compareTo(matrixA, matrixB, 4))
    {
        cout << "Матрицы A и B равны" << endl;
        diagonalMtrx(matrixA, matrixC, 4);
        cout << "Диагональный вид матрицы A" << endl;
        displyMtrx(matrixC);
    }
    else
    {
        cout << "Матрицы A и B не равны" << endl;
    }
}