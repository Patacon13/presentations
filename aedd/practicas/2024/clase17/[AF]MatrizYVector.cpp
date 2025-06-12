#include <iostream>
#define TF 10
using namespace std;

void FilasOrdenadas(int matriz[][TF], int vector[], int tl);
void PrimerMayorenColumna(int matriz[][TF], int vector[], int tl);

int main(int argc, char *argv[]) {
	int T, Q;
	cout << "Ingresa la dimension de la matriz deseada (entre 2 y 10): ";
	cin >> T;
	while(T < 2 or T > 10){
		cout << "Recuerda! La dimension ingresada debe estar entre 2 y 10." << endl;
		cout << "Reingresa..." << endl;
		cin >> T;
	}
	int matriz[TF][TF];
	int vector[TF];
	cout << "Ingresa los elementos de la matriz (" << T*T << " numeros enteros)" << endl;
	for(int i=0; i<T; i++){
		for(int j=0; j<T; j++){
			cin >> matriz[i][j];
		}
	}
	cout << "Ingresa los elementos del vector (" << T << " numeros enteros)" << endl;
	for(int i=0; i<T; i++){
		cin >> vector[i];
	}
	cout << "Ingresa el tipo de consulta deseada (1 o 2): ";
	cin >> Q;
	while(Q != 1 and Q != 2){
		cout << "Recuerda! Las consultas disponibles se acceden a través de ingresar 1 o ingresar 2." << endl;
		cout << "Reingresa..." << endl;
		cin >> Q;
	}
	cout << "El resultado de la consulta es: ";
	if(Q == 1) FilasOrdenadas(matriz, vector, T);
	else PrimerMayorenColumna(matriz, vector, T);
	return 0;
}

void FilasOrdenadas(int matriz[][TF], int vector[], int tl){
	bool vecAscendente, filaOrdenCorrecto;
	int contador=0;
	if(vector[0] < vector[tl-1]) vecAscendente = true;
	else vecAscendente = false;
	for(int i=0; i<tl; i++){
		filaOrdenCorrecto = true;
		int j=1;
		if(vecAscendente){
			while(j<tl and filaOrdenCorrecto){
				if(matriz[i][j-1] > matriz[i][j]) filaOrdenCorrecto = false;
				++j;
			}
		}
		else{
			while(j<tl and filaOrdenCorrecto){
				if(matriz[i][j-1] < matriz[i][j]) filaOrdenCorrecto = false;
				++j;
			}
		}
		if (filaOrdenCorrecto) contador++;
	}
	cout << contador << endl;
}
	
void PrimerMayorenColumna(int matriz[][TF], int vector[], int tl){
	float promedioVector=0;
	int primerMayorValor, j;
	for(int i=0; i<tl; i++)
		promedioVector += vector[i];
	promedioVector/=tl;
	for(int i=0; i<tl; i++){
		primerMayorValor=-1;
		j = 0;
		while(j<tl and primerMayorValor == -1){
			if (matriz[j][i] > promedioVector) primerMayorValor = matriz[j][i];
			++j;
		}
		cout << primerMayorValor << "  ";
	}
}
