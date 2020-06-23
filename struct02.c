#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
/*  
 * Simples codigo usando struct em c 
 * author: felipe
 */
#define LIMITE_NOME 100

//main 
int main(void){
	int index ,aut;
     char user_nome[LIMITE_NOME];
	 char user_senha[LIMITE_NOME];
	
	//struct
	struct user{
	     char nome[LIMITE_NOME];
		  char senha[LIMITE_NOME];

	};
	struct user usuario[3];
	
	
	//armazenando o nome de usuario e senha 
	printf("Informe os nomes e senhas de tres usuarios\n");
	for(index = 0 ; index < 3 ; index++){
	   
	   printf("Informe o nome do usuario [%d]: " , index+1);
       fgets(usuario[index].nome,LIMITE_NOME,stdin);
	   printf("Informe a senha do usuario [%d]: " , index+1);
       fgets(usuario[index].senha,LIMITE_NOME,stdin);
	   printf("\n");
	   __fpurge(stdin);
	}
	
	printf("informe um usuario: ");
	fgets(user_nome, LIMITE_NOME,stdin);
	
	printf("Iforme a senha do usuario: ");
	fgets(user_senha, LIMITE_NOME,stdin);

	for(index = 0 ; index < 3 ; index++){
	   if(strcmp(usuario[index].nome , user_nome) == 0 && strcmp(usuario[index].senha, user_senha)==0){
           aut = 1; 
		   break;
	   }   
	}
       if(aut == 1)
		   printf("Usuario autenticado\n");
	   else
		  printf("Usuario nao autenticado\n");
		

 return 0;
}





