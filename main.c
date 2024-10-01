#include <stdio.h>
#define ASIGNATURAS 3
#define ESTUDIANTES 5

int main()
{
    int numC = 0;
    int Aprobados = 0, NoAprobados = 0;
    float promT = 0;
    char nombres[5][20];
    char asignaturas[ASIGNATURAS][20] = {"Matematicas", "Ciencias", "Programacion"};
    for (int i = 0; i < 5; i++)
    {
        printf("Ingresa un nombre %d: ", i + 1);
        fgets(nombres[i], 20, stdin);
    }

    printf("Ingresa el numero de calificaciones que deseas>> ");

    while (scanf("%d", &numC) != 1)
    {
        printf("Error: Debe ingresar un numero válido.\n");

        while (getchar() != '\n')
        {
            printf("Por favor, ingrese un numero: ");
        }
    }

    /*Tabla de calificaciones*/
    float tabla[ASIGNATURAS][numC];

    for (int j = 0; j < ESTUDIANTES; j++)
    { // Bucle para repetir 5 veces

        int i2 = 0, i3 = 0;
        printf("-----------------------------------------------------------------\n");
        printf("Estudiante %s", nombres[j]);

        /*vectores de Maximos, Minimos y Promedios*/
        float Max[3] = {0, 0, 0};
        float Min[3] = {10, 10, 10};
        float Prom[3] = {0, 0, 0};

        /*Ingresar notas de las tres asignaturas*/
        do
        {
            for (int i = 0; i < numC; i++)
            {
                printf("\nIngresa la calificacion %d de (%s)>> ", i + 1, asignaturas[i2]);

                while (scanf("%f", &tabla[i2][i]) != 1)
                {
                    printf("Error: Debe ingresar un numero válido.\n");

                    while (getchar() != '\n')
                    {
                        printf("Por favor, ingrese un numero: ");
                    }

                    i--;
                }

                if (tabla[i2][i] < 0 || tabla[i2][i] > 10)
                {
                    printf("La calificacion es incorrecta\n");
                    i--;
                }
            }

            i2 += 1;

        } while (i2 < ASIGNATURAS);

        /*Calcular maximo, minimo y promedio de las Asignaturas */
        do
        {
            for (int i = 0; i < numC; i++)
            {
                if (tabla[i3][i] > Max[i3])
                {
                    Max[i3] = tabla[i3][i];
                }

                if (tabla[i3][i] < Min[i3])
                {
                    Min[i3] = tabla[i3][i];
                }

                Prom[i3] = Prom[i3] + tabla[i3][i];
            }

            Prom[i3] = Prom[i3] / numC;

            i3 += 1;

        } while (i3 < ASIGNATURAS);

        /*Calculo del promedio total*/
        promT = (Prom[0] + Prom[1] + Prom[2]) / ASIGNATURAS;
        printf("\nEl promedio total del estudiante es: %.2f\n", promT);

        /*Mostrar en pantalla el maximo,minimo y promedio del estudiante*/
        printf("______________________________\n");
        printf("Estudiante %s", nombres[j]);

        for (int i = 0; i < ASIGNATURAS; i++)
        {
            printf("\n(%s)\n", asignaturas[i]);
            printf("La calificacion mas alta es: %.2f\n", Max[i]);
            printf("La calificacion mas baja es: %.2f\n", Min[i]);
            printf("El promedio es: %.2f\n", Prom[i]);
        }

        if (promT >= 6)
        {
            printf("\nEl estudiante Aprobo con un promedio Total de: %.2f\n", promT);
            Aprobados += 1;
        }
        else
        {
            printf("\nEl estudiante No aprobo con un promedio Total de: %.2f\n", promT);
            NoAprobados += 1;
        }
    }

    printf("\n----------------------------------Estudiantes Aprobados y Reprobados----------------------------------\n");
    printf("\n");
    printf("Estudiantes Aprobados: %d\n", Aprobados);
    printf("Estudiantes No aprobados: %d\n", NoAprobados);
    printf("\n");
    return 0;
}
