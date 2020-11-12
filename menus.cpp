#include <iostream>
#include "fecha.h"
#include "prospecto.h"
#include "prospecto.cpp"
#include "vendedor.h"
#include "funcglobales.h"
#include "venta.h"
#include "reportes.h"
#include "reportes.cpp"

using namespace std;

void menuPrincipal(){
    int opc;
    while (true){
    system("cls");
    cout << endl;
    cout << "-- VENDIENDO CRM --"<<endl<<endl;
    cout << "Ingrese una opcion"<<endl<<endl;
    cout << "1.NUEVO PROSPECTO/CONTACTO"<<endl;
    cout << "2.PROSPECTOS"<<endl;
    cout << "3.VENTAS"<<endl;
    cout << "4.REPORTES"<<endl;
    cout << "5.VENDEDORES"<<endl;
    cin >> opc;
    switch (opc)
    {
    case 1:
        nuevoProspecto();
        system("pause");
        break;
    case 2:
        menuProspectos();
        break;
    case 3:
        menuVentas();
        break;
    case 4:
        menuReportes();
        break;
    case 5:
        menuVendedores();
        }
    }
}

void menuProspectos(){
    int opc;
    while (true){
    system("cls");
    cout << "-- MENU PROSPECTOS --"<<endl<<endl;
    cout << "1. LISTAR PROSPECTOS"<<endl;
    cout << "2. LISTAR POR SEGUIMIENTO"<<endl;
    cout << "0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout << "INGRESE UNA OPCION: "<<endl;
    cin >> opc;
    system("cls");
    if (opc == 1){
        cout << "LISTADO DE PROSPECTOS: "<<endl<<endl;
    }
    switch (opc){
        case 1:
            listarProspectos();
            system("pause");
            break;
        case 2:
            mostrarSeguimiento();
            break;
        case 3:
//            data;
            break;
        case 4:
            //menuReportes;
            break;
        case 5:
            //mas cosas
        case 0:
            menuPrincipal();
        }
    }
}

//MENU QUE PERMITE CARGAR UNA NUEVA VENTA Y VER LAS EXISTENTES
void menuVentas(){
    int opc;
    while (true){
    system("cls");
    cout << "-- MENU VENTAS--"<<endl<<endl;
    cout << "1. NUEVA VENTA"<<endl;
    cout << "2. MOSTRAR VENTAS"<<endl;
    cout << "3. VENTAS CONSORCIOS"<<endl;
    cout << "0. VOLVER AL MENU PRINCIPAL"<<endl;
    cin >> opc;
    switch (opc){
    case 1:
        cargarVenta();
        break;
    case 2:
        mostrarVentas();
        break;
/*    case 3:
        ventasCons();
        break;
*/
    case 0:
        menuPrincipal();
        }
    }

}

void menuVendedores(){
    int opc;
    while (true){
    system("cls");
    cout << "-- MENU DE VENDEDORES -- "<<endl<<endl;
    cout << "1. NUEVO VENDEDOR"<<endl;
    cout << "2. VER VENDEDORES"<<endl;
    cout << "3. MODIFICAR VENDEDORES"<<endl<<endl;
    cout << "-------------------------"<<endl;
    cout << "0. VOLVER AL MENU PRINCIPAL"<<endl;
    cin >> opc;
    switch(opc){
    system("cls");
    case 1:
        cargarVendedor();
        break;
    case 2:
        mostrarVendedores();
        break;
    case 3:
        modificarVendedor();
        break;
    case 0:
        menuPrincipal();
        }
    }
}

void menuReportes(){
     int opc;
    while (true){
    system("cls");
    cout << "-- MENU DE REPORTES -- "<<endl<<endl;
    cout << "1. REPORTE POR VENDEDOR"<<endl;
    cout << "2. VER VENDEDORES"<<endl;
    cout << "3. MODIFICAR VENDEDORES"<<endl<<endl;
    cout << "-------------------------"<<endl;
    cout << "0. VOLVER AL MENU PRINCIPAL"<<endl;
    cin >> opc;
    switch(opc){
    system("cls");
    case 1:
        ventaxVendedor();
        break;
        }
    }
}
