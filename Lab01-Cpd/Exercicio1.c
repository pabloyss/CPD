#include <stdio.h>
void shellsort(int arr[], int num)
{
    int i, j, k, tmp;


    for (i = num / 2; i > 0; i = i / 2)
    {

        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
                // o incremento e como esta a lista
        printf("\n After increments of size of %d \n", i);
        for (k = 0; k < num; k++)
        printf("%d ", arr[k]);
    }
}


    void shellsortciura(int arr[], int num)
{
    int i, j, k, tmp, z, h = 701, gapsize=7;

    int gaps[] = {1,4,10,23,57,132,301,701};



    // Popula array
    while  (h < num)
    {
        gapsize++;
        h = h * 2.25;
        gaps[gapsize] = h;

    }

    for (z = gapsize; z >= 0; z--)
    {
        i = gaps[z];
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;

                }
            }

        }
        // o incremento e como esta a lista
        printf("\n After increments of size of %d \n", i);
        for (k = 0; k < num; k++)
        printf("%d ", arr[k]);

    }

}


int main()
{

    int arr[30];
    int k,  num;
    printf("Digite o total de elementos : ");
    scanf("%d", &num);
    printf("\nDigite a sequencia de numeros: ");

    for (k =  0 ; k < num; k++)
    {
        scanf("%d", &arr[k]);
    }
    //shellsort(arr, num);
    shellsortciura(arr,num);

    return 0;
}
