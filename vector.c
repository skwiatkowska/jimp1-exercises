#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector *reserve(Vector *vect){
    Vector *pom;
    pom=(Vector*)malloc(sizeof(Vector));
    if(pom==NULL){
        printf("\nAlokacja struktury nie powiodla sie.\n\n");
        return NULL;
    }
    if(vect==NULL || vect->numOfElem==0){
        pom->tablica=(int*)malloc(sizeof(int));
        pom->capacity=sizeof(int);
        pom->numOfElem=0;
        return pom;
    }
    pom->tablica=(int*)malloc((vect->numOfElem)*sizeof(int));
    if(pom->tablica==NULL){
        printf("\nAlokacja tablicy liczb calkowitych nie powiodla sie.\n\n");
        free(pom);
        return NULL;
    }
    for(int i=0; i<(vect->numOfElem); i++){
        pom->tablica[i]=vect->tablica[i];
    }
    pom->capacity=capacity(vect);
    pom->numOfElem=size(vect);
    printf("\nAlokacja tablicy liczb calkowitych powiodla sie.\n\n");
    return pom;
}

int size(Vector *vect){
    return vect->numOfElem;
}

int capacity(Vector *vect){
    return vect->capacity;
}

int empty(Vector *vect){
    if(vect->numOfElem==0){
        return 0;
    }
    else{
        return 1;
    }
}

void push_back(Vector *vect){
    if(vect==NULL){
        printf("\nStruktura nie zostala zaalokowana.\n\n");
        return;
    }
    vect->tablica=(int*)realloc(vect->tablica, (vect->numOfElem+1)*sizeof(int));
    if(vect->tablica==NULL){
        printf("\nBlad przy realokacji.\n");
        return;
    }
    printf("\nPodaj liczbe do dodania na koncu tablicy: ");
    scanf("%d", &(vect->tablica[vect->numOfElem]));
    (vect->numOfElem)++;
    printf("Liczba zostala dodana na koniec tablicy.\n\n");
    if(size(vect)==1){
        return;
    }
    vect->capacity+=sizeof(int);
}

void insert(Vector *vect){
    int i, miejsce;
    printf("W ktore miejsce listy chcesz wstawic liczbe: ");
    scanf("%d", &miejsce);
    if(vect->tablica==NULL){
        printf("\nBlad przy realokacji. Trzeba ponownie zaalokowac.\n\n");
        return;
    }
    if(miejsce>size(vect) || miejsce<=0){
        printf("\nLiczba wykracza poza zakres tablicy.\n\n");
        return;
    }
    else if(miejsce==1 && size(vect)==0){
        vect->tablica=(int*)realloc(vect->tablica,(vect->numOfElem+1)*sizeof(int));
        scanf("%d",&(vect->tablica[0]));
    }
    vect->tablica=(int*)realloc(vect->tablica,(vect->numOfElem+1)*sizeof(int));
    for(i=size(vect); i>miejsce-1; i--){
        vect->tablica[i]=vect->tablica[i-1];
    }
    printf("\nPodaj liczbe do dodania: ");
    scanf("%d",&(vect->tablica[i]));
    (vect->numOfElem)++;
    printf("Liczba zostala dodana w wybrane miejsce.\n\n");
    vect->capacity+=sizeof(int);
}

void removeElement(Vector *vect){
    int miejsce;
    printf("\nKtory element chcesz usunac: ");
    scanf("%d", &miejsce);
    if(miejsce>size(vect) || miejsce<=0){
        printf("\nLiczba wykracza poza zakres tablicy.\n\n");
        return;
    }
    else if(miejsce==1 && size(vect)==1){
        free(vect->tablica);
        (vect->numOfElem)--;
        vect->capacity-=sizeof(int);
    }
    for(int i=miejsce-1; i<size(vect)-1; i++){
        vect->tablica[i]=vect->tablica[i+1];
    }
    vect->tablica=(int*)realloc(vect->tablica,(vect->numOfElem-1)*sizeof(int));
    (vect->numOfElem)--;
    vect->capacity-=sizeof(int);
    printf("Element usuniety.\n\n");
}

void reverse(Vector *vect){
    int i=0,pom;
    while(i<=(size(vect)-1)/2){
        pom=vect->tablica[i];
        vect->tablica[i]=vect->tablica[(size(vect)-1)-i];
        vect->tablica[(size(vect)-1)-i]=pom;
        i++;
    }
    printf("Odwrocono liste.\n");
}

void at(Vector *vect){
    int n;
    printf("Ktory element chcesz pobrac: ");
    scanf("%d", &n);
    if(n>size(vect)){
        printf("\nTen element nie istnieje.\n\n");
        return;
    }
    printf("\n%d element = %d\n\n", n, vect->tablica[n-1]);
}
