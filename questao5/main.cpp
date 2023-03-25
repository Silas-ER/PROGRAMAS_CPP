#include <iostream>
#include "pri.h"
#include "fat.h"

using namespace std;

int main(){
    int num;
    int inicial = 1;
    cout << "Insira o numero que deseja saber o fatorial: ";
    cin >> num;
    cout << "O fatorial de " << num << " eh " << fatorial(num,inicial) << endl;
    cout << "O maior primo anterior eh " << primo_anterior(fatorial(num,inicial)-1,inicial) << endl;
    return 0;
}