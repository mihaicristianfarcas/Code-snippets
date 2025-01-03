#include <iostream>
#include <algorithm>
using namespace std;

/*
    Frecvente si Vectori Caracteristici

    -> diferenta dintre vec. de frecv. si vec. caracteristic

    1) COUNTING SORT -> Sortare prin numarare

    Se da un sir cu n elemente numere naturale pana in 1.000.000 si se cere sortarea
    acestora.
*/

int n, x;
int f[1000001];

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x, f[x]++;
    
    for(int i = 1; i <= 1000000; ++i)
        while(f[i] != 0)
            cout << i << ' ', f[i]--;

    // O(n) -> complexitatea de sortare =)

    return 0;
}