/**
  * @file Arbol.h
  * @date 13/11/2018
  * @author Eddieson Cortés
  * @author Fernando Servín
  * @brief Métodos del árbol binario de búsqueda
  */

/**
* @brief Estructura que representa un Nodo de un árbol binario de búsqueda.
*/
typedef struct nodo{
    int dato;/**< Dato que almacena el nodo */
    char* palabra;
    char* significado;
    struct nodo* hizq;/**< Apuntador al hijo izquierdo del nodo */
    struct nodo* hder;/**< Apuntador al hijo derecho del nodo */
}Nodo;

Nodo** raiz;/**< Nodo raíz del árbol*/

/**
* @brief Asigna memoria a la raíz del árbol
*/
void init();

/**
* @brief Inserta nuevo nodo en el arbol
* El árbol ordenará el nuevo nodo según el valor que contenga
* @param Nodo** dirección de la raíz
* @param Nodo* nuevo nodo a insertar
*/
void insertar(Nodo** raiz, Nodo* nuevo);

/**
* @brief Muestra el menú para seleccionar el recorrido del árbol
*/
void mostrar();

/**
* @brief Eliminar nodo
* Elimina el nodo que tenga el valor que se manda como parámetro
* @param Nodo** raíz del árbol
* @param int número a buscar para eliminar
* @return int 1 si ya se terminó la recursividad
*/
int eliminarNodo(Nodo** raiz, char* palabra);

/**
* @brief Busca nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int valor del nodo a encontrar
* @return Nodo* NULL si no existe el nodo o el nodo si es que existe
*/
Nodo* encontrarNodo(Nodo** raiz, char* palabra);

/**
* @brief Obtiene que recorrido de arbol quiere el usuario
* @return int valor encontrado según el órden
*/
int getRecorrido();

/**
* @brief Mostrar inorden el árbol
* @param Nodo** raíz
*/
void inOrden(Nodo** raiz);

/**
* @brief Mostrar preorden el árbol
* @param Nodo** raíz
*/
void preOrden(Nodo** raiz);

/**
* @brief Mostrar postorden el árbol
* @param Nodo** raíz
*/
void postOrden(Nodo** raiz);

/**
* @brief Calcula la altura del nodo
* @param Nodo** raíz
* @return int altura del árbol
*/
int altura(Nodo** raiz);

/**
* @brief Calcula el nivel del nodo dado
* @param Nodo** raiz del árbol
* @param int valor del nodo el cual se quiere saber el nivel
* @param int nivel del nodo
* @return int nivel del dato
*/
int nivelNodo(Nodo** raiz, char* palabra, int nivel);

/**
* @brief Modificar nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int nuevo valor del nodo a cambiar
* @param int valor del nodo a cambiar
* @return int 0 si no está el nodo a buscar o si ya existe el nuevo nodo
*/
int modificarNodo(Nodo** raiz, char* nuevaPalabra, char* palabra, char* significado);

/**
* @brief Busca cuál es el valor mínimo dentro del árbol
* @param Nodo** raíz
* @return valro mínimo contenido en el árbol
*/
Nodo** minimo(Nodo** raiz);

/**
* @brief Imprime el valor maximo del arbol
*/
void valorMaximo();

/**
* @brief Imprime el valor minimo del arbol
*/
void valorMinimo();

/**
* @brief Busca cuál es el valor máximo dentro del árbol
* @param Nodo** raíz
* @return valro máximo contenido en el árbol
*/
Nodo** maximo(Nodo** raiz);

/**
* @brief Crea nodo con valor dado
* @param int valor del nodo a crear
* @return Nodo* con número ingresado
*/
Nodo* crearNodo(char* palabra, char* significado);

/**
* @brief Crea nodo con valor dado pidiendo dato
* @param int valor del nodo a crear
* @return Nodo* nodo con número número ingresado
*/
Nodo* crearNodoPD();

/**
* @brief Busca dato en el árbol
* @param int valor a buscar
*/
void encontrarDato(char* palabra);

/**
* @brief Busca nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int valor del nodo a encontrar del padre
* @return Nodo* NULL si no existe el nodo o el nodo si es que existe
*/
Nodo* encontrarAnterior(Nodo** raiz, char*  palabra);
