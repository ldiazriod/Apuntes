#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Usuario{
public:
    Usuario(string _nombre): nombre{_nombre}{}

    void welcome();

    string getNombre() const;
    void setNombre(const string &value);

private:

    string nombre;
};

void mainMenu();
void guardarFicheroMod(string nomMod, string dim, vector<vector<string>> color, vector<vector<string>> nota, vector<vector<string>> algorit);
void guardarFicheroNoMod(string dim, vector<vector<string>> color, vector<vector<string>> nota, vector<vector<string>> algorit);
void newCubeMenu();

void documentosPush_Back(string nombreFichero);

void printFicheros();
void searchFicheros();

void eliminar();
void eliminardeLista(string nombre);


int main()
{
    try {

        //Variables clase Usuario
        string nombre;

        //Variables para la clase cubo
        string modName, dimensiones;
        vector<string> unColor; vector<vector<string>> todosMisColores; //Lo hago así para que salgan todos los colores en lineas distinta.
        vector<string> notacionUnaCara; vector<vector<string>> todasMisNotaciones; //Igual que con colores
        vector<string> unAlgoritmo; vector<vector<string>> todosMisAlgoritmos;    //De la misma forma que en los dos anteriores.

        Usuario miUsuario(nombre);

        miUsuario.welcome();

        mainMenu();

    } catch (string e) {

        cout << e << endl;
    }
    return 0;
}

//Otros

void newCubeMenu(){
    string nomMod, dim;
    int decision;
    int numColores, numCapas, numAlgorit;
    //Vectores para la matriz de colores
    string color;
    vector<string> unColor;
    vector<vector<string>> todosLosColores;
    //Vectores para la matriz de notaciones
    string notacion;
    vector<string> unNotacion;
    vector<vector<string>> todasMisNotaciones;
    //Vectores para la matriz de algoritmos
    string algoritmo;
    vector<string> unAlgoritmo;
    vector<vector<string>> todosMisAlgoritmos;


    cout << endl;

    cout << "Que tipo de cubo es?: " << endl;
    cout << "1. Normal" << endl;
    cout << "2. Modificacion" << endl;
    cout << "3. Volver" << endl;

    cin >> decision;

    if(decision < 1 || decision > 3){
        throw string {"No es un opcion valida"};

    }else{
        switch(decision) {

        case 1: {

            cout << endl;

            cout << "Cuales son las dimensiones del cubo?: ";
            cin >> dim;

            cout << endl;

            cout << "Cuantos colores tiene tu cubo:? ";
            cin >> numColores;

            for(int i{0}; i < numColores; i++){
                cout << "Cual es el siguiente color?: ";
                cin >> color;

                unColor.push_back(color);
                todosLosColores.push_back(unColor);
                unColor.erase(unColor.begin(), unColor.end());
            }
            cout << endl;

            cout << "Cuantas capas tiene tu cubo? (Necesario para la notacion): ";
            cin >> numCapas;

            for(int j{0}; j < numCapas; j++){
                cout << "Meta la capa a la que se refiera, seguida de la letra utilizada para la notacion: ";
                cin >> notacion;

                unNotacion.push_back(notacion);
                todasMisNotaciones.push_back(unNotacion);
                unNotacion.erase(unNotacion.begin(), unNotacion.end());
            }

            cout << endl;

            cout << "Cuantos algoritmos tiene el cubo? Debe contar además con algoritmos de uso ocasional como los de paridadad: ";
            cin >> numAlgorit;

            cout << endl;

            cout << "Meta el algoritmo, ademas le recomendamos añadir antes de meter el algoritmo numerar o especificar el algoritmo." << endl;

            cout << "Ejemplo: " << endl;
            cout << "1. B,F,L,E,Rr,B" << endl;
            cout << "Paridad 1. B'" << endl;

            cout << endl;

            for(int k{0}; k < numAlgorit; k++){

                cout << "Meta el algoritmo: ";
                cin >> algoritmo;

                unAlgoritmo.push_back(algoritmo);
                todosMisAlgoritmos.push_back(unAlgoritmo);
                unAlgoritmo.erase(unAlgoritmo.begin(), unAlgoritmo.end());

            }

            guardarFicheroNoMod(dim, todosLosColores, todasMisNotaciones, todosMisAlgoritmos);
            cout << "Se ha guardado todo correctamente." << endl;

            cout << "Quiere hacer alguna otra cosa?: ";
            mainMenu();

            break;
        }

        case 2: {

            cout << endl;

            cout << "Meta el nombre de la modificacion: ";
            cin >> nomMod;

            cout << endl;

            cout << "Cuales son las dimensiones del cubo?: ";
            cin >> dim;

            cout << endl;

            cout << "Cuantos colores tiene tú cubo:? ";
            cin >> numColores;

            for(int i{0}; i < numColores; i++){
                cout << "Cual es el siguiente color?: ";
                cin >> color;

                unColor.push_back(color);
                todosLosColores.push_back(unColor);
                unColor.erase(unColor.begin(), unColor.end());
            }
            cout << endl;

            cout << "Cuantas capas tiene tu cubo? (Necesario para la notacion): ";
            cin >> numCapas;

            for(int j{0}; j < numCapas; j++){
                cout << "Meta la capa a la que se refiera, seguida de la letra utilizada para la notacion: ";
                cin >> notacion;

                unNotacion.push_back(notacion);
                todasMisNotaciones.push_back(unNotacion);
                unNotacion.erase(unNotacion.begin(), unNotacion.end());
            }

            cout << endl;

            cout << "Cuantos algoritmos tiene el cubo? Debe contar además con algoritmos de uso ocasional como los de paridadad: ";
            cin >> numAlgorit;

            cout << endl;

            cout << "Meta el algoritmo, ademas le recomendamos añadir antes de meter el algoritmo numerar o especificar el algoritmo." << endl;

            cout << "Ejemplo: " << endl;
            cout << "1. B,F,L,E,Rr,B";
            cout << "Paridad 1. B'";

            cout << endl;

            for(int k{0}; k < numAlgorit; k++){

                cout << "Meta el algoritmo: ";
                cin >> algoritmo;

                unAlgoritmo.push_back(algoritmo);
                todosMisAlgoritmos.push_back(unAlgoritmo);
                unAlgoritmo.erase(unAlgoritmo.begin(), unAlgoritmo.end());

            }

            guardarFicheroMod(nomMod, dim, todosLosColores, todasMisNotaciones, todosMisAlgoritmos);
            cout << "Se ha guardado todo correctamente." << endl;

            cout << "Quiere hacer alguna otra cosa?: ";

            cout << endl;

            mainMenu();

            break;
        }

        case 3:{

            cout << endl;

            mainMenu();

            break;
        }

        }
    }
}

