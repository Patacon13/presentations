#include <iostream>
#define TAMANIOFISICOA 7
#define TAMANIOFISICOB 5
#define TAMANIOFISICOV 500
using namespace std;
void ordenaAsc(int [], int);
void intercambiar(int&, int&);
void ordenaDes(int [], int);
void funcion(int [], int, int [], int, int [], int&, bool);
void copiaArreglo(int [], int, int []);
int main(int argc, char *argv[]) {
	int vectorA[TAMANIOFISICOA] {5,8,3,1,12,3,9}, vectorB[TAMANIOFISICOB] {12,2,9,4,9}, vectorV[TAMANIOFISICOV], tamanioLogicoB = 5, tamanioLogicoA = 7, tamanioLogicoV = 0;
	bool c = true;
	
	funcion(vectorA, tamanioLogicoA, vectorB, tamanioLogicoB, vectorV, tamanioLogicoV, c);
	
	for (int i=0; i<tamanioLogicoV; i++) {
		cout << vectorV[i] << endl;
	}
	
	cout << "Tamanio logico de V = " << tamanioLogicoV << endl;
	return 0;
}

void copiaArreglo(int arregloA[], int tamanioLogicoA, int arregloB[]) {
	for (int i = 0; i < tamanioLogicoA; i++) {
		arregloB[i] = arregloA[i];
	}
}

void funcion(int vectorA[], int tamanioLogicoA, int vectorB[], int tamanioLogicoB, int vectorV[], int& tamanioLogicoV, bool c){
	
	if(c) {
		ordenaAsc(vectorA, tamanioLogicoA);
		ordenaAsc(vectorB, tamanioLogicoB);
	}
	else {
		ordenaDes(vectorA, tamanioLogicoA);
		ordenaDes(vectorB, tamanioLogicoB);
	}
	
	int indiceA = 0, indiceB = 0;
	while (indiceA < tamanioLogicoA && indiceB < tamanioLogicoB) {
		if (indiceB > 0 and vectorB[indiceB] == vectorB[indiceB - 1]) 
			indiceB++;
		if (vectorA[indiceA] < vectorB[indiceB]) indiceA++;
		else if (vectorA[indiceA] == vectorB[indiceB]) {
			vectorV[tamanioLogicoV] = vectorA[indiceA];
			tamanioLogicoV++;
			indiceB++;
		}
		else indiceB++;
	}
	
}
	
void ordenaDes(int vec[], int tamanioLogico) {
	int minimo;
	for(int i=tamanioLogico-1; i>=0; i--){
		minimo=i;
		for(int j = i - 1; j >= 0; j--)
			if (vec[j] < vec[minimo]) minimo=j;
		intercambiar(vec[minimo], vec[i]);
	}
}
		
void ordenaAsc(int vec[], int tamanioLogico) {
	int minimo;
	for (int i=0; i<tamanioLogico; i++) {
		minimo=i;
		for(int j=i+1; j<tamanioLogico; j++)
			if(vec[j]<vec[minimo])  minimo=j;
		intercambiar(vec[minimo], vec[i]);
	}
}
			
void intercambiar(int& a,int& b) {
	int aux = a;
	a = b;
	b = aux;
}
				
				
