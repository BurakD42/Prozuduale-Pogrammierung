#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int *myarray, anzahl_elemente, i = 0;
    srand(time(NULL));
        scanf("%d", &anzahl_elemente);
        myarray = malloc(anzahl_elemente * sizeof(int));
        if(myarray == NULL){
            printf("Fehler bei der Speicherreservierung");
            return EXIT_FAILURE;
        }
        while(i < anzahl_elemente){
            myarray[i] = rand();
            i++;
        }
        printf("%d\n", anzahl_elemente);
        for(int i = 0; i < anzahl_elemente; i++){
            printf("%d ", myarray[i]);
        }
        printf("\n1\n1");


    return 0;
}