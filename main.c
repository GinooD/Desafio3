#include <stdio.h>

#define MAX 10

/* Intercambia dos enteros usando punteros */
void intercambiar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/* Mostrar entradas cargadas */
void mostrarEntradas(int numeros[], int dias[], int cantidad) {
    int i;
    if (cantidad == 0) {
        printf("\n[AVISO] No hay entradas cargadas.\n");
        return;
    }

    printf("\n--- ENTRADAS REGISTRADAS ---\n");
    for (i = 0; i < cantidad; i++) {
        printf("Entrada #%d | Dias vencimiento: %d | Estado: %s\n",
               numeros[i],
               dias[i],
               (dias[i] > 0) ? "ACTIVA" : "VENCIDA");
    }
}

/* Agregar entrada validando dias > 0 */
void agregarEntrada(int numeros[], int dias[], int *pCant) {
    int num, d;

    if (*pCant >= MAX) {
        printf("\n[ERROR] Se alcanzo el maximo de entradas.\n");
        return;
    }

    printf("\nIngrese el numero de entrada: ");
    scanf("%d", &num);

    printf("Ingrese los dias para el vencimiento: ");
    scanf("%d", &d);

    if (d <= 0) {
        printf("[ERROR] Los dias para el vencimiento deben ser mayores a 0.\n");
        return;
    }

    numeros[*pCant] = num;
    dias[*pCant] = d;
    (*pCant)++;
    printf("[OK] Entrada agregada correctamente.\n");
}

/* Actualizar dias de una entrada */
void actualizarEntrada(int numeros[], int dias[], int cantidad) {
    int buscado, nuevosDias, i, pos = -1;

    if (cantidad == 0) {
        printf("\n[AVISO] No hay entradas para actualizar.\n");
        return;
    }

    printf("\nIngrese el numero de entrada a actualizar: ");
    scanf("%d", &buscado);

    for (i = 0; i < cantidad; i++) {
        if (numeros[i] == buscado) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("[ERROR] No se encontro la entrada #%d.\n", buscado);
        return;
    }

    printf("Ingrese los nuevos dias para el vencimiento: ");
    scanf("%d", &nuevosDias);

    if (nuevosDias <= 0) {
        printf("[ERROR] Los dias deben ser mayores a 0.\n");
        return;
    }

    dias[pos] = nuevosDias;
    printf("[OK] Entrada #%d actualizada.\n", buscado);
}

/* Eliminar entrada corriendo los elementos hacia la izquierda */
void eliminarEntrada(int numeros[], int dias[], int *pCant) {
    int buscado, i, pos = -1;

    if (*pCant == 0) {
        printf("\n[AVISO] No hay entradas para eliminar.\n");
        return;
    }

    printf("\nIngrese el numero de entrada a eliminar: ");
    scanf("%d", &buscado);

    for (i = 0; i < *pCant; i++) {
        if (numeros[i] == buscado) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("[ERROR] No se encontro la entrada #%d.\n", buscado);
        return;
    }

    for (i = pos; i < *pCant - 1; i++) {
        numeros[i] = numeros[i + 1];
        dias[i] = dias[i + 1];
    }

    (*pCant)--;
    printf("[OK] Entrada #%d eliminada.\n", buscado);
}

int main(void) {
    int numeros[MAX];
    int dias[MAX];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n=== GESTION DE ENTRADAS (PASO 1) ===\n");
        printf("1. Agregar entrada\n");
        printf("2. Actualizar entrada\n");
        printf("3. Eliminar entrada\n");
        printf("4. Mostrar entradas\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEntrada(numeros, dias, &cantidad);
                break;
            case 2:
                actualizarEntrada(numeros, dias, cantidad);
                break;
            case 3:
                eliminarEntrada(numeros, dias, &cantidad);
                break;
            case 4:
                mostrarEntradas(numeros, dias, cantidad);
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\n[ERROR] Opcion invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
