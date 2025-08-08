#include <iostream>
#define TAMFRECUENCIAS 20000
using namespace std;
void ingresaElementos(int [], int);
void llenaFrecuencias(int [], int [], int);
void imprimeFrecuencias(int []);

int main(int argc, char *argv[]) {
	int frecuencias[TAMFRECUENCIAS] {};
	
	int n;
	
	cin >> n;
	
	ingresaElementos(frecuencias, n);
	imprimeFrecuencias(frecuencias);
	
	return 0;
}

void ingresaElementos(int frecuencias[], int n) {
	for (int i = 0; i < n; i++) {
		int ingreso;
		cin >> ingreso;
		frecuencias[ingreso]++;
	}
}


void imprimeFrecuencias(int frecuencias[]) {
	for (int i = 0; i < TAMFRECUENCIAS; i++) {
		if (frecuencias[i] != 0) 
			cout << i << " aparece " << frecuencias[i] << " vez(es)" << endl;
	}
}
