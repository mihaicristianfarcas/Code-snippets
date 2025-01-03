#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) Numarul de cifre
    2) Suma cifrelor
*/

int sum_cif(int n){
    int s = 0;
    while(n){
        s = s + n % 10;
        n /= 10;
    }
    return s;
}

int sum_cif_rec(int n){
    if(n == 0)
        return 0;
    return n % 10 + sum_cif_rec(n / 10);
}

int nr_cif(int n){
    int cnt = 0;
    if(n == 0)
        cnt = 1;
    while(n){
        cnt++;
        n /= 10;
    }
    return cnt;
}

int nr_cif1(int n){
    int cnt = 0;
    do{
        cnt++;
        n /= 10;
    }while(n);
    return cnt;
}

int nr_cif2(int n){
    int cnt = 1;
    while(n > 9){
        cnt++;
        n /= 10;
    }
    return cnt;
}

int nr_cif_rec(int n){
    if(n < 10)
        return 1;
    return 1 + nr_cif_rec(n / 10);
}

int main(){
    
    int n;
    cin >> n;
    cout << sum_cif(n) << ' ' << sum_cif_rec(n) << endl;
    cout << nr_cif(n) << ' ' << nr_cif1(n) << ' ' << nr_cif2(n) << ' ' << nr_cif_rec(n);

    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) Oglinditul unui numar
    2) Verificare Palindrom

    abcd = a * 1000 + b * 100 + c * 10 + d
    dcba = d * 1000 + c * 100 + b * 10 + a
*/

int oglindit(int n){
    int ogl = 0;
    while(n){
        ogl = ogl * 10 + n % 10;
        n /= 10;
    }
    return ogl;
}

bool este_palindrom(int n){
    if(n == oglindit(n))
        return true;
    return false;
}

int main(){
    
    int n;
    cin >> n;
    if( este_palindrom(n) )
        cout << "DA";
    else cout << "NU";
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) Se da un numar n. Sa se elimine din n toate cifrele sale impare.
        Ex. 12345 -> 24
    2) Se da un numar n. Sa se dubleze toate cifrele sale pare.
        Ex. 12345 -> 1223445

    !!! OGLINDITUL OGLINDITULUI UNUI NUMAR - NU - ESTE NUMARUL INITIAL
*/

int stergere_impare(int n){
    int nr_nou = 0, p = 1;
    while(n){
        int c = n % 10;
        if(c % 2 == 0){
            nr_nou = nr_nou + c * p;
            p *= 10;
        }
        n /= 10;
    }
    return nr_nou;
}

int stergere_impare_rec(int n){
    if(n == 0)
        return 0;
    int c = n % 10;
    if(c % 2 == 0)
        return stergere_impare_rec(n / 10) * 10 + c;
    return stergere_impare_rec(n / 10); 
}

int dublare_pare(int n){
    int nr_nou = 0, p = 1;
    while(n){
        int c = n % 10;
        nr_nou = nr_nou + c * p;
        p *= 10;
        if(c % 2 == 0){
            nr_nou = nr_nou + c * p;
            p *= 10;
        }
        n /= 10;
    }
    return nr_nou;
}

int dublare_pare_rec(int n){
    if(n == 0)
        return 0;
    int c = n % 10;
    if(c % 2 == 0)
        return dublare_pare_rec(n / 10) * 100 + c * 10 + c;
    return dublare_pare_rec(n / 10) * 10 + c;
}

int main(){
    
    int n;
    cin >> n;
    cout << stergere_impare(n) << ' ' << stergere_impare_rec(n) << endl;
    cout << dublare_pare(n) << ' ' << dublare_pare_rec(n);
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) CifSort
        Ex. 123456 - 214365
*/

int transformare(int n){
    int nr_nou = 0, p = 1;
    while(n){
        int c = n % 100;
        c = (c % 10) * 10 + c / 10;
        nr_nou = nr_nou + c * p;
        p *= 100;
        n /= 100;
    }
    return nr_nou;
}

