#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct {

int id;
char nombre[30];
char sexo;
int isFull;

} e_Cliente;

typedef struct
{
    int id;
    char descripcion [20];
} e_tipoDeMoto;

typedef struct
{
    int id;
    char nombreColor [20];
} e_Color;

typedef struct
{
    int id;
    char marca [20];
    int idTipo;
    int idCliente;
    int idColor;
    int cilindrada;
    int isFull;
} e_Moto;

#endif // MOTO_H_INCLUDED

/** \brief Busca una moto por ID en el vector de motos y devuelve su subindice de ubicacion en el vector
 *
 * \param ID de moto a buscar
 * \param vector de motos
 * \param tamaño de vector
 * \return devuelve el indice del vector donde esta guardado el id de la moto (>=0)
            devuelve -1 si no se encontro el id
 *
 */
int buscarMoto (int id,e_Moto vec[],int size);
//

/** \brief obtiene el primer lugar disponible para guardar nuevos datos en el vector tipo e_Moto
 *
 * \param vector de motos
 * \param tamaño de vector
 * \return devuelve subindice del vector e_moto donde se pueden guardar datos
            devuelve -1 si no hay lugar disponible
 *
 */
int getEmptySlotMoto (e_Moto vec[],int size);
//

/** \brief Obtiene todos los datos necesarios para guardar una moto, la guarda en el vector indicado y nos devuelve si pudo hacer el alta.
 *
 * \param vector de motos
 * \param tamaño de vector
 * \param vector de tipos de moto para mostrar al usuario
 * \param tamaño de vector de tipos
 * \param vector de colores para mostrar al usuario
 * \param tamaño de vector de colores
 * \return devuelve 1 si pudo hacer el alta de moto.
            devuelve 0 si no pudo hacer el alta de moto.
 *
 */
int getMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores);
//

/** \brief Inicializa el vector de motos seteando todos los campos isFull a 0;
 *
 * \param vector de motos
 * \param tamaño de vector
 *
 */
void inicializarMotos (e_Moto vec[],int size);
//

/** \brief Despliega lista de colores guardados en el sistema
 *
 * \param vector de colores
 * \param tamaño del vector de colores
 *
 */
void listarColoresDeMotos(e_Color colores[],int size);
//

/** \brief Despliega lista de tipos de moto guardados en el sistema
 *
 * \param vector de tipos de moto
 * \param tamaño del vector de tipos de moto
 *
 */
void listarTiposDeMotos (e_tipoDeMoto tipos[],int size);
//

/** \brief Permite al usuario modificar datos de la moto que quiera. Valida todos los datos pedidos.
 *
 * \param vector de motos
 * \param tamaño de vector
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void modificarMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Color colores[], int sizeColores,e_Cliente clientes[],int sizeClientes);
//

/** \brief Despliega lista de cilindradas disponibles para elejir. 50,125,500,600,750
 *
 *
 */
void mostrarCilindradas ();
//

/** \brief Muestra datos de una moto por consola. SIN ENCABEZADO
 *
 * \param moto a mostrar
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void mostrarMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief
 *
 * \param vector de motos a mostrar
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void mostrarMotos(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief Muestra datos de una moto por consola. CON ENCABEZADOS POR COLUMNA
 *
 * \param moto a mostrar
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void mostrarPrimerMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief Permite al usuario elminar una moto del sistema. Realiza baja logica (setea campo isFull a 0).
 *
 * \param vector de motos a recorrer para buscar la que el usuario quiera elminar
 * \param tamaño de vector de motos

 (pide estos parametros porque muestra la moto antes de elminarla)
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void eliminarMoto (e_Moto vec[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief Recorre el vector de motos y nos dice si hay alguna moto dada de alta en el sistema
 *
 * \param Vector de motos a recorrer
 * \param tamaño del vector de motos
 * \return devuelve la cantidad de motos que hay guardadas. (>=0)
 *
 */
int hayMotos (e_Moto motos[],int size);
//

/** \brief Inicializa vector de clientes seteando campo isFull a 0;
 *
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void inicializarClientes (e_Cliente vec[],int size);
//

/** \brief Muestra listado de clientes con encabezados por columna (ID,sexo,Nombre completo)
 *
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void mostrarClientes(e_Cliente clientes[], int size);
//

/** \brief Busca un cliente en el vector de clientes por id
 *
  * \param ID del cliente a buscar
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \return devuelve el indice del vector de clientes en donde se encontro al cliente guardaddo.
            devuelve -1 si no encontro al cliente por id
 *
 */
int buscarCliente (int id,e_Cliente vec[],int size);
//

/** \brief Pide color al usuario por consola y muestra todas las motos de ese color.
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \return devuelve cantidad de motos mostradas
 *
 */
int listarMotosSegunColor(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief Pide tipo de moto al usuario por consola y muestra todas las motos de ese tipo
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \return devuelve cantidad de motos mostradas
 *
 */
int listarMotosSegunTipo(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//

/** \brief Ordena el vector de motos por id de tipo.
 *
 * \param vector de motos a ordenar
 * \param tamaño del vector de motos
 *
 */
void ordenarMotosTipo (e_Moto motos [],int size);
//

/** \brief Muestra solamente las motos de un tipo ingresado por parametro. Encabeza el listado segun el tipo.
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
  * \param ID DE TIPO de motos que se quieran mostrar.
 *
 */
void mostrarMotosDeTipo(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes,int idTipo);
//

/** \brief Recorre el vector de motos y averigua cual es el valor maximo de las cilindradas. Luego muestra unicamente las motos cuyo valor de cilindrada sea igual al maximo. El valor inicial esta seteado en 50.
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \return Devuelve cantidad de motos mostradas
 *
 */
int listarMotosMayorCilindrada(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[], int sizeClientes);
//

/** \brief Muetra unicamente las motos cuyo id de color y id de tipo sean iguales a aquellos ingresados por parametros.
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 * \param id de tipo de motos a mostrar
 * \param id de color de motos a mostrar
 * \return devuelve cantidad de motos mostradas
 *
 */
int mostrarMotosDeTipoYColor(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes,int idTipo, int idColor);
//

/** \brief Recorre el vector de motos. Cuenta la cantidad de motos de cada color. Muestra la descripcion del color mas usado y cuantas motos son de ese color.
 *
 * \param vector de motos a recorrer
 * \param tamaño de vector de motos
 * \param vector de colores de moto
 * \param tamaño de vector de colores de moto
 * \param vector de tipos de moto
 * \param tamaño de vector de tipos de moto
 * \param vector de clientes guardados en el sistema
 * \param tamaño del vector de clientes
 *
 */
void coloresMasUsados (e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos,e_Cliente clientes[],int sizeClientes);
//


