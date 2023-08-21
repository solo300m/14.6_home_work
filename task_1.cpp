#include <iostream>

using namespace std;

int main()
{
    int plase [2][6] = {{1,1,1,1,1,1},{1,1,1,1,1,1}};    
    int delish [2][6] = {{3,2,2,2,2,2},{3,2,2,2,2,2}};
    int forge [2][6] = {{4,3,3,3,3,3},{4,3,3,3,3,3}};
    plase[0][4]++;
    forge[1][2]--;
    forge[1][0]--;
    forge[1][2]++;
    delish[1][0]--;
    cout<<"Итоговое состояние стола:"<<endl;
    for(int i = 0; i<2; i++){
        for(int j = 0; j < 6; j++){
            cout << "Ряд- "<<i+1<<" Место- "<<j+1<<" стульев- "<<plase[i][j]<< " Приборы- "<<forge[i][j]<<" Тарелки- "<<delish[i][j]<<endl;
        }
        cout<<endl;
    }

}