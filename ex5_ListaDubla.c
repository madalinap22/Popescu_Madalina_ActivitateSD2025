//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Student {
//	unsigned int cod;
//	char* nume;
//	char* specializare;
//	unsigned char varsta;
//	int nrNote;
//	float* note;
//}Student;
//
//typedef struct Nod {
//	Student info;
//	struct Nod* next;
//	struct Nod* prev;
//}Nod;
//
//typedef struct LD {
//	struct Nod* prim;
//	struct Nod* ultim;
//}LD;
//
//Student initializareStudent(unsigned int cod, char* nume, char* specializare, unsigned char varsta, int nrNote, float* note) {
//	Student s;
//	s.cod = cod;
//	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(s.nume, (sizeof(char) * strlen(nume) + 1), nume);
//	s.specializare = (char*)malloc(sizeof(char) * strlen(specializare) + 1);
//	strcpy_s(s.specializare, (sizeof(char) * strlen(specializare) + 1), specializare);
//	s.varsta = varsta;
//	s.nrNote = nrNote;
//	s.note = (float*)malloc(sizeof(float) * s.nrNote);
//	for (int i = 0; i < s.nrNote; i++) {
//		s.note[i] = note[i];
//	}
//	return s;
//}
//
//LD adaugaInceput(LD lista, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.cod, s.nume, s.specializare, s.varsta, s.nrNote, s.note);
//	nou->next = NULL;
//	nou->prev = NULL;
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
//LD adaugaFinal(LD lista, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.cod, s.nume, s.specializare, s.varsta, s.nrNote, s.note);
//	nou->next = NULL;
//	nou->prev = NULL;
//
//	if (lista.ultim == NULL) {
//		lista.ultim = lista.prim = nou;
//	}
//	else {
//		lista.ultim->next = nou;
//		nou->prev = lista.ultim;
//		lista.ultim = nou;
//	}
//	return lista;
//}
//void afisareStudent(Student s) {
//	printf("\n%u, %s, %s, %u, %d ", s.cod, s.nume, s.specializare, s.varsta, s.nrNote);
//	printf("Note: ");
//	for (int i = 0; i < s.nrNote; i++) {
//		printf("%.2f, ", s.note[i]);
//	}
//
//}
//void afisareListaInceput(LD lista) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		afisareStudent(aux->info);
//		aux = aux->next;
//	}
//}
//void afisareListaFinal(LD lista) {
//	Nod* aux = lista.ultim;
//	while (aux) {
//		afisareStudent(aux->info);
//		aux = aux->prev;
//	}
//}
//void dezalocare(LD lista) {
//	Nod* aux = lista.prim;
//	while (aux) {
//		free(aux->info.nume);
//		free(aux->info.specializare);
//		free(aux->info.note);
//
//		Nod* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//}
//
//Nod* maxim(LD lista) {
//	Nod* aux = lista.prim;
//	Nod* max = lista.prim;
//
//	while (aux) {
//		if (aux->info.varsta > max->info.varsta) {
//			max = aux;
//		}
//		aux = aux->next;
//	}
//	return max;
//}
//LD stergeNod(LD* lista) {
//	Nod* aux = lista->prim;
//	Nod* max = maxim(*lista);
//
//	while (aux) {
//		if (aux->info.varsta == max->info.varsta) {
//			Nod* nodDeSters = aux;
//			if (aux == lista->prim) {
//				aux->next = lista->prim;
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
//			free(nodDeSters->info.nume);
//			free(nodDeSters->info.specializare);
//			free(nodDeSters->info.note);
//			free(nodDeSters);
//		}
//		else {
//			aux = aux->next;
//		}
//	}
//	return *lista;
//}
//
//void main() {
//	Student s;
//	LD lista;
//	lista.prim = NULL;
//	lista.ultim = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex5_ListaSimpla.txt", "r");
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		s.cod = atoi(token);
//
//		token = strtok(NULL, separator);
//		s.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(s.nume, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		s.specializare = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(s.specializare, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		s.varsta = atoi(token);
//
//		token = strtok(NULL, separator);
//		s.nrNote = atoi(token);
//
//		s.note = (float*)malloc(sizeof(float) * s.nrNote);
//		for (int i = 0; i < s.nrNote; i++) {
//			token = strtok(NULL, separator);
//			s.note[i] = atof(token);
//		}
//
//		lista = adaugaFinal(lista, s);
//		//lista = adaugaInceput(lista, s);
//		free(s.nume);
//		free(s.specializare);
//		free(s.note);
//
//	}
//	fclose(f);
//
//	//afisareListaFinal(lista);
//	afisareListaInceput(lista);
//
//	printf("\n\nMaxim:");
//	Nod* max = maxim(lista);
//	afisareStudent(max->info);
//
//	printf("\n\nStergere");
//	stergeNod(&lista);
//	afisareListaInceput(lista);
//
//
//
//	dezalocare(lista);
//
//}
