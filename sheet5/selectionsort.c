//Include Header
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Beginn Hauptprogramm
int main (void) {
    /*
Einlesen des Array aus externer Datei:
Durch das Umleiten der Standardeingabe wird wie gewohnt scanf(...) verwendet. Mit dem Unterschied, 
dass Sie die Eingabe nicht mehr über die Tastatur tätigen, sondern diese automatisch von der Datei erfolgt.

Lesen Sie zunächst die Anzahl der Einträge des Array ein.
Lesen Sie als nächstes die einzelnen Einträge des Array ein. 
Verwenden Sie beim Ausführen der Datei den <-Operator.
Die Syntax im Terminal lautet:
program < datei
*/
bool max_found = false;
int *myarray, anzahl_elemente, i = 0, max, temp, index_new_max, durchlauefe = 0;
    scanf("%d", &anzahl_elemente);
    myarray = malloc(anzahl_elemente * sizeof(int));
    if(myarray == NULL){
        printf("Fehler bei der Speicherreservierung");
        return EXIT_FAILURE;
    }
    while(i < anzahl_elemente){
        scanf("%d", &myarray[i]);
        i++;
    }
    printf("Eingegebenes Array: ");
    for(int i = 0; i < anzahl_elemente; i++){
        printf("%d ", myarray[i]);
    }
//Selection-Sort-Algorithmus
for(int i = 0; i < anzahl_elemente; i++){           // zu ueberpruefendes Element --> myarray[i]
    durchlauefe++;
    max = myarray[i];
    temp = myarray[i];
    printf("\nZu ueberpruefendes Element: %d", myarray[i]);
    for(int j = i; j < anzahl_elemente; j++){       // finde größte Zahl im Array nach Position i
        if(myarray[j] > max){
            printf("\nj: %d", j);
            max = myarray[j];
            index_new_max = j;
            printf("\nGefundenes Max: %d", myarray[max]);
            max_found = true;
        }
    }
    if(max_found == true){
        myarray[i] = max;
        myarray[index_new_max] = temp;
        max_found = false;
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
printf("Anzahl der Durchlaeufe: %d", durchlauefe);
//Ende Hauptprogramm
    return 0;
}

