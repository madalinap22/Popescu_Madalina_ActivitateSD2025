#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//to do: conversie vector + alte functii

//tabela de dispersie (vector pe care leg liste)
//10 "noduri"-> id(150)%10 = rest 0; poz 0
//coliziune = aceeasi pozitie (rest)
typedef struct Magazin {
	int id;
	char* nume;
	char* program;
	float suprafata;
	unsigned char nrAngajati;
	int* varsteAngajati;
}Magazin;

//nod de lista simpla
typedef struct Nod {
	Magazin info;
	struct Nod* next;
}Nod;

typedef struct HT {
	int dim;
	Nod** vector; //vector de pointeri la noduri; * ca e vector dinamic si * pt ca pe fiecare pozitie sta cate o adresa de lista(cap)

}HT;

//tipuri functii: dupa un numeric, dupa un char*
int functieHashInt(HT tabela, unsigned int id) {
	return id % tabela.dim; 
}

int functieHashChar(HT tabela, const char* nume) {
	return strlen(nume) % tabela.dim; 
}

Magazin initializareMagazin(int id, char* nume, char* program, float suprafata, unsigned char nrAngajati, int* varsteAngajati) {
	Magazin m;
	m.id = id;
	m.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(m.nume, (sizeof(char) * strlen(nume) + 1), nume);
	m.program = (char*)malloc(sizeof(char) * strlen(program) + 1);
	strcpy_s(m.program, (sizeof(char) * strlen(program) + 1), program);
	m.suprafata = suprafata;
	m.nrAngajati = nrAngajati;

	m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
	for (int i = 0; i < m.nrAngajati; i++) {
		m.varsteAngajati[i] = varsteAngajati[i];
	}

	return m;
}

int inserare(HT tabela, Magazin m) {

	int poz = 0;

	if (tabela.vector) {
		Nod* nou = (Nod*)malloc(sizeof(Nod));
		nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
		nou->next = NULL;

		//poz = functieHashChar(tabela, m.nume);
		poz = functieHashInt(tabela, m.id);
		if (tabela.vector[poz] == NULL) { //daca poz este nula
			tabela.vector[poz] = nou;
		}
		else {
			Nod* aux = tabela.vector[poz]; //tabela.vector[poz] este primul element din lista exp:tabela.vector[7] = adresa cap de lista
			while (aux->next) { //NU while(aux) pt ca va ajunge la sfarsit pe aux NULL
				aux = aux->next;
			}
			aux->next = nou;
		}

	}
	return poz;
}

void afisareMagazin(Magazin m) {
	printf("\n%d, %s, %s, %.2f, %d: ", m.id, m.nume, m.program, m.suprafata, m.nrAngajati);
	for (int i = 0; i < m.nrAngajati; i++) {
		printf("%d ", m.varsteAngajati[i]);
	}
}

//la fiecare functie ma intreb daca am vector si daca am ceva pe pozitie
void afisare(HT tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) { //parcurgere lateral
			//printf("\nPozitie: %d", i);
			if (tabela.vector[i]) { //parcurgere in jos
				printf("\nPozitie: %d", i);
				Nod* aux = tabela.vector[i]; //pozitionare pe primul elem
				while (aux) {
					afisareMagazin(aux->info);
					aux = aux->next;
				}
			}
		}

	}
}

void dezalocare(HT tabela) {
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					free(aux->info.nume);
					free(aux->info.program);
					free(aux->info.varsteAngajati);
					Nod* temp = aux->next;
					free(aux);
					aux = temp;
				}
			}
		}
		free(tabela.vector); //alocata in main
	}
}
//functii------------------------
//contor dupa char*
//nrElemente dupa un char* ca parametru -> nr magazine dupa denumire (denumirea nu este cheie)
int nrMagazine(HT tabela, const char* denCautata) {

	int contor = 0;
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					if (strcmp(aux->info.nume, denCautata) == 0) {
						contor++;
					}
				aux = aux->next;
				}
			}
		}
		
	}
	return contor;
}

//suma dupa char*
//suma dupa un int ca parametru -> total angajati la magazinele cu suprafata mai mare de 1000 mp
int sumaAngajati(HT tabela, int prag) {

	int suma = 0;
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i];
				while (aux) {
					if (aux->info.suprafata > prag) {
						suma += aux->info.nrAngajati;
					}
					aux = aux->next;
				}
			}
		}

	}
	return suma;
}

void stergeMagazin(HT tabela, const char* denCautata) {
	
	int poz = 0;
	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			if (tabela.vector[i]) {
				Nod* aux = tabela.vector[i]; //parcurg cu aux
				Nod* prev = NULL; //parcurgere in paralel, ca sa stiu prev-ul lui aux

				while (aux) {
					if (strcmp(aux->info.nume, denCautata) == 0) {
					
						Nod* nodDeSters = aux; //scriu pe nodul x nodDeSters
						if (prev == NULL) { //inseamna ca sterg primul nod
							tabela.vector[i] = aux->next;
							aux = tabela.vector[i];
						}
						else { //adica sterg din interiorul listei si trebuie sa stabilesc restul de legaturi
							prev->next = aux->next;
							aux = prev->next;
						}
						
						free(nodDeSters->info.nume);
						free(nodDeSters->info.program);
						free(nodDeSters->info.varsteAngajati);
						free(nodDeSters);
					}
					else {
						prev = aux;
						aux = aux->next;
					}
				}

			}
		}
	
	}

}

//conversie
//sa se salveze intr-o lista toate magazinele cu suprafata mai mare de 400 mp
//inserare, afisare si dezalocare de lista simpla (si nod)

Nod* inserareLsSfarsit(Nod* cap, Magazin m) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializareMagazin(m.id, m.nume, m.program, m.suprafata, m.nrAngajati, m.varsteAngajati);
	nou->next = NULL;

	if (cap == NULL) {
		cap = nou;
	}
	else {
		Nod* aux = cap;
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nou;
	}
	return cap;
}

void afisareLista(Nod* cap) {
	Nod* aux = cap;
	while (aux) {
		afisareMagazin(aux->info);
		aux = aux->next;
	}
}

void dezalocareLs(Nod* cap) {
	Nod* aux = cap;
	while (aux) {
		free(aux->info.nume);
		free(aux->info.program);
		free(aux->info.varsteAngajati);

		Nod* temp = aux->next;
		free(aux);
		aux = temp;
	}
}

Nod* salveazaInLista(HT tabela, int prag) {
	//creare noua lista
	Nod* cap = NULL;

	if (tabela.vector) {
		for (int i = 0; i < tabela.dim; i++) {
			Nod* aux = tabela.vector[i];
			while (aux) {
				if (aux->info.suprafata > prag) {

					cap = inserareLsSfarsit(cap, aux->info);
				}
				aux = aux->next;
			}
		}
	}
	return cap;
}


void main() {
	Magazin m;
	//alocare memorie pt tabela
	HT tabela; 
	tabela.dim = 10;
	tabela.vector=(Nod*)malloc(sizeof(Nod*) * tabela.dim);
	for (int i = 0; i < tabela.dim; i++) {
		tabela.vector[i] = NULL;
	}

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("extra1_HashTable.txt", "r");
	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		m.id = atoi(token);

		token = strtok(NULL, separator);
		m.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(m.nume, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		m.program = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(m.program, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		m.suprafata = atof(token);

		token = strtok(NULL, separator);
		m.nrAngajati = atoi(token);

		m.varsteAngajati = (int*)malloc(sizeof(int) * m.nrAngajati);
		for (int i = 0; i < m.nrAngajati; i++) {
		token = strtok(NULL, separator);
		m.varsteAngajati[i] = atoi(token);
		}

		inserare(tabela, m);

		free(m.nume);
		free(m.program);
		free(m.varsteAngajati);
	}
	fclose(f);


	afisare(tabela);

	printf("\n\nNr magazine Flanco: %d", nrMagazine(tabela, "Flanco"));

	printf("\n\nSuma angajati magazine cu supraf >1000 : % d", sumaAngajati(tabela, 1000));

	printf("\n\nStergere:");
	/*stergeMagazin(tabela, "Flanco");
	afisare(tabela);*/

	printf("\n\nLista simpla:");
	Nod* cap = salveazaInLista(tabela, 400);
	afisareLista(cap);



	dezalocare(tabela);
	dezalocareLs(cap);

}


