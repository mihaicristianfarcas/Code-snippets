#include <iostream>
#include <cstring>
using namespace std;

char s[256], rez[21];

bool is_palindrom(char s[]){
    for(int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
        if(tolower(s[i]) != tolower(s[j]))
            return false;
    return true;
}

int main(){

    cin.getline(s, 255);

    char *p = strtok(s, " ,.:;");
    while(p){

        if(is_palindrom(p) && strlen(p) > strlen(rez))
            strcpy(rez, p);

        p = strtok(NULL, " ,.:;");
    }

    cout << rez;

    return 0;
}









#include <iostream>
using namespace std;

bool islower(char ch){
    if(ch >= 'a' && ch <= 'z')
        return true;
    return false;
}

bool isupper(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return true;
    return false;
}

char tolower(char ch){
    if(isupper(ch))
        ch += ('a' - 'A');
    return ch;
}

char toupper(char ch){
    if(islower(ch))
        ch -= ('a' - 'A');
    return ch;
}

bool isalpha(char ch){
    return islower(ch) || isupper(ch);
}

bool isdigit(char ch){
    return ch >= '0' && ch <= '9';
}

bool isalnum(char ch){
    return isalpha(ch) || isdigit(ch);
}

// FUNCTIILE PREDEFINITE PENTRU CARACTERE

int main(){



    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

/*  Functiile predefinite care returneaza adrese de memorie
 *  1) STRTOK
 *  2) STRSTR
 *  3) STRCHR
 */

char s[256 * 256], a[256], b[256], aux[256 * 256];

int main(){

    cin.getline(s, 256);
    cin >> a >> b;
    char *p = strstr(s, a);
    while(p){
        strcpy(aux, b);
        strcat(aux, p + strlen(a));
        strcpy(p, aux);
        p = strstr(p, a);
    }

    cout << s;

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

char a[256], b[256];
char cuv[256][256], rez[256][256];
int nrcuva, nrcuvrez;

int main(){
    
    cin.getline(a, 256);
    cin.getline(b, 256);
    
    for(int i = 0; a[i]; ++i)
        if(isupper(a[i]))
            a[i] = tolower(a[i]);
    
    for(int i = 0; b[i]; ++i)
        if(isupper(b[i]))
            b[i] = tolower(b[i]);
            
    char *p = strtok(a, " ");
    while(p){
        strcpy(cuv[++nrcuva], p);
        p = strtok(NULL, " ");
    }
    
    p = strtok(b, " ");
    while(p){
        
        for(int i = 1; i <= nrcuva; ++i)
            if(strcmp(p, cuv[i]) == 0){
                bool apare = false;
                for(int j = 1; j <= nrcuvrez; ++j)
                    if(strcmp(p, rez[j]) == 0)
                        apare = true;
                if(!apare)
                    strcpy(rez[++nrcuvrez], p);
            }

        p = strtok(NULL, " ");
    }
    
    for(int i = 1; i < nrcuvrez; ++i)
        for(int j = i + 1; j <= nrcuvrez; ++j)
            if(strcmp(rez[i], rez[j]) > 0)
                swap(rez[i], rez[j]);
    
    for(int i = 1; i <= nrcuvrez; ++i)
        cout << rez[i] << '\n';
    
    return 0;
}









#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("cuvmax.in");
ofstream cout("cuvmax.out");

char s[256], rez[256], aux[256];
int n, nrmaxcuv;

int main(){
    
    cin >> n;
    cin.get();
    for(int i = 1; i <= n; ++i){
        cin.getline(s, 256);
        strcpy(aux, s);
        char *p = strtok(s, " ");
        int cnt = 0;
        while(p){
            cnt++;
            p = strtok(NULL, " ");
        }
        if(cnt > nrmaxcuv){
            nrmaxcuv = cnt, strcpy(rez, aux);
        }
    }
    
    cout << rez;
    
    return 0;
}









#include <cstring>
#include <fstream>
using namespace std;

ifstream cin("file.in");
ofstream cout("file.out");

char cuv[256][256];

int partitionare(int st, int dr){
    int pozb=st;
    for(int i=st;i<dr;i++){
        if(strcmp(cuv[i],cuv[dr])<0){
            swap(cuv[i],cuv[pozb]);
            pozb++;
        }
    }
    swap(cuv[pozb],cuv[dr]);
    return pozb;
}

void quicksort(int st, int dr){
    if(st>dr)
        return;
    int poz=partitionare(st,dr);
    quicksort(st,poz-1);
    quicksort(poz+1,dr);
}

int main()
{
    char s[256],k=0;
    cin.getline(s,256);
    char *p=strtok(s," ");
    while(p){
        strcpy(cuv[++k],p);
        p=strtok(NULL," ");
    }
    
    quicksort(1,k);

    for(int i=1;i<=k;i++)
        cout<<cuv[i]<<'\n';

    return 0;
}









#include <iostream>
#include <cstring>

using namespace std;
char s[256], cuv[256][256], aux[256][256];

void mergesort(int st, int dr) {
    if (st == dr) return;
    else {
        int mij = (st + dr) / 2;
        mergesort(st, mij);
        mergesort(mij + 1, dr);
        int ind1 = st, ind2 = mij + 1, poz = 0;
        while (ind1 <= mij && ind2 <= dr)
            if (strlen(cuv[ind1]) < strlen(cuv[ind2]) || (strlen(cuv[ind1]) == strlen(cuv[ind2]) && strcmp(cuv[ind1], cuv[ind2]) > 0))
                strcpy(aux[++poz], cuv[ind2++]);
            else strcpy(aux[++poz], cuv[ind1++]);
        while (ind1 <= mij)
            strcpy(aux[++poz], cuv[ind1++]);
        while (ind2 <= dr)
            strcpy(aux[++poz], cuv[ind2++]);
        for (int i = 1; i <= poz; ++i)
            strcpy(cuv[i + st - 1], aux[i]);
    }
}

int main() {
    cin.getline(s, 256);
    char *p = strtok(s, " ");
    int k = 0;
    while (p) {
        strcpy(cuv[++k], p);
        p = strtok(NULL, " ");
    }
    mergesort(1, k);
    for (int i = 1; i <= k; ++i)
        cout << cuv[i] << '\n';
    return 0;
}