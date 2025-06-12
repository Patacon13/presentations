#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Libro {
	char titulo[40];
	char autor[40];
	char isbn[40];
	int precio, cantidadExistencias, cantidadVendido;
};

int main(int argc, char *argv[]) {
	Libro libroEscribir;
	string tituloGuardar, autorGuardar, isbnGuardar;
	getline(cin, tituloGuardar);
	strcpy(libroEscribir.titulo, tituloGuardar.c_str());
	getline(cin, autorGuardar);
	strcpy(libroEscribir.autor, autorGuardar.c_str());
	getline(cin, isbnGuardar);
	strcpy(libroEscribir.isbn, isbnGuardar.c_str());
	
	cin >> libroEscribir.precio >> libroEscribir.cantidadExistencias >> libroEscribir.cantidadVendido;
	
	ofstream archivo;
	archivo.open("miArchivo.bin");
	
	archivo.write((char *) &libroEscribir, sizeof(libroEscribir));
	
	archivo.close();
	
	Libro nuevoLibro;
	ifstream archivoPrueba;
	
	archivoPrueba.open("miArchivo.bin");
	
	archivoPrueba.read((char *) & nuevoLibro, sizeof(nuevoLibro));
	
	cout << nuevoLibro.titulo << endl;
	return 0;
}

