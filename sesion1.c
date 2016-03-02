#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/sem.h>
#include <unistd.h>

int calcular_longitud(int num);
long elevar(int num1, int num2);

int main(){
	
	int hijo1, hijo2, hijo3, hijo4;
	float somnolencia;
	int mi_pid, longitud;
	long dividir;


	hijo1 = fork();
	switch(hijo1){
		case -1:
			perror("Ha ocurrido un error al crear el Hijo 1");
		break;
		case 0:
			/*Hijo 1*/
			mi_pid = getpid();
			longitud = calcular_longitud(mi_pid);
			dividir = elevar(10, longitud - 1);
			somnolencia = (mi_pid / dividir) + 1;
			printf("## 1 ## Mi somnolencia es: %d, mi pid es: ", somnolencia, mi_pid);
		break;
		default:
			hijo2 = fork();
			switch(hijo2){
				case -1:
					perror("Ha ocurrido un error al crear el Hijo 2");
				break;
				case 0:
					/*Hijo 2*/
					mi_pid = getpid();
					longitud = calcular_longitud(mi_pid);
					dividir = elevar(10, longitud - 1);
					somnolencia = (mi_pid / dividir) + 1;
					printf("## 2 ## Mi somnolencia es: %d, mi pid es: ", somnolencia, mi_pid);
				break;
				default:
					hijo3 = fork();
					switch(hijo3){
						case -1:
							perror("Ha ocurrido un error al crear el Hijo 3");
						break;
						case 0:
							/*Hijo 3*/
							mi_pid = getpid();
							longitud = calcular_longitud(mi_pid);
							dividir = elevar(10, longitud - 1);
							somnolencia = (mi_pid / dividir) + 1;
							printf("## 3 ## Mi somnolencia es: %d, mi pid es: ", somnolencia, mi_pid);
						break;
						default:
							hijo4 = fork();
							switch(hijo4){
								case -1:
									perror("Ha ocurrido un error error al crear el Hijo 4");
								break;
								case 0:
									/*Hijo 4*/
									mi_pid = getpid();
									longitud = calcular_longitud(mi_pid);
									dividir = elevar(10, longitud - 1);
									somnolencia = (mi_pid / dividir) + 1;
									printf("## 4 ## Mi somnolencia es: %d, mi pid es: ", somnolencia, mi_pid);
								break;
								default:

								break;
							}
						break;
					}
				break;
			}
		break;
	}

	return(0);
}

int calcular_longitud(int num){
	int cont = 0;

	while(num / 10 > 0){
		cont++;
	}

	return cont;
}


long elevar(int num1, int num2){
	long resultado = 1;

	for(int x = 0; x<num2; x++){
		resultado *= num1;
	}

	return resultado;
}