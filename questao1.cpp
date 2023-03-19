#include <iostream>
#include <math.h>
using namespace std;

int soma_cubos(int soma, int n){
    if(n == 0){
        return soma; 
    }else{
        soma += pow(n,3);
        return soma_cubos(soma,n-1);
    }
}
int main (){
    int num, s = 0;
    cin >> num;
    cout << "A soma dos cubos sequenciais é " << soma_cubos(s,num) << "!" << endl;
    return 0;
}