#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include "fecha.h"
#include "persona.h"

class Vendedor:public Persona{

private:
    char nombres[50];
    char apellidos[50];
    int id;
    int comision;

public:
    void setNombres(char *);
    char * getNombres();
    void setApellidos(char *);
    char * getApellidos();
    void setId();
    void setCom();
    int getId();
    int getCom();
    void mostrarV();
    void cargarV();
    void mostrarVendedorInd(int);
    bool guardarDisco(int = -1);
    bool leerDisco(int );
    bool modificarDisco(int);
};

//FUNCIONES GLOBALES DE VENDEDORES

void cargarVendedor();
int buscarVendedor(int);
void mostrarVendedores();
bool modificarVendedor();
int generarId();
Vendedor leerVendedor(int);


#endif // VENDEDOR_H_INCLUDED
