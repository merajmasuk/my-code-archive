
#include <iostream>
#include <algorithm>

using namespace std;

int getCell(int (*arr)[20][20], int r, int c){
    if (r >= 0 && r < 20 && c >= 0 && c < 20) return (*arr)[r][c];
    return 0;
}

int findMax(int (*arr)[20][20], int n){
    long long MAX = 0;

    for (int r = 0; r < 20; r++){
        for (int c = 0; c < 20; c++){
            long long row = 1, col = 1, diag = 1, anti = 1;
            for (int i = 0; i < n; i++) {
                row  *= getCell(arr, r+i, c  );
                col  *= getCell(arr, r  , c+i);
                diag *= getCell(arr, r+i, c+i);
                anti *= getCell(arr, r+i, c-i);
            }

            MAX = max(MAX, max(max(row, col), max(diag, anti)));
            //cout << MAX << endl;
        }
    }

    //cout << MAX << endl;
    return MAX;
}

int main(){
    int mat[20][20], MAX = 0;

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++) cin >> mat[i][j];

    cout << findMax(&mat, 4) << endl;

    return 0;
}
