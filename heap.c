//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
////coada de prioritati
//
//typedef struct Activitate {
//	char* denumire;
//	int prioritate;
//}Activitate;
//
//typedef struct Heap {
//	int dim;
//	Activitate* vector;
//}Heap;
//Activitate initializareActivitate(char* denumire, int prioritate) {
//	Activitate a;
//	a.denumire = (char*)malloc(sizeof(char) * strlen(denumire) + 1);
//	strcpy_s(a.denumire, (sizeof(char) * strlen(denumire) + 1), denumire);
//	a.prioritate = prioritate;
//	return a;
//}
//
//Heap initializareHeap(int dim) {
//	Heap h;
//	h.dim = dim;
//	h.vector = (Activitate*)malloc(sizeof(Activitate) * h.dim);
//	return h;
//}
//
////f de filtrare, f. adaugare, f. extragere
////afisare&dezalocare de vector
//
//void filtrare(Heap h, int index) { //index de unde incep filtrarea
//	int indexRad = index; //incep filtrarea cu ce am la parametru
//	int indexSt = 2 * index + 1;
//	int indexDr = 2 * index + 2;
//
//	//ca sa nu depasim dim vector verificam in if
//	if (indexSt < h.dim && h.vector[indexSt].prioritate < h.vector[indexRad].prioritate) {
//		indexRad = indexSt;
//	}
//	if (indexDr < h.dim && h.vector[indexDr].prioritate < h.vector[indexRad].prioritate) {
//		indexRad = indexDr;
//	}
//	if (index != indexRad) {
//		Activitate aux = h.vector[index];
//		h.vector[index] = h.vector[indexRad];
//		h.vector[indexRad] = aux;
//		//dupa interschimbare mai filtram pt a vedea daca
//
//		for (int i = (h.dim / 2) - 1; i < 0; i--){
//			filtrare(h, i);
//		}
//		
//	}
//
//}
//
//Heap inserareHeap(Heap h, Activitate a) {
//	//copie la vector Activiatte* vector
//	Activitate* copieVector = (Activitate*)malloc(sizeof(Activitate) * (h.dim + 1));
//	for (int i = 0; i < h.dim; i++) {
//		copieVector[i] = h.vector[i];
//	}
//	copieVector[h.dim] = a;
//	free(h.vector);
//	h.dim++;
//	h.vector = copieVector;
//
//	return h;
//
//}
////extragere; mut primul element(prioriatte 0) pe ultimul
//Heap extragereHeap(Heap h, Activitate* a) {
//	//interschimb pt a scoate ultimul element
//	Activitate aux = h.vector[0];
//	h.vector[0] = h.vector[h.dim - 1]; //h.dim - 1 =>ultimul element din vector
//	h.vector[h.dim - 1] = aux;
//
//	//copie la vector Activiatte* vector
//	Activitate* copieVector = (Activitate*)malloc(sizeof(Activitate) * (h.dim - 1));
//	for (int i = 0; i < h.dim-1; i++) {
//		copieVector[i] = h.vector[i];
//	}
//	//salvare
//	*a = initializareActivitate(h.vector[h.dim - 1].denumire, h.vector[h.dim - 1].prioritate);//optional
//	free(h.vector);
//	h.dim--;
//	h.vector = copieVector;
//
//	return h;
//
//}
//
//void afisareActivitate(Activitate a) {
//	printf("%s, %d ", a.denumire, a.prioritate);
//}
//
//
//
//void main() {
//
//	Heap h;
//	h.dim = 3;
//	h.vector = (Activitate*)malloc(sizeof(Activitate) * h.dim);
//	h.vector[0] = initializareActivitate("Alergare", 5);
//	h.vector[1] = initializareActivitate("Vot", 1);
//	h.vector[2] = initializareActivitate("Meditatie", 3);
//	
//
//	for (int i = 0; i < h.dim; i++) {
//		afisareActivitate(h.vector[i]);
//	}
//
//	
//		filtrare(h, 0);
//
//		for (int i = 0; i < h.dim; i++) {
//			afisareActivitate(h.vector[i]);
//		}
//
//	Activitate a = initializareActivitate("Cumparaturi", 0);
//	h = inserareHeap(h, a);
//
//	for (int i = 0; i < h.dim; i++) {
//		afisareActivitate(h.vector[i]);
//	}
//
//
//}