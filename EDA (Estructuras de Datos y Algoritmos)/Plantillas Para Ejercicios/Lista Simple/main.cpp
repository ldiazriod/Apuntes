#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

class Lista{
public:
    Lista();
    bool vacia();

    //Insertar en lista vacia(Para no repetir codigo)
    void insertarListaVacia(Nodo *n);

    //Insertar un nodo directamente
    void insertarInicio(Nodo *n);
    void insertarFinal(Nodo *n);

    //Insertar un nodo mediante un valor
    void insertarInicioValor(int valor);
    void insertarFinalValor(int valor);

private:
    Nodo* primero, *ultimo;

};

int main()
{
    Nodo *n1 = new Nodo{1, nullptr};
    Nodo *n2 = new Nodo{2, nullptr};
    Nodo *n3 = new Nodo{3, nullptr};
    Nodo *n4 = new Nodo{4, nullptr};

    Lista MiLista;

    MiLista.insertarInicio(n1);
    MiLista.insertarInicio(n2);
    MiLista.insertarInicio(n3);
    MiLista.insertarFinal(n4);
    return 0;
}

Lista::Lista()
{
    primero = nullptr;
    ultimo = nullptr;
}

bool Lista::vacia()
{
    return (primero == nullptr);
}

void Lista::insertarListaVacia(Nodo *n)
{
    if(n != nullptr){
        Nodo *NuevoNodo = new Nodo;
        *NuevoNodo = *n;
        NuevoNodo->siguiente = nullptr;
        primero = NuevoNodo;
        ultimo = NuevoNodo;
    }
}

void Lista::insertarInicio(Nodo *n)
{
    if(vacia()){
        insertarListaVacia(n);
    }else{
        Nodo *NuevoNodo = new Nodo;
        *NuevoNodo = *n;
        NuevoNodo->siguiente = primero;
        NuevoNodo = primero;
    }
}

void Lista::insertarFinal(Nodo *n)
{
    if(vacia()){
        insertarListaVacia(n);
    }else{
        Nodo *NuevoNodo = new Nodo;
        NuevoNodo->siguiente = nullptr;
        ultimo->siguiente = NuevoNodo;
        ultimo = NuevoNodo;
    }
}

void Lista::insertarInicioValor(int valor)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->dato = valor;
    if(vacia()){
        insertarListaVacia(NuevoNodo);
    }else{
        NuevoNodo->siguiente = primero;
        primero = NuevoNodo;
    }
}

void Lista::insertarFinalValor(int valor)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->dato = valor;
    if(vacia()){
        insertarListaVacia(NuevoNodo);
    }else{
        NuevoNodo->siguiente = nullptr;
        ultimo->siguiente = NuevoNodo;
        ultimo = NuevoNodo;
    }
}
