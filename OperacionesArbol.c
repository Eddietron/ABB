/**
  * @file OperacionesArbol.c
  * @date 13/11/2018
  * @author Eddieson Cortés
  * @author Fernando Servín
  * @brief Métodos del árbol binario de búsqueda
  */

#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "DatosLibreria.h"

/**
 * @brief Función callback de tipo Nodo*
 * Crea un nodo con valor igual al párametro de entrada
 * @param int valor del nuevo nodo
 * @return Nodo* con valor asignado
 */
Nodo* (*cndd)(char*, char*) = crearNodo;


/**
* @brief Asigna memoria a la raíz del árbol
*/
void init(){
    raiz = (Nodo**)malloc(sizeof(Nodo*));
    *raiz = NULL;
}

/**
* @brief Inserta nuevo nodo en el arbol
* El árbol ordenará el nuevo nodo según el valor que contenga
* @param Nodo** dirección de la raíz
* @param Nodo* nuevo nodo a insertar
*/
void insertar(Nodo** raiz, Nodo* nuevo){
    if ( !(*raiz))
        *(raiz) = nuevo;
    else{
        if ((*raiz)->dato <= nuevo->dato)
            insertar(&((*raiz)->hder), nuevo);
        else if ((*raiz)->dato > nuevo->dato)
            insertar(&((*raiz)->hizq), nuevo);
    }
}

/**
* @brief Muestra el menú para seleccionar el recorrido del árbol
*/
void mostrar(){
    int recorrido = getRecorrido();
    switch(recorrido){
        case 1:
            inOrden(raiz);
            break;
        case 2:
            preOrden(raiz);
            break;
        case 3:
            postOrden(raiz);
            break;
    }
    printf("\n");
}

/**
* @brief Eliminar nodo
* Elimina el nodo que tenga el valor que se manda como parámetro
* @param Nodo** raíz del árbol
* @param int número a buscar para eliminar
* @return int 1 si ya se terminó la recursividad
*/
int eliminarNodo(Nodo** raiz, char* palabra){
    Nodo* aux = encontrarNodo(raiz, palabra);
    if ( aux == NULL){
        printf("dato  no encontrado\n");
        return 0;
    }
    if(*raiz == NULL)
        return 0;
    if(equals((*raiz)->palabra, palabra) == 1){
        if((*raiz)->hizq == NULL && (*raiz)->hder == NULL){
            Nodo* aux = *raiz;
            *raiz = NULL;
            free(aux);
        }else if((*raiz)->hizq == NULL && (*raiz)->hder != NULL){
            Nodo* aux = *raiz;
            *raiz = aux->hder;
            free(aux);
        }else if((*raiz)->hizq != NULL && (*raiz)->hder == NULL){
            Nodo* aux = *raiz;
            *raiz = aux->hizq;
            free(aux);
        }else{
            Nodo** min = minimo(&(*raiz)->hder);
            Nodo* aux = *min;
            *min = aux->hder;
            aux->hder = NULL;
            aux->hder = (*raiz)->hder;
            aux->hizq = (*raiz)->hizq;
            free(raiz);
            *raiz = aux;
        }
    }else if((*raiz)->dato < getValor(palabra))
        return eliminarNodo(&(*raiz)->hder, palabra);
    else
        return eliminarNodo(&(*raiz)->hizq, palabra);
    return 1;
}