void mainMenu(){

    int decision;

    cout << "Que quieres hacer?: " << endl;
    cout << "1. Nuevo Cubo" << endl;
    cout << "2. Buscar Cubo" << endl;
    cout << "3. Eliminar Cubo" << endl;
    cout << "4. Salir" << endl;

    cin >> decision;

    if(decision < 1 || decision > 4 ){
        throw string {"No es una opcion valida"};
    }else{
        switch(decision){

        case 1:{
            newCubeMenu();
            break;
        }
        case 2:{
            cout << endl;

            searchFicheros();

            break;
        }

        case 3:{
            cout << endl;

            eliminar();

            break;
        }

        case 4:{

            ifstream miUsuario ("Usuario.txt");
            string nombreUsuario;

            if(!miUsuario.eof()){
                miUsuario >> nombreUsuario;

                cout << "Adios " << nombreUsuario << endl;

                miUsuario.close();
            }

        }

        }
    }
}

void guardarFicheroMod(string nomMod, string dim, vector<vector<string>> color, vector<vector<string>> nota, vector<vector<string>> algorit){

    string nombreFichero{nomMod + dim + ".txt"};
    ofstream miNuevoCubo(nombreFichero);

    miNuevoCubo << "Nombre de la modificacion: " << nomMod << endl;

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Dimensiones del cubo: " << dim << endl;

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Colores de las caras del cubo: " << endl;

    for(unsigned int i{0}; i < color.size(); i++){
        for(unsigned int j{0}; j < color.at(i).size(); j++){
            miNuevoCubo << color.at(i).at(j);
            miNuevoCubo << " " << "|" << endl;
        }
    }

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Notacion del cubo: " << endl;

    for(unsigned int ii{0}; ii < nota.size(); ii++){
        for(unsigned int jj{0}; jj < nota.at(ii).size(); jj++){
            miNuevoCubo << nota.at(ii).at(jj);
            miNuevoCubo << " " << "|" << endl;
        }
    }

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Algoritmos del cubo: " << endl;

    for(unsigned int iii{0}; iii < algorit.size(); iii++){
        for(unsigned int jjj{0}; jjj < algorit.at(iii).size(); jjj++){
            miNuevoCubo << algorit.at(iii).at(jjj);
            miNuevoCubo << " " << "|" << endl;
        }
    }
    miNuevoCubo.close();

    documentosPush_Back(nombreFichero);
}

