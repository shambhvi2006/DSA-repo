#include <iostream>
using namespace std;

// index: i==j -> idx=i, else zero
void d_set(int* a,int n,int i,int j,int val){ 
    if(i==j) a[i]=val; 
}
int  d_get(int* a,int n,int i,int j){ 
    return (i==j)? a[i] : 0; 
}

void d_print(int* a,int n){
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j) 
        cout<<d_get(a,n,i,j)<<" "; 
    cout<<"\n";
}
}

int main(){
    int n=4; int* A=new int[n]();            // n elements
    d_set(A,n,0,0,5); 
    d_set(A,n,1,1,7); 
    d_set(A,n,2,2,9); 
    d_set(A,n,3,3,2);
    d_print(A,n);
    delete[] A;
    return 0;
}
