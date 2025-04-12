//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//
//
//typedef struct Student Student;
//typedef struct Nodls Nodls;
//typedef struct Nodlp Nodlp;
//
//typedef struct Student {
//	unsigned int id;
//	char* nume;
//	unsigned char nrMaterii;//0-255 - > este numeric
//	int* note;
//} Student;
//
//typedef struct Nodls {
//	Student info;
//	struct Nodls* next;
//
//} Nodls;
//
//typedef struct Nodlp {
//	Nodls* info; //cap de lista secundara
//	Nodlp* next;
//
//} Nodlp;
//
//
//Student initializareStudent(unsigned int id, const char* nume, unsigned char nrMaterii, int* note) {
//	Student s;
//	s.id = id;
//	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
//	s.nrMaterii = nrMaterii;
//	s.note = (int*)malloc(sizeof(int) * nrMaterii);
//	for (int i = 0; i < nrMaterii; i++) {
//		s.note[i] = note[i];
//	}
//
//	return s;
//}
//
////ins in lista simpla/secundara
//Nodls* inserareLs(Nodls* capls, Student s) {
//	//creare nod
//	Nodls* nou = (Nodls*)malloc(sizeof(Nodls));
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
//	nou->next = NULL;
//
//	//inserare
//	if (capls == NULL) {
//		capls = nou;
//	}
//	else {
//		Nodls* aux = capls;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	return capls;
//}
//
////inserare lista principala
//Nodlp* inserareLp(Nodlp* caplp, Nodls* capls) {//adresa de inceput a listei secundare
//	Nodlp* nou = (Nodlp*)malloc(sizeof(Nodlp));
//	nou->info = capls; //asteapta o adresa, am o adresa
//	nou->next = NULL;
//	if (caplp == NULL) {
//		caplp = nou;
//	}
//	else {
//		Nodlp* aux = caplp;
//		while (aux->next) { //while(aux) nu insereaza
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	return caplp;
//}
////afisare Student
//void afisareStudent(Student s)
//{
//	printf("\n%u, %s, %u   ", s.id, s.nume, s.nrMaterii);
//	for (int i = 0; i < s.nrMaterii; i++) {
//		printf("%d ", s.note[i]);
//	}
//}
////afisare ls
//void afisareLs(Nodls* capls) {
//	Nodls* aux = capls;
//	while (aux) {
//		printf("\n%u, %s, %u   ", aux->info.id, aux->info.nume, aux->info.nrMaterii);
//		for (int i = 0; i < aux->info.nrMaterii; i++) {
//			printf("%d ", aux->info.note[i]);
//		}
//		aux = aux->next;
//	}
//	printf("\n");
//}
//
////afisare lp
//void afisareLp(Nodlp* caplp) {
//	Nodlp* aux = caplp;
//	int contor = 1;
//	while (aux) {
//		printf("Sublista: %d", contor++);
//		afisareLs(aux->info);
//		aux = aux->next;
//	}
//}
//
//void dezalocareLs(Nodls* capls) {
//	Nodls* aux = capls;
//	while (aux) {
//		free(aux->info.nume);
//		free(aux->info.note);
//		Nodls* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//}
//
//void dezalocareLp(Nodlp* caplp) {
//	Nodlp* aux = caplp;
//	while (aux) {
//		dezalocareLs(aux->info);
//		Nodlp* temp = aux->next;
//		free(aux);
//		aux = temp;
//	}
//}
//
//void main()
//{
//	int nr;
//	Student s;
//	Nodls* capls = NULL;
//	Nodlp* caplp = NULL;
//	Nodls* capls1 = NULL;
//
//	char buffer[40];
//
//	FILE* f = fopen("fisierListaDeListe.txt", "r");
//	fscanf(f, "%d", &nr);
//
//	for (int i = 0; i < nr; i++) {
//		fscanf(f, "%u", &s.id);
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy_s(s.nume, sizeof(char) * (strlen(buffer) + 1), buffer);
//		fscanf(f, "%u", &s.nrMaterii);
//		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
//		for (int i = 0; i < s.nrMaterii; i++) {
//			fscanf(f, "%d", &s.note[i]);
//		}
//
//		//conditii
//		if (s.id % 2 == 0) {
//			capls = inserareLs(capls, s);
//		}
//		else {
//			capls1 = inserareLs(capls1, s);
//		}
//
//		free(s.nume);
//		free(s.note);
//	}
//	fclose(f);
//	afisareLs(capls);
//	afisareLs(capls1);
//
//	caplp = inserareLp(caplp, capls);
//	caplp = inserareLp(caplp, capls1);
//
//	printf("\nLista de liste ------------------------------\n");
//	afisareLp(caplp);
//}
