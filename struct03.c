#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define SIZE 30

//struct veiculo
struct veiculo{
      char modelo[SIZE];
      char placa[SIZE];
};

//struct pessoa
struct pessoa{
    
	char nome[SIZE];
	int numeroVeiculos;
	struct veiculo *veiculos;
	
};

void cadastro_usuario(){
char *caractere;

	struct pessoa *pessoas;
	int numeroPessoas=0;
	int x, y;

	printf("Informe a quantidade de pessoas a serem cadastradas: ");
	scanf("%d", &numeroPessoas);
    __fpurge(stdin);	
	// Aloca dinamicamente o espaco necessario para armazenar "x" estruturas do tipo "pessoa"
	pessoas = (struct pessoa *) malloc(numeroPessoas * sizeof(struct pessoa));

	// Para cada estrutura (pessoa), solicita os dados
	for(x=0; x<numeroPessoas; x++)
	{
		printf("\nInforme o nome da pessoa #%d: ", x+1);
		fgets(pessoas[x].nome,SIZE,stdin);

		printf("Informe a quantidade de veiculos que '%s' possui: ", pessoas[x].nome);
		scanf("%d", &pessoas[x].numeroVeiculos);
		__fpurge(stdin); // Limpa o buffer

		// Aloca dinamicamente o espaco necessario para armazenar "x" estruturas do tipo "veiculo"
		pessoas[x].veiculos = (struct veiculo *) malloc(pessoas[x].numeroVeiculos * sizeof(struct veiculo));

		// Para cada estrutura (veiculo), solicita os dados
		for(y=0; y<pessoas[x].numeroVeiculos; y++)
		{
			printf("\nInforme o modelo do veiculo #%d da pessoa '%s': ", y+1, pessoas[x].nome);
			fgets(pessoas[x].veiculos[y].modelo,SIZE,stdin);

			printf("\nInforme a placa do veiculo #%d da pessoa '%s': ", y+1, pessoas[x].nome);
			fgets(pessoas[x].veiculos[y].placa,SIZE,stdin);
		}
	}

	// Exibe todas as estruturas "pessoa"
	for(x=0; x<numeroPessoas; x++){
		// Exibe todas as estruturas "veiculo" da pessoa em questao
		for(y=0; y<pessoas[x].numeroVeiculos; y++){
			printf("\nO veiculo %s de placa %s pertence a %s", pessoas[x].veiculos[y].modelo, pessoas[x].veiculos[y].placa, pessoas[x].nome);
		}
	}
	
	free(pessoas);
}

int main(void){
 cadastro_usuario();
	return 0;
}