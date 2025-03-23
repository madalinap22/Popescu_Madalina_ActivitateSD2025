#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//tabela de dispersie (vector pe care leg liste)
//10 "noduri"-> id(150)%10 = rest 0; poz 0
//coliziune = aceeasi pozitie (rest)
//la chaining pot insera la infinit; la linear probbing nu
typedef struct Student {
	unsigned int id;
	char* nume;
	unsigned char nrMaterii;
	int* note;
} Student;

//Necesar: nod, functie hash si structura de tabela (vector alocat dinamic)

typedef struct Nod {
	Student info;
	struct Nod* next;
}Nod;

typedef struct hashTable {
	int dim;
	Nod** vector; //vector de pointeri la noduri; * ca e vector dinamic si * pt ca pe fiecare pozitie sta cate o adresa de lista(cap)

}hashTable;

//tipuri functii: dupa un numeric, dupa un char*
int functieHash(hashTable tabela, unsigned int id) {
	return id % tabela.dim; 
}

int functieHash2(hashTable tabela, const char* nume) {
	return strlen(nume) % tabela.dim; 
}


Student initializareStudent(unsigned int id, const char* nume, unsigned char nrMaterii, int* note) {
	Student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
	s.nrMaterii = nrMaterii;
	s.note = (int*)malloc(sizeof(int) * nrMaterii);
	for (int i = 0; i < nrMaterii; i++) {
		s.note[i] = note[i];
	}

	return s;
}

void afisareStudent(Student s)
{
	printf("\n%u, %s, %u   ", s.id, s.nume, s.nrMaterii);
	for (int i = 0; i < s.nrMaterii; i++) {
		printf("%d ", s.note[i]);
	}
}

//la inserare stiu unde inserez (vector); int in caz ca trebuie sa vad pozitia la care am inserat
int inserare(hashTable tabela, Student s) {
	int poz = 0;
	if (tabela.vector) {
		poz = functieHash(tabela, s.id);
		Nod* nou = (Nod*)malloc(sizeof(Nod)); //////////////////////////////////////////////////////
		nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
		nou->next = NULL;

		if (tabela.vector[poz] == NULL) {
			tabela.vector[poz] = nou;
		}
		else {
			Nod* aux = tabela.vector[poz]; //<=> cap; tabela.vector[poz] e primul element din lista
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nou; //legatura la nodul nou
		}
	}
	return poz;
}
//daca am vector si daca am ceva in vector
void afisare(hashTable tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				printf("\nPozitia: %d", i);
				Nod* aux = tabela.vector[i];
				while (aux) {
					afisareStudent(aux->info); //sau un for
					aux = aux->next;
				}
			}
		}
	}
}

void dezalocare(hashTable tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					free(aux->info.nume);
					free(aux->info.note);
					Nod* temp = aux->next;
					free(aux);
					aux = temp;
				}
			}
		}
		free(tabela.vector); //alocata in main
	}
}

void main() {
	Student s;
	hashTable tabela;//neinitializata; ii dau dimensiune, aloc memorie + for

	tabela.dim = 10;
	tabela.vector=(Nod*)malloc(sizeof(Nod*) * tabela.dim);  /////////////////////////////
	for (int i = 0; i < tabela.dim; i++) {
		tabela.vector[i] = NULL;
	}

	char linieBuffer[100];
	char separator[3] = ","; //\n   ///////////////////////////////////
	char* token; //pun fiecare cuvant pana la virgula

	//eroare stream != nullptr-> fisier
	FILE* f = fopen("fisierHash.txt", "r");
	while (fgets(linieBuffer, 100, f)) { //sau sizeof(linieBuffer) in loc de 100
		token = strtok(linieBuffer,separator);
		s.id = atoi(token);

		token = strtok(NULL, separator); //!!!nu linieBuffer ca o ia de la capat
		s.nume = (char*)malloc(sizeof(char*) * (strlen(token) + 1));
		strcpy_s(s.nume, sizeof(char*) * (strlen(token) + 1), token);

		token = strtok(NULL, separator);
		s.nrMaterii = atoi(token);

		s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
		for (int i = 0; i < s.nrMaterii; i++) {
			token = strtok(NULL, separator);
			s.note[i] = atoi(token);
		}
		inserare(tabela, s);
		free(s.nume);
		free(s.note);

	}

	afisare(tabela);

}