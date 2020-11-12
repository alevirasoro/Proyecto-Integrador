//METODOS DE LA CLASE PERSONA
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "persona.h"

using namespace std;

void Persona::setNombres(char *n){
    strcpy(nombres, n);
}

void Persona::setApellidos(char *a){
    strcpy(apellidos, a);
}

char * Persona::getApellidos(){
    return apellidos;
}

char * Persona::getNombres(){
    return nombres;
}

void Persona::cargarPersona(){
    cout << "NOMBRES: ";
    cin >> nombres;
    cout << "APELLDIOS: ";
    cin >> apellidos;
}

void Persona::mostrarPersona(){
    cout << "NOMBRES: "<<nombres<<endl;
    cout << "APELLIDOS: "<<apellidos<<endl;
}
