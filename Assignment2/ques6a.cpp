#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout << "Enter dimensions (rows cols): ";
    cin >> m >> n;

    int A[m][n];
    cout << "Enter matrix:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    int size = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != 0) ++size;

    int sp[size + 1][3];
    sp[0][0] = m; sp[0][1] = n; sp[0][2] = size;

    int row = 1; // start after header
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != 0) {
                sp[row][0] = i;           // row
                sp[row][1] = j;           // col
                sp[row][2] = A[i][j];     // val
                ++row;
            }

    int tsp[size + 1][3];
    tsp[0][0]=sp[0][1];
    tsp[0][1]=sp[0][0]; 
    tsp[0][2]=sp[0][2];
    
    int k=1;
    for(int j=0;j<sp[0][1];j++){
        for(int i=1;i<=size;i++){
            if(sp[i][1]==j){
                tsp[k][0]=sp[i][1];
                tsp[k][1]=sp[i][0];
                tsp[k][2]=sp[i][2];
                k++;
            }
        }
    }

    for(int i=0;i<=size;i++){
        for(int j=0;j<3;j++){
            cout<<tsp[i][j]<<" ";
        }
        cout<<"\n";
    }

    
    return 0;
}
