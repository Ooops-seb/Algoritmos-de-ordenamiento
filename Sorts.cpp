/*Aplicacion de algoritmos de ordenamiento
Nombre: Erik Villarreal
Fecha: 15 de diciembre 2022
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void menu();
void create();
void sort();
void show();
void create_random(int [], int);
double Shell_Sort(int [], int);
double Quick_Sort(int *, int, int);
int pivotear(int *, int , int);
double Bubble_Sort(int [], int);
double Radix_Sort(int [], int);
int MAX(int [], int);
void radix_sorting(int [], int, int);

//VECTORES
int data_5k[5000];
int data_20k[20000];
int data_200k[200000];
int data_500k[500000];
int aux_data_5k[5000];
int aux_data_20k[20000];
int aux_data_200k[200000];
int aux_data_500k[500000];

double bubble_time_sort[3];
double quick_time_sort[3];
double shell_time_sort[3];
double radix_time_sort[3];

int main(){
    
    int op;
    bool salida=false;
    do{
        menu();
        cout<<"Ingrese una opcion: ";
        cin>>op;
        switch (op)
        {
            case 1:
                create();
                system("pause");
                break;
            case 2:
                sort();
                system("pause");
                break;
            case 3:
                show();
                system("pause");
                break;
            case 4:
                cout<<endl<<"Saliendo del programa..."<<endl;
                salida=true;
                break;
            default:
                cout<<"***OPCION INVALIDA - INGRESE NUEVAMENTE***"<<endl;
                system("pause");
                break;
        }
    }while(!salida);

    return 0;
}

void menu(){
    system("cls");
    cout << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                 Aplicativo de algoritmos              |" << endl;
    cout << "|                     de ordenamiento                   |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "| 1. Crear vectores random  | 2. Ordenar vectores       |" << endl;
    cout << "| 3. Tiempos de ejecucion   | 4. SALIR                  |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
}
void create(){
    system("cls");
    int dim;
    cout << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|           Creando datos random en vectores            |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "Creando archivos de 5.000 datos..." << endl;
    dim = 5000;
    create_random(data_5k, dim);
    cout << "\tDatos creados correctamente!" << endl;

    cout << "Creando archivos de 20.000 datos..." << endl;
    dim = 20000;
    create_random(data_20k, dim);
    cout << "\tDatos creados correctamente!" << endl;

    cout << "Creando archivos de 200.000 datos..." << endl;
    dim = 200000;
    create_random(data_200k, dim);
    cout << "\tDatos creados correctamente!" << endl;

    cout << "Creando archivos de 500.000 datos..." << endl;
    dim = 500000;
    create_random(data_500k, dim);
    cout << "\tDatos creados correctamente!" << endl;

    cout << endl << "***Operacion finalizada***" << endl;
}
void sort(){
    system("cls");
    int dim;
    cout << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|                  ORDENANDO VECTORES                   |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    
    //Bubble
    cout << "\tBubble Sort: " << endl;

    cout << "Ordenando archivos de 5.000 datos..." << endl;
    dim = 5000;
    for(int i=0; i<dim; i++){
        aux_data_5k[i] = data_5k[i];
    }
    cout << "\tCargando.." << endl;
    bubble_time_sort[0]=Bubble_Sort(aux_data_5k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 20.000 datos..." << endl;
    dim = 20000;
    for(int i=0; i<dim; i++){
        aux_data_20k[i] = data_20k[i];
    }
    cout << "\tCargando.." << endl;
    bubble_time_sort[1]=Bubble_Sort(aux_data_20k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 200.000 datos..." << endl;
    dim = 200000;
    for(int i=0; i<dim; i++){
        aux_data_200k[i] = data_200k[i];
    }
    cout << "\tCargando.." << endl;
    bubble_time_sort[2]=Bubble_Sort(aux_data_200k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 500.000 datos..." << endl;
    dim = 500000;
    for(int i=0; i<dim; i++){
        aux_data_500k[i] = data_500k[i];
    }
    cout << "\tCargando.." << endl;
    bubble_time_sort[3]=Bubble_Sort(aux_data_500k, dim);
    cout << "Orden completo..." << endl;

    cout << endl << "***Operacion Bubble Sort finalizada***" << endl;

    //Quick
    cout << "\tQuick Sort: " << endl;

    cout << "Ordenando archivos de 5.000 datos..." << endl;
    dim = 5000;
    for(int i=0; i<dim; i++){
        aux_data_5k[i] = data_5k[i];
    }
    cout << "\tCargando.." << endl;
    quick_time_sort[0]=Quick_Sort(aux_data_5k, 0, dim-1);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 20.000 datos..." << endl;
    dim = 20000;
    for(int i=0; i<dim; i++){
        aux_data_20k[i] = data_20k[i];
    }
    cout << "\tCargando.." << endl;
    quick_time_sort[1]=Quick_Sort(aux_data_20k, 0, dim-1);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 200.000 datos..." << endl;
    dim = 200000;
    for(int i=0; i<dim; i++){
        aux_data_200k[i] = data_200k[i];
    }
    cout << "\tCargando.." << endl;
    quick_time_sort[2]=Quick_Sort(aux_data_200k, 0, dim-1);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 500.000 datos..." << endl;
    dim = 500000;
    for(int i=0; i<dim; i++){
        aux_data_500k[i] = data_500k[i];
    }
    cout << "\tCargando.." << endl;
    quick_time_sort[3]=Quick_Sort(aux_data_500k, 0, dim-1);
    cout << "Orden completo..." << endl;

    cout << endl << "***Operacion Quick Sort finalizada***" << endl;

    //Shell
    cout << "\tShell Sort: " << endl;

    cout << "Ordenando archivos de 5.000 datos..." << endl;
    dim = 5000;
    for(int i=0; i<dim; i++){
        aux_data_5k[i] = data_5k[i];
    }
    cout << "\tCargando.." << endl;
    shell_time_sort[0]=Shell_Sort(aux_data_5k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 20.000 datos..." << endl;
    dim = 20000;
    for(int i=0; i<dim; i++){
        aux_data_20k[i] = data_20k[i];
    }
    cout << "\tCargando.." << endl;
    shell_time_sort[1]=Shell_Sort(aux_data_20k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 200.000 datos..." << endl;
    dim = 200000;
    for(int i=0; i<dim; i++){
        aux_data_200k[i] = data_200k[i];
    }
    cout << "\tCargando.." << endl;
    shell_time_sort[2]=Shell_Sort(aux_data_200k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 500.000 datos..." << endl;
    dim = 500000;
    for(int i=0; i<dim; i++){
        aux_data_500k[i] = data_500k[i];
    }
    cout << "\tCargando.." << endl;
    shell_time_sort[3]=Shell_Sort(aux_data_500k, dim);
    cout << "Orden completo..." << endl;

    cout << endl << "***Operacion Shell Sort finalizada***" << endl;

    //Radix
    cout << "\tRadix Sort: " << endl;

    cout << "Ordenando archivos de 5.000 datos..." << endl;
    dim = 5000;
    for(int i=0; i<dim; i++){
        aux_data_5k[i] = data_5k[i];
    }
    cout << "\tCargando.." << endl;
    radix_time_sort[0]=Radix_Sort(aux_data_5k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 20.000 datos..." << endl;
    dim = 20000;
    for(int i=0; i<dim; i++){
        aux_data_20k[i] = data_20k[i];
    }
    cout << "\tCargando.." << endl;
    radix_time_sort[1]=Radix_Sort(aux_data_20k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 200.000 datos..." << endl;
    dim = 200000;
    for(int i=0; i<dim; i++){
        aux_data_200k[i] = data_200k[i];
    }
    cout << "\tCargando.." << endl;
    radix_time_sort[2]=Radix_Sort(aux_data_200k, dim);
    cout << "Orden completo..." << endl;

    cout << "Ordenando archivos de 500.000 datos..." << endl;
    dim = 500000;
    for(int i=0; i<dim; i++){
        aux_data_500k[i] = data_500k[i];
    }
    cout << "\tCargando.." << endl;
    radix_time_sort[3]=Radix_Sort(aux_data_500k, dim);
    cout << "Orden completo..." << endl;

    cout << endl << "***Operacion Radix Sort finalizada***" << endl;
    cout << endl << endl << "\t\t***Ordenamientos finalizados***" << endl;
}
void show(){
    cout << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "|                        |      Tiempos de ejecucion      |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "|                        |          5.000 datos           |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "| Bubble Sort:           |          "<<bubble_time_sort[0]<<"          |" << endl;
    cout << "| Quick Sort:            |          "<<quick_time_sort[0]<<"          |" << endl;
    cout << "| Shell Sort:            |          "<<shell_time_sort[0]<<"          |" << endl;
    cout << "| Radix Sort:            |          "<<radix_time_sort[0]<<"          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "|                        |          20.000 datos          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "| Bubble Sort:           |          "<<bubble_time_sort[1]<<"          |" << endl;
    cout << "| Quick Sort:            |          "<<quick_time_sort[1]<<"          |" << endl;
    cout << "| Shell Sort:            |          "<<shell_time_sort[1]<<"          |" << endl;
    cout << "| Radix Sort:            |          "<<radix_time_sort[1]<<"          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "|                        |         200.000 datos          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "| Bubble Sort:           |          "<<bubble_time_sort[2]<<"          |" << endl;
    cout << "| Quick Sort:            |          "<<quick_time_sort[2]<<"          |" << endl;
    cout << "| Shell Sort:            |          "<<shell_time_sort[2]<<"          |" << endl;
    cout << "| Radix Sort:            |          "<<radix_time_sort[2]<<"          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "|                        |         500.000 datos          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
    cout << "| Bubble Sort:           |          "<<bubble_time_sort[3]<<"          |" << endl;
    cout << "| Quick Sort:            |          "<<quick_time_sort[3]<<"          |" << endl;
    cout << "| Shell Sort:            |          "<<shell_time_sort[3]<<"          |" << endl;
    cout << "| Radix Sort:            |          "<<radix_time_sort[3]<<"          |" << endl;
    cout << "|------------------------|--------------------------------|" << endl;
}
void create_random(int array[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        array[i] = 1 + rand() % (10000+1 - 1);
    }
}

//Algoritmos de ordenamiento
//ShellSort
double Shell_Sort(int V[], int dim)
{
    unsigned t0, t1;
    t0 = clock();
    for (int i = dim / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < dim; j++)
        {
            for (int k = j - i; k >= 0; k = k - i)
            {
                if (V[k] < V[k + i])
                {
                    break;
                }
                else
                {
                    int temp = V[k + i];
                    V[k + i] = V[k];
                    V[k] = temp;
                }
            }
        }
    }
    t1=clock();
    double exe_time = (double(t1-t0)/CLOCKS_PER_SEC);
    return exe_time;
}

//QuickSort
int pivotear(int *V, int b, int t){
    int pivote, valor_pivote;
    int temp;
    pivote = b;
    valor_pivote = V[pivote];
    for(int i = b+1; i<=t; i++){
        if(V[i] < valor_pivote){
            pivote++;
            temp = V[i];
            V[i] = V[pivote];
            V[pivote] = temp;
        }
    }
    temp = V[b];
    V[b] = V[pivote];
    V[pivote] = temp;
    return pivote;
}
double Quick_Sort(int *V, int b, int t){
    unsigned t0, t1;
    t0 = clock();
    int pivote;
    if(b < t){
        pivote = pivotear(V, b, t);
        Quick_Sort(V, b, pivote-1);
        Quick_Sort(V, pivote+1, t);
    }
    t1=clock();
    double exe_time = (double(t1-t0)/CLOCKS_PER_SEC);
    return exe_time;
}

//BubbleSort
double Bubble_Sort(int V[], int dim){
    unsigned t0, t1;
    t0 = clock();
    for(int i=0; i<dim; i++){
        for(int j=i+1;j<dim; j++){
            if(V[i]>V[j]){
                int aux = V[i];
                V[i]=V[j];
                V[j]=aux;
            }
        }
    }
    t1=clock();
    double exe_time = (double(t1-t0)/CLOCKS_PER_SEC);
    return exe_time;
}

//RadixSort
double Radix_Sort(int V[] , int dim){
    unsigned t0, t1;
    t0 = clock();
    int m = MAX(V, dim);
    for (int exp = 1; m / exp > 0; exp *= 10)
        radix_sorting(V, dim, exp);
    t1=clock();
    double exe_time = (double(t1-t0)/CLOCKS_PER_SEC);
    return exe_time;
}
int MAX(int V[], int n){
    int mx = V[0];
    for (int i = 1; i < n; i++)
        if (V[i] > mx)
            mx = V[i];
    return mx;
}
void radix_sorting(int V[], int dim, int exp){
    int output[dim];
    int i, count[10] = { 0 };
    for (i = 0; i < dim; i++)
        count[(V[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = dim - 1; i >= 0; i--) {
        output[count[(V[i] / exp) % 10] - 1] = V[i];
        count[(V[i] / exp) % 10]--;
    }
    for (i = 0; i < dim; i++)
        V[i] = output[i];
}