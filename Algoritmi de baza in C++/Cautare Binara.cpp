#include <iostream>
using namespace std;

/*
    Cautare Binara

    x = 68

    [1, 100] -> [51, 100] -> [51, 74] -> [63, 74] -> 68
*/

bool CB(int a[], int n, int val){
    int st = 1, dr = n;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] == val)
            return true;
        else if(val < a[mij])
            dr = mij - 1;
        else st = mij + 1;
    }
    return false;
} // algoiritmul clasic - verifica daca o valoarea apre intr-un sir

int CB1(int a[], int n, int val){
    int st = 1, dr = n;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] == val)
            return mij;
        else if(val < a[mij])
            dr = mij - 1;
        else st = mij + 1;
    }
    return -1;
} // cautare binara care returneaza pozitia unui element

int main(){

    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    cout << CB1(a, n, 3);

    return 0;
}









#include <iostream>
using namespace std;

/*
    Cautare Binara

    Cautam Binar cel mai apropiat element ca valoare
    de elementul nostru.

    1) Cel mai mic, mai mare sau egal decat val
    2) Cel mai mare, mai mic sau egal decat val
   
*/

int CelMaiMicMaiMareSauEgal(int a[], int n, int val){
    int st = 1, dr = n;
    int poz = n + 1;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] >= val){
            poz = mij;
            dr = mij - 1;
        }
        else st = mij + 1;
    }
    if(poz == n+1)
        return -1;
    return poz;
}

int CelMaiMareMaiMicSauEgal(int a[], int n, int val){
    int st = 1, dr = n;
    int poz = 0;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] <= val){
            poz = mij;
            st = mij + 1;
        }
        else dr = mij - 1;
    }
    if(poz == 0)
        return -1;
    return poz;
}

int main(){

    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    cout << CelMaiMareMaiMicSauEgal(a, n, 3) << endl
         << CelMaiMicMaiMareSauEgal(a, n, 3);

    return 0;
}









#include <iostream>
using namespace std;

/*
    Cautare Binara

    Sa se determine utilizand cb de cate ori apare
    o valoare data intr-un sir ordonat.

    Ex: 1 2 3 3 3 4 4 5 6 6 6 7 8 9
        3
        3
        4
        6
    
    R:  3
        2
        3

    Cautare binara care identifica prima aparitie
    a unei valori intr-un sir.
    Cautare binara care identifica ultima aparitie
    a unei valori intr-un sir.
   
*/

int CB_pa(int a[], int n, int val){
    int st = 1, dr = n;
    int poz = -1;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] == val){
            poz = mij;
            dr = mij - 1;
        }
        else if(a[mij] > val)
            dr = mij - 1;
        else st = mij + 1;
    }
    return poz;
}

int CB_ua(int a[], int n, int val){
    int st = 1, dr = n;
    int poz = -1;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(a[mij] == val){
            poz = mij;
            st = mij + 1;
        }
        else if(a[mij] > val)
            dr = mij - 1;
        else st = mij + 1;
    }
    return poz;
}

int main(){

    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    cout << CB_ua(a, n, 3) - CB_pa(a, n, 3) + 1;

    return 0;
}