//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////to do: conversii, stergere
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
//Magazin initializareMagazin(int id, char* nume, char* program, float suprafata, unsigned char nrAngajati, int* varsteAngajati) {
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
//		m.varsteAngajati[i] = varsteAngajati[i];
//	}
//	return m;
//}
//
//LD inserare(LD lista, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
//	nou->prev = NULL;
//	nou->next = NULL;
//
//	if (lista.prim == NULL) {
//		lista.prim = lista.ultim = nou;
//		nou->prev = lista.prim;
//		nou->next = lista.prim;
//	}
//	else {
//		lista.ultim->next = nou;
//		nou->prev = lista.ultim;
//		nou->next = lista.prim;
//		lista.prim->prev = nou;
//		lista.prim = nou; //!Atentie; fara asta o sa lege la noul apel tot de vechiul nod ultim
//	}
//	return lista;
//}
//
//void afisareMagazin(Magazin m) {
//	printf("\n%d, %s, %s, %.2f, %u ", m.id, m.nume, m.program, m.suprafata, m.nrAngajati);
//	printf("Varste angajati: ");
//	for (int i = 0; i < m.nrAngajati; i++) {
//		printf("%d ", m.varsteAngajati[i]);
//	}
//}
//void afisareLista(LD lista) {
//	if (lista.prim) {
//		Nod* aux = lista.prim;
//		while (aux->next != lista.prim) {
//			afisareMagazin(aux->info);
//			aux = aux->next;
//		}
//		afisareMagazin(aux->info); //ca sa afiseze si ultimul nod (din cauza conditie while; pt ca se opreste cand aux->next = cap))
//	}
//	else {
//		printf("Lista este goala");
//	}
//}
//
//void dezalocare(LD lista) {
//	Nod* aux = lista.prim;
//	while (aux->next != lista.prim) {
//		free(aux->info.nume);
//		free(aux->info.program);
//		free(aux->info.varsteAngajati);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//	//pt ultimul nod
//	free(aux->info.nume);
//	free(aux->info.program);
//	free(aux->info.varsteAngajati);
//	free(aux);
//
//}
////suma dupa un char* ca parametru -> total angajati dupa denumire
//int totalAngajati(LD lista, const char* denCautata) {
//	int suma = 0;
//	Nod* aux = lista.prim;
//
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//	return suma;
//
//	//int suma = 0;
//	//Nod* aux = lista.prim;
//	//do {
//	//	if (strcmp(aux->info.nume, denCautata) == 0) {
//	//		suma += aux->info.nrAngajati;
//	//	}
//	//	aux = aux->next;
//	//} while (aux != lista.prim);
//	//
//	//return suma;
//}
//
////suma dupa un int ca prag dat ca parametru
////totalul angajatilor in magazinele cu suprafata mai mare 1000 mp
//int totalAngajatiPrag(LD lista, int pragSuprafata) {
//	int suma = 0;
//
//	Nod* aux = lista.prim;
//	while (aux->next) {
//		if (aux->info.suprafata >= pragSuprafata) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//	return suma;
//}
////medie
//float medieSuprafete(LD lista, const char* denCautata) {
//	float suma = 0;
//	int contor = 0;
//
//	Nod* aux = lista.prim;
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.suprafata;
//			contor++;
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//	return suma / contor;
//}
//
////modificare numeric dupa char*
////modifica nr angajati dupa nume
//void modificaSuprafata(LD lista, const char* denCautata, unsigned char suprafNoua) {
//	Nod* aux = lista.prim;
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			aux->info.suprafata = suprafNoua;
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//
//}
//
////modificare char* dupa int
////modifica program dupa id-ul magazinului
//void modificaProgram(LD lista, int idCautat, char* programNou) {
//	Nod* aux = lista.prim;
//	while (aux->next) {
//		if (aux->info.id == idCautat) {
//			aux->info.program = (char*)malloc(sizeof(char) * strlen(programNou) + 1);
//			strcpy_s(aux->info.program, sizeof(char) * (strlen(programNou) + 1), programNou);
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//}
////nr elemente
//int  nrElemente(LD lista) {
//	int contor = 0;
//
//	Nod* aux = lista.prim;
//	while (aux->next) {
//		contor++;
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//	return contor;
//}
////maxim
////afisare magazin cu suprafata maxima
//void afiseazaMaxim(LD lista) {
//	Nod* aux = lista.prim;
//	Nod* maxim = lista.prim;
//
//	while (aux->next) {
//		if (aux->info.suprafata > maxim->info.suprafata) {
//			maxim = aux;
//		}
//		aux = aux->next;
//		if (aux == lista.prim) break;
//	}
//
//	//afisareMagazin(maxim->info);
//	printf(" %s ", maxim->info.nume);
//}
//
//
//
//
//void main() {
//	Magazin m;
//	LD lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token;
//
//	FILE* f = fopen("extra1_ListaDublaCirculara_fisier.txt", "r");
//	if (!f) {
//		printf("Fisierul nu a fost gasit");
//
//	}
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		m.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		m.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(m.nume, (sizeof(char) * strlen(token) + 1), token);
//		
//		token = strtok(NULL, separator);
//		m.program = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(m.program, (sizeof(char) * strlen(token) + 1), token);
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
//		lista = inserare(lista, m);
//
//		free(m.nume);
//		free(m.program);
//		free(m.varsteAngajati);
//
//	}
//	fclose(f);
//
//	afisareLista(lista);
//
//	printf("\n\nFunctii-------------------------------------------------------------------------------");
//
//	printf("\nTotal angajati pentru Flanco: %d", totalAngajati(lista, "Flanco"));
//	printf("\nTotal angajati pentru magazinele cu suprafata mai mare de 1000mp: %d", totalAngajatiPrag(lista, 1000));
//	printf("\nMedia suprafetei pentru Flanco: %.2f", medieSuprafete(lista, "Flanco"));
//	
//	modificaSuprafata(lista, "Samsung", 100.5);
//	printf("\n\nSuprafata modificata pentru Samsung: ");
//	afisareLista(lista);
//	
//	modificaProgram(lista, 10, "12:00-13:00");
//	printf("\n\nProgram modificat pt magazinul cu id 10: ");
//	afisareLista(lista);
//
//	printf("\n\nNr elemente in lista: %d", nrElemente(lista));
//
//	printf("\n\nNumele magazinul cu suprafata maxima:");
//	afiseazaMaxim(lista);
//
//	dezalocare(lista);
//}
