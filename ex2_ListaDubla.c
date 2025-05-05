#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Cladire {
	int id;
	int anConstructie;
	char* adresa;
	char* status; //expertizata/neexpertizata
	int nrLuni;
	float* cheltuieliLunare;
}Cladire;

typedef struct Nod {
	Cladire info;
	struct Nod* prev;
	struct Nod* next;
}Nod;

typedef struct LD {
	Nod* prim;
	Nod* ultim;
}LD;

Cladire initializareCladire(int id, int anConstructie, char* adresa, char* status, int nrLuni, float* cheltuieliLunare) {
	Cladire c;
	c.id = id;
	c.anConstructie = anConstructie;
	c.adresa = (char*)malloc(sizeof(char) * strlen(adresa) + 1);
	strcpy_s(c.adresa, (sizeof(char) * strlen(adresa) + 1), adresa);
	c.status = (char*)malloc(sizeof(char) * strlen(status) + 1);
	strcpy_s(c.status, (sizeof(char) * strlen(status) + 1), status);
	c.nrLuni = nrLuni;
	c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
	for (int i = 0; i < c.nrLuni; i++) {
		c.cheltuieliLunare[i] = cheltuieliLunare[i];
	}
	return c;
}

LD adaugaInceput(LD lista, Cladire c) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
	nou->next = NULL;
	nou->prev = NULL;

	if (lista.prim == NULL) {
		lista.prim = lista.ultim =  nou;
	}
	else {
		lista.prim->prev = nou;
		nou->next = lista.prim;
		lista.prim = nou;
	}
	return lista;
}
LD adaugaFinal(LD lista, Cladire c) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
	nou->next = NULL;
	nou->prev = NULL;

	if (lista.ultim == NULL) {
		lista.prim = lista.ultim = nou;

	}
	else {
		lista.ultim->next = nou;
		nou->prev = lista.ultim;
		lista.ultim = nou;
	}
	return lista;
}

void afisareCladire(Cladire c) {
	printf("\n %d, %d, %s, %s, %d", c.id, c.anConstructie, c.adresa, c.status, c.nrLuni);
	printf(" Cheltuieli lunare: ");
	for (int i = 0; i < c.nrLuni; i++) {
		printf("%.2f ", c.cheltuieliLunare[i]);
	}
}

void afisareInceput(LD lista) {
	if (lista.prim) {
		Nod* aux = lista.prim;
		while (aux) {
			afisareCladire(aux->info);
			aux = aux->next;
		}
	}

}

void afisareFinal(LD lista) {
	if (lista.ultim) {
		Nod* aux = lista.ultim;
		while (aux) {
			afisareCladire(aux->info);
			aux = aux->prev;
		}
	}
}

void dezalocare(LD lista) {
		Nod* aux = lista.prim;
		while (aux) {
			free(aux->info.adresa);
			free(aux->info.status);
			free(aux->info.cheltuieliLunare);

			Nod* temp = aux->next;
			free(aux);
			aux = temp;
		}
}

void main() {
	Cladire c;
	LD lista;
	lista.prim = NULL;
	lista.ultim = NULL;

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("ex2_ListaDubla.txt", "r");

	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		c.id = atoi(token);

		token = strtok(NULL, separator);
		c.anConstructie = atoi(token);

		token = strtok(NULL, separator);
		c.adresa = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(c.adresa, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		c.status = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(c.status, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		c.nrLuni = atoi(token);

		c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
		for (int i = 0; i < c.nrLuni; i++) {
			token = strtok(NULL, separator);
			c.cheltuieliLunare[i] = atof(token);
		}

		//lista = adaugaInceput(lista, c);
		lista = adaugaFinal(lista, c);

		free(c.adresa);
		free(c.status);
		free(c.cheltuieliLunare);
	}
	fclose(f);
	//afisareFinal(lista);
	afisareInceput(lista);

	//int id;
	//int anConstructie;
	//char* adresa;
	//char* status; //expertizata/neexpertizata
	//int nrLuni;
	//float* cheltuieliLunare;


	dezalocare(lista);
}
