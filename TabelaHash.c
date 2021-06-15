#include <stdio.h>
#include <stdlib.h>

    // definindo uma constante para o "tamanho do vetor"
#define M 50

    // craindo um apelido para a struct Pessoa
typedef struct {
            int matricula; // chave de inserção
            char nome[50];
}Pessoa;

    // criando uma tabela de pessoas de tamanho "M"
Pessoa tabelaHash[M];

    // funcao que inicia a tabela com valor de codigo  -1
void iniciarTabela(){

        //variavel auxiliar para percorrer a tabela
        int i;

        // laço de repeticao que percorre a tabela
        for(i = 0; i < M; i++){
            tabelaHash[i].matricula = -1;
        }

}
    // funcao de espalhamento
    int gerarCodigoHash(int chave) {
        // a funcao retorna a chave pelo resto da divisao do tamanho do vetor (M)
        return chave % M;
    }

    //funcao para ler e retornar uma pessoa
    Pessoa lerPessoa(){
        Pessoa p;
        printf("Digite a matricula: ");
        scanf("%d", &p.matricula);
        scanf("%c");
        printf("Digite o nome: ");
        fgets(p.nome, 50 , stdin);
        return p;
    }

    // inserir uma pessoa na tabela
    void inserir(){
        Pessoa pes = lerPessoa();
        int indice = gerarCodigoHash(pes.matricula);
        while(tabelaHash[indice].matricula != -1)
            indice = gerarCodigoHash(indice + 1);
        tabelaHash[indice] = pes;
    }

    // buscar um elemento da tabela
    Pessoa* buscar(int chave){
        int indice = gerarCodigoHash(chave);
        while(tabelaHash[indice].matricula != -1){
            if(tabelaHash[indice].matricula == chave)
                return &tabelaHash[indice];
            else
                indice = gerarCodigoHash(indice + 1);
        }
        return NULL;
    }

    void imprimir(){
        int i;
        printf("\n ---------------------------------TABELA------------------------------\n");
        for(i=0; i < M; i++){
            if(tabelaHash[i].matricula != -1)
                printf("%d = %d \t %s", i,tabelaHash[i].matricula, tabelaHash[i].nome);
            else
                printf("%d =\n", i);
        }
        printf("\n---------------------------------------------------------------------------\n");
    }



int main(){
    int op, chave;
    Pessoa *p;

    iniciarTabela();

    //menu
    do{
        printf("1 - Inserir\n2  - Buscar\n3 - Imprimir\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                inserir();
                break;
            case 2:
                printf("Digite a matricula a ser buscada: ");
                scanf("%d", &chave);
                p = buscar(chave);
                if(p){
                    printf("\n\tMatricula: %d \tNome: %s\n", p->matricula, p->nome);
                } else{
                    printf("Matricula nao encontrada!\n");
                }
                break;
            case 3:
                imprimir();
                break;
            default:
                printf("Opcao Invalida!\n");
        }

    }while(op != 0);


    return 0;
    }