/**
* @brief Modificar nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int nuevo valor del nodo a cambiar
* @param int valor del nodo a cambiar
* @return int 0 si no está el nodo a buscar o si ya existe el nue   vo nodo
*/
int modificarNodo(Nodo** raiz, char* significado,  char* nuevaPalabra,  char* palabra){
    Nodo* target = NULL;
    target = encontrarNodo(raiz, palabra);
    Nodo* buscador = NULL;
    buscador = encontrarNodo(raiz, palabra);
    if(buscador != NULL){
        printf("El nuevo valor del nodo ya existe\n");
        return 0;
    }
    if(target == NULL){
        printf("Nodo no encontrado\n");
        return 0;
    }
    if( target == *raiz)
        if(target->hizq->dato < getValor(nuevaPalabra) && target->hder->dato > getValor(nuevaPalabra)){
            target->dato = getValor(nuevaPalabra);
            target->palabra = palabra;
            target->significado = significado;
            return 1;
        }else{
            eliminarNodo(raiz, palabra);
            insertar(raiz, (*cndd)(nuevaPalabra, significado));
            return 1;
        }
    if(target->hizq == NULL && target->hder == NULL){
        eliminarNodo(&target, palabra);
        insertar(raiz, (*cndd)(nuevaPalabra, significado));
    }else if(target->hizq != NULL && target->hder == NULL){
        Nodo* anterior =encontrarAnterior(raiz, palabra);
        if(target->hizq->dato < getValor(nuevaPalabra) && getValor(nuevaPalabra) < anterior->dato){
            target->dato = getValor(nuevaPalabra);
            target->palabra =  nuevaPalabra;
            target->significado =  significado;
            return 1;
        }else{
            eliminarNodo(&target, palabra);
            insertar(raiz, (*cndd)(nuevaPalabra, significado));
            return 1;
        }
    }else if(target->hizq == NULL && target->hder != NULL){
        Nodo* anterior =encontrarAnterior(raiz, palabra);
        if(getValor(nuevaPalabra) < target->hder->dato && getValor(nuevaPalabra) > anterior->dato){
            target->dato = getValor(nuevaPalabra);
            target->palabra = nuevaPalabra;
            target->significado = significado;
            return 1;
        }else{
            eliminarNodo(&target, palabra);
            insertar(raiz, (*cndd)(nuevaPalabra, significado));
            return 1;
        }
    }else if(target->hizq != NULL && target->hder != NULL){
        eliminarNodo(raiz, palabra);
        insertar(raiz, (*cndd)(nuevaPalabra, significado));
    }
    return 1;
}

/**
* @brief Busca nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int valor del nodo a encontrar
* @return Nodo* NULL si no existe el nodo o el nodo si es que existe
*/
Nodo* encontrarNodo(Nodo** raiz, char* palabra){
    if(*(raiz) != NULL){
        if(equals((*raiz)->palabra, palabra) == 1)
            return *raiz;
        else if((*raiz)->dato < getValor(palabra))
            return encontrarNodo(&(*raiz)->hder, palabra);  
        else if ((*raiz)->dato > getValor(palabra))
            return encontrarNodo(&(*raiz)->hizq, palabra);   
    }
    return NULL;
}

/**
* @brief Busca nodo con valor dado
* @param Nodo** raiz de donde empieza a buscar
* @param int valor del nodo a encontrar del padre
* @return Nodo* NULL si no existe el nodo o el nodo si es que existe
*/
Nodo* encontrarAnterior(Nodo** raiz, char* palabra){
    if(*(raiz) != NULL){
        if(equals((*raiz)->palabra, palabra) == 1)
            return NULL;
        if((*raiz)->hder != NULL && (*raiz)->hizq != NULL)
            if( equals((*raiz)->hder->palabra, palabra) == 1 || equals((*raiz)->hizq->palabra, palabra) == 1)
                return *raiz;
        else if((*raiz)->hder == NULL && (*raiz)->hizq != NULL)
            if(equals((*raiz)->hizq->palabra, palabra) == 1)
                return *raiz;
        else if((*raiz)->hder != NULL && (*raiz)->hizq == NULL)
            if(equals((*raiz)->hder->palabra, palabra) == 1)
                return *raiz;
        else if((*raiz)->hder == NULL && (*raiz)->hizq == NULL)
                return NULL;
        if((*raiz)->dato < getValor(palabra))
            return encontrarNodo(&(*raiz)->hder, palabra);  
        else if ((*raiz)->dato > getValor(palabra))
            return encontrarNodo(&(*raiz)->hizq, palabra);   
    }
    return NULL;
}

/**
* @brief Busca dato en el árbol
* @param int valor a buscar
*/
void encontrarDato(char* palabra){
    Nodo* encontrado =  encontrarNodo(raiz, palabra);
    if(encontrado == NULL)
        printf("El dato no existe\n");
    else
        printf("El dato encontrado\n");
}

/**
* @brief Mostrar inorden el árbol
* @param Nodo** raíz
*/
void inOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        inOrden(&(*raiz)->hizq);
        printf("--------------------------\n");
        printf("%s:\n%s \n", (*(raiz))->palabra, (*(raiz))->significado);
        inOrden(&(*raiz)->hder);
    }
}

