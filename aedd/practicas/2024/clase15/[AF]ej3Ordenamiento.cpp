#include <iostream>
using namespace std;
void ordenaAsc(int vec[], int tam);
void intercambiar(int& a, int& b);
void ordenaDes(int vec[], int tam);
void funcion(int vecA[], int tama, int vecB[], int tamb, int vecV[], int& tamv, bool c);
int main(int argc, char *argv[]) {
	int vecA[7]={5,8,3,1,12,3,9}, vecB[5]={12,2,9,4,9}, vecV[500], tamb=5, tama=7,tamv;
	bool c=true;
	
	funcion(vecA, tama, vecB, tamb, vecV, tamv, c);
	
	for(int cont=0; cont<tamv; cont++){
		cout<<vecV[cont]<<endl;
	}
	cout<<"Tamanio logico de V = "<<tamv<<endl;
	return 0;
}
void funcion(int vecA[], int tama, int vecB[], int tamb, int vecV[], int& tamv, bool c){
	if(c) ordenaAsc(vecB,tamb);
	else ordenaDes(vecB,tamb);
	int posA,posV=0;
	bool distintos=true;                   
	for(int cont=0; cont<tamb; cont++){
		posA=0;
		distintos=1;
		while(posA<tama and distintos and vecB[cont]!=vecB[cont+1]){  
			if(vecB[cont]==vecA[posA]){
				vecV[posV]=vecB[cont];
				distintos=false;
				posV++;
			}
			posA++;
		}
	}
	tamv=posV;
}
	
void ordenaDes(int vec[], int tam){
	int min;
	for(int cont=tam-1; cont>=0; cont--){
		min=cont;
		for(int j=cont-1; j>=0; j--)
			if(vec[j]<vec[min])  min=j;
		intercambiar(vec[min], vec[cont]);
	}
}
		
void ordenaAsc(int vec[], int tam){
	int min;
	for(int cont=0; cont<tam; cont++){
		min=cont;
		for(int j=cont+1; j<tam; j++)
			if(vec[j]<vec[min])  min=j;
		intercambiar(vec[min], vec[cont]);
	}
}
	
void intercambiar(int& a,int& b){
	int aux=a;
	a=b;
	b=aux;
}
				
