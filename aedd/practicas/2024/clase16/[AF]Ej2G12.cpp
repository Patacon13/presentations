#include <iostream>
#define TAMANIOCATEGORIAS 4
#define TAMANIOLOCALIDADES 50
using namespace std;

void pasajerosPorLocalidad(int [][TAMANIOLOCALIDADES], string []);

void pasajerosPorCategoria(int [][TAMANIOLOCALIDADES], string []);

void localidadesSinPasajesVendidos(int [][TAMANIOLOCALIDADES], string []);

void localidadMenorCantidadPasajeros(int [][TAMANIOLOCALIDADES], string []);

void localidadMasNPasajeros(int [][TAMANIOLOCALIDADES], string [], int);

bool existeCategoriaSinPasajesVendidos(int [][TAMANIOLOCALIDADES], string []);

int main() {
	
	// Vector con nombres de localidades
	string localidades[TAMANIOLOCALIDADES] = {
		"Localidad1", "Localidad2", "Localidad3", "Localidad4", "Localidad5",
			"Localidad6", "Localidad7", "Localidad8", "Localidad9", "Localidad10",
			"Localidad11", "Localidad12", "Localidad13", "Localidad14", "Localidad15",
			"Localidad16", "Localidad17", "Localidad18", "Localidad19", "Localidad20",
			"Localidad21", "Localidad22", "Localidad23", "Localidad24", "Localidad25",
			"Localidad26", "Localidad27", "Localidad28", "Localidad29", "Localidad30",
			"Localidad31", "Localidad32", "Localidad33", "Localidad34", "Localidad35",
			"Localidad36", "Localidad37", "Localidad38", "Localidad39", "Localidad40",
			"Localidad41", "Localidad42", "Localidad43", "Localidad44", "Localidad45",
			"Localidad46", "Localidad47", "Localidad48", "Localidad49", "Localidad50"
	};
	
	// Matriz de pasajes vendidos
	int pasajesVendidos[TAMANIOCATEGORIAS][TAMANIOLOCALIDADES] = {
		{100, 200, 150, 300, 250, 50, 600, 0, 900, 1000, 1200, 700, 500, 400, 100, 1500, 1600, 1700, 50, 600, 700, 800, 900, 1000, 50, 150, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400},
	{50, 100, 75, 150, 125, 25, 300, 0, 450, 500, 600, 350, 250, 200, 50, 750, 800, 850, 25, 300, 350, 400, 450, 500, 25, 75, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 950, 1000, 1050, 1100, 1150, 1200, 1250},
		{200, 400, 300, 600, 500, 100, 1200, 0, 1800, 2000, 2400, 1400, 1000, 800, 200, 3000, 3200, 3400, 100, 1200, 1400, 1600, 1800, 2000, 100, 300, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000, 3200, 3400, 3600, 3800, 4000, 4200, 4400, 4600, 4800, 5000},
	{150, 300, 225, 450, 375, 75, 900, 0, 1350, 1500, 1800, 1050, 750, 600, 150, 2250, 2400, 2550, 75, 900, 1050, 1200, 1350, 1500, 75, 225, 300, 450, 600, 750, 900, 1050, 1200, 1350, 1500, 1650, 1800, 1950, 2100, 2250, 2400, 2550, 2700, 2850, 3000, 3150, 3300, 3450, 3600, 3750}
	};
	
	// Cantidad de pasajeros por localidad
	pasajerosPorLocalidad(pasajesVendidos, localidades);
	
	// Cantidad de pasajeros por categoría
	pasajerosPorCategoria(pasajesVendidos, localidades);
	
	
	// Localidades sin pasajes vendidos
	localidadesSinPasajesVendidos(pasajesVendidos, localidades);
	
	
	// Localidad con menor cantidad de pasajeros
	localidadMenorCantidadPasajeros(pasajesVendidos, localidades);
	
	
	// Localidades con más de 1000 pasajeros
	localidadMasNPasajeros(pasajesVendidos, localidades, 1000);
	
	// Categoría sin pasajes vendidos
	if (existeCategoriaSinPasajesVendidos(pasajesVendidos, localidades)) cout << "Existe una categoria sin pasajes vendidos" << endl;
	else cout << "No existe una categoria sin pasajes vendidos" << endl;
	
	return 0;
}

void pasajerosPorLocalidad(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[]) {
	for (int i = 0; i < TAMANIOLOCALIDADES; i++) {
		int totalPasajeros = 0;
		for (int j = 0; j < TAMANIOCATEGORIAS; j++) {
			totalPasajeros += pasajesVendidos[j][i];
		}
		cout << "Localidad: " << localidades[i] << ", Pasajeros: " << totalPasajeros << endl;
	}
}

void pasajerosPorCategoria(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[]) {
	for (int i = 0; i < TAMANIOCATEGORIAS; i++) {
		int totalPasajeros = 0;
		for (int j = 0; j < TAMANIOLOCALIDADES; j++) {
			totalPasajeros += pasajesVendidos[i][j];
		}
		cout << "Categoría: " << i << ", Pasajeros: " << totalPasajeros << endl;
	}
}

void localidadesSinPasajesVendidos(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[]) {
	cout << "Localidades sin pasajes vendidos:" << endl;
	for (int i = 0; i < TAMANIOLOCALIDADES; i++) {
		bool noPasajes = true;
		int j = 0;
		while (j < TAMANIOCATEGORIAS and noPasajes) {
			if (pasajesVendidos[j][i] > 0)
				noPasajes = false;
			j++;
		}
		if (noPasajes) {
			cout << localidades[i] << endl;
		}
	}
}

void localidadMenorCantidadPasajeros(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[]) {
	int minPasajeros = pasajesVendidos[0][0];
	int minIndex = 0;
	for (int i = 0; i < TAMANIOLOCALIDADES; i++) {
		int totalPasajeros = 0;
		for (int j = 0; j < TAMANIOCATEGORIAS; j++) {
			totalPasajeros += pasajesVendidos[j][i];
		}
		if (totalPasajeros < minPasajeros) {
			minPasajeros = totalPasajeros;
			minIndex = i;
		}
	}
	cout << "Localidad con menor cantidad de pasajeros: " << localidades[minIndex] << " con " << minPasajeros << " pasajeros." << endl;
}

void localidadMasNPasajeros(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[], int n) {
	int count = 0;
	for (int i = 0; i < TAMANIOLOCALIDADES; i++) {
		int totalPasajeros = 0;
		for (int j = 0; j < TAMANIOCATEGORIAS; j++) 
			totalPasajeros += pasajesVendidos[j][i];
		if (totalPasajeros > n)
			count++;
	}
	cout << "Cantidad de localidades con más de " << n << " pasajeros: " << count << endl;
}

bool existeCategoriaSinPasajesVendidos(int pasajesVendidos[][TAMANIOLOCALIDADES], string localidades[]) {
	bool categoriaSinPasajes = false;
	int i = 0;
	while (i < TAMANIOCATEGORIAS and !categoriaSinPasajes) {
		bool noPasajes = true;
		int j = 0;
		while (j < TAMANIOLOCALIDADES and noPasajes) {
			if (pasajesVendidos[i][j] > 0)
				noPasajes = false;
			j++;
		}
		if (noPasajes)
			categoriaSinPasajes = true;
		i++;
	}
	return categoriaSinPasajes;
}
