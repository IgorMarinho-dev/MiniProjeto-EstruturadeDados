#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include 	<locale.h>

#define MAX 60

typedef struct aln {
	char	nome[50];
	char	RGM[50];
} Aluno;

	char	acessar[50];

typedef struct turma {
	Aluno	alunos[MAX];
	int	ultimo_aluno;
} Lista;

Lista	criar () {
	Lista turma;
	
	turma.ultimo_aluno = -1;
	
	return turma;
}

int isVazia(Lista * turma) {
	return (turma->ultimo_aluno == -1);
}

int isCheia(Lista * turma) {
	return (turma->ultimo_aluno == (MAX -1));
}

Aluno * getAluno(Lista * turma, int pos) {
	if ((pos > turma->ultimo_aluno) || (pos < 0))
		return NULL;
		
	return &(turma->alunos[pos]);
}

int getPosicao(Lista * turma, char RGM[]) {
	int	i;
	
	for (int i = 0; i <= turma->ultimo_aluno; i++) {
		if (strcmp(turma->alunos[i].RGM, RGM) == 0)
			return i;
	}
			
	return -1;
}

int deslocaDireita(Lista * turma, int pos) {
    int i;

    for (i = turma->ultimo_aluno + 1; i>pos; i--)
        turma->alunos[i] = turma->alunos[i-1];
}

int inserirPos (Lista * turma, int pos, Aluno dado) {
    if (isCheia(turma) || (pos > turma->ultimo_aluno + 1) || (pos < 0))
        return 0;

    deslocaDireita(turma, pos);
    turma->alunos[pos] = dado;
    (turma->ultimo_aluno)++;
    return 1;
}

int deslocaEsquerda(Lista * turma, int pos) {
    int i;

    for (i = pos; i < turma->ultimo_aluno ; i++)
        turma->alunos[i] = turma->alunos[i+1];
}

int getPosicaoInsercaoOrdenada(Lista * turma, char RGM[]) {
    int i;
    
    for (i = 0; i <= turma->ultimo_aluno; i++) {
        if (strcmp(turma->alunos[i].RGM, RGM) > 0)
            return i;
    }

    return i;
}

int inserirOrdenada (Lista * turma, Aluno dado) {
	int pos;
	
    if (isCheia(turma))
        return 0;

	if (isVazia(turma))
		pos = 0;
	else
	    pos = getPosicaoInsercaoOrdenada(turma, dado.RGM);
	
	inserirPos (turma, pos, dado);	

    return 1;
}

void	mostrar(Lista * turma){
	
	int i;
	
	printf("Lista de alunos\n");
	for(i = 0; i <= turma->ultimo_aluno; i++) {
		printf("Nome: %s\t", turma->alunos[i].nome);
		printf("RGM: %s\n", turma->alunos[i].RGM);
	}
}

                typedef struct disc {
                        char nome[50];
                        struct disc* prox;
                } Disciplina;

int menu() {
        int op;
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar\n");
        printf("2 - Mostrar\n");
        printf("3 - Buscar\n");
        printf("4 - Remover\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);
        return op;
}

Disciplina* criarDisciplina(char* nome) {
        Disciplina* nova = (Disciplina*)malloc(sizeof(Disciplina));
        if (nova) {
                strcpy(nova->nome, nome);
                nova->prox = NULL;
        }
        return nova;
}

void adicionarDisciplina(Disciplina** lista, char* nome) {
        Disciplina* nova = criarDisciplina(nome);
        if (*lista == NULL) {
                *lista = nova;
        } else {
                Disciplina* atual = *lista;
                while (atual->prox) atual = atual->prox;
                atual->prox = nova;
        }
}

void mostrarDisciplinas(Disciplina* lista) {
        if (!lista) {
                printf("(sem disciplinas)\n");
                return;
        }
        Disciplina* atual = lista;
        printf("[");
        int primeira = 1;
        while (atual) {
                if (!primeira) printf(", ");
                printf("%s", atual->nome);
                primeira = 0;
                atual = atual->prox;
        }
        printf("]\n");
}

void liberarDisciplinas(Disciplina* lista) {
        while (lista) {
                Disciplina* prox = lista->prox;
                free(lista);
                lista = prox;
        }
}

int remover(Lista* turma, char RGM[]) {
        int pos = getPosicao(turma, RGM);
        if (pos == -1) {
                printf("Aluno não encontrado!\n");
                return 0;
        }
        for (int i = pos; i < turma->ultimo_aluno; i++) {
                turma->alunos[i] = turma->alunos[i + 1];
        }
        turma->ultimo_aluno--;
        printf("Aluno removido!\n");
        return 1;
}

int	main() {
	setlocale(0,"Portuguese");
	
	Lista	myLista;
	Aluno alu;
	int pos = 0;
	char resp = 's';
	
	myLista = criar();
	
	printf("=== SISTEMA DE GESTAO DE ALUNOS ===\n");
	
                        do {
                                int op = menu();
                                
                                switch(op) {
                                        case 1:
                                                printf("Nome:");
                                                gets(alu.nome);
                                                printf("RGM:");
                                                gets(alu.RGM);

                                                inserirOrdenada(&myLista, alu);
                                                pos++;
                                                
                                                printf("Deseja continuar s/n\n");
                                                resp = getchar();
                                                fflush(stdin);
                                                break;
                                                
                                        case 2:
                                                mostrar(&myLista);
                                                break;
                                                
                                        case 3:
                                                printf("Digite o RGM do aluno que deseja acessar:\n");
                                                gets(acessar);
                                                
                                                int mostrar = getPosicao(&myLista, acessar);
                                                
                                                if (mostrar == -1) {
                                                        printf("não existe.\n");
                                                }
                                                else {
                                                        printf("Nome: %s\n", myLista.alunos[mostrar].nome);
                                                        printf("RGM: %s\n", myLista.alunos[mostrar].RGM);
                                                }
                                                break;
                                                
                                        case 4:
                                                printf("Digite o RGM para remover:\n");
                                                gets(acessar);
                                                remover(&myLista, acessar);
                                                mostrar(&myLista);
                                                break;
                                }
                        } while(op != 0);
	
	getchar();
}