#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/*
    Arquivo chamado "arquivo" era para me auxiliar na hora de excluir em meu arquivo ultilizado "inserir_auxiliar"
    "Notas" esta contidos a situa��o de alunos cadatrados.

	S� faltou o excluir ele excluiria sobre escrevendo de arquivo chamado "arquivo" com a altera��o a "inserir_auxiliar
	(O excluir funcionaria em "Notas" tamb�m);

*/

struct aluno {
	int matricula;
	char nome[20];
	char eMail[30];
	int turma;
	float nota1, nota2;
}escola[100];

void inserir(aluno escola[100], int p) {
	FILE *ponteiroPrincipal;
	ponteiroPrincipal = fopen("auxiliar_inserir.txt", "a");
	printf("Numero de matricula: ");
	scanf("%d", &escola[p].matricula);
	fprintf(ponteiroPrincipal, "%d ", escola[p].matricula);
	printf("Nome do aluno: ");
	scanf("%s", escola[p].nome);
	fprintf(ponteiroPrincipal, "Aluno: %s ", escola[p].nome);
	printf("Insira o eMail: ");
	scanf("%s", escola[p].eMail);
	fprintf(ponteiroPrincipal, "eMai: %s ", escola[p].eMail);
	printf("Informe a turma: ");
	scanf("%d", &escola[p].turma);
	fprintf(ponteiroPrincipal, "Turma: %d\n", escola[p].turma);
	printf("Lido com sucesso! \n");
	fclose(ponteiroPrincipal);

}


bool pesquisa (aluno escola, int matricula) {
	FILE *ponteiroPrincipal;
	int in,valor,cont=0;
	char aluno[5], nome[10], email[5], mail[20], turma[5];
	ponteiroPrincipal = fopen("auxiliar_inserir.txt", "r+");
	do {
	    fscanf(ponteiroPrincipal,"%d %s %s %s %s %s %d", &in,aluno,nome,email,mail,turma,&valor);
	    if (in == matricula) {
		    printf("Matricula encontrada: ");
		    printf("%d\n", in);
		    printf("%s %s\n%s %s\n%s %d\n", aluno,nome,email,mail,turma,valor);
	    }  else {
	    	cont=cont+1;
		}
	} while (in != matricula && cont < 100);
	if (in != matricula) {
		system("pause");
		return false;
	} else {
		return true;
	}
	fclose(ponteiroPrincipal);
}
void trocaArquivo(aluno escola) {
	int in,valor;
	char aluno[20],nome[20],email[6],mail[30],turma[7];
	FILE *ponteiroAuxiliar, *ponteiroPrincipal;
	ponteiroAuxiliar = fopen ("arquivo.txt", "r");
	ponteiroPrincipal = fopen ("auxiliar_inserir.txt", "w");
	while (fscanf(ponteiroAuxiliar,"%d %s %s %s %s %s %d", &in,aluno,nome,email,mail,turma,&valor) != EOF) {
		fprintf(ponteiroPrincipal, "%d %s %s %s %s %s %d \n", in,aluno,nome,email,mail,turma,valor);
		printf("-\n");
	}
	printf("Removido com sucesso\n");
}

void excluir (aluno escola, int matricula) {
	FILE *ponteiroPrincipal;
	FILE *ponteiroAuxiliar;
	int in,valor;
	char aluno[5], nome[10], email[5], mail[20], turma[5];
	ponteiroPrincipal = fopen("auxiliar_inserir.txt", "r+");
	ponteiroAuxiliar = fopen("arquivo.txt", "w");
    while (fscanf(ponteiroPrincipal,"%d %s %s %s %s %s %d", &in,aluno,nome,email,mail,turma,&valor) != EOF) {
    	if (in != matricula) {
    		fprintf(ponteiroAuxiliar, "%d %s %s %s %s %s %d \n", in,aluno,nome,email,mail,turma,valor);
		}
	}
	trocaArquivo(escola);
	fclose(ponteiroPrincipal);
	fclose(ponteiroAuxiliar);
//	while (fscanf(ponteiro,"%d %s %s %s %s %s %d", &in,aluno,nome,email,mail,turma,&valor) != EOF) {
//		fprintf(aux, "%d %s %s %s %s %s %d \n", in,aluno,nome,email,mail,turma,valor);
//	}
}

void inserirNotas (aluno escola[100], int matricula, int p) {
	FILE *Notas;
	Notas = fopen("Notas.txt", "a");
	    fprintf(Notas, "%d ", matricula);
	    printf("Insira o nome: ");
	    scanf("%s", escola[p].nome);
	    fprintf(Notas, "%s ", escola[p].nome);
		printf("Informe a nota1: ");
		scanf("%f", &escola[p].nota1);
		fprintf(Notas, "%2.2f ", escola[p].nota1);
		printf("Informe a nota2: ");
		scanf("%f", &escola[p].nota2);
		fprintf(Notas, "%2.2f ", escola[p].nota2);
		if (((escola[p].nota1 + escola[p].nota2) / 2) >= 7) {
			fprintf(Notas, "Aprovado\n");
			printf("Aluno aprovado!\n");
		} else {
			fprintf(Notas, "Reprovado\n");
			printf("Aluno reprovado\n");
		}

	fclose(Notas);
}

void listaNotas(aluno escola) {
	FILE *Notas;
	int matricula;
	float nota1,nota2;
	char nome[20],resultado[10];
	Notas = fopen ("Notas.txt", "r");
	if (Notas != NULL) {
		while( fscanf(Notas, "%d %s %f %f %s", &matricula, nome, &nota1,&nota2,resultado) != EOF ) {
			printf("=========== SITUACAO DO ALUNO ================\n\n");
			printf("Matricula: %d\n", matricula);
			printf("Nome: %s\n", nome);
			printf("Nota1: %2.2f\n", nota1);
			printf("Nota2: %2.2f\n", nota2);
			printf("Resultado: %s\n\n", resultado);
		}
	}
}

int main () {
    char linha [100];
    int i=1,r=0,matric,x=1,espera;
	char l [200];
	if (r==0) {
		FILE *ponteiroAuxiliar;
		ponteiroAuxiliar = fopen("arquivo.txt", "w");
			if (ponteiroAuxiliar == NULL) {
	           printf("Nao foi possivel abrir o arquivo!\n");
		       return 0;
	        }
	        fclose(ponteiroAuxiliar);
	}
    int matriculaTeste;
    while (r != 6) {
    printf("                        .......................                             \n");
	printf("                        | Program - [arquivo] |                             \n");
	printf("                        .......................                             \n\n");
   	printf("=======================================================================\n");
	printf(" 01 - Incluir aluno                                                   |\n");
	printf(" 02 - Excluir aluno                                                   |\n");
	printf(" 03 - Pesquisar aluno                                                 |\n");
	printf(" 04 - Lancar notas                                                    |\n");
	printf(" 05 - Lista notas                                                     |\n");
	printf(" 06 - Sair                                                            |\n");
    printf("=======================================================================\n");
	printf("\n");
	scanf("%d", &r);
	printf("\n");
	if (r == 1) {
		printf("===========================================\n");
		printf("      Testa validade[disponibilidade]      \n");
		printf("===========================================\n");
		scanf("%d", &matriculaTeste);
		if (pesquisa (escola[100], matriculaTeste) == false) {
			inserir(escola,i);
		    i++;
		}
		system("pause");
		system("cls");
	} else {
		if (r == 3) {
			printf("Informe o numero da matricula: ");
			scanf("%d", &matric);
			printf("===========================================\n");
			pesquisa(escola[100],matric);
			printf("===========================================\n");
			system("pause");
			system("cls");
		} else {
			if (r == 2) {
				printf("Informe o numero da matricla[EXCLUIR]: ");
				scanf("%d", &matric);
				excluir(escola[100],matric);
			} else {
				if (r == 4) {
					printf("=============  LARNCAR NOTAS  ================\n");
					printf("Informe sua matricula: ");
					scanf("%d", &matric);
					if (pesquisa(escola[100],matric) == true) {
						printf("\n");
						printf("===== INFORMACOES ======\n\n");
						inserirNotas(escola,matric,x);
						system("pause");
			            system("cls");
						x++;
					} else {
						if (pesquisa(escola[100],matric) == false) {
							printf("Numero de matricula invalido... \n");
							system("pause");
			                system("cls");
						}
					}
				}
			}
		}
	}
	if (r == 5) {
	listaNotas(escola[100]);
	system("pause");
	system("cls");
}
}

	printf("======================= FINALIZADO COM SUCESSO =========================\n");
	system("pause");
    return 0;
}
// bmthmurilo@hotmail.com
