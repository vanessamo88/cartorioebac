#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // bliblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema

    {
      //Inicio da cria��o de vari�veis/strig
      char arquivo[40]; //A numera��o em [] refere-se � quantos caracteres ser�o aceitos
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //final da cria��o de vari�veis/strig
      
      printf("Digite CPF � ser cadastrado: "); //Coletando informa��o do usu�rio
      scanf("%s", cpf); //%s refere-se � string
      
      strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
      
      FILE *file; // Cria o arquivo no banco de dados
      file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
      fprintf(file,cpf); // Salvo o valor da vari�vel
      fclose(file); // Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Onde ser� atualizada a informa��o, "a" significa atualizar
      fprintf(file,","); // Salvo o valor da vari�vel
      fclose(file); // Fecha o arquivo
      
      printf("Digite o nome � ser cadastrado: "); //Coletando informa��o do usu�rio
      scanf("%s", nome); //%s refere-se � string
      
      file = fopen(arquivo, "a");
      fprintf(file,nome);   
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o sobrenome � ser cadastrado: ");
      scanf("%s", sobrenome);
      
      file = fopen(arquivo, "a");
      fprintf(file,sobrenome);   
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o cargo � ser cadastrado: ");
      scanf("%s", cargo);
      
      file = fopen(arquivo, "a");
      fprintf(file,cargo);   
      fclose(file);
      
      system("pause"); //Pausa na tela antes de retornar ao menu
           
      
    }
    
int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema

    {
        
      setlocale(LC_ALL, "Portuguese"); 
        
      char cpf[40];
      char conteudo[200];
      
      printf("Digite CPF a ser consultado: ");
      scanf("%s", cpf);
      
      FILE *file;
      file = fopen(cpf, "r"); //Onde ser� lida a informa��o, "r" significa ler(read)
      
      if(file == NULL) // Condicional caso a informa��o inserida n�o esteja compat�vel com nada do banco de dados
      {
      printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
      }
      
      while(fgets(conteudo, 200, file) != NULL) //Quantidade de caracteres que a busca ir� realizar no banco de dados
      
      {
      printf("\nEssas s�o as informa��es do usu�rio: "); //Retorno do sistema quando usu�rio � encontrado
      printf("%s", conteudo); 
      printf("\n\n"); // \n significa pular linha 
           
      }
       
      system("pause");
       
    }
    
int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema

    {
    char cpf[40];
    printf("Digite CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    printf("Usu�rio n�o encontrado no sistema\n");
    system("pause");
    }
    
    
    }
    
    
int main() //Fun��o principal
    {
    int opcao=0; //Defininindo vari�veis
    int laco=1; 
    
    for(laco=1;laco=1;)//Comando para repeti��o de opera��o
    {
       
       system("cls"); //Respons�vel por limpar a tela
       
       setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
    
       printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu - Como aparecem as op��es ao cliente
       printf(" Escolha a op��o desejada no menu:\n\n");
       printf(" \t1 - Registrar nomes\n");
       printf(" \t2 - Consultar nomes\n");
       printf(" \t3 - Deletar nomes\n\n");
       printf("Op��o: "); //Final no menu
    
       scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
    
       system("cls"); //Respons�vel por limpar a tela
       
       switch(opcao) //Inicio da sele��o do menu
       {
            case 1:
            registro(); //Chamada de fun��es
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            
            default: //Quando n�o h� op��o mapeada
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
        }
    
       
}
}
