//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
////Cu transformare in AVL
////to do - medie, min, returnare nod? 
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
//	int grad; //pt AVL
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
////AVL
////inatltime, max, nr niveluri
////f de calcul grad - salvam calculul
////calcul grad-> S-D
////modificare afisare ca sa vedem gradul
////f care echilibreaza arborele
////MAX
//int maxim(int a, int b) {
//	if (a > b) {
//		return a;
//	}
//	else {
//		return b;
//	}
//}
//
//int inaltimeArbore(Nod* rad) { //inaltime arbore = cel mai lung drum de la nodul radacina pana la frunza
//	if (rad) {
//		return 1 + maxim(inaltimeArbore(rad->stang), inaltimeArbore(rad->drept));
//	}
//	else {////////////////////////////////////////neaparat, va numara in plus
//		return 0;
//	}
//}
////calcul grad-> S-D
//void calculGrad(Nod* rad) {
//	if (rad) {
//		rad->grad = inaltimeArbore(rad->stang) - inaltimeArbore(rad->drept);
//		calculGrad(rad->stang);
//		calculGrad(rad->drept);
//	}
//}
//
//void afisarePreordine2(Nod* rad) {
//	if (rad) {
//		afisareCladire(rad->info);
//		printf("GRAD: %d", rad->grad);
//		afisarePreordine2(rad->stang);
//		afisarePreordine2(rad->drept);
//	}
//}
////rotiri pt echilibrare
////rotire stanga
//Nod* rotireStanga(Nod* rad) {
//	Nod* x = rad->drept;
//	rad->drept = x->stang;
//	x->stang = rad;
//
//	return x;
//
//}
//
////rotire dreapta
//Nod* rotireDreapta(Nod* rad) {
//	Nod* x = rad->stang;
//	rad->stang = x->drept;
//	x->drept = rad;
//
//	return x;
//}
//
////f de reechilibrare
//Nod* reechilibrare(Nod* rad) {
//	if (rad) {
//		//rad->stang = reechilibrare(rad->stang);
//		//rad->drept = reechilibrare(rad->drept);
//		if (rad->grad > 1 && rad->stang->grad >= 0) { //rad->grad> 1 = dez pe stanga
//			return rotireDreapta(rad); 
//		}
//		if (rad->grad  > 1 && rad->stang->grad < 0) {//dezechilibru dublu, zig-zag
//			rad->stang = rotireStanga(rad->stang);
//			return rotireDreapta(rad);
//		}
//		if (rad->grad < -1 && rad->drept->grad <=0) {//rotatie la stanga
//			return rotireStanga(rad);
//		}
//		if (rad->grad < -1 && rad->drept->grad > 0) {
//			rad->drept = rotireDreapta(rad->drept);
//			return rotireStanga(rad);
//		}
//
//	}
//	//return rad;
//}
//
////suma suprafete
//float suprafataTotala(Nod* rad) {
//	float suma = 0;
//	int contor = 0;
//	if (rad) { //daca exista rad continui, dac anu ma opresc
//		suma += rad->info.suprafata;
//		suma += suprafataTotala(rad->stang);
//		suma += suprafataTotala(rad->drept);
//	
//	}
//	return suma;
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
//
//
//	calculGrad(rad);
//	afisarePreordine2(rad);
//	//afisarePostordine(rad);
//	//afisareInordine(rad);
//
//	printf("\n\nAfisare dupa reechilibrare: ");
//	rad = reechilibrare(rad);
//	calculGrad(rad);
//	afisarePreordine2(rad);
//
//	printf("\n\nSuma: %.2f", suprafataTotala(rad));
//
//
//
//
//	dezalocare(rad);
//}