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
//	struct Nod* next; 
//}Nod;
//
//Student initializareStudent(unsigned int id, char* nume, unsigned char nrMaterii, int* note) {
//	Student s;
//	s.id = id;
//	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
//	s.nrMaterii = nrMaterii;
//	s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
//	for (int i = 0; i < s.nrMaterii; i++) {
//		s.note[i] = note[i];
//	}
//	return s;
//}
//
//Nod* inserare(Nod* cap, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
//	nou->next = NULL;
//
//	if (cap == NULL) {
//		cap = nou; /////////atentie NU nou = cap; pt ca cap este NULL si nou devine NULL
//		nou->next = cap;  //1 singur nod legat la el insusi
//	
//	}
//	else {
//		Nod* aux = cap;
//		while (aux->next != cap) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//		nou->next = cap;
//		//cap=nou; ////////////////////////////////////////////////////
//
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
//	while (aux->next != cap) {
//		afisareStudent(aux->info);
//		aux = aux->next;
//	}
//	afisareStudent(aux->info); //ca sa afiseze si ultimul nod (din cauza conditie while; pt ca se opreste cand aux->next = cap))
//}
//
//void dezalocare(Nod* cap) {
//	Nod* aux = cap;
//	while (aux->next != cap) {
//		free(aux->info.nume);
//		free(aux->info.note);
//
//		Nod* temp = aux->next; ///////////////////////ca nu mai am info? si pastrez doar next-ul?
//		free(aux);
//		aux = temp;
//	}
//	free(aux->info.nume); //stergere ultimul nod
//	free(aux);
//}
//
//void main(){
//		Student s;
//		Nod* cap = NULL;
//	
//		char linieBuffer[100];
//		char separator[3] = ",";
//		char* token = NULL;
//	
//		FILE* f = fopen("fisierListaCirculara.txt", "r"); 
//		if (!f) {
//			printf("Fisierul nu a fost gasit!\n");
//		}
//	
//		while (fgets(linieBuffer, 100, f)) {
//			token = strtok(linieBuffer, separator);
//			s.id = atoi(token);
//	
//			token = strtok(NULL, separator);
//			s.nume = (char*)malloc(sizeof(char*) * (strlen(token) + 1));
//			strcpy_s(s.nume, sizeof(char*) * (strlen(token) + 1), token);
//	
//			token = strtok(NULL, separator);
//			s.nrMaterii = atoi(token);
//	
//			s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
//			for (int i = 0; i < s.nrMaterii; i++) {
//			token = strtok(NULL, separator);
//			s.note[i] = atoi(token);
//			}
//			
//			cap = inserare(cap, s);
//	
//			free(s.nume);
//			free(s.note);
//		}
//		fclose(f);
//
//		afisare(cap);
//
//
//
//		dezalocare(cap);
//}
//
