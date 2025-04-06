//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct Student{
//	unsigned int id;
//	char* nume; //&
//	unsigned char nrMaterii;
//	int* note;
//}Student;
//
//typedef struct Nod {
//	Student info;
//	struct Nod* next; //adressa nodului urmator
//}Nod;
//
//Student initializareStudent(unsigned int id, char* nume, unsigned char nrMaterii, int* note) {
//	Student s;
//	s.id = id;
//	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
//	s.nrMaterii = nrMaterii;
//	s.note = (int*)malloc(sizeof(int) * s.nrMaterii); //nrMaterii
//	for (int i = 0; i < s.nrMaterii; i++) {
//		s.note[i] = note[i];
//	}
//	return s;
//}
////cand te duci prin valoarea compilatorul face copie
//
////pt pastrarea adresei cap functia o facem de tipul Nod*; daca era void trebuia sa am Nod** cap ca parametru ca sa pot schimba informatia din cap
//Nod* inserareInceput(Nod* cap, Student s) {
//	//ma intereseaz adresa nodului desci avem Nod* nou
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	//nou->info = s; //shallow copy
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
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
//Nod* inserareSfarsit(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap =  nou;
//	}
//	else {
//		Nod* aux = cap;
//		while (aux->next) {//!=NULL
//			aux = aux->next; //parcurgere
//		}
//		aux->next = nou;
//	}
//	return cap;
//}
//
//void afisareStudent(Student s) {
//	printf("\n%u, %s, %u ", s.id, s.nume, s.nrMaterii);
//	printf("Note: ");
//	for (int i = 0; i < s.nrMaterii; i++) {
//		printf("%d ", s.note[i]);
//	}
//}
//
//void afisare(Nod* cap) {
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
//		free(aux->info.note);
//
//		Nod* temp = aux->next;
//		free(aux); //aux="null"; informatia e goala
//		aux = temp; //nu aux=aux->next pt ca aux e sters
//
//	}
//
//
// }
//
//
//
//void main() {
//	Student s;
//	Nod* cap = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ListaSimplaStudenti.txt", "r"); 
//	if (!f) {
//		printf("Fisierul nu a fost gasit!\n");
//	}
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		s.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		s.nume = (char*)malloc(sizeof(char*) * (strlen(token) + 1));
//		strcpy_s(s.nume, sizeof(char*) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		s.nrMaterii = atoi(token);
//
//		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
//		for (int i = 0; i < s.nrMaterii; i++) {
//		token = strtok(NULL, separator);
//		s.note[i] = atoi(token);
//		}
//		//cap = inserareInceput(cap, s);
//		cap = inserareSfarsit(cap, s);
//
//		free(s.nume);
//		free(s.note);
//	}
//	fclose(f);
//
//	afisare(cap);
//
//
//
//	dezalocare(cap);
//}