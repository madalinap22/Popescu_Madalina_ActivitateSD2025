//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
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
//		printf("%u, %s, %s, %.2f, %d \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma, radacina->info.nrCamere);
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
//
//void dezalocare(Nod* radacina) {
//	if (radacina){
//		Nod* tempSt = radacina->stanga;
//		Nod* tempDr = radacina->dreapta;
//
//		free(radacina->info.hotel);
//		free(radacina->info.client);
//		free(radacina);
//		dezalocare(tempSt);
//		dezalocare(tempDr);
//	}
//}
////maxim
//int maxim(int a, int b) {
//	//if (a > b) {
//	//	return a;
//	//}
//	//else {
//	//	return b;
//	//}
//
//	return a > b ? a : b;
//}
////nr niveluri
//int niveluri(Nod* radacina) {
//	if (radacina) {
//		return 1 + maxim(niveluri(radacina->stanga), niveluri(radacina->dreapta));
//	}
//	else {
//		return 0;
//	}
//}
////numarare cazari din arbore
//void contorizareCazari(Nod* rad, int* contor) { //int* pt ca il schimb; nu il iau ca int contro =0 in functie pt ca ar fi tot timpul maxim 1
//	if (rad) {
//		(*contor)++;
//		contorizareCazari(rad->stanga, contor);
//		contorizareCazari(rad->dreapta, contor);
//	}
//}
////nodurile frunza - nr cazari din frunze (rad->stanga si rad-.dreapta == null)
//void nrCamFrunze(Nod* rad, int* suma) {
//	if (rad) {
//		if (rad->stanga == NULL && rad->dreapta == NULL) {
//			(*suma) += rad->info.nrCamere;
//		}
//		nrCamFrunze(rad->stanga, suma);
//		nrCamFrunze(rad->dreapta, suma);
//	}
//}
//
//
//void main(){
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
//	afisarePreordine(radacina);
//
//	int nr = niveluri(radacina);
//	printf("\nNr niveluri: %d ", nr);
//
//	int contor = 0;
//	contorizareCazari(radacina, &contor);
//	printf("\nNr cazari: %d ", contor);
//
//	int suma = 0;
//	nrCamFrunze(radacina, &suma);
//	printf("\nNr camere noduri frunze: %d ", suma);
//
//
//
//}
