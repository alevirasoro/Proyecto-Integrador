#include <iostream>
#include "vendedor.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

//FALTAN TODAS LAS VALIDACIONES

void Vendedor::setNombres(char * nn){
    strcpy(nombres, nn);
}

void Vendedor::setApellidos(char * na){
    strcpy(apellidos, na);
}

char * Vendedor::getNombres(){
    return nombres;
}

char * Vendedor::getApellidos(){
    return apellidos;
}

void Vendedor::setId(){
    cout << "INGRESE EL ID: ";
    cin >> id;
}

void Vendedor::setCom(){
    cout << "INGRESE LA COMISION: ";
    cin >> comision;
}

int Vendedor::getCom(){
    return comision;
}
int Vendedor::getId(){
    return id;
}
void Vendedor::mostrarV(){
    cout << left;
    cout << setw(14) << "NOMBRES" << setw(12) << "APELLDIOS" << setw(6) << "ID" << setw(10) << "% COMISION"<<endl;
    cout << "-----------------------------------------"<<endl;
    cout <<setw(14);
    cout << nombres;
    cout << setw(12);
    cout << apellidos;
    cout << setw(6);
    cout << id;
    cout << setw(12);
    cout << comision;
    /*cout << "NOMBRE: "<<nombres<<endl;
    cout << "APELLIDOS: "<<apellidos<<endl;
    cout << "ID: "<<id<<endl;
    cout << "COMISION: "<<comision<<"%"<<endl<<endl;*/
    cout << endl<<endl;
}

//BUSCAR UNA FORMA DE QUE LOS ID SEAN AUTOMATICOS

void Vendedor::cargarV(){
    cout << "INGRESE EL NOMBRE: ";
    cin.ignore();
    cin.getline (nombres, 50, '\n');
    cout << "INGRESE EL APELLIDO: ";
    cin.getline (apellidos, 50, '\n');
    cout << "PORCENTAJE DE COMISION: ";
    cin >> comision;
    cout << "ID: ";
    id = generarId();
    cout << id;
    guardarDisco(-1);
}

bool Vendedor::guardarDisco(int posicion){
    FILE *p;
    bool grabo;
    if (posicion == - 1){
        p = fopen("vendedores.dat", "ab");
        if (p == NULL){
            return false;
        }
    }
    else{
        p = fopen("vendedores.dat", "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Vendedor), 0);
    }
    grabo = fwrite(this, sizeof(Vendedor),1, p);
    fclose(p);
    return grabo;
}

bool Vendedor::leerDisco(int posicion){
    FILE *p;
    bool leyo;
    p = fopen("vendedores.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, posicion * sizeof (Vendedor), 0);
    leyo = fread(this, sizeof(Vendedor), 1, p);
    return leyo;
}

//-------FUNCIONES GLOBALES DE VENDEDORES------

void cargarVendedor(){
    Vendedor v;
    system("cls");
    v.cargarV();
}

void mostrarVendedores(){
    system("cls");
    Vendedor v;
    int i = 0;
    while (v.leerDisco(i++)){
        v.mostrarV();
    }
    system("pause");
}

void Vendedor::mostrarVendedorInd(int bus){
    system("cls");
    Vendedor v;
    int i = 0;
    while (v.leerDisco(i++)){
        if (bus == v.getId())
        v.mostrarV();
    }
}

bool modificarVendedor(){
    system("cls");
    int id, pos;
    Vendedor v;
    cout << "ID de Vendedor: ";
    cin >> id;
    pos = buscarVendedor(id);
    if(pos>=0){
    cout << "Vendedor a Modificar: "<<endl;
    v = leerVendedor(pos);
    v.mostrarVendedorInd(id);
    cout << "POSICION: "<<pos;
    cout << endl;
    cout << "Nueva Comision: ";
    v.setCom();
    if (v.guardarDisco(pos) == true){
        cout << "Vendedor modificado con Exito";
        system("pause");
        return true;
    }
    else{
        cout << " No se guardo el vendedor";
        return false;
    }
    }
    else{
        cout<< "No existe el vendedor";
        return false;
}
}

int buscarVendedor(int cbuscado){
    Vendedor v;
    FILE *p;
    int pos = 0;
    p = fopen("vendedores.dat", "rb");
    if(p == NULL){
        return -2;
    }
    while (fread(&v, sizeof(Vendedor), 1, p)){
        if (cbuscado == v.getId()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

//VALIDAR CUANDO ES EL PRIMERO QUE NO SEA 0
int generarId(){
    FILE *p = fopen("vendedores.dat", "rb");
    Vendedor aux;
    int bytes, cant, id;
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes/sizeof(Vendedor);
    if (cant == 0){
        cant = 1;
    }else{
    cant++;
    id = cant;
    }
    return id;
}

Vendedor leerVendedor(int id){
    Vendedor reg;
    FILE *p = fopen("vendedores.dat", "rb");
    /*
    if (p == NULL){
        reg = 0;
        return reg;
    }*/
    fseek(p, id * sizeof(Vendedor), SEEK_SET);
    fread(&reg, sizeof(Vendedor), 1, p);
    fclose(p);
    return reg;
}
