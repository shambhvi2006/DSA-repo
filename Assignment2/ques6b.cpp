#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 3;

    int A[3][3] = { {0,0,1}, {0,2,0}, {0,0,3} };
    int B[3][3] = { {0,1,0}, {0,2,0}, {3,0,0} };

    // --- print matrices A and B (dense) ---
    cout << "Matrix A:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cout << A[i][j] << " ";
        cout << "\n";
    }

    cout << "\nMatrix B:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cout << B[i][j] << " ";
        cout << "\n";
    }

    
    int sizeA = 0, sizeB = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != 0) ++sizeA;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (B[i][j] != 0) ++sizeB;

    int spA[sizeA + 1][3];
    int spB[sizeB + 1][3];
    spA[0][0] = m; spA[0][1] = n; spA[0][2] = sizeA;
    spB[0][0] = m; spB[0][1] = n; spB[0][2] = sizeB;

    int rowA = 1;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != 0) {
                spA[rowA][0] = i;
                spA[rowA][1] = j;
                spA[rowA][2] = A[i][j];
                ++rowA;
            }

    int rowB = 1;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (B[i][j] != 0) {
                spB[rowB][0] = i;
                spB[rowB][1] = j;
                spB[rowB][2] = B[i][j];
                ++rowB;
            }
    int spC[sizeA + sizeB + 1][3];
    spC[0][0] = m; spC[0][1] = n; 
    int iA = 1, iB = 1, k = 1;
    while (iA <= sizeA && iB <= sizeB) {
        int rA = spA[iA][0], cA = spA[iA][1];
        int rB = spB[iB][0], cB = spB[iB][1];

        if (rA < rB || (rA == rB && cA < cB)) {
            spC[k][0] = rA; spC[k][1] = cA; spC[k][2] = spA[iA][2];
            ++iA; ++k;
        } else if (rB < rA || (rB == rA && cB < cA)) {
            spC[k][0] = rB; spC[k][1] = cB; spC[k][2] = spB[iB][2];
            ++iB; ++k;
        } else {
            int sum = spA[iA][2] + spB[iB][2];
            if (sum != 0) {
                spC[k][0] = rA; spC[k][1] = cA; spC[k][2] = sum;
                ++k;
            }
            ++iA; ++iB;
        }
    }
    while (iA <= sizeA) { 
        spC[k][0] = spA[iA][0]; 
        spC[k][1] = spA[iA][1]; 
        spC[k][2] = spA[iA][2]; 
        ++iA; ++k; 
    }
    while (iB <= sizeB) { 
        spC[k][0] = spB[iB][0]; 
        spC[k][1] = spB[iB][1]; 
        spC[k][2] = spB[iB][2]; 
        ++iB; ++k; 
    }

    spC[0][2] = k - 1; // final non-zero count
    cout << "\nA (triplet):\n";
    for (int t = 0; t <= sizeA; ++t)
        cout << spA[t][0] << " " << spA[t][1] << " " << spA[t][2] << "\n";

    cout << "\nB (triplet):\n";
    for (int t = 0; t <= sizeB; ++t)
        cout << spB[t][0] << " " << spB[t][1] << " " << spB[t][2] << "\n";

    
    cout << "\nA + B (triplet):\n";
    for (int t = 0; t <= spC[0][2]; ++t)
        cout << spC[t][0] << " " << spC[t][1] << " " << spC[t][2] << "\n";

    return 0;
}
