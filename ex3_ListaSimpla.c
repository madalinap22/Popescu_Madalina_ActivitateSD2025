//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Pachet {
//	unsigned int id;
//	char* destinatie;
//	char* destinatar;
//	float pret;
//	int nrTemperaturi;
//	float* temperaturi;
//}Pachet;
//
//typedef struct Nod {
//	Pachet info;
//	struct Nod* next;
//}Nod;
//
//Pachet initializarePachet(unsigned int id, char* destinatie, char* destinatar, float pret, int nrTemperaturi, float* temperaturi) {
//	Pachet p;
//	p.id = id;
//	p.destinatie = (char*)malloc(sizeof(char) * strlen(destinatie) + 1);
//	strcpy_s(p.destinatie, (sizeof(char) * strlen(destinatie) + 1), destinatie);
//	p.destinatar = (char*)malloc(sizeof(char) * strlen(destinatar) + 1);
//	strcpy_s(p.destinatar, (sizeof(char) * strlen(destinatar) + 1), destinatar);
//	p.pret = pret;
//	p.nrTemperaturi = nrTemperaturi;
//	p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
//	for (int i = 0; i < p.nrTemperaturi; i++) {
//		p.temperaturi[i] = temperaturi[i];
//	}
//	return p;
//}
//
//Nod* adaugaInceput(Nod* cap, Pachet p) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializarePachet(p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi, p.temperaturi);
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
//Nod* adaugaFinal(Nod* cap, Pachet p) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializarePachet(p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi, p.temperaturi);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		Nod* aux = cap;
//		while (aux->next) {//////////////////////////////////
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	return cap;
//}
//
//void afisarePachet(Pachet p) {
//	printf("\n%u, %s, %s, %.2f, %d ", p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi);
//	printf("Temperaturi: ");
//	for (int i = 0; i < p.nrTemperaturi; i++) {
//		printf("%.2f ", p.temperaturi[i]);
//	}
//}
//
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		afisarePachet(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		free(aux->info.destinatie);
//		free(aux->info.destinatar);
//		free(aux->info.temperaturi);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//
//}
//
//Nod* maxim(Nod* cap) {
//	Nod* aux = cap;
//	Nod* max = cap;///////////////////
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
//			free(nodDeSters->info.destinatie);
//			free(nodDeSters->info.destinatar);
//			free(nodDeSters->info.temperaturi);
//		}
//		else {
//			prev = aux;
//			aux = aux->next;
//		}
//	}
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
//}
//
//Pachet* vectorFiltrat(Nod* cap, int prag) {
//	int dim = nrElemente(cap, prag);
//	Pachet* vector = (Pachet*)malloc(sizeof(Pachet) * dim);
//	int index = 0;
//
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.pret > prag) {
//			vector[index] = initializarePachet(aux->info.id, aux->info.destinatie, aux->info.destinatar, aux->info.pret, aux->info.nrTemperaturi, aux->info.temperaturi);
//			index++;
//		}
//		aux = aux->next;
//	}
//	return vector;
//}
//
//void dezalocareVector(Pachet* vector, int dim) {
//	if (vector) {
//		for (int i = 0; i < dim; i++) {
//			free(vector[i].destinatie);
//			free(vector[i].destinatar);
//			free(vector[i].temperaturi);
//		}
//		free(vector);
//			
//	}
//}
//
//void modificaChar(Nod* cap, int id, const char* denNoua) {
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.id == id) {
//			aux->info.destinatar = (char*)malloc(sizeof(char) * strlen(denNoua) + 1);
//			strcpy_s(aux->info.destinatar, (sizeof(char) * strlen(denNoua) + 1), denNoua);
//		}
//		aux = aux->next;
//	}
//}
//
//void main() {
//	Pachet p;
//	Nod* cap = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex3_ListaSimpla.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		p.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.destinatie = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.destinatie, (sizeof(char) * strlen(token) + 1), token);
//	
//		token = strtok(NULL, separator);
//		p.destinatar = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.destinatar, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		p.pret = atof(token);
//
//		token = strtok(NULL, separator);
//		p.nrTemperaturi = atoi(token);
//
//		p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
//		for (int i = 0; i < p.nrTemperaturi; i++) {
//			token = strtok(NULL, separator);
//			p.temperaturi[i] = atof(token);
//		}
//
//		//cap = adaugaInceput(cap, p);
//		cap = adaugaFinal(cap, p);
//		free(p.destinatie);
//		free(p.destinatar);
//		free(p.temperaturi);
//
//	}
//	fclose(f);
//	afisareLista(cap);
//
//	printf("\nNod maxim: ");
//	Nod* max = maxim(cap);
//	afisarePachet(max->info);
//
//	printf("\n\nNod Sters: ");
//	/*stergeNod(&cap);
//	afisareLista(cap);*/
//
//	printf("\nNr elemente: %d", nrElemente(cap, 150));
//
//	printf("\n\nDestinatar modificat: ");
//	modificaChar(cap, 1, "NA");
//	afisareLista(cap);
//
//
//
//
//	printf("\n\nConversie vector: ");
//	int dim = nrElemente(cap, 150);
//	Pachet* vector = vectorFiltrat(cap, 150);
//	for (int i = 0; i < dim; i++) {
//		afisarePachet(vector[i]);
//	}
//
//
//
//	dezalocare(cap);
//}
