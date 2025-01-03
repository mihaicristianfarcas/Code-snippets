#include <iostream>
using namespace std;

/*
    Divizibilitate
    
    1) Parcurgerea divizorilor unui numar
    2) Cmmdc si Cmmmc
    3) Primalitate
    4) Factorizare
    
    5)* - Extra - Legaturile dintre 1) si 4)
    
    Divizorii unui numar:
    D12={1,2,3,4,6,12};
    12 = 1 * 12 
    12 = 2 * 6
    12 = 3 * 4
    12 = d * (12 / d)
*/

void afisarea_divizorilor(int n){
    for(int d = 1; d <= n; ++d)
        if(n % d == 0)
            cout << d << ' ';
} // Complexitate: O(n) - liniara

void afisarea_divizorilor1(int n){
    for(int d = 1; d * d < n; ++d)
        if(n % d == 0 && d * d < n)
            cout << d << ' ' << n / d << ' ';
        else if(d * d == n)
            cout << d << ' ';
} // Complexitate: O(sqrt(n)) - radical - mult mai bun

void afisarea_divizorilor1_rec(int n, int d = 1){
    if(d * d > n)
        return ;
    if(n % d == 0 && d * d < n)
        cout << d << ' ' << n / d << ' ';
    else if(d * d == n)
        cout << d << ' ';
    afisarea_divizorilor1_rec(n, d + 1);
} // identic cu varianta iterativa

void afisarea_divizorilor2_rec(int n, int d = 1){
    if(d * d >= n){
        if(d * d == n)
            cout << d << ' ';
        return ;
    }
    if(n % d == 0)
        cout << d << ' ';
    afisarea_divizorilor2_rec(n, d+1);
    if(n % d == 0)
        cout << n / d << ' ';
} // cea mai smechera functie =))

int main(){
    afisarea_divizorilor1_rec(12);
    return 0;
}









#include <iostream>
using namespace std;

/*
    Divizibilitate
    
    1) Parcurgerea divizorilor unui numar
    2) Cmmdc si Cmmmc
    3) Primalitate
    4) Factorizare
    
    5)* - Extra - Legaturile dintre 1) si 4)
    
    Cel mai mare divizor comun:
    D12={1,2,3,4,6,12};
    D20={1,2,4,5,10,20};
    
    Algoritmul lui Euclid
    - pentru a calcula cmmdc a 2 numere este suficient sa scadem din cel mai mare
    pe cel mai mic pana cand cele 2 numere ajung egale => acela e cmmdc-ul
    Ex: 12, 20 -> 12, 8 -> 4, 8 -> 4, 4
    Ex: 102, 3 -> 3, 0 
*/

int cmmdc(int a, int b){
    int maxi = 1;
    for(int d = 1; d * d <= a; ++d){
        if(a % d == 0){
            int d1 = d;
            int d2 = (a / d);
            if(b % d1 == 0 && d1 > maxi)
                maxi = d1;
            if(b % d2 == 0 && d2 > maxi)
                maxi = d2;
        }
    }
    return maxi;
} // Complexitate: O(sqrt(n))

int cmmdc_scaderi(int a, int b){
    while(a != b)
        if(a > b)
            a -= b;
        else b -= a;
    return a;
} // Complexitate: O(max(a, b))
// Daca a sau b sunt 0 => ciclu infinit

int cmmdc_scaderi_rec(int a, int b){
    if(a == b)
        return b;
    if(a > b)
        return cmmdc_scaderi_rec(a - b, b);
    return cmmdc_scaderi_rec(a, b - a);
} // acelasi scenariu ca sus

int cmmdc_impartiri(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
} // Complexitate -> foarte foarte bun
// cel mai bun posibil

int cmmdc_impartiri_rec(int a, int b){
    if(b == 0)
        return a;
    return cmmdc_impartiri_rec(b, a % b);
} // aceiasi poveste ...

int main(){
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Divizibilitate
    
    1) Parcurgerea divizorilor unui numar
    2) Cmmdc si Cmmmc
    3) Primalitate
    4) Factorizare
    
    5)* - Extra - Legaturile dintre 1) si 4)
    
    Cel mai mare divizor comun:
    D12={1,2,3,4,6,12};
    D20={1,2,4,5,10,20};
    
    Cel mai mic multiplu comun
    
    cmmmc(a, b) = a * b / cmmdc(a, b); !!
*/

