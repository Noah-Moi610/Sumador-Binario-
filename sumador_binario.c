// Máquina de estado finito, sumador binario
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ESTADO_INICIAL 0
#define ESTADO_ACARREO 1
#define NUM_ESTADOS 2
#define NUM_SIMBOLOS 4

// Tabla de estado siguiente 
int transiciones[NUM_ESTADOS][NUM_SIMBOLOS] = 
{
    {0, 0, 0, 1}, // q1
    {0, 1, 1, 1}, // q2
};
 // Tabla de salidas 
char salidas[NUM_ESTADOS][NUM_SIMBOLOS] =
{
    {'0', '1', '1', '0'}, // q1
    {'1', '0', '0', '1'}, // q2
};

bool esEstadoFinal(int estado) {
    return estado == ESTADO_INICIAL;
}

// Oden de las columnas de las matrices
int obtenerIndice(char entrada[]) {
    if (strcmp(entrada, "00") == 0)
        return 0;
    if (strcmp(entrada, "01") == 0)
        return 1;
    if (strcmp(entrada, "10") == 0)
        return 2;
    if (strcmp(entrada, "11") == 0)
        return 3;
    return -1;
}

char* sumarBits(char cadena1[], char cadena2[]) {

    //Asumimos la misma longitud en ambas cadenas
    int longitud = strlen(cadena1);
    int estadoActual = ESTADO_INICIAL;
    char resultado[100];
    int k;
    int longitudTemp = sizeof(resultado);
    for (k = 0; k < longitud + 2; k++){
        resultado[k]= '0';
    }
    resultado[k] = '\0';
    char entrada[3];
    int i;
    int temp = strlen(resultado) - 1;
    for (i = longitud - 1; i >= 0; i-- , temp--) {
        entrada[0] = cadena1[i];
        entrada[1] = cadena2[i];
        entrada[2] = '\0';
        int indiceEntrada = obtenerIndice(entrada);
        int siguienteEstado = transiciones[estadoActual][indiceEntrada];
        int salida = salidas[estadoActual][indiceEntrada];
        resultado[temp] = salida;
        estadoActual = siguienteEstado;
    }
    
    if (estadoActual == ESTADO_ACARREO) {
        resultado[temp] = '1';
    } else {
        resultado[temp] = '0';
    }
    printf("SUMA: %s \n",resultado);
    return resultado;
}

int main() {

    // Se ingresa cadenas
    char cadena1[100], cadena2[100];
    printf("Ingrese la primera cadena de bits '1's y '0's: ");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena de bits '1's y '0's: ");
    scanf("%s", cadena2);

    //Sumar las cadenas 
    char *resultado = sumarBits(cadena1, cadena2);
    //printf("SUMA: %s \n",resultado);
    free(resultado);

}
