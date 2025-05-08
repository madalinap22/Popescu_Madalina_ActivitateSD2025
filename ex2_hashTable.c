//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Cladire {
//	int id;
//	int anConstructie;
//	char* adresa;
//	char* status;
//	int nrLuni;
//	float* cheltuieliLunare;
//}Cladire;
//
//typedef struct Nod {
//	Cladire info;
//	struct Nod* next;
//}Nod;
//
//typedef struct HT {
//	int dim;
//	Nod** vector;
//}HT;
//
//int functieHashInt(HT tabela, int id) {
//	return id % tabela.dim;
//}
//
//int functieHashChar(HT tabela, const char* den) {
//	return strlen(den) % tabela.dim;
//}
//
//Cladire initializareCladire(int id, int anConstructie, char* adresa, char* status, int nrLuni, float* cheltuieliLunare) {
//	Cladire c;
//	c.id = id;
//	c.anConstructie = anConstructie;
//	c.adresa = (char*)malloc(sizeof(char) * strlen(adresa) + 1);
//	strcpy_s(c.adresa, (sizeof(char) * strlen(adresa) + 1), adresa);
//	c.status = (char*)malloc(sizeof(char) * strlen(status) + 1);
//	strcpy_s(c.status, (sizeof(char) * strlen(status) + 1), status);
//	c.nrLuni = nrLuni;
//	c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
//	for (int i = 0; i < c.nrLuni; i++) {
//		c.cheltuieliLunare[i] = cheltuieliLunare[i];
//	}
//	return c;
//
//}
//
//int inserareTabela(HT tabela, Cladire c) {
//	int poz = 0;
//
//	if (tabela.vector) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info =	initializareCladire(c.id, c.anConstructie, c.adresa, c.status, c.nrLuni, c.cheltuieliLunare);
//		nou->next = NULL;
//
//		//poz = functieHashInt(tabela, c.anConstructie);
//		poz = functieHashChar(tabela, c.status);
//
//		if (tabela.vector[poz] == NULL) {
//			tabela.vector[poz] = nou;
//		}
//		else {
//			Nod* aux = tabela.vector[poz];
//			while (aux->next) { ///!!!!!
//				aux = aux->next;
//			};
//			aux->next = nou;
//		}
//	}
//	return poz;
//}
//
//void afisareCladire(Cladire c) {
//	printf("\n %d, %d, %s, %s, %d: ", c.id, c.anConstructie, c.adresa, c.status, c.nrLuni);
//	printf(" Cheltuieli lunare: ");
//	for (int i = 0; i < c.nrLuni; i++) {
//		printf("%.2f ", c.cheltuieliLunare[i]);
//	}
//}
//
//void afisareTabela(HT tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				printf("\nPozitie: %d",i);
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					afisareCladire(aux->info);
//					aux = aux->next;
//				}
//			}
//		}
//	}
//}
//
//void dezalocare(HT tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					free(aux->info.adresa);
//					free(aux->info.status);
//					free(aux->info.cheltuieliLunare);
//
//					Nod* temp = aux->next;
//					free(aux);
//					aux = temp;
//				}
//			}
//		}
//		
//		free(tabela.vector);
//	}
//}
//int medie(HT tabela) {
//	int contor = 0;
//	int suma = 0;
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					suma += aux->info.anConstructie;
//					contor++;
//					aux = aux->next;
//				}
//			}
//		}
//	}
//	return suma / contor;
//}
//
//void modificaStatus(HT tabela, int id, const char* denNoua) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (aux->info.id == id) {
//						aux->info.status = (char*)malloc(sizeof(char) * strlen(denNoua) + 1);
//						strcpy_s(aux->info.status, (sizeof(char) * strlen(denNoua) + 1), denNoua);
//					}
//					aux = aux->next;
//				}
//			}
//		}
//	}
//}
//
//Nod* maxim(HT tabela) {
//	Nod* max = NULL;; ////////////////////
//	if (tabela.vector) {
//		max = tabela.vector;
//		for (int i = 0; i < tabela.dim; i++) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (aux->info.anConstructie > max->info.anConstructie) {
//						max = aux;
//					}
//					aux = aux->next;
//				}
//		}
//	}
//	return max;
//}
//
//void stergeCladire(HT tabela) {
//	//int poz = 0;
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				Nod* prev = NULL; 
//				Nod* max = maxim(tabela);
//				while (aux) {
//					if (max->info.anConstructie == aux->info.anConstructie) {
//						Nod* nodDeSters = aux;
//						if (prev == NULL) {
//							tabela.vector[i] = aux->next;
//							aux = tabela.vector[i];
//						}
//						else {
//							prev->next = aux->next;
//							aux = aux->next;
//						}
//						free(nodDeSters->info.adresa);
//						free(nodDeSters->info.status);
//						free(nodDeSters->info.cheltuieliLunare);
//					}
//					else {
//						prev = aux; //se actualizeaza doar daca nu stergem
//						aux = aux->next;
//					}
//				}
//			}
//		}
//	}
//}
//
////conversie vector pt cladirile expertizate
//int nrElemente(HT tabela, const char* denCautata) {
//	int contor = 0;
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.status, denCautata)==0) {
//						contor++;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//	}
//	return contor;
//}
//
//Cladire* conversieVector(HT tabela, const char* denCautata) {
//	if (tabela.vector) {
//		int nr = nrElemente(tabela, denCautata);
//		Cladire* vector = (Cladire*)malloc(sizeof(Cladire) * nr);
//		int index = 0;
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.status, denCautata) == 0) {
//						vector[index] = initializareCladire(aux->info.id, aux->info.anConstructie, aux->info.adresa,
//							aux->info.status, aux->info.nrLuni, aux->info.cheltuieliLunare);
//						index++;
//					}
//					aux = aux->next;
//				}
//			
//			}
//		}
//		return vector;
//	}
//}
//void dezalocareVectorCladiri(Cladire* vector, int dim) {
//	if (vector) {
//		for (int i = 0; i < dim; i++) {
//			free(vector[i].adresa);
//			free(vector[i].status);
//			free(vector[i].cheltuieliLunare);
//		}
//		free(vector);
//	}
//
//}
//
//
//void main() {
//	Cladire c;
//	HT tabela;
//	tabela.dim = 10;
//	tabela.vector = (Nod*)malloc(sizeof(Nod) * tabela.dim);
//	for (int i = 0; i < tabela.dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex2_hashTable.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		c.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.anConstructie = atoi(token);
//
//		token = strtok(NULL, separator);
//		c.adresa = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.adresa, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		c.status = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(c.status, (sizeof(char) * strlen(token) + 1), token);
//
//
//		token = strtok(NULL, separator);
//		c.nrLuni = atoi(token);
//
//		c.cheltuieliLunare = (float*)malloc(sizeof(float) * c.nrLuni);
//		for (int i = 0; i < c.nrLuni; i++) {
//			token = strtok(NULL, separator);
//			c.cheltuieliLunare[i] = atof(token);
//		}
//
//		inserareTabela(tabela, c);
//		free(c.adresa);
//		free(c.status);
//		free(c.cheltuieliLunare);
//	
//	}
//	fclose(f);
//
//	afisareTabela(tabela);
//
//
//	Nod* nodMax = maxim(tabela);
//	printf("\n\nNodul cu anul maxim: ");
//	afisareCladire(nodMax->info);
//
//	printf("\nMedie: %d", medie(tabela));
//
//	printf("\nStatus modificat: ");
//	modificaStatus(tabela, 1, "NA");
//	afisareTabela(tabela);
//
//
//	printf("\n\nStergere nod maxim: ");
//	/*stergeCladire(tabela);
//	afisareTabela(tabela);*/
//
//	printf("\nNr elemente: %d", nrElemente(tabela, "Expertizata"));
//
//	printf("\n\nConversie in vector");
//	int dim = nrElemente(tabela, "Expertizata");
//	Cladire* vectorCladiri = conversieVector(tabela, "Expertizata");
//	for (int i = 0; i < dim; i++) {
//		afisareCladire(vectorCladiri[i]);
//	}
//
//
//
//	dezalocare(tabela);
//	dezalocareVectorCladiri(vectorCladiri, dim);
//}