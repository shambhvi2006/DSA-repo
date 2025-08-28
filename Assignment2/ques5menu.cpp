#include <iostream>
using namespace std;


int diag_len(int n) { 
    return n; 
}
int tri_len(int n)  { 
    return 3*n - 2; 
}
int tri_index(int n, int i, int j) {
    if (i == j+1) return i-1;             // lower diag
    if (i == j)   return (n-1) + i;       // main diag
    if (j == i+1) return (2*n - 1) + i;   // upper diag
    return -1;
}
int lower_len(int n){ 
    return n*(n+1)/2; 
}
int lower_index(int n, int i, int j){     // i >= j
    return (i*(i+1))/2 + j;
}
int upper_len(int n){ 
    return n*(n+1)/2; 
}
int upper_index(int n, int i, int j){     // i <= j
    int before = i*n - (i*(i-1))/2;
    return before + (j - i);
}
int sym_len(int n){ 
    return n*(n+1)/2; 
}
int sym_index(int n, int i, int j){       // store lower triangle
    if (i < j) { int t=i; i=j; j=t; }
    return (i*(i+1))/2 + j;
}


void print_1d(int *a, int m){
    for (int k=0; k<m; ++k) cout << a[k] << " ";
    cout << "\n";
}

void expand_diag(int *a, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            cout << ((i==j)? a[i] : 0) << " ";
        }
        cout << "\n";
    }
}
void expand_tri(int *a, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int k = tri_index(n,i,j);
            cout << ((k==-1)? 0 : a[k]) << " ";
        }
        cout << "\n";
    }
}
void expand_lower(int *a, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i<j) cout << 0 << " ";
            else     cout << a[ lower_index(n,i,j) ] << " ";
        }
        cout << "\n";
    }
}
void expand_upper(int *a, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i>j) cout << 0 << " ";
            else     cout << a[ upper_index(n,i,j) ] << " ";
        }
        cout << "\n";
    }
}
void expand_sym(int *a, int n){
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int ii=i, jj=j;
            if (ii<jj){ int t=ii; ii=jj; jj=t; }
            cout << a[ (ii*(ii+1))/2 + jj ] << " ";
        }
        cout << "\n";
    }
}


void compress_diag(int **mat, int *a, int n){
    for (int i=0;i<n;++i) a[i] = mat[i][i];
}
void compress_tri(int **mat, int *a, int n){
    // init zeros
    for (int k=0;k<tri_len(n);++k) a[k]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int k = tri_index(n,i,j);
            if (k!=-1) a[k] = mat[i][j];
        }
    }
}
void compress_lower(int **mat, int *a, int n){
    int m = lower_len(n);
    for (int k=0;k<m;++k) a[k]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<=i;++j)
            a[ lower_index(n,i,j) ] = mat[i][j];
}
void compress_upper(int **mat, int *a, int n){
    int m = upper_len(n);
    for (int k=0;k<m;++k) a[k]=0;
    for (int i=0;i<n;++i)
        for (int j=i;j<n;++j)
            a[ upper_index(n,i,j) ] = mat[i][j];
}
void compress_sym(int **mat, int *a, int n){
    int m = sym_len(n);
    for (int k=0;k<m;++k) a[k]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int a=i, b=j;
            if (a<b){ 
                swap(a,b);
            }
            a[ (a*(a+1))/2 + b ] = mat[i][j]; // if not symmetric, this just takes last seen
        }
    }
}

int main(){
    int n;
    cout << "Enter n: ";
    if(!(cin >> n) || n<=0){ cout<<"Invalid n\n"; return 0; }

    int **mat = new int*[n];
    for (int i=0;i<n;++i) mat[i] = new int[n];

    cout << "Enter the " << n << "x" << n << " matrix:\n";
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin >> mat[i][j];

    cout << "\nChoose storage type:\n";
    cout << "1) Diagonal\n";
    cout << "2) Tri-diagonal\n";
    cout << "3) Lower triangular\n";
    cout << "4) Upper triangular\n";
    cout << "5) Symmetric (store lower)\n";
    cout << "Enter choice: ";
    int ch; cin >> ch;

    if (ch==1){
        int m = diag_len(n);
        int *a = new int[m];
        compress_diag(mat,a,n);

        cout << "\nCompressed (size " << m << "): ";
        print_1d(a,m);

        cout << "Reconstructed matrix:\n";
        expand_diag(a,n);

        delete[] a;
    } else if (ch==2){
        int m = tri_len(n);
        int *a = new int[m];
        compress_tri(mat,a,n);

        cout << "\nCompressed (size " << m << "): ";
        print_1d(a,m);

        cout << "Reconstructed matrix:\n";
        expand_tri(a,n);

        delete[] a;
    } else if (ch==3){
        int m = lower_len(n);
        int *a = new int[m];
        compress_lower(mat,a,n);

        cout << "\nCompressed (size " << m << "): ";
        print_1d(a,m);

        cout << "Reconstructed matrix:\n";
        expand_lower(a,n);

        delete[] a;
    } else if (ch==4){
        int m = upper_len(n);
        int *a = new int[m];
        compress_upper(mat,a,n);

        cout << "\nCompressed (size " << m << "): ";
        print_1d(a,m);

        cout << "Reconstructed matrix:\n";
        expand_upper(a,n);

        delete[] a;
    } else if (ch==5){
        int m = sym_len(n);
        int *a = new int[m];
        compress_sym(mat,a,n);

        cout << "\nCompressed (size " << m << "): ";
        print_1d(a,m);

        cout << "Reconstructed matrix:\n";
        expand_sym(a,n);

        delete[] a;
    } else {
        cout << "Invalid choice.\n";
    }

    for (int i=0;i<n;++i) delete[] mat[i];
    delete[] mat;
    return 0;
}
