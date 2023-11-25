#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Tareas
{
    char titulo[50];
    int completada;  // 0 para pendiente, 1 para completada
};

int agregar_tarea(struct Tareas tarea[], int total_tareas)
{
    if (total_tareas < 100)
    {
        printf("Ingrese el titulo de la tarea: ");
        scanf("%s", tarea[total_tareas].titulo);
        tarea[total_tareas].completada = 0;
        total_tareas++;
        printf("Tarea agregada con exito. \n");
        printf("\n");
    }
    else
    {
        printf("Se ha alcanzado el maximo de tareas. \n");
        printf("\n");
    }
    return total_tareas;
}

void marcar_completada(struct Tareas tarea[], int total_tareas)
{
    int opcion;
    printf("Ingrese el numero de la tarea a marcar como completada: ");
    scanf("%d", &opcion);

    opcion--;

    if (opcion >= 0 && opcion < total_tareas)
    {
        tarea[opcion].completada = 1;
        printf("Tarea marcada como completada. \n");
        printf("\n");
    }
    else
    {
        printf("Numero de tarea invalido. \n");
        printf("\n");
    }
}

void mostrar_tareas_pendientes(struct Tareas tarea[], int total_tareas)
{
    int pendientes = 0;

    printf("Tareas pendientes: \n");

    for (int i = 0; i < total_tareas; i++)
    {
        if (tarea[i].completada == 0)
        {
            printf("Tarea %d: \n", pendientes + 1);
            printf("Titulo: %s \n", tarea[i].titulo);
            printf("Estado: Pendiente \n");
            printf("\n");
            pendientes++;
        }
    }

    if (pendientes == 0)
    {
        printf("No hay tareas pendientes. \n");
        printf("\n");
    }
}

void mostrar_tareas(struct Tareas tarea[], int total_tareas)
{
    if (total_tareas == 0)
    {
        printf("No hay tareas para mostrar. \n");
        printf("\n");
        return;
    }

    printf("\n");
    printf("Lista de tareas: \n");
    printf("\n");

    for (int i = 0; i < total_tareas; i++)
    {
        printf("Tarea %d: \n", i + 1);
        printf("Titulo: %s \n", tarea[i].titulo);
        printf("Estado: %s \n", tarea[i].completada ? "Completada" : "Pendiente");
        printf("\n");
    }
}

void buscar_tarea(struct Tareas tarea[], int total_tareas, char titulo[], int indice)
{
    if(indice >= total_tareas)
    {
        printf("No se encontro la tarea con el titulo: %s\n", titulo);
        printf("\n");
        return;
    }

    if(strcmp(tarea[indice].titulo, titulo) == 0)
    {
        printf("Tarea encontrada en el indice: %d\n", indice);
        printf("Titulo: %s\n", tarea[indice].titulo);
        printf("Estado: %s\n", tarea[indice].completada ? "Completada" : "Pendiente");
        printf("\n");
        return;
    }

    buscar_tarea(tarea, total_tareas, titulo, indice + 1);
}


void menu_opciones(struct Tareas tarea[], int *total_tareas)
{
    int opcion = 0;
    char titulo[50];

    printf("Bienvenido al Sistema de Gestion de Tareas! \n");
    printf("\n");
    while (opcion != 6)
    {
        printf("1-Agregar una tarea. \n");
        printf("2-Marcar una tarea como completada. \n");
        printf("3-Listar todas las tareas pendientes. \n");
        printf("4-Listar todas las tareas. \n");
        printf("5-Buscar una tarea por titulo. \n");
        printf("6-Salir. \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                *total_tareas = agregar_tarea(tarea, *total_tareas);
                break;
            case 2:
                marcar_completada(tarea, *total_tareas);
                break;
            case 3:
                mostrar_tareas_pendientes(tarea, *total_tareas);
                break;
            case 4:
                mostrar_tareas(tarea, *total_tareas);
                break;
            case 5:
                printf("Ingrese el título de la tarea a buscar: ");
                scanf("%s", titulo);
                buscar_tarea(tarea, *total_tareas, titulo, 0);
                break;
            case 6:
                printf("Saliendo del programa. \n");
                printf("\n");
                break;
            default:
                printf("Opcion invalida. \n");
                printf("\n");
        }
    }
}

#endif // FUNCTIONS_H_INCLUDED
