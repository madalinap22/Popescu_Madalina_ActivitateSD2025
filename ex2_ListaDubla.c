//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Cladire {
//	int id;
//	int anConstructie;
//	char* adresa;
//	char* status; //expertizata/neexpertizata
//	int nrLuni;
//	float* cheltuieliLunare;
//}Cladire;
//
//typedef struct Nod {
//	Cladire info;
//	struct Nod* prev;
//	struct Nod* next;
//}Nod;
//
//typedef struct LD {
//	Nod* prim;
//	Nod* ultim;
//}LD;
//
//Cladire initializareCladire(int id, int anConstructie, char* adresa, char* status, int nrLuni, float* cheltuieliLunare) {
//	Cladire c;
//	c.id = id;
//	c.anConstructie = anConstructie;
//	c.adresa = (char*)malloc(sizeof(char) * strlen(adresa) + 1);
//	strcpy_s(c.adresa, (sizeof(char) * strlen(adresa) + 1), adresa);
//	c.status = (char*)malloc(sizeof(char) * strlen(status) + 1);
//	strcpy_s(c.status, (sizeof(char) * strlen(status) + 1), status);
//	c.nrLuni = nrLuni;
//	c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
//	for (int i = 0; i < c.nrLuni; i++) {
//		c.cheltuieliLunare[i] = cheltuieliLunare[i];
//	}
//	return c;
//}
//
//LD adaugaInceput(LD lista, Cladire c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (lista.prim == NULL) {
//		lista.prim = lista.ultim =  nou;
//	}
//	else {
//		lista.prim->prev = nou;
//		nou->next = lista.prim;
//		lista.prim = nou;
//	}
//	return lista;
//}
//LD adaugaFinal(LD lista, Cladire c) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (lista.ultim == NULL) {
//		lista.prim = lista.ultim = nou;
//
//	}
//	else {
//		lista.ultim->next = nou;
//		nou->prev = lista.ultim;
//		lista.ultim = nou;
//	}
//	return lista;
//}
//
//void afisareCladire(Cladire c) {
//	printf("\n %d, %d, %s, %s, %d", c.id, c.anConstructie, c.adresa, c.status, c.nrLuni);
//	printf(" Cheltuieli lunare: ");
//	for (int i = 0; i < c.nrLuni; i++) {
//		printf("%.2f ", c.cheltuieliLunare[i]);
//	}
//}
//
//void afisareInceput(LD lista) {
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			afisareCladire(aux->info);
//			aux = aux->next;
//		}
//	}
//
//}
//
//void afisareFinal(LD lista) {
//	if (lista.ultim) {
//		Nod* aux = lista.ultim;
//		while (aux) {
//			afisareCladire(aux->info);
//			aux = aux->prev;
//		}
//	}
//}
//
//void dezalocare(LD lista) {
//		Nod* aux = lista.prim;
//		while (aux) {
//			free(aux->info.adresa);
//			free(aux->info.status);
//			free(aux->info.cheltuieliLunare);
//
//			Nod* temp = aux->next;
//			free(aux);
//			aux = temp;
//		}
//}
//
////stergeri
////stergere nod maxim
//Nod* maxim(LD lista) {
//	Nod* aux = lista.prim;
//	Nod* max = lista.prim;
//	while (aux) {
//		if (aux->info.anConstructie > max->info.anConstructie) {
//			max = aux;
//		}
//		aux = aux->next;
//	}
//	return max;
//}
//
//LD stergeNod(LD* lista) {
//	Nod* aux = lista->prim;
//	Nod* max = maxim(*lista);
//
//	while (aux) {
//		if (aux->info.anConstructie == max->info.anConstructie) {
//			Nod* nodDeSters = aux;
//
//			if (aux == lista->prim) {
//				lista->prim = aux->next;
//				lista->prim->prev = NULL;
//				aux = aux->next;
//			}
//			else if (aux->next == NULL) {
//				aux->prev->next = NULL;
//				aux = aux->next;
//			}
//			else {
//				aux->prev->next = aux->next;
//				aux->next->prev = aux->prev;
//				aux = aux->next;
//			}
//
//			free(nodDeSters->info.adresa);
//			free(nodDeSters->info.status);
//			free(nodDeSters->info.cheltuieliLunare);
//
//		}
//		else {
//			aux = aux->next;
//		}
//		
//	}
//	return *lista;
//}
//
//
////conversie vector conditie
//// //sa se salveze in vector cladirile expertizate
//int nrElemente(LD lista, const char* denCautata) {
//	Nod* aux = lista.prim;
//	int contor = 0;
//
//	while (aux) {
//		if (strcmp(aux->info.status, denCautata) == 0) {
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//}
//
//Cladire* vectorFiltrat(LD lista, const char* denCautata) {
//	int dim = nrElemente(lista, denCautata);
//	Cladire* vector = (Cladire*)malloc(sizeof(Cladire) * dim);
//
//	int index = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.status, denCautata) == 0) {
//			vector[index] = initializareCladire(aux->info.id, aux->info.anConstructie, aux->info.adresa,
//				aux->info.status, aux->info.nrLuni, aux->info.cheltuieliLunare);
//			index++;
//		}
//		aux = aux->next;
//	}
//	return vector;
//}
////conversie in lista simpla
////sa se adauge in lista simpla cladirile expertizate
//typedef struct NodLS {
//	Cladire info;
//	struct NodLS* next;
//}NodLS;
//
//NodLS* adaugareLS(NodLS* cap, Cladire c) {
//	NodLS* nou = (NodLS*)malloc(sizeof(NodLS));
//	nou->info = initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou;
//	}
//	else {
//		NodLS* aux = cap;
//		while (aux->next) {
//			aux=aux->next;
//		}
//		aux->next = nou;
//	}
//	return cap;
//}
//
//void dezalocareLS(NodLS* cap) {
//	NodLS* aux = cap;
//	while (aux) {
//		free(aux->info.adresa);
//		free(aux->info.status);
//		free(aux->info.cheltuieliLunare);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//}
//void afisareLS(NodLS* cap) {
//	NodLS* aux = cap;
//	while (aux) {
//		afisareCladire(aux->info);
//		aux = aux->next;
//	}
//}
//
//NodLS* conversieLS(LD lista, const char* denCautata) {
//	Nod* aux = lista.prim;
//	NodLS* cap = NULL;
//
//	while (aux) {
//		if (strcmp(aux->info.status, denCautata) == 0) {
//			cap = adaugareLS(cap, aux->info);
//		}
//		aux = aux->next;
//	}
//	return cap;
//}
//
////medie nr luni
//int medie(LD lista) {
//	Nod* aux = lista.prim;
//	int contor = 0;
//	int suma = 0;
//
//	while (aux) {
//		suma += aux->info.nrLuni;
//		contor++;
//
//		aux = aux->next;
//	}
//	return suma / contor;
//}
////modificare status
//void modificaStatus(LD lista, int idCautat, const char* denNoua) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (aux->info.id == idCautat) {
//			aux->info.status = (char*)malloc(sizeof(char) * strlen(denNoua)+1);
//			strcpy_s(aux->info.status, (sizeof(char) * strlen(denNoua) + 1), denNoua);
//		}
//		aux = aux->next;
//	}
//}
//
//void main() {
//	Cladire c;
//	LD lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex2_ListaDubla.txt", "r");
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		c.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.anConstructie = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.adresa = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.adresa, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.status = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.status, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.nrLuni = atoi(token);
//
//		c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
//		for (int i = 0; i < c.nrLuni; i++) {
//			token = strtok(NULL, separator);
//			c.cheltuieliLunare[i] = atof(token);
//		}
//
//		//lista = adaugaInceput(lista, c);
//		lista = adaugaFinal(lista, c);
//
//		free(c.adresa);
//		free(c.status);
//		free(c.cheltuieliLunare);
//	}
//	fclose(f);
//	//afisareFinal(lista);
//	afisareInceput(lista);
//
//
//
//	printf("\nAfisare nod cu anul cel mai mare: ");
//	Nod* max = maxim(lista);
//	afisareCladire(max->info);
//
//	printf("\n Stergere nod maxim: ");
//	//stergeNod(&lista);
//	//afisareInceput(lista);
//
//	printf("\n Nr cladiri expertizate: %d", nrElemente(lista, "Expertizata"));
//
//	printf("\nConversie in vector: ");
//	int dim = nrElemente(lista, "Expertizata");
//	Cladire* vectorCladiri = vectorFiltrat(lista, "Expertizata");
//	for (int i = 0; i < dim; i++)
//	{
//		afisareCladire(vectorCladiri[i]);
//	}
//
//	printf("\nConversie in lista simpla: ");
//	NodLS* cap = NULL;
//	cap = conversieLS(lista, "Expertizata");
//	afisareLS(cap);
//
//	printf("\nMedie: %d", medie(lista));
//
//	printf("\nStatus modificat: ");
//	modificaStatus(lista, 1, "NA");
//	afisareInceput(lista);
//	
//
//
//	dezalocare(lista);
//	dezalocareLS(cap);
//}
