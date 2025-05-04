//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////To do: stergere, conversie in alta lista simpla, dubla?
//
//typedef struct Magazin {
//	int id;
//	char* nume;
//	char* program;
//	float suprafata;
//	unsigned char nrAngajati;
//	int* varsteAngajati;
//}Magazin;
//
//typedef struct Nod {
//	Magazin info;
//	struct Nod* prev;
//	struct Nod* next;
//}Nod;
//
//typedef struct LD {
//	Nod* prim;
//	Nod* ultim;
//}LD;
//
//Magazin initializareMagazin(int id, char* nume, char* program, float suprafata, unsigned char nrAngajati, int* varste) {
//	Magazin m;
//	m.id = id;
//	m.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(m.nume, sizeof(char) * (strlen(nume) + 1), nume);
//	m.program = (char*)malloc(sizeof(char) * strlen(program) + 1);
//	strcpy_s(m.program, sizeof(char) * (strlen(program) + 1), program);
//	m.suprafata = suprafata;
//	m.nrAngajati = nrAngajati;
//	m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
//	for (int i = 0; i < m.nrAngajati; i++) {
//		m.varsteAngajati[i] = varste[i];
//	}
//
//	return m;
//}
//
//LD inserareInceput(LD lista, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
//	nou->prev = NULL;
//	nou->next = NULL;
//
//	if (lista.prim == NULL) {
//		lista.prim = lista.ultim = nou;
//	}
//	else {
//		nou->next = lista.prim;
//		lista.prim->prev = nou;
//		lista.prim = nou;
//	}
//	return lista;
//}
//
//LD inserareSfarsit(LD lista, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
//	nou->prev = NULL;
//	nou->next = NULL;
//
//	if (lista.ultim == NULL) {
//		lista.ultim = lista.prim = nou;
//	}
//	else {
//		lista.ultim->next = nou;
//		nou->prev = lista.ultim;
//		lista.ultim = nou;
//	}
//}
//
//void afisareMagazin(Magazin m) {
//	printf("\n%d, %s, %s, %.2f, %u ", m.id, m.nume, m.program, m.suprafata, m.nrAngajati);
//	printf("Varste angajati: ");
//	for (int i = 0; i < m.nrAngajati; i++) {
//		printf("%d ", m.varsteAngajati[i]);
//	}
//}
//
//void afisareInceput(LD lista) {
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux) {/////////////////////(!NU aux->next) nu mai afiseaza ultimul/primul element inserat
//			//while (aux->next) se opreste inainte de ultimul nod
//			afisareMagazin(aux->info);
//			aux = aux->next;
//		}
//	}
//	else {
//		printf("Lista este goala");
//	}
//}
//
//void afisareSfarsit(LD lista) {
//	if (lista.ultim) {
//		Nod* aux = lista.ultim;
//		while (aux) {
//			afisareMagazin(aux->info);
//			aux = aux->prev; ///////////////////!Atentie la prev/next
//		}
//	}
//	else {
//		printf("Lista este goala");
//	}
//}
//
//void dezalocare(LD lista) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		free(aux->info.nume);
//		free(aux->info.program);
//		free(aux->info.varsteAngajati);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;///////////////////////!Atentie; free(aux); aux e null; nu mai apoti accesa nici un camp din aux
//		//aux = temp; => muta pointerul pe uurmatorul nod
//		//aux->next = temp; => incearca sa modifice lista si după free(aux), duce la comportament nedefinit
//	}
//
//
//}
//
////suma dupa un char* ca parametru -> total angajati dupa denumire
//int totalAngajati(LD lista, const char* denCautata) {
//	int suma = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//	}
//	return suma;
//}
//
////suma dupa un numeric ca prag dat ca parametru
////totalul angajatilor in magazinele cu suprafata mai mare 1000 mp
//int totalAngajatiPrag(LD lista, int pragSuprafata) {
//	int suma = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (aux->info.suprafata >= pragSuprafata) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//	}
//	return suma;
//}
////medie
//float medieSuprafete(LD lista, const char* denCautata) {
//	float suma = 0;
//	int contor = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.suprafata;
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return suma / contor;
//}
//
////modificare numeric dupa char*
////modifica nr angajati dupa nume
//void modificaSuprafata(LD lista, const char* denCautata, float suprafNoua) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			aux->info.suprafata = suprafNoua;
//		}
//		aux = aux->next;
//	}
//
//}
//
////modificare char* dupa int
////modifica program dupa id-ul magazinului
//void modificaProgram(LD lista, int idCautat, char* programNou) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (aux->info.id == idCautat) {
//			aux->info.program = (char*)malloc(sizeof(char) * strlen(programNou) + 1);
//			strcpy_s(aux->info.program, sizeof(char) * (strlen(programNou) + 1), programNou);
//		}
//		aux = aux->next;
//	}
//}
//
////maxim = suprafata maxima
//void afiseazaMaxim(LD lista) {
//	Nod* aux = lista.prim;
//	Nod* maxim = lista.prim;
//
//	while (aux->next) {
//		if (aux->info.suprafata > maxim->info.suprafata) {
//			maxim = aux;
//		}
//		aux = aux->next;
//	}
//	//afisareMagazin(maxim->info);
//	printf(" %s ", maxim->info.nume);
//}
//
////conversie vector
////nr elemente
//int  nrElemente(LD lista) {
//	int contor = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		contor++;
//		aux = aux->next;
//	}
//	return contor;
//}
//
//Magazin* conversieVector(LD lista) {
//	int index = 0;
//
//	int dim = nrElemente(lista);
//	Magazin* vector = (Magazin*)malloc(sizeof(Magazin) * dim);
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		vector[index] = initializareMagazin(aux->info.id, aux->info.nume,
//			aux->info.program, aux->info.suprafata, aux->info.nrAngajati, aux->info.varsteAngajati);
//		index++;
//		aux = aux->next;
//	}
//	return vector;
//}
//
//
////conversie vector cu conditie
////sa se salveze intr-un vector magazinel cu suprafata mai mare de 400
//int  nrElementePrag(LD lista, int prag) {
//	int contor = 0;
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (aux->info.suprafata > prag) {
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//}
//Magazin* conversieVectorFiltrat(LD lista, int prag) {
//	int index = 0;
//
//	int dim = nrElementePrag(lista, prag);
//	Magazin* vector = (Magazin*)malloc(sizeof(Magazin) * dim);
//
//	Nod* aux = lista.prim;
//	while (aux) {
//		if (aux->info.suprafata > prag) {
//			vector[index] = initializareMagazin(aux->info.id, aux->info.nume,
//				aux->info.program, aux->info.suprafata, aux->info.nrAngajati, aux->info.varsteAngajati);
//			index++;
//		}
//		aux = aux->next;
//	}
//	return vector;
//}
//
//void main() {
//	Magazin m;
//	LD lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	char  linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("extra1_ListaDubla_fisier.txt", "r");
//
//	if (!f) {
//		printf("Fisierul nu a fost gasit!\n");
//	}
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		m.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		m.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(m.nume, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		m.program = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(m.program, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		m.suprafata = atof(token);
//
//		token = strtok(NULL, separator);
//		m.nrAngajati = atoi(token);
//
//		m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
//		for (int i = 0; i < m.nrAngajati; i++) {
//			token = strtok(NULL, separator);
//			m.varsteAngajati[i] = atoi(token);
//		}
//
//
//		//lista = inserareInceput(lista, m);
//		lista = inserareSfarsit(lista, m);
//
//		free(m.nume);
//		free(m.program);
//		free(m.varsteAngajati);
//	}
//	fclose(f);
//
//	//afisareInceput(lista);
//	afisareSfarsit(lista);
//
//	printf("\n\nFunctii-------------------------------------------------------------------------------");
//
//	printf("\nTotal angajati pentru Flanco: %d", totalAngajati(lista, "Flanco"));
//
//	printf("\nTotal angajati pentru magazinele cu suprafata mai mare de 1000mp: %d", totalAngajatiPrag(lista, 1000));
//
//	printf("\nMedia suprafetei pentru Flanco: %.2f", medieSuprafete(lista, "Flanco"));
//
//	modificaSuprafata(lista, "Samsung", 110.5);
//	printf("\n\nSuprafata modificata pentru Samsung: ");
//	afisareSfarsit(lista);
//
//	modificaProgram(lista, 1, "12:00-13:00");
//	printf("\n\nProgram modificat pt magazinul cu id 1: ");
//	afisareSfarsit(lista);
//
//	printf("\n\nNr elemente in lista: %d", nrElemente(lista));
//
//	printf("\n\nMagazinul cu suprafata maxima: ");
//	afiseazaMaxim(lista);
//
//	printf("\nConversie vector: \n");
//	int dim = nrElemente(lista);
//	Magazin* vectorMagazine = conversieVector(lista);
//	for (int i=0; i < dim; i++) {
//		afisareMagazin(vectorMagazine[i]);
//	}
//
//	printf("\nConversie vector cu conditie: \n");
//	int dim2 = nrElementePrag(lista, 400);
//	Magazin* vectorMagazine2 = conversieVectorFiltrat(lista, 400);
//	for (int i = 0; i < dim2; i++) {
//		afisareMagazin(vectorMagazine2[i]);
//	}
//
//
//
//	dezalocare(lista);
//
//}
//
//
//
