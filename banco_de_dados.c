#include<stdio.h> // biblioteca de comunica��o com o usu�rio
#include<stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include<locale.h> // biblioteca de aloca��o de texto por regi�o
#include<string.h> // biblioteca string

//fun��es separadas que podem ser "chamadas" a qualquer hora no programa
int cadastro()
{
	char arquivo[40]; // [] - sempre que for criada uma vari�vel, precisa ter um valor por quest�o de alo��o de mem�ria
	char cpf[40]; // vari�vel cacacter vai receber texto - [] por ser uma string s� recebe texto - 40 vari�veis de "cpf"
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	///// char � uma var caracter - tamb�m pode receber n�mero e funciona melhor no gerenciamente de strings
	///// string � um conj de vari�veis
	
	///////////// CPF ///////////////// - 
	
	printf("\n - Digite o CPF que deseja cadastrar (sem ponto/tra�o): \n");
	scanf("%s" , cpf); // at� 40 caracteres, ele vai armazenar dentro de cpf
	
	strcpy(arquivo , cpf); // strcpy copia os valores da string, nesse caso, copia do cpf para o arquivo
	
	FILE *file; // sistema est� mandando acessar o FILE e criar um arquivo file no banco de dados (pasta do sistema)
	
	file = fopen(arquivo , "w"); // cria um novo arquivo - "w" que vem de write (escrever) - escreve dentro da var arquivo
	fprintf(file,cpf); //salva dentro de file, o valor da vari�vel cpf
	fclose(file); // fecha o arquivo - importante, sempre fechar 
	
	file = fopen(arquivo , "a"); // abre arquivo que foi criada - "a"  atualizar o arquivo criado 
	fprintf(file, ", "); // inclui a "\n" dentro do arquivo - da espa�o entre os dados
	fclose(file); // sempre fechar o file!
	
	
	// a parte acima � diferente, porque tudo vai ser "acrescentado" nela a partir daqui, a var arquivo � o cpf (foi "igualada"), 
	//  abaixo, todos os dados ser�o acresentados a var arquivo que acima recebeu o valor de cpf
	// "w" escreveu o cpf dentro da var arquivo depois � usado "a" pra atualizar/acresentar os dados a seguir para dentro da var arquivo
	// resumidamente, var arquivo = cpf - o arquivo na pasta do sistema, est� nomeado com o numero do cpf
	
	///////////// Nome ///////////////// - 
	
	printf("\n - Digite o nome que deseja cadastrar: \n");
	scanf("%s",nome);
	
	file = fopen(arquivo , "a"); // abre a var arquivo - atualiza/acresenta ("a") com o "valor" de nome  
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo , "a"); // abre arquivo que foi criada - "a"  atualizar o arquivo criado 
	fprintf(file, ", "); // inclui a "," dentro do arquivo - da espa�o entre os dados
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
	
	setlocale(LC_ALL, "Portuguese"); // Uma fun��o n�o reconhece outra, por estar em uma fun��o diferente "int" ,
	// � necess�rio acrecsentar este comando todas as vezes que for utilizar acentos em portugu�s
	
	
	// os dados que ser�o consultados, est�o nomeados com cpf que foi cadastrado anteriormente (cada cadastro ser� criado um novo arquivo na pasta do sistema)
	char cpf [40]; //  por ser uma nova fun��o (consulta), o sistema n�o reconhece a que foi criada na fun��o anterior - necess�rio criar outra aqui para consultar/ler 
	char conteudo[200]; // para o sistema mostrar o que tem no arquivo consultado, precisa ser armazenado em uma vari�vel, no caso "conteudo"
	
	printf(" \nDigite o CPF (sem ponto/tra�o) que deseja consultar: \n ");
	scanf("%s", cpf);
	
	FILE *file; // consulta arquivo a seguir
	file = fopen(cpf,"r"); // manda o sistema ler o arquivo cpf que est� armazenado dentro da pasta do sistema 
	
	
	if (file == NULL) // se o arquivo n�o for encontrado, n�o existir, o sistema retorna a seguinte mensagem abaixo
	{
		printf(" \n - Arquivo n�o encontrado\n");
	}
	
	while(fgets(conteudo, 200 , file ) != NULL) // fgets (busca arquivo) - enquanto (while) - tudo que estiver dentro de file ser� armazenado dentro de conteudo
	// at� 200 carac//at� n�o achar mais caracteres ai ele para (!=NULL)
	
	{
		printf("\n- Informa��es requeridas: ");
		printf("%s", conteudo); // printa na tela o que est� em conte�do, no caso, o que foi pedido pelo usu�rio
		printf("\n\n"); // apenas pular linha - est�tico
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
		printf(" - O CPF digitado n�o foi encontrado, verifique e tente novamente: \n");
	}
	else
		printf("CPF deletado com sucesso!\n"); 
	
	
	fclose(file);
			
	system("pause");
	
		
}


int main()
{
	
	int opcao=0; // vari�vel
	int repet=1; // vari�vel repeti��o
	
	for	(repet=1;repet=1;) // vai repetir indefinidamente a partir daqui
	{
		
		system("cls"); // limpa a tela ap�s a repeti��o
		
		
		setlocale(LC_ALL, "Portuguese"); // define a lignuagem 
		
		printf(" ### Cadastro de Alunos EBAC ### \n\n");
		printf("Escolha a op��o desejada: \n\n"); // inicio do menu
		printf("\t1 - Fazer um Cadastro \n");
		printf("\t2 - Consultar um Cadastro \n");
		printf("\t3 - Deletar dado Cadastrado \n\n\n");
		printf("\nOp��o:  "); // fim do menu
	
		scanf("%d",&opcao); // faz um scan do que o usu�rio escolhe e armazena na vari�vel opcao
	
		system("cls"); // limpa as mensagens da tela
		
		switch(opcao) // usando switch case ao inv�s de if - 
		{
			case 1: // switch usa : ao inv�s da chave
			cadastro();
			break; // encerra a instru��o
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default: // 
			printf("\n\n - Essa op�ao n�o est� dipon�vel\n\n");
			system("pause");
			break;
		}
		
		
	
	
	}
	
	
	
	
	
}
