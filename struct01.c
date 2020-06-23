#include<stdio.h>
#include<stdio_ext.h>// __fpurge 

/*  
 * Simples codigo usando struct em c 
 * author: felipe
 */

//constantes
#define NOME_LIMITE 100
#define CONT_LIMITE 5 

//contador 
typedef int contador;

//struct pessoa
typedef struct pessoa{
   char nome[NOME_LIMITE];
   unsigned int idade;
}PESSOAS;

// funcao que ira preencher a struct pessoa
void preencher_struct(PESSOAS pessoas[]){
    contador index_preencher;
	for(index_preencher = 0 ; index_preencher < CONT_LIMITE ; index_preencher++){
        printf("Informe o nome da pessoa[%d]: ", index_preencher+1 );
		fgets(pessoas[index_preencher].nome,NOME_LIMITE,stdin);
		printf("Informe a idade da pessoa[%d]: " , index_preencher+1);
		scanf("%d" , &pessoas[index_preencher].idade);
       __fpurge(stdin);  
		printf("\n");
	}//for
	printf("\n");
}//fim da funcao preenche_struct

//funcao para exibir as informacao da struct
void exibir_struct_pessoa(PESSOAS pessoas[]){
    contador index_exibir;
	printf("=>> Exibindo As Informacoes das pessoas<<=\n\n");
	for(index_exibir = 0 ; index_exibir < CONT_LIMITE ; index_exibir++){
	   printf("Nome e idade da pessoa [%d] e: %s" ,index_exibir+1, pessoas[index_exibir].nome );
	   printf("Idade da pessoa[%d] e: %d anos\n", index_exibir+1, pessoas[index_exibir].idade);
       printf("\n");
	}//for
	
	printf("\n");
}//fim da funcao exibir_struct_pessoa

//funcao para exibir a pessoa de menor idade da struct
void struct_menor_idade(PESSOAS p[] , PESSOAS p_menor_idade){
 contador index_idade;
 p_menor_idade = p[0];
 printf("=>> EXIBINDO A PESSOA DE MENOR IDADE <<=\n\n");
	for(index_idade = 0 ; index_idade < CONT_LIMITE ; index_idade++){
	      if(p[index_idade].idade < p_menor_idade.idade)
			 p_menor_idade = p[index_idade];
	}//for
		   printf("Essa pessoa tem a menor idade e: %s\n", p_menor_idade.nome);
}//fim da funcao struct_menor_idade

//main
int main(void){
	PESSOAS p1[CONT_LIMITE],p2;
	preencher_struct(p1);
	exibir_struct_pessoa(p1);
	struct_menor_idade(p1, p2);
	return 0;
}//fim funcao main

