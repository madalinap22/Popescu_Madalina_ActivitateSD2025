//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//
////to do - medie, min, returnare nod? + transformare in AVL
//
//typedef struct Cladire {
//	int id;
//	char* status;
//	float suprafata;
//	char riscSeismic;
//}Cladire;
//
//typedef struct Nod {
//	Cladire info;
//	struct Nod* stang;
//	struct Nod* drept;
//}Nod;
//
//Cladire initializareCladire(int id, char* status, float suprafata, char riscSeismic) {
//	Cladire c;
//	c.id = id;
//	c.status = (char*)malloc(sizeof(char) * strlen(status) + 1);
//	strcpy_s(c.status, (sizeof(char) * strlen(status) + 1), status);
//	c.suprafata = suprafata;
//	c.riscSeismic = riscSeismic;
//	return c;
//}
//
//Nod* creareNod(Cladire c, struct Nod* stang, struct Nod* drept) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareCladire(c.id, c.status, c.suprafata, c.riscSeismic);
//	nou->stang = stang;
//	nou->drept = drept;
//
//	return nou;
//}
//
//Nod* inserareArbore(Nod* rad, Cladire c) {
//	if (rad) {
//		if (c.id < rad->info.id) {
//			rad->stang = inserareArbore(rad->stang, c);
//			return rad;
//		}
//		else if (c.id > rad->info.id) {
//			rad->drept = inserareArbore(rad->drept, c);
//			return rad;
//		}
//		else {
//			return rad;
//		}
//	}
//	else {
//		return creareNod(c, NULL, NULL);
//	}
//}
//
//void afisareCladire(Cladire c) {
//	printf("\n%d, %s, %.2f, %c ", c.id, c.status, c.suprafata, c.riscSeismic);
//}
//
//void afisarePreordine(Nod* rad) {
//	if (rad) {
//		afisareCladire(rad->info);
//		afisarePreordine(rad->stang);
//		afisarePreordine(rad->drept);
//	}
//}
//
//void afisarePostordine(Nod* rad) {
//	if (rad) {
//		afisarePostordine(rad->stang);
//		afisarePostordine(rad->drept);
//		afisareCladire(rad->info);
//	}
//}
//void afisareInordine(Nod* rad) {
//	if (rad) {
//		afisareInordine(rad->stang);
//		afisareCladire(rad->info);
//		afisareInordine(rad->drept);	
//	}
//}
//
//void dezalocare(Nod* rad) {
//	if (rad) {
//		Nod* tempS = rad->stang;
//		Nod* tempD = rad->drept;
//
//		free(rad->info.status);
//		free(rad);
//		dezalocare(tempS);
//		dezalocare(tempD);
//	}
//}
//
//
//
//void main() {
//	Cladire c;
//	Nod* rad = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex2_ABC.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		c.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.status = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.status, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.suprafata = atof(token);
//
//		token = strtok(NULL, separator);
//		c.riscSeismic = token[0];////////////////////////////////////
//
//		rad = inserareArbore(rad, c);
//
//		free(c.status);
//
//	}
//	fclose(f);
//
//	afisarePreordine(rad);
//	//afisarePostordine(rad);
//	//afisareInordine(rad);
//
//
//
//
//
//
//
//	dezalocare(rad);
//}