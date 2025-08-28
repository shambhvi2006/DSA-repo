#include <iostream>
using namespace std;

int sym_size(int n){ 
    return n*(n+1)/2; 
}
int sym_index(int n,int i,int j){
    if(i<j){ 
        swap(i,j);
    }                 
    return (i*(i+1))/2 + j;                       
}
void sym_set(int* a,int n,int i,int j,int val){ 
    a[sym_index(n,i,j)] = val; 
}
int  sym_get(int* a,int n,int i,int j){ 
    return a[sym_index(n,i,j)]; 
}

void sym_print(int* a,int n){
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j) cout<<sym_get(a,n,i,j)<<" "; 
        cout<<"\n"; 
    }
}

int main(){
    int n=4; int* A=new int[sym_size(n)]();
    // Set symmetric entries; you only set once
    sym_set(A,n,0,0,1); 
    sym_set(A,n,1,0,2); 
    sym_set(A,n,1,1,3);
    sym_set(A,n,2,0,4); 
    sym_set(A,n,2,1,5); 
    sym_set(A,n,2,2,6);
    sym_set(A,n,3,0,7); 
    sym_set(A,n,3,1,8); 
    sym_set(A,n,3,2,9); 
    sym_set(A,n,3,3,10);
    sym_print(A,n);
    delete[] A; return 0;
}
