#include <iostream>
using namespace std;

int main() {
    int m;
    cin>>m;
   int **mtrx1 = new int* [m];
    for (int i = 0; i <m ; ++i) {
        mtrx1[i] = new int [3];
    }
    for (int i = 0; i <m ; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>mtrx1[i][j];
        }
    }

    int n;
    cin>>n;
    int **mtrx2 = new int* [n];
    for (int i = 0; i <n ; ++i) {
        mtrx2[i] = new int [3];
    }
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>mtrx2[i][j];
        }
    }

    int **mtrx3 = new int* [mtrx1[0][0]];
    for (int i = 0; i <mtrx1[0][0] ; ++i) {
        mtrx2[i] = new int [mtrx2[0][1]];
    }
    for (int i = 0; i < mtrx1[0][2]; ++i) {
        for (int j = 0; j < mtrx2[0][2]; ++j) {
          if(mtrx1[i][1] == mtrx2 [j][0])
                    mtrx3[mtrx1[i][0]][mtrx2[j][1]]+ = mtrx2[j][2]* mtrx1[i][2];
            }
        }

    }
    for (int l = 0; l < mtrx1[0][0]; ++l) {
        for (int h = 0; h < mtrx2[0][1]; ++h) {
            cout<<mtrx3[l][h]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
