#include "fecha.h"
#include "moto.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} e_Servicio;



typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    e_fecha fechaDeTrabajo;
    int isFull;
} e_Trabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Setea el campo isFull de todos los trabajos en el vector de trabajos a 0
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 *
 */
void inicializarTrabajos (e_Trabajo vec[],int size);
//

/** \brief Muestra datos de un trabajo por consola. SIN ENCABEZADO
 *
 * \param Trabajo a mostrar
 * \param vector de servicios
 * \param tamaño del vector de servicios
 *
 */
void mostrarTrabajo (e_Trabajo trabajo, e_Servicio servicios[],int sizeServicios);
//

/** \brief Muestra datos de un trabajo por consola. CON ENCABEZADO por columnas
 *
 * \param Trabajo a mostrar
 * \param vector de servicios
 * \param tamaño del vector de servicios
 *
 */
void mostrarPrimerTrabajo (e_Trabajo trabajo, e_Servicio servicios[],int sizeServicios);
//

/** \brief Muestra todos los trabajos por consola y sus datos en el vector de trabajos. CON ENCABEZADO
 *
 * \param Vector de trabajos a mostrar
 * \param tamaño del vector de trabajos
  * \param vector de servicios
 * \param tamaño del vector de servicios
 *
 */
void mostrarTrabajos(e_Trabajo trabajos[],int size, e_Servicio servicios[],int sizeServicios);
//

/** \brief Obtiene el primer indice disponible en el vector de trabajos para guardar un nuevo trabajo
 *
 * \param Vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \return devuelve el primer indice del vector donde se pueden guardar datos.
           devuelve -1 si no hay lugar disponible
 *
 */
int getEmptySlotTrabajo (e_Trabajo vec[],int size);
//

/** \brief Despliega lista de servicios cargados en el sistema con sus precios
 *
 * \param vector de servicios
 * \param tamaño del vector de servicios
 *
 */
void listarServiciosDeMotos (e_Servicio servicios[],int size);
//

/** \brief
 *
 * \param vector de trabajos
 * \param tamaño del vector de trabajos
 * \param id que va a tomar el trabajo (autoincremental) empieza por 100.
 * \param vector de servicios cargado en el sistema (ofrece opciones al usuario)
 * \param tamaño del vector de servicios
 * \param vector de motos guardado en el sistema
 * \param tamaño del vector de motos
 * \param vector de tipos de moto guardados en el sistema
 * \param tamaño del vector de tipos
 * \param vector de colores guardados en el sistema
 * \param tamaño del vector de colores
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \return 1 si pudo dar de alta el trabajo. 0 si no pudo dar de alta el trabajo (los ids de trabajo son autoincrementales).
 *
 */
int getTrabajo (e_Trabajo trabajos[],int sizeT,int idOrigen,e_Servicio servicios[],int sizeServicios,e_Moto vec[],int sizeM,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores,e_Cliente clientes[],int sizeClientes);
//

/** \brief Busca trabajo por ID y nos devuelve en que indice del vector de trabajos se encuentra
 *
 * \param id de trabajo a buscar
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \return indice del vector de trabajos donde se encuentra el trabajo que buscamos.
           devuelve -1 si el id pasado por parametro no corresponde a un id guardado en el vector de trabajos.
 *
 */
int buscarTrabajo (int id,e_Trabajo vec[],int size);
//

/** \brief Ordena el vector de trabajos por fecha de mas antiguo a mas reciente
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 *
 */
void ordenarTrabajosFecha (e_Trabajo trabajos[],int size);
//

/** \brief Pide al usuario un id de moto y muestra todos los trabajos que se le realizaron a esa moto
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \param vector de motos guardado en el sistema
 * \param tamaño del vector de motos
 * \param vector de servicios cargado en el sistema
 * \param tamaño del vector de servicios
* \return Devuelve cantidad de trabajos listados
 *
 */
int listarTrabajosSegunMoto (e_Trabajo trabajos[],int sizeT,e_Moto motos[],int sizeM,e_Servicio servicios[],int sizeServicios);
//

/** \brief Pide al usuario un servicio de moto (lista los servicios) y muestra todos los trabajos que se le realizaron de ese servicio
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \param vector de servicios cargado en el sistema
 * \param tamaño del vector de servicios
 * \return devuelve cantidad de trabajos listados
 *
 */
int listarTrabajosSegunServicio (e_Trabajo trabajos[],int sizeT,e_Servicio servicios[],int sizeServicios);
//

/** \brief Pide al usuario una fecha  y muestra todos los trabajos que se le realizaron en esa fecha (valida la fecha con ac_getDate). El año maximo permitido ees 2020 y el minimo es 1900 (suponiendo que es el año de apertura del taller).
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \param vector de servicios cargado en el sistema
 * \param tamaño del vector de servicios
 * \return devuelve cantidad de trabajos listados
 *
 */
int listarTrabajosSegunFecha (e_Trabajo trabajos[],int sizeT,e_Servicio servicios[],int sizeServicios);
//

/** \brief Pide id de moto al usuario por consola y la suma del precio de todos los trabajos que se le realizaron a esa moto.
 *
 * \param vector de trabajos a recorrer
 * \param tamaño del vector de trabajos
 * \param vector de servicios cargado en el sistema
 * \param tamaño del vector de servicios
 * \return devuelve total de importe de servicios realizados a la moto
 *
 */
int totalServiciosPorMoto (e_Trabajo trabajos[],int sizeT,e_Moto motos[],int sizeM,e_Servicio servicios[],int sizeServicios);
