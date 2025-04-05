#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Student{
	unsigned int id;
	char* nume; //&
	unsigned char nrMaterii;
	int* note;
}Student;

typedef struct Nod {
	Student info;
	Nod* next; //adressa nodului urmator
}Nod;

Student initializareStudent(unsigned int id, char* nume, unsigned char nrMaterii, int* note) {
	Student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
	s.nrMaterii = nrMaterii;
	s.note = (int*)malloc(sizeof(int) * s.nrMaterii); //nrMaterii
	for (int i = 0; i < s.nrMaterii; i++) {
		s.note[i] = note[i];
	}
	return s;
}
//cand te duci prin valoarea compilatorul face copie

//pt pastrarea adresei cap functia o facem de tipul Nod*; daca era void trebuia sa am Nod** cap ca parametru ca sa pot schimba informatia din cap
Nod* inserareInceput(Nod* cap, Student s) {
	//ma intereseaz adresa nodului desci avem Nod* nou
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	//nou->info = s; //shallow copy
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	if (cap == NULL) {
		cap = nou;
	}
	else {
		nou->next = cap;
		cap = nou;
	}
	return cap;
}

Nod* inserareSfarsit(Nod* cap, Student s) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	if (cap == NULL) {
		cap =  nou;
	}
	else {
		Nod* aux = cap;
		while (aux->next) {//!=NULL
			aux = aux->next; //parcurgere
		}
		aux->next = nou;
	}
	return cap;
}

void afisareStudent(Student s) {
	printf("\n%u, %s, %u ", s.id, s.nume, s.nrMaterii);
	/*printf("Note: ");*/
	for (int i = 0; i < s.nrMaterii; i++) {
		printf("%d", s.note[i]);
	}
}

void afisare(Nod* cap) {
	Nod* aux = cap;
	while (aux) {
		afisareStudent(aux->info);
		aux = aux->next;

	}
}

//to do: dezalocare + citire din fisier



void main() {

}