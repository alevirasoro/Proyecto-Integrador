#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


class Fecha{

protected:
    int dia;
    int mes;
    int anio;

public:
    Fecha (int = 1, int =1, int = 1999);
    void setDia();
    int getDia();
    void setMes();
    int getMes();
    void setAnio();
    int getAnio();
    void cargarFecha();
    void mostrarFecha();
};


#endif // FECHA_H_INCLUDED
