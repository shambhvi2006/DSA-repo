#include <iostream>
using namespace std;

int main(){
    int m, n;
    cout << "Enter dimensions (rows cols): ";
    cin >> m >> n;
    int A[m][n];  
    cout << "Enter matrix:\n";
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin >> A[i][j];
    int size = 0;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if (A[i][j] != 0) ++size;

    int sp[size+1][3];
    sp[0][0] = m; sp[0][1] = n; sp[0][2] = size;

    int row = 1;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if (A[i][j] != 0) {
                sp[row][0] = i;        // row index
                sp[row][1] = j;        // col index
                sp[row][2] = A[i][j];  // value
                ++row;
            }
    for(int i=0;i<row;++i){
        cout << sp[i][0] << " " << sp[i][1] << " " << sp[i][2] << "\n";
    }
    return 0;
}
