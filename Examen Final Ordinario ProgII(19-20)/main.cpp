#include <iostream>
#include <memory>
#include "data.h"
#include <vector>

using namespace std;

using std:: shared_ptr;
using std:: make_shared;

class Persona{
public:
    Persona(string _nombre, int _nacimiento, int _telefono): nombre{_nombre}, nacimiento{_nacimiento}, telefono{_telefono}{}
  string getNombre() const;
  void setNombre(const string &value);

  int getNacimiento() const;
  void setNacimiento(int value);

  int getTelefono() const;
  void setTelefono(int value);

private:
  string nombre;
  int nacimiento, telefono;

};


ostream & operator << (ostream &o, shared_ptr<Persona> p){
    o << p->getNombre() << "," << p->getNacimiento() << "," << p->getTelefono();
    return o;
}



int main()
{
    string eleccion;
    string nombree;
    int year{0}, numero{0};

   Data<shared_ptr<Persona>> misPersonas;

   misPersonas.push_back(make_shared<Persona> ("Hola", 1, 2));

   cout << misPersonas << endl;

   while(eleccion != "exit"){
   cout << "Quiere anadir, ver el listado, buscar a una persona, o borrar: ";
   cin >> eleccion;

   if(eleccion == "Anadir" || eleccion =="anadir"){

       cout << "Anada los datos con separacion y sin comas: ";
       cin >> nombree >> year >> numero;

       misPersonas.push_back(make_shared<Persona> (nombree, year, numero));

   }else if(eleccion == "listado"){
       cout << misPersonas << endl;

   }else if(eleccion == "buscar"){
       
       
   }else if(eleccion == "borrar"){
       int borrar;
       cout << "Que quieres borrar?: ";
       cin >> borrar;

       misPersonas.erase(borrar);

       cout << "Así se ha quedado su lista: "<< endl;

       cout << misPersonas << endl;

   }else{
       eleccion = "exit";
   }

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

int Persona::getNacimiento() const
{
return nacimiento;
}

void Persona::setNacimiento(int value)
{
nacimiento = value;
}

int Persona::getTelefono() const
{
return telefono;
}

void Persona::setTelefono(int value)
{
telefono = value;
}
