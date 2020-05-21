#include <iostream>
#include <vector>
#include "list.h"
#include <memory>

using namespace std;

using std::shared_ptr;
using std::make_shared;

class Persona{
public:
    Persona(string nombre, int edad): nombre{nombre}, edad{edad}{};


    string getNombre() const;
    void setNombre(const string &value);

    int getEdad() const;
    void setEdad(int value);

private:
    string nombre;
    int edad;
};

ostream & operator<<(ostream &os, shared_ptr<Persona> p){
    os << p->getNombre() << ": "<<  p->getEdad();
    return os;
}


int main()
{
    try {
        string buscar;
        list<shared_ptr<Persona>> personas;

        personas.push_back(make_shared<Persona> ("Luis", 19));
        personas.push_back(make_shared<Persona> ("Hitler", 56));
        personas.push_back(make_shared<Persona> ("Stalin", 74));
        personas.push_back(make_shared<Persona> ("TuViejaA4", 100));

        cout << personas << endl;

        cout << personas.devolverReferencia(2) << endl;

        personas.erase(2);

        cout << personas << endl;

        personas.insert(make_shared<Persona> ("TuMadreEsUnaPuta", 10), 2);

        cout << personas << endl;

        personas.search(make_shared<Persona> ("Hitler", 56));



   }catch(string e){
        cout << e << "\n";
    }
    return 0;
}

string Persona::getNombre() const
{
return nombre;
}

void Persona::setNombre(const string &value)
{
nombre = value;
}

int Persona::getEdad() const
{
return edad;
}

void Persona::setEdad(int value)
{
edad = value;
}
