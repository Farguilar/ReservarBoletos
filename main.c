#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 
	int distribucion[9][12]; //Establece la matriz de 9 filas y 12 columnas (la ultima columna sera utilizada para el precio).
	char usuario_in[50], contra_in[50], usuario[50],contra[50]; //Se definen las variables para el inicio de sesion.
	int con_inicio, opcion_menu1; //con_inicio=condicional para cerrar el bucle de inicio de sesion.
	int i,j,k,l; //Variables para imprimir y manejar datos de la matriz. i=filas. j=columnas.
	int num_fila,cant_boletos=0,cant_boletos_55=0,cant_boletos_89=0,cant_boletos_73=0,costo_total=0;
	int fila,asiento,fila_cancelar,asiento_cancelar,bucle_principal;
	
	//Ciclo para asignar valores 0 a la matriz.
		for (i=0;i<9;i++){ //Ciclo for (filas).
			for(j=0;j<12;j++){ //Ciclo for (columnas).
				distribucion[i][j]=0;
			} //Llave de ciclo for (columnas).
		}//Llave de ciclo for (filas).
	
		//Asignar los precios a las filas.
		for (i=0;i<3;i++){ //Ciclo for (filas).
			distribucion[i][11]=55;
		}//Llave de ciclo for (filas).
		for (i=3;i<6;i++){ //Ciclo for (filas).
			distribucion[i][11]=89;
		}//Llave de ciclo for (filas).
		for (i=6;i<9;i++){ //Ciclo for (filas).
			distribucion[i][11]=73;
		}//Llave de ciclo for (filas).	
	
	//Registra el nuevo nombre de usuario y nueva contraseña.
	printf("Registro de usuario.\n");
	printf("Registre el nuevo nombre de usuario.\n");
	scanf("%s", &usuario_in);
	strcpy(usuario,usuario_in);
	printf("Registre la nueva contraseña.\n");
	scanf("%s", &contra_in);
	strcpy(contra,contra_in);
	printf("Usuario y contraseña registrados.\n");
	
	do{ //Inicio de sesion. Se cierra hasta que el usuario y contraseña son los correctos.

			printf("Inicio de sesion.\n");
			printf("Ingrese el nombre de usuaraio.\n");
			scanf("%s",&usuario_in);
			printf("Ingrese su contraseña.\n");
			scanf("%s",&contra_in);
		
			if ((strcmp(contra_in,contra)==0) && (strcmp(usuario_in,usuario)==0)){ //Evalua si el usuario y contraseña ingresados son iguales a los ya establecidos.
				printf("Acceso concedido.\n");
				con_inicio=1;
			} else {  //Llave if(contra,usuario).
				printf("Acceso denegado.\n");
				con_inicio=0;
			}
		}while (con_inicio==0); //Fin del ciclo de inicio de sesion.
	
	//Inicio del programa.
	do { 
		printf("Menu principal.\n");
		printf("Ingrese la opcion que desea.\n");
		printf("1. Comprar boletos\n");
		printf("2. Mostrar mapa de asientos.\n");
		printf("3. Cancelar compra de boletos.\n");
		printf("4. Costo total de los boletos reservados\n");
		printf("5. Salir\n");
		scanf("%d", &opcion_menu1);
		
		//Evalua las opciones del menu.
		switch (opcion_menu1){
			case 1: //Comprar boeltos.
				printf("Distribucion.\n");
				printf("Los asientos ocupados estan identificados con el numero 1.\n\n\n");
				printf("\t\t\t\t\t\tAsientos disponibles\t\t\t\t     Precio($)\n\n");
				//Ciclo para imprimir la matriz.
				for (i=0;i<9;i++){ //Ciclo for (filas).
					num_fila=i+1;
					printf("Fila  %d:\t",num_fila);
					for(j=0;j<12;j++){ //Ciclo for (columnas).
						printf("%d\t", distribucion[i][j]);
					} //Llave de ciclo for (columnas).
					printf("\n");
				}//Llave de ciclo for (filas).
				
				//Compra de boletos.
				printf("Ingrese la cantidad de boletos que desea reservar.\n");
				scanf("%d", &cant_boletos);
				if (cant_boletos>0 && cant_boletos<=7){
					for (i=0;i<cant_boletos;i++){
						printf("Ingrese el numero de fila del boleto a reservar.\n");
						scanf("%d", &fila);
						printf("Ingrese el numero de asiento que desea reservar.\n");
						scanf("%d", &asiento);
						if (distribucion[fila][asiento]==0){ //Evalua si el lugar ya esta reservado.
							printf("Lugar reservado exitosamente.\n");
							distribucion[fila-1][asiento-1]=1;
						}else{
							printf("Este lugar ya esta reservado.\n");
						}
						
					}				
				}else {
					printf("No puedes reservar esa cantidad de lugares.\n");
				}
				//Se definen las variables por precaucion.
				cant_boletos_55=0;
				cant_boletos_89=0;
				cant_boletos_73=0;
				costo_total=0;
				if ((cant_boletos>0) && (cant_boletos<=7)){
				//Calcula el total de los boletos reservados.
				for (i=0;i<3;i++){ //Boletos de $55.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_55=cant_boletos_55+1;
						}
					}
				}
				for (i=3;i<6;i++){ //Boletos de $89.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_89=cant_boletos_89+1;
						}
					}
				}
				for (i=6;i<9;i++){ //Boletos de $73.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_73=cant_boletos_73+1;
						}
					}
				}
				
				costo_total=((cant_boletos_55*55)+(cant_boletos_89*89)+(cant_boletos_73*73));
				printf("El costo total de los lugares reservados es: %d\n", costo_total);
				}
				bucle_principal=1;
			break; //Fin de comprar boletos.
			
			case 2: //Mostrar mapa de asientos.
				printf("Distribucion.\n");
				printf("Los asientos ocupados estan identificados con el numero 1.\n\n\n");
				printf("\t\t\t\t\t\tAsientos disponibles\t\t\t\t     Precio($)\n\n");
				//Ciclo para imprimir la matriz.
				for (i=0;i<9;i++){ //Ciclo for (filas).
					num_fila=i+1;
					printf("Fila  %d:\t",num_fila);
					for(j=0;j<12;j++){ //Ciclo for (columnas).
						printf("%d\t", distribucion[i][j]);
					} //Llave de ciclo for (columnas).
					printf("\n");
				}//Llave de ciclo for (filas).
				bucle_principal=1;
			break; //Fin de mostrar mapa de asientos.
			
			case 3: //Cancelar compra.
				do{ //Inicio de sesion. Se cierra hasta que el usuario y contraseña son los correctos.
				printf("Inicio de sesion.\n");
				printf("Ingrese el nombre de usuaraio.\n");
				scanf("%s",&usuario_in);
				printf("Ingrese su contraseña.\n");
				scanf("%s",&contra_in);
		
				if ((strcmp(contra_in,contra)==0) && (strcmp(usuario_in,usuario)==0)){ //Evalua si el usuario y contraseña ingresados son iguales a los ya establecidos.
					printf("Acceso concedido.\n");
					con_inicio=1;
				} else {  //Llave if(contra,usuario).
					printf("Acceso denegado.\n");
					con_inicio=0;
				}
				}while (con_inicio==0); //Fin del ciclo de inicio de sesion.
				
				printf("Cancelar reservacion.\n");
				printf("Ingrese el numero de la fila del lugar que desea cancelar.\n");
				scanf("%d", &fila_cancelar);
				printf("Ingrese el numero del lugar que desea cancelar.\n");
				scanf("%d", &asiento_cancelar);
				distribucion[fila_cancelar-1][asiento_cancelar-1]=0;
				printf("Reservacion cancelada exitosamente.\n");
				bucle_principal=1;
			break; //Fin cancelar compra.
				
			case 4: //Coato total de los asientos reservados.
				cant_boletos_55=0;
				cant_boletos_89=0;
				cant_boletos_73=0;
				costo_total=0;
				//Calcula el total de los boletos reservados.
				for (i=0;i<3;i++){ //Boletos de $55.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_55=cant_boletos_55+1;
						}
					}
				}
				for (i=3;i<6;i++){ //Boletos de $89.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_89=cant_boletos_89+1;
						}
					}
				}
				for (i=6;i<9;i++){ //Boletos de $73.
					for(j=0;j<11;j++){
						if (distribucion[i][j]==1){
							cant_boletos_73=cant_boletos_73+1;
						}
					}
				}
				costo_total=((cant_boletos_55*55)+(cant_boletos_89*89)+(cant_boletos_73*73));
				printf("El costo total de los lugares reservados es: %d\n", costo_total);
				bucle_principal=1;
			break; //Fin calcular el costo total.
			
			case 5: //Salir del menu.
				bucle_principal=2;
			break;	//Fin salir del menu.
		} //Fin switch (Menu princiapl).
		
		if (bucle_principal==1){
		printf("Ingrese la opcion que desea.\n");
		printf("1. Menu principal\n");
		printf("2. Salir del menu\n");
		scanf("%d", &bucle_principal);	
		}
	}while(bucle_principal==1);
	printf("Saliendo...\n");

	return 0;
}
