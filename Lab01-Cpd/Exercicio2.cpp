#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;


int binary_search (int a[], int low, int high, int key) {
	int mid;
	if (low == high)
		return low;
	mid = low + ((high-low)/2);
	if (key > a[mid])
		return binary_search(a, mid+1, high, key);
	else if (key < a [mid])
		return binary_search(a, low, mid, key);
	return mid;
}

void print_array(int C[], int tam) {
	printf("[");
	for (int i=0; i<tam-1; i++) {
		printf("%d, ", C[i]);
	}
	printf("%d]", C[tam-1]);
}

void binary_insertion_sort(int C[], int tam, int print_ok) {
	long changes = 0;
	int i, j, chave;
	int ins;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}
	for (j=1; j<tam; j++) {
		ins = binary_search(C, 0, j, C[j]);
		chave = C[j];
		for (int k=j-1; k>=ins; k--) {
			C[k+1] = C[k];
			changes++;
		}
		C[ins]=chave;
	}
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nInsertion Sort Binary Search of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval*1000);
}

void shell_insertion_sort_ciura(int arr[], int num, int print_ok) {

    int i, j, k, tmp, z, gapsize = 7;
    long changes = 0, h = 701;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    int gaps[] = {1,4,10,23,57,132,301,701};

    // Popula array
    while  (h < num)
    {
        h = h * 2.25;
        if(h < num){
        gapsize++;
        gaps[gapsize] = h;
    }}


    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    if (print_ok) {
		printf("\nArray before:");
		print_array(arr, num);
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
                    changes++;
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;

                }
            }
        }
    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(arr, num);
	}
	printf("\nCiura Sort of %d elements: #changes = %ld - time = %10.4Lf ms", num, changes, interval*1000);

}

void insertion_sort(int C[], int tam, int print_ok) {
	long changes = 0;
	int i, j, chave;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

	if (print_ok) {
		printf("\nArray before:");
		print_array(C, tam);
	}
	for (j=1; j<tam; j++) {
		chave = C[j];
		i = j-1;
		while ((i>=0) && C[i]>chave) {
			C[i+1] = C[i];
			i--;
			changes++;
		}
		C[i+1]=chave;
	}
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(C, tam);
	}
	printf("\nInsertion Sort of %d elements: #changes = %ld - time = %10.4Lf ms", tam, changes, interval*1000);
}

void shell_insertion_sort(int arr[], int num, int print_ok){
	long changes = 0;
	int i, j,k , chave, tmp;
	int ins;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

	if (print_ok) {
		printf("\nArray before:");
		print_array(arr, num);
	}
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
                    changes++;
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;

                }
            }
        }
    }
    QueryPerformanceCounter(&end);
    interval = (double) (end.QuadPart - start.QuadPart) / frequency.QuadPart;

	if (print_ok) {
		printf("\nArray after:");
		print_array(arr, num);
	}
	printf("\nShell of %d elements: #changes = %ld - time = %10.4Lf ms", num, changes, interval*1000);
}

void copy_array (int* array_origem, int* array_destino, int size) {
	for (int i=0; i< size; i++) array_destino [i] = array_origem [i];
}
#define SIZE1 100
#define SIZE2 1000
#define SIZE3 10000

#define NSIZES 3

int main(){
	int arr1[10]={12,2,5,4,8,7,6,9,1,15};
	int arr2[10]={1,2,3,4,5,6,7,8,9,10};
	int arr3[10]={10,9,8,7,6,5,4,3,2,1};

	int arr_sizes[NSIZES] = {SIZE1, SIZE2, SIZE3};
	int arr_origem[SIZE3];
	int arr_destino[SIZE3];

	shell_insertion_sort(arr1, 10, 1);
	shell_insertion_sort(arr2, 10, 1);
	shell_insertion_sort(arr3, 10, 1);

	// Generate test arrays
	for (int j=0; j<NSIZES; j++) {
		int size = arr_sizes[j];
		for (int i=0; i<size; i++) arr_origem[i]=rand()%size+1;	// arr_size1[i] = SIZE1-i;
		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Insertion Sort\n" << flush;
		insertion_sort(arr_destino, size, 0);
		cout << "\nEnd Insertion Sort" << flush;

		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Binary Insertion Sort\n" << flush;
		binary_insertion_sort(arr_destino, size, 0);
		cout << "\nEnd Insertion Sort" << flush;

		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Shell Sort\n" << flush;
		shell_insertion_sort(arr_destino, size, 0);
		cout << "\nEnd Shell Sort" << flush;

		copy_array(arr_origem, arr_destino, size);
		cout << "\nStarting Shell Sort Ciura\n" << flush;
		shell_insertion_sort_ciura(arr_destino, size, 0);
		cout << "\nEnd Shell Sort" << flush;




	}


	for (int i=0; i<SIZE1; i++) arr_sizes[i]=rand()%SIZE1+1;
	for (int i=0; i<SIZE2; i++) arr_sizes[i]=rand()%SIZE2+1;
	for (int i=0; i<SIZE3; i++) arr_sizes[i]=rand()%SIZE3+1;

	copy_array(arr_origem, arr_destino, SIZE1);
	shell_insertion_sort(arr_sizes, SIZE1, 0);
	printf("\n\n");
}
