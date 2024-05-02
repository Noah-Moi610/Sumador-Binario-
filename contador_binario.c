// Noé Moisés Galindo Leal 
// Se incluye las librerias 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Se define los estados 
#define ESTADO_INICIAL 0
#define ESTADO_ACARREO 1
#define NUM_ESTADOS 2
#define NUM_SIMBOLOS 4

// Tabla de estado siguiente 
int transiciones[NUM_ESTADOS][NUM_SIMBOLOS] =
{
    {0, 0, 0, 1},
    {1, 0, 0, 1},
};

int salidas[NUM_ESTADOS][NUM_SIMBOLOS] =
{
    {0, 1, 1, 0},
    {1, 0, 0, 1},
};

bool esEstadoFinal(int estado) {
    return estado == ESTADO_ACARREO;
}

int obtenerIndiceResultados(char entrada[]) {
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

char* sumarCadenasBinarias(char cadena1[], char cadena2[]) {
    // Estado inicial del sumador
    int estadoActual = ESTADO_INICIAL;
    int longitud = strlen(cadena1);
    char* resultados = (char*)malloc((longitud + 2) * sizeof(char)); 
    if (resultados == NULL) {
        printf("Error: No se pudo asignar memoria para los resultados.\n");
        return NULL;
    }
    // Verificar si las cadenas tienen la misma longitud
    if (strlen(cadena1) != strlen(cadena2)) {
        printf("Las cadenas tienen longitudes diferentes.\n");
        free(resultados);
        return NULL;
    }
    // Inicializar el acarreo en cero
    int acarreo = 0;
    int indiceResultado = 0;
    
    // Recorrer cada bit de las cadenas de entrada
    for (int i = longitud - 1; i >= 0; i--) {
        // Convertir los caracteres de las cadenas a enteros
        int bit1 = cadena1[i] - '0';
        int bit2 = cadena2[i] - '0';
        
        // Calcular la suma de los bits y el acarreo
        int suma = bit1 + bit2 + acarreo;
        resultados[indiceResultado++] = suma % 2 + '0'; 
        acarreo = suma / 2; 
    }
    
    // Si hay acarreo restante, agregarlo al resultado
    if (acarreo > 0) {
        resultados[indiceResultado++] = '1'; // Agregar el acarreo al resultado
    }
    
    resultados[indiceResultado] = '\0'; // Agregar el terminador de cadena
    
    // Invertir el orden de los bits en el resultado final
    int i = 0;
    int j = indiceResultado - 1;
    while (i < j) {
        char temp = resultados[i];
        resultados[i] = resultados[j];
        resultados[j] = temp;
        i++;
        j--;
    }
    return resultados;
}

int main() {
    // se ingresa cadenas
    char cadena1[100], cadena2[100];
    printf("Ingrese la primera cadena de bits '1's y '0's: ");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena de bits '1's y '0's: ");
    scanf("%s", cadena2);

    //Sumar las cadenas 
    char *suma = sumarCadenasBinarias(cadena1, cadena2);

// Se pone un "if" para validar la cadena
    if (suma != NULL) {
        printf("La suma de las dos cadenas es. %s\n", suma);
        free(suma);
    } else {
        printf("El resultado no es valido. \n");
    }
    return 0;
}