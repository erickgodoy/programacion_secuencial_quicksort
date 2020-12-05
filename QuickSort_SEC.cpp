#include <iostream>
#include <time.h>

#define dimension 1500

using namespace std;

void quicksort(int A[], int limIzq, int limDer){
    int izq, der, pibot, aux;
    izq = limIzq;
    der = limDer;
    pibot = A[(limIzq + limDer) / 2];
    do {
        while ((A[izq] < pibot) && (der <= limDer)){
            izq++;
        }
        while ((pibot < A[der]) && (der > limIzq)){
            der--;
        }
        if (izq <= der){
            aux = A[izq]; A[izq] = A[der]; A[der] = aux;
            izq++;  der--;
        }
    }while (izq <= der);
    if (limIzq < der)
        quicksort(A, limIzq, der);
    if (izq < limDer)
        quicksort(A, izq, limDer);
}

int main(){
    unsigned t0, t1;
    t0 = clock();
    int *A, i;
    A = new int [dimension];
    srand(time(NULL));
    for (i = 0; i < dimension; i++)   {
        *(A+i) = 1 + rand() % (100);
    }
    for (i = 0; i < dimension; i++)    {
        cout << A[i] << " ";
    }
    cout << endl;
    quicksort(A, 0, dimension - 1);
    for (i = 0; i < dimension; i++)    {
        cout << A[i] << " ";
    }
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "\nTiempo de Ejecucion: " << time << endl;
    return 0;
}