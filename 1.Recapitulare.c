//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
////variabila globala; vizibila si in main si in interiorul functiilor
//int x = 10;
//
//int suma(int a, int b) {
//	int suma = 0;//var locala
//	x = 11;
//}
//
////cea mai sigura metoda de lucru(acces/modificare) - prin adresa
//
////transmitere parametri prin valoare si adresa (prin adresa doar in C++)
////
//
//
//
//
//void main() {
//	int a = 7;
//	printf("%d\n", a);
//	printf("%.2f\n", (float)a); 
//	printf("%p\n", &a); //adresa se schimba la fiecare rulare
//
//	//& -> referentiere - merge pe orice tip de data; acces adresa
//	//* -> dereferentiere - merge doar pe pointeri; acces valoarea de la adresa
//
//	int* pointera = &a; //(adresa)referinta
//	printf("%p\n", pointera); //adresa
//	printf("%d\n", *pointera); //dereferentiere - accesare valoare
//
//
//	//vectori statici (stack; sunt stivuiti(ordonati)) ->nu ne ocupam de alocare/dezalocare de memorie
//	
//	int vectorStatic[5] = { 2,4,6,8,9 }; //sau cu indexare
//	vectorStatic[2] = 100;
//	
//	printf("Vector static------------------\n");
//	for (int i = 0; i < 5; i++) {
//		printf("%d\n", vectorStatic[i]);
//	}
//	//vectorStatic - adresa primei valori din vector
//	//vectorii statici nu au voie sa depaseasca zona de memorie alocata
//
//
//	//vectori dinamici(heap - sunt alocati dinamic)
//	printf("Vector dinamic------------------\n");
//	int dim = 5;
//	int* vectorDinamic = (int*)malloc(sizeof(int) * dim); //int* ->tipul de data returnat; 
//	printf("%p\n", vectorDinamic); //adresa vectorului (prima adresa din vector)
//
//	vectorDinamic[0] = 23; //numar default la vectorDinamic[1] daca este doar alocata memorie
//	vectorDinamic[2] = 24;
//	vectorDinamic[3] = 25;
//	vectorDinamic[4] = 26;
//	vectorDinamic[5] = 27;
//	for (int i = 0; i < dim; i++) {
//		printf(" %d\n", vectorDinamic[i]);
//	}
//
//	//referinta-dereferentiere
//	printf("\nreferinta-dereferentiere------------------\n");
//
//	int v[5] = { 4,6,10,8,5 };
//	printf("%p\n", v);
//	printf("%p\n", v+1);
//	printf("%d\n", *(v+1));//valoarea element de pe pozitia 2
//	printf("%d\n", *(v + 2));
//	printf("%d\n", *(v + 3));
//
//	int* p = NULL; //nu lasam pointerii neinitializati
//
//	p = v;
//	printf("%p\n", p); //adresa pointerului egala cu adresa v (primul element)
//	printf("%d\n", *p);//valoarea primului element
//	printf("%d\n", v[0]);
//	
//	*p = 100;
//	printf("%d\n", *p); //schimbare valoare
//
//	p++; //pointeaza la urmatoarea pozitie
//	*p = 200;
//	printf("%d\n", v[1]);
//
//	//egalare pointer - varianta indexare
//	p = &v[2];
//	printf("Egalare pointer %d\n", *p);
//
//	*p = 17;
//	printf("Modificare valoare pointer cu indexare %d\n", v[2]);
//
//	//egalare pointer - fara indexare
//	p = v + 3;
//	printf("Egalare pointer fara indexare %d\n", *p);
//
//	*p = 88;
//	printf("Modificare valoare pointer %d\n", *(v+3));
//	printf("Modificare valoare pointer 2: %d\n", *p);
//
//	p = v; //p pointeaza la adresa lui v
//	printf("%d\n", *p);
//
//	p--;
//	printf("%d\n", *p);//numar default - a adresei de dinaintea vectorului
//	//*p = 300; //Stack around the variable 'v' was corrupted.
//
//	//Modificare valoare prin vector
//	*(v + 4) = 55;
//	printf("Modificare prin vector %d\n", v[4]);
//	p = (v + 4); //p pointeaza la adresa lui v[4]
//	printf("Modificare 2: %d\n", *p);
//
//
//
//}
