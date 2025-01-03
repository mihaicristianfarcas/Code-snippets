#include <iostream>
using namespace std;

// DIVIDE ET IMPERA
/*
    toatePare(st, dr) = toatePare(st, mij) && toatePare(mij+1, dr)
    existaPare(st, dr) = existaPare(st, mij) || existaPare(mij+1, dr)
    
    ordonat(st, dr) = ordonat(st, mij) && ordonat(mij+1, dr) && a[mij] <= a[mij+1]
*/

int a[1001];

bool toatePare(int st, int dr){
    if(st == dr)
        return a[st] % 2 == 0;
    int mij = (st + dr) / 2;
    return toatePare(st, mij) && toatePare(mij+1, dr);
}

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    cout << toatePare(1, n);
    
    return 0;
}