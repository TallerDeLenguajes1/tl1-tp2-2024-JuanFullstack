#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definición de la estructura para representar una PC
struct compu {
    int velocidad;          // velocidad de procesamiento en GHz (entre 1 y 3)
    int anio;               // año de fabricación (entre 2015 y 2023)
    int cantidad;           // cantidad de núcleos (entre 1 y 8)
    char *tipo_cpu;         // tipo de procesador
};

// Declaraciones de las funciones
void presentarPCs(struct compu *pcs, int num_pcs);
void pcMasVieja(struct compu *pcs, int num_pcs);
void pcMayorVelocidad(struct compu *pcs, int num_pcs);

int main() {

    system("cls");

    srand(time(NULL));

    // Arreglo de tipos de CPU
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    // Arreglo de estructuras para almacenar las características de las PCs
    struct compu pcs[5];

    // Inicialización de las PCs con valores aleatorios
    for (int i = 0; i < 5; i++) {
        pcs[i].velocidad = 1 + rand() % 3;           // entre 1 y 3 GHz
        pcs[i].anio = 2015 + rand() % 9;             // entre 2015 y 2023
        pcs[i].cantidad = 1 + rand() % 8;            // entre 1 y 8 núcleos
        pcs[i].tipo_cpu = tipos[rand() % 6];         // tipo de CPU aleatorio del arreglo tipos
    }

    // Presentación de la lista de las PCs
    presentarPCs(pcs, 5);

    // PC más vieja
    pcMasVieja(pcs, 5);

    // PC con mayor velocidad
    pcMayorVelocidad(pcs, 5);

    return 0;
}

// Función para presentar la lista de las PC
void presentarPCs(struct compu *pcs, int num_pcs) {
    printf("Lista de PCs:\n");
    for (int i = 0; i < num_pcs; i++) {
        printf("PC %d:\n", i+1);
        printf("Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricacion: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad);
        printf("Tipo de CPU: %s\n\n", pcs[i].tipo_cpu);
    }
}

// Función para encontrar la PC más vieja
void pcMasVieja(struct compu *pcs, int num_pcs) {
    int anio_viejo = pcs[0].anio; // inicializamos con el primer año
    int posicionI = 0;

    for (int i = 1; i < num_pcs; i++) {
        if (pcs[i].anio < anio_viejo) {
            anio_viejo = pcs[i].anio;
            posicionI = i;
        }
    }
    printf("La PC mas vieja es la siguiente:\n");
    printf("Anio de fabricacion: %d\n", pcs[posicionI].anio);
    printf("Tipo de CPU: %s\n\n", pcs[posicionI].tipo_cpu);
}

// Función para encontrar la PC con mayor velocidad
void pcMayorVelocidad(struct compu *pcs, int num_pcs) {
    int velocidad_max = pcs[0].velocidad; // inicializamos con la velocidad de la primera PC
    int posicionI = 0;

    for (int i = 1; i < num_pcs; i++) {
        if (pcs[i].velocidad > velocidad_max) {
            velocidad_max = pcs[i].velocidad;
            posicionI = i;
        }
    }
    printf("La PC con mayor velocidad es la siguiente:\n");
    printf("Velocidad: %d GHz\n", pcs[posicionI].velocidad);
    printf("Tipo de CPU: %s\n\n", pcs[posicionI].tipo_cpu);
}