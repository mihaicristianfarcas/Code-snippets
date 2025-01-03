#include <iostream>
using namespace std;

void baza2(int n){
    if(n == 0)
        return ;
    baza2(n / 2);
    cout << n % 2;
}

char cifre16[] = "0123456789ABCDEF"; // tablou de conversie

void baza16(int n){
    if(n == 0)
        return ;
    baza16(n / 16);
    cout << cifre16[n % 16];
}

int main(){
    
    baza16(255);
    
    return 0;
}