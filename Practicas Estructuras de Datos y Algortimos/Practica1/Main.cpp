#include <iostream>
#include <math.h>
#include<vector>


using namespace std;


//Ejercicio 1
bool numPar(int n){
    if(n == 0){
        return true;
    }else if(n == 1){
        return false;
    }else{
        return numPar(n-2);
    }
}

//Ejercicio 2
bool esPar(int);
bool esImpar(int);
bool esPar(int n){
    if(n == 0){
        return true;
    }else{
        return esImpar(n -1);
    }
}

bool esImpar(int n){
    if(n == 1){
        return true;
    }else{
        return esPar(n-1);
    }
}

//Ejercicio 3
int producto(int n, int m){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return m;
    }else {
        return n + producto(n-1, m);
    }
}

//Ejercicio 4
int potencia1(int x, int n){
    if(n == 0){
        return 1;
    }else if(n == 1){
        return n;
    }else{
        return x * potencia1(x, n-1);
    }
}
//Ejercicio 5
int potencia2(int x, int n){
    int p = potencia2(x, n/2);
    if(n == 0){
        return 1;
    }else if(n % 2 == 0){
        return (p * p);
    }else{
        return (x * p * p);
    }
}

//Ejercicio 6
int factorial(int n){
    if(n == 0){
        return 1;
    }else {
        return n * factorial(n-1);
    }
}

//Ejercicio 7
int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

//Ejercicio 8
int cociente(int dividendo, int divisor){
    if(dividendo < divisor){
        return 0;
    }else{
        return 1 + cociente(dividendo - divisor, divisor);
    }
}

int resto(int dividendo, int divisor){
    if(dividendo < divisor){
        return dividendo;
    }else{
        return resto(dividendo - divisor, divisor);
    }
}

//Ejercicio 9
bool multiplo(int dividendo, int divisor){
    if(dividendo < divisor){
        return false;
    }else {

    }
}

//Ejercicio 10
int sumatoria(int n){
    if(n == 0){
        return 0;
    }else {
        return n + sumatoria(n-1);
    }
}

int sumatoriaPar(int n){
    if(n == 0){
        return 0;
    }else{
        return n + sumatoria(n-2);
    }
}
int sumatoriaImpar(int n){
    if(n == 1){
        return 1;
    }else {
        return n + sumatoria(n-2);
    }
}

//Ejercicio 11
int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(a, a % b);
    }
}

//Ejercicio 12
double eval(int coeficiente[], int n, int valor){
    double r = 0.0;
    for(int i{0}; i < n; i ++){
        r = r + coeficiente[i] * pow(valor,i);
    }

    return r;
}

//Ejercicio 13
int minimo(int v[], int n){
    if(n == 1){
        return v[0];
    }else{
        return min(v[n-1], minimo(v,n-1));
    }
}

void print(int v[], int n){
    if(n > 0){
        cout << v[n] << endl;
    }else{
        print(v, n-1);
    }
}

int maximo(int v[], int n){
    if(n == 1){
        return v[0];
    }else{
        return max(v[n-1], minimo(v,n-1));
    }
}

int sumatoria2(int v[], int n){
    if(n == 1){
        return v[0];
    }else{
        return v[n-1] + sumatoria2(v, n-1);
    }
}
int sumatoriaPar2(int v[], int n){
    if(n == 1){
        return v[0];
    }else{
        return v[n-2] + sumatoriaPar2(v, n-2);
    }
}
int sumatoriaImpar(int v[], int n){
    
}
/*
double promedio(int v[], int n, int total){

}
bool existe(int v[], int n, int valor){

}
void invierte(int v[], int p, int n){

}*/
//Ejercicio 14
void hanoi(int n, int origen, int auxiliar, int destino){
    if(n == 1){
        cout << "El disco " << n << " se mueve desde " << origen << " a la posicion " << destino << endl; //Si n = 1, solo hay un disco, por lo que se puede mover directamente al destino.
        return;
    }else{
        hanoi(n-1, origen, destino, auxiliar);
        cout << "El disco " << n << " se mueve desde " << origen << " a la posicion " << destino << endl;
        hanoi(n-1, auxiliar, origen, destino);
    }
}

//Ejercicio 15
bool par2(int n){
    for(int i{0}; i < n; i++){
        n = n - 2;
    }
    if(n != 0){
        cout << "Es impar" << endl;
    }else{
        cout << "Es par" << endl;
    }
}

//Ejercicio 16
int cociente2(int dividendo, int divisor){
    int cociente{0};
    while(dividendo >= divisor){
        cociente = cociente + 1;
    }
    cout << cociente << endl;
}

int resto2(int dividendo, int divisor ){
    int resto{0};
    while(dividendo >= divisor){
        dividendo = dividendo - divisor;
    }
    resto = dividendo;
    cout << resto << endl;
}

//Ejercicio 17
bool multiplo2(int dividendo, int divisor){

}

//Ejercicio 18
int fibonacci2(int n){
    int x{0}, y{1}, z{0};
    for(int i{1}; i < n; i++){
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
    }
    cout << endl;
}

//Ejercicio 19
void imprimeBinario(unsigned short n){
    vector<int>bit;
    for(int i{0}; n > 0; i++){
        bit.push_back(n % 2);
        n = n/2;
    }

    for(unsigned long long j{bit.size()}; j > 0; j--){
        cout << bit.at(j-1) << " ";
    }
}

//Ejercicio 20
int producto2(int n, int m){
    int suma{0};
    for(int i{0}; i < m; i++){
        suma = suma + n;
    }
    
    cout << suma << endl;
}

//Ejercicio 21
int potencia3(int x, int n){
    int producto{1};
    for(int i{0}; i < n; i++){
        producto = producto * x;
    }
    
    cout << producto << endl;
}

//Ejercicio 22
double eval2(int c[], int n, int valor){
    double r = 0.0;
    for(int i{0}; i < n; i++){
        r = r + c[i] * pow(valor,i);
    }
}

//Ejercicio 21

//Ejercicio 22
bool esEsperfecto(int n){
    int suma{0}, i{1};
    while(i < n){
        if(n % i == 0){
            suma = suma + i;
            i++;
        }
    }
    if(suma == n){
        cout << i << " es un numero perfecto" << endl;
    }else{
        cout << i << " no es un numero perfecto" << endl;
    }
}
int main()
{
   int n, m;
   cin >> n;
   cin >> m;
   cout << "-----" << endl;
  /* cout << "Meta el numero de discos que tiene la torre: ";
   cin >> n;

   cout << endl;
   cout << "La posicion 1 es el origen, la posicion 2 es la auxiliar, la posicion 3 es la final" << endl;
   hanoi(n, 1, 2, 3);
   */
   
    return 0;
}
