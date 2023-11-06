#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int bubblesort(int *myarray, int anzahl_elemente, int sortierrichtung){
    // Variablen deklarieren
    bool sorted = false;
    int temp, counter = 0, durchlauefe = 0;

    // Bubble-Sort-Algorithmus
    if(anzahl_elemente > 1){
        while(sorted == false){
            for(int i = 0; i < anzahl_elemente; i++){
                durchlauefe++;
                if(counter == anzahl_elemente){
                    sorted = true;
                    break;
                }
                printf("\ni: %d\nnext i: %d", i, i+1);
                printf("\narray[i]: %d\narray[i++]: %d", myarray[i], myarray[i+1]);
                if(i+1 >= anzahl_elemente){
                    printf("\nWe break here...");
                    break;
                }
                if(sortierrichtung == 1){
                    if(myarray[i] <= myarray[i+1]){
                        printf("\nNot swapped");
                        counter++;
                    }else{
                        printf("\nSwapped");
                        printf("\nUpdated Array: ");
                        temp = myarray[i+1];
                        myarray[i+1] = myarray[i];
                        myarray[i] = temp;
                        counter = 0;
                        for(int i = 0; i < anzahl_elemente; i++){
                            printf("%d ", myarray[i]);
                        }
                    } 
                }
                if(sortierrichtung == 2){
                    if(myarray[i] >= myarray[i+1]){
                        printf("\nNot swapped");
                        counter++;
                    }else{
                        printf("\nSwapped");
                        printf("\nUpdated Array: ");
                        temp = myarray[i+1];
                        myarray[i+1] = myarray[i];
                        myarray[i] = temp;
                        counter = 0;
                        for(int i = 0; i < anzahl_elemente; i++){
                            printf("%d ", myarray[i]);
                        }
                    }   
                }
            }
        }
    }
    // Ausgabe des Ergebnisses im Terminal
    printf("\n\nBubble Sort\nEnd-Array: ");
    for(int i = 0; i < anzahl_elemente; i++){
        printf("%d ", myarray[i]);
    }
    printf("\nAnzahl der Durchlaeufe: %d", durchlauefe);
    return 0;
}

int selectionsort(int *myarray, int anzahl_elemente, int sortierrichtung){
    // Variablen deklarieren
    bool elem_found = false;
    int elem, temp, index_new_elem, durchlauefe = 0;

    //Selection-Sort-Algorithmus
    for(int i = 0; i < anzahl_elemente; i++){               // zu ueberpruefendes Element --> myarray[i]
        durchlauefe++;
        elem = myarray[i];
        temp = myarray[i];
        printf("\nZu ueberpruefendes Element: %d", myarray[i]);
        if(sortierrichtung == 1){                           
            for(int j = i; j < anzahl_elemente; j++){       // finde kleinste Zahl im Array nach Position i
                if(myarray[j] < elem){
                    elem = myarray[j];
                    index_new_elem = j;
                    printf("\nGefundenes Min: %d", myarray[elem]);
                    elem_found = true;
                }
            }
        }
        if(sortierrichtung == 2){     
            for(int j = i; j < anzahl_elemente; j++){       // finde größte Zahl im Array nach Position i
                if(myarray[j] > elem){
                    elem = myarray[j];
                    index_new_elem = j;
                    printf("\nGefundenes Max: %d", myarray[elem]);
                    elem_found = true;
                }
            }
        }
        if(elem_found == true){
            myarray[i] = elem;
            myarray[index_new_elem] = temp;
            elem_found = false;
        }
        printf("\nUpdated Array: ");
        for(int i = 0; i < anzahl_elemente; i++){
        printf("%d ", myarray[i]);
    }
    }
    //Ausgabe des Ergebnisses im Terminal
    printf("\n\nSelection Sort\nEnd-Array: ");
    for(int i = 0; i < anzahl_elemente; i++){
        printf("%d ", myarray[i]);
    }
    printf("\nAnzahl der Durchlaeufe: %d", durchlauefe);
    return 0;
}

int main(void){
int *myarray, anzahl_elemente, i = 0, auswahl, sortierrichtung;
    printf("\nGeben Sie die Groesse des Arrays an: ");
    scanf("%d", &anzahl_elemente);
    myarray = malloc(anzahl_elemente * sizeof(int));
    if(myarray == NULL){
        printf("Fehler bei der Speicherreservierung");
        return EXIT_FAILURE;
    }
    while(i < anzahl_elemente){
        printf("Wert %d: ", i+1);
        scanf("%d", &myarray[i]);
        i++;
    }
    printf("Eingegebenes Array: ");
    for(int i = 0; i < anzahl_elemente; i++){
        printf("%d ", myarray[i]);
    }

    printf("\nWie soll ihr Array sortiert werden?\n- Aufsteigend(1)\n- Absteigend(2)\nIhre Auswahl: ");
    scanf("%d", &auswahl);
    switch(auswahl){
        case 1: sortierrichtung = 1; break;
        case 2: sortierrichtung = 2; break;
        default: printf("Keine gueltige Angabe"); break;
    }
    printf("\nWelchen Sortieralgorithmus wollen Sie verwenden?\n- Bubblesort(1)\n- Selectionsort(2)\nIhre Auswahl: ");
    scanf("%d", &auswahl);
    switch(auswahl){
        case 1: bubblesort(myarray, anzahl_elemente, sortierrichtung); break;
        case 2: selectionsort(myarray, anzahl_elemente, sortierrichtung); break;
        default: printf("Keine gueltige Angabe"); break;
    }
    return 0;
}