int transformare_rec(int n){
    if(n == 0)
        return 0;
    int c = n % 100;
    c = (c % 10) * 10 + c / 10;
    return transformare_rec(n / 100) * 100 + c;
}

int main(){
    
    int n;
    cin >> n;
    cout << transformare(n);// << ' ' << transformare_rec(n);
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) Alternant2
        Sa se verifice daca un numar este alternant. 
        Un numar se numeste alternant daca nu contine 
        2 cifre de aceiasi paritate alaturate.

        Ex. 12345 -> DA
            12452 -> NU
*/

bool este_alternant(int n){
    bool ok = true;
    int p = n % 2;
    n /= 10;
    while(n){
        int c = n % 10;
        if(c % 2 == p)
            ok = false;
        p = c % 2;
        n /= 10;
    }
    return ok;
}

bool este_alternant1(int n){
    bool ok = true;
    while(n > 9){
        int c1 = n % 10;
        int c2 = (n / 10) % 10;
        if(c1 % 2 == c2 % 2)
            ok = false;
        n /= 10;
    }
    return ok;
}

bool este_alternant_rec(int n){
    if(n <= 9)
        return true;
    int c1 = n % 10;
    int c2 = (n / 10) % 10;
    if(c1 % 2 == c2 % 2)
        return false;
    return este_alternant_rec(n / 10);
}

int main(){
    
    int n;
    cin >> n;
    cout << este_alternant_rec(n) << ' ' << este_alternant1(n) << ' ' << este_alternant(n);
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) asociat_par
*/

int asociat_par(int n){
    if(n == 0)
        return 0;
    int c = n % 10;
    if(c % 2 == 0)
        return asociat_par(n / 10) * 10 + c;
    return asociat_par(n / 10);
} // rec

int oglindit(int n){
    int ogl = 0;
    while(n){
        ogl = ogl * 10 + n % 10;
        n /= 10;
    }
    return ogl;
} // it

bool este_palindrom(int n){
    if(n == oglindit(n))
        return true;
    return false;
} // it

bool contine_pare(int n){
    do{
        int c = n % 10;
        if(c % 2 == 0)
            return true;
        n /= 10;
    }while(n);
    return false;
}

int main(){
    
    int n, x, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        if(este_palindrom(asociat_par(x)) && contine_pare(x))
            cnt++;
    }
    cout << cnt;
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Cifrele unui numar

    1) Cifra de control

    -> este cifra care se obtine inlocuind pe n cu suma cifrelor sale pana cand
    rezultatul este de o cifra

    _______________TERNARY EXPRESSION_______________
    if(conditie)
        expr1;
    else expr2;

    conditie ? expr1 : expr2;
*/

int sum_cif(int n){
    return n ? n % 10 + sum_cif(n / 10) : 0;
}

int cifra_control(int n){
    while (n>9) 
        n = sum_cif(n);
    return n;
}

int cifra_control_rec(int n){
    if (n <= 9) 
        return n;
    return cifra_control(suma_cif(n));
}

int main(){
    
    
    return 0;
}









#include <iostream>
#include <cmath>
using namespace std;

/*
    Cifrele unui numar

    1) Permutarea cifrelor

    Sa se calculeze suma permutarilor circulare spre dreapta a lui n;

    Ex. n = 123 ; s = 123 + 312 + 231

*/

int nr_cif(int n){
    int cnt = 0;
    do{
        cnt++;
        n /= 10;
    }while(n);
    return cnt;
}

int suma_permutari(int n){
    int sum = 0;
    int p = pow(10, nr_cif(n) - 1);
    for(int i = 1; i <= nr_cif(n); ++i){
        sum += n;
        n = (n % 10) * p + n / 10;
    }
    return sum;
}

int main(){
    
    int n;
    cin >> n;
    cout << suma_permutari(n);
    
    return 0;
}