void guardarFicheroNoMod(string dim, vector<vector<string>> color, vector<vector<string>> nota, vector<vector<string>> algorit){

    string nombreFichero{dim + ".txt"};
    ofstream miNuevoCubo(nombreFichero);

    miNuevoCubo << "Dimensiones del cubo: " << dim << endl;

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Colores de las caras del cubo: " << endl;

    for(unsigned int i{0}; i < color.size(); i++){
        for(unsigned int j{0}; j < color.at(i).size(); j++){
            miNuevoCubo << color.at(i).at(j);
            miNuevoCubo << " " << "|" << endl;
        }
    }

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Notacion del cubo: " << endl;

    for(unsigned int ii{0}; ii < nota.size(); ii++){
        for(unsigned int jj{0}; jj < nota.at(ii).size(); jj++){
            miNuevoCubo << nota.at(ii).at(jj);
            miNuevoCubo << " " << "|" << endl;
        }
    }

    miNuevoCubo << "-----------------------------" << endl;

    miNuevoCubo << "Algoritmos del cubo: " << endl;

    for(unsigned int iii{0}; iii < algorit.size(); iii++){
        for(unsigned int jjj{0}; jjj < algorit.at(iii).size(); jjj++){
            miNuevoCubo << algorit.at(iii).at(jjj);
            miNuevoCubo << " " << "|" << endl;
        }
    }
    miNuevoCubo.close();

    documentosPush_Back(nombreFichero);
}

void documentosPush_Back(string nombreFichero){

    ifstream misDatos ("todosMisDatos.txt");
    ofstream aux ("auxiliar.txt");
    string nombres;

    vector<string> ficheros;

    while(!misDatos.eof()){

        misDatos >> nombres;

        ficheros.push_back(nombres);
    }

    ficheros.push_back(nombreFichero);

    for(unsigned int i{0}; i < ficheros.size(); i++){
        if(ficheros.at(i) == nombreFichero){
            aux << ficheros.at(i);
        }else{
            aux << ficheros.at(i) << endl;
        }

    }

    misDatos.close();
    aux.close();

    remove("todosMisDatos.txt");
    rename("auxiliar.txt", "todosMisDatos.txt");

}

void eliminardeLista(string nombre){
    ifstream misDatos ("todosMisDatos.txt");
    ofstream aux("auxiliar.txt");
    string nombres;
    unsigned int count{0};

    vector<string> ficheros;

    while(!misDatos.eof()){
        misDatos >> nombres;

        ficheros.push_back(nombres);
    }

    for(unsigned int i{0}; i < ficheros.size(); i++){
        if(ficheros.at(i) == nombre){
            ficheros.erase(ficheros.begin()+i);
        }
    }

    for(unsigned int j{0}; j < ficheros.size(); j++){
        count++;
        if(count == ficheros.size()){
            aux << ficheros.at(j);
        }else{
            aux << ficheros.at(j) << endl;
        }
    }

    misDatos.close();
    aux.close();

    remove("todosMisDatos.txt");
    rename("auxiliar.txt", "todosMisDatos.txt");

}

void printFicheros(){
    ifstream miDatos("todosMisDatos.txt");
    string cubos;
    int count{0};

    while(!miDatos.eof()){
        count++;

        string s = to_string(count);

        miDatos >> cubos;

        cout << s << ". " << cubos << endl;
    }

}

