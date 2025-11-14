#include <iostream>
#define TAMANIO 10
using namespace std;

void inicializaArreglo(int [], int);

bool existeNumero(int [], int, int);

int sumaDigitos(int);

int main(int argc, char *argv[]) {
	int numerosIniciales[TAMANIO], ingreso;
	inicializaArreglo(numerosIniciales, TAMANIO);
	
	do {
		cout << "Ingrese un numero" << endl;
		cin >> ingreso;
	} while(!existeNumero(numerosIniciales, TAMANIO, sumaDigitos(ingreso)));
	
	cout << "El numero que cumple la condicion es: " << ingreso << endl;
	
	return 0;
}

void inicializaArreglo(int V[], int tam) {
	for (int i = 0; i < tam; i++) {
		int ingreso;
		cout << "Ingrese el valor " << i + 1 << endl;
		cin >> ingreso;
		V[i] = ingreso;
	}
}

bool existeNumero(int V[], int tam, int numero) {
	bool encontrado = false;
	int i = 0;
	
	while (i < tam and !encontrado) {
		if (V[i] == numero) encontrado = true;
		i++;
	}
	
	return encontrado;
}

int sumaDigitos(int numero) {
	if (numero < 10) return numero;
	return numero % 10 + sumaDigitos(numero/10);
}

