#include <iostream>
using namespace std;

/*
    Sortari de Vectori

    1) Selection Sort - O(n ^ 2)
    2) Insertion Sort - O(n ^ 2)
    3) Bubble Sort - O(n ^ 2)
    4) Merge Sort - O(n * log2(n))
    5) Quick Sort - O(n * log2(n))
    
    SELECTION SORT 
    
    3 5 4 1 2
    1 2 4 3 5
    ...
    
*/

void selectionSort_explicita(int a[], int n){
    for(int i = 1; i < n; ++i){
        int mini = a[i], pozmin = i;
        for(int j = i + 1; j <= n; ++j)
            if(a[j] < mini)
                mini = a[j], pozmin = j;
        swap(a[i], a[pozmin]);
    }
} // Sortare prin Selectie - metoda clasica - explicita - O(n ^ 2)

void selectionSort_implicita(int a[], int n){
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i] > a[j])
                swap(a[i], a[j]);
} // Sortare prin Selectie - metoda clasica - implicita (scurta) - O(n ^ 2)

void selectionSort_rec1(int a[], int n, int i = 1){
    if(i == n)
        return ;
    for(int j = i + 1; j <= n; ++j)
        if(a[i] > a[j])
            swap(a[i], a[j]);
    selectionSort_rec1(a, n, i+1);
} // Sortare prin Selectie - metoda recursiva - recursivitate simpla - O(n ^ 2)

void selectionSort_rec2(int a[], int n){
    if(n == 1)
        return ;
    for(int j = 1; j < n; ++j)
        if(a[j] > a[n])
            swap(a[j], a[n]);
    selectionSort_rec2(a, n-1);
} // Sortare prin Selectie - metoda recursiva - ...

void selectionSort_rec3(int a[], int n, int j = 1){
    if(n == 1)
        return ;
    if(j < n){
        if(a[j] > a[n])
            swap(a[j], a[n]);
        selectionSort_rec3(a, n, j+1);
    }
    else selectionSort_rec3(a, n-1, 1);
} // Sortare prin Selectie - dubla recursivitate -> Cea mai interesanta

int main(){
    
    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    selectionSort_explicita(a, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Sortari de Vectori

    1) Selection Sort - O(n ^ 2)
    2) Insertion Sort - O(n ^ 2)
    3) Bubble Sort - O(n ^ 2)
    4) Merge Sort - O(n * log2(n))
    5) Quick Sort - O(n * log2(n))
    
    INSERTION SORT
    
    2 2 3 4 5
    
*/

void insertionSort_explicita(int a[], int n){
    for(int i = 2; i <= n; ++i){
        int poz = i;
        for(int j = i - 1; j >= 1; --j)
            if(a[j] > a[i])
                poz = j;
        int aux = a[i];
        for(int j = i-1; j >= poz; --j)
            a[j+1] = a[j];
        a[poz] = aux;
    }
} // Sortare prin Insertie - varianta explicita - O(n ^ 2)

void insertionSort_implicita(int a[], int n){
    for(int i = 2; i <= n; ++i){
        int j = i;
        while(a[j] < a[j-1] && j >= 2)
            swap(a[j], a[j-1]), j--;
    }
} // Sortare prin Insertie - varianta implicita - O(n ^ 2)

void insertionSort_rec(int a[], int n, int i = 2){
    if(i > n)
        return ;
    int j = i;
    while(a[j] < a[j-1] && j >= 2)
        swap(a[j], a[j-1]), j--;
    insertionSort_rec(a, n, i+1);
} // prima varianta recusiva - simpla recusivitate

void insertionSort_rec1(int a[], int n, int i = 2, int j = 2){
    if(i > n)
        return ;
    if(a[j] < a[j-1] && j >= 2){
        swap(a[j], a[j-1]);
        insertionSort_rec1(a, n, i, j-1);
    }
    else insertionSort_rec1(a, n, i+1, i+1);
} // Insertion Sort - dubla recursivitate