/**
* @brief Mostrar preorden el árbol
* @param Nodo** raíz
*/
void preOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        printf("--------------------------\n");
        printf("%s:\n%s \n", (*(raiz))->palabra, (*(raiz))->significado);
        preOrden(&(*raiz)->hizq);
        preOrden(&(*raiz)->hder);
    }
}

/**
* @brief Mostrar postorden el árbol
* @param Nodo** raíz
*/
void postOrden(Nodo** raiz){
    if(*(raiz) != NULL){  
        postOrden(&(*raiz)->hizq);
        postOrden(&(*raiz)->hder);
        printf("--------------------------\n");
        printf("%s:\n%s \n", (*(raiz))->palabra, (*(raiz))->significado);
    }
}

/**
* @brief Calcula la altura del nodo
* @param Nodo** raíz
* @return int altura del árbol
*/
int altura(Nodo** raiz){
    if(*(raiz) == NULL)
        return 0;
    else{
        int hd = altura( &(*raiz)->hder );
        int hi = altura( &(*raiz)->hizq );
        if(hd > hi)
            return hd+1;
        else
            return hi+1;
    }
}

/**
* @brief Calcula el nivel del nodo dado
* @param Nodo** raiz del árbol
* @param int valor del nodo el cual se quiere saber el nivel
* @param int nivel del nodo
* @return int nivel del dato
*/
int nivelNodo(Nodo** raiz, char* palabra, int nivel){
    if(*raiz == NULL)
        return 0;
    if( equals(palabra, (*raiz)->palabra) == 1 )
        return nivel;
    int nivelN = nivelNodo(&((*raiz)->hizq), palabra, nivel+1);
    if( nivelN != 0)
        return nivelN;
    nivelN = nivelNodo(&((*raiz)->hder), palabra, nivel+1);
    return nivelN;
}

/**
* @brief Busca cuál es el valor mínimo dentro del árbol
* @param Nodo** raíz
* @return valro mínimo contenido en el árbol
*/
Nodo** minimo(Nodo** raiz){
    if(*raiz == NULL)
        return NULL;
    if((*raiz)->hizq == NULL)
        return raiz;
    return minimo(&((*raiz)->hizq));
}

/**
* @brief Busca cuál es el valor máximo dentro del árbol
* @param Nodo** raíz
* @return valro máximo contenido en el árbol
*/
Nodo** maximo(Nodo** raiz){
    if(*raiz == NULL)
        return  NULL;
    if((*raiz)->hder == NULL)
        return raiz;
    return maximo(&((*raiz)->hder));
}

/**
* @brief Imprime el valor maximo del arbol
*/
void valorMaximo(){
    printf("valor maximo: %s\n", (*maximo(raiz))->palabra );
}

/**
* @brief Imprime el valor minimo del arbol
*/
void valorMinimo(){
    printf("valor minimo: %s\n", (*minimo(raiz))->palabra );
}

/**
* @brief Obtiene que recorrido de arbol quiere el usuario
* @return int valor encontrado según el órden
*/
int getRecorrido(){
    int n;
    printf("Selecciona la forma recorrer el arbol:\n1. InOrden\n2. PreOrden\n3. PostOrden\n");
    scanf("%d", &n);
    if(n>=1 && n<=3)
        return n;
    return getRecorrido();
}

/**
* @brief Crea nodo con valor dado
* @param int valor del nodo a crear
* @return Nodo* con número ingresado
*/
Nodo* crearNodo(char* significado, char* palabra){
    printf("Creando nodo...\n");
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = getValor(palabra);
    printf("valor obtenido...\n");
    nuevo->palabra = palabra;
    nuevo->significado = significado;
    nuevo->hizq = NULL;
    nuevo->hder = NULL;
    return nuevo;
}

/**
* @brief Crea nodo con valor dado pidiendo dato
* @param int valor del nodo a crear
* @return Nodo* nodo con número número ingresado
*/
Nodo* crearNodoPD(){
    char* palabra = NULL;
    char* significado  = NULL;
    printf("Escribe la palabra:\n");
    palabra = getString();
    printf("Escribe el significado:\n");
    significado = getString();

    return crearNodo(significado, palabra);
}
