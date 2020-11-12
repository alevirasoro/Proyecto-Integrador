#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include "fecha.h"
#include "venta.h"
#include "prospecto.h"

using namespace std;

bool Venta::guardarDisco(int posicion){
    bool grabo;
    FILE *p;
    if (posicion == -1){
        p = fopen("ventas.dat", "ab");
        if (p == NULL){
            return false;
        }
    }
    else{
        p = fopen("ventas.dat", "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Venta), 0);
    }
    grabo = fwrite(this, sizeof(Venta),1, p);
    fclose(p);
    return grabo;
}

bool Venta::leerDisco(int posicion){
    FILE *p;
    bool leyo;
    p = fopen("ventas.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, posicion * sizeof (Venta), 0);
    leyo = fread(this, sizeof(Venta), 1, p);
    return leyo;
}

void Venta::cargarV(){
    Prospecto p;
    int pos;
    bool v = true;
    cout << "INGRESE EL VENDEDOR: ";
    cin >> idVendedor;
    cout << "INGRESE EL ID DE PROSPECTO: ";
    cin >> idProspecto;
    cout << "INGRESE EL SERVICIO VENDIDO: ";
    cin >> servicios;
    cout << "CANTIDAD DE UF/PROPIEDADES: ";
    cin >> cantidad;
    if (servicios == 1){
        montoVenta=cantidad*47;
    }else{
        montoVenta=cantidad*18;
    }
    cout << "INGRESE LA FECHA DE LA VENTA: ";
    fechaVenta.cargarFecha();
    pos = buscarIdProspecto(idProspecto);
    p = leerProspecto(pos);
    p.setVenta();
    guardarDisco(-1);
}

void Venta::mostrarVenta(){
    cout << "FECHA: ";
    fechaVenta.mostrarFecha();
    cout << "SERVICIO: "<<endl;
    if (servicios == 1){
        cout << "CONSORCIOS"<<endl;
    }else{
        cout << "ALQUILERES"<<endl;
    }
    cout << "VENDEDOR: ";
    cout << idVendedor<<endl;
    cout << "$: ";
    cout << montoVenta;
}

int Venta::getVendedor(){
    return idVendedor;
}

float Venta::getMonto(){
    return montoVenta;
}

//FUNCIONES GLOBALES

void cargarVenta(){
    Venta v;
    v.cargarV();
}

void mostrarVentas(){
    system("cls");
    Venta v;
    int i = 0;
    while (v.leerDisco(i++)){
        v.mostrarVenta();
    }
    system("pause");
}


void setVendedor();
int getVendedor();
void setServicios();
int getServicios();
void setCantidad();
int getCantidad();
void setMonto();
float getMonto();
void setFecha();
Fecha getFecha();
bool leerDisco();
