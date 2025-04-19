//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct Rezervare {
//	unsigned int id;
//	char* hotel;
//	char* client;
//	float suma;
//}Rezervare;
//
//typedef struct Nod {
//	Rezervare info;
//	struct Nod* stanga;
//	struct Nod* dreapta;
//}Nod;
//
//Rezervare initializareRezervare(unsigned int id, const char* hotel, const char* client, float suma) {
//	Rezervare r;
//	r.id = id;
//	r.hotel = (char*)malloc(sizeof(char) * (strlen(hotel) + 1));
//	strcpy_s(r.hotel, sizeof(char) * (strlen(hotel) + 1), hotel);
//	r.client = (char*)malloc(sizeof(char) * (strlen(client) + 1));
//	strcpy_s(r.client, sizeof(char) * (strlen(client) + 1), client);
//	r.suma = suma;
//	return r;
//}
//
//Nod* creareNod(Rezervare r, Nod* stanga, Nod* dreapta) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->stanga = stanga;
//	nou->dreapta = dreapta;
//	nou->info = initializareRezervare(r.id, r.hotel, r.client, r.suma);
//	return nou;
//}
//
////informatia si unde inserez//cheia de inserare = id-ul
//Nod* inserareArbore(Nod* radacina, Rezervare r) {
//	//if radacina? intotdeauna ne intrebam daca avem radacina; fara if radacina nua vem recursivitate
//	if (radacina) { //!=NULL
//		if (r.id < radacina->info.id) {
//			radacina->stanga = inserareArbore(radacina->stanga, r);
//			return radacina;
//		}
//		else if (r.id > radacina->info.id) {
//			radacina->dreapta = inserareArbore(radacina->dreapta, r);
//			return radacina;
//		}
//		else {
//			return radacina;
//		}
//	}
//	return creareNod(r, NULL, NULL);
//}
//
////afisari de obicei de la stanga la dreapta
////RSD
//void afisarePreordine(Nod* radacina) {
//	if (radacina) {
//		printf("%u, %s, %s, %.2f \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma);
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
//		printf("%u, %s, %s, %.2f \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma);
//	}
//}
//
////SRD
//void afisareInordine(Nod* radacina) {
//	if (radacina) {
//		afisareInordine(radacina->stanga);
//		printf("%u, %s, %s, %.2f \n", radacina->info.id, radacina->info.hotel, radacina->info.client, radacina->info.suma);
//		afisareInordine(radacina->dreapta);
//	}
//}
//
//void dezalocare(Nod* radacina) {
//	if (radacina) {
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
//
//
//void main() {
//	Rezervare r;
//	Nod* radacina = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ","; //\n
//	char* token;
//
//	FILE* f = fopen("fisierABC.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		r.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		r.hotel = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy_s(r.hotel, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		r.client = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy_s(r.client, sizeof(char) * (strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		r.suma = atof(token);
//
//		radacina = inserareArbore(radacina, r);
//
//		free(r.hotel);
//		free(r.client);
//
//	}
//	fclose(f);
//
//	afisarePreordine(radacina);
//
//	int nr = niveluri(radacina);
//	printf("\nNr niveluri: %d ", nr);
//
//}
