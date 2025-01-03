#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 1 3 4 5 8 10
    b[] = 2 3 4 5 6 9
    
    c[] = 1 2 3 3 4 4 5 5 6 8 9 10

*/

void interclasare(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    indc = 0;
    while(inda <= n && indb <= m)
        if(a[inda] <= b[indb])
            c[++indc] = a[inda++];
        else c[++indc] = b[indb++];
    while(inda <= n)
        c[++indc] = a[inda++];
    while(indb <= m)
        c[++indc] = b[indb++];
} // algoritmul clasic de interclasare

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    interclasare(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 1 3 4 4 4 4 5 8 10
    b[] = 2 3 4 4 4 4 5 6 9
    
    c[] = 1 2 3 4 5 6 8 9 10

*/

void reuniune(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    while(inda <= n && indb <= m)
        if(a[inda] < b[indb])
            c[++indc] = a[inda++];
        else if(a[inda] > b[indb])
            c[++indc] = b[indb++];
        else c[++indc] = a[inda++], indb++;
    while(inda <= n)
        c[++indc] = a[inda++];
    while(indb <= m)
        c[++indc] = b[indb++];
} // algoritmul clasic de interclasare

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    reuniune(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 2 3 4 4 4 4 5 8 10
    b[] = 2 3 4 4 4 4 5 6 9
    
    c[] = 1 2 3 4 5 6 8 9 10

*/

void reuniune1(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    while(inda <= n && indb <= m)
        if(a[inda] < b[indb])
            c[++indc] = a[inda++];
        else if(a[inda] > b[indb])
            c[++indc] = b[indb++];
        else{
            int aux = a[inda];
            while(aux == a[inda] && inda <= n)
                inda++;
            while(aux == b[indb] && indb <= m)
                indb++;
            c[++indc] = aux;
        }
    while(inda <= n)
        c[++indc] = a[inda++];
    while(indb <= m)
        c[++indc] = b[indb++];
} // algoritmul de interclasare fara repetitii

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    reuniune1(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}








#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 2 3 4 4 4 4 5 8 10
    b[] = 1 1 4 4 4 4 5 6 9
    
    c[] = 1 2 3 4 5 6 8 9 10

*/

void intersectie(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    indc = 0;
    while(inda <= n && indb <= m)
        if(a[inda] < b[indb])
            inda++;
        else if(a[inda] > b[indb])
            indb++;
        else
            c[++indc] = a[inda++], indb++;
} // intersectia a 2 multimi de numere naturale

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    intersectie(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}










#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 2 3 4 4 4 4 5 8 10
    b[] = 1 1 4 4 4 4 5 6 9
    
    c[] = 1 2 3 4 5 6 8 9 10

*/

void intersectie1(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    indc = 0;
    while(inda <= n && indb <= m)
        if(a[inda] < b[indb])
            inda++;
        else if(a[inda] > b[indb])
            indb++;
        else{
            int aux = a[inda];
            while(a[inda] == aux && inda <= n)
                inda++;
            while(b[indb] == aux && indb <= m)
                indb++;
            c[++indc] = aux;
        }
} // intersectia fara repetitii

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    intersectie1(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 1 3 4 5 9 10 
    b[] = 1 2 5 10 12
    
    c[] = 3 4 9

*/

void diferenta(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    indc = 0;
    while(inda <= n && indb <= m)
        if(a[inda] == b[indb])
            inda++, indb++;
        else if(a[inda] < b[indb])
            c[++indc] = a[inda++];
        else indb++;
    while(inda <= n)
        c[++indc] = a[inda++];
} // diferenta a 2 multimi

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    diferenta(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Interclasare
    
    1) Interclasarea clasica
    2) Reuniunea 
    3) Intersectia
    4) Diferenta

    a[] = 1 3 4 5 5 9 10 
    b[] = 1 2 5 10 12
    
    c[] = 3 4 9

*/

void diferenta1(int a[], int n, int b[], int m, int c[], int &indc){
    int inda = 1, indb = 1;
    indc = 0;
    while(inda <= n && indb <= m)
        if(a[inda] == b[indb]){
            int aux = a[inda];
            while(a[inda] == aux && inda <= n)
                inda++;
            while(b[indb] == aux && indb <= m)
                indb++;
        }
        else if(a[inda] < b[indb])
            c[++indc] = a[inda++];
        else indb++;
    while(inda <= n)
        c[++indc] = a[inda++];
} // diferenta fara repetitii

int main(){
    
    int a[1001], b[1001], c[2001];
    int n, m, k;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    
    diferenta1(a, n, b, m, c, k);
    
    for(int i = 1; i <= k; ++i)
        cout << c[i] << ' ';
    
    return 0;
}









#include <iostream>
#include <fstream>
using namespace std;

ifstream fin1("bac1.txt");
ifstream fin2("bac2.txt");

/*
    Interclasare
    
    Test4/2021 - S3.3
*/

int main(){
    
    int n, m, a, b;
    bool gasit = false;
    
    fin1 >> n >> a;
    fin2 >> m >> b;
    
    int inda = 1, indb = 1;
    while(inda <= n && indb <= m){
        if(a < b){
            if(a % 5 == 0)
                cout << a << ' ', gasit = true;
            fin1 >> a;
            inda++;
        }
        else if(b < a){
            if(b % 5 == 0)
                cout << b << ' ', gasit = true;
            fin2 >> b;
            indb++;
        }
        else{
            int aux = a;
            while(a == aux && inda <= n)
                fin1 >> a, inda++;
            while(b == aux && indb <= m)
                fin2 >> b, indb++;
        }
    }
    while(inda <= n){
        if(a % 5 == 0)
            cout << a << ' ', gasit = true;
        fin1 >> a;
        inda++;
    }
    while(indb <= m){
        if(b % 5 == 0)
            cout << b << ' ', gasit = true;
        fin2 >> b;
        indb++;
    }
    
    if(!gasit)
        cout << "nu exista";
    
    return 0;
}