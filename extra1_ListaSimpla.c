//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////to do: stergere nod de pe o pozite data ca parametru, adaugare in lista a elementelor sortate crescator dupa un camp la alegere,
////interschimb, conversie in alta lista simpla, dubla?
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
//Magazin initializareMagazin(int id, char* nume, char* program, float suprafata, unsigned char nrAngajati, int* varsteAngajati) {
//	Magazin m;
//	m.id = id;
//	m.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(m.nume, (sizeof(char) * strlen(nume) + 1), nume);
//	m.program = (char*)malloc(sizeof(char) * strlen(program) + 1);
//	strcpy_s(m.program, (sizeof(char) * strlen(program) + 1), program);
//	m.suprafata = suprafata;
//	m.nrAngajati = nrAngajati;
//
//	m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
//	for (int i = 0; i < m.nrAngajati; i++) {
//		m.varsteAngajati[i] = varsteAngajati[i];
//	}
//
//	return m;
//}
//
//Nod* adaugaInceput(Nod* cap, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
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
//
//}
//
//Nod* adaugaSfarsit(Nod* cap, Magazin m) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
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
//	return cap; //!atentie
//}
//
//void afisareMagazin(Magazin m) {
//	printf("\n%d, %s, %s, %.2f, %d: ", m.id, m.nume, m.program, m.suprafata, m.nrAngajati);
//	for (int i = 0; i < m.nrAngajati; i++) {
//		printf("%d ", m.varsteAngajati[i]);
//	}
//}
//
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		afisareMagazin(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		free(aux->info.nume);
//		free(aux->info.program);
//		free(aux->info.varsteAngajati);
//		
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//
//}
////functii si metode
////suma dupa un char* ca parametru -> total angajati dupa denumire
//int totalAngajati(Nod* cap, const char* denCautata) {
//	int suma = 0;
//
//	Nod* aux = cap;
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
//int totalAngajatiPrag(Nod* cap, int pragSuprafata) {
//	int suma = 0;
//
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.suprafata >= pragSuprafata) {
//			suma += aux->info.nrAngajati;
//		}
//		aux = aux->next;
//	}
//	return suma;
//}
//
////medie
////sa se afle media suprafetelor magazinelor cu numele dat ca parametru
//float medieSuprafete(Nod* cap, const char* denCautata) {
//	float suma = 0;
//	int contor = 0;
//
//	Nod* aux = cap;
//	while (aux) {
//		if (strcmp(aux->info.nume, denCautata) == 0) {
//			suma += aux->info.suprafata;
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return suma / contor;
//}
////modificare numeric dupa char*
////modifica nr angajati dupa nume
//void modificaSuprafata(Nod* cap, const char* denCautata, float suprafNoua) {
//	Nod* aux = cap;
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
//void modificaProgram(Nod* cap, int idCautat, char* programNou) {
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.id == idCautat) {
//			aux->info.program = (char*)malloc(sizeof(char) * strlen(programNou) + 1);
//			strcpy_s(aux->info.program, sizeof(char) * (strlen(programNou) + 1), programNou);
//		}
//		aux = aux->next;
//	}
//}
////maxim = suprafata maxima
////sa se afiseze magazinul cu suprafata cea mai mare
//void afiseazaMaxim(Nod* cap) {
//	Nod* aux = cap;
//	Nod* maxim = cap;
//
//	while (aux) {
//		if (aux->info.suprafata > maxim->info.suprafata) {
//			maxim = aux;
//		}
//		aux = aux->next;
//	}
//	//afisareMagazin(maxim->info);
//	printf(" %s ", maxim->info.nume);
//}
//
////Conversie vector
////sa se salveze in vector magazinele cu o suprafata mai mare de 400 mp
//int nrElemente(Nod* cap, int prag) {
//	Nod* aux = cap;
//	int contor = 0;
//
//	while (aux) {
//		if (aux->info.suprafata > prag) {
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//}
//
//Magazin* vectorFiltrat(Nod* cap, int prag) {
//
//	//alocare memorie pt vector
//	int dim = nrElemente(cap, prag);
//	Magazin* vector = (Magazin*)malloc(sizeof(Magazin) * dim);
//
//	//index pt vector
//	int index = 0;
//
//	//parcurgere lista si punem elem in vector
//	Nod* aux = cap;
//	while (aux) {
//		if (aux->info.suprafata > prag) {
//			vector[index] = initializareMagazin(aux->info.id, aux->info.nume, aux->info.program,
//				aux->info.suprafata, aux->info.nrAngajati, aux->info.varsteAngajati);
//			index++;
//		}
//		aux = aux->next;
//	}
//
//	return vector;
//}
//
//
//void main() {
//
//	Magazin m;
//	Nod* cap = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("extra1_ListaSimpla.txt", "r");
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
//		token = strtok(NULL, separator);
//		m.varsteAngajati[i] = atoi(token);
//		}
//
//		//cap = adaugaInceput(cap, m);
//		cap = adaugaSfarsit(cap, m);
//		free(m.nume);
//		free(m.program);
//		free(m.varsteAngajati);
//
//	}
//	fclose(f);
//
//	afisareLista(cap);
//
//	printf("\nFunctii--------------------------");
//
//	printf("\n Nr total angajati Flanco: %d", totalAngajati(cap, "Flanco"));
//
//	printf("\n Nr total angajati pt magazinele >1000p: %d", totalAngajatiPrag(cap, 1000));
//
//	printf("\n Medie suprafete pt Flanco: %.2f", medieSuprafete(cap, "Flanco"));
//
//	modificaSuprafata(cap, "Samsung", 110.5);
//	printf("\n\nSuprafata modificata pentru Samsung: ");
//	afisareLista(cap);
//	
//	//afisare doar a magazinului in cauza
//	printf("\nMagazinul cu suprafata schimbata: ");
//	Nod* aux = cap;
//	while (aux) {
//		if (strcmp(aux->info.nume, "Samsung") == 0) {
//			afisareMagazin(aux->info);
//			printf("\nSuprafata modificata: %.2f", aux->info.suprafata);
//		//	break;  // doar afisare primul nod gasit
//		}
//		aux = aux->next;
//	}
//
//	modificaProgram(cap, 6, "12:00-13:00");
//	printf("\n\nProgram modificat pt magazinul cu id 6: ");
//	afisareLista(cap);
//
//	printf("\n\nMagazinul cu suprafata maxima: ");
//	afiseazaMaxim(cap);
//
//	printf("\nNr magazine cu suprafata mai mare de 400mp: %d", nrElemente(cap, 400));
//
//	printf("\nConversie vector: ");
//	int dim = nrElemente(cap, 400);
//	Magazin* vectorMagazine = vectorFiltrat(cap, 400);
//	for (int i = 0; i < dim; i++) {
//		afisareMagazin(vectorMagazine[i]);
//	}
//
//
//
//
//
//
//	dezalocare(cap);
//
//}