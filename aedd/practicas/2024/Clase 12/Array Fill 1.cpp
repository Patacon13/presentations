//array fill
#include <iostream>
#define TAM 10
using namespace std;

void inicializar_teclado(int [], int);
void imprimir_vector(int [], int);

int main(int argc, char *argv[]) {
	int vector[TAM];
	inicializar_teclado(vector,TAM);
	imprimir_vector(vector,TAM);
	return 0;
}

void inicializar_teclado(int V[], int tam){
	cin>> V[0];
	for(int i=1; i<tam;i++)
		V[i]= 2*V[i-1];
}
	
void imprimir_vector(int V[], int tam){
	for(int i=0; i<tam;i++)
		cout<<"N["<<i<<"]"<<" = "<<V[i]<<endl;
}
