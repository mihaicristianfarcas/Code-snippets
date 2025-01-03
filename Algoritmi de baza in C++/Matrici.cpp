#include <iostream>
using namespace std;

/*
 *  Matrici
 *  1) Matrici Oarecare
 *  2) Matrici Patratice
 *
 *  Matrici Patratice:
 *
 *  x 1 1 1 x
 *  4 x 1 x 2
 *  4 4 x 2 2
 *  4 x 3 x 2
 *  x 3 3 3 x
 *
 *
 *  1) Diagonala principala -> a[i][j], daca i == j
 *  2) Diagonala secundara ->  a[i][j], daca i + j == n + 1, daca indexarea e de la 1
 *                             a[i][j], daca i + j == n - 1, daca indexarea e de la 0
 *
 *  Pozitionarea elementelor fata de diagonale:
 *      1) a[i][j] -> deasupra diagonalei principale daca: j > i
 *      2) a[i][j] -> sub diagonala principala daca      : j < i
 *      3) a[i][j] -> deasupra diagonalei secundare daca : i + j < n + 1
 *      4) a[i][j] -> sub diagonala secundra daca        : i + j > n + 1
 *
 *  Identificarea zonei:
 *      ZONA 1, daca i < j && i + j < n + 1
 *      ZONA 2, daca i < j && i + j > n + 1
 *      ZONA 3, daca i > j && i + j > n + 1
 *      ZONA 4, daca i > j && i + j < n + 1
 *
 *   Ex1) Sa se scrie o secventa de instructiuni care calculeaza suma elementelor de pe diagonala secundara.
 *   int sum = 0;
 *   for(int i = 1; i <= n; ++i)
 *      sum += a[i][n - i + 1];
 *
 *   Ex2) Sa se scrie o secventa .... zona 2.
 *   int sum = 0;
 *   for(int i = 2; i < n; ++i)
 *      for(int j = max(n - i + 2, i + 1); j <= n; ++j)
 *          sum += a[i][j];
 *
 *   Ex3) Sa se scrie o secventa .... zona 1.
 *   int sum = 0;
 *   for(int i = 1; i <= n / 2; ++i)
 *      for(int j = i + 1; j <= n - i; ++j)
 *          sum += a[i][j];
 *
 *   Ex4) Sa se scrie o secventa .... zona 4.
 *   int sum = 0;
 *   for(int i = 2; i <= n - 1; ++i)
 *      for(int j = 1; j < i && j < n - i + 1; ++j)
 *          sum += a[i][j];
 *         
 *   Ex5) Sa se scrie o secventa .... zona 3.
 *   int sum = 0;
 *   for(int i = n / 2 + 2; i <= n; ++i)
 *      for(int j = n - i + 2; j < i; ++j)
 *          sum += a[i][j];
 *          
 *   Simetrie:
 *   Simetricul lui a[i][j] fata de diagonala principala este a[j][i]
 *   Simetricul lui a[i][j] fata de diagonala secundara este a[n-j+1][n-i+1]
 *
 */

int main() {



    return 0;
}









#include <iostream>
#include <cmath>
using namespace std;

// Se da o matrice patratica si se cere permutarea spre dreapta a liniei i cu i pozitii
/*
 *  EX:
 *  1 2 3 4 5
 *  1 2 3 4 5
 *  3 4 5 1 2
 *  1 2 3 4 5
 *  1 2 3 4 5
 *
 * R:
 *  5 1 2 3 4
 *  4 5 1 2 3
 *  3 4 5 1 2
 *  2 3 4 5 1
 *  1 2 3 4 5
 *
 */

int n, a[1001][1001], aux[1001];

int main(){

    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for(int i = 1; i <= n; ++i){
        int ind = 0;
        for(int j = n - i + 1; j <= n; ++j)
            aux[++ind] = a[i][j];
        for(int j = n - i; j >= 1; --j)
            a[i][j + i] = a[i][j];
        for(int j = 1; j <= i; ++j)
            a[i][j] = aux[j];
    }

    for(int i = 1; i <= n; ++i, cout << endl)
        for(int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';

    return 0;
}










