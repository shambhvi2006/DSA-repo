#include <iostream>
using namespace std;

struct Triplet {
    int r, c;
    int v;
};

struct Sparse {
    int rows, cols, nz;
    Triplet* t;
};

// Read a sparse matrix already in sorted order (row-major: by r, then c)
void readSparse(Sparse &S) {
    cin >> S.rows >> S.cols >> S.nz;
    S.t = new Triplet[S.nz];
    for (int i = 0; i < S.nz; ++i) {
        cin >> S.t[i].r >> S.t[i].c >> S.t[i].v; // 0-indexed positions preferred
    }
}

// Print sparse matrix triplets
void printSparse(const Sparse &S) {
    cout << S.rows << " " << S.cols << " " << S.nz << "\n";
    for (int i = 0; i < S.nz; ++i)
        cout << S.t[i].r << " " << S.t[i].c << " " << S.t[i].v << "\n";
}

// Naive but simple transpose (keeps row-major order by scanning columns)
Sparse transpose(const Sparse &A) {
    Sparse T; T.rows = A.cols; T.cols = A.rows; T.nz = A.nz;
    T.t = new Triplet[T.nz];
    int k = 0;
    for (int col = 0; col < A.cols; ++col) {
        for (int i = 0; i < A.nz; ++i) {
            if (A.t[i].c == col) {
                T.t[k].r = A.t[i].c;
                T.t[k].c = A.t[i].r;
                T.t[k].v = A.t[i].v;
                ++k;
            }
        }
    }
    return T;
}

// Merge-like addition; assumes both inputs sorted by (r,c)
Sparse add(const Sparse &A, const Sparse &B) {
    Sparse C; C.rows = A.rows; C.cols = A.cols; C.t = new Triplet[A.nz + B.nz];
    int i = 0, j = 0, k = 0;
    while (i < A.nz && j < B.nz) {
        if (A.t[i].r < B.t[j].r || (A.t[i].r == B.t[j].r && A.t[i].c < B.t[j].c)) {
            C.t[k++] = A.t[i++];
        } else if (B.t[j].r < A.t[i].r || (B.t[j].r == A.t[i].r && B.t[j].c < A.t[i].c)) {
            C.t[k++] = B.t[j++];
        } else { // same position
            int sum = A.t[i].v + B.t[j].v;
            if (sum != 0) { C.t[k] = A.t[i]; C.t[k++].v = sum; }
            ++i; ++j;
        }
    }
    while (i < A.nz) C.t[k++] = A.t[i++];
    while (j < B.nz) C.t[k++] = B.t[j++];
    C.nz = k;
    return C;
}

// Multiplication using row-accumulation (A: m x n, B: n x p)
Sparse multiply(const Sparse &A, const Sparse &B) {
    Sparse C; C.rows = A.rows; C.cols = B.cols;
    // quick dimension check
    if (A.cols != B.rows) { C.nz = 0; C.t = new Triplet[0]; return C; }

    // For each row of A, accumulate into a dense temp row of size B.cols
    int *acc = new int[B.cols];
    Triplet* temp = new Triplet[A.rows * B.cols]; // upper bound
    int k = 0;

    // Precompute indices of B grouped by row (since we need B elements with row = Acol)
    // Build simple index lists (no STL): count, then positions.
    int *countRow = new int[B.rows]; for (int i = 0; i < B.rows; ++i) countRow[i] = 0;
    for (int i = 0; i < B.nz; ++i) ++countRow[B.t[i].r];
    int *start = new int[B.rows]; start[0] = 0;
    for (int i = 1; i < B.rows; ++i) start[i] = start[i-1] + countRow[i-1];

    Triplet* BbyRow = new Triplet[B.nz];
    int *placed = new int[B.rows]; for (int i = 0; i < B.rows; ++i) placed[i] = 0;
    for (int i = 0; i < B.nz; ++i) {
        int r = B.t[i].r;
        int pos = start[r] + placed[r]++;
        BbyRow[pos] = B.t[i];
    }

    // Walk over A row by row
    for (int r = 0; r < A.rows; ++r) {
        for (int j = 0; j < B.cols; ++j) acc[j] = 0;

        // All nonzeros in row r of A
        for (int i = 0; i < A.nz; ++i) {
            if (A.t[i].r != r) continue;
            int aCol = A.t[i].c;
            int aval = A.t[i].v;
            // multiply with all nonzeros of B whose row == aCol
            int s = start[aCol], e = s + countRow[aCol];
            for (int p = s; p < e; ++p) {
                int c = BbyRow[p].c;
                acc[c] += aval * BbyRow[p].v;
            }
        }
        // flush this row into triplets
        for (int c = 0; c < B.cols; ++c) if (acc[c] != 0) {
            temp[k].r = r; temp[k].c = c; temp[k].v = acc[c]; ++k;
        }
    }

    C.nz = k;
    C.t = new Triplet[k];
    for (int i = 0; i < k; ++i) C.t[i] = temp[i];

    delete[] acc; delete[] temp; delete[] countRow; delete[] start; delete[] BbyRow; delete[] placed;
    return C;
}

int main() {
    // Example driver:
    // Input format:
    // A: rows cols nz then nz lines of (r c v)
    // B: rows cols nz then nz lines of (r c v)
    Sparse A, B; 
    // Sample:
    // 3 3 4
    // 0 0 1
    // 0 2 2
    // 1 1 3
    // 2 0 4
    // 3 3 3
    // 0 1 5
    // 1 2 6
    // 2 0 7
    readSparse(A);
    readSparse(B);

    cout << "Transpose of A:\n"; printSparse(transpose(A));
    cout << "A + B (if same size):\n"; 
    if (A.rows==B.rows && A.cols==B.cols) printSparse(add(A,B)); else cout << "Incompatible\n";

    cout << "A x B (if cols(A)==rows(B)):\n"; printSparse(multiply(A,B));

    delete[] A.t; delete[] B.t;
    return 0;
}
