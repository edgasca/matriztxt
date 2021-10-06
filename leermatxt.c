#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3][3], contador=0, arreglo[(3*3)], temp=0;
    int frecuencia=0, moda=0;
    FILE *archivo;
    archivo=fopen("matriz.txt", "r");
    //Pasar el archivo de texto a la Matriz
    for(int i=0; !feof(archivo); i++)
        for (int j= 0;!feof(archivo); j++)
        {
            fscanf(archivo,"%d", &x[i][j]);
        }
    fclose(archivo);
    
    for(int i=0;i<3; i++)
            for (int j=0; j<3; j++)
            {
             arreglo[contador]=x[i][j];
             contador++;
            }
    for(int k=0; k<9;k++)
        printf("Arreglo [%d]= %d \n", k, arreglo[k]);

    for(int i=0;i<3; i++)
        for (int j=i+1; j<3; j++)
            if (arreglo[i]>arreglo[j])
                {
                    temp=arreglo[i];
                    arreglo[i]=arreglo[j];
                    arreglo[j]=temp;
                }
    
    
    contador=1;

    for(int i=0;i<9; i++)
    {
        for (int j=0; j<9; j++)
            {
                if(arreglo[i]==arreglo[j])
                {
                    contador++;
                    
                    if(contador>frecuencia)
                    {
                    frecuencia= contador;
                    moda= arreglo[j];
                    }
                }
            }
        contador=1;
    }
            

    printf("MODA: %d \n", moda);
    return 0;
}