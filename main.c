#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include"alquileres.h"

#define ALQUILADO 1
#define FINALIZADO 0
#define CANT 100

int main()
{
    int opcion;
    eCliente cliente[CANT];
    eAlquiler alquiler[CANT];

    inicializador(cliente,alquiler,CANT);

    do
    {
        system("color 1F");
        system("cls");
        opcion=menu();

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\t\t\tALTA\n");
            printf("__________________________________________________________________________\n");
            alta(cliente,CANT);
            break;
        case 2:
            system("cls");
            printf("\t\t\tLISTAR CLIENTES\n");
            printf("__________________________________________________________________________\n");
            listar(cliente, CANT);
            break;
        case 3:
            system("cls");
            printf("\t\t\tMODIFICAR CLIENTE\n");
            printf("__________________________________________________________________________\n");
            modificar(cliente, CANT);
            break;
        case 4:
            system("cls");
            printf("\t\t\tBAJA DE CLIENTE\n");
            printf("____________________________________________________________\n");
            baja(cliente,CANT);
            break;
        case 5:
            system("cls");
            printf("\t\t\tNUEVO ALQUILER\n");
            printf("____________________________________________________________\n");
            break;
        case 6:
            system("cls");
            printf("\t\t\tFIN DE ALQUILER\n");
            printf("____________________________________________________________\n");
            break;
        case 7:
            system("cls");
            printf("\t\t\tINFORMAR\n");
            printf("____________________________________________________________\n");
            break;
        }
        printf("\n\n\n\n");
        system("pause");
    }
    while(opcion!=8);

    return 0;
}
