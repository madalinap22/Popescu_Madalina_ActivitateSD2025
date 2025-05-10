//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#include <string.h>
//
//
//typedef struct Carte {
//	int cod;
//	char* titlu;
//	char* autor;
//	float pret;
//	int nrRatinguri;
//	int* ratinguri;
//}Carte;
//
//typedef struct Nod {
//	Carte info;
//	struct Nod* next;
//}Nod;
//
//Carte initializareCarte(int cod, char* titlu, char* autor, float pret, int nrRatinguri, int* ratinguri) {
//	Carte c;
//	c.cod = cod;
//	c.titlu = (char*)malloc(sizeof(char)*strlen(titlu) + 1);
//	strcpy_s(c.titlu, (sizeof(char) * strlen(titlu) + 1), titlu);
//	c.autor = (char*)malloc(sizeof(char) * strlen(autor) + 1);
//	strcpy_s(c.autor, (sizeof(char) * strlen(autor) + 1), autor);
//	c.pret = pret;
//	c.nrRatinguri = nrRatinguri;
//	c.ratinguri = (int*)malloc(sizeof(int) * c.nrRatinguri);
//	for (int i = 0; i < c.nrRatinguri; i++) {
//		c.ratinguri[i] = ratinguri[i];
//	}
//	return c;
//}
//
//Nod* adaugaInceput(Nod* cap, Carte c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareCarte(c.cod, c.titlu, c.autor, c.pret, c.nrRatinguri, c.ratinguri);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		nou->next = cap;
//		cap = nou;
//	}
//	return cap;
//}
//
//Nod* adaugaSfarsit(Nod* cap, Carte c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareCarte(c.cod, c.titlu, c.autor, c.pret, c.nrRatinguri, c.ratinguri);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		Nod* aux = cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	return cap;
//}
//
//void afisareCarte(Carte c) {
//	printf("\n %d, %s, %s, %.2f, %d", c.cod, c.titlu, c.autor, c.pret, c.nrRatinguri);
//	printf(" Ratinguri: ");
//	for (int i = 0; i < c.nrRatinguri; i++) {
//		printf("%d ", c.ratinguri[i]);
//	}
//}
//
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		afisareCarte(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		free(aux->info.titlu);
//		free(aux->info.autor);
//		free(aux->info.ratinguri);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//}
//Nod* maxim(Nod* cap) {
//	Nod* aux = cap;
//	Nod* max = cap;
//	while (aux) {
//		if (aux->info.pret > max->info.pret) {
//			max = aux;
//		}
//		aux = aux->next;
//	}
//	return max;
//}
//
//void stergeNod(Nod** cap) {
//	Nod* aux = *cap;
//	Nod* prev = NULL;
//	Nod* max = maxim(*cap);
//
//	while (aux) {
//		if (aux->info.pret == max->info.pret) {
//			Nod* nodDeSters = aux;
//			if (prev == NULL) {
//				*cap = aux->next;
//				aux = aux->next;
//			}
//			else {
//				prev->next = aux->next;
//				aux = aux->next;
//			}
//			free(nodDeSters->info.titlu);
//			free(nodDeSters->info.autor);
//			free(nodDeSters->info.ratinguri);
//		}
//		else {
//			prev = aux;
//			aux = aux->next;
//		}
//	}
//
//
//}
//
//int nrElemente(Nod* cap, int prag) {
//	Nod* aux = cap;
//	int contor = 0;
//	while (aux) {
//		if (aux->info.pret > prag) {
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//
//}
//
//Carte* conversieVector(Nod* cap, int prag) {
//	int dim = nrElemente(cap, prag);
//	Carte* vector = (Carte*)malloc(sizeof(Carte) * dim);
//	int index = 0;
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.pret > prag) {
//			vector[index] = initializareCarte(aux->info.cod, aux->info.titlu, aux->info.autor, aux->info.pret, aux->info.nrRatinguri, aux->info.ratinguri);
//			index++;
//		}
//		aux = aux->next;
//	}
//	return vector;
//}
//void dezalocareVector(Carte* vector, int dim) {
//	if (vector) {
//		for (int i = 0; i < dim; i++) {
//			free(vector[i].titlu);
//			free(vector[i].autor);
//			free(vector[i].ratinguri);
//		}
//		free(vector);
//	}
//}
//
//void main() {
//	Carte c;
//	Nod* cap = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex2_ListaSimpla.txt", "r");
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		c.cod = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.titlu = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.titlu, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.autor = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.autor, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.pret = atof(token);
//
//		token = strtok(NULL, separator);
//		c.nrRatinguri = atoi(token);
//
//		c.ratinguri = (int*)malloc(sizeof(int) * c.nrRatinguri);
//		for (int i = 0; i < c.nrRatinguri; i++) {
//		token = strtok(NULL, separator);
//		c.ratinguri[i] = atoi(token);
//		}
//
//		//cap = adaugaInceput(cap, c);
//		cap = adaugaSfarsit(cap, c);
//		free(c.titlu);
//		free(c.autor);
//		free(c.ratinguri);
//	}
//	fclose(f);
//
//	afisareLista(cap);
//	printf("\n\nMaxim: ");
//	Nod* max = maxim(cap);
//	afisareCarte(max->info);
//
//	printf("\n\nStergere: ");
//	//stergeNod(&cap);
//	//afisareLista(cap);
//
//	printf("\n\nNr elem: %d", nrElemente(cap, 35));
//
//	printf("\n\nConversie vector:");
//	int dim = nrElemente(cap, 35);
//	Carte* vectorCarti = conversieVector(cap, 35);
//	for (int i = 0; i < dim; i++) {
//		afisareCarte(vectorCarti[i]);
//	}
//
//
//	dezalocare(cap);
//	dezalocareVector(vectorCarti, dim);
//}
