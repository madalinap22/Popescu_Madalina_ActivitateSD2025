#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Student {
	unsigned int id;
	char* nume; //&
	unsigned char nrMaterii;
	int* note;
}Student;

typedef struct Nod {
	Student info;
	struct Nod* next;
	struct Nod* prev;
}Nod;

typedef struct LD {
	Nod* prim;
	Nod* ultim;
}LD;

Student initializareStudent(unsigned int id, char* nume, unsigned char nrMaterii, int* note) {
	Student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
	s.nrMaterii = nrMaterii;
	s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
	for (int i = 0; i < s.nrMaterii; i++) {
		s.note[i] = note[i];
	}
	return s;
}

LD inserare(LD lista, Student s) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->prev = NULL;
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;
	
	if (lista.prim == NULL) {
		lista.prim = lista.ultim = nou;
		nou->prev = lista.prim;
		nou->next = lista.prim;
	}
	else {
		nou->prev = lista.ultim;
		nou->next = lista.prim;
		lista.ultim->next = nou;
		lista.prim->prev = nou;
		lista.ultim = nou; //!Atentie; fara asta o sa lege la noul apel tot de vechiul nod ultim
	}
	return lista;
}

void afisareStudent(Student s) {
	printf("\n%u, %s, %u ", s.id, s.nume, s.nrMaterii);
	printf("Note: ");
	for (int i = 0; i < s.nrMaterii; i++) {
		printf("%d ", s.note[i]);
	}
}

void afisare(LD lista) {
	Nod* aux = lista.prim;
	while (aux->next != lista.prim) {
		afisareStudent(aux->info);
		aux = aux->next;
	}
	afisareStudent(aux->info); //ca sa afiseze si ultimul nod (din cauza conditie while; pt ca se opreste cand aux->next = cap))
}

void dezalocare(LD lista) {
	Nod* aux = lista.prim;
	while (aux->next != lista.prim) {
		free(aux->info.nume);
		free(aux->info.note);

		Nod* temp = aux->next; ///////////////////////ca nu mai am info? si pastrez doar next-ul?
		free(aux);
		aux = temp;
	}
	free(aux->info.nume); //stergere ultimul nod
	free(aux);
}

void main() {
	Student s;
	LD lista;
	lista.prim = NULL;
	lista.ultim = NULL;

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("fisierListaDublaCirculara.txt", "r");
	if (!f) {
		printf("Fisierul nu a fost gasit!\n");
	}

	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		s.id = atoi(token);

		token = strtok(NULL, separator);
		s.nume = (char*)malloc(sizeof(char*) * (strlen(token) + 1));
		strcpy_s(s.nume, sizeof(char*) * (strlen(token) + 1), token);

		token = strtok(NULL, separator);
		s.nrMaterii = atoi(token);

		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
		for (int i = 0; i < s.nrMaterii; i++) {
			token = strtok(NULL, separator);
			s.note[i] = atoi(token);
		}

		lista = inserare(lista, s);

		free(s.nume);
		free(s.note);
	}
	fclose(f);

	afisare(lista);



	dezalocare(lista);
}

