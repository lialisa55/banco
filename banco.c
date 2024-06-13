#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	char *nome, *cpf;
	int idade;
	float saldo, credito;
};

void receber(int num, struct pessoa *cliente){
	for (int i = 0; i < num; i++){
        cliente[i].nome = (char*) malloc(sizeof(char)*31);
        cliente[i].cpf = (char*) malloc(sizeof(char)*12);

		fscanf(stdin, " %30[^,], %11[^,], %d, %f, %f", cliente[i].nome, cliente[i].cpf, &cliente[i].idade, &cliente[i].saldo, &cliente[i].credito);

		cliente[i].nome = (char*) realloc(cliente[i].nome, (strlen(cliente[i].nome) + 1) * sizeof(char));
		cliente[i].cpf = (char*) realloc(cliente[i].cpf, (strlen(cliente[i].cpf) + 1) * sizeof(char));
	}
}

void imprimir(int num, struct pessoa *cliente) {
    int endividados = 0;

    for (int i = 0; i < num; i++) {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", cliente[i].nome);
        printf("CPF: %s\n", cliente[i].cpf);
        printf("Idade: %d\n", cliente[i].idade);
        printf("Saldo: %.2f\n", cliente[i].saldo);
        printf("Credito: %.2f\n", cliente[i].credito);
        printf("\n");
    }

    printf("Pessoas endividadas:");
    for (int i = 0; i < num; i++) {

        if (cliente[i].saldo < cliente[i].credito) {
            printf("\n");
            printf("Nome: %s\n", cliente[i].nome);
            printf("CPF: %s\n", cliente[i].cpf);
            printf("Divida: %.2f\n", cliente[i].credito - cliente[i].saldo);
            endividados++;
        }
    }

    if (endividados == 0) {
        printf("\nNenhuma pessoa endividada encontrada.\n");
    }
}

int main (void){
	int num;
	scanf("%d", &num);
    struct pessoa *cliente = (struct pessoa*) malloc(sizeof(struct pessoa) * num);
	receber(num, cliente);
	imprimir(num, cliente);

    for (int i = 0; i < num; i++) {
        free(cliente[i].nome);
        free(cliente[i].cpf);
    }
    free(cliente);

	return 0;
}