int cmmdc(int a, int b){
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int cmmmc(int a, int b){
    return a / cmmdc(a, b) * b;
} // atentie la ordine

int main(){
    cout << cmmmc(12, 20);
    return 0;
}









#include <iostream>
using namespace std;

/*
    Divizibilitate
    
    1) Parcurgerea divizorilor unui numar
    2) Cmmdc si Cmmmc
    3) Primalitate
    4) Factorizare
    
    5)* - Extra - Legaturile dintre 1) si 4)
    
    Factorizare:
    - scrierea numerelor sub forma de produs de numere prime se numeste factorizare 
    - cu ajutorul scrierii sub forma de produs de numere prime, putem deduce diverse
    proprietati ale numerelor
    Ex. 120 = 2^3 * 3 * 5
    120 | 2
    60  | 2
    30  | 2
    15  | 3
    5   | 5
    1   | -
*/

void factorizare(int n){
    int d = 2;
    while(n > 1){
        int p = 0;
        while(n % d == 0)
            n /= d, p++;
        if(p != 0)
            cout << d << ' ' << p << endl;
        d++;
        if(d * d > n)
            d = n;
    }
}

void factorizare_rec(int n, int d = 2){
    if(n == 1)
        return ;
    int p = 0;
    while(n % d == 0)
        n /= d, p++;
    if(p != 0)
        cout << d << ' ' << p << endl;
    if(d * d > n)
        factorizare_rec(n, n);
    else factorizare_rec(n, d+1);
}

void factorizare2_rec(int n, int d = 2, int p = 0){
    if(n == 1)
        return ;
    if(n % d == 0){
        p++;
        n /= d;
        if(n % d != 0)
            cout << d << ' ' << p << endl;
        factorizare2_rec(n, d, p);
    }
    else{
        if(d * d > n)
            factorizare2_rec(n, n, 0);
        else factorizare2_rec(n, d+1, 0);
    }
} // aceiasi Marie cu alta palarie

int main(){
    factorizare_rec(120);
    return 0;
}









#include <iostream>
using namespace std;

/*
    Divizibilitate

    5) Legaturile dintre scrierea in factori primi a unui numar si divizorii acestuia

    120 = 2^3 * 3 * 5
    nr_div(120) = 4 * 2 * 2 = 16

    n = 2^a * 3^b * 5^c
    n = d * (n / d)

    d * (n / d) = 2^a * 3^b * 5^c
    
    d = 2^a1 * 3^b1 * 5^c1

        a1 = {0,1,2,...,a}
        b1 = {0,1,2,...,b}
        c1 = {0,1,2,...,c}

        Cate valori distincte pentru d exista?
            - (a + 1) * (b + 1) * (c + 1)
    
    ______________________________________

    Din scrierea in factori primi:
        - pot cunoaste numarul de valori 0 in care se termina numarul - min(put2, put5)
        - pot cunoaste daca este divizbil cu o anumita valoare
        - pot cunoaste daca este prim - are un singur factor prim
*/

int nr_div(int n){
    int d = 2, cnt = 1;
    while(n > 1){
        int p = 0;
        while(n % d == 0)
            p++, n /= d;
        if(p)
            cnt *= (p + 1);
        d++;
        if(d * d > n)
            d = n;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout << nr_div(n);    
    return 0;
}









#include <iostream>
using namespace std;

/*
    PRIM001

    n = 2^a * 3^b * 5^c

    n^n = 2^(a*n) * 3^(b*n) * 5^(c*n)
    nr_div(n^n) = (a*n + 1) * (b*n + 1) * (c*n + 1) 
*/

long long nr_div_nlan(long long n){
    long long d = 2;
    long long cn = n;
    long long rez = 1;
    while(n > 1){
        int p = 0;
        while(n % d == 0)
            n /= d, p++;
        if(p){
            rez *= (p * cn + 1);
            rez = rez % 59999;
        }
        d++;
        if(d * d > n)
            d = n;
    }
    return rez;
}

int main(){
    long long n;
    cin >> n;
    cout << nr_div_nlan(n);
    return 0;
}









#include <iostream>
using namespace std;

/*
    SUMA_PERM_N9
    
    123
    132
    213
    231
    312
    321
    ___
   1332

    sum_col = sum_cif(n) * (nrcif(n) - 1)!
*/

int sum_cif(int n){
    if(n == 0)
        return 0;
    return sum_cif(n / 10) + n % 10;
}

int nr_cif(int n){
    if(n <= 9)
        return 1;
    return 1 + nr_cif(n / 10);
}

int fact(int n){
    if(n <= 1)
        return 1;
    return fact(n-1) * n;
}

int main(){
    int n;
    cin >> n;
    int sum_col = sum_cif(n) * fact(nr_cif(n) - 1);
    int transport = 0;
    long long sum = 0, p = 1;
    for(int i = 1; i <= nr_cif(n); ++i){
        int cif = (sum_col + transport) % 10;
        transport = (sum_col + transport) / 10;
        sum = sum + cif * p;
        p *= 10;
    }
    sum = sum + transport * p;
    cout << sum;
    return 0;
}









#include <iostream>
using namespace std;

/*
    Subiect Bac Simulare 2022
    S3.P3.
*/

int main(){
    int n;
    cin >> n;
    int cnt3 = 0, cnt5 = 0;
    for(int i = 3; i <= n; i += 3){
        int cp = i;
        while(cp % 3 == 0)
            cp /= 3, cnt3++;
    } // O(n * log3(n))
    for(int i = 5; i <= n; i += 5){
        int cp = i;
        while(cp % 5 == 0)
            cp /= 5, cnt5++;
    } // O(n * log5(n))
    cout << min(cnt3/2, cnt5);
    return 0;
}









#include <iostream>
using namespace std;

/*
    Subiect Bac Simulare 2022
    S3.P3.

    Cum determin puterea la care apare 3 in n! ?

    1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15
    0   0   1   0   0   1   0   0   2    0    0    1    0    0    1

    Cati multipli are 3 pana la n ? -> n / 3
    Cati multipli are 9 pana la n ? -> n / 9

    Teorema lui Legendre -> puterea la care apare un factor prim in
    descompunerea in factori primi a lui n! este egala cu suma
    partilor intregi a impartirii lui n, pe rand, la toate puterile
    factorului prim, mai mici sau egale decat n.
*/

int main(){
    int n;
    cin >> n;
    int cnt3 = 0, cnt5 = 0;
    int put3 = 3, put5 = 5;
    while(put3 <= n){
        cnt3 += n / put3;
        put3 *= 3;
    } // O(log3(n))
    while(put5 <= n){
        cnt5 += n / put5;
        put5 *= 5;
    } // O(log5(n))
    cout << min(cnt3 / 2, cnt5);
    return 0;
}









#include <iostream>
using namespace std;

/*
    DivizoriXYZ

    x = n/a
    y = n/b
    z = n/c

    x + y + z = n
    n/a + n/b + n/c = n
    n * a * b + n * b * c + n * a * c = n * a * b * c
    a * b + a * c + b * c = a * b * c
*/

int main(){
    int n;
    cin >> n;
    if(n % 6 == 0)
        cout << n / 6 << ' ' << n / 3 << ' ' << n / 2 << endl;
    else cout << "nu exista";
    return 0;
}









#include <iostream>
using namespace std;

/*
    Numere22
*/

int main(){
    int p, q, n, cntp = 0, cntq = 0;
    cin >> p >> q >> n;
    int x;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        while(x % p == 0)
            x /= p, cntp ++;
        while(x % q == 0)
            x /= q, cntq ++;
    }
    cout << min(cntp, cntq);
    return 0;
}









#include <iostream>
using namespace std;

/*
    FactZero1
*/

int main(){
    int n;
    cin >> n;
    int put5 = 5, cnt5 = 0;
    while(put5 <= n){
        cnt5 += n / put5;
        put5 *= 5;
    }
    int prod = 1;
    for(int i = 2; i <= n; ++i){
        int cp = i;
        while(cp % 5 == 0)
            cp /= 5;
        while(cnt5 != 0 && cp % 2 == 0)
            cp /= 2, cnt5--;
        prod *= cp;
        prod %= 10;
    }
    cout << prod;
    return 0;
}









#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int prod = 1;
    int x, cnt5 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        int d = 2;
        while(x > 1){
            int p = 0;
            while(x % d == 0)
                x /= d, p++;
            if(p){
                if(d == 5)
                    cnt5 += p;
                else if(d == 2)
                    cnt2 += p;
                else{
                    for(int j = 1; j <= p; ++j)
                        prod *= (d % 10), prod %= 10;
                }
            }
            d++;
            if(d * d > x)
                d = x;
        }
    }
    
    if(cnt5 > cnt2)
        for(int i = cnt2 + 1; i <= cnt5; ++i)
            prod *= 5, prod %= 10;
    else
        for(int i = cnt5 + 1; i <= cnt2; ++i)
            prod *= 2, prod %= 10;
            
    cout << prod;
    
    return 0;
}