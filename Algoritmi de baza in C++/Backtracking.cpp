#include <iostream>
#include <cstring>
using namespace std;

// Backtracking -> Permutari
// 3 -> 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1

// _ _ _

int n, P[11], x[11];

void afis(){
    for(int i = 1; i <= n; ++i)
        cout << x[i] << ' ';
    cout << "\n";
}

void back(int k){
    for(int i = 1; i <= n; ++i)
        if(!P[i]){
            P[i] = 1;
            x[k] = i;
            if(k < n)
                back(k + 1);
            else afis();
            P[i] = 0;
        }
}

int main(){
    
    cin >> n;
    back(1);

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

// Backtracking -> Aranjamente
// Aranjamente (5, 3) -> 1 2 3, 1 2 4, 1 2 5, 1 3 4, 1 3 5, 1 4 5

// _ _ _ (1,2,3,4,5)

int x[11], n, k, P[11];

void afis(){
    for(int i = 1; i <= k; ++i)
        cout << x[i] << ' ';
    cout << endl;
}

void back(int poz){
    for(int i = 1; i <= n; ++i){
        if(!P[i]){
            P[i] = 1;
            x[poz] = i;
            if(poz < k)
                back(poz+1);
            else afis();
            P[i] = 0;}
        }
}

int main(){
    
    cin >> n >> k;
    back(1);

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

// Backtracking -> Combinari
// Sunt aranjamentele ordonate crescator
// 5 3 -> 1 2 3, 1 2 4, 1 2 5, 1 3 4, 1 3 5, 1 4 5, 2 3 4, 2 3 5, 2 4 5, 3 4 5

// _ _ _ (1,2,3,4,5)

/*
    C(7, 5)
    _ _ _ _ _  (1,2,3,4,5,6,7)
*/

int x[11], n, k;

void afis(){
    for(int i = 1; i <= k; ++i)
        cout << x[i] << ' ';
    cout << '\n';
}

void back(int poz){
    for(int i = x[poz-1] + 1; i <= n - (k - poz); ++i){
        x[poz] = i;
        if(poz < k)
            back(poz+1);
        else afis();
    }
}

int main(){
    
    cin >> n >> k;
    back(1);

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

/*
    Se dau n arome de inghetata. Determinati cate meniuri distincte cu cate k
    globuri distincte putem forma.
    Ex: (ciocolata, vanilie, fructe de padure), k = 2
    R:  (ciocolata, vanilie), (ciocolata, fructe de padure), (vanilie, fructe de padure)
*/

int n, k, x[101];
char arome[101][101];

void afis(){
    for(int i = 1; i <= k; ++i)
        cout << arome[x[i]] << ' ';
    cout << "\n"; 
}

void back(int pas){
    for(int i = x[pas-1] + 1; i <= n - (k - pas); ++i){
        x[pas] = i;
        if(pas < k)
            back(pas+1);
        else afis(); 
    }
}

int main(){
    
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> arome[i];

    back(1);

    return 0;
}









#include <iostream>
using namespace std;

int n, a[11], P[11];

void afis(){
    for(int i = 1; i <= n; ++i, cout << endl)
        for(int j = 1; j <= n; ++j)
            if(a[i] == j)
                cout << "* ";
            else cout << "- ";
    
    exit(0);
}

bool nu_se_ataca_pe_diagonala(int lin, int col){
    for(int i = 1; i < lin; ++i)
        if(abs(lin - i) == abs(a[i] - col))
            return false;
    return true;
}

void back(int k){
    for(int i = 1; i <= n; ++i)
        if(!P[i] && nu_se_ataca_pe_diagonala(k, i)){
            P[i] = 1;
            a[k] = i;
            if(k < n)
                back(k+1);
            else afis();
            P[i] = 0;
        }
}

int main(){

    cin >> n;
    back(1);

    return 0;
}









#include <fstream>
using namespace std;

ifstream cin("suma35.in");
ofstream cout("suma35.out");

int n, nr_5;

int main(){

    cin >> n;
    while(n >= nr_5 * 5){
        if((n - nr_5 * 5) % 3 == 0){
            int nr_3 = (n - nr_5 * 5) / 3;
            for(int i = 1; i <= nr_3; ++i)
                cout << 3 << ' ';
            for(int i = 1; i <= nr_5; ++i)
                cout << 5 << ' ';
            cout << '\n';
        }
        nr_5++;
    }

    return 0;
}









#include <iostream>
using namespace std;

int n, a[351];

void afis(int n){
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << "\n";
}

void back(int k, int sum){
    if(sum == n)
        afis(k-1);
    if(sum + 3 <= n && a[k-1] <= 3){
        a[k] = 3;
        back(k + 1, sum + 3);
    }
    if(sum + 5 <= n){
        a[k] = 5;
        back(k + 1, sum + 5);
    }
}

int main(){

    cin >> n;
    back(1, 0);

    return 0;
}









#include <iostream>
using namespace std;

int n, S, v[11], c[11], x[11];

void afis(){
    for(int i = 1; i <= n; ++i)
        cout << x[i] << ' ';
    exit(0);
}

void back(int k, int sum){
    for(int i = 1; i <= c[k] && sum + i * v[k] <= S; ++i){
        x[k] = i;
        if(k == n && S == sum + i * v[k])
            afis();
        else if(k < n)
            back(k + 1, sum + i * v[k]);
    }
}

int main(){

    cin >> n >> S;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    
    back(1, 0);

    return 0;
}









#include <fstream>
using namespace std;

ifstream cin("partitiinr.in");
ofstream cout("partitiinr.out");

int n, x[101];

void afis(int n){
    for(int i = 1; i <= n; ++i)
        cout << x[i] << ' ';
    cout << '\n';
}

void back(int k, int sum){
    for(int i = x[k-1] + 2; sum + i <= n; ++i){
        x[k] = i;
        if(sum + i == n)
            afis(k);
        else if(sum + i < n)
            back(k+1, sum + i);
    }
}

int main(){

    cin >> n;
    
    x[0] = -1;
    back(1, 0);

    return 0;
}









#include <fstream>
using namespace std;

ifstream cin("paranteze.in");
ofstream cout("paranteze.out");

int n;
char x[21];

void back(int k, int nr_d, int nr_i){
    if(k > n)
        cout << x + 1 << '\n';
    if(nr_d < n / 2)
        x[k] = '(', back(k + 1, nr_d + 1, nr_i);
    if(nr_d > nr_i)
        x[k] = ')', back(k + 1, nr_d, nr_i + 1);
}

int main(){
    cin >> n;  
    back(1, 0, 0);
    return 0;
}









#include <iostream>
using namespace std;

int n, m;
char x[29];
bool gasit = false;

void back(int k, int nr_E, int nr_M){
    if(k > n + m)
        cout << x + 1 << '\n', gasit = true;
    if(nr_E < n)
        if(k <= 2 || x[k-1] != 'E' || x[k-2] != 'E')
            x[k] = 'E', back(k + 1, nr_E + 1, nr_M);
    if(nr_M < m)
        if(k <= 2 || x[k-1] != 'M' || x[k-2] != 'M')
            x[k] = 'M', back(k + 1, nr_E, nr_M + 1);
}

int main(){
    cin >> n >> m;  
    back(1, 0, 0);
    if(!gasit)
        cout << "IMPOSIBIL";
    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

int n, k, x[31], P[31];
char a[31][21];
bool gasit = false;

void sortare(){
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(strcmp(a[i], a[j]) > 0)
                swap(a[i], a[j]);
}

bool fazan(char s1[], char s2[]){
    if(s2[strlen(s2) - 2] == s1[0] && s2[strlen(s2) - 1] == s1[1])
        return 1;
    return 0;
}

void afis(){
    for(int i = 1; i <= k; ++i)
        cout << a[x[i]] << ' ';
    cout << "\n";
    gasit = true;
}

void back(int poz){
    for(int i = 1; i <= n; ++i)
        if(!P[i] && (poz == 1 || fazan(a[i], a[x[poz-1]]))){
            x[poz] = i;
            P[i] = 1;
            if(poz == k)
                afis();
            else back(poz + 1);
            P[i] = 0;
        }
}

int main(){
    
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    sortare();

    back(1);
    
    if(!gasit)
        cout << "IMPOSIBIL";

    return 0;
}









#include <iostream>
#include <cstring>
using namespace std;

int n;
char s[30];

void back(int k){
    if(k > n){
        cout << s + 1 << '\n';
        return ;
    }
    if(s[k-1] != 'a'){
        s[k] = s[k-1] - 1;
        back(k + 1);
    }
    if(s[k-1] + 1 <= 'a' + (n - k)){
        s[k] = s[k-1] + 1;
        back(k + 1);
    }
}

int main(){
    
    cin >> n;
    s[1] = 'a';
    back(2);
    
    return 0;
}









#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("cerc.in");
ofstream cout("cerc.out");

int n, v[11], x[11], P[11];
int maxim = 0, rez[11];

void afis(int prod){
    prod += v[x[1]] * v[x[n]];
    if(prod > maxim){
        maxim = prod;
        for(int i = 1; i <= n; ++i)
            rez[i] = v[x[i]];
    }
}

void back(int k, int prod){
    for(int i = 1; i <= n; ++i)
        if(!P[i]){
            P[i] = 1;
            x[k] = i;
            if(k >= 2)
                prod += v[i] * v[x[k-1]];
            if(k < n)
                back(k + 1, prod);
            else afis(prod);
            if(k >= 2)
                prod -= v[i] * v[x[k-1]];
            P[i] = 0;
        }
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(v[i] > v[j])
                swap(v[i], v[j]);
    
    back(1, 0);

    for(int i = 1; i <= n; ++i)
        cout << rez[i] << ' ';
    
    return 0;
}









#include <fstream>
using namespace std;

ifstream cin("shuffle.in");
ofstream cout("shuffle.out");

int n, v[10], a[10][10], P[10], x[10];
bool gasit=false;

void afis(){
    
  for(int i=1;i<=n;i++)
    cout<<x[i]<<' ';
  cout<<'\n';
    
  gasit=true;
}

void back(int k){
    
  for(int i=1;i<=n;i++){
    if(!P[i]){
      x[k]=i;
      P[i]=1;
      if(k==n && a[x[k-1]][x[k]]==0)
        afis();
      else if(k<n){
        if(k<2)
          back(k+1);
        else if(a[x[k-1]][x[k]]==0)
          back(k+1);
      }
    P[i]=0;
    }
  }
}
int main(){
  cin>>n;
  cin>>v[1];
  for(int i=2;i<=n;i++)
    cin>>v[i], a[v[i-1]][v[i]]=1, a[v[i]][v[i-1]]=1;
  back(1);
  if(!gasit)
    cout<<"nu exista";
  return 0;
  
}









#include <iostream>
using namespace std;

// PartitiiNumar6 -> returnam numarul de solutii

int nr_mod(int n, int ant){
    if(n == 0)
        return 1;
    int cnt = 0;
    for(int i = ant + 2; i <= n; i += 2)
        cnt += nr_mod(n - i, i);
    return cnt;
}

/*
    nr_mod(16, -1) = nr_mod(15, 1) + nr_mod(13, 3) + nr_mod(11, 5) + nr_mod(9, 7) + ... 
*/

int main(){
    
    
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Se da un sir cu n numere naturale si se cere determinarea celei mai mari sume
    care s-ar putea obtine din selectarea unei submultimi cu elemente aflate 
    pe pozitii neconsecutive in sir:
    Ex: 3 12 6 10 3 3 11 7 => 33

    smax(k) - max(smax(k + 2) + a[k], smax(k + 1));
*/

int n, a[11], smax, x[11];

void back(int k, int sum){
    for(int i = x[k - 1] + 2; i <= n; ++i){
        x[k] = i;
        sum += a[i];
        if(sum > smax)
            smax = sum;
        back(k + 1, sum);
        sum -= a[i];
    }
}

int suma_maxima(int k){
    if(k > n)
        return 0;
    return max(suma_maxima(k + 2) + a[k], suma_maxima(k + 1));
}

int suma_maxima_1(int k, int prev){
    if(k > n)
        return 0;
    int sum1 = suma_maxima_1(k + 1, prev);
    int sum2 = 0;
    if(k > prev + 1)
        sum2 = suma_maxima_1(k + 1, k) + a[k];
    return max(sum1, sum2);
}

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    x[0] = -1;
    back(1, 0);

    cout << smax << ' ' << suma_maxima(1);

    return 0;
}









#include <iostream>
using namespace std;

// Paranteze

int n;

int nr_mod(int k, int cnt_D, int cnt_I){
    if(k > n)
        return 1;
    int cnt = 0;
    if(cnt_D < n / 2)
        cnt += nr_mod(k + 1, cnt_D + 1, cnt_I);
    if(cnt_I < cnt_D)
        cnt += nr_mod(k + 1, cnt_D, cnt_I + 1);
    return cnt;
}

int main(){

    cin >> n;
    cout << nr_mod(1, 0, 0);

    return 0;
}









#include <iostream>
using namespace std;

// Back_ME

int n, m;
char x[30];

int nr_mod(int k, int cnt_E, int cnt_M){
    if(k > n + m)
        return 1;
    int cnt = 0;

    if(cnt_E < n && (k <= 2 || x[k-1] == 'M' || x[k-2] == 'M'))
        x[k] = 'E', cnt += nr_mod(k + 1, cnt_E + 1, cnt_M);
    if(cnt_M < m && (k <= 2 || x[k-1] == 'E' || x[k-2] == 'E'))
        x[k] = 'M', cnt += nr_mod(k + 1, cnt_E, cnt_M + 1);

    return cnt;
}

int main(){

    cin >> n >> m;
    cout << nr_mod(1, 0, 0);

    return 0;
}









#include <iostream>
using namespace std;

// Plata3

int n, v[10], S;

int nr_mod(int sum, int prev){
    if(sum == 0)
        return 1;
    int cnt = 0;
    for(int i = prev; i <= n && sum >= v[i]; ++i)
        cnt += nr_mod(sum - v[i], i);
    return cnt;
}

int main(){

    cin >> n >> S;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    cout << nr_mod(S, 1);

    return 0;
}