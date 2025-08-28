#include <iostream>
using namespace std;

int ut_size(int n){ 
    return n*(n+1)/2; 
}
int ut_index(int n,int i,int j){
    if(i>j) return -1;
    int b = i*n - (i*(i-1))/2;
    return b + (j - i);
}
void ut_set(int* a,int n,int i,int j,int val){ 
    int k=ut_index(n,i,j); 
    if(k!=-1) a[k]=val; 
}
int  ut_get(int* a,int n,int i,int j){ 
    int k=ut_index(n,i,j); 
    return (k==-1)?0:a[k]; 
}

void ut_print(int* a,int n){
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j) 
        cout<<ut_get(a,n,i,j)<<" "; 
    cout<<"\n"; 
}
}

int main(){
    int n=4; int* A=new int[ut_size(n)]();
    ut_set(A,n,0,0,1); ut_set(A,n,0,1,2); ut_set(A,n,0,2,3); ut_set(A,n,0,3,4);
    ut_set(A,n,1,1,5); ut_set(A,n,1,2,6); ut_set(A,n,1,3,7);
    ut_set(A,n,2,2,8); ut_set(A,n,2,3,9);
    ut_set(A,n,3,3,10);
    ut_print(A,n);
    delete[] A; return 0;
}
