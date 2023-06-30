#include<stdio.h> // biblioteca de comunicação com o usuário
#include<stdlib.h> // biblioteca de alocação de espaço em memória
#include<locale.h> // biblioteca de alocação de texto por região
#include<string.h> // biblioteca string

//funções separadas que podem ser "chamadas" a qualquer hora no programa
int cadastro()
{
	char arquivo[40]; // [] - sempre que for criada uma variável, precisa ter um valor por questão de aloção de memória
	char cpf[40]; // variável cacacter vai receber texto - [] por ser uma string só recebe texto - 40 variáveis de "cpf"
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	///// char é uma var caracter - também pode receber número e funciona melhor no gerenciamente de strings
	///// string é um conj de variáveis
	
	///////////// CPF ///////////////// - 
	
	printf("\n - Digite o CPF que deseja cadastrar (sem ponto/traço): \n");
	scanf("%s" , cpf); // até 40 caracteres, ele vai armazenar dentro de cpf
	
	strcpy(arquivo , cpf); // strcpy copia os valores da string, nesse caso, copia do cpf para o arquivo
	
	FILE *file; // sistema está mandando acessar o FILE e criar um arquivo file no banco de dados (pasta do sistema)
	
	file = fopen(arquivo , "w"); // cria um novo arquivo - "w" que vem de write (escrever) - escreve dentro da var arquivo
	fprintf(file,cpf); //salva dentro de file, o valor da variável cpf
	fclose(file); // fecha o arquivo - importante, sempre fechar 
	
	file = fopen(arquivo , "a"); // abre arquivo que foi criada - "a"  atualizar o arquivo criado 
	fprintf(file, ", "); // inclui a "\n" dentro do arquivo - da espaço entre os dados
	fclose(file); // sempre fechar o file!
	
	
	// a parte acima é diferente, porque tudo vai ser "acrescentado" nela a partir daqui, a var arquivo é o cpf (foi "igualada"), 
	//  abaixo, todos os dados serão acresentados a var arquivo que acima recebeu o valor de cpf
	// "w" escreveu o cpf dentro da var arquivo depois é usado "a" pra atualizar/acresentar os dados a seguir para dentro da var arquivo
	// resumidamente, var arquivo = cpf - o arquivo na pasta do sistema, está nomeado com o numero do cpf
	
	///////////// Nome ///////////////// - 
	
	printf("\n - Digite o nome que deseja cadastrar: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo , "a"); // abre a var arquivo - atualiza/acresenta ("a") com o "valor" de nome  
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo , "a"); // abre arquivo que foi criada - "a"  atualizar o arquivo criado 
	fprintf(file, ", "); // inclui a "," dentro do arquivo - da espaço entre os dados
	fclose(file); // sempre fechar o file!
	
	///////////// Sobrenome ///////////////// - 
	
	printf("\n - Digite o sobrenome que deseja cadastrar: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo , "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo , "a");	
	fprintf(file, ", "); 
	fclose(file); 
	
	///////////// Cargo ///////////////// - 
	
	printf("\n - Digite o cargo: \n ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo , "a");	
	fprintf(file, ", "); 
	fclose(file); 
	
	system("pause");
		
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); // Uma função não reconhece outra, por estar em uma função diferente "int" ,
	// é necessário acrecsentar este comando todas as vezes que for utilizar acentos em português
	
	
	// os dados que serão consultados, estão nomeados com cpf que foi cadastrado anteriormente (cada cadastro será criado um novo arquivo na pasta do sistema)
	char cpf [40]; //  por ser uma nova função (consulta), o sistema não reconhece a que foi criada na função anterior - necessário criar outra aqui para consultar/ler 
	char conteudo[200]; // para o sistema mostrar o que tem no arquivo consultado, precisa ser armazenado em uma variável, no caso "conteudo"
	
	printf(" \nDigite o CPF (sem ponto/traço) que deseja consultar: \n ");
	scanf("%s", cpf);
	
	FILE *file; // consulta arquivo a seguir
	file = fopen(cpf,"r"); // manda o sistema ler o arquivo cpf que está armazenado dentro da pasta do sistema 
	
	
	if (file == NULL) // se o arquivo não for encontrado, não existir, o sistema retorna a seguinte mensagem abaixo
	{
		printf(" \n - Arquivo não encontrado\n");
	}
	
	while(fgets(conteudo, 200 , file ) != NULL) // fgets (busca arquivo) - enquanto (while) - tudo que estiver dentro de file será armazenado dentro de conteudo
	// até 200 carac//até não achar mais caracteres ai ele para (!=NULL)
	
	{
		printf("\n- Informações requeridas: ");
		printf("%s", conteudo); // printa na tela o que está em conteúdo, no caso, o que foi pedido pelo usuário
		printf("\n\n"); // apenas pular linha - estético
	}
	
	
	fclose(file);

	system("pause");
}



int deletar()
{
	
	char cpf[40];
	
	printf(" - Digite o CPF que deseja deletar:\n");
	scanf("%s", cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r: read - ler a o cpf dentro da pasta
	
		
	if(file == NULL)
	{
		printf(" - O CPF digitado não foi encontrado, verifique e tente novamente: \n");
	}
	else
		printf("CPF deletado com sucesso!\n"); 
	
	
	fclose(file);
			
	system("pause");
	
		
}


int main()
{
	
	int opcao=0; // variável
	int repet=1; // variável repetição
	
	for	(repet=1;repet=1;) // vai repetir indefinidamente a partir daqui
	{
		
		system("cls"); // limpa a tela após a repetição
		
		
		setlocale(LC_ALL, "Portuguese"); // define a lignuagem 
		
		printf(" ### Cadastro de Alunos EBAC ### \n\n");
		printf("Escolha a opção desejada: \n\n"); // inicio do menu
		printf("\t1 - Fazer um Cadastro \n");
		printf("\t2 - Consultar um Cadastro \n");
		printf("\t3 - Deletar dado Cadastrado \n\n\n");
		printf("\nOpção:  "); // fim do menu
	
		scanf("%d",&opcao); // faz um scan do que o usuário escolhe e armazena na variável opcao
	
		system("cls"); // limpa as mensagens da tela
		
		switch(opcao) // usando switch case ao invés de if - 
		{
			case 1: // switch usa : ao invés da chave
			cadastro();
			break; // encerra a instrução
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: // 
			printf("\n\n - Essa opçao não está diponível\n\n");
			system("pause");
			break;
		}
		
		
	
	
	}
	
	
	
	
	
}
