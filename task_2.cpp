#include <iostream>

using namespace std;

static void displayLand(char land[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << land[i][j] << "\t";
        }
        cout << endl;
    }
}
static int gameOver(char land[3][3])
{
    // return: -1 - победа Х, 1 - победа 0, 0 - ничья, 2 - продолжаем играть
    // int countXGor = 0;
    // int countXVert = 0;
    // int countXDiagH = 0;
    // int countXDiagL = 0;

    // int countYGor = 0;
    // int countYVert = 0;
    // int countYDiagH = 0;
    // int countYDiagL = 0;
    int arrWin[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (land[i][j - 1] == land[i][j] && land[i][j] == 'X')
            {
                arrWin[0]++; // countXGor
            }
            else if (land[i][j - 1] == land[i][j] && land[i][j] == '0')
            {
                arrWin[1]++; // countYGor
            }
        }
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (land[i][j] == land[i - 1][j] && land[i][j] == 'X')
            {
                arrWin[2]++; // countXVert
            }
            else if (land[i][j] == land[i - 1][j] && land[i][j] == '0')
            {
                arrWin[3]++; // countYVert
            }
        }
    }
    for (int i = 1; i < 3; i++)
    {

        if (land[i][i] == land[i - 1][i - 1] && land[i][i] == 'X')
        {
            arrWin[4]++; // countXDiagH
        }
        else if (land[i][i] == land[i - 1][i - 1] && land[i][i] == '0')
        {
            arrWin[5]++; // countYDiagH
        }
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j >= 0; j--)
        {
            if (land[i][j] == land[i - 1][j + 1] && land[i][j] == 'X')
            {
                arrWin[6]++; // countXDiagL
            }
            else if (land[i][j] == land[i - 1][j + 1] && land[i][j] == '0')
            {
                arrWin[7]++; // countYDiagL
            }
        }
    }
    int index = -1;
    int index2 = -1;
    for (int i = 0; i < 8; i++)
    {
        if (arrWin[i] == 2)
        {
            if (index == -1)
            {
                index = i;
            }
            else
            {
                index2 = i;
            }
        }
        if (index != -1 && index2 != -1)
        {
            break;
        }
    }
    if (index != -1 && index2 == -1)
    {
        switch (index)
        {
        case 0:
        case 2:
        case 4:
        case 6:
            return -1;
        case 1:
        case 3:
        case 5:
        case 7:
            return 1;
        }
    }
    else if (index != -1 && index2 != -1)
    {
        return 0;
    }
    else
    {
        return 2;
    }
    return -2;
}

int main()
{
    char land[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool gamerStrik = false;
    int step = 0;
    int x = 0;
    int y = 0;
    int gameOv = 2;
    while (step != 9)
    {
        displayLand(land);
        gameOv = gameOver(land);
        if (gameOv == 2)
        {
            cout << "Продолжаем игру!" << endl;
            if (!gamerStrik)
            {
                cout << "Ход игрока - Х" << endl;
                cout << "Введите последовательно координаты Х и У: ";
                cin >> x >> y;
                if ((x > 0 && x <= 3) && (y > 0 && y <= 3))
                {
                    if (land[x - 1][y - 1] == ' ')
                    {
                        land[x - 1][y - 1] = 'X';
                        step++;
                        gamerStrik = true;
                    }
                    else
                    {
                        cout << "Ячейка занята. Переходите.";
                        continue;
                    }
                }
                else
                {
                    cout << "Координаты введены не верно. Переходите.";
                    continue;
                }
            }
            else
            {
                cout << "Ход игрока - 0" << endl;
                cout << "Введите последовательно координаты Х и У: ";
                cin >> x >> y;
                if ((x > 0 && x <= 3) && (y > 0 && y <= 3))
                {
                    if (land[x - 1][y - 1] == ' ')
                    {
                        land[x - 1][y - 1] = '0';
                        step++;
                        gamerStrik = false;
                    }
                    else
                    {
                        cout << "Ячейка занята. Переходите.";
                        continue;
                    }
                }
                else
                {
                    cout << "Координаты введены не верно. Переходите.";
                    continue;
                }
            }
        }
        else if (gameOv == -1)
        {
            cout << "Победа игрока Х";
            return 0;
        }
        else if (gameOv == 1)
        {
            cout << "Победа игрока 0";
            return 0;
        }
        else if (gameOv == 0)
        {
            cout << "Ничья!";
            return 0;
        }
    }
    cout << "Ничья!";
}