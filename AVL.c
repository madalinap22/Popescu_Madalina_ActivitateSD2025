//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//
////AVL - are grad de echilibru si se baga in nod ca int grad
////echilibrat - nr de niveluri pe st - nr niveluri dr
//
//typedef struct Cazare {
//	unsigned int id;
//	char* hotel;
//	char* client;
//	float suma;
//	int nrCamere; //unsigned char
//}Cazare;
//
//typedef struct Nod {
//	Cazare info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//	int grad;
//}Nod;
//
//Cazare initializareCazare(unsigned int id, const char* hotel, const char* client, float suma, int nrCamere) {
//	Cazare c;
//	c.id = id;
//	c.hotel = (char*)malloc(sizeof(char) * (strlen(hotel) + 1));
//	strcpy_s(c.hotel, sizeof(char) * (strlen(hotel) + 1), hotel);
//	c.client = (char*)malloc(sizeof(char) * (strlen(client) + 1));
//	strcpy_s(c.client, sizeof(char) * (strlen(client) + 1), client);
//	c.suma = suma;
//	c.nrCamere = nrCamere;
//	return c;
//}
//
//Nod* creareNod(Cazare c, Nod* stanga, Nod* dreapta) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->stanga = stanga;
//	nou->dreapta = dreapta;
//	nou->info = initializareCazare(c.id, c.hotel, c.client, c.suma, c.nrCamere);
//	return nou;
//	//pot sa fac si gradul
//}
//
////informatia si unde inserez//cheia de inserare = id-ul
//Nod* inserareArbore(Nod* radacina, Cazare c) {
//	//if radacina? intotdeauna ne intrebam daca avem radacina; fara if radacina nua vem recursivitate
//	if (radacina) { //!=NULL
//		if (c.id < radacina->info.id) {
//			radacina->stanga = inserareArbore(radacina->stanga, c);
//			return radacina;
//		}
//		else if (c.id > radacina->info.id) {
//			radacina->dreapta = inserareArbore(radacina->dreapta, c);
//			return radacina;
//		}
//		else {
//			return radacina;
//		}
//	}
//	return creareNod(c, NULL, NULL);
//}
//
////afisari de obicei de la stanga la dreapta
////RSD
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		printf("Grad: %d \n%u, %s, %s, %.2f, %d \n", radacina->grad, radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma, radacina->info.nrCamere);
//		afisarePreordine(radacina->stanga);
//		afisarePreordine(radacina->dreapta);
//	}
//}
////
////void afisarePreordine(Nod* radacina) {
////
////	if (radacina) {
////
////		printf("%u %s %s %.2f \n", radacina->info.id, radacina->info.hotel,
////			radacina->info.client, radacina->info.suma);
////		afisarePreordine(radacina->stanga);
////		afisarePreordine(radacina->dreapta);
////
////	}
////
////}
//
////SDR
//void afisarePostordine(Nod* radacina) {
//	if (radacina) {
//		afisarePostordine(radacina->stanga);
//		afisarePostordine(radacina->dreapta);
//		printf("%u, %s, %s, %.2f, %d \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma, radacina->info.nrCamere);
//	}
//}
//
////SRD
//void afisareInordine(Nod* radacina) {
//	if (radacina) {
//		afisareInordine(radacina->stanga);
//		printf("%u, %s, %s, %.2f, %d \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma, radacina->info.nrCamere);
//		afisareInordine(radacina->dreapta);
//	}
//}
//int maxim(int a, int b) {
//	if (a > b) {
//		return a;
//	}
//	else {
//		return b;
//	}
//
//	//return a > b ? a : b;
//}
////nr niveluri - necesara pt calcul nr grad
//int niveluri(Nod* radacina) {
//	if (radacina) {
//		return 1 + maxim(niveluri(radacina->stanga), niveluri(radacina->dreapta)); //1 de la radacina + maxim ce am pe stanga si ce am pe dreapta
//	}
//	else {
//		return 0;
//	}
//}
//
////functie de calculare a gradului; (neaparat functie de nrNiveluri (inaltime))
//void calculGrad(Nod* rad) {
//	if (rad) {
//		rad->grad = (niveluri(rad->stanga) - niveluri(rad->dreapta));
//		calculGrad(rad->stanga);
//		calculGrad(rad->dreapta);
//	} //fiecare nod sa stie diferenta
//}//se salveaza in campul de grad
//
////rotiri
//Nod* rotireStanga(Nod* rad) {
//	Nod* x = rad->dreapta;
//	Nod* y = x->dreapta;
//
//	
//	x->stanga = rad; 
//	rad->dreapta = NULL;
//	
//	return x; //devine radacina
//}
//
//Nod* rotireDreapta(Nod* rad) {
//	Nod* x = rad->stanga;
//	Nod* y = x->stanga;
//
//	x->dreapta = rad;
//	rad->stanga = y;
//	return x; //return radacina
//}
//
//Nod* rotireStangaDreapta(Nod* rad){
//	rad->stanga = rotireStanga(rad->stanga);
//	return rotireDreapta(rad);
//
//}
//
//Nod* rotireDreaptaStanga(Nod* rad) {
//	rad->dreapta = rotireDreapta(rad->dreapta);
//	return rotireStanga(rad);
//
//}
//void main() {
//	Cazare c;
//	Nod* radacina = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ","; //\n
//	char* token;
//
//	FILE* f = fopen("fisierABC.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		c.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.hotel = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy_s(c.hotel, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.client = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy_s(c.client, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.suma = atof(token);
//
//		token = strtok(NULL, separator);
//		c.nrCamere = atoi(token);
//
//		radacina = inserareArbore(radacina, c);
//
//		free(c.hotel);
//		free(c.client);
//
//	}
//	fclose(f);
//
//	calculGrad(radacina);
//	printf("Afisare initiala (arbore dezechilibrat):\n");
//	afisarePreordine(radacina);
//
//	printf("\nAfisare dupa rotire stanga (echilibrat):\n");
//	radacina = rotireStanga(radacina);
//	calculGrad(radacina);
//	afisarePreordine(radacina);
//
//
//
//}
