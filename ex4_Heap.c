//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//typedef struct Proiect {
//	int id;
//	char* beneficiar;
//	float buget;
//}Proiect;
//
//typedef struct Heap {
//	int dim;
//	Proiect* vector;
//}Heap;
//
//Proiect initializareProiect(int id, char* beneficiar, float buget) {
//	Proiect p;
//	p.id = id;
//	p.beneficiar = (char*)malloc(sizeof(char) * strlen(beneficiar) + 1);
//	strcpy_s(p.beneficiar, (sizeof(char) * strlen(beneficiar) + 1), beneficiar);
//	p.buget = buget;
//	return p;
//}
//
//void filtrare(Heap h, int index) {
//	int indexRad = index;
//	int indexSt = 2 * index + 1;
//	int indexDr = 2 * index + 2;
//
//	if (indexSt < h.dim && h.vector[indexSt].id > h.vector[index].id) {
//		indexRad = indexSt;
//	}
//	if (indexDr < h.dim && h.vector[indexDr].id > h.vector[index].id) {
//		indexRad = indexDr;
//	}
//	if (index != indexRad) {
//		Proiect aux = h.vector[index];
//		h.vector[index] = h.vector[indexRad];
//		h.vector[indexRad] = aux;
//	}
//	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//		filtrare(h, i);
//	}
//}
//
//void inserareHeap(Heap h, Proiect p) {
//	Proiect* copieVector = (Proiect*)malloc(sizeof(Proiect) * (h.dim + 1));
//	for (int i = 0; i < h.dim; i++) {
//		copieVector[i] = h.vector[i];
//	}
//	copieVector[h.dim] = initializareProiect(p.id, p.beneficiar, p.buget);
//	free(h.vector);
//	h.dim++;
//	h.vector = copieVector;
//
//	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//		filtrare(h, i);
//	}
//	return h;
//}
//void afisareProiect(Proiect p) {
//	printf("\n%d, %s, %.2f", p.id, p.beneficiar, p.buget);
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareProiect(h.vector[i]);
//	}
//}
//
//void main() {
//	Proiect p;
//	Heap h;
//	h.dim = 0;
//	h.vector = NULL;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("Proiecte.txt", "r");
//
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		p.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.beneficiar = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.beneficiar, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		p.buget = atof(token);
//
//		inserareHeap(h,p);
//
//		free(p.beneficiar);
//	}
//	fclose(f);
//
//	afisareHeap(h);
//
//
//
//
//
//
//}