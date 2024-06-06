#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	char *nome, *cpf;
	int idade;
	float saldo, credito;
};

void receber(int num, char *nome, char *cpf, int idade, float saldo, float credito){
	nome = (char*) malloc(sizeof(char)*30);
	cpf = (char*) malloc(sizeof(char)*11);

	for (int i = 0; i < num; i++){
		fscanf(stdin, " %30[^,], %11[^,], %d[^,], %f[^,], %f[^,]", nome, cpf, &idade, &saldo, &credito);
	}
}

int main (void){
	struct pessoa cliente;
	int num;
	scanf("%d", &num);
	receber(num, cliente.nome, cliente.cpf, cliente.idade, cliente.saldo, cliente.credito);

	return 0;
}
