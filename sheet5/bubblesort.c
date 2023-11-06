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
bool sorted = false;
int *myarray, anzahl_elemente, i = 0, temp, counter = 0, durchlauefe = 0;
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
// Ausgabe des Ergebnisses im Terminal
printf("\n\nBubble Sort\nEnd-Array: ");
for(int i = 0; i < anzahl_elemente; i++){
    printf("%d ", myarray[i]);
}
printf("\nAnzahl der Durchlaeufe: %d", durchlauefe);
//Ende Hauptprogramm

    free(myarray);
    return 0;

}