int main(){
    
    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    insertionSort_rec1(a, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

/*
    Sortari de Vectori

    1) Selection Sort - O(n ^ 2)
    2) Insertion Sort - O(n ^ 2)
    3) Bubble Sort - O(n ^ 2)
    4) Merge Sort - O(n * log2(n))
    5) Quick Sort - O(n * log2(n))
    
    Bubble Sort 
    
*/

void BubbleSort_clasic(int a[], int n){
    bool este_sortat = false;
    while(!este_sortat){
        este_sortat = true;
        for(int i = 1; i < n; ++i)
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                este_sortat = false;
            }
    }
} // BubbleSort Clasic

void BubbleSort_clasic_rec(int a[], int n){
    bool este_sortat = true;
    for(int i = 1; i < n; ++i)
        if(a[i] > a[i+1]){
            swap(a[i], a[i+1]);
            este_sortat = false;
        }
    if(!este_sortat)
        BubbleSort_clasic_rec(a, n);
} // Varianta de recursivitate clasica a Sortarii prin metoda Bulelor

void BubbleSort_interesant(int a[], int n){
    for(int k = 1; k < n; ++k)
        for(int i = 1; i < n; ++i)
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
} // BubbleSort - EXTREM DE ASEMANATOR CU SELECTION SORT 

void BubbleSort_rec(int a[], int n, int i = 1, int j = 2){
    if(i == n)
        return ;
    if(j <= n){
        if(a[j] < a[j-1])
            swap(a[j], a[j-1]);
        BubbleSort_rec(a, n, i, j+1);
    }
    else BubbleSort_rec(a, n, i+1);
} // BubbleSort - recursiv foarte fain!

void SelectionSort_rec(int a[], int n, int i = 1, int j = 2){
    if(i == n)
        return ;
    if(j <= n){
        if(a[j] < a[i])
            swap(a[j], a[i]);
        SelectionSort_rec(a, n, i, j+1);
    }
    else SelectionSort_rec(a, n, i+1, i+2);
} // SelectionSort - recursiv, aproape identic cu BubbleSort 

int main(){
    
    int a[1001], n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    SelectionSort_rec(a, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <fstream>
using namespace std;


//Sortare Divizori

ifstream cin("sortare_divizori.in");
ofstream cout("sortare_divizori.out");

int nr_div(int n){
    int prod = 1;
    int d = 2;
    while(n > 1){
        int p = 0;
        while(n % d == 0)
            n /= d, p++;
        if(p)
            prod *= (p + 1);
        d++;
        if(d * d > n)
            d = n;
    } 
    return prod;
} // NrDiv cu desc in fact primi

int a[1001], n, nrdiv[1001];

int main(){
    
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], nrdiv[i] = nr_div(a[i]);
    
    for(int i = 1; i < n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(nrdiv[i] < nrdiv[j]){
                swap(nrdiv[i], nrdiv[j]);
                swap(a[i], a[j]);
            } else if(nrdiv[i] == nrdiv[j] && a[i] > a[j])
                swap(a[i], a[j]);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

// MergeSort
/*
    2 7 8 1 4 6 5 3 => {2 7 8 1} U {4 6 5 3}
    
    {2 7 8 1} => {2 7} U {8 1}
    {2 7} => {2} U {7}
    {8 1} => {8} U {1}
    
    {4 6 5 3} => {4 6} U {5 3}
    {4 6} => {4} U {6}
    {5 3} => {5} U {3}
*/

int a[100001], c[100001];

void MergeSort(int st, int dr){
    if(st == dr)
        return ;
    else{
        int mij = (st + dr) / 2;
        MergeSort(st, mij);
        MergeSort(mij+1, dr);
        int ind1 = st, ind2 = mij+1, indc = 0;
        while(ind1 <= mij && ind2 <= dr)
            if(a[ind1] < a[ind2])
                c[++indc] = a[ind1++];
            else c[++indc] = a[ind2++];
        while(ind1 <= mij)
            c[++indc] = a[ind1++];
        while(ind2 <= dr)
            c[++indc] = a[ind2++];
        for(int i = 1; i <= indc; ++i)
            a[st++] = c[i];
    }
}

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    MergeSort(1, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

// QuickSort
/*
    7 2 1 8 3 6 5 4
    
    2 1 3 4 7 8 6 5
*/

int a[100001], b[100001];

int partitionare(int st, int dr){
    int pozb = st, pozpiv = 0;
    for(int i = st; i < dr; ++i)
        if(a[i] < a[dr])
            b[pozb++] = a[i];
    b[pozb] = a[dr];
    pozpiv = pozb;
    for(int i = st; i < dr; ++i)
        if(a[i] >= a[dr])
            b[++pozb] = a[i];
    for(int i = st; i <= dr; ++i)
        a[i] = b[i];
    return pozpiv;
}

void QuickSort(int st, int dr){
    if(st >= dr)
        return ;
    else{
        int poz = partitionare(st, dr);
        QuickSort(st, poz-1);
        QuickSort(poz+1, dr);
    }
}

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    QuickSort(1, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}









#include <iostream>
using namespace std;

// QuickSort
/*
    7 2 1 8 3 6 5 4
    
    2 1 3 4 7 8 6 5
*/

int a[100001], b[100001];

int partitionare(int st, int dr){
    int poz = st;
    for(int i = st; i < dr; ++i)
        if(a[i] < a[dr]){
            swap(a[i], a[poz]);
            poz++;
        }
    swap(a[dr], a[poz]);
    return poz;
}

void QuickSort(int st, int dr){
    if(st >= dr)
        return ;
    else{
        int poz = partitionare(st, dr);
        QuickSort(st, poz-1);
        QuickSort(poz+1, dr);
    }
}

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    QuickSort(1, n);
    
    for(int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    
    return 0;
}