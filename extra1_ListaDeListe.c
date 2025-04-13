#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//to do: conversii, stergere; vezi conditie dupa cheie char; case-uri la conditie pt mai multe subliste;

typedef struct Magazin {
	int id;
	char* nume;
	char* categorie;
	float suprafata;
	unsigned char nrAngajati;
	int* varsteAngajati;
}Magazin;

typedef struct Nodls {
	Magazin info;
	struct Nodls* next;
}Nodls;


typedef struct Nodlp {
	Nodls* info;  //cap de lista secundara
	struct Nodlp* next;
}Nodlp;

Magazin initializareMagazin(int id, const char* nume, const char* categorie, float suprafata, unsigned char nrAngajati, int* varsteAngajati) {
	Magazin m;
	m.id = id;
	m.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
	strcpy_s(m.nume, sizeof(char) * (strlen(nume) + 1), nume);
	m.categorie = (char*)malloc(sizeof(char) * (strlen(categorie) + 1));
	strcpy_s(m.categorie, sizeof(char) * (strlen(categorie) + 1), categorie);
	m.suprafata = suprafata;
	m.nrAngajati = nrAngajati;

	m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
	for (int i = 0; i < m.nrAngajati; i++) {
		m.varsteAngajati[i] = varsteAngajati[i];
	}
	return m;
}

Nodls* inserareLs(Nodls* capls, Magazin m) {
	Nodls* nou = (Nodls*)malloc(sizeof(Nodls));
	nou->info = initializareMagazin(m.id, m.nume, m.categorie, m.suprafata, m.nrAngajati, m.varsteAngajati);
	nou -> next = NULL;

	if (capls == NULL) {
		capls = nou;
	}
	else {
		Nodls* aux = capls;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	return capls;
}

Nodlp* inserareLp(Nodlp* caplp, Nodls* capls) {
	Nodlp* nou = (Nodlp*)malloc(sizeof(Nodlp));
	nou->info = capls;  //adresa primului nd din lista secundara
	nou->next = NULL;

	if (caplp == NULL) {
		caplp = nou;
	}
	else {
		Nodlp* aux = caplp;
		while (aux->next) { //!aux->next
			aux = aux->next;
		}
		aux->next = nou;
	}
	return caplp;
}

//int id;
//char* nume;
//char* categorie;
//float suprafata;
//unsigned char nrAngajati;
//int* varsteAngajati;

void afisareMagazin(Magazin m) {
	printf("\n%d, %s, %s, %.2f, %u", m.id, m.nume, m.categorie, m.suprafata, m.nrAngajati);
	printf(" Varste angajati: ");
	for (int i = 0; i < m.nrAngajati; i++) {
		printf("%d ", m.varsteAngajati[i]);
	}
}

void afisareLs(Nodls* capls) {
	if (capls != NULL) {
		Nodls* aux = capls;
		while (aux) { ////////////////////////////////// aux?
			afisareMagazin(aux->info);
			aux = aux->next;
		}
	}
	else {
		printf("Lista este goala");
	}
}

//intri pe nod de lp si afisezi in jos; apelare afisareLs
void afisareLp(Nodlp* caplp) {
	Nodlp* aux = caplp;
	int contor = 1; //pt vizibilitatea sublistelor

	while (aux) { /////////////////////////////////////////aux?
		printf("\nSublista: %d", contor);
		afisareLs(aux -> info);
		contor++;
		aux = aux->next;
	}
}

void dezalocareLs(Nodls* capls) {
	Nodls* aux = capls;
	while (aux) {
		free(aux->info.nume);
		free(aux->info.categorie);
		free(aux->info.varsteAngajati);

		Nodls* temp = aux->next;
		free(aux);
		aux = temp;
	}
}

//cu apelul dezalocarii listei secundare
void dezalocareLp(Nodlp* caplp) {
	Nodlp* aux = caplp;
	while (aux) {
		dezalocareLs(aux->info);
		Nodlp* temp = aux->next;
		free(aux);
		aux=temp;
	}
}


void main() {
	Magazin m;
	Nodls* capls = NULL;
	Nodlp* caplp = NULL;
	Nodls* capls2 = NULL; //pt conditia de inserare

	char linieBuffer[100];
	char separator[3] = ",";
	char* token;

	FILE* f = fopen("extra1_ListaDeListe_fisier.txt", "r");
	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		m.id = atoi(token);

		token = strtok(NULL, separator);
		m.nume = (char*)malloc(sizeof(char) * (strlen(token) + 1));
		strcpy_s(m.nume, sizeof(char) * (strlen(token) + 1), token);

		token = strtok(NULL, separator);
		m.categorie = (char*)malloc(sizeof(char) * (strlen(token) + 1));
		strcpy_s(m.categorie, sizeof(char) * (strlen(token) + 1), token);

		token = strtok(NULL, separator);
		m.suprafata = atof(token);

		token = strtok(NULL, separator);
		m.nrAngajati = atoi(token);

		m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
		for (int i = 0; i < m.nrAngajati; i++) {
			token = strtok(NULL, separator);
			m.varsteAngajati[i] = atoi(token);
		}

		//capls = inserareLs(capls, m);

		if (m.id % 2 == 0) {
			capls = inserareLs(capls, m);
		}
		else {
			capls2 = inserareLs(capls2, m);
		}
		free(m.nume);
		free(m.categorie);
		free(m.varsteAngajati);

	}
	fclose(f);

	afisareLs(capls);
	afisareLs(capls2); //else-ul

	printf("\n\nLista de liste:");
	caplp = inserareLp(caplp, capls);
	caplp = inserareLp(caplp, capls2);
	afisareLp(caplp);






	dezalocareLp(caplp);
}





