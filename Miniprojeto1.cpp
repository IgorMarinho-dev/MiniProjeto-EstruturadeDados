#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include 	<locale.h>

#define MAX 60

typedef struct aln {
	char	nome[50];
	char	RGM[50];
} Aluno;

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

int	main() {
	setlocale(0,"Portuguese");
	
	Lista	myLista;
	Aluno alu;
	int pos = 0;
	char resp = 's';
	
	myLista = criar();
	
	while(resp == 's') {
		printf("Nome:");
		gets(alu.nome);
		printf("RGM:");
		gets(alu.RGM);

		inserirOrdenada(&myLista, alu);
		pos++;
		
		printf("Deseja continuar s/n\n");
		resp = getchar();
		fflush(stdin);
	}
	
	mostrar(&myLista);
	
	getchar();
}
