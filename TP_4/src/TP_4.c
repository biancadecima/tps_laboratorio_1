#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
	int id;
	char nombre[50];
	int edad;
	char sexo;
}eMascota;

void mostrasMascota(eMascota* this);
void mostrarLista(LinkedList* lista);
int compararPorNombre (void *m1, void *m2);

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaMascota = ll_newLinkedList(); // USO LL_newLinkedList
	LinkedList* listaClonada = ll_newLinkedList();
	LinkedList* subLista = ll_newLinkedList();
	eMascota* auxMascota = NULL;
	int indice;
	int contiene;
	int isEmpty;

	eMascota pArrayMascotas[5] = {{1, "Pipu", 2, 'm'}, {2, "Lola", 4, 'h'}, {3, "Carlo", 5, 'm'}, {4, "Mora", 1, 'h'}, {5, "Michi", 3, 'm'}};
	eMascota setMascota = {22, "Marco", 8, 'm'};
	eMascota pushMascota = {13, "Lila", 10, 'h'};

	for(int i = 0; i<5; i++){
		ll_add(listaMascota, &pArrayMascotas[i]);
	}

	printf("================================\n");
	printf("|        FUNCION  ll_add        |\n");
	printf("================================\n");
	printf("Se agregaron 5 mascotas: \n");
	mostrarLista(listaMascota);

	printf("\n\n");
	printf("================================\n");
	printf("|       FUNCION  ll_clone       |\n");
	printf("================================\n");
	printf("Se clonó la lista: \n");
	listaClonada = ll_clone(listaMascota);
	mostrarLista(listaClonada);

	printf("\n\n");
	printf("================================\n");
	printf("|     FUNCION  ll_containsAll   |\n");
	printf("================================\n");
	printf("Se verifica que las mascotas de la lista original esten contenidos en la lista clonada si retorna 1: \n");
	contiene = ll_containsAll(listaMascota, listaClonada);
	printf("%d\n", contiene);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_sort      |\n");
	printf("================================\n");
	printf("Se ordena la lista clonada por nombre: \n");
	ll_sort(listaClonada, compararPorNombre, 1);
	mostrarLista(listaClonada);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_set       |\n");
	printf("================================\n");
	printf("Se setea una nueva mascota a la lista en el indice 3: \n");
	ll_set(listaMascota, 3, &setMascota);
	mostrarLista(listaMascota);

	printf("\n\n");
	printf("================================\n");
	printf("|       FUNCION  ll_remove      |\n");
	printf("================================\n");
	printf("Se remueve la mascota de la lista en el indice 2: \n");
	ll_remove(listaMascota, 2);
	mostrarLista(listaMascota);

	printf("\n\n");
	printf("================================\n");
	printf("|      FUNCION  ll_indexOf      |\n");
	printf("================================\n");
	printf("Devuelve el indice de la lista donde se encuentra la mascota Marco: \n");
	indice = ll_indexOf(listaMascota, &setMascota);
	printf("%d\n", indice);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_push      |\n");
	printf("================================\n");
	printf("Inserta una nueva mascota en la lista en la posicion 2: \n");
	ll_push(listaMascota, 2, &pushMascota);
	mostrarLista(listaMascota);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_pop       |\n");
	printf("================================\n");
	printf("Elimina la mascota de la posicion 3: \n");
	auxMascota = ll_pop(listaMascota,3);
	mostrarLista(listaMascota);
	printf(" Y retorna el puntero al elemento: \n");
	mostrasMascota(auxMascota);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_contains       |\n");
	printf("================================\n");
	printf("Verifica que la mascota Marco este contenida en la lista si retorna 1: \n");
	contiene = ll_contains(listaMascota, &setMascota);
	printf("%d\n", contiene);

	printf("\n\n");
	printf("================================\n");
	printf("|      FUNCION  ll_subList     |\n");
	printf("================================\n");
	printf("Se crea una nueva lista de la mascota en la posicion 2 a la 4: \n");
	subLista = ll_subList(listaMascota, 2, 4);
	mostrarLista(subLista);

	printf("\n\n");
	printf("================================\n");
	printf("|        FUNCION  ll_clear      |\n");
	printf("================================\n");
	printf("Se eliminaron todas las mascotas, pero la linkedlist sigue existiendo: \n");
	ll_clear(listaMascota);
	mostrarLista(listaMascota);

	printf("\n\n");
	printf("================================\n");
	printf("| FUNCION  ll_deleteLinkedList |\n");
	printf("================================\n");
	printf("Se elimino la linkedList, ahora su longitud es de: \n");
	ll_deleteLinkedList(listaMascota);
	isEmpty = ll_isEmpty(listaMascota);
	printf("%d\n", isEmpty);

	return EXIT_SUCCESS;
}

void mostrasMascota(eMascota* this){
	printf("| %3d | %8s | %4d | %4c |\n", this->id, this->nombre, this->edad, this->sexo);
}

void mostrarLista(LinkedList* lista) {
	int largoLista;
	eMascota* auxMascota = NULL;

	largoLista = ll_len(lista); // USO LL_LEN
	printf("================================\n");
	printf("| ID  |  NOMBRE  | EDAD | SEXO |\n");
	printf("================================\n");
	for (int i = 0; i < largoLista; i++) {
		auxMascota = ll_get(lista, i); // USO LL_GET
		if (ll_isEmpty(lista) == 0) { // USO LL_ISEMPTY
			mostrasMascota(auxMascota);
		}
	}printf("===============================\n");
}

int compararPorNombre (void *m1, void *m2) {
	int compara = 0;
	eMascota* pMascotaUno = NULL;
	eMascota* pMascotaDos = NULL;
	char nombre1[100];
	char nombre2[100];

	if (m1 != NULL && m2 != NULL) {
		pMascotaUno = (eMascota*) m1;
		pMascotaDos = (eMascota*) m2;
		if (pMascotaUno != NULL && pMascotaDos != NULL) {
			strcpy(nombre1, pMascotaUno->nombre);
			strcpy(nombre2, pMascotaDos->nombre);
			compara = strcmp(nombre1, nombre2);
		}
	}

	return compara;
}
