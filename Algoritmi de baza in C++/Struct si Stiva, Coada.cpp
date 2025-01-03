#include <iostream>
#include <cstring>
using namespace std;

struct user{
    char nume[256], prenume[256];
    int varsta;
    char sex; // m, f, n
    struct {
        int zi, luna, an;
    } data_nasterii;
    
    void initializare(char n[], char p[], int v, int s, int z, int l, int a){
        strcpy(nume, n);
        strcpy(prenume, p);
        varsta = v;
        sex = s;
        data_nasterii.zi = z;
        data_nasterii.an = a;
        data_nasterii.luna = l;
    }
    
    void print_data(){
        cout << "Nume: " << nume << '\n';
        cout << "Prenume: " << prenume << '\n';
        cout << "Varsta: " << varsta << '\n';
        cout << "Sex: " << sex << '\n';
        cout << "Data Nasterii: (" << data_nasterii.zi << "," << data_nasterii.luna << "," 
            << data_nasterii.an << ")\n";
    }
};

int main(){
    
    user u1;
    u1.initializare("Somesan", "Paul", 20, 'm', 28, 10, 2002);
    
    u1.print_data();
    
    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

// CountWords

struct cuvinte{
    char valoare[1001];
    int nr_ap = 0;
}cuvinte[2001];

int nr_cuv = 0;

char s[10001];

int main(){
    
    cin.getline(s, 10001);
    char sep[]=" ,.;:";

    char *p = strtok(s, sep);
    while(p){
        bool gasit = false;
        for(int i = 1; i <= nr_cuv && !gasit; ++i)
            if(strcmp(cuvinte[i].valoare, p) == 0)
                cuvinte[i].nr_ap++, gasit = true;
        if(!gasit)
            strcpy(cuvinte[++nr_cuv].valoare, p), cuvinte[nr_cuv].nr_ap = 1;
        p = strtok(NULL, sep);
    }

    for(int i = 1; i < nr_cuv; ++i)
        for(int j = i + 1; j <= nr_cuv; ++j)
            if(strcmp(cuvinte[i].valoare, cuvinte[j].valoare) > 0)
                swap(cuvinte[i], cuvinte[j]);
    
    for(int i = 1; i <= nr_cuv; ++i)
        cout << cuvinte[i].valoare << ' ' << cuvinte[i].nr_ap << '\n';

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

/*
 *  Structuri de date neomogene
 *
 */

struct entitati{
    char prenume[256], nume[256];
    long long salariu, varsta;
    char functie[256], nr_tel[256], email[256];
}a[81];
int n, criteriu;
char semn;

bool ok(entitati a, entitati b){
    switch(criteriu){
        case 1:
            return strcmp(a.prenume, b.prenume) <= 0;
        case 2:
            return strcmp(a.nume, b.nume) <= 0;
        case 3:
            return a.salariu <= b.salariu;
        case 4:
            return a.varsta <= b.varsta;
        case 5:
            return strcmp(a.functie, b.functie) <= 0;
        case 6:
            return strcmp(a.nr_tel, b.nr_tel) <= 0;
        case 7:
            return strcmp(a.email, b.email) <= 0;
    }
}

void sortare(){
    for(int i = 2; i <= n; ++i){
        int j = i;
        while(!ok(a[j-1], a[j]) && j >= 2)
            swap(a[j-1], a[j]), j--;
    }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].prenume >> a[i].nume >> a[i].salariu >> a[i].varsta >> a[i].functie >> a[i].nr_tel >> a[i].email;
    cin >> criteriu >> semn;
    sortare();
    if(semn == '+')
        for(int i = 1; i <= n; ++i)
            cout << a[i].prenume << ' ' << a[i].nume << ' ' << a[i].salariu << ' ' << a[i].varsta << ' ' << a[i].functie
                 << ' ' << a[i].nr_tel << ' ' << a[i].email << '\n';
    else
        for(int i = n; i >= 1; --i)
            cout << a[i].prenume << ' ' << a[i].nume << ' ' << a[i].salariu << ' ' << a[i].varsta << ' ' << a[i].functie
                 << ' ' << a[i].nr_tel << ' ' << a[i].email << '\n';
    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

// Stiva si Coada
/*
    Stiva: PUSH, POP, TOP, EMPTY
    PUSH - adauga un element in varful stivei
    POP - elimina elementul din varful stivei
    TOP - returneaza elementul din varful stivei
    EMPTY - verifica daca stiva e goala
    
    PUSH 3
    PUSH 4
    PUSH 5
    
    
                5
                4
                3
    
*/

struct MyStack{
    int a[100001], dr = 0, st = 1;
    
    void push(int val){
        a[++dr] = val;
    }
    
    bool empty(){
        return dr < st;
    }
    
    int top(){
        if(!empty())
            return a[dr];
        return -1;
    }
    
    void pop(){
        if(!empty())
            dr--;
    }
};

int main(){
    
    MyStack S1;
    int n, x;
    cin >> n;
    char s[6];
    for(int i = 1; i <= n; ++i){
        cin >> s;
        if(strcmp(s, "push") == 0){
            cin >> x;
            S1.push(x);
        }
        else if(strcmp(s, "top") == 0){
            if(!S1.empty())
                cout << S1.top() << '\n';
        }
        else S1.pop();
    }
    
    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

// Stiva si Coada
/*
    Coada: PUSH, POP, FRONT, EMPTY 
*/

struct MyQueue{
    int a[100001], st = 1, dr = 0;
    
    void push(int val){
        a[++dr] = val;
    }
    
    bool empty(){
        return st > dr;
    }
    
    int front(){
        if(!empty())
            return a[st];
        return -1;
    }
    
    void pop(){
        if(!empty())
            st++;
    }
};

int main(){
    
    MyQueue q;
    int n, op;
    cin >> n;
    char s[6];
    for(int i = 1; i <= n; ++i){
        cin >> s;
        if(strcmp(s, "front") == 0){
            if(!q.empty())
                cout << q.front() << '\n';
        }
        else if(strcmp(s, "push") == 0){
            cin >> op;
            q.push(op);
        }
        else{
            q.pop();
        }
    }
    return 0;
}









#include <iostream>
using namespace std;

// DEPOU

struct MyStack{
    int a[100001], dr = 0, st = 1;
    
    void push(int val){
        a[++dr] = val;
    }
    
    bool empty(){
        return dr < st;
    }
    
    int top(){
        if(!empty())
            return a[dr];
        return -1;
    }
    
    void pop(){
        if(!empty())
            dr--;
    }
};

int depou[1001];

int main(){
    
    MyStack A, B;
    int n, x, cnt = 0, directii[10001];
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> x, A.push(x), depou[x] = 1;
        
    bool ok = true;
    for(int i = 1; i <= n && ok; ++i){
        if(depou[i] == 1){
            while(A.top() != i){
                // A -> B
                directii[++cnt] = 1;
                B.push(A.top());
                depou[A.top()] = 2;
                A.pop();
            }
            // A -> C
            depou[i] = 3;
            A.pop();
            directii[++cnt] = 2;
        }
        else{
            if(B.top() != i){
                ok = false;
                break;
            }
            // B -> C
            directii[++cnt] = 3;
            depou[B.top()] = 3;
            B.pop();
        }
    }
    
    if(!ok)
        cout << 0;
    else{
        cout << cnt << endl;
        for(int i = 1; i <= cnt; ++i)
            if(directii[i] == 1)
                cout << "A B\n";
            else if(directii[i] == 2)
                cout << "A C\n";
            else cout << "B C\n";
    }
    
    return 0;
}









#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("ratc2.in");
ofstream cout("ratc2.out");

/*
 *  RATC2
 *
 */

struct clienti{
    char prenume[51], nume[51];
    int penalizari = 0;
}a[101];

int nr = 0;

void sortare(clienti a[], int n){
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i].penalizari < a[j].penalizari)
                swap(a[i], a[j]);
            else if(a[i].penalizari == a[j].penalizari && strcmp(a[i].prenume, a[j].prenume) > 0)
                swap(a[i], a[j]);
            else if(a[i].penalizari == a[j].penalizari && strcmp(a[i].prenume, a[j].prenume) == 0 && strcmp(a[i].nume, a[j].nume) > 0)
                swap(a[i], a[j]);
}

int main() {

    int n, cer;
    cin >> n >> cer;
    char pr[51], nu[51];
    for(int i = 1, platit; i <= n; ++i){
        cin >> pr >> nu >> platit;
        int ind = -1;
        for(int i = 1; i <= nr; ++i)
            if(strcmp(a[i].prenume, pr) == 0 && strcmp(a[i].nume, nu) == 0)
                ind = i;
        if(ind == -1){
            strcpy(a[++nr].prenume, pr);
            strcpy(a[nr].nume, nu);
            if(platit == 0)
                a[nr].penalizari = 1;
        }
        else a[ind].penalizari += (platit == 0);
    }

    sortare(a, nr);

    if(cer == 1)
        cout << a[1].prenume << ' ' << a[1].nume << ' ' << a[1].penalizari;
    else{
        for(int i = 1; i <= nr; ++i)
            cout << a[i].prenume << ' ' << a[i].nume << ' ' << a[i].penalizari << '\n';
    }

    return 0;
}










#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("intervale4.in");
ofstream cout("intervale4.out");

// Intervale4

struct interval{
    int st, dr;
};

struct myStack{
    int st = 1, dr = 0;
    interval a[100001];

    bool empty(){
        return st > dr;
    }

    void push(interval i){
        a[++dr] = i;
    }

    void pop(){
        if(!empty())
            dr--;
    }

    interval top(){
        return a[dr];
    }
};

bool se_intersecteaza(interval a, interval b){
    if(a.dr < b.st || b.dr < a.st)
        return false;
    return true;
}

int main(){
    
    int n;
    cin >> n;
    myStack S;
    interval curr;
    for(int i = 1; i <= n; ++i){
        cin >> curr.st >> curr.dr;
        if(!S.empty()){
            interval ant = S.top();
            while(se_intersecteaza(ant, curr)){
                curr.st = min(curr.st, ant.st);
                curr.dr = max(curr.dr, ant.dr);
                S.pop();
                if(!S.empty())
                    ant = S.top();
                else break;
            }
        }
        S.push(curr);
    }

    int cnt = 0;
    while(!S.empty()){
        cnt++;
        S.pop();
    }

    cout << cnt;

    return 0;
}









