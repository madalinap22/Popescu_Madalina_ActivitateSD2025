#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Pachet {
	unsigned int id;
	char* destinatie;
	char* destinatar;
	float pret;
	int nrTemperaturi;
	float* temperaturi;
}Pachet;

typedef struct Nod {
	Pachet info;
	struct Nod* next;
	struct Nod* prev;
}Nod;

typedef struct LD {
	struct Nod* prim;
	struct Nod* ultim;
}LD;

Pachet initializarePachet(unsigned int id, char* destinatie, char* destinatar, float pret, int nrTemperaturi, float* temperaturi) {
	Pachet p;
	p.id = id;
	p.destinatie = (char*)malloc(sizeof(char) * strlen(destinatie) + 1);
	strcpy_s(p.destinatie, (sizeof(char) * strlen(destinatie) + 1), destinatie);
	p.destinatar = (char*)malloc(sizeof(char) * strlen(destinatar) + 1);
	strcpy_s(p.destinatar, (sizeof(char) * strlen(destinatar) + 1), destinatar);
	p.pret = pret;
	p.nrTemperaturi = nrTemperaturi;
	p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
	for (int i = 0; i < p.nrTemperaturi; i++) {
		p.temperaturi[i] = temperaturi[i];
	}
	return p;
}

LD adaugaInceput(LD lista, Pachet p) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializarePachet(p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi, p.temperaturi);
	nou->next = NULL;
	nou->prev = NULL;

	if (lista.prim == NULL) {
		lista.prim = lista.ultim = nou;
	}
	else {
		lista.prim->prev = nou;
		nou->next = lista.prim;
		lista.prim = nou;
	}
	return lista;
}

LD adaugaFinal(LD lista, Pachet p) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializarePachet(p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi, p.temperaturi);
	nou->next = NULL;
	nou->prev = NULL;

	if (lista.ultim == NULL) {
		lista.ultim = lista.prim = nou;
	}
	else {
		lista.ultim->next = nou;
		nou->prev = lista.ultim;
		lista.ultim = nou;
	}
	return lista;
}

void afisarePachet(Pachet p) {
	printf("\n%u, %s, %s, %.2f, %d ", p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi);
	printf("Temperaturi: ");
	for (int i = 0; i < p.nrTemperaturi; i++) {
		printf("%.2f ", p.temperaturi[i]);
	}
}

void afisareInceput(LD lista) {
	Nod* aux = lista.prim;
	while (aux) {
		afisarePachet(aux->info);
		aux = aux->next;
	}
}
void afisareFinal(LD lista) {
	Nod* aux = lista.ultim;
	while (aux) {
		afisarePachet(aux->info);
		aux = aux->prev;
	}
}

void dezalocare(LD lista) {
	Nod* aux = lista.prim;
	while (aux) {
		free(aux->info.destinatie);
		free(aux->info.destinatar);
		free(aux->info.temperaturi);

		Nod* temp = aux->next;
		free(aux);
		aux = temp;
	}
}

Nod* maxim(LD lista) {
	Nod* aux = lista.prim;
	Nod* max = lista.prim;
	while (aux) {
		if (aux->info.pret > max->info.pret) {
			max = aux;
		}
		aux = aux->next;
	}
	return max;
}

LD stergeNod(LD* lista) {
	Nod* aux = lista->prim;
	Nod* max = maxim(*lista);

	while (aux) {
		if (aux->info.pret == max->info.pret) {
			Nod* nodDeSters = aux;

			if (aux == lista->prim) {
				lista->prim = aux->next;
				lista->prim->prev = NULL;
				aux = aux->next;
			}
			else if (aux->next == NULL) {
				aux->prev->next = NULL;
				aux = aux->next;
			}
			else {
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				aux = aux->next;
			}

			free(nodDeSters->info.destinatie);
			free(nodDeSters->info.destinatar);
			free(nodDeSters->info.temperaturi);
		}
		else {
			aux = aux->next;
		}
	}
}

int nrElemente(LD lista, int prag) {
	Nod* aux = lista.prim;
	int contor = 0;
	while (aux) {
		if (aux->info.pret > prag) {
			contor++;
		}
		aux = aux->next;
	}
	return contor;
}

Pachet* conversieVector(LD lista, int prag) {
	int dim = nrElemente(lista, prag);
	Pachet* vector = (Pachet*)malloc(sizeof(Pachet) * dim);
	Nod* aux = lista.prim;
	int index = 0;
	while (aux) {
		if (aux->info.pret > prag) {
			vector[index] = initializarePachet(aux->info.id, aux->info.destinatie, aux->info.destinatar, aux->info.pret, aux->info.nrTemperaturi, aux->info.temperaturi);
			index++;
		}
		aux = aux->next;
	}
	return vector;
}

void main() {
	Pachet p;
	LD lista;
	lista.prim = NULL;
	lista.ultim = NULL;

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("ex3_ListaDubla.txt", "r");

	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		p.id = atoi(token);

		token = strtok(NULL, separator);
		p.destinatie = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(p.destinatie, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		p.destinatar = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(p.destinatar, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		p.pret = atof(token);

		token = strtok(NULL, separator);
		p.nrTemperaturi = atoi(token);

		p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
		for (int i = 0; i < p.nrTemperaturi; i++) {
			token = strtok(NULL, separator);
			p.temperaturi[i] = atof(token);
		}

		lista = adaugaFinal(lista, p);
		//lista = adaugaInceput(lista, p);

		free(p.destinatie);
		free(p.destinatar);
		free(p.temperaturi);
	}
	fclose(f);

	afisareInceput(lista);
	//afisareFinal(lista);

	printf("\n\n Nod maxim: ");
	Nod* max = maxim(lista);
	afisarePachet(max->info);

	printf("\n\nStergere nod: ");
	//stergeNod(&lista);
	//afisareInceput(lista);

	printf("\n\nNr elemente: %d ", nrElemente(lista, 150));

	printf("\n\nConversie vector: ");
	int dim = nrElemente(lista, 150);
	Pachet* vectorPachete = conversieVector(lista, 150);
	for (int i = 0; i < dim; i++) {
		afisarePachet(vectorPachete[i]);
	}




	dezalocare(lista);
}
