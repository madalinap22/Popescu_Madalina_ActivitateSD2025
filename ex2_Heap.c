//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//
//typedef struct Cladire {
//	int id;
//	char* status;
//	float suprafata;
//	char riscSeismic;
//}Cladire;
//
//typedef struct Heap {
//	int dim;
//	Cladire* vector;
//}Heap;
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
//		Cladire aux = h.vector[index];
//		h.vector[index] = h.vector[indexRad];
//		h.vector[indexRad] = aux;
//
//		for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//			filtrare(h, i);
//		}
//	}
//
//	
//}
//
//Heap inserareHeap(Heap h, Cladire c) {
//	Cladire* copieVector = (Cladire*)malloc(sizeof(Cladire) * (h.dim + 1));
//	for (int i = 0; i < h.dim; i++) {
//		copieVector[i] = h.vector[i];
//	}
//
//	copieVector[h.dim] = initializareCladire(c.id, c.status, c.suprafata, c.riscSeismic);
//	free(h.vector);
//	h.dim++;
//	h.vector = copieVector;
//
//	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//		filtrare(h, i);
//	}
//	return h;
//}
//
//void afisareCladire(Cladire c) {
//	printf("\n%d, %s, %.2f, %c ", c.id, c.status, c.suprafata, c.riscSeismic);
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareCladire(h.vector[i]);
//	}
//}
//
//
//
//
//
//void main() {
//	Heap h;
//	h.dim = 0;
//	h.vector = NULL;
//	Cladire c;
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
//		h = inserareHeap(h, c);
//
//		free(c.status);
//
//	}
//	fclose(f);
//
//	afisareHeap(h);
//
//
//
//}
