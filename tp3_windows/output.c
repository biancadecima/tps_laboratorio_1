#include <stdio.h>
#include "output.h"

int manejarMenuPrincipal() {
	int opcion;

	printf("\n**** MENU PRINCIPAL ****\n"
			"1. Cargar archivos de texto de jugadores y selecciones\n"
			"2. Alta jugador\n"
			"3. Modificar jugador\n"
			"4. Baja jugador\n"
			"5. Listar\n"
			"6. Convocar jugadores\n"
			"7. Ordenar y listar\n"
			"8. Generar archivo binario\n"
			"9. Cargar archivo binario\n"
			"10. Guardar archivos de texto\n"
			"11. Salir\n");

	getNumber(&opcion, "\nIngrese opcion: ", "\nOpcion invalida. ", 1, 11, 3);

	return opcion;
}

int manejarMenuListados(){
	int opcion;

	printf("\n1. Listado de todos los jugadores\n2. Listado de selecciones\n3. Listado de jugadores convocados\n");

	getNumber(&opcion, "\nIngrese opcion: ", "\nOpcion Invalida. ", 1, 3, 3);

	return opcion;
}

int manejarMenuConvocados(){
	int opcion;

	printf("\n1. Convocar Jugador\n2. Quitar jugador de una seleccion\n");

	getNumber(&opcion, "\nIngrese opcion: ", "Opcion invalida. ", 1, 2, 3);

	return opcion;
}

void mostrarNacionalidades(){
	printf("\n0. Argentino\n1. Brasilero\n2. Uruguayo\n3. Portugues\n4. Ingles\n5. Aleman\n6. Mexicano\n7. Estado Unidense\n8. Camerunes\n9. Senegales\n10. Australiano\n11. Qatari"
			"\n12. Arabe \n13. Belga\n14. Canadiense\n15. Surcoreano\n16. Costariqueño\n17. Croata\n18. Dinamarques\n19. Ecuatoriano\n20. Español\n21. Frances\n22. Gales"
			"\n23. Ghanes\n24. Holandes\n25. Irani\n26. Japones\n27. Marroqui\n28. Polaco\n29. Serbio\n30. Suizo\n31. Tunecino\n");
}

void mostrarConfederaciones(){

	printf("\n0. AFC\n1. CAF\n2. CONCACAF\n3. CONMEBOL \n4. UEFA");

}

void mostrarPosiciones(){
	printf("\n0.Portero\n1. Defensa Central\n2.Lateral izquierdo\n3.Lateral derecho\n4. Pivote\n5. Mediocentro\n6. Mediocentro ofensivo\n7. Extremo izquierdo\n8. Extremo derecho\n9. Mediapunta\n10. Delantero centro");
}

int manejoSalida(){
	int opcion;

	getNumber(&opcion, "\n Confirma la salida?\n1. Si\n2. No\nIngrese opcion: ", "Opcion Invalida. ", 1, 2, 3);

	return opcion;
}
