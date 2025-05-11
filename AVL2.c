//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct rezervare rezervare;
//typedef struct nod nod;
//
//struct rezervare {
//	unsigned int id;
//	char* hotel;
//	char* client;
//	int nrCamere;
//	float suma;
//};
//
//struct nod {
//	rezervare info;
//	nod* st;
//	nod* dr;
//
//	int grad;//pt AVL
//};
//
//rezervare creareRezervare(unsigned int id, const char* hotel, const char* client, int nrCamere, float suma) {
//	rezervare r;
//	r.id = id;
//	r.hotel = (char*)malloc(sizeof(char) * (strlen(hotel) + 1));
//	strcpy(r.hotel, hotel);
//	r.client = (char*)malloc(sizeof(char) * (strlen(client) + 1));
//	strcpy(r.client, client);
//	r.nrCamere = nrCamere;
//	r.suma = suma;
//
//	return r;
//
//}
//
//
//
//nod* creaNod(rezervare r, nod* st, nod* dr) {
//	nod* nou = (nod*)malloc(sizeof(nod));
//	nou->info = creareRezervare(r.id, r.hotel, r.client, r.nrCamere, r.suma);
//	nou->st = st;
//	nou->dr = dr;
//	//sa ne ocupam si de grad
//}
//
//
////ccheia de inserare sa fie id
//nod* inserareArbore(nod* rad, rezervare r) {
//	if (rad) {//diferita de null
//		if (r.id < rad->info.id) {
//			rad->st = inserareArbore(rad->st, r);
//			return rad;
//		}
//		else if (r.id > rad->info.id) {
//			rad->dr = inserareArbore(rad->dr, r);
//			return rad;
//		}
//		else {
//			return rad;
//		}
//	}
//	return creaNod(r, NULL, NULL);
//}
//
////RSD
//void afisarePreordine(nod* rad) {
//	if (rad) {
//		printf("Grad: %d \n%u, %s, %s, %d, %.2f \n", rad->grad, rad->info.id, rad->info.hotel, rad->info.client, rad->info.nrCamere, rad->info.suma);
//		afisarePreordine(rad->st);
//		afisarePreordine(rad->dr);
//	}
//}
//
//int maxim(int a, int b) {
//
//	return a > b ? a : b;
//}
//
//int nrNiveluiri(nod* rad) {
//	if (rad) {
//		return 1 + maxim(nrNiveluiri(rad->st), nrNiveluiri(rad->dr));
//	}
//	else {
//		return 0;
//	}
//}
////nu putem calcula gradul fara functia de nrNiveluri(inaltime)//optional
//void calculGradEchArb(nod* rad) {
//	if (rad) {
//		rad->grad = (nrNiveluiri(rad->st) - nrNiveluiri(rad->dr));
//		calculGradEchArb(rad->st);
//		calculGradEchArb(rad->dr);
//
//	}
//}
// 
// 
////calcul grad cu return/////////////////////////////////////////////////////////////
//int calculGrad(nod* rad) {
//	if (rad) {
//		return (nrNiveluiri(rad->st) - nrNiveluiri(rad->dr));
//	}
//	else {
//		return 0;
//	}
//
//}
//
////rotire st
//nod* rotireStanga(nod* rad) {
//	nod* x = rad->dr;
//	rad->dr = x->st;
//	x->st = rad;
//
//	return x;
//	//normal ar fi sa recalculam gradul de echilibru
//
//}
//
//nod* rotireDreapta(nod* rad) {
//	nod* x = rad->st;
//	rad->st = x->dr;
//	x->dr = rad;
//	return x;
//}
////optional
////nod* rotireStangaDreapta(nod* rad) {
////	rad->st = rotireStanga(rad->st);
////	return rotireDreapta(rad);
////}
////
////nod* rotireDreaptaStanga(nod* rad) {
////	rad->dr = rotireDreapta(rad->dr);
////	return rotireStanga(rad);
////}
//
//nod* InserareNodAVL( nod* rad, rezervare r)
//{
//	if (rad) //!=NULL
//	{
//		if (r.id >rad->info.id)
//		{
//			rad->dr = InserareNodAVL(rad->dr, r);
//		}
//		else if(r.id < rad->info.id)
//		{
//			rad->st = InserareNodAVL(rad->st, r);
//		}
//		else {
//			return rad;
//		}
//		//facem echilibrare
//		int grad = calculGrad(rad);
//		if (grad == 2)
//		{
//			if (calculGrad(rad->st) == -1) {
//				rad->st = rotireStanga(rad->st);
//			}
//			rad = rotireDreapta(rad);
//		}
//		if (grad == -2) {
//			if (calculGrad(rad->dr) == 1) {
//				rad->dr = rotireDreapta(rad->dr);
//			}
//			rad = rotireStanga(rad);
//
//		}
//	}
//	else
//	{
//		return creaNod(r,NULL,NULL);
//	}
//	return rad;
//}
//
//void main() {
//	//structurile
//	rezervare r;
//	nod* rad = NULL;
//
//
//	//auxiliare pt citire
//	char liniebuffer[128];
//	char sep[] = ",";//\n
//	char* token;
//
//	FILE* f = fopen("avl_rezervari.txt", "r");
//	while (fgets(liniebuffer, 128, f)) {
//		token = strtok(liniebuffer, sep);
//		r.id = atoi(token);
//
//		token = strtok(NULL, sep);
//		r.hotel = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy(r.hotel, token);
//
//		token = strtok(NULL, sep);
//		r.client = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//		strcpy(r.client, token);
//
//		token = strtok(NULL, sep);
//		r.nrCamere = atoi(token);
//
//		token = strtok(NULL, sep);
//		r.suma = atof(token);
//
//		//rad = inserareArbore(rad, r);
//		rad = InserareNodAVL(rad, r);
//
//		free(r.hotel);
//		free(r.client);
//
//	}
//	//calculGrad(rad);
//	//printf("Afisare arbore dezechilibrat:\n");
//	//afisarePreordine(rad);
//	//rad = rotireStanga(rad);
//
//	calculGradEchArb(rad);
//	printf("Afisare arbore dupa echilibrare:\n\n");
//	afisarePreordine(rad);
//
//}
//
////5, Central, Andrei, 5, 1447.88
////12, Central, Amalia, 1, 144.88
////13, Central, Cristian, 1, 144.88
////14, Central, Andra, 1, 144.88
////12,Piatra Mare,Adam Anca,2,1299.99