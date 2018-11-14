#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

Nodo* (*cndd)(int) = crearNodo;

void init(){
    raiz = (Nodo**)malloc(sizeof(Nodo*));
    *raiz = NULL;
}
//raiz - nodo raiz del arbol
// nuevo - nodo a insertar
void insertar(Nodo** raiz, Nodo* nuevo){
    if ( !(*raiz))
        *(raiz) = nuevo;
    else if((*raiz)->dato == nuevo->dato){
        printf("Ese valor ya existe\n");
        return;
    }else{
        if ((*raiz)->dato < nuevo->dato)
            insertar(&((*raiz)->hder), nuevo);
        else if ((*raiz)->dato > nuevo->dato)
            insertar(&((*raiz)->hizq), nuevo);
    }
}
//menu para imprimir el arbol
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
//raiz - raiz del arbol
//id - valor del nodo a eliminar
int eliminarNodo(Nodo** raiz, int id){
    Nodo* aux = encontrarNodo(raiz, id);
    if ( aux == NULL){
        printf("dato  no encontrado\n");
        return 0;
    }
    if(*raiz == NULL)
        return 0;
    if((*raiz)->dato == id){
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
    }else if((*raiz)->dato < id)
        return eliminarNodo(&(*raiz)->hder, id);
    else
        return eliminarNodo(&(*raiz)->hizq, id);
    return 1;
}
//raiz - raiz del arbol
//nuevo - nuevo valor del nodo a cambiar
//id - valor del nodo a cambiar

int modificarNodo(Nodo** raiz, int nuevo, int id){
    Nodo* target = NULL;
    target = encontrarNodo(raiz, id);
    Nodo* buscador = NULL;
    buscador = encontrarNodo(raiz, nuevo);
    if(buscador != NULL){
        printf("El nuevo valor del nodo ya existe\n");
        return 0;
    }
    if(target == NULL){
        printf("Nodo no encontrado\n");
        return 0;
    }
    if( target == *raiz)
        if(target->hizq->dato < nuevo && target->hder->dato > nuevo)
            target->dato = nuevo;
        else{
            eliminarNodo(raiz, target->dato);
            insertar(raiz, (*cndd)(nuevo));
        }

    if(target->hizq == NULL && target->hder == NULL){
        eliminarNodo(&target, target->dato);
        insertar(raiz, (*cndd)(nuevo));
    }else if(target->hizq != NULL && target->hder == NULL){
        Nodo* anterior =encontrarAnterior(raiz, id);
        if(target->hizq->dato < nuevo && nuevo < anterior->dato)
            target->dato = nuevo;
        else{
            eliminarNodo(&target, target->dato);
            insertar(raiz, (*cndd)(nuevo));
        }
    }else if(target->hizq == NULL && target->hder != NULL){
        Nodo* anterior =encontrarAnterior(raiz, id);
        if(nuevo < target->hder->dato && nuevo > anterior->dato)
            target->dato = nuevo;
        else{
            eliminarNodo(&target, target->dato);
            insertar(raiz, (*cndd)(nuevo));
        }
    }else if(target->hizq != NULL && target->hder != NULL){
        eliminarNodo(raiz, id);
        insertar(raiz, (*cndd)(nuevo));
    }
    return 1;
}
//raiz - raiz del arbol
//id - valor del nodo a encontrar
Nodo* encontrarNodo(Nodo** raiz, int id){
    if(*(raiz) != NULL){
        if((*raiz)->dato == id)
            return *raiz;
        else if((*raiz)->dato < id)
            return encontrarNodo(&(*raiz)->hder, id);  
        else if ((*raiz)->dato > id)
            return encontrarNodo(&(*raiz)->hizq, id);   
    }
    return NULL;
}
//raiz - raiz del arbol
//id - valor del nodo el cual se requiere su nodo predecesor
Nodo* encontrarAnterior(Nodo** raiz, int id){
    if(*(raiz) != NULL){
        if((*raiz)->dato == id)
            return NULL;
        if((*raiz)->hder != NULL && (*raiz)->hizq != NULL)
            if((*raiz)->hder->dato == id || (*raiz)->hizq->dato == id)
                return *raiz;
        else if((*raiz)->hder == NULL && (*raiz)->hizq != NULL)
            if((*raiz)->hizq->dato == id)
                return *raiz;
        else if((*raiz)->hder != NULL && (*raiz)->hizq == NULL)
            if((*raiz)->hder->dato == id)
                return *raiz;
        else if((*raiz)->hder == NULL && (*raiz)->hizq == NULL)
                return NULL;
        if((*raiz)->dato < id)
            return encontrarNodo(&(*raiz)->hder, id);  
        else if ((*raiz)->dato > id)
            return encontrarNodo(&(*raiz)->hizq, id);   
    }
    return NULL;
}
//id - valor del nodo a encontrar
void encontrarDato(int id){
    Nodo* encontrado =  encontrarNodo(raiz, id);
    if(encontrado == NULL)
        printf("El dato no existe\n");
    else
        printf("El dato encontrado\n");
}
//raiz - raiz del arbol
void inOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        inOrden(&(*raiz)->hizq);
        printf("%d, ", (*(raiz))->dato);
        inOrden(&(*raiz)->hder);
    }
}
//raiz - raiz del arbol
void preOrden(Nodo** raiz){
    if(*(raiz) != NULL){
        printf("%d, ", (*(raiz))->dato);
        preOrden(&(*raiz)->hizq);
        preOrden(&(*raiz)->hder);
    }
}
//raiz - raiz del arbol
void postOrden(Nodo** raiz){
    if(*(raiz) != NULL){  
        postOrden(&(*raiz)->hizq);
        postOrden(&(*raiz)->hder);
        printf("%d, ", (*(raiz))->dato);
    }
}
//raiz - raiz del arbol
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
//raiz - raiz del arbol
//id - valor del nodo el cual se quiere saber el nivel
// nivel - nivel del nodo
int nivelNodo(Nodo** raiz, int id, int nivel){
    if(*raiz == NULL)
        return 0;
    if( (*raiz)->dato == id)
        return nivel;
    int nivelN = nivelNodo(&((*raiz)->hizq), id, nivel+1);
    if( nivelN != 0)
        return nivelN;
    nivelN = nivelNodo(&((*raiz)->hder), id, nivel+1);
    return nivelN;
}
//raiz - raiz del arbol
Nodo** minimo(Nodo** raiz){
    if(*raiz == NULL)
        return NULL;
    if((*raiz)->hizq == NULL)
        return raiz;
    return minimo(&((*raiz)->hizq));
}
//raiz - raiz del arbol
Nodo** maximo(Nodo** raiz){
    if(*raiz == NULL)
        return  NULL;
    if((*raiz)->hder == NULL)
        return raiz;
    return maximo(&((*raiz)->hder));
}
//imprime el valor maximo del arbol
void valorMaximo(){
    printf("valor maximo: %d\n", (*maximo(raiz))->dato );
}
//imprime el valor minimo del arbol
void valorMinimo(){
    printf("valor minimo: %d\n", (*minimo(raiz))->dato );
}
//obtiene que recorrido de arbol quiere el usuario
int getRecorrido(){
    int n;
    printf("Selecciona la forma recorrer el arbol:\n1. InOrden\n2. PreOrden\n3. PostOrden\n");
    scanf("%d", &n);
    if(n>=1 && n<=3)
        return n;
    return getRecorrido();
}
//id - valor del nodo a crear
Nodo* crearNodo(int id){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = id;
    nuevo->hizq = NULL;
    nuevo->hder = NULL;
    return nuevo;
}
//crea un nodo
Nodo* crearNodoPD(){
    int n;
    printf("inserta el dato\n");
    scanf("%d", &n);
    return crearNodo(n);
}
