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
//typedef struct Nod {
//	Proiect info;
//	struct Nod* stang;
//	struct Nod* drept;
//}Nod;
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
//Nod* creareNod(Proiect p, struct Nod* stang, struct Nod* drept) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareProiect(p.id, p.beneficiar, p.buget);
//	nou->stang = stang;
//	nou->drept = drept;
//	return nou;
//}
//
//Nod* inserareNod(Nod* rad, Proiect m) {
//	if (rad) {
//		if (m.id < rad->info.id) {
//			rad->stang = inserareNod(rad->stang, m);
//			return rad;
//		}
//		else if (m.id > rad->info.id) {
//			rad->drept = inserareNod(rad->drept, m);
//			return rad;
//		}
//		else {
//			return rad;
//			}
//	}else{
//		return creareNod(m, NULL, NULL);
//	}
//}
//
//void afisareProiect(Proiect p) {
//	printf("\n%d, %s, %.2f", p.id, p.beneficiar, p.buget);
//}
//
//void afisarePreOrdine(Nod* rad) {
//	if (rad) {
//		afisareProiect(rad->info);
//		afisarePreOrdine(rad->stang);
//		afisarePreOrdine(rad->drept);
//	}
//}
//
//void dezalocare(Nod* rad) {
//	if(rad) {
//		Nod* tempS = rad->stang;
//		Nod* tempD = rad->drept;
//
//		free(rad->info.beneficiar);
//		free(rad);
//		dezalocare(tempS);
//		dezalocare(tempD);
//	}
//}
//float suma(Nod* rad) {
//	float sum = 0;
//	if (rad) {
//		sum += rad->info.buget;
//		sum += suma(rad->stang);
//		sum += suma(rad->drept);
//
//	}
//	return sum;
//}
//int numaraNoduri(Nod* rad) {
//	if (rad == NULL) {
//		return 0;
//	}
//	else {
//		return 1 + numaraNoduri(rad->stang) + numaraNoduri(rad->drept);
//	}
//}
//int numaraNoduriDupaBeneficiar(Nod* rad, const char* beneficiarCautat) {
//	if (rad == NULL) {
//		return 0;
//	}
//
//	int contor = 0;
//	if (strcmp(rad->info.beneficiar, beneficiarCautat) == 0) {
//		contor = 1;
//	}
//
//	return contor +
//		numaraNoduriDupaBeneficiar(rad->stang, beneficiarCautat) +
//		numaraNoduriDupaBeneficiar(rad->drept, beneficiarCautat);
//}
//Nod* nodCuBugetMinim(Nod* rad) {
//	if (rad == NULL) {
//		return NULL;
//	}
//
//	Nod* minStang = nodCuBugetMinim(rad->stang);
//	Nod* minDrept = nodCuBugetMinim(rad->drept);
//
//	Nod* min = rad;
//
//	if (minStang && minStang->info.buget < min->info.buget) {
//		min = minStang;
//	}
//	if (minDrept && minDrept->info.buget < min->info.buget) {
//		min = minDrept;
//	}
//
//	return min;
//}
//Nod* cautaDupaBeneficiar(Nod* rad, const char* beneficiarCautat) {
//	if (rad == NULL) {
//		return NULL;
//	}
//
//	if (strcmp(rad->info.beneficiar, beneficiarCautat) == 0) {
//		return rad;
//	}
//
//	Nod* rezultatStang = cautaDupaBeneficiar(rad->stang, beneficiarCautat);
//	if (rezultatStang) {
//		return rezultatStang;
//	}
//
//	return cautaDupaBeneficiar(rad->drept, beneficiarCautat);
//}
////pt deep copy
//Nod* copieNod(Nod* sursa) {
//	if (!sursa) return NULL;
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = initializareProiect(sursa->info.id, sursa->info.beneficiar, sursa->info.buget);
//	nou->stang = NULL;
//	nou->drept = NULL;
//
//	return nou;
//}
//void dezalocareNodNou(Nod* nod) {
//	if (nod) {
//		free(nod->info.beneficiar);
//		free(nod);                 
//	}
//}
//
//
//
//void main() {
//	Proiect p;
//	Nod* rad = NULL;
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
//		rad = inserareNod(rad, p);
//
//		free(p.beneficiar);
//	}
//	fclose(f);
//
//	afisarePreOrdine(rad);
//
//	printf("\n\nSuma: %.2f", suma(rad));
//	printf("\n\nNr noduri DRM: %d", numaraNoduriDupaBeneficiar(rad,"DRM"));
//
//
//	float medie = suma(rad) / numaraNoduri(rad);
//	printf("\n\nMedie : %.2f", medie);
//
//	Nod* nodMin = nodCuBugetMinim(rad);
//	if (nodMin) {
//		printf("\n\nProiectul cu bugetul minim este:");
//		afisareProiect(nodMin->info);
//	}
//
//	printf("\n\nNod returnat dupa beneficiar:");
//	Nod* rezultat = cautaDupaBeneficiar(rad, "DONA");
//	afisareProiect(rezultat->info);
//	printf("\n\nNod returnat dupa beneficiar cu deep copy:");
//	if (rezultat) {
//		Nod* copie = copieNod(rezultat);
//		dezalocareNodNou(copie);
//	}
//	afisareProiect(rezultat->info);
//	
//
//
//
//	dezalocare(rad);
//}
