#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    struct Tareas tarea[100];
    int total_tareas = 0;

    menu_opciones(tarea, &total_tareas);

    return 0;
}
