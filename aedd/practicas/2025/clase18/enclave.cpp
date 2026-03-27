#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int shift;
	cout << "Ingresar desplazamiento (puede ser negativo): ";
	cin >> shift;
	
	
	ifstream archivoEntrada;
	archivoEntrada.open("original.txt");
	
	ofstream archivoSalida;
	archivoSalida.open("enclave.txt"); 

	if (!archivoEntrada || !archivoSalida) {
		cout << "No se pudo abrir los archivos" << endl;
	}
	
	else {
		char c;
		
		archivoEntrada.get(c);
		while(!archivoEntrada.eof()) {
			if (c != ' ') c += shift;
			cout << "imprimiendo" << " " << c << endl;
			archivoSalida << c;
			archivoEntrada.get(c);
		}
		
		
		
		archivoSalida.close();
		
		cout << "Listo. Archivo enclave.txt generado." << endl;
	}
	return 0;
}
