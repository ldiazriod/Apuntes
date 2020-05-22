#ifndef DATA_H
#define DATA_H

#endif // DATA_H

#include <iostream>
#include <vector>

using namespace std;


template<class T>
class Data{
public:
    Data(){}
    ~Data(){}

    //Buscar forma de enlazar DNI con datos.
    void push_back(T const &d);
    void erase(int pos);
    void newPersona(T const &d, int pos);
    T search(T const &d);


    vector<T> getDatos() const;
    void setDatos(const vector<T> &value);

    string getClave() const;
    void setClave(const string &value);

private:
    vector<T> datos;
    string clave;
};

template<class T>
void Data<T>::push_back(const T &d){
    datos.push_back(d);
}

template<class T>
void Data<T>::erase(int pos){
    datos.erase(datos.begin() + pos);
}

template<class T>
void Data<T>::newPersona(const T &d,int pos){
    datos.insert(datos.begin() + pos, d);
}

template<class T>
T Data<T>::search(const T &d){
    for(int i{0}; i < datos.size(); i++){
        if(datos.at(i) == d){
            cout << "Aqui esta lo que buscabas: " << i << endl;
        }
    }
}

template<class T>
vector<T> Data<T>::getDatos() const
{
    return datos;
}

template<class T>
void Data<T>::setDatos(const vector<T> &value)
{
    datos = value;
}

template<class T>
string Data<T>::getClave() const
{
return clave;
}

template<class T>
void Data<T>::setClave(const string &value)
{
clave = value;
}

template<class T>
ostream & operator<<(ostream &os, Data<T> p){
    auto datos = p.getDatos();
    for(auto elem : datos){
        cout << elem << "--";
    }
    return os;

   }
