//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////to do conversie si salvare in vector, dezalocare - cu pop pana la ultimul nod
//
////typedef struct Student Student;
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
//void push(Nod** varf, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
//	nou->next = NULL;
//
//	if (*varf == NULL){ //varf == NULL
//		*varf = nou;
//	}
//	else {
//		nou->next = *varf;
//		*varf = nou;
//	}
//}
//
//int pop(Nod** varf, Student* s) { //o adresa in care pun studentul scos
//	if (*varf == NULL) {
//		return -1;
//	}
//	else {
//		*s = initializareStudent((*varf)->info.id, (*varf)->info.nume, 
//			(*varf)->info.nrMaterii, (*varf)->info.note); //facem o copie
//		//sau: unsigned int id = (*varf)->info.id si initializareStudent(id, ....)
//
//		Nod* temp = (*varf)->next;
//		free((*varf)->info.note);
//		free((*varf)->info.nume);
//		free(*varf);
//
//		*varf = temp;
// return 0;
//	}
//
//}
//
//void afisare(Nod* varf) {
//	Nod* aux = varf;
//	while (aux) {
//		afisareStudent(aux->info); //aux->info = s
//		aux = aux->next;
//	}
//}
//
////to do conversie si salvare in vector
//
//
//void main()
//{
//	Student s;
//	int nr;
//	char buffer[50];
//	Nod* varf = NULL;
//
//	FILE* f = fopen("fisierStiva.txt", "r");
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
//		push(&varf, s);
//
//		free(s.nume);
//		free(s.note);
//	}
//
//	fclose(f);
//
//	afisare(varf);
//
//
//
//
//}