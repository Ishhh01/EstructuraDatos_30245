#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nombre[50];
    float nota;
} Estudiante;

/* Lee una linea sin salto de linea final */
void leerTexto(const char *msg, char *dest, int tam) {
    printf("%s", msg);
    fgets(dest, tam, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

int leerEntero(const char *msg) {
    char buf[32];
    leerTexto(msg, buf, sizeof(buf));
    return atoi(buf);
}

float leerFloat(const char *msg) {
    char buf[32];
    leerTexto(msg, buf, sizeof(buf));
    return (float)atof(buf);
}

void mostrar(const Estudiante *e) {
    printf("  Codigo: %d | Nombre: %-20s | Nota: %.2f\n", e->codigo, e->nombre, e->nota);
}

/* Devuelve puntero al estudiante con ese codigo, o NULL */
Estudiante *buscar(Estudiante *lista, int n, int codigo) {
    Estudiante *p;
    for (p = lista; p < lista + n; p++)
        if (p->codigo == codigo) return p;
    return NULL;
}

void agregar(Estudiante **lista, int *n) {
    int codigo = leerEntero("Codigo: ");
    if (buscar(*lista, *n, codigo)) {
        printf("Ya existe un estudiante con ese codigo.\n");
        return;
    }
    Estudiante *tmp = realloc(*lista, (*n + 1) * sizeof(Estudiante));
    if (!tmp) {
        printf("Sin memoria.\n");
        return;
    }
    *lista = tmp;
    Estudiante *nuevo = *lista + *n;
    nuevo->codigo = codigo;
    leerTexto("Nombre: ", nuevo->nombre, sizeof(nuevo->nombre));
    nuevo->nota = leerFloat("Nota: ");
    (*n)++;
    printf("Estudiante agregado.\n");
}

void listar(Estudiante *lista, int n) {
    if (n == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    for (Estudiante *p = lista; p < lista + n; p++) mostrar(p);
}

void buscarYMostrar(Estudiante *lista, int n) {
    Estudiante *e = buscar(lista, n, leerEntero("Codigo a buscar: "));
    if (e) mostrar(e);
    else printf("No encontrado.\n");
}

void modificar(Estudiante *lista, int n) {
    Estudiante *e = buscar(lista, n, leerEntero("Codigo a modificar: "));
    if (!e) {
        printf("No encontrado.\n");
        return;
    }
    leerTexto("Nuevo nombre: ", e->nombre, sizeof(e->nombre));
    e->nota = leerFloat("Nueva nota: ");
    printf("Estudiante modificado.\n");
}

void eliminar(Estudiante **lista, int *n) {
    Estudiante *e = buscar(*lista, *n, leerEntero("Codigo a eliminar: "));
    if (!e) {
        printf("No encontrado.\n");
        return;
    }
    Estudiante *fin = *lista + *n - 1;
    for (; e < fin; e++) *e = *(e + 1); /* desplaza elementos */
    (*n)--;
    if (*n == 0) {
        free(*lista);
        *lista = NULL;
    } else {
        Estudiante *tmp = realloc(*lista, *n * sizeof(Estudiante));
        if (tmp) *lista = tmp;
    }
    printf("Estudiante eliminado.\n");
}

void promedio(Estudiante *lista, int n) {
    if (n == 0) {
        printf("No hay estudiantes registrados.\n");
        return;
    }
    float suma = 0;
    Estudiante *mayor = lista;
    for (Estudiante *p = lista; p < lista + n; p++) {
        suma += p->nota;
        if (p->nota > mayor->nota) mayor = p;
    }
    printf("Promedio: %.2f\nMejor nota:\n", suma / n);
    mostrar(mayor);
}

int main(void) {
    Estudiante *lista = NULL;
    int n = 0, opcion;

    do {
        printf("\n===== MENU ESTUDIANTES =====\n");
        printf("1. Agregar\n2. Listar\n3. Buscar por codigo\n4. Modificar\n");
        printf("5. Eliminar\n6. Promedio y mejor nota\n0. Salir\n");
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: agregar(&lista, &n); break;
            case 2: listar(lista, n); break;
            case 3: buscarYMostrar(lista, n); break;
            case 4: modificar(lista, n); break;
            case 5: eliminar(&lista, &n); break;
            case 6: promedio(lista, n); break;
            case 0: printf("Hasta luego.\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    free(lista);
    return 0;
}
