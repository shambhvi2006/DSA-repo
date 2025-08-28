#include <iostream>
using namespace std;
//A tri-diagonal matrix has 3n−2 useful elements.
//We compress it into a 1D array lower then main then upper
//Index formula picks the right position depending on whether (i,j) is below, on, or above the main diagonal.

int td_size(int n){ 
    return 3*n-2; 
}
//we are making the matrix into one array
int td_index(int n,int i,int j){
    if(i==j+1) return i-1;
    if(i==j)   return (n-1)+i;
    if(j==i+1) return (2*n-1)+i;
    return -1; // zero element
}
//setting the values in the array
void td_set(int* a,int n,int i,int j,int val){
    int k=td_index(n,i,j); 
    if(k!=-1) {
        a[k]=val;
    }
}
//when we dont have the value we check the index value and return 0
int  td_get(int* a,int n,int i,int j){
    int k=td_index(n,i,j); 
    return (k==-1)?0:a[k];
}

void td_print(int* a,int n){
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j) 
            cout<<td_get(a,n,i,j)<<" "; 
        cout<<"\n"; 
    }
}

int main(){
    int n=4; int* A=new int[td_size(n)]();   // 3n-2 elements
    td_set(A,n,0,0,4); 
    td_set(A,n,1,0,1); 
    td_set(A,n,1,1,5);
    td_set(A,n,0,1,2); 
    td_set(A,n,2,1,3); 
    td_set(A,n,2,2,6);
    td_set(A,n,1,2,7); 
    td_set(A,n,3,2,8); 
    td_set(A,n,3,3,9);
    td_set(A,n,3,1,9);

    td_print(A,n);
    delete[] A;
    return 0;
}
