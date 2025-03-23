//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////to do - conversii
//
//typedef struct Student {
//	unsigned int id;
//	char* nume;
//	unsigned char nrMaterii;
//	int* note;
//} Student;
//
//typedef struct Nod {
//	Student info;
//	struct Nod* next;
//}Nod;
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
//void afisareStudent(Student s)
//{
//	printf("\n%u, %s, %u   ", s.id, s.nume, s.nrMaterii);
//	for (int i = 0; i < s.nrMaterii; i++) {
//		printf("%d ", s.note[i]);
//	}
//}
//
//void put(Nod** prim, Nod** ultim, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
//	nou->next = NULL;
//
//	if (*prim == NULL && *ultim == NULL) { //*prim == NULL
//		*prim = nou;
//		*ultim = nou;
//	}
//	else {
//		(*ultim)->next = nou;
//		*ultim = nou;
//	}
//
//}
//
//int get(Nod** prim, Nod** ultim, Student* s) {
//	if (prim == NULL && ultim == NULL) { ///////*prim si *ultim
//		return -1;
//	}
//	else {
//		*s = initializareStudent((*prim)->info.id, (*prim)->info.nume,
//			(*prim)->info.nrMaterii, (*prim)->info.note);
//		
//		Nod* temp = (*prim)->next;
//				free((*prim)->info.note);
//				free((*prim)->info.nume);
//				free(*prim);
//		
//				*prim = temp;
//
//				return 0;
//	
//	}
//}
//
//
//
//void afisare(Nod* varf) {
//	Nod* aux = varf;
//	while (aux) {
//		afisareStudent(aux->info); //aux->info = s
//		aux = aux->next;
//	}
//}
//
//
//
//
//void main()
//{
//	Student s;
//	int nr;
//	char buffer[50];
//	Nod* prim = NULL;
//	Nod* ultim = NULL;
//
//	FILE* f = fopen("fisierCoada.txt", "r");
//	fscanf(f, "%d", &nr);
//
//	for (int i = 0; i < nr; i++) {
//		fscanf(f, "%u", &s.id);
//
//		fscanf(f, "%s", buffer);
//		s.nume = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
//		strcpy_s(s.nume, sizeof(char) * (strlen(buffer) + 1), buffer);
//
//		fscanf(f, "%u", &s.nrMaterii);
//		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
//		for (int i = 0; i < s.nrMaterii; i++) {
//			fscanf(f, "%d", &s.note[i]);
//		}
//
//		put(&prim, &ultim, s);
//
//		free(s.nume);
//		free(s.note);
//	}
//
//	fclose(f);
//
//	afisare(prim);
//
//	Student s1;
//	get(&prim, &ultim, &s1);
//	printf("\n\n");
//	afisare(prim);
//
//	printf("\n\n");
//	afisareStudent(s1);
//
//
//
//
//}