#include <iostream>
using namespace std;

int lt_size(int n){ 
    return n*(n+1)/2; 
}
int lt_index(int n,int i,int j){ 
    return (i>=j)? (i*(i+1))/2 + j : -1; 
}

void lt_set(int* a,int n,int i,int j,int val){ 
    int k=lt_index(n,i,j); 
    if(k!=-1) a[k]=val; 
}
int  lt_get(int* a,int n,int i,int j){ 
    int k=lt_index(n,i,j); 
    return (k==-1)?0:a[k]; 
}

void lt_print(int* a,int n){
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j) 
        cout<<lt_get(a,n,i,j)<<" "; 
    cout<<"\n"; }
}

int main(){
    int n=4; int* A=new int[lt_size(n)]();
    lt_set(A,n,0,0,1); lt_set(A,n,1,0,2); lt_set(A,n,1,1,3);
    lt_set(A,n,2,0,4); lt_set(A,n,2,1,5); lt_set(A,n,2,2,6);
    lt_set(A,n,3,0,7); lt_set(A,n,3,1,8); lt_set(A,n,3,2,9); lt_set(A,n,3,3,10);
    lt_print(A,n);
    delete[] A; return 0;
}
