#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "menus.h"
#include "moto.h"
#include "trabajo.h"
#include "funciones_adicionales.h"
#include "ac_dataStorage.h"

#define TAMTRABAJOS 20
#define TAMMOTOS 30
#define TAMSERVICIOS 4
#define TAMCOLORES 5
#define TAMTIPOS 4
#define CANT_HARDCODE 10
#define TAMCLIENTES 30


void hardcodearMotos (e_Moto vec[],int size);
void hardcodearTrabajos (e_Trabajo vec[],int size);
void hardcodearClientes(e_Cliente vec[],int size);


int main()
{
    char opcion;
    int idOrigenTrabajo = 100;
    int opcionInformes = 11;
    int tipoUsuario;
    int colorUsuario;
    int total;

    e_Moto motos[TAMMOTOS];
    e_Trabajo trabajos[TAMTRABAJOS];
    e_Cliente clientes[TAMCLIENTES];
    e_Servicio servicios [TAMSERVICIOS] = {{20000,"Ajuste",300}, {20001,"Balanceo",17}, {20002,"Cadena",190},{20003,"Limpieza",250}};
    e_Color colores[TAMCOLORES] = {{10000,"Azul"},{10001,"Blanco"},{10002,"Gris"},{10003,"Negro"},{10004,"Rojo"}};
    e_tipoDeMoto tiposDeMoto[TAMTIPOS] = {{1000,"Chopera"},{1001,"Ciclomotor"},{1002,"Enduro"},{1003,"Scooter"}};

    inicializarMotos(motos,TAMMOTOS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);
    inicializarClientes(clientes,TAMCLIENTES);
    hardcodearMotos(motos,CANT_HARDCODE);
    hardcodearTrabajos(trabajos,CANT_HARDCODE);
    hardcodearClientes(clientes,CANT_HARDCODE);

    idOrigenTrabajo += CANT_HARDCODE;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 'a':
            getMoto(motos,TAMMOTOS,tiposDeMoto,TAMTIPOS,colores,TAMCOLORES);
            break;
        case 'b':
            if (hayMotos(motos,TAMMOTOS)>0)
            {
                modificarMoto(motos,TAMMOTOS,tiposDeMoto,TAMTIPOS,colores,TAMCOLORES,clientes,TAMCLIENTES);
            }
            else
            {
                printf("\nNo hay motos cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'c':
            if (hayMotos(motos,TAMMOTOS)>0)
            {
                eliminarMoto(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
            }
            else
            {
                printf("\nNo hay motos cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'd':
            if (hayMotos(motos,TAMMOTOS)>0)
            {
                mostrarMotos(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
                system("pause");
            }
            else
            {
                printf("\nNo hay motos cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'e':
            system("cls");
            listarTiposDeMotos(tiposDeMoto,TAMTIPOS);
            system("pause");
            break;
        case 'f':
            system("cls");
            listarColoresDeMotos(colores,TAMCOLORES);
            system("pause");
            break;
        case 'g':
            system("cls");
            listarServiciosDeMotos(servicios,TAMSERVICIOS);
            system("pause");
            break;
        case 'h':
            if (hayMotos(motos,TAMMOTOS)>0)
            {
                idOrigenTrabajo += getTrabajo(trabajos,TAMTRABAJOS,idOrigenTrabajo,servicios,TAMSERVICIOS,motos,TAMMOTOS,tiposDeMoto,TAMTIPOS,colores,TAMCOLORES,clientes,TAMCLIENTES);
            }
            else
            {
                printf("\nNo hay motos cargadas en el sistema. \n");
                system("pause");
            }
            break;
        case 'i':
            mostrarTrabajos(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);
            break;
        case 'j':
            if (hayMotos(motos,TAMMOTOS)>0)
            {
                do
                {
                    opcionInformes = menuInformes();
                    switch(opcionInformes)
                    {
                    case 1:
                        system("cls");
                        listarMotosSegunColor(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
                        break;
                    case 2:
                        system("cls");
                        listarMotosSegunTipo(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
                        break;
                    case 3:
                        system("cls");
                        listarMotosMayorCilindrada(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
                        break;
                    case 4:
                        system("cls");
                        mostrarMotosDeTipo(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES,1000);
                        mostrarMotosDeTipo(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES,1001);
                        mostrarMotosDeTipo(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES,1002);
                        mostrarMotosDeTipo(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES,1003);
                        break;
                    case 5:
                        listarTiposDeMotos(tiposDeMoto,TAMTIPOS);
                        if (ac_getInt(&tipoUsuario,1,4,"Ingrese tipo de las motos que quiera mostrar: ",3)== -1)
                        {
                            break;
                        }
                        listarColoresDeMotos(colores,TAMCOLORES);
                        if (ac_getInt(&colorUsuario,1,5,"Ingrese color de las motos que quiera mostrar: ",3)== -1)
                        {
                            break;
                        }
                        system("cls");
                        printf("CANTIDAD DE MOTOS DE TIPO Y COLOR PEDIDOS: %d \n\n",mostrarMotosDeTipoYColor(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES,tipoUsuario+999,colorUsuario+9999));
                        break;
                    case 6:
                        system("cls");
                        coloresMasUsados(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS,clientes,TAMCLIENTES);
                        break;
                    case 7:
                        system("cls");
                        listarTrabajosSegunMoto(trabajos,TAMTRABAJOS,motos,TAMMOTOS,servicios,TAMSERVICIOS);
                        break;
                    case 8:
                        system("cls");
                        total = totalServiciosPorMoto(trabajos,TAMTRABAJOS,motos,TAMMOTOS,servicios,TAMSERVICIOS);
                        if (total >0)
                        {
                            printf("El importe total por servicios realizados a la moto es de: $ %d\n",total);
                        }
                        break;
                    case 9:
                        system("cls");
                        listarTrabajosSegunServicio(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);
                        break;
                    case 10:
                        system("cls");
                        listarTrabajosSegunFecha(trabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);
                        break;
                    }
                    if (opcionInformes != 11)
                    {
                        system("pause");
                    }
                }
                while (opcionInformes != 11);
            }
            else
            {
                printf("\nNo hay motos cargadas en el sistema. \n");
                system("pause");
            }
            break;
        }
    }
    while (opcion != 'k');

    return 0;
}

void hardcodearTrabajos (e_Trabajo vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].id = idsTrabajo[i];
        vec[i].idServicio = idsServicio[i];
        vec[i].idMoto = rand()%CANT_HARDCODE + 100000;
        vec[i].isFull = 1;
        vec[i].fechaDeTrabajo.day = days[i];
        vec[i].fechaDeTrabajo.month = months[i];
        vec[i].fechaDeTrabajo.year = years[i];
    }
}

void hardcodearMotos (e_Moto vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].id = idsMoto[i];
        strcpy(vec[i].marca,marcasMoto[i]);
        vec[i].cilindrada = cilindradas[i];
        vec[i].idTipo = rand()%4 + 1000;
        vec[i].idColor = rand()%5 + 10000;
        vec[i].isFull = 1;
        vec[i].idCliente = idsCliente[i];
    }
}
void hardcodearClientes(e_Cliente vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].id = idsCliente[i];
        strcpy(vec[i].nombre, nombresCompletos[i]);
        vec[i].sexo = sexos[i];
        vec[i].isFull = 1;
    }
}


