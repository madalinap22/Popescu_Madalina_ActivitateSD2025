#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Student {
	unsigned int cod;
	char* nume;
	char* specializare;
	unsigned char varsta;
	int nrNote;
	float* note;
}Student;

typedef struct Nod {
	Student info;
	struct Nod* next;
}Nod;

typedef struct HT {
	int dim;
	Nod** vector;
}HT;

int functieHashInt(HT tabela, int id) {
	return id % tabela.dim;
}

int functieHashChar(HT tabela, const char* den) {
	return strlen(den) % tabela.dim;
}

Student initializareStudent(unsigned int cod, char* nume, char* specializare, unsigned char varsta, int nrNote, float* note) {
	Student s;
	s.cod = cod;
	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(s.nume, (sizeof(char) * strlen(nume) + 1), nume);
	s.specializare = (char*)malloc(sizeof(char) * strlen(specializare) + 1);
	strcpy_s(s.specializare, (sizeof(char) * strlen(specializare) + 1), specializare);
	s.varsta = varsta;
	s.nrNote = nrNote;
	s.note = (float*)malloc(sizeof(float) * s.nrNote);
	for (int i = 0; i < s.nrNote; i++) {
		s.note[i] = note[i];
	}
	return s;
}

int inserareTabela(HT tabela, Student s) {
	int poz = 0;
	if (tabela.vector) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = initializareStudent(s.cod, s.nume, s.specializare, s.varsta, s.nrNote, s.note);
		nou->next = NULL;

		poz = functieHashChar(tabela, s.specializare);
		if (tabela.vector[poz] == NULL) {
			tabela.vector[poz] = nou;
		}
		else {
			Nod* aux = tabela.vector[poz];
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nou;
		}
	}
	return poz;
}

dezalocareTabela(HT tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					free(aux->info.nume);
					free(aux->info.specializare);
					free(aux->info.note);

					Nod* temp = aux->next;
					free(aux);
					aux = temp;
				}
			}
		}
	}
}
void afisareStudent(Student s) {
	printf("\n%u, %s, %s, %u, %d ", s.cod, s.nume, s.specializare, s.varsta, s.nrNote);
	printf("Note: ");
	for (int i = 0; i < s.nrNote; i++) {
		printf("%.2f, ", s.note[i]);
	}
}

void afisareTabela(HT tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				printf("\nPozitie: %d", i);
				Nod* aux = tabela.vector[i];
				while (aux) {
					afisareStudent(aux->info);
					aux = aux->next;
				}
			}
		}
	}
}

void main() {
	Student s;
	HT tabela;
	tabela.dim = 10;
	tabela.vector = (Nod*)malloc(sizeof(Nod) * tabela.dim);
	for (int i = 0; i < tabela.dim; i++) {
		tabela.vector[i] = NULL;
	}

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("ex5_ListaSimpla.txt", "r");

	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		s.cod = atoi(token);

		token = strtok(NULL, separator);
		s.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(s.nume, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		s.specializare = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(s.specializare, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		s.varsta = atoi(token);

		token = strtok(NULL, separator);
		s.nrNote = atoi(token);

		s.note = (float*)malloc(sizeof(float) * s.nrNote);
		for (int i = 0; i < s.nrNote; i++) {
			token = strtok(NULL, separator);
			s.note[i] = atof(token);
		}

		inserareTabela(tabela, s);
		free(s.nume);
		free(s.specializare);
		free(s.note);

	}
	fclose(f);

	afisareTabela(tabela);



	dezalocareTabela(tabela);
}