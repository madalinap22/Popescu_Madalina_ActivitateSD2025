#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Magazin {
	int id;
	char* nume;
	float suprafata;
}Magazin;

typedef struct Nod {
	Magazin info;
	struct Nod* stang;
	struct Nod* drept;
}Nod;

Magazin initializareMagazin(int id, char* nume, float suprafata) {
	Magazin m;
	m.id = id;
	m.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
	strcpy_s(m.nume, (sizeof(char) * strlen(nume) + 1), nume);
	m.suprafata = suprafata;
	return m;
}

Nod* creareNod(Magazin m, struct Nod* stang, struct Nod* drept) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = initializareMagazin(m.id, m.nume, m.suprafata);
	nou->stang = stang;
	nou->drept = drept;

	return nou;
}
//inserare - cheia este id-ul
//intotdeauna ne intrebam daca avem if(radacina); fara if nu avem recursivitate
Nod* inserareArbore(Nod* rad, Magazin m) {
	if (rad) {
		if (m.id < rad->info.id) {
			rad->stang = inserareArbore(rad->stang, m);
			return rad;
		}
		else if (m.id > rad->info.id) {
			rad->drept = inserareArbore(rad->drept, m);
			return rad;
		}
		else {
			return rad;
		}
	}
	else {
		return creareNod(m, NULL, NULL);
	}
	
	
}

void afisarePreordine(Nod* rad) {
	if (rad) {
		printf("\n%d, %s, %.2f", rad->info.id, rad->info.nume, rad->info.suprafata);
		afisarePreordine(rad->stang);
		afisarePreordine(rad->drept);
	}
}
void afisarePostordine(Nod* rad) {
	if (rad) {
		afisarePostordine(rad->stang);
		afisarePostordine(rad->drept);
		printf("\n%d, %s, %.2f", rad->info.id, rad->info.nume, rad->info.suprafata);
	}
}
void afisareInordine(Nod* rad) {
	if (rad) {
		afisareInordine(rad->stang);
		printf("\n%d, %s, %.2f", rad->info.id, rad->info.nume, rad->info.suprafata);
		afisareInordine(rad->drept);
	}
}

void dezalocare(Nod* rad) {
	if (rad) {
		Nod* tempS = rad->stang;
		Nod* tempD = rad->drept;

		free(rad->info.nume);
		free(rad);
		dezalocare(tempS);
		dezalocare(tempD);
	}
}

void main() {
	Magazin m;
	Nod* rad = NULL;

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("ex1_ABC.txt", "r");
	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		m.id = atoi(token);

		token = strtok(NULL, separator);
		m.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(m.nume, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		m.suprafata = atof(token);

		rad = inserareArbore(rad, m);
		//free(m.nume);
	}
	fclose(f);

	afisarePreordine(rad);
	//afisarePostordine(rad);
	//afisareInordine(rad);



	dezalocare(rad);
}