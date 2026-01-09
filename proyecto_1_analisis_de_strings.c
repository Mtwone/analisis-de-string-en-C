#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contPalabras(char s[],int cantcar);
void contVocales(char s[], int cancar);

void encriptar(char s[]);
void invertir(char s[],int cantCar);

int main(void){

int numeroMenu = 0;
char *arr = NULL;
int cantidadCaracteres = 0;
puts("--Programa sobre analisis en cadenas de texto--");

puts("cuantos caracteres espera ingresar: ");
scanf("%d",&cantidadCaracteres);
getchar();

arr =(char *) malloc((cantidadCaracteres + 1)*sizeof(char));

if(arr == NULL){
	puts("error al asignar memoria");
	return 1;
}

puts("ingrese un texto para ser analizado: ");
fgets(arr,(cantidadCaracteres + 1),stdin);
arr[strcspn(arr,"\n")]= '\0';

puts("digite un numero segun la operacion para aplicar al texto: ");
puts("  |1-analisis del conteo del texto \n  |2-encriptar texto\n  |3-invertir texto\n  |4-salir\n");
scanf("%d",&numeroMenu);
puts("-------------");
switch(numeroMenu){

	case 1:
	
	contPalabras(arr,cantidadCaracteres);
	contVocales(arr,cantidadCaracteres);
		break;
	case 2:

	encriptar(arr);
		break;
	case 3:

	invertir(arr,cantidadCaracteres);
		break;
	case 4:
		return 0;
		break;
	default:
		puts("digite un numero segun la operacion a realizar");
		break;
}
free (arr);

}

void contPalabras(char s[],int cantcar){

	int contadorPalabras = 0;	
	int switchBool = 0;
	char *aux = s;

	for(;*aux != '\0';aux++){

		if(*aux != '\n' && *aux != ' ' && *aux != '\t'){

			if(switchBool == 0){
				contadorPalabras++;
				switchBool = 1;
			}
		}else{
			switchBool = 0;	
		}
	}
	
		printf("la cantidad de palabras del texto son: %d \n",contadorPalabras);
		printf("la longitud total de el texto contando caracteres y espacios es de: %d\n",(aux-s));
}

void contVocales(char s[],int cantcar){

	int contadorVocales = 0;
	char *aux = s;

	for(;*aux != '\0';aux++){

	char car = *aux | 32;
		if(car == 'a' || car == 'e' || car == 'i' || car == 'o'|| car == 'u'){
			contadorVocales++;
		}

	}
	printf("la cantidad de vocales en el texto son: %d \n",contadorVocales);
}

void encriptar(char s[]){

	char *aux = s;
	
	printf("texto original: \n%s\n",s);

	for(;*aux != '\0';aux++){

	*aux += 3;	
	}
	
	puts("texto encriptado: ");
	printf("%s\n",s);


}

void invertir(char s[],int cantCar){

	int longitud = strlen(s);
	char *aux = s+longitud;

	for(int j = 0,i = (longitud-1);j<= (longitud-1),i>=0;j++,i--){

		aux[i] = s[j];
	}

	printf("%s\n",aux);

}
