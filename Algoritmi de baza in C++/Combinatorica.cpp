#include <iostream>
using namespace std;

/*
 *  Combinatorica:
 *  1) Permutari
 *  2) Aranjamente
 *  3) Combinari
 * 
 *  PERMUTARI
 *  -> n! = 1 * 2 * ... * n
 */

int permutari(int n){
    if(n <= 1)
        return 1;
    return n * permutari(n-1);
} // O(n)

int permutari1(int n){
    int prod = 1;
    for(int i = 2; i <= n; ++i)
        prod *= i;
    return prod;
} // O(n)

int main() {
    
    return 0;
}









#include <iostream>
using namespace std;

/*
 *  Combinatorica:
 *  1) Permutari
 *  2) Aranjamente
 *  3) Combinari
 *
 *  Aranjamente - A(n, k) = n! / (n-k)! = (n-k+1) * (n-k+2) * ... * n
 */

int permutari1(int n){
    int prod = 1;
    for(int i = 2; i <= n; ++i)
        prod *= i;
    return prod;
} // O(n)

int aranjamente(int n, int k){
    return permutari1(n) / permutari1(n-k);
} // O(n)
// E posibil sa depasim limitele tipurilor de date cand calculam Aranjamente asa, deoarece n! poate fi foarte mare
// In acelasi timp, rezultatul poate fi foarte mic

int aranjamente1(int n, int k){
    int prod = 1;
    for(int i = n - k + 1; i <= n; ++i)
        prod *= i;
    return prod;
} // O(n)
// Aceasta functie este construita in asa fel incat daca rezultatul se incadreaza pe un anumit tip de date
// atunci stim sigur ca il va calcula corect

int aranjamente2(int n, int k){
    if(k == 0)
        return 1;
    return (n - k + 1) * aranjamente2(n, k-1);
} // O(n)
// Varianta recursiva

int main() {

    return 0;
}









#include <iostream>
using namespace std;

/*
 *  Combinatorica:
 *  1) Permutari
 *  2) Aranjamente
 *  3) Combinari
 *
 *  Combinari: C(n, k) = n! / (k! * (n-k)!) = A(n, k) / k! = (n-k+1) * (n-k+2) * ... * n / k!
 *  Triunghiul lui Pascal:
 *      C(n, k) = C(n-1, k-1) + C(n-1, k)
 *
 */

int permutari(int n){
    int prod = 1;
    for(int i = 2; i <= n; ++i)
        prod *= i;
    return prod;
} // O(n)

int aranjamente(int n, int k){
    int prod = 1;
    for(int i = n - k + 1; i <= n; ++i)
        prod *= i;
    return prod;
} // O(n)

int combinari(int n, int k){
    return aranjamente(n, k) / permutari(k);
} // Exact ca la aranjamente, calculul combinarinarilor este afectat de rezultatele intermediare mari pe care
// le-am putea avea

int cnt = 0, Comb[1001][1001];

int combinari1(int n, int k){
    cnt++;
    if(n == 1 || n == k || k == 0)
        return 1;
    if(Comb[n-1][k-1] == 0)
        Comb[n-1][k-1] = combinari1(n-1, k-1);
    if(Comb[n-1][k] == 0)
        Comb[n-1][k] = combinari1(n-1, k);
    return Comb[n-1][k-1] + Comb[n-1][k];
} // folosim memoizare pentru a evita efectuarea unui numar foarte mare de apeluri recursive

int combinari2(int n, int k){

    for(int i = 0; i <= n; ++i)
        Comb[i][0] = Comb[i][i] = 1;

    for(int i = 2; i <= n; ++i)
        for(int j = 1; j < i; ++j)
            Comb[i][j] = Comb[i-1][j-1] + Comb[i-1][j];

    return Comb[n][k];

} // O(n) -> varianta cu dinamica

int main() {

    cout << combinari1(20, 5) << ' ' << cnt;

    return 0;
}









#include <iostream>
using namespace std;

/*
 *  Triunghiul lui pascal
 *
 */

void pascal(int niv, int a[]){
    int level = 0;
    a[0] = 1;
    while(level < niv){
        level ++;
        a[level] = 1;
        for(int i = level - 1; i >= 1; --i)
            a[i] = a[i-1] + a[i];
    }
}

int main() {

    int a[101], n;
    cin >> n;
    pascal(n,a);
    for(int i = 0; i <= n; ++i)
        cout << a[i] << ' ';

    return 0;
}









#include <iostream>
using namespace std;

/*
 *  Triunghiul lui pascal
 *
 */

int C(int n, int k){
    if(n == k || n == 1 || k == 0)
        return 1;
    return C(n-1, k) + C(n-1, k-1);
}

void pascal(int niv, int a[]){
    for(int i = 0; i <= niv; ++i)
        a[i] = C(niv, i);
}

int main() {

    int a[101], n;
    cin >> n;
    pascal(n,a);
    for(int i = 0; i <= n; ++i)
        cout << a[i] << ' ';

    return 0;
}