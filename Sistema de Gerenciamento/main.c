#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 30
#define MAX_SENHA 10
#define MAX_CLIENTES 100


struct dadosMensais {
    int quantidadeResiduos; // Numero inteiro representando a quantidade de residuos tratados mensalmente.
    float custoEstimado; // Valor em ponto flutuante representando o custo estimado associado ao tratamento mensal de residuos.
};

struct cadastroFuncionario {
    char nomeFuncionario[100];
    char dataNascimento[9];
    char estadoCivil[100];
    char email[100];
    char cpf[12];
    char rg[17];
    char tel[12];
    struct dadosMensais dadosMensais[12]; // Array para armazenar dados de 12 meses.
};

struct cadastroCliente {
    char nomeCliente[100];
    char nomeEmpresa[100];
    char cnpj[15];
    char razaoSocial[100];
    char nomeFantasia[100];
    char tel[12];
    char cidadeEstado[100];
    char email[100];
    char dataAbertura[15];
    struct dadosMensais dadosMensais[12];
    char regiao[50];
    char tipoIndustrial[50];
    float volumeResiduos;
};

struct Usuario {
    char nome[MAX_NOME + 1];
    char senha[MAX_SENHA + 1];
};

struct relatorioGlobal{
    int totalClientes;
    float totalCustos;

};

// Funcao para gerar relatarios globais
void gerarRelatorioGlobal(struct cadastroCliente *clientes, int totalClientes, struct relatorioGlobal *relatorio) {
    relatorio->totalClientes = totalClientes;
    relatorio->totalCustos = 0;

    for (int i = 0; i < totalClientes; i++) {
        for (int j = 0; j < 12; j++) {
             relatorio->totalCustos += clientes[i].dadosMensais[j].custoEstimado;
        }
    }
}

// Fun��o para exibir relat�rios globais na tela
void exibirRelatorioGlobal(struct relatorioGlobal *relatorio) {

    // Implemente a l�gica para exibir as estat�sticas globais na tela
    printf("Total de Clientes: %d\n", relatorio->totalClientes);
    printf("Custo Total: %.2f\n", relatorio->totalCustos);
    // ... outras estat�sticas ...

}

void salvarRelatorioGlobal(struct relatorioGlobal *relatorio, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "Total de Clientes: %d\n", relatorio->totalClientes);
    fprintf(arquivo, "Custo Total: %.2f\n", relatorio->totalCustos);
    fclose(arquivo);

}

void limparBufferEntrada(){ // Essa fun��o � usada para limpar o buffer de entrada ap�s a leitura de strings com fgets.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void criptografarDados(struct cadastroCliente *cliente){
    for (int i = 0; i < strlen(cliente->cnpj); i++) {
        cliente->cnpj[i] = cliente->cnpj[i] + 5; //Exemplo para substitui��o.
    }
    for (int i = 0; i < strlen(cliente->email); i++) {
        cliente->email[i] = cliente->email[i] + 3; //Exemplo para substitui��o.
    }
}

void descriptografarDados(struct cadastroCliente *cliente){
    for (int i = 0; i < strlen(cliente->cnpj); i++) {
        cliente->cnpj[i] = cliente->cnpj[i] - 1; // Reverte o deslocamento
    }
    for (int i = 0; i < strlen(cliente->email); i++) {
        cliente->email[i] = cliente->email[i] - 1; // Reverte o deslocamento
    }
}

void atualizarDadosMensais(struct dadosMensais *dados) {
        for (int i = 0; i < 12; i++) {
        printf("\n Mes %d\n", i + 1);
        printf("Quantidade de Residuos Tratados: ");
        scanf("%d", &dados[i].quantidadeResiduos);

        printf("Custo Estimado: ");
        scanf("%f", &dados[i].custoEstimado);
    }
}

void visualizarDadosMensais(const struct dadosMensais *dados, int totalMeses) {
    printf("\nVisualizacao Mensal de Residuos\n");
    printf("================================");

    for (int i = 0; i < totalMeses; i++) {
        printf("\n Mes %d\n", i + 1);
        printf("Quantidade de Residuos Tratados: %d\n", dados[i].quantidadeResiduos);
        printf("Custo Estimado: %2.f\n", dados[i].custoEstimado);
    }
}

void escreverDadosMensais(struct dadosMensais *dados, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "w");

    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for(int i = 0; i < 12; i++) {
        fprintf(arquivo, "%d %.2f\n", dados[i].quantidadeResiduos, dados[i].custoEstimado);
    }

    fclose(arquivo);
}

void cadastrarFuncionario(struct cadastroFuncionario *funcionario) {

    printf("\n  Cadastro de Funcionario\n");
    printf("==============================\n");

    printf("\nNome do Funcionario: ");
    fgets(funcionario->nomeFuncionario, sizeof(funcionario->nomeFuncionario), stdin);
    funcionario->nomeFuncionario[strcspn(funcionario->nomeFuncionario, "\n")] = '\0';

    printf("Data de Nascimento: ");
    fgets(funcionario->dataNascimento, sizeof(funcionario->dataNascimento), stdin);
    funcionario->dataNascimento[strcspn(funcionario->dataNascimento, "\n")] = '\0';

    printf("Estado Civil: ");
    fgets(funcionario->estadoCivil, sizeof(funcionario->estadoCivil), stdin);
    funcionario->estadoCivil[strcspn(funcionario->estadoCivil, "\n")] = '\0';

    printf("Email: ");
    fgets(funcionario->email, sizeof(funcionario->email), stdin);
    funcionario->email[strcspn(funcionario->email, "\n")] = '\0';

    printf("CPF: ");
    fgets(funcionario->cpf, sizeof(funcionario->cpf), stdin);
    funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';

    printf("RG: ");
    fgets(funcionario->rg, sizeof(funcionario->rg), stdin);
    funcionario->rg[strcspn(funcionario->rg, "\n")] = '\0';

    printf("Telefone: ");
    fgets(funcionario->tel, sizeof(funcionario->tel), stdin);
    funcionario->tel[strcspn(funcionario->tel, "\n")] = '\0';

    printf("\nFuncionario cadastrado com sucesso!\n");
    printf("\nPressione Enter.\n");
    limparBufferEntrada();

}

void cadastrarCliente(struct cadastroCliente *cliente) {

    printf("\n  Cadastro de Cliente\n");
    printf("========================\n");

    printf("\nNome do Cliente: ");
    fgets(cliente->nomeCliente, sizeof(cliente->nomeCliente), stdin);
    cliente->nomeCliente[strcspn(cliente->nomeCliente, "\n")] = '\0';

    printf("Nome da Empresa: ");
    fgets(cliente->nomeEmpresa, sizeof(cliente->nomeEmpresa), stdin);
    cliente->nomeEmpresa[strcspn(cliente->nomeEmpresa, "\n")] = '\0';

    criptografarDados(cliente);
    printf("CNPJ: ");
    fgets(cliente->cnpj, sizeof(cliente->cnpj), stdin);
    cliente->cnpj[strcspn(cliente->cnpj, "\n")] = '\0';
    descriptografarDados(cliente);

    printf("Razao Social: ");
    fgets(cliente->razaoSocial, sizeof(cliente->razaoSocial), stdin);
    cliente->razaoSocial[strcspn(cliente->razaoSocial, "\n")] = '\0';

    printf("Nome Fantasia: ");
    fgets(cliente->nomeFantasia, sizeof(cliente->nomeFantasia), stdin);
    cliente->nomeFantasia[strcspn(cliente->nomeFantasia, "\n")] = '\0';

    printf("Telefone: ");
    fgets(cliente->tel, sizeof(cliente->tel), stdin);
    cliente->tel[strcspn(cliente->tel, "\n")] = '\0';

    printf("Cidade e Estado: ");
    fgets(cliente->cidadeEstado, sizeof(cliente->cidadeEstado), stdin);
    cliente->cidadeEstado[strcspn(cliente->cidadeEstado, "\n")] = '\0';

    criptografarDados(cliente);
    printf("Email: ");
    fgets(cliente->email, sizeof(cliente->email), stdin);
    cliente->email[strcspn(cliente->email, "\n")] = '\0';
    descriptografarDados(cliente);

    printf("Data de Abertura: ");
    fgets(cliente->dataAbertura, sizeof(cliente->dataAbertura), stdin);
    cliente->dataAbertura[strcspn(cliente->dataAbertura, "\n")] = '\0';

    printf("Regiao: ");
    fgets(cliente->regiao, sizeof(cliente->regiao), stdin);
    cliente->regiao[strcspn(cliente->regiao, "\n")] = '\0';

    printf("Volume de Residuos: ");
    scanf("%f", &cliente->volumeResiduos);
    limparBufferEntrada();

    printf("\nCliente cadastrado com sucesso! Pressione Enter.\n");
    limparBufferEntrada();
}

int main() {

    int opcaoMenu = -1;

        struct Usuario p[1];

        // Define o nome e senha de usu�rio padr�o.
        strcpy(p[0].nome, "usuario");
        strcpy(p[0].senha, "123");

        printf("       TELA DE LOGIN...\n   ");
        printf("=======================\n");

        char nome[MAX_NOME + 1];
        char senha[MAX_SENHA + 1];

        printf("Nome de usuario: ");
        scanf("%30s", nome);
        limparBufferEntrada();

        printf("Digite sua senha: ");
        scanf("%10s", senha);
        limparBufferEntrada();

        printf("\n");

        if (strcmp(nome, p[0].nome) == 0 && strcmp(senha, p[0].senha) == 0) {
            printf("Usuario logado!\n\n");
        } else {
            printf("Usuario ou senha incorreta\n");
            return 0;
    }

    struct cadastroFuncionario funcionario; // Instancia da estrutura cadastroFuncionario.
    struct dadosMensais dados[12];
    struct relatorioGlobal relatorio;
    struct cadastroCliente cliente[MAX_CLIENTES];
    int totalClientes = 0;

        while(opcaoMenu != 0) {

            printf("\n  MENU PRINCIPAL\n");
            printf("=======================\n");
            printf("\n1) Cadastro de Cliente\n");
            printf("2) Cadastro de Funcionario\n");
            printf("3) Atualizacao Mensal de Residuos\n");
            printf("4) Gerar Relatorio Global\n");
            printf("5) Visualizar Dados Mensais\n");  // Adicionada opcao para visualizar dados mensais
            printf("\nDigite '0' para sair ou Escolha uma opcao:");
            scanf("%d", &opcaoMenu);
            limparBufferEntrada();

        switch (opcaoMenu) {
            case 1:
                if (totalClientes < MAX_CLIENTES) {
                    cadastrarCliente(&cliente[totalClientes]);
                    totalClientes++;
                } else {
                    printf("Limite de clientes atingido.\n");
                }
                break;
            case 2:
                cadastrarFuncionario(&funcionario);
                break;
            case 3:
                for (int i = 0; i < totalClientes; i++) {
                     printf("=======================\n");
                    printf("\n----Atualizacao Mensal de Residuos para o Cliente: %s\n", cliente[i].nomeCliente);
                    atualizarDadosMensais(cliente[i].dadosMensais);
                }
                escreverDadosMensais(cliente[0].dadosMensais, "dados_mensais.txt");
                break;
            case 4:
                printf("\n");
                printf("---- Relatorio Global ----");
                printf("\n");
                gerarRelatorioGlobal(cliente, totalClientes, &relatorio);
                exibirRelatorioGlobal(&relatorio);
                break;
            case 5:
                for(int i = 0; i < totalClientes; i++) {
                    printf("\nVisualizacao Mensal de Residuos para o Cliente: %s\n", cliente[i].nomeCliente);
                    visualizarDadosMensais(cliente[i].dadosMensais, 12);
                }
                break;
            case 0:
                printf("\nSaindo do programa... Pressione Enter novamente.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}





