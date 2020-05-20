#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "moto.h"
#include "trabajo.h"

void listarServiciosDeMotos (e_Servicio servicios[],int size)
{
    printf("*SERVICIOS*\n");
    for (int i = 0; i<size; i++)
    {
        printf("%d- %s ($%d)\n",i+1,servicios[i].descripcion,servicios[i].precio);
    }
}

void inicializarTrabajos (e_Trabajo vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}



int getEmptySlotTrabajo (e_Trabajo vec[],int size)
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


int getTrabajo (e_Trabajo trabajos[],int sizeT,int idOrigen,e_Servicio servicios[],int sizeServicios,e_Moto vec[],int sizeM,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores,e_Cliente clientes[],int sizeClientes)
{
    system("cls");
    int i = getEmptySlotTrabajo(trabajos,sizeT);
    int todoBien = 0;
    int auxIdMoto;
    int auxIdServicio;
    e_fecha aux;

    if (i != -1)
    {
        printf("****NUEVO TRABAJO****\n\n");
        do
        {
            mostrarMotos(vec,sizeM,colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
            printf("\n\n");
            if (ac_getInt(&auxIdMoto,0,999999,"Ingese ID de moto: (xxxxxx): ",3)== -1)
            {
                break;
            }
            else if (buscarMoto(auxIdMoto,vec,sizeM)>=0)
            {
                trabajos[i].idMoto = auxIdMoto;
                system("cls");
                mostrarPrimerMoto(vec[(buscarMoto(auxIdMoto,vec,sizeM))],colores,sizeColores,tipos,sizeTipos,clientes,sizeClientes);
                printf("\n\n");
                listarServiciosDeMotos(servicios,sizeServicios);
                printf("\n\n");
                if (ac_getInt(&auxIdServicio,1,4,"Ingrese servicio a realizar: ",3) == -1)
                {
                    break;
                }
                trabajos[i].idServicio = auxIdServicio + 19999;
                printf("\n\n");
                if (ac_getDate(&aux.day,&aux.month,&aux.year,"Ingrese fecha de realizacion del trabajo: ",1950,2020,3)==-1)
                {
                    break;
                }
                trabajos[i].fechaDeTrabajo = aux;
            }
            else
            {
                printf("El ID que ha ingresado no corresponde a una moto en el sistema.\n");
                system("pause");
                break;
            }
            trabajos[i].isFull = 1;
            trabajos[i].id = idOrigen;
            printf("\nAlta de trabajo realizada con exito. \n");
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

void mostrarTrabajo (e_Trabajo trabajo, e_Servicio servicios[],int sizeServicios)
{

    printf("%4d             %6d        %15s ($%4d )              %2d/%2d/%2d \n",trabajo.id,trabajo.idMoto,servicios[trabajo.idServicio-20000].descripcion,servicios[trabajo.idServicio-20000].precio,trabajo.fechaDeTrabajo.day,trabajo.fechaDeTrabajo.month,trabajo.fechaDeTrabajo.year);
}
void mostrarPrimerTrabajo (e_Trabajo trabajo, e_Servicio servicios[],int sizeServicios)
{

    printf(" ID              ID-MOTO             SERVICIO (PRECIO)          FECHA DEL TRABAJO\n");
    printf("%4d             %6d        %15s ($%4d)               %2d/%2d/%2d \n",trabajo.id,trabajo.idMoto,servicios[trabajo.idServicio-20000].descripcion,servicios[trabajo.idServicio-20000].precio,trabajo.fechaDeTrabajo.day,trabajo.fechaDeTrabajo.month,trabajo.fechaDeTrabajo.year);
}


void mostrarTrabajos(e_Trabajo trabajos[],int size, e_Servicio servicios[],int sizeServicios)
{
    int flag = 0;

    printf("****LISTADO DE TRABAJOS****\n\n");
    printf(" ID              ID-MOTO             SERVICIO (PRECIO)          FECHA DEL TRABAJO\n");

    for (int i = 0; i<size; i++)
    {
        if (trabajos[i].isFull == 1)
        {
            flag = 1;
            mostrarTrabajo(trabajos[i],servicios,sizeServicios);
        }
    }

    if (flag == 0)
    {
        printf("No hay trabajos que mostrar\n");
    }
    system("pause");
}

int buscarTrabajo (int id,e_Trabajo vec[],int size)
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

void ordenarTrabajosFecha (e_Trabajo trabajos[],int size)
{
    e_Trabajo aux;

    for (int i = 0; i<size-1 ; i++)
    {
        for (int j = i+1; j<size; j++ )
        {
            if (trabajos[i].fechaDeTrabajo.year > trabajos[j].fechaDeTrabajo.year)
            {
                aux = trabajos[i];
                trabajos[i] = trabajos[j];
                trabajos[j] = aux;
            }
            else if (trabajos[i].fechaDeTrabajo.year == trabajos[j].fechaDeTrabajo.year && trabajos[i].fechaDeTrabajo.month > trabajos[j].fechaDeTrabajo.month)
            {
                aux = trabajos[i];
                trabajos[i] = trabajos[j];
                trabajos[j] = aux;
            }
            else if (trabajos[i].fechaDeTrabajo.year == trabajos[j].fechaDeTrabajo.year && trabajos[i].fechaDeTrabajo.month == trabajos[j].fechaDeTrabajo.month && trabajos[i].fechaDeTrabajo.day > trabajos[j].fechaDeTrabajo.day)
            {
                aux = trabajos[i];
                trabajos[i] = trabajos[j];
                trabajos[j] = aux;
            }
        }
    }
}

int listarTrabajosSegunMoto (e_Trabajo trabajos[],int sizeT,e_Moto motos[],int sizeM,e_Servicio servicios[],int sizeServicios)
{
    int flag = 0;
    int idMoto;
    int contador  = 0;
    ac_getInt(&idMoto,0,999999,"Ingrese ID de moto cuyos trabajos quiera mostrar: ",3);
    if (buscarMoto(idMoto,motos,sizeM)>=0)
    {
        printf("****LISTADO DE TRABAJOS****\n\n");
        printf(" ID              ID-MOTO             SERVICIO (PRECIO)          FECHA DEL TRABAJO\n");
        ordenarTrabajosFecha(trabajos,sizeT);
        for (int i = 0; i<sizeT; i++)
        {
            if (trabajos[i].isFull == 1 && trabajos[i].idMoto == idMoto)
            {
                flag = 1;
                mostrarTrabajo(trabajos[i],servicios,sizeServicios);
                contador++;
            }
        }

        if (flag == 0)
        {
            printf("No hay trabajos que mostrar\n");
            system("pause");
        }
    }
    else
    {
        printf("El ID de moto ingresado no corresponde a una moto en el sistema.\n");
        system("pause");
    }

    return contador;
}

int totalServiciosPorMoto (e_Trabajo trabajos[],int sizeT,e_Moto motos[],int sizeM,e_Servicio servicios[],int sizeServicios)
{
    int total = 0;
    int idMoto;
    int flag = 0;
    ac_getInt(&idMoto,0,999999,"Ingrese ID de moto cuyo importe total quiera mostrar: ",3);
    if (buscarMoto(idMoto,motos,sizeM)>=0)
    {
        for (int i = 0; i<sizeT ; i++)
        {
            if (trabajos[i].isFull == 1 && trabajos[i].idMoto == idMoto)
            {
                total += servicios[trabajos[i].idServicio-20000].precio;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Esta moto no tuvo servicios realizados\n");
            system("pause");
        }
    }
    else
    {
        printf("El ID de moto ingresado no corresponde a una moto en el sistema.\n");
        system("pause");
    }

    return total;
}

int listarTrabajosSegunServicio (e_Trabajo trabajos[],int sizeT,e_Servicio servicios[],int sizeServicios)
{
    int flag = 0;
    int idServicio;
    int contador  = 0;
    listarServiciosDeMotos(servicios,sizeServicios);
    if (ac_getInt(&idServicio,1,4,"Ingrese clase de servicio cuyos trabajos quiera mostrar: ",3)>0)
    {
        system("cls");
        printf("****LISTADO DE TRABAJOS DE %s****\n\n",servicios[idServicio-1].descripcion);
        printf(" ID              ID-MOTO             SERVICIO (PRECIO)          FECHA DEL TRABAJO\n");
        ordenarTrabajosFecha(trabajos,sizeT);
        for (int i = 0; i<sizeT; i++)
        {
            if (trabajos[i].isFull == 1 && trabajos[i].idServicio == idServicio + 19999)
            {
                flag = 1;
                mostrarTrabajo(trabajos[i],servicios,sizeServicios);
                contador++;
            }
        }

        if (flag == 0)
        {
            printf("No hay trabajos que mostrar\n");
            system("pause");
        }
    }
    else
    {
        printf("El servicio ingresado no corresponde a un tipo de servicio en el sistema.\n");
        system("pause");
    }

    return contador;
}


int listarTrabajosSegunFecha (e_Trabajo trabajos[],int sizeT,e_Servicio servicios[],int sizeServicios)
{
    int flag = 0;
    int year;
    int month;
    int day;
    int contador  = 0;
    if (ac_getDate(&day,&month,&year,"Ingrese fecha de realizacion cuyos trabajos quiera mostrar(dd/mm/aaaa): ",1900,2020,3)>0)
    {
        system("cls");
        printf("****LISTADO DE TRABAJOS DEL DIA %2d/%2d/%4d****\n\n",day,month,year);
        printf(" ID              ID-MOTO             SERVICIO (PRECIO)          FECHA DEL TRABAJO\n");
        for (int i = 0; i<sizeT; i++)
        {
            if (trabajos[i].isFull == 1 && trabajos[i].fechaDeTrabajo.year == year && trabajos[i].fechaDeTrabajo.month == month && trabajos[i].fechaDeTrabajo.day == day)
            {
                flag = 1;
                mostrarTrabajo(trabajos[i],servicios,sizeServicios);
                contador++;
            }
        }

        if (flag == 0)
        {
            printf("No se realizaron trabajos en esa fecha\n");
        }
    }
    else
    {
        printf("La fecha ingresada no es valida. \n");

    }

    return contador;
}



