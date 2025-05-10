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
//}Nod;
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
//Nod* adaugaInceput(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.cod,s.nume,s.specializare,s.varsta,s.nrNote,s.note);
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
//Nod* adaugaFinal(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.cod, s.nume, s.specializare, s.varsta, s.nrNote, s.note);
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
//void afisareStudent(Student s) {
//	printf("\n%u, %s, %s, %u, %d ", s.cod, s.nume, s.specializare, s.varsta, s.nrNote);
//	printf("Note: ");
//	for (int i = 0; i < s.nrNote; i++) {
//		printf("%.2f, ", s.note[i]);
//	}
//}
//
//void afisareLista(Nod* cap) {
//	Nod* aux = cap;
//	while (aux) {
//		afisareStudent(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
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
//Nod* maxim(Nod* cap) {
//	Nod* aux = cap;
//	Nod* max = cap;
//
//	while (aux) {
//		if (aux->info.varsta > max->info.varsta) {
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
//		if (aux->info.varsta == max->info.varsta) {
//			Nod* nodDeSters = aux;
//
//			if (prev == NULL) {
//				*cap = aux->next;
//				aux = aux->next;
//			}
//			else {
//				prev->next = aux->next;
//				aux = aux->next;
//			}
//			free(nodDeSters->info.nume);
//			free(nodDeSters->info.specializare);
//			free(nodDeSters->info.note);
//			free(nodDeSters);
//
//		}
//		else {
//			prev = aux;
//			aux = aux->next;
//		}
//		
//	}
//}
//
//int nrElemente(Nod* cap, int prag) {
//	Nod* aux = cap;
//	int contor = 0;
//	while (aux) {
//		if (aux->info.varsta > prag) {
//			contor++;
//		}
//		aux = aux->next;
//	}
//	return contor;
//}
//
//Student* conversieVector(Nod* cap, int prag) {
//	Nod* aux = cap;
//	int dim = nrElemente(cap, prag);
//	Student* vector = (Student*)malloc(sizeof(Student) * dim);
//	int index = 0;
//
//	while (aux) {
//		if (aux->info.varsta > prag) {
//			vector[index] = initializareStudent(aux->info.cod, aux->info.nume, aux->info.specializare, aux->info.varsta, aux->info.nrNote, aux->info.note);
//			index++;
//		}
//		aux = aux->next;
//	}
//	return vector;
//}
//
//void main() {
//	Student s;
//	Nod* cap = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex5_ListaSimpla.txt", "r");
//
//	//s.cod, s.nume, s.specializare, s.varsta, s.nrNote, s.note
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
//		//cap = adaugaInceput(cap, s);
//		cap = adaugaFinal(cap, s);
//		free(s.nume);
//		free(s.specializare);
//		free(s.note);
//
//	}
//	fclose(f);
//
//	afisareLista(cap);
//
//	printf("\n\nNod maxim");
//	Nod* max = maxim(cap);
//	afisareStudent(max->info);
//
//	printf("\n\nStergere: ");
//	/*stergeNod(&cap);
//	afisareLista(cap);*/
//
//	printf("\nNr elem: %d", nrElemente(cap, 21));
//
//	printf("\n\nConversie vector:");
//	int dim = nrElemente(cap, 21);
//	Student* vectorStudenti = conversieVector(cap, 21);
//	for (int i = 0; i < dim; i++) {
//		afisareStudent(vectorStudenti[i]);
//	}
//
//
//	dezalocare(cap);
//}