#include <iostream>
#include <cstdlib>
#include <cstring>
#include "prospecto.h"
#include "fecha.h"
#include "fecha.cpp"
#include <cstdio>

using namespace std;


//FALTAN TODAS LAS VALIDACIONES

char * Prospecto::getMail(){
    return mail;
}

void Prospecto::setMail(char *nMail){
    strcpy(mail, nMail);
}

int Prospecto::getSeguimiento(){
    return seguimiento;
}

char * Prospecto::getObs(){
    return observacion;
}

void Prospecto::setObs(char *o){
    strcpy(observacion, o);
}

char * Prospecto::getNombreEmp(){
    return nomEmp;
}

void Prospecto::setNombreEmp(char *e){
    strcpy(nomEmp, e);
}

int Prospecto::getIdProspecto(){
    return idProspecto;
}

void Prospecto::setVenta(){
    venta = true;
}

bool Prospecto::getVenta(){
    return venta;
}
// FALTAN TODOS LOS SET Y GETS RETANTES

bool Prospecto::guardarDisco(int posicion){
    bool grabo;
    FILE *p;
    if (posicion == -1){
        p = fopen("prospectos.dat", "ab");
        if (p == NULL){
            return false;
        }
    }
    else{
        p = fopen("prospectos.dat", "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Prospecto), 0);
    }
    grabo = fwrite(this, sizeof(Prospecto),1, p);
    fclose(p);
    return grabo;
}

bool Prospecto::leerDisco(int posicion){
    bool leyo;
    FILE *p;
    p = fopen("prospectos.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, posicion * sizeof (Prospecto), 0);
    leyo = fread(this, sizeof(Prospecto), 1, p);
    fclose(p);
    return leyo;
}

void Prospecto::mostrarProspecto(){
    if (venta == false){
    if (tipoCliente == 1){
        cout << "ADMINSTRACION: "<< nomEmp<<endl;
    }else{
        cout << "INMOBILIARIA: "<< nomEmp<<endl;
    }
    if (seguimiento == 0){
        cout<< "SEGUIMIENTO MEDIO"<<endl;
    }else{
        cout << "SEGUIMIENTO ALTO"<<endl;
    }
    cout << "TELEFONO: "<<telefono<<endl;
    cout << "MAIL: "<< mail<<endl;
    cout << "FECHA DE CONTACTO: ";
    fechaCont.mostrarFecha();
    cout << "OBSERVACIONES: "<< observacion<<endl;
    cout <<"ID Prospecto: "<<idProspecto<<endl;
    cout << "-----------------------"<<endl;
    }
}

void Prospecto::cargarProspecto(){

    cout << "Ingrese el telefono: ";
    cin >> telefono;
    cout <<endl;
    cout << "Mail: ";
    cin >> mail;
    cin.ignore();
    cout <<endl;
    cout << "Nombre de Administracion: ";
    cin.getline(nomEmp, 50, '\n');
    cout <<endl;
    cout << "Tipo de Cliente (1: Adm - 2: Inm: )";
    cin >> tipoCliente;
    cout <<endl;
    cout << "Seguimiento (0: Medio - 1: Alto): ";
    cin >> seguimiento;
    cout <<endl;
    cout << "Fecha: ";
    fechaCont.cargarFecha();
    cin.ignore();
    cout << "Observaciones: ";
    cin.getline(observacion, 80, '\n');
    cout << "Vendedor: ";
    cin >> idVendedor;
    cout <<endl;
    cout << venta;
    idProspecto = generarIdp();
    guardarDisco(-1);
}

void Prospecto::mostrarProspectoInd(int bus){
    system("cls");
    Prospecto p;
    int i = 0;
    while (p.leerDisco(i++)){
        if (bus == p.getSeguimiento())
        p.mostrarProspecto();
    }
}

//FUNCIONES GLOBALES

void listarProspectos(){
    Prospecto p;
    int i = 0;
    if (p.getVenta() == false){
    while (p.leerDisco(i++)){
        p.mostrarProspecto();
    }
    }
}

void nuevoProspecto(){
    system("cls");
    Prospecto p;
    p.cargarProspecto();
}
//VALIDAR CUANDO ES EL PRIMERO QUE NO SEA 0
int generarIdp(){
    FILE *p = fopen("prospectos.dat", "rb");
    Prospecto aux;
    int bytes, cant, id;
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes/sizeof(Prospecto);
    cant++;
    id = cant;
    return id;
}

int buscarProspecto(int seg){
    Prospecto aux;
    FILE *p;
    int pos = 0;
    p = fopen("prospectos.dat", "rb");
    if(p == NULL){
        return -2;
    }
    while (fread(&aux, sizeof(Prospecto), 1, p)){
        if (seg == aux.getSeguimiento()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool mostrarSeguimiento(){
    system("cls");
    int seg, pos;
    Prospecto p;
    cout << "SEGUIMIENTO: ";
    cin >> seg;
    pos = buscarProspecto(seg);
    if(pos>=0){
    cout << "Listado de Prospectos con seguimiento "<<endl;
    if (seg == 1){
        cout<< "ALTO"<<endl;
    }else{
        cout << "MEDIO"<<endl;
    }
    p.mostrarProspectoInd(seg);
    system("pause");
    return true;
    }
}

int buscarIdProspecto(int cod){
    Prospecto aux;
    FILE *p;
    int pos = 0;
    p = fopen("prospectos.dat", "rb");
    if(p == NULL){
        return -2;
    }
    while (fread(&aux, sizeof(Prospecto), 1, p)){
        if (cod == aux.getIdProspecto()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

Prospecto leerProspecto(int id){
    Prospecto reg;
    FILE *p = fopen("prospectos.dat", "rb");
    /*
    if (p == NULL){
        reg = 0;
        return reg;
    }*/
    fseek(p, id * sizeof(Prospecto), SEEK_SET);
    fread(&reg, sizeof(Prospecto), 1, p);
    fclose(p);
    return reg;
}
