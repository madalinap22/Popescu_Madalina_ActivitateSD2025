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
//	struct Nod* next;
//}Nod;
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
//Nod* inserare(Nod* cap, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou; ////////atentie NU nou = cap; pt ca cap este NULL si nou devine NULL
//		nou->next = cap;  //1 singur nod legat la el insusi
//	}
//	else {
//		Nod* aux = cap;
//		while (aux->next != cap) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//		nou->next = cap;
//		//cap=nou; ////////////////////////////////////////////////////
//	}
//	return cap;
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
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux->next != cap) {
//		afisareMagazin(aux->info);
//		aux = aux->next;
//	}
//	afisareMagazin(aux->info);//ca sa afiseze si ultimul nod (din cauza conditie while; pt ca se opreste cand aux->next = cap))
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux->next != cap) {
//		free(aux->info.nume);
//		free(aux->info.program);
//		free(aux->info.varsteAngajati);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//	free(aux->info.nume);
//	free(aux->info.program);
//	free(aux->info.varsteAngajati);
//	free(aux);
//}
////suma dupa un char* ca parametru -> total angajati dupa denumire
//int totalAngajati(Nod* cap, const char* denCautata) {
//	int suma = 0;
//	Nod* aux = cap;
//
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//	return suma;
//}
////suma dupa un numeric ca prag dat ca parametru
////totalul angajatilor in magazinele cu suprafata mai mare 1000 mp
//int totalAngajatiPrag(Nod* cap, int pragSuprafata) {
//	int suma = 0;
//
//	Nod* aux = cap;
//	while (aux->next) {
//		if (aux->info.suprafata >= pragSuprafata) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//	return suma;
//}
////medie
//float medieSuprafete(Nod* cap, const char* denCautata) {
//	float suma = 0;
//	int contor = 0;
//
//	Nod* aux = cap;
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.suprafata;
//			contor++;
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//	return suma / contor;
//}
////modificare numeric dupa char*
////modifica nr angajati dupa nume
//void modificaSuprafata(Nod* cap, const char* denCautata, unsigned char suprafNoua) {
//	Nod* aux = cap;
//	while (aux->next) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			aux->info.suprafata = suprafNoua;
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//
//}
//
////modificare char* dupa int
////modifica program dupa id-ul magazinului
//void modificaProgram(Nod* cap, int idCautat, char* programNou) {
//	Nod* aux = cap;
//	while (aux->next) {
//		if (aux->info.id == idCautat) {
//			aux->info.program = (char*)malloc(sizeof(char) * strlen(programNou) + 1);
//			strcpy_s(aux->info.program, sizeof(char) * (strlen(programNou) + 1), programNou);
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//}
////nr elemente
//int  nrElemente(Nod* cap) {
//	int contor = 0;
//
//	Nod* aux = cap;
//	while (aux->next) {
//		contor++;
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//	return contor;
//}
////maxim
////afisare magazin cu suprafata maxima
//void afiseazaMaxim(Nod* cap) {
//	Nod* aux = cap;
//	Nod* maxim = cap;
//
//	while (aux->next) {
//		if (aux->info.suprafata > maxim->info.suprafata) {
//			maxim = aux;
//		}
//		aux = aux->next;
//		if (aux == cap) break;
//	}
//
//	//afisareMagazin(maxim->info);
//	printf(" %s ", maxim->info.nume);
//}
//
//void main() {
//	Magazin m;
//	Nod* cap = NULL;
//
//	char  linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("extra1_ListaCirculara_fisier.txt", "r");
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
//		cap = inserare(cap, m);
//
//		free(m.nume);
//		free(m.program);
//		free(m.varsteAngajati);
//	}
//	fclose(f);
//
//	afisareLista(cap);
//
//	printf("\n\nFunctii-------------------------------------------------------------------------------");
//
//	printf("\nTotal angajati pentru Flanco: %d", totalAngajati(cap, "Flanco"));
//	printf("\nTotal angajati pentru magazinele cu suprafata mai mare de 1000mp: %d", totalAngajatiPrag(cap, 1000));
//	printf("\nMedia suprafetei pentru Flanco: %.2f", medieSuprafete(cap, "Flanco"));
//	
//	modificaSuprafata(cap, "Samsung", 100.5);
//	printf("\n\nSuprafata modificata pentru Samsung: ");
//	afisareLista(cap);
//	
//	modificaProgram(cap, 11, "12:00-13:00");
//	printf("\n\nProgram modificat pt magazinul cu id 11: ");
//	afisareLista(cap);
//
//
//	printf("\n\nNr elemente in lista: %d", nrElemente(cap));
//
//	printf("\n\nNumele magazinul cu suprafata maxima:");
//	afiseazaMaxim(cap);
//
//
//	dezalocare(cap);
//}
//
