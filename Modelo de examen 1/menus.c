#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "menus.h"
#include "moto.h"
#include "trabajo.h"

char menu()
{
    char opcion;
    system("cls");
    printf("****MENU DE OPCIONES****\n\n");
    printf("A- NUEVA ALTA DE MOTO \n");
    printf("B- MODIFICAR MOTO \n");
    printf("C- BAJA DE MOTO \n");
    printf("D- LISTAR MOTOS \n");
    printf("E- LISTAR TIPOS DE MOTOS \n");
    printf("F- LISTAR COLORES DE MOTOS \n");
    printf("G- LISTAR SERVICIOS \n");
    printf("H- ALTA DE TRABAJO \n");
    printf("I- LISTAR TRABAJOS \n");
    printf("J- INFORMES \n");
    printf("K- SALIR\n");

    ac_getChar(&opcion,"Ingrese opcion: ",'0','0','0','0','0',3);
    opcion = tolower(opcion);
    while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd' && opcion != 'e' && opcion != 'f' && opcion != 'g' && opcion != 'h' && opcion != 'i' && opcion != 'j' && opcion != 'k')
    {
        ac_getChar(&opcion,"Error. Ingrese opcion: ",'0','0','0','0','0',3);
    }
    return opcion;
}

int menuInformes()
{
    int opcion = 11;
    system("cls");
    printf("****MENU DE INFORMES****\n\n");
    printf("1- MOSTRAR MOTOS DE COLOR SELECCIONADO \n");
    printf("2- MOSTRAR MOTOS DE TIPO SELECCIONADO \n");
    printf("3- INFORMAR MOTOS DE MAYOR CILINDRADA\n");
    printf("4- LISTAR MOTOS POR TIPO\n");
    printf("5- INFORMAR CANTIDAD DE MOTOS DE UN TIPO Y COLOR ESPECIFICO\n");
    printf("6- MOSTRAR EL/LOS COLORES MAS ELEJIDOS POR LOS CLIENTES\n");
    printf("7- PEDIR MOTO Y MOSTRAR TODOS LOS TRABAJOS QUE SE LE HICIERON\n");
    printf("8- PEDIR MOTO E INFORMAR EL TOTAL DE IMPORTES POR LOS SERVICIOS REALIZADOS\n");
    printf("9- PEDIR SERVICIO Y MOSTRAR MOTOS A LAS CUALES SE LES REALIZO\n");
    printf("10- PEDIR FECHA Y MOSTRAR LOS SERVICIOS REALIZADOS EN LA MISMA\n");
    printf("11- VOLVER A MENU PRINCIPAL \n");

    ac_getInt(&opcion,1,11,"Ingrese opcion: ",3);
    return opcion;
}

