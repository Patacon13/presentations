#include <iostream>
#include <ctime>
using namespace std;

void inicializar_aleatorio(int V[], int tam) {
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		int ingreso = rand();
		V[i] = ingreso;
	}
}

void inicializar_teclado(int V[], int tam) {
	for (int i = 0; i < tam; i++) {
		int ingreso;
		cout << "Ingrese el valor " << i + 1 << endl;
		cin >> ingreso;
		V[i] = ingreso;
	}
}

void imprimeArreglo(int V[], int tam) {
	for (int i = 0; i < tam; i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int vector[1000];
	
	int tamanioLogico;
	cout << "Ingrese la cantidad de elementos que tiene su arreglo" << endl;
	cin >> tamanioLogico;
	
	inicializar_aleatorio(vector, tamanioLogico);
	imprimeArreglo(vector, tamanioLogico);
	return 0;
}

