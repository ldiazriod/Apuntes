#include <lista.h>
#include<iostream>
#include<sstream>
using namespace std;

Lista::Lista()
{
    inicio = nullptr;
    fin = nullptr;
}

Lista::~Lista()
{
    while(inicio != nullptr){
        eliminaFin();
    }
}

bool Lista::vacia()
{
    return (inicio == nullptr);
}

int Lista::elementos()
{
    NodoLista *p = inicio;
    int count{0};
    if(vacia()){
        return 0;
    }else {
        while(p != nullptr){
            count++;
            p = p ->siguiente;
        }
    }  
    cout << count << endl;
}

bool Lista::existe(int v)
{
    
}

void Lista::insertaInicio(int v)
{
    NodoLista *p = new NodoLista;
    p->dato = v;
    if(vacia()){
        p->siguiente = nullptr;
        inicio = p;
        fin = p;
    }else{
        p->siguiente = inicio;
        inicio = p;
    }
}

void Lista::insertaFin(int v)
{
    NodoLista *p = new NodoLista;
    p->dato = v;
    p->siguiente = nullptr;
    if(vacia()){
        inicio = p;
        fin = p;
    }else{
        fin->siguiente=p;
        fin = p;
    }
}

int Lista::eliminaInicio()
{
    NodoLista *p = inicio;
    if(vacia()) throw std::string ("Lista Vacia");
    
    int v = inicio ->dato;
    if(inicio == fin){
        inicio =nullptr;
        fin = nullptr;
    }else{
        inicio = inicio ->siguiente;
    }
    delete p;
    return v;
}

int Lista::eliminaFin()
{
    NodoLista *p = fin;
    if(vacia()) throw std::string ("Lista Vacia");
    
    int v = fin->dato;
    if(inicio == fin){
        inicio = nullptr;
        fin = nullptr;
    }else{
        NodoLista *q = inicio;
        while(q->siguiente != fin){
            q = q ->siguiente;
        }
        q ->siguiente = nullptr;
        fin = q;
        delete p;
        return v;
    }   
}

void Lista::elimina(int v)
{
   
}

std::string Lista::toString(std::string s)
{
    stringstream ss;
    NodoLista *p = inicio;
    if(p == nullptr){
        ss << "Lista Vacia" << endl;
    }else{
        ss << s << " (";
        while(p != nullptr) {
            ss << p->dato << ",";
            p=p->siguiente;
        }
        ss << "}" << " ";
    }
    return ss.str();
}
