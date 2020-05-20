#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "ac_getFunciones.h"
#include "moto.h"
#include "funciones_adicionales.h"


void inicializarMotos (e_Moto vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}


void inicializarClientes (e_Cliente vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}


void listarTiposDeMotos (e_tipoDeMoto tipos[],int size)
{
    printf("*TIPOS DE MOTO*\n");
    for (int i = 0; i<size; i++)
    {
        printf("%d- %s\n",i+1,tipos[i].descripcion);
    }
}

void listarColoresDeMotos(e_Color colores[],int size)
{
    printf("*COLORES DE MOTO*\n");
    for (int i = 0; i<size; i++)
    {
        printf("%d- %s\n",i+1,colores[i].nombreColor);
    }
}



void mostrarCilindradas ()
{
    printf("CILINDRADA: \n");
    printf("1- 50 \n");
    printf("2- 125 \n");
    printf("3- 500 \n");
    printf("4- 600 \n");
    printf("5- 750 \n");
}

int getEmptySlotMoto (e_Moto vec[],int size)
{
    int lugar = -1;
    int flag = 0;
    for (int i = 0; i<size && flag == 0; i++)
    {
        if (vec[i].isFull == 0)
        {
            lugar = i;
            flag = 1;
        }
    }
    return lugar;
}


int getMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores)
{
    system("cls");
    int i = getEmptySlotMoto(vec,size);
    int todoBien = 0;
    int aux;
    int auxTipo;
    int auxColor;
    int auxCilindrada;

    if (i != -1)
    {
        printf("****ALTA DE MOTO****\n");
        do
        {
            if (ac_getInt(&aux,100000,999999,"Ingese ID de moto: (xxxxxx)",3)== -1)
            {
                break;
            }
            else if (buscarMoto(aux,vec,size)== -1)
            {
                vec[i].id = aux;
                if (ac_getString(vec[i].marca,20,5,"Ingrese marca de la moto: ") == -1)
                {
                    break;
                }
                normalizeString( vec[i].marca);
                listarTiposDeMotos(tipos,sizeTipos);
                if (ac_getInt(&auxTipo,1,sizeTipos,"Ingrese tipo de moto: ",3)==-1)
                {
                    break;
                }
                vec[i].idTipo = auxTipo+999;
                listarColoresDeMotos(colores,sizeColores);
                if (ac_getInt(&auxColor,1,sizeColores,"Ingrese color de la moto",3) == -1)
                {
                    break;
                }
                vec[i].idColor = auxColor+9999;
                mostrarCilindradas();
                if (ac_getInt(&auxCilindrada,1,5,"Ingrese tipo de cilindrada: ",3)==-1)
                {
                    break;
                }
                switch (auxCilindrada)
                {
                case 1:
                    vec[i].cilindrada = 50;
                    break;
                case 2:
                    vec[i].cilindrada = 125;
                    break;
                case 3:
                    vec[i].cilindrada = 500;
                    break;
                case 4:
                    vec[i].cilindrada = 600;
                    break;
                case 5:
                    vec[i].cilindrada = 750;
                    break;
                }
            }
            else
            {
                printf("El ID que ha ingresado ya corresponde a una moto en el sistema.\n");
                system("pause");
                break;
            }
            vec[i].isFull = 1;
            printf("\nAlta de moto realizada con exito. \n");
            todoBien = 1;
            system("pause");
        }
        while (todoBien == 0);
    }
    else
    {
        printf("No hay lugar disponible.\n");
        system("pause");
    }
    return todoBien;
}


void modificarMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores,e_Cliente clientes[],int sizeClientes)
{
    int aux;
    int indiceMotoBaja;
    int opcion = 5;
    int auxTipo;
    int auxColor;
    int auxCilindrada;
    system("cls");
    printf("****MODIFICACION DE MOTO****\n");
    ac_getInt(&aux,0,999999,"Ingrese ID de moto a modificar (xxxxxx)",5);
    indiceMotoBaja = buscarMoto(aux,vec,size);
    if ( indiceMotoBaja == -1)
    {
        printf("La moto que desea modificar no existe.\n");
        system("pause");
    }
    else
    {
        do
        {
            system("cls");
            printf("Datos de la moto\n");
            mostrarPrimerMoto(vec[indiceMotoBaja],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            printf("\nDato a modificar:\n");
            printf("1-Marca\n");
            printf("2-Tipo\n");
            printf("3-Color\n");
            printf("4-Cilindrada\n");
            printf("5-Volver a menu principal\n");
            ac_getInt(&opcion,1,5,"\nIngrese opcion: ",3);

            switch (opcion)
            {
            case 1:
                if (ac_getString(vec[indiceMotoBaja].marca,20,3,"\nIngrese nueva marca de la moto: ") == -1)
                {
                    break;
                }
                normalizeString( vec[indiceMotoBaja].marca);
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 2:
                listarTiposDeMotos(tipos,sizeTipos);
                if (ac_getInt(&auxTipo,1,sizeTipos,"\nIngrese nuevo tipo de moto: ",3)==-1)
                {
                    break;
                }
                vec[indiceMotoBaja].idTipo = auxTipo+999;
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            case 3:
                listarColoresDeMotos(colores,sizeColores);
                if (ac_getInt(&auxColor,1,sizeColores,"\nIngrese nuevo color de moto: ",3) == -1)
                {
                    break;
                }
                vec[indiceMotoBaja].idColor = auxColor+9999;
                printf("\nModificacion realizada con exito\n");
                break;
            case 4:
                mostrarCilindradas();
                if (ac_getInt(&auxCilindrada,1,5,"\nIngrese nuevo tipo de cilindrada: ",3)==-1)
                {
                    break;
                }
                switch (auxCilindrada)
                {
                case 1:
                    vec[indiceMotoBaja].cilindrada = 50;
                    break;
                case 2:
                    vec[indiceMotoBaja].cilindrada = 125;
                    break;
                case 3:
                    vec[indiceMotoBaja].cilindrada = 500;
                    break;
                case 4:
                    vec[indiceMotoBaja].cilindrada = 600;
                    break;
                case 5:
                    vec[indiceMotoBaja].cilindrada = 750;
                    break;
                }
                printf("\nModificacion realizada con exito\n");
                system("pause");
                break;
            }
        }
        while (opcion != 5);
    }
}

int buscarMoto (int id,e_Moto vec[],int size)
{
    int lugar = -1;
    for (int i= 0; i<size; i++)
    {
        if (vec[i].id == id && vec[i].isFull == 1)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}


int buscarCliente (int id,e_Cliente vec[],int size)
{
    int lugar = -1;
    for (int i= 0; i<size; i++)
    {
        if (vec[i].id == id && vec[i].isFull == 1)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void mostrarClientes(e_Cliente clientes[], int size)
{

    int flag = 0;

    printf("****CLIENTES****\n");
    printf("      NOMBRE COMPLETO       SEXO       ID\n");

    for (int i = 0; i<size; i++)
    {
        if (clientes[i].isFull == 1)
        {
            flag = 1;
            printf("%20s          %c        %8d\n",clientes[i].nombre,clientes[i].sexo,clientes[i].id);
        }
    }

    if (flag == 0)
    {
        printf("No hay clientes que mostrar\n");
    }
}

void mostrarMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int indice = buscarCliente(moto.idCliente,clientes,sizeClientes);
    printf("%6d  %20s        %10s      %10s     %4d            %20s\n",moto.id,moto.marca,tipos[moto.idTipo-1000].descripcion,colores[moto.idColor-10000].nombreColor,moto.cilindrada,clientes[indice].nombre);
}
void mostrarPrimerMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int indice = buscarCliente(moto.idCliente,clientes,sizeClientes);
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");
    printf("%6d  %20s        %10s      %10s     %4d            %20s\n",moto.id,moto.marca,tipos[moto.idTipo-1000].descripcion,colores[moto.idColor-10000].nombreColor,moto.cilindrada,clientes[indice].nombre);
}


void mostrarMotos(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int flag = 0;

    printf("****LISTA DE MOTOS****\n\n");
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1)
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
        }
    }

    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
}

