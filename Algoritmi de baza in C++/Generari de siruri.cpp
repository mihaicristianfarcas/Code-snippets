#include <iostream>
using namespace std;

/*
    Generari de siruri
    
    - Sirul lui Fibonacci
    F(x) = F(x-1) + F(x-2), x >= 2
           1, x <= 1
           
    F: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    p: 0  1  2  3  4  5   6   7   8   9  10   11
    
*/

int fibo(int n){
    if(n <= 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    
    cout << fibo(9);
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Generari de siruri
    
    - Sirul lui Fibonacci
    F(x) = F(x-1) + F(x-2), x >= 2
           1, x <= 1
           
    F: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    p: 0  1  2  3  4  5   6   7   8   9  10   11
    
*/

int fibo(int n){
    if(n <= 1){
        cout << "Aici";
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
} // De cate ori se afiseaza "AICI"?

int main(){
    
    cout << fibo(9);
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Generari de siruri
    
    Sirul lui Fibonacci
    
    PANA LA 1 MLD EXISTA 45 de numere ale lui FIBONACCI
    
    f(n) = 2 * f(n-1) = f(n-1) + f(n-1)
    
    F(n) = F(n-1) + F(n-2)
*/


int main(){
    
    int a = 1, b = 1;
    cout << a << ' ' << b << ' ';
    while(b < 1000000000){
        int c = a + b;
        cout << c << ' ';
        a = b;
        b = c;
    }
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Generari de siruri
    
    1) Se da un sir recurent calculat dupa formula: f(x) = f(x-1)*2 + f(x-2)*3, f(0) = f(1) = 1
    Dandu-se 2 numere consecutive din acest sir, sa se afiseze elementele sirului in ordine
    descrescatoare. 
    
    Ex: 121 41
        121 41 13 5 1 1
        
    f(x) = f(x-1)*2 + f(x-2)*3
    f(x-2) = (f(x) - 2*f(x-1)) / 3
*/


int main(){
    
    int a, b;
    cin >> a >> b;
    cout << a << ' ' << b << ' ';
    while(a != 1 || b != 1){
        int c = (a - 2*b) / 3;
        cout << c << ' ';
        a = b;
        b = c;
    }
    
    return 0;
}









