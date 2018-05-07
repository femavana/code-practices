#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include"alquileres.h"

#define ALQUILADO 1
#define FINALIZADO 0

int menu()
{
    int opcion;
    printf("_________________________________ALQUILERES_____________________________\n");
    printf("\n\t\t1|Alta cliente\n\t\t2|Listar clientes\n\t\t3|Modificar datos\n\t\t4|Baja del cliente\n\t\t5|Nuevo alquiler\n\t\t6|Fin de alquiler\n\t\t7|Informar\n\t\t8|Salir\n");
    printf("___________________________________________________________________________\n");
    printf("\n\n\tIngrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void subMenu()
{
    system("cls");
    printf("__________________________MODIFICAR_________________________\n");
    printf("\n\t\ta|Nombre del cliente\n\t\tb|Apellido del cliente\n\t\tc|Regresar menu principal\n");
    printf("_____________________________________________________________\n");
}

void inicializador(eCliente cliente[], int CANT)
{
    int i;//cliente
//int j;alquiler

    for(i=0; i<CANT; i++)
    {
        cliente[i].estado = 0;
    }
    /* for(j=0; j<CANT; j++)
     {
         alquiler[i].estado = 0;
     }*/
}

void espacioLibre(eCliente cliente[],int CANT)
{
    int i;
    char aux[9];

    printf("\n\t______________Verificando espacio______________");
    printf("\n\n\tIngrese DNI del cliente a cargar: ");
    fflush(stdin);
    gets(aux);
    for(i=0; i<CANT; i++)
    {
        if(strcmp(cliente[i].dni,aux)==0)
        {
            printf("\n\tEl cliente ya fue cargado\n\n");
            printf("\n\n\t\t__|NOMBRE|____|APELLIDO|____|DNI|_\n");
            printf("\t\t_|%s|____|%s|____|%s|_\n\n",cliente[i].nombre,cliente[i].apellido,cliente[i].dni);
            break;
        }
        else
        {
            printf("\n\tHay espacio\n");
        }
        if(i == CANT)
        {
            printf("\n\n\tNo hay espacio libre\n");
        }
        break;
    }
}

void alta(eCliente cliente[], int CANT)
{
    int i;
    char seguir;

    espacioLibre(cliente,CANT);
    getche();
    printf("\n\tContinuar con el alta?(s/n): ");
    fflush(stdin);
    scanf("%c", &seguir);

    if(seguir == 's')
    {
        for(i=0; i<CANT; i++)
        {
            if(cliente[i].estado == 0)
            {
                printf("\n\tIngrese DNI de cliente: ");
                fflush(stdin);
                gets(cliente[i].dni);

                printf("\n\tIngrese nombre: ");
                fflush(stdin);
                gets(cliente[i].nombre);

                printf("\n\tIngrese apellido: ");
                gets(cliente[i].apellido);

                cliente[i].estado = 1;
                break;
            }
        }
    }
    else
    {
        printf("\n\tSe cancela eliminacion\n");
    }
}

void baja(eCliente cliente[], int CANT)
{
    int i;
    char seguir;
    char aux[9];
    int dni;

    dni=verificaDNI(cliente,CANT);
    if(dni ==1)
    {
        printf("\n\tSeguro desea eliminar al cliente?(s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 's')
        {
            system("cls");
            printf("\t\t\tBAJA DE CLIENTE\n");
            printf("____________________________________________________________\n");

            printf("\n\n\tIngrese DNI del cliente a eliminar: ");
            fflush(stdin);
            gets(aux);

            for(i=0; i<CANT; i++)
            {
                if(cliente[i].estado == 1 && strcmp(cliente[i].dni,aux)==0)
                {
                    cliente[i].estado = 0;
                    printf("\n\tEl cliente fue eliminado\n");
                }
            }
        }
        else
        {
            printf("\n\tSe cancela eliminacion\n");
        }
    }
}

void listar(eCliente cliente[], int CANT)
{
    int i;

    for(i=0; i<CANT; i++)
    {
        if(cliente[i].estado == 1)
        {
            printf("\n\n\t\t__|NOMBRE|____|APELLIDO|____|DNI|_\n");
            printf("\t\t_|%s|____|%s|____|%s|_\n\n",cliente[i].nombre,cliente[i].apellido,cliente[i].dni);
        }
    }
}

void modificar(eCliente cliente[], int CANT)
{
    int i;
    char opcion;
    char aux[9];
    char seguir;
    int dni;

    dni=verificaDNI(cliente,CANT);

    if(dni ==1)
    {
        printf("\n\tContinuar con la modificacion?(s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 's')
        {
            system("cls");
            subMenu();
            printf("\n\n\tIngrese DNI del cliente a modificar: ");
            fflush(stdin);
            gets(aux);
            printf("\n\n\tIngrese una opcion: ");
            scanf("%c", &opcion);

            for(i=0; i<CANT; i++)
            {
                if(cliente[i].estado == 1 && strcmp(cliente[i].dni,aux)==0)
                {
                    switch(opcion)
                    {
                    case 'a':
                        printf("\n\tIngrese nuevo nombre: ");
                        fflush(stdin);
                        gets(cliente[i].nombre);
                        break;
                    case 'b':
                        printf("\n\tIngrese nuevo apellido: ");
                        fflush(stdin);
                        gets(cliente[i].apellido);
                        break;
                    case 'c':
                        break;
                    }
                }
            }
        }
        else
        {
            printf("\n\tSe cancela la modificacion");
        }
    }
}



int verificaDNI(eCliente cliente[], int CANT)
{
    int i;
    char aux[9];
    int dni=0;

    printf("\n\t______________Verificando Cliente______________");
    printf("\n\n\tIngrese DNI del cliente: ");
    fflush(stdin);
    gets(aux);

    for(i=0; i<CANT; i++)
    {
        if(cliente[i].estado == 1 && strcmp(cliente[i].dni,aux)==0)
        {
            printf("\n\n\t\t__|NOMBRE|____|APELLIDO|____|DNI|_\n");
            printf("\t\t_|%s|____|%s|____|%s|_\n\n",cliente[i].nombre,cliente[i].apellido,cliente[i].dni);
            dni=1;
        }
        else
        {
            printf("\n\t\tEl DNI ingresado no existe");
        }
        break;
    }
    return dni;
}















/*
void inicializador(eAlquiler alquiler[],int CANT)
{
    int i;
    for(i=0; i<CANT; i++)
    {
        alquiler[i].estado = FINALIZADO;
    }
}



void Alta
{


}

Baja

Modificar

Nueva llamada

Fin de llamada

Informar
*/
