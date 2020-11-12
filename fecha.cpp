//FUNCIONES DE CLASE FECHA
#include <iostream>
#include "fecha.h"

using namespace std;


Fecha::Fecha(int d,int m,int a){
    dia = d;
    mes = m;
    anio = a;
}
void Fecha::setAnio(){
    cout << "Ingrese el anio: "<<endl;
    cin >> anio;
}
void Fecha::setMes(){
    cout << "Ingrese el mes: "<<endl;
    cin >> mes;
}
void Fecha::setDia(){
    cout << "Ingrese el dia: "<<endl;
    cin >> dia;
}

void Fecha::mostrarFecha(){
    cout << dia<< "/"<< mes << "/" << anio<<endl;
}
void Fecha::cargarFecha(){
    cout << "INGRESE EL DIA: ";
    cin >> dia;
    cout << "INGRESE EL MES: ";
    cin >> mes;
    cout << "INGRESE EL ANIO: ";
    cin >> anio;
}
