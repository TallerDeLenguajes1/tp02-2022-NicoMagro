#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 2

struct compu {
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu; //valores del arreglo tipos
}typedef compu;

void mostrar(compu *pcompu);

void mostrarMasVieja(compu *pcompu);

void mostrarMayorVelocidad(compu *pcompu);


int main(){
    srand(time(NULL));

    int k;
    compu *pcompu;
    pcompu = malloc(MAX*sizeof(compu));

    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    printf("Cargue los datos de la computadora a registrar: \n\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("DATOS COMPUTADORA %d\n", i+1);
        printf("Velocidad de la computadora(entre 1 y 3): ");
        scanf("%d",&pcompu->velocidad);
        while(pcompu->velocidad > 3)
        {
            printf("Valor no valido, ingresar nuevamente: ");
            scanf("%d",&pcompu->velocidad);
        }
        
        printf("Anio de la computadora(entre 2015 y 2022): ");
        scanf("%d",&pcompu->anio);
        while(pcompu->anio > 2022 || pcompu->anio < 2015)
        {
            printf("Valor no valido, ingresar nuevamente: ");
            scanf("%d",&pcompu->anio);
        }
        printf("Cantidad de nucleos del procesador: ");
        scanf("%d",&pcompu->cantidad);
        while (pcompu->cantidad > 8)
        {
            printf("Valor no valido, ingresar nuevamente: ");
            scanf("%d",&pcompu->cantidad);
        }

        printf("Tipo de procesador(Valores entre 0 y 5): ");
        scanf("%d", &k);
        while (k<0 || k>5)
        {
            printf("Valor no valido, ingresar nuevamente: ");
            scanf("%d",&pcompu->tipo_cpu);
        }
        
        pcompu->tipo_cpu = tipos[k];

        pcompu++;
    }
    pcompu -= MAX;

    mostrar(pcompu);

    mostrarMasVieja(pcompu);

    mostrarMayorVelocidad(pcompu);

    return 0;
}

void mostrar(compu *pcompu){

    printf("==================Muestra de datos==================\n\n");

    for (int i = 1; i <= MAX; i++)
    {
        printf("============DATOS COMPUTADORA %i==============\n", i);
        printf("Velocidad: %d\n", pcompu->velocidad);
        printf("Anio: %d\n", pcompu->anio);
        printf("Nucleo: %d\n", pcompu->cantidad);
        printf("Tipo de procesador: %s\n", pcompu->tipo_cpu);
        pcompu++;
    }
    
}

void mostrarMasVieja(compu *pcompu){
    int vieja = 2022, numCompuVieja = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (pcompu->anio < vieja)
        {
            vieja = pcompu->anio;
            numCompuVieja = i+1;
        }
        pcompu++;
    }
    printf("\n\nLa computadora mas vieja es la computadora: %d\n El anio de la computadora mas vieja es: %d\n", numCompuVieja, vieja);
}

void mostrarMayorVelocidad(compu *pcompu){
    int veloz = 0, numCompuVeloz = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (pcompu->velocidad > veloz)
        {
            veloz = pcompu->velocidad;
            numCompuVeloz = i+1;
        }
        pcompu++;
    }
    printf("\n\nLa computadora mas veloz es la computadora: %d\n La velocidad de la compu mas veloz es: %d\n", numCompuVeloz, veloz);
}