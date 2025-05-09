//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct Pachet {
//	unsigned int id;
//	char* destinatie;
//	char* destinatar;
//	float pret;
//	int nrTemperaturi;
//	float* temperaturi;
//
//}Pachet;
//
//typedef struct Nod {
//	Pachet info;
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
//Pachet initializarePachet(unsigned int id, char* destinatie, char* destinatar, float pret, int nrTemperaturi, float* temperaturi) {
//	Pachet p;
//	p.id = id;
//	p.destinatie = (char*)malloc(sizeof(char) * strlen(destinatie) + 1);
//	strcpy_s(p.destinatie, (sizeof(char) * strlen(destinatie) + 1), destinatie);
//	p.destinatar = (char*)malloc(sizeof(char) * strlen(destinatar) + 1);
//	strcpy_s(p.destinatar, (sizeof(char) * strlen(destinatar) + 1), destinatar);
//	p.pret = pret;
//	p.nrTemperaturi = nrTemperaturi;
//	p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
//	for (int i = 0; i < p.nrTemperaturi; i++) {
//		p.temperaturi[i] = temperaturi[i];
//	}
//	return p;
//}
//
//int adaugareTabela(HT tabela, Pachet p) {
//	int poz = 0;
//	if (tabela.vector) {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->info = initializarePachet(p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi, p.temperaturi);
//		nou->next = NULL;
//
//		poz = functieHashChar(tabela, p.destinatie);
//		if (tabela.vector[poz] == NULL) {
//			tabela.vector[poz] = nou;
//
//		}
//		else {
//			Nod* aux = tabela.vector[poz];
//			while (aux->next) {
//				aux = aux->next;
//			}
//			aux->next = nou;
//		}
//	}
//	return poz;
//}
//
//void afisarePachet(Pachet p) {
//	printf("\n%u, %s, %s, %.2f, %d ", p.id, p.destinatie, p.destinatar, p.pret, p.nrTemperaturi);
//	printf("Temperaturi: ");
//	for (int i = 0; i < p.nrTemperaturi; i++) {
//		printf("%.2f ", p.temperaturi[i]);
//	}
//}
//
//void afisareTabela(HT tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				printf("\nPozitie: %d", i);
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					afisarePachet(aux->info);
//					aux = aux->next;
//				}
//			}
//		}
//	}
//}
//
//void dezalocareTabela(HT tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					free(aux->info.destinatie);
//					free(aux->info.destinatar);
//					free(aux->info.temperaturi);
//
//					Nod* temp = aux->next;
//					free(aux);
//					aux = temp;
//				}
//			}
//		}
//		free(tabela.vector);
//	}
//}
//double suma(HT tabela, const char* denCautata) {
//	double suma = 0;
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.destinatie, denCautata) == 0) {
//						suma += aux->info.pret;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//	}
//	return suma;
//}
//Nod* maxim(HT tabela) {
//	Nod* max = NULL;
//	if (tabela.vector) {
//		max = tabela.vector;
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (aux->info.pret > max->info.pret) {
//						max = aux;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//		return max;
//	}
//}
//
//void stergeNod(HT tabela) {
//	if (tabela.vector) {
//		Nod* max = maxim(tabela);
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				Nod* prev = NULL;
//
//				while (aux) {
//					if (aux->info.pret == max->info.pret) {
//						Nod* nodDeSters = aux;
//						if (prev == NULL) {
//							tabela.vector[i] = aux->next;
//							aux = tabela.vector[i];
//						}else{
//							prev->next = aux->next;
//							aux = aux->next;
//						}
//						free(nodDeSters->info.destinatie);
//						free(nodDeSters->info.destinatar);
//						free(nodDeSters->info.temperaturi);
//
//					}
//					prev = aux;
//					aux = aux->next;
//				}
//			}
//		}
//	}
//}
//int nrElemente(HT tabela, const char* denCautata) {
//	int contor = 0;
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.destinatie, denCautata) == 0) {
//						contor++;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//	}
//	return contor;
//}
//Pachet* vectorFiltrat(HT tabela,  const char* denCautata) {
//	if (tabela.vector) {
//		int dim = nrElemente(tabela, denCautata);
//		Pachet* vector = (Pachet*)malloc(sizeof(Pachet)*dim);
//		int index = 0;
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				Nod* aux = tabela.vector[i];
//				while (aux) {
//					if (strcmp(aux->info.destinatie, denCautata) == 0) {
//						vector[index] = initializarePachet(aux->info.id, aux->info.destinatie, aux->info.destinatar, aux->info.pret, aux->info.nrTemperaturi, aux->info.temperaturi);
//						index++;
//					}
//					aux = aux->next;
//				}
//			}
//		}
//		return vector;
//	}
//}
//
//void dezalocareVector(Pachet* vector, int dim) {
//	if (vector) {
//		for (int i = 0; i < dim; i++) {
//			free(vector[i].destinatie);
//			free(vector[i].destinatar);
//			free(vector[i].temperaturi);
//		}
//		free(vector);
//	}
//}
//
//void main() {
//	Pachet p;
//	HT tabela;
//	tabela.dim = 10;
//	tabela.vector = (Nod*)malloc(sizeof(Nod)* tabela.dim);
//	for (int i = 0; i < tabela.dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token = NULL;
//
//	FILE* f = fopen("ex3_hashTable.txt", "r");
//	while (fgets(linieBuffer, 100, f)) {
//		token = strtok(linieBuffer, separator);
//		p.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.destinatie = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.destinatie, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		p.destinatar = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy_s(p.destinatar, (sizeof(char) * strlen(token) + 1), token);
//
//		token = strtok(NULL, separator);
//		p.pret = atof(token);
//
//		token = strtok(NULL, separator);
//		p.nrTemperaturi = atoi(token);
//
//		p.temperaturi = (float*)malloc(sizeof(float) * p.nrTemperaturi);
//		for (int i = 0; i < p.nrTemperaturi; i++) {
//			token = strtok(NULL, separator);
//			p.temperaturi[i] = atof(token);
//		}
//
//		adaugareTabela(tabela, p);
//		free(p.destinatie);
//		free(p.destinatar);
//		free(p.temperaturi);
//	}
//	fclose(f);
//
//	afisareTabela(tabela);
//
//	printf("\nSuma: %.2f", suma(tabela, "Iasi"));
//	printf("\nNod maxim: ");
//	Nod* max = maxim(tabela);
//	afisarePachet(max->info);
//
//	printf("\nSterge nod: ");
//	//stergeNod(tabela);
//	//afisareTabela(tabela);
//
//	printf("\nNr elemente: %d", nrElemente(tabela, "Iasi"));
//
//	printf("\n\nConversie vector: ");
//	int dim = nrElemente(tabela, "Iasi");
//	Pachet* vectorPachete = vectorFiltrat(tabela, "Iasi");
//	for (int i = 0; i < dim; i++) {
//		afisarePachet(vectorPachete[i]);
//	}
//
//
//	dezalocareTabela(tabela);
//	dezalocareVector(vectorPachete,dim);
//
//}