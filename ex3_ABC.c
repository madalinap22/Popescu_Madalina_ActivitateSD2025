//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Proiect {
//	int id;
//	char* nume;
//	float buget;
//	int nrAngajati;
//	char status;
//	
//}Proiect;
//
//typedef struct Nod {
//	Proiect info;
//	struct Nod* stang;
//	struct Nod* drept;
//
//}Nod;
//
//Proiect initializareProiect(int id, char* nume, float buget, int nrAngajati, char status) {
//	Proiect p;
//	p.id = id;
//	p.nume = (char*)malloc(sizeof(char) * strlen(nume) + 1);
//	strcpy_s(p.nume, (sizeof(char) * strlen(nume) + 1), nume);
//	p.buget = buget;
//	p.nrAngajati = nrAngajati;
//	p.status = status;
//	
//	return p;
//}
//
//Nod* creareNod(Proiect p, struct Nod* stang, struct Nod* drept) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareProiect(p.id, p.nume, p.buget, p.nrAngajati, p.status);
//	nou->stang = stang;
//	nou->drept = drept;
//	return nou;
//}
//
//Nod* inserareArbore(Nod* rad, Proiect p) {
//	if (rad) {
//		if (p.nrAngajati < rad->info.nrAngajati) {
//			rad->stang = inserareArbore(rad->stang, p);
//			return rad;
//		}
//		 else if (p.nrAngajati > rad->info.nrAngajati) {
//			rad->drept = inserareArbore(rad->drept, p);
//			return rad;
//		}
//		 else {
//			return rad;
//		}
//	}
//	else {
//		return creareNod(p,NULL,NULL);
//	}
//}
//
//void dezalocare(Nod* rad) {
//	if (rad) {
//		Nod* tempS = rad->stang;
//		Nod* tempD = rad->drept;
//
//		free(rad->info.nume);
//		free(rad);
//		dezalocare(tempS);
//		dezalocare(tempD);
//	}
//}
//
//void afiseazaProiect(Proiect p) {
//	printf("\n%d, %s, %.2f, %d, %c ", p.id, p.nume, p.buget, p.nrAngajati, p.status);
//}
//
//void afiseazaPreordine(Nod* rad) {
//	if (rad) {
//		afiseazaProiect(rad->info);
//		afiseazaPreordine(rad->stang);
//		afiseazaPreordine(rad->drept);
//	}
//
//}
//
//void main() {
//	Proiect p;
//	Nod* rad = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex3_ABC.txt", "r");
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		p.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.nume = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.nume, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		p.buget = atof(token);
//
//		token = strtok(NULL, separator);
//		p.nrAngajati = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.status = token[0];
//
//		rad = inserareArbore(rad, p);
//
//		//free(p.nume);
//
//	}
//	fclose(f);
//
//	afiseazaPreordine(rad);
//
//
//	dezalocare(rad);
//
//}