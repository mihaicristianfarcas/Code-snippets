#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

/*  Operatii pe biti si masca de biti
 *
 *  Se citesc de la tastatura n elemente cu valori mai mici ca 30 si se cere sa se afiseze pe ecran, elementele care
 *  au aparut in sir cel putin o data in ordine crescatoare.
 *
 *  SHIFTARE SPRE DREAPTA
 *  (1 << x) -> 2^x
 *
 *  SHIFTARE SPRE STANGA
 *  (x >> y) -> x / 2^y
 *
 *  OPERATORUL &
 *  -> se foloseste la verificarea unui bit
 *  x & (1 << y) -> este egal cu (1 << y) daca y apare in masca 
 *               -> este egal cu 0 daca y nu apare
 *               
 *  OPERATORUL |
 *  -> se foloseste pentru setarea unui bit
 *  msk = msk | (1 << y) -> este folosit pentru setarea cu 1 a bit-ului y
 *  
 *  
 */

int main(){

    unsigned int F; // vector caracteristic pentru elemente pana la 31

    int n, x;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        // setam x-ul in masca
        F = (F | (1 << x)); // setarea bit-ului x
    }

    for(int i = 0; i <= 30; ++i)
        if((F & (1 << i)) == (1 << i))
            cout << i << ' ';

    return 0;
}