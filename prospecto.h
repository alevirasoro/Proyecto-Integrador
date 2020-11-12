#ifndef PROSPECTO_H_INCLUDED
#define PROSPECTO_H_INCLUDED
#include "persona.h"
#include "fecha.h"
#include <iostream>

class Prospecto:public Persona{

private:
    int telefono;
    char mail [50];
    char nomEmp [50];
    char observacion [80];
    int idVendedor;
    int seguimiento;
    int tipoCliente;
    Fecha fechaCont;
    int idProspecto;
    bool venta;

public:
    //CONSTRUCTOR? QUE PONGA TODO EN BASICO
    void setNombreEmp (char *);
    char * getNombreEmp();
    void setMail(char *);
    char * getMail();
    void setObs(char *);
    char * getObs();
    void setTelefono();
    int getTelefono();
    Fecha getFecha();
    void setFecha();
    void setIdVendedor();
    int getIdVendedor ();
    void setTipoCliente ();
    int getTipoCliente();
    void setSeguimiento();
    int getSeguimiento();
    void setIdProspecto();
    int getIdProspecto();
    void setVenta();
    bool getVenta();
    void mostrarProspecto();
    void cargarProspecto();
    void mostrarProspectoInd(int);
    bool guardarDisco(int = -1);
    bool leerDisco(int);
};

//FUNCIONES GLOBALES

void listarProspectos();//LISTA TODOS LOS PROSPECTOS UNO POR UNO DEL ARCHIVO
void nuevoProspecto();//CARGA UN NUEVO PROSPECTO/POSIBLE CLIENTE
int generarIdp();//GENERA ID CONSECUTIVO EN BASE A LA CANTIDAD DE REGISTROS EN EL ARCHIVO
bool mostrarSeguimiento(int);
int buscarIdProspecto(int);
Prospecto leerProspecto(int);

#endif // PROSPECTO_H_INCLUDED
