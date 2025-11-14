#include <iostream>
using namespace std;

int elimOrdenar(int[], int &, int);
void bubbleSort(int [], int);
void intercambiar(int&,int&);

int main() {
	int A[500] = {1, 5, 10, 15, 20};
	int TLA = 5;
	int X;
	
	cout << "Ingrese el valor de X" << endl;
	cin >> X;
	
	int elementosEliminados = elimOrdenar(A, TLA, X);
	
	cout << "Elementos eliminados: " << elementosEliminados << endl;
	cout << "Arreglo ordenado y filtrado: ";
	for (int i = 0; i < TLA; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
	return 0;
}

int elimOrdenar(int A[], int &TLA, int X) {
	int nuevoTLA = 0;
	
	for (int i = 0; i < TLA; i++) {
		if (A[i] % X != 0) {
			A[nuevoTLA] = A[i];
			nuevoTLA++;
		}
	}
	
	bubbleSort(A, TLA);
	
	int cantidadEliminados = TLA - nuevoTLA;
	TLA = nuevoTLA;
	return cantidadEliminados;
}

void bubbleSort(int vec[], int tamanioLogico) {
	int minimo;
	for (int i=0; i<tamanioLogico; i++) {
		minimo=i;
		for(int j=i+1; j<tamanioLogico; j++)
			if(vec[j]<vec[minimo])  minimo=j;
		intercambiar(vec[minimo], vec[i]);
	}
}

void intercambiar(int& a,int& b){
	int aux = a;
	a = b;
	b = aux;
}
