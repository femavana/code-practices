#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int idCliente;
    char dni[9];
    char nombre[20];
    char apellido[20];
    int estado;
    int motivo;
}eCliente;

typedef struct
{
    int idCliente;
    int idAlquiler;
    char operador[20];
    int tiempoEstimado;
    int tiempoReal;
    int estado;
}eAlquiler;

typedef struct
{
    int idCliente;
    int idAlquiler;
    int estado;
}eClienteAlquiler;

/** \brief  Muestra el menu principal.
 * \return devuelve la opcion elegida por el usuario.
 */
int menu();
void subMenu();

void inicializador(eCliente cliente[], int CANT);

void espacioLibre(eCliente cliente[],int CANT);

int verificaDNI(eCliente cliente[], int CANT)

void alta(eCliente cliente[], int CANT);

void listar(eCliente cliente[], int CANT);

void baja(eCliente cliente[], int CANT);

void modificar(eCliente cliente[], int CANT);


/*
;

void validCode();
void validChar();
void validInt();
*/


#endif //ALQUILERES_H_INCLUDED