void eliminarMoto (e_Moto vec[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int aux;
    int indiceMotoBaja;
    char confirmar;
    system("cls");
    printf("****BAJA DE MOTO****\n");
    ac_getInt(&aux,000000,999999,"Ingrese ID de moto a dar de baja (xxxxxx)",5);
    indiceMotoBaja = buscarMoto(aux,vec,size);
    if ( indiceMotoBaja == -1)
    {
        printf("La moto que desea dar de baja no existe.\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("Datos de la moto\n");
        mostrarPrimerMoto(vec[indiceMotoBaja],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
        printf("\nSeguro que desea continuar? Se perderan todos los datos. (y/n)\n");
        fflush(stdin);
        scanf("%c",&confirmar);
        if (confirmar == 'y')
        {
            vec[indiceMotoBaja].isFull = 0;
            printf("\nBaja de moto realizada con exito. \n");
            system("pause");
        }
        else
        {
            printf("\nBaja cancelada\n");
            system("pause");
        }
    }

}

int hayMotos (e_Moto motos[],int size)
{
    int hay = 0;
    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1)
        {
            hay++;
        }
    }
    return hay;
}

int listarMotosSegunColor(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int flag = 0;
    int color;
    int contador = 0;
    listarColoresDeMotos(colores,sizeColores);
    ac_getInt(&color,1,5,"Ingrese color de motos a listar: ",3);
    printf("****LISTA DE MOTOS****\n\n");
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1 && motos[i].idColor - 9999 == color)
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            contador++;
        }
    }

    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
    return contador;
}


int listarMotosSegunTipo(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int flag = 0;
    int tipo;
    int contador = 0;
    listarTiposDeMotos(tipos,sizeTipos);
    ac_getInt(&tipo,1,4,"Ingrese tipo de motos a listar: ",3);
    printf("****LISTA DE MOTOS****\n\n");
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1 && motos[i].idTipo - 999 == tipo)
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            contador++;
        }
    }

    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
    return contador;
}


void ordenarMotosTipo (e_Moto motos [],int size)
{
    e_Moto aux;

    for (int i = 0; i<size-1 ; i++)
    {
        for (int j = i+1; j<size; j++ )
        {
            if (motos[i].idTipo > motos[j].idTipo)
            {
                aux = motos[i];
                motos[i] = motos[j];
                motos[j] = aux;
            }
        }
    }
}

void mostrarMotosDeTipo(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes,int idTipo) // va del 1000 al 1003
{
    int flag = 0;

    printf("****LISTA DE MOTOS DE TIPO %s****\n\n",tipos[idTipo-1000].descripcion);
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1 && motos[i].idTipo == idTipo)
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
        }
    }
    printf("\n\n");
    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
}

int listarMotosMayorCilindrada(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[], int sizeClientes)
{
    int flag = 0;
    int contador = 0;
    int cilindradaMax = 50;

    for (int h = 0; h< size; h++)
    {
        if (motos[h].cilindrada > cilindradaMax && motos[h].isFull == 1)
        {
            cilindradaMax = motos[h].cilindrada;
        }
    }
    printf("%d",cilindradaMax);

    printf("****LISTA DE MOTOS DE MAYOR CILINDRADA****\n\n");
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1 && motos[i].cilindrada == cilindradaMax )
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            contador++;
        }
    }

    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
    return contador;
}

int mostrarMotosDeTipoYColor(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes,int idTipo, int idColor) // tipo va del 1.000 al 1.003 // color va del  10.000 al 10.004
{
    int contador = 0;
    int flag = 0;

    printf("****LISTA DE MOTOS DE TIPO %s Y COLOR %s****\n\n",tipos[idTipo-1000].descripcion,colores[idColor-10000].nombreColor);
    printf("ID                     MARCA              TIPO            COLOR     CILINDRADA         NOMBRE DEL CLIENTE\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1 && motos[i].idTipo == idTipo && motos[i].idColor == idColor)
        {
            flag = 1;
            mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            contador++;
        }
    }
    printf("\n\n");
    if (flag == 0)
    {
        printf("No hay motos que mostrar\n");
    }
    return contador;
}

void coloresMasUsados (e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes)
{
    int contador [5] = {0,0,0,0,0};
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        if (motos[i].idColor == 10000 && motos[i].isFull == 1)
        {
            contador[0]++;
        }
        if (motos[i].idColor == 10001 && motos[i].isFull == 1)
        {
            contador[1]++;
        }
        if (motos[i].idColor == 10002 && motos[i].isFull == 1)
        {
            contador[2]++;
        }
        if (motos[i].idColor == 10003 && motos[i].isFull == 1)
        {
            contador[3]++;
        }
        if (motos[i].idColor == 10004 && motos[i].isFull == 1)
        {
            contador[4]++;
        }
    }
    for (int i = 0; i < 5 ; i++)
    {
        if (contador[i]>max)
        {
            max = contador[i];
        }
    }
    printf("****COLORES MAS POPULARES****\n\n");
    for (int i = 0; i <5; i++)
    {
        if (contador[i] == max)
        {
            printf("COLOR: %s    ,  CANTIDAD DE MOTOS:  %d\n",colores[i].nombreColor,contador[i]);
        }
    }
}
