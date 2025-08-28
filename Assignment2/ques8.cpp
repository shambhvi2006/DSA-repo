#include <iostream>
using namespace std;

// Simple merge sort to avoid extra headers
void merge(long long a[], long long tmp[], int l, int m, int r){
    int i=l, j=m+1, k=l;
    while(i<=m && j<=r) tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while(i<=m) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int p=l;p<=r;++p) a[p]=tmp[p];
}
void msort(long long a[], long long tmp[], int l, int r){
    if(l>=r) return;
    int m=(l+r)/2;
    msort(a,tmp,l,m); msort(a,tmp,m+1,r); merge(a,tmp,l,m,r);
}

int main(){
    int n; cin >> n;
    long long* a = new long long[n];
    for(int i=0;i<n;++i) cin >> a[i];
    long long* tmp = new long long[n];
    msort(a,tmp,0,n-1);
    int distinct = (n>0)?1:0;
    for(int i=1;i<n;++i) if(a[i]!=a[i-1]) ++distinct;
    cout << distinct << "\n";
    delete[] a; delete[] tmp;
    return 0;
}
