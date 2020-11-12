#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{

    private:
        char nombres [50];
        char apellidos [50];

    public:
        void setNombres(char *);
        char * getNombres();
        void setApellidos(char *);
        char * getApellidos();
        void cargarPersona();
        void mostrarPersona();
};


#endif // PERSONA_H_INCLUDED
