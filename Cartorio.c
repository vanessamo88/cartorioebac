#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // bliblioteca de alocação de espaço em memória
#include <locale.h> // bliblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema

    {
      //Inicio da criação de variáveis/strig
      char arquivo[40]; //A numeração em [] refere-se à quantos caracteres serão aceitos
      char cpf[40];
      char nome[40];
      char sobrenome[40];
      char cargo[40];
      //final da criação de variáveis/strig
      
      printf("Digite CPF à ser cadastrado: "); //Coletando informação do usuário
      scanf("%s", cpf); //%s refere-se à string
      
      strcpy(arquivo, cpf); // Responsável por copiar os valores das string
      
      FILE *file; // Cria o arquivo no banco de dados
      file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
      fprintf(file,cpf); // Salvo o valor da variável
      fclose(file); // Fecha o arquivo
      
      file = fopen(arquivo, "a"); //Onde será atualizada a informação, "a" significa atualizar
      fprintf(file,","); // Salvo o valor da variável
      fclose(file); // Fecha o arquivo
      
      printf("Digite o nome à ser cadastrado: "); //Coletando informação do usuário
      scanf("%s", nome); //%s refere-se à string
      
      file = fopen(arquivo, "a");
      fprintf(file,nome);   
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o sobrenome à ser cadastrado: ");
      scanf("%s", sobrenome);
      
      file = fopen(arquivo, "a");
      fprintf(file,sobrenome);   
      fclose(file);
      
      file = fopen(arquivo, "a");
      fprintf(file,",");
      fclose(file);
      
      printf("Digite o cargo à ser cadastrado: ");
      scanf("%s", cargo);
      
      file = fopen(arquivo, "a");
      fprintf(file,cargo);   
      fclose(file);
      
      system("pause"); //Pausa na tela antes de retornar ao menu
           
      
    }
    
int consulta() //Função responsável por consultar os usuários no sistema

    {
        
      setlocale(LC_ALL, "Portuguese"); 
        
      char cpf[40];
      char conteudo[200];
      
      printf("Digite CPF a ser consultado: ");
      scanf("%s", cpf);
      
      FILE *file;
      file = fopen(cpf, "r"); //Onde será lida a informação, "r" significa ler(read)
      
      if(file == NULL) // Condicional caso a informação inserida não esteja compatível com nada do banco de dados
      {
      printf("Não foi possivel abrir o arquivo, não localizado!.\n");
      }
      
      while(fgets(conteudo, 200, file) != NULL) //Quantidade de caracteres que a busca irá realizar no banco de dados
      
      {
      printf("\nEssas são as informações do usuário: "); //Retorno do sistema quando usuário é encontrado
      printf("%s", conteudo); 
      printf("\n\n"); // \n significa pular linha 
           
      }
       
      system("pause");
       
    }
    
int deletar() //Função responsável por deletar os usuários no sistema

    {
    char cpf[40];
    printf("Digite CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    printf("Usuário não encontrado no sistema\n");
    system("pause");
    }
    
    
    }
    
    
int main() //Função principal
    {
    int opcao=0; //Defininindo variáveis
    int laco=1; 
    
    for(laco=1;laco=1;)//Comando para repetição de operação
    {
       
       system("cls"); //Responsável por limpar a tela
       
       setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
    
       printf("### Cartório da EBAC ###\n\n"); //Inicio do menu - Como aparecem as opções ao cliente
       printf(" Escolha a opção desejada no menu:\n\n");
       printf(" \t1 - Registrar nomes\n");
       printf(" \t2 - Consultar nomes\n");
       printf(" \t3 - Deletar nomes\n\n");
       printf("Opção: "); //Final no menu
    
       scanf("%d", &opcao); //Armazenando a escolha do usuário 
    
       system("cls"); //Responsável por limpar a tela
       
       switch(opcao) //Inicio da seleção do menu
       {
            case 1:
            registro(); //Chamada de funções
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            
            default: //Quando não há opção mapeada
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
        }
    
       
}
}
