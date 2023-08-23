#include <iostream>
using namespace std;
void multyMtrxVec(int matrix[][4], int vec1[], int vec2[], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        // int tmp = 0;
        vec2[i] = 0;
        for (int j = 0; j < size2; j++)
        {
            vec2[i] += (matrix[i][j] * vec1[i]);
        }
    }
}
void displyMtrx(int vec[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << endl;
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
void inputVec(int arr[], int size)
{
    cout << "Введите последовательно значения вектора: " << endl;

    for (int j = 0; j < size; j++)
    {
        cout << "Элемент [" << j << "] -> ";
        cin >> arr[j];
    }
}
int main()
{
    // для тестирования функционала
    /*int matrixA[4][4] = {{1, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4}};
    int vectorB[4] = {1, 2, 3, 4};*/
    int matrixA[4][4];
    int vectorB[4];
    int vectorC[4];
    inputMtrx(matrixA, 4);
    inputVec(vectorB, 4);
    multyMtrxVec(matrixA, vectorB, vectorC, 4, 4);
    displyMtrx(vectorC, 4);
}