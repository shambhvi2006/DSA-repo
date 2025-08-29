#include <iostream>
using namespace std;

int main() {
    int m=3, n=3;
    int A[3][3]={{0,0,1},{0,2,0},{0,0,3}};
    int B[3][3]={{0,1,0},{0,2,0},{3,0,0}};

    int sizeA = 0, sizeB = 0;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) if (A[i][j]!=0) ++sizeA;
    for (int i=0;i<m;++i) for (int j=0;j<n;++j) if (B[i][j]!=0) ++sizeB;

    int spA[sizeA + 1][3];
    int spB[sizeB + 1][3];
    spA[0][0] = m; spA[0][1] = n; spA[0][2] = sizeA;
    spB[0][0] = m; spB[0][1] = n; spB[0][2] = sizeB;

    int rowA = 1;
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (A[i][j] != 0) {
                spA[rowA][0] = i;  
                spA[rowA][1] = j;  
                spA[rowA][2] = A[i][j];
                ++rowA;
            }

    int rowB = 1;
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            if (B[i][j] != 0) {
                spB[rowB][0] = i;
                spB[rowB][1] = j;
                spB[rowB][2] = B[i][j];
                ++rowB;
            }

    cout << "A (triplet):\n";
    for (int t=0; t<=sizeA; ++t)
        cout << spA[t][0] << " " << spA[t][1] << " " << spA[t][2] << "\n";

    cout << "\nB (triplet):\n";
    for (int t=0; t<=sizeB; ++t)
        cout << spB[t][0] << " " << spB[t][1] << " " << spB[t][2] << "\n";

    int rowsA = spA[0][0], colsA = spA[0][1];
    int rowsB = spB[0][0], colsB = spB[0][1];
    if (colsA != rowsB) {
        cout << "\nA x B not possible (cols(A) != rows(B))\n";
        return 0;
    }

    // C = A x B in triplet form (no heap)
int maxC = rowsA * colsB;        
int spC[maxC + 1][3];            
spC[0][0] = rowsA; 
spC[0][1] = colsB;               

int acc[colsB];                  // row-accumulator

int kC = 1;                      // next write index in spC
for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsB; ++j) {
        acc[j] = 0;
    }

    // for each nonzero A[i,k], multiply with all B[k,*] nonzeros
    for (int p = 1; p <= sizeA; ++p) {  
        if (spA[p][0] != i) continue;   // Keep only those whose row == i 
        int k  = spA[p][1];            // column of A becomes row in B
        int av = spA[p][2];
        for (int q = 1; q <= sizeB; ++q) {
            if (spB[q][0] == k) {      // row k in B
                int j = spB[q][1];     // column in B
                acc[j] += av * spB[q][2];
            }
        }
    }

    for (int j = 0; j < colsB; ++j) {
        if (acc[j] != 0) {
            spC[kC][0] = i;            // row
            spC[kC][1] = j;            // col
            spC[kC][2] = acc[j];
            ++kC;
        }
    }
}

spC[0][2] = kC - 1;                     // non zero count

// print C in triplet form
cout << "\nC = A x B (triplet):\n";
for (int t = 0; t <= spC[0][2]; ++t)
    cout << spC[t][0] << " " << spC[t][1] << " " << spC[t][2] << "\n";

}
