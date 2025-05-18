#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Dispozitiv {
	unsigned int id;
	char* sistemOperare;
	float pret;
	char* defecte;
	unsigned int zile;

}Dispozitiv;

typedef struct Heap {
	int dim;
	Dispozitiv* vector;
	int nrDispozitive; //optional
}Heap;

Dispozitiv initializareDispozitiv(unsigned int id, char* sistemOperare, float pret, char* defecte, unsigned int zile) {
	Dispozitiv d;
	d.id = id;
	d.sistemOperare = (char*)malloc(sizeof(char) * strlen(sistemOperare)+1);
	strcpy_s(d.sistemOperare, (sizeof(char) * strlen(sistemOperare) + 1), sistemOperare);
	d.pret = pret;
	d.defecte = (char*)malloc(sizeof(char) * strlen(defecte)+1);
	strcpy_s(d.defecte, (sizeof(char) * strlen(defecte) + 1), defecte);
	d.zile = zile;

	return d;
}
void filtrare(Heap h, int index) { //index de unde incep filtrarea
	int indexRad = index; //incep filtrarea cu ce am la parametru
	int indexSt = 2 * index + 1;
	int indexDr = 2 * index + 2;

	//ca sa nu depasim dim vector verificam in if
	if (indexSt < h.dim && h.vector[indexSt].zile > h.vector[indexRad].zile) { //maxheap; la min modifica si for-ul?
		indexRad = indexSt;
	}
	if (indexDr < h.dim && h.vector[indexDr].zile > h.vector[indexRad].zile) {
		indexRad = indexDr;
	}
	if (index != indexRad) {
		Dispozitiv aux = h.vector[index];
		h.vector[index] = h.vector[indexRad];
		h.vector[indexRad] = aux;
		//dupa interschimbare mai filtram pt a vedea daca

		for (int i = (h.dim / 2) - 1; i >= 0; i--) {
			filtrare(h, i);
		}

	}
}

Heap inserareHeap(Heap h, Dispozitiv d) {
	//copie la vector Activiatte* vector
	Dispozitiv* copieVector = (Dispozitiv*)malloc(sizeof(Dispozitiv) * (h.dim + 1));
	for (int i = 0; i < h.dim; i++) {
		copieVector[i] = h.vector[i];
	}
	//copieVector[h.dim] = a; //shallow copy
	copieVector[h.dim] = initializareDispozitiv(d.id, d.sistemOperare, d.pret, d.defecte, d.zile);
	free(h.vector);
	h.dim++;
	h.vector = copieVector;

	for (int i = (h.dim / 2) - 1; i >= 0; i--) { //atentie la  >= !!!!!!!!!!!!!!!!!!!!!
		filtrare(h, i);
	}

	return h;

}


////extragere; mut primul element(prioriatte 0) pe ultimul
Heap extragereHeap(Heap h, Dispozitiv* a) {
	//interschimb(primul cu ultimul) pt a scoate ultimul element cu prioritatea minima
	Dispozitiv aux = h.vector[0];
	h.vector[0] = h.vector[h.dim - 1]; //h.dim - 1 =>ultimul element din vector
	h.vector[h.dim - 1] = aux;

	//scoatem elementul
	//copie la vector Activiatte* vector
	Dispozitiv* copieVector = (Dispozitiv*)malloc(sizeof(Dispozitiv) * (h.dim - 1));
	for (int i = 0; i < h.dim-1; i++) {
		copieVector[i] = h.vector[i];
	}
	//salvare elementul extras
	*a = initializareDispozitiv(h.vector[h.dim - 1].id, h.vector[h.dim - 1].sistemOperare,
		h.vector[h.dim - 1].pret, h.vector[h.dim - 1].defecte, h.vector[h.dim - 1].zile);
	free(h.vector);
	h.dim--;
	h.vector = copieVector;

	for (int i = (h.dim / 2) - 1; i >= 0; i--) { //atentie la  >= !!!!!!!!!!!!!!!!!!!!!
		filtrare(h, i);
	}


	return h;

}

void afisareDispozitiv(Dispozitiv d) {
	printf("\n%u, %s, %.2f, %s, %u ", d.id, d.sistemOperare, d.pret, d.defecte, d.zile);
}

void afisareHeap(Heap h) {

	for (int i = 0; i < h.dim; i++) {
		afisareDispozitiv(h.vector[i]);
	}
}

void dezalocare(Heap h) {
	for (int i = 0; i < h.dim; i++) {
		free(h.vector[i].sistemOperare);
		free(h.vector[i].defecte);
	}
	free(h.vector);
}

int nrDispozitive(Heap h, const char* denCautata) {
	int contor = 0;
	if (h.vector) {
		for (int i = 0; i < h.dim; i++) {
			if (strcmp(h.vector[i].sistemOperare, denCautata) == 0) {
				contor++;
			}

		}
	}
	return contor;
}

//de modificat
Dispozitiv extrageDispozitiv(Heap* h) {
	if (h->vector) {
		Dispozitiv aux = h->vector[0];
		h->vector[0] = h->vector[h->dim - 1]; //h.dim - 1 =>ultimul element din vector
		h->vector[h->dim - 1] = aux;
		h->dim--;
	
		for (int i = (h->dim / 2) - 1; i >= 0; i--) { //atentie la  >= !!!!!!!!!!!!!!!!!!!!!
			filtrare(*h, i);
		}
		return aux; //shallow copy
	}
}




void main() {
	Heap h;
	h.dim = 0;
	h.vector = NULL;

	Dispozitiv d;

	char linieBuffer[100];
	char separator[] = ",\n";
	char* token;

	FILE* f = fopen("fisierHeap.txt", "r");
	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		d.id = atoi(token);

		token = strtok(NULL, separator);
		d.sistemOperare = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(d.sistemOperare, (sizeof(char) * strlen(token) + 1), token);


		token = strtok(NULL, separator);
		d.pret = atof(token);

		token = strtok(NULL, separator);
		d.defecte = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(d.defecte, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		d.zile = atoi(token);

		h = inserareHeap(h, d);

		free(d.sistemOperare);
		free(d.defecte);

	}
	fclose(f);

	afisareHeap(h);

	printf("\nNr elemente din heap: %d", nrDispozitive(h, "IOS"));

	//extragere
	printf("\n\nExtragere-----------------");
	Dispozitiv dispExtras;
	h = extragereHeap(h, &dispExtras);
	afisareHeap(h);

	printf("\nAfisare element extras-----------------");
	afisareDispozitiv(dispExtras);




	dezalocare(h);


	}