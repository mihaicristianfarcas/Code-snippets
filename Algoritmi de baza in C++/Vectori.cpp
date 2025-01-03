 #include <iostream>
using namespace std;

/*
    Vectori - Tablouri Unidimensionale
    
    1) Stergeri si Inserari
    2) Ordonarea elementelor - Sortari
    3) Cautari de elemente - CB si CS
    4) Interclasarea
    5) Frecvente si vectori Caracteristici
*/

int a[1001];
int n;

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> i[a]; // *(i + a)

    for(int i = 1; i <= n; ++i)
        cout << *(a + i) << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Vectori - Tablouri Unidimensionale
    
    1) Stergeri si Inserari
    2) Ordonarea elementelor - Sortari
    3) Cautari de elemente - CB si CS
    4) Interclasarea
    5) Frecvente si vectori Caracteristici
*/

/*
    * - operator de dereferentiere
    & - operator de referentiere
*/

int a[1001];
int n;
// 1 2 3 4 5

void stergere_element(int *a, int &n, int poz){ // int a[]
    for(int i = poz + 1; i <= n; ++i)
        a[i-1] = a[i];
    n--;
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> i[a]; // *(i + a)
    
    stergere_element(a, n, 3);
    
    for(int i = 1; i <= n; ++i)
        cout << *(a + i) << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Vectori - Tablouri Unidimensionale
    
    1) Stergeri si Inserari
    2) Ordonarea elementelor - Sortari
    3) Cautari de elemente - CB si CS
    4) Interclasarea
    5) Frecvente si vectori Caracteristici
*/

/*
    * - operator de dereferentiere
    & - operator de referentiere
*/

int a[1001];
int n;
// 1 2 3 4 5

void stergere_element(int *a, int &n, int poz){
    for(int i = poz + 1; i <= n; ++i)
        a[i-1] = a[i];
    n--;
}

void stergere_pare(int a[], int &n){
    int i = 1;
    while(i <= n){
        if(a[i] % 2 == 0){
            for(int j = i; j < n; ++j)
                a[j] = a[j + 1];
            n--;
        }
        else
            i++;
    }
}

void stergere_pare1(int a[], int &n){
    for(int i = 1; i <= n; ++i)
        if(a[i] % 2 == 0)
            stergere_element(a, n, i), i--;
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> i[a]; // *(i + a)
    
    stergere_pare1(a, n);
    
    for(int i = 1; i <= n; ++i)
        cout << *(a + i) << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Vectori - Tablouri Unidimensionale
    
    1) Stergeri si Inserari
    2) Ordonarea elementelor - Sortari
    3) Cautari de elemente - CB si CS
    4) Interclasarea
    5) Frecvente si vectori Caracteristici
*/

/*
    * - operator de dereferentiere
    & - operator de referentiere
*/

int a[1001];
int n;
// 1 2 3 3 4 5

void inserare_element(int a[], int &n, int poz, int val){
    for(int i = n; i >= poz; --i)
        a[i+1] = a[i];
    a[poz] = val;
    n++;
}

void inserare_jum_pare(int a[], int &n){
    for(int i = 1; i <= n; ++i)
        if(a[i] % 2 == 0){
            for(int j = n; j > i; --j)
                a[j+1] = a[j];
            a[i + 1] = a[i] / 2;
            n++;
            i++;
        }
} // insereaza dupa fiecare element par, jumatatea lui

void inserare_jum_pare1(int a[], int &n){
    int i = 1;
    while(i <= n){
        if(a[i] % 2 == 0){
            inserare_element(a, n, i + 1, a[i] / 2);
            i += 2;
        }
        else i++;
    }
} // insereaza dupa fiecare element par, jumatatea lui

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> i[a]; // *(i + a)
    
    inserare_jum_pare1(a, n);
    
    for(int i = 1; i <= n; ++i)
        cout << *(a + i) << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Vectori - Tablouri Unidimensionale
    
    1) Stergeri si Inserari
    2) Ordonarea elementelor - Sortari
    3) Cautari de elemente - CB si CS
    4) Interclasarea
    5) Frecvente si vectori Caracteristici
*/

/*
    * - operator de dereferentiere
    & - operator de referentiere
*/

bool is_pp(int n){
    int d = 1;
    while(d * d < n)
        d ++;
    return d * d == n;
} // O(sqrt(n))

bool is_pp1(int n){
    int d = 2;
    while(n > 1){
        int p = 0;
        while(n % d == 0)
            n /= d, p++;
        if(p % 2 == 1)
            return false;
        d++;
        if(d * d > n)
            d = n;
    }
    return true;
} // O(sqrt(n))

bool is_pp2(int n){
    int st = 1, dr = n;
    while(st <= dr){
        int mij = (st + dr) / 2;
        if(mij * mij == n)
            return true;
        else if(mij * mij > n)
            dr = mij - 1;
        else st = mij + 1;
    }
    return false;
} // O(log2(n))

int main(){
    
    
    
    return 0;
}









#include <iostream>
using namespace std;

int a[100001], n;

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    bool ok = false;
    while(!ok){
        ok = true;
        for(int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << endl;
        for(int i = 1; i < n; ++i)
            if(abs(a[i]) % 2 == abs(a[i+1]) % 2 && a[i] != a[i+1]){
                int med = (a[i] + a[i+1]) / 2;
                for(int j = n; j >= i; --j)
                    a[j+1] = a[j];
                a[i+1] = med;
                i++;
                n++;
                ok = false;
            }
    }
    
    return 0;
}