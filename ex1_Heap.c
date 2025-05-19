//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
////to do returnare cu deep copy + conditie
//
//typedef struct Magazin {
//	unsigned int id;
//	char* denumire;
//	float suprafata;
//	int nrAngajati;
//}Magazin;
//
//typedef struct Heap {
//	int dim;
//	Magazin* vector;
//}Heap;
//
//Magazin initializareMagazin(unsigned int id, char* denumire, float suprafata, int nrAngajati) {
//	Magazin m;
//	m.id = id;
//	m.denumire = (char*)malloc(sizeof(char) * strlen(denumire) + 1);
//	strcpy_s(m.denumire, (sizeof(char) * strlen(denumire) + 1), denumire);
//	m.suprafata = suprafata;
//	m.nrAngajati = nrAngajati;
//	return m;
//}
//
//void filtrare(Heap h, int index) {
//	int indexRad = index;
//	int indexSt = 2 * index + 1;
//	int indexDr = 2 * index + 2;
//
//	if (indexSt < h.dim && h.vector[indexSt].nrAngajati > h.vector[index].nrAngajati) {//max
//		indexRad = indexSt;
//	}
//	if (indexDr < h.dim && h.vector[indexDr].nrAngajati > h.vector[index].nrAngajati) {//max
//		indexRad = indexDr;
//	}
//	if (index != indexRad) {
//		Magazin aux = h.vector[index];
//		h.vector[index] = h.vector[indexRad];
//		h.vector[indexRad] = aux;
//
//		for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//			filtrare(h, i);
//		}
// 	}
//}
//
//Heap inserareHeap(Heap h, Magazin m) {
//	Magazin* copieVector = (Magazin*)malloc(sizeof(Magazin) * (h.dim +1));
//	for (int i = 0; i < h.dim; i++) {
//		copieVector[i] = h.vector[i];
//	}
//
//	copieVector[h.dim] = initializareMagazin(m.id, m.denumire, m.suprafata, m.nrAngajati);
//	free(h.vector);
//	h.dim++;
//	h.vector = copieVector;
//
//	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//		filtrare(h, i);
//	}
//
//	return h;
//
//}
//
//Heap extragereHeap(Heap h, Magazin* m) {
//	
//	Magazin aux = h.vector[0];
//	h.vector[0] = h.vector[h.dim - 1];
//	h.vector[h.dim - 1] = aux;
//
//	
//	Magazin* copieVector = (Magazin*)malloc(sizeof(Magazin) * (h.dim - 1));
//	for (int i = 0; i < h.dim-1; i++) {
//		copieVector[i] = h.vector[i];
//	}
//
//	*m = initializareMagazin(h.vector[h.dim - 1].id, ///pt afisare element extras
//		h.vector[h.dim - 1].denumire, h.vector[h.dim - 1].suprafata, h.vector[h.dim - 1].nrAngajati);
//	
//	free(h.vector);
//	h.dim--;
//	h.vector = copieVector;
//
//	for (int i = (h.dim / 2) - 1; i >= 0; i--) {
//		filtrare(h, i);
//	}
//	return h;
//
//}
//
//void afisareMagazin(Magazin m) {
//	printf("\n%u, %s, %.2f, %d ", m.id, m.denumire, m.suprafata, m.nrAngajati);
//}
//
//void afisareHeap(Heap h) {
//	for (int i = 0; i < h.dim; i++) {
//		afisareMagazin(h.vector[i]);
//	}
//}
//
//void dezalocare(Heap h) {
//	if (h.vector) {
//		for (int i = 0; i < h.dim; i++) {
//			free(h.vector[i].denumire);
//		}
//		free(h.vector);
//	}
//}
//
//float medieSupraf(Heap h, const char* denCautata) {
//	int suma = 0;
//	int contor = 0;
//	if (h.vector) {
//		for (int i = 0; i < h.dim; i++) {
//			if (strcmp(h.vector[i].denumire, denCautata) == 0) {
//				suma += h.vector[i].suprafata;
//				contor++;
//			}
//		}
//		
//	}
//	return (float)suma / contor;
//}
//
//void modificaDenumire(Heap h, unsigned int idCautat, const char* denNoua) {
//	if (h.vector) {
//		for (int i = 0; i < h.dim; i++) {
//			if (h.vector[i].id == idCautat) {
//				free(h.vector[i].denumire);
//				h.vector[i].denumire = (char*)malloc(sizeof(char) * strlen(denNoua) + 1);
//				strcpy_s(h.vector[i].denumire, (sizeof(char) * strlen(denNoua) + 1), denNoua);
//				
//				//break;
//			}
//		}
//	}
//}
//
//Magazin returnareMax(Heap h) {
//	Magazin max;
//	if (h.vector) {
//		max = h.vector[0];
//		for (int i = 0; i < h.dim; i++) {
//			if (h.vector[i].suprafata > max.suprafata) {
//				max = h.vector[i];
//			}
//		}
//	}
//	return max;
//}
//
//
//
//void main() {
//	Heap h;
//	h.dim = 0;
//	h.vector = NULL;
//
//	Magazin m;
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex1_heap.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		m.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		m.denumire = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(m.denumire, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		m.suprafata = atof(token);
//
//		token = strtok(NULL, separator);
//		m.nrAngajati = atoi(token);
//
//		h = inserareHeap(h, m);
//
//		free(m.denumire);
//
//	}
//	fclose(f);
//
//	afisareHeap(h);
//
//	printf("\n\nMedie mega image: %.2f", medieSupraf(h, "Mega image"));
//
//	printf("\n\nModificare denumire:");
//	modificaDenumire(h, 2, "NA");
//	afisareHeap(h);
//
//	printf("\n\nReturnare maxim:");
//	Magazin maxim = returnareMax(h);
//	afisareMagazin(maxim);
//
//
//	printf("\n\nExtragere din heap -------------");
//	Magazin mExtras;
//	h = extragereHeap(h,&mExtras);
//	afisareHeap(h);
//
//	printf("\n\nElement extras -------------");
//	afisareMagazin(mExtras);
//
//
//
//
//	dezalocare(h);
//}