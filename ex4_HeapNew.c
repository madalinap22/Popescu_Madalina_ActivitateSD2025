#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Proiect {
	int id;
	char* beneficiar;
	float buget;
}Proiect;

typedef struct Heap {
	int dim;
	Proiect* vector;
}Heap;

Proiect initializareProiect(int id, char* beneficiar, float buget) {
	Proiect p;
	p.id = id;
	p.beneficiar = (char*)malloc(sizeof(char) * strlen(beneficiar) + 1);
	strcpy_s(p.beneficiar, (sizeof(char) * strlen(beneficiar) + 1), beneficiar);
	p.buget = buget;
	return p;
}

void filtrare(Heap h, int index) {
	int indexRad = index;
	int indexSt = 2 * index + 1;
	int indexDr = 2 * index + 2;

	if (indexSt < h.dim && h.vector[indexSt].id > h.vector[index].id) {
		indexRad = indexSt;
	}
	if (indexDr < h.dim && h.vector[indexDr].id > h.vector[index].id) {
		indexRad = indexDr;
	}
	if (index != indexRad) {
		Proiect aux = h.vector[index];
		h.vector[index] = h.vector[indexRad];
		h.vector[indexRad] = aux;

		for (int i = (h.dim / 2) - 1; i >= 0; i--) {
			filtrare(h, i);
		}
	}
	
}

Heap inserareHeap(Heap h, Proiect p) {
	Proiect* copieVector = (Proiect*)malloc(sizeof(Proiect) * (h.dim + 1));
	for (int i = 0; i < h.dim; i++) {
		copieVector[i] = h.vector[i];
	}
	copieVector[h.dim] = initializareProiect(p.id, p.beneficiar, p.buget);
	free(h.vector);
	h.dim++;
	h.vector = copieVector;

	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
		filtrare(h, i);
	}
	return h;
}

Heap extragereHeap(Heap h, Proiect* p) {
	Proiect aux = h.vector[0];
	h.vector[0] = h.vector[h.dim - 1];
	h.vector[h.dim - 1] = aux;

	Proiect* copieVector = (Proiect*)malloc(sizeof(Proiect) * (h.dim - 1));
	for (int i = 0; i < h.dim - 1; i++) {
		copieVector[i] = h.vector[i];
	}

	*p = initializareProiect(h.vector[h.dim - 1].id,
		h.vector[h.dim - 1].beneficiar, h.vector[h.dim - 1].buget);

	free(h.vector);
	h.dim--;
	h.vector = copieVector;

	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
		filtrare(h, i);
	}
	return h;

}

void afisareProiect(Proiect p) {
	printf("\n%d, %s, %.2f", p.id, p.beneficiar, p.buget);
}

void afisareHeap(Heap h) {
	for (int i = 0; i < h.dim; i++) {
		afisareProiect(h.vector[i]);
	}
}

void dezalocare(Heap h) {
	if (h.vector) {
		for (int i = 0; i < h.dim; i++) {
			free(h.vector[i].beneficiar);
		}
		free(h.vector);
	}
}
float medie(Heap h, const char* denCautata) {
	int suma = 0;
	int contor = 0;
	if (h.vector) {
		for (int i = 0; i < h.dim; i++) {
			if (strcmp(h.vector[i].beneficiar, denCautata) == 0) {
				suma += h.vector[i].buget;
				contor++;
			}

		}
	}
	return (float)suma / contor;
}
Proiect* cautaDupaIdDeepCopy(Heap h, int idCautat) {
	if (h.vector) {
		for (int i = 0; i < h.dim; i++) {
			if (h.vector[i].id == idCautat) {
				Proiect* copie = (Proiect*)malloc(sizeof(Proiect));
				*copie = initializareProiect(h.vector[i].id, h.vector[i].beneficiar, h.vector[i].buget);
				return copie;
			}
		}
	}
	//return NULL;
}

void main() {
	Proiect p;
	Heap h;
	h.dim = 0;
	h.vector = NULL;

	char linieBuffer[100];
	char separator[3] = ",";
	char* token = NULL;

	FILE* f = fopen("Proiecte.txt", "r");

	while (fgets(linieBuffer, 100, f)) {
		token = strtok(linieBuffer, separator);
		p.id = atoi(token);

		token = strtok(NULL, separator);
		p.beneficiar = (char*)malloc(sizeof(char) * strlen(token) + 1);
		strcpy_s(p.beneficiar, (sizeof(char) * strlen(token) + 1), token);

		token = strtok(NULL, separator);
		p.buget = atof(token);

		h = inserareHeap(h, p);

		free(p.beneficiar);
	}
	fclose(f);

	afisareHeap(h);

	printf("\n\nMedie: %.2f", medie(h, "DRM"));

	printf("\n\nReturnare cu deep copy: ");
	Proiect* p1 = cautaDupaIdDeepCopy(h, 8);
	if (p1) {
		afisareProiect(*p1);
		free(p1->beneficiar);
		free(p1);
	}



	printf("\n\nExtragere din heap -------------");
	Proiect pExtras;
	h = extragereHeap(h, &pExtras);
	afisareHeap(h);


	dezalocare(h);
}