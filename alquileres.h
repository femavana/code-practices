#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int idCliente;
    char dni[9];
    char nombre[20];
    char apellido[20];
    int estado;
}eCliente;

typedef struct
{
    int idCliente;
    char operador[20];
    int tiempoEstimado;
    int tiempoReal;
    int motivo;
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

/** \brief  Muestra el aubmenu.
 * \return ho devuelve nada.
 */
void subMenu();

/** \brief  Inicializa todos elementos del cliente en 0 y los del array alquiler en finalizado
 * \return ho devuelve nada.
 */
void inicializador(eCliente cliente[], eAlquiler alquiler[], int CANT);



int espacioLibre(eCliente cliente[],int CANT);

int verificaDNI(eCliente cliente[], int CANT);

void alta(eCliente cliente[], int CANT);

void listar(eCliente cliente[], int CANT);

void baja(eCliente cliente[], int CANT);

void modificar(eCliente cliente[], int CANT);


void validCode();
void validChar();
void validInt();



#endif //ALQUILERES_H_INCLUDED
