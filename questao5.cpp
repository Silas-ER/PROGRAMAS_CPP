#include <iostream>
using namespace std;

int fatorial(int n, int fat){
    if(n == 1){
        return fat;
    }else{
        fat *= n;
        return fatorial(n-1,fat);
    }
}

int primo_anterior(int n, int primo){
    int cont=0;
    if(n == 2){
        primo = n;
        return primo;
    }else{
        for(int i=n;i>0;i--){
            if(n%i == 0){
                cont++;
            }
        }
        if(cont == 2){
            primo = n;
            return primo;
        }else{
            return primo_anterior(n-1, primo);
        }
    }
}

int main(){
    int num, inicial = 1;
    cout << "Insira o numero que deseja saber o fatorial: ";
    cin >> num;
    cout << "O fatorial de " << num << " eh " << fatorial(num,inicial) << endl;
    cout << "O maior primo anterior eh " << primo_anterior(fatorial(num,inicial),inicial) << endl;
    return 0;
}