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
	struct Nod* prev;
	Student info;
	struct Nod* next; 
}Nod;

typedef struct LD {
	Nod* prim;
	Nod* ultim;
}LD;

Student initializareStudent(unsigned int id, char* nume, unsigned char nrMaterii, int* note) {
	Student s;
	s.id = id;
	s.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(s.nume, sizeof(char) * (strlen(nume) + 1), nume);
	s.nrMaterii = nrMaterii;
	s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
	for (int i = 0; i < s.nrMaterii; i++) {
		s.note[i] = note[i];
	}
	return s;
}

//pt a nu da 2 parametri de prim si ultim ne mai facem o structura care sa-i contina
LD inserareInceput(LD lista, Student s) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->prev = NULL;
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	if (lista.prim == NULL) { //e suficient verificarea lista.prim; daca nu exista prim, nu exista nici ultim
		lista.prim = nou; //daca lista e goala, atat prim cat si ultim = 1 singur nod
		lista.ultim = nou;
	}
	else {
		nou->next = lista.prim;
		lista.prim->prev = nou;
		lista.prim = nou;
	}
	return lista;
}

LD inserareFinal(LD lista, Student s) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->prev = NULL;
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	if (lista.prim == NULL) { 
		lista.prim = nou; //daca lista e goala, atat prim cat si ultim = 1 singur nod
		lista.ultim = nou;
	}
	else {
		nou->prev = lista.ultim;
		lista.ultim->next = nou;
		lista.ultim = nou;
	}
	return lista;
}

void afisareStudent(Student s) {
	printf("\n%u, %s, %u ", s.id, s.nume, s.nrMaterii);
	printf("Note: ");
	for (int i = 0; i < s.nrMaterii; i++) {
		printf("%d ", s.note[i]);
	}
}

void afisareInceput(LD lista) {
	if (lista.prim) {
		if (lista.prim) {
			Nod* aux = lista.prim;
			while (aux) {
				afisareStudent(aux->info);
				aux = aux->next;
			}
		}
	}
	else {
		printf("Lista este goala");

	}
}

void afisareFinal(LD lista) {
	if (lista.ultim) { //sau lista.prim
		Nod* aux = lista.ultim;
		while (aux) {
			afisareStudent(aux->info);
			aux = aux->prev;
		}
	}
}

void dezalocare(LD lista) {
	Nod* aux = lista.prim;
		while (aux) {
			free(aux->info.nume);
			free(aux->info.note);
	
			Nod* temp = aux->next; //pt a nu pierde legatura cu urmatorul nod (pierdem adresa din next-ul lui aux)
			free(aux); //aux="null"; informatia e goala
			aux = temp; //nu aux=aux->next pt ca aux e sters
		}
}

//stergere
LD stergere(LD* lista, const char* denCautata) {
	Nod* aux = lista->prim;

	while (aux) {
		if (strcmp(aux->info.nume, denCautata) == 0) {

			Nod* nodDeSters = aux;
			if (aux == lista->prim) {
				lista->prim = aux->next;
				lista->prim->prev = NULL;
				aux = aux->next;
			}else if(aux->next == NULL){
				aux->prev->next = NULL;
				aux = aux->next;
			}
			else { //mijloc
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				aux = aux->next;
			}
			free(nodDeSters->info.nume);
			free(nodDeSters->info.note);
			free(nodDeSters);
		}
		else {
			aux = aux->next;
		}
	}
	return *lista;
	
}

//conversie in lista simpla
//nod de lS, inserare, afisare, dezalocare

typedef struct NodLS {
	Student info;
	struct NodLS* next; //adressa nodului urmator
}NodLS;

NodLS* inserareSfarsitLS(NodLS* cap, Student s) {
	NodLS* nou = (NodLS*)malloc(sizeof(NodLS));
	nou->info = initializareStudent(s.id, s.nume, s.nrMaterii, s.note);
	nou->next = NULL;

	if (cap == NULL) {
		cap =  nou;
	}
	else {
		NodLS* aux = cap;
		while (aux->next) {//!=NULL
			aux = aux->next; //parcurgere
		}
		aux->next = nou;
	}
	return cap;
}

void afisareLS(NodLS* cap) {
	NodLS* aux = cap;
	while (aux) {
		afisareStudent(aux->info);
		aux = aux->next;
	}
}

void dezalocareLS(NodLS* cap) {
	NodLS* aux = cap;
	while (aux) {
		free(aux->info.nume);
		free(aux->info.note);

		NodLS* temp = aux->next;
		free(aux); //aux="null"; informatia e goala
		aux = temp; //nu aux=aux->next pt ca aux e sters

	}
}

//dubla->simpla
NodLS* conversie(LD lista) {
	Nod* aux = lista.prim;
	NodLS* cap = NULL;

	while (aux) {
		cap = inserareSfarsitLS(cap, aux->info);
		aux = aux->next;
	}
	return cap;
}


void main() {
		Student s;
		LD lista;
		lista.prim = NULL;  //Nu uita sa initializezi pointerii din LD
		lista.ultim = NULL;
		
	
		char linieBuffer[100];
		char separator[3] = ",";
		char* token = NULL;
	
		FILE* f = fopen("fisierListaDubla.txt", "r"); 
		if (!f) {
			printf("Fisierul nu a fost gasit!\n");
		}
	
			while (fgets(linieBuffer, 100, f)) {
				token = strtok(linieBuffer, separator);
				s.id = atoi(token);

				token = strtok(NULL, separator);
				s.nume = (char*)malloc(sizeof(char*) * (strlen(token) + 1));
				strcpy_s(s.nume, sizeof(char*) * (strlen(token) + 1), token);

				token = strtok(NULL, separator);
				s.nrMaterii = atoi(token);

				s.note = (int*)malloc(sizeof(int) * s.nrMaterii);
				for (int i = 0; i < s.nrMaterii; i++) {
					token = strtok(NULL, separator);
					s.note[i] = atoi(token);
				}

				//lista = inserareInceput(lista, s);
				lista = inserareFinal(lista, s);

				free(s.nume);
				free(s.note);
			}
	
		fclose(f);

		afisareInceput(lista);
		//afisareFinal(lista);

	/*	printf("\nStergere------------");
		stergere(&lista, "Patricia Coman");
		afisareInceput(lista);*/

		printf("\nConversie------------");
		NodLS* listaLS = NULL;
		listaLS = conversie(lista);
		afisareLS(listaLS);




		dezalocare(lista);
		dezalocareLS(listaLS);

}