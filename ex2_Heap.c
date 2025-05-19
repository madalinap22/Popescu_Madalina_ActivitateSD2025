#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


typedef struct Cladire {
	int id;
	char* status;
	float suprafata;
	char riscSeismic;
}Cladire;

typedef struct Heap {
	int dim;
	Cladire* vector;
}Heap;

Cladire initializareCladire(int id, char* status, float suprafata, char riscSeismic) {
	Cladire c;
	c.id = id;
	c.status = (char*)malloc(sizeof(char) * strlen(status) + 1);
	strcpy_s(c.status, (sizeof(char) * strlen(status) + 1), status);
	c.suprafata = suprafata;
	c.riscSeismic = riscSeismic;
	return c;
}

void filtrare(Heap h, int index) {
	int indexRad = index;
	int indexSt = 2 * index + 1;
	int indexDr = 2 * index + 2;

	if (indexSt < h.dim && h.vector[indexSt].id > h.vector[indexRad].id) {
		indexRad = indexSt;
	}
	if (indexDr < h.dim && h.vector[indexDr].id > h.vector[indexRad].id) {
		indexRad = indexDr;
	}
	if (index != indexRad) {
		Cladire aux = h.vector[index];
		h.vector[index] = h.vector[indexRad];
		h.vector[indexRad] = aux;
	}

	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
		filtrare(h, i);
	}
}
