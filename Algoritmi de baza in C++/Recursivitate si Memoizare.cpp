#include <iostream>
using namespace std;

/*
 *  Recursivitate
 *
 *  -> proprietatea unor noriuni de a se defini prin ele insele
 *
 *  -> La matematica, sirurile recurente reprezinta recursivitati:
 *      Sirul lui Fibonacci -> f(n) = f(n-1) + f(n-2), f(1) = f(0) = 1;
 *      Factorialele -> f(n) = n * f(n-1), f(1) = f(0) = 1;
 *
 *                      f(n)
 *              f(n-1)         f(n-2)
 *         f(n-2)   f(n-3)  f(n-3)  f(n-4)
 *
 *   
 *
 */

int fibo(int n){
    if(n == 0 || n == 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
} // O(2^n)

int main(){



    return 0;
}









int doiLa(int n){
    if(n == 0)
        return 1;
    return doiLa(n-1) * 2;
} // O(n) -> liniara

int doiLa1(int n){
    if(n == 0)
        return 1;
    return doiLa1(n-1) + doiLa1(n-1);
} // O(2^n) -> exponentiala

int main(){



    return 0;
}








int doiLa(int n){
    if(n == 0)
        return 1;
    return doiLa(n-1) * 2;
} // O(n) -> liniara

int doiLa1(int n){
    if(n == 0)
        return 1;
    return doiLa1(n-1) + doiLa1(n-1);
} // O(2^n) -> exponentiala

int a_la_b(int a, int b){
    if(b == 0)
        return 1;
    int put = a_la_b(a, b/2);
    if(b % 2 == 0)
        return put * put;
    return a * a_la_b(a, b-1);
} // Radica pe a la puterea b in O(log2(b))

int a_la_b_2(int a, int b){
    if(b == 0)
        return 1;
    return a * a_la_b_2(a, b-1);
} // O(b)

int main(){



    return 0;
}









#include <iostream>
using namespace std;

/*
 *  Fotbal
 *
 *              10 - 10
 *    10 - 9               9 - 10
 * 
 * 10 - 8   9 - 9      9 - 9    8-10
 */

int cnt;
int nr_mod[11][11];

int scor(int a, int b){
    cnt++;
    if(a == 0 || b == 0)
        return 1;
    if(nr_mod[a-1][b] == 0)
        nr_mod[a-1][b] = scor(a-1, b);
    if(nr_mod[a][b-1] == 0)
        nr_mod[a][b-1] = scor(a, b-1);
    return nr_mod[a-1][b] + nr_mod[a][b-1];
} // memoizare -> stocarea rezultatelor unor functii recursive cu scopul de a evita
// dezvolatrea exponentiala a apelurilor

int main(){

    int a, b;
    cin >> a >> b;
    cout << scor(a, b) << ' ' << cnt;

    return 0;
}









int fibo[45];

int f(int n){
    if(n <= 1)
        return 1;
    if(fibo[n-1] == 0)
        fibo[n-1] = f(n-1);
    if(fibo[n-2] == 0)
        fibo[n-2] = f(n-2);
    return fibo[n-1] + fibo[n-2];
} // complexitate liniara datorita evitarii repetarii apelurilor inutile

int main(){

    int a;
    cin >> a;
    cout << f(a);

    return 0;
}









#include <iostream>
#include <cmath>
using namespace std;

/*  pattern1
 *
 */

int a[512][512];

void pattern(int n, int x1, int y1, int x2, int y2){
    if(n == 0)
        return ;
    int xmij = (x1 + x2) / 2;
    int ymij = (y1 + y2) / 2;
    a[xmij][ymij] = n;
    pattern(n-1, x1, y1, xmij-1, ymij-1);
    pattern(n-1, x1, ymij+1, xmij-1, y2);
    pattern(n-1, xmij+1, y1, x2, ymij-1);
    pattern(n-1, xmij+1, ymij+1, x2, y2);
}

int main(){

    int n;
    cin >> n;
    pattern(n, 1, 1, pow(2, n) - 1, pow(2, n) - 1);

    for(int i = 1; i <= pow(2, n) - 1; i ++, cout << endl)
        for(int j = 1; j <= pow(2, n) - 1; j ++)
            cout << a[i][j] << ' ';

    return 0;
}









#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;

ifstream cin("sierpinski.in");
ofstream cout("sierpinski.out");

/*  sierpinski
 *
 */

bitset<730> a[730];

void pattern(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2)
        return ;
    int lat = (x2 - x1 + 1) / 3;
    pattern(x1, y1, x1 + lat - 1, y1 + lat - 1);
    pattern(x1, y1 + lat, x1 + lat - 1, y1 + 2 * lat - 1);
    pattern(x1, y1 + 2 * lat, x1 + lat - 1, y2);
    pattern(x1 + lat, y1, x1 + 2 * lat - 1, y1 + lat - 1);

    for(int i = x1 + lat; i <= x1 + 2 * lat - 1; ++i)
        for(int j = y1 + lat; j <= y1 + 2 * lat - 1; ++j)
            a[i][j] = 1;

    pattern(x1 + lat, y1 + 2 * lat, x1 + 2 * lat - 1, y2);
    pattern(x1 + 2 * lat, y1, x2, y1 + lat - 1);
    pattern(x1 + 2 * lat, y1 + lat, x2, y1 + 2 * lat - 1);
    pattern(x1 + 2 * lat, y1 + 2 * lat, x2, y2);
}

int main(){

    int n;
    cin >> n;
    pattern(1, 1, pow(3, n), pow(3, n));

    for(int i = 1; i <= pow(3, n); i ++, cout << endl)
        for(int j = 1; j <= pow(3, n); j ++)
            cout << a[i][j] << ' ';

    return 0;
}