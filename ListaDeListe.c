#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


//TO DO: modifica nume structuri -  Student
typedef struct student student;
typedef struct nodls nodls;
typedef struct nodlp nodlp;

typedef struct student {
	unsigned int id;
	char* nume;
	unsigned char nrMaterii;//0-255 - > este numeric
	int* note;
}student;

typedef struct nodls {
	student info;
	nodls* next;

}nodls;

typedef struct nodlp {
	nodls* info;
	nodlp* next;

}nodlp;


student initializareStudent(unsigned int id, const char* nume, unsigned char nrMaterii, int* note) {
	student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
	s.nrMaterii = nrMaterii;
	s.note = (int*)malloc(sizeof(int) * nrMaterii);
	for (int i = 0; i < nrMaterii; i++) {
		s.note[i] = note[i];
	}

	return s;

}

//ins in lista simpla/secundara
nodls* inserareLs(nodls* capls, student s) {
	//creare nod

	nodls* nou = (nodls*)malloc(sizeof(nodls));
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	//inserare
	if (capls == NULL) {
		capls = nou;

	}
	else {
		nodls* aux = capls;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	return capls;

}

//inserare lista principala
nodlp* inserareLp(nodlp* caplp, nodls* capls) {//adresa de inceput a listei secundare
	nodlp* nou = (nodlp*)malloc(sizeof(nodlp));
	nou->info = capls; //asteapta o adresa, am o adresa
	nou->next = NULL;
	if (caplp == NULL) {
		caplp = nou;
	}
	else {
		nodlp* aux = caplp;
		while (aux->next) { //while(aux) nu insereaza
			aux = aux->next;

		}
		aux->next = nou;

	}
	return caplp;
}
//afisare student
void afisareStudent(student s)
{
	printf("\n%u, %s, %u   ", s.id, s.nume, s.nume, s.nrMaterii);
	for (int i = 0; i < s.nrMaterii; i++) {
		printf("%d ", s.note[i]);
	}

}
//afisare ls
void afisareLs(nodls* capls) {
	nodls* aux = capls;
	while (aux) {
		printf("\n%u, %s, %u   ", aux->info.id, aux->info.nume, aux->info.nrMaterii);
		for (int i = 0; i < aux->info.nrMaterii; i++) {
			printf("%d ", aux->info.note[i]);
		}
		aux = aux->next;

		/*afisareStudent(aux->info);*/
	}
	printf("\n");
}

//afisare lp
void afisareLp(nodlp* caplp) {
	nodlp* aux = caplp;
	int contor = 1;
	while (aux) {
		printf("Sublista: %d", contor++);
		afisareLs(aux->info);
		aux = aux->next;
	}
}

void dezalocareLs(nodls* capls) {
	nodls* aux = capls;
	while (aux) {
		free(aux->info.nume);
		free(aux->info.note);

		nodls* temp = aux->next;
		free(aux);
		aux = temp;
	}
}

void dezalocareLp(nodlp* caplp) {
	nodlp* aux = caplp;
	while (aux) {
		dezalocareLs(aux->info);
		nodlp* temp = aux->next;
		free(aux);
		aux = temp;
	}
}




void main()
{
	int nr;
	student s;
	nodls* capls = NULL;
	nodlp* caplp = NULL;

	nodls* capls1 = NULL;

	char buffer[40];

	FILE* f = fopen("fisierListaDeListe.txt", "r");
	fscanf(f, "%d", &nr);

	for (int i = 0; i < nr; i++) {
		fscanf(f, "%u", &s.id);

		fscanf(f, "%s", buffer);
		s.nume = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy_s(s.nume, sizeof(char) * (strlen(buffer) + 1), buffer);

		fscanf(f, "%u", &s.nrMaterii);
		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
		for (int i = 0; i < s.nrMaterii; i++) {
			fscanf(f, "%d", &s.note[i]);
		}

		//conditii
		if (s.id % 2 == 0) {
			capls = inserareLs(capls, s);
		}
		else {
			capls1 = inserareLs(capls1, s);
		}

		free(s.nume);
		free(s.note);

	}
	fclose(f);
	afisareLs(capls);
	afisareLs(capls1);


	caplp = inserareLp(caplp, capls);
	caplp = inserareLp(caplp, capls1);

	printf("\nLista de liste ------------------------------\n");
	afisareLp(caplp);




}

