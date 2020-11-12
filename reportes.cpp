#include <iostream>
#include <cstdlib>
#include "reportes.h"
#include "vendedor.h"
#include "prospecto.h"
#include "venta.h"

using namespace std;

void ventaxVendedor(){
    Vendedor s;
    Venta v;
    int opc, anio, id, pos, i = 0;
    float tot;
    system("cls");
    cout << "-- VENTAS POR VENDEDOR -- "<<endl<<endl;
    cout << "INGRESE EL ID DE VENDEDOR A CONSULTAR"<<endl;
    cin >> id;
    pos = buscarVendedor(id);
    s.mostrarVendedorInd(pos++);
    cout <<endl;
    cout << "REPORTE POR TOTAL (1) O ANUAL (2)?";
    cin >> opc;
    if (opc == 1){
        while (v.getVendedor() == id){
            v.leerDisco(pos);
            tot+=v.getMonto();
            i++;
        }
    }
}
