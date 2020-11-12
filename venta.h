#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "fecha.h"

class Venta{

private:
    int idProspecto;
    int idVendedor;
    int servicios;//1: Consorcios 2:Alquileres
    int cantidad;
    float montoVenta;
    Fecha fechaVenta;

public:
    void cargarV();
    void mostrarVenta();
    void setId();
    int getID();
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
    bool leerDisco(int);
    bool guardarDisco(int = -1);
};

//FUNCIONES GLOBALES

void cargarVenta();
void mostrarVentas();

#endif // VENTA_H_INCLUDED