void searchFicheros(){
    //ifstream miFichero("todosMisDatos");
    char volver;
    string nombreFichero;
    string datosDelCubo;
    int count{0};

    cout << "Estos son los cubos que tienes guardados: " << endl;

    cout << endl;

    printFicheros();

    cout << "Cual de los siguientes cubos quieres ver?: ";
    cin >> nombreFichero;

    cout << endl;

    ifstream verCubo(nombreFichero + ".txt");

    if(nombreFichero.size() > 3){
        while(!verCubo.eof()){

            verCubo >> datosDelCubo;

            if(datosDelCubo != "-----------------------------"){
                if(datosDelCubo == nombreFichero){
                    datosDelCubo = " ";
                }

                if(datosDelCubo == "|"){
                    datosDelCubo = "";
                    cout << endl;
                    cout << datosDelCubo;
                }else{
                    cout << datosDelCubo << " ";
                }

                if(datosDelCubo == "cubo:"){
                    if(count == 0){
                        count++;
                    }else{
                        cout << endl;
                        cout << endl;
                        cout << "";
                    }
                }

            }else{
                cout << endl;
                cout << datosDelCubo << endl;
            }

        }

        cout << endl;
        cout << endl;

        cout << "Cuando desee volver, pulse -v-" << endl;
        cin >> volver;

        if(volver != 'v'){
            throw string {"No es una opcion valida"};

        }else{
            mainMenu();
        }

    }else{

        while(!verCubo.eof()){

            verCubo >> datosDelCubo;

            if(datosDelCubo != "-----------------------------"){
                if(datosDelCubo == nombreFichero){
                    datosDelCubo = " ";
                }

                if(datosDelCubo == "|"){
                    datosDelCubo = "";
                    cout << endl;
                    cout << datosDelCubo;
                }else{
                    cout << datosDelCubo << " ";
                }

                if(datosDelCubo == "cubo:"){
                    if(count == 0){
                        count++;
                        datosDelCubo = nombreFichero;
                        cout << datosDelCubo;
                    }else{
                        cout << endl;
                        cout << endl;
                        cout << "";
                    }
                }

            }else{
                cout << endl;
                cout << datosDelCubo << endl;
            }

        }

        cout << endl;
        cout << endl;

        cout << "Cuando desee volver, pulse -v-" << endl;
        cin >> volver;

        if(volver != 'v'){
            throw string {"No es una opcion valida"};

        }else{
            mainMenu();
        }
    }

}


void eliminar(){
    string nombre;
    string misDatos;
    int decision;
    printFicheros();

    cout << "Que fichero desea eliminar?: ";
    cin >> nombre;

    cout << endl;

    cout << "Esta seguro de que quiere eliminar el siguiente archivo?: "  << nombre + ".txt" << endl;
    cout << "1. No" << endl;
    cout << "2. Si" << endl;
    cin >> decision;

    cout << endl;

    if(decision < 1 || decision > 2){
        throw string {"No es una opcion valida"};
    }else{
        switch(decision){
        case 1:{

            cout << "Se le ha devuelto al menu princiapal" << endl;

            cout << endl;

            mainMenu();

            break;
        }

        case 2:{
            const char *datName;

            nombre = nombre + ".txt";

            datName = nombre.c_str();

            remove(datName);

            eliminardeLista(nombre);

            cout << "Su fichero ha sido eliminado" << endl;

            cout << endl;

            mainMenu();

        }

        }

    }

}

//CLASE USUARIO
void Usuario::welcome(){
    ifstream miUsuario("Usuario.txt");
    string nombre, nombreUsuario;

    if(!miUsuario.is_open()){
        ofstream nuevoUsuario ("Usuario.txt");
        ofstream nuevoFicheroDeFicheros ("todosMisDatos.txt");
        cout << "Bienvenido, vemos que es la primera vez que te metes, podrías meter tu nombre?: ";
        cin >> nombre;

        nuevoUsuario << nombre;
        nuevoUsuario.close();
        nuevoFicheroDeFicheros.close();
    }

    if(!miUsuario.eof()){
        miUsuario >> nombreUsuario;

        cout << "Bienvenido a tu base de datos " << nombreUsuario << endl;

        miUsuario.close();
    }
}

string Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(const string &value)
{
    nombre = value;
}
