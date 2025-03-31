//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
////To do: //nr elemente dupa un parametru char*, suma, medie, praguri, etc
//
//typedef struct Pachet {
//	unsigned int id;
//	char* dataPrimire;
//	char* dataLivrare;
//	char* numeClient;
//	float suma;
//}Pachet;
//
//typedef struct nodLS {
//	Pachet info;
//	struct nodLS* next;
//}nodLS;
//
//typedef struct hashTable {
//	int dim;
//	nodLS** vector;
//}hashTable;
//
//Pachet crearePachet(unsigned int id, char* dataPrimire, char* dataLivrare, char* numeClient, float suma) {
//	Pachet p;
//	p.id = id;
//	p.dataPrimire = (char*)malloc(sizeof(char) * strlen(dataPrimire) + 1);
//	strcpy(p.dataPrimire, dataPrimire);
//	p.dataLivrare = (char*)malloc(sizeof(char) * strlen(dataLivrare) + 1);
//	strcpy(p.dataLivrare, dataLivrare);
//	p.numeClient = (char*)malloc(sizeof(char) * strlen(numeClient) + 1);
//	strcpy(p.numeClient, numeClient);
//	p.suma = suma;
//
//	return p;
//}
//
//int functieInserare(hashTable tabela, const char* dataPrimire) {
//	/*return dataPrimire[0] % tabela.dim;*/
//
//	return  (dataPrimire[0] + dataPrimire[1]) % tabela.dim;
//	
//}
//
//int inserareHT(hashTable tabela, Pachet p) {
//	int poz = 0;
//	nodLS* nou = (nodLS*)malloc(sizeof(nodLS));
//	nou->info = crearePachet(p.id, p.dataPrimire, p.dataLivrare, p.numeClient, p.suma);
//	nou->next = NULL;
//
//	if (tabela.vector) {
//		poz = functieInserare(tabela, p.dataPrimire);
//		if (tabela.vector[poz] == 0) {
//			tabela.vector[poz] = nou;
//		}
//		else {
//			nodLS* aux = tabela.vector[poz]; //cap
//			while (aux->next) {
//				aux = aux->next;
//			}
//			aux->next = nou;
//		}
//	}
//	return poz;
//}
//
//void afisare(hashTable tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			if (tabela.vector[i]) {
//				printf("\nPozitia: %d", i);
//
//				nodLS* aux = tabela.vector[i];
//				while (aux) {
//					printf("\nPachetul %u a fost primit pe data de %s si va fi livrat pe data de %s pe numele %s cu valoarea este %.2f\n ",
//						aux->info.id, aux->info.dataPrimire, aux->info.dataPrimire, aux->info.numeClient, aux->info.suma);
//					aux = aux->next;
//				}
//				
//			}
//		}
//	}
//}
//
//void dezalocare(hashTable tabela) {
//	if (tabela.vector) {
//		for (int i = 0; i < tabela.dim; i++) {
//			nodLS* aux = tabela.vector[i];
//			while (aux) {
//				free(aux->info.dataPrimire);
//				free(aux->info.dataLivrare);
//				free(aux->info.numeClient);
//
//				nodLS* temp = aux->next;
//					free(aux);
//					aux = temp;
//			}
//		}
//		free(tabela.vector);
//	}
//}
//
//
//
//void main(){
//
//	Pachet p;
//	hashTable tabela;
//	tabela.dim = 10;
//	tabela.vector = (nodLS**)malloc(sizeof(nodLS*) * tabela.dim);
//	for (int i = 0; i < tabela.dim; i++) {
//		tabela.vector[i] = NULL;
//	}
//
//	char linieBuffer[100];
//	char separator[3] = ",";
//	char* token;
//
//	FILE* fisier = fopen("fisierEx_hashtable.txt", "r");
//	while (fgets(linieBuffer, 100, fisier)) {
//		token = strtok(linieBuffer, separator);
//		p.id = atoi(token);
//
//		token = strtok(NULL, separator);
//		p.dataPrimire = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy(p.dataPrimire, token);
//
//		token = strtok(NULL, separator);
//		p.dataLivrare = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy(p.dataLivrare, token);
//
//		token = strtok(NULL, separator);
//		p.numeClient = (char*)malloc(sizeof(char) * strlen(token) + 1);
//		strcpy(p.numeClient, token);
//
//
//		token = strtok(NULL, separator);
//		p.suma = atof(token);
//
//		inserareHT(tabela, p);
//		free(p.dataPrimire);
//		free(p.dataLivrare);
//		free(p.numeClient);
//	}
//	fclose(fisier);
//
//	afisare(tabela);
//
//
//
//
//}