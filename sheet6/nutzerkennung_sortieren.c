#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

int main(void){
    int anz_kennungen = 0;
    int length = 0;                                             // Keep track of length of each string entered by user
    int position_j;
    char kennung[BUFFER_SIZE], **strings;
    // char grosser_buffer[30][100] = {{0}};
    bool kleines_elem_gefunden = false;
    
    printf("Anzahl der Nutzerkennungen: ");
    scanf("%d", &anz_kennungen);
    
    anz_kennungen += 1;

    strings = malloc(anz_kennungen * sizeof(char *));
    
        for(int i = 0; i < anz_kennungen; i++){
        printf("Geben Sie eine Kennung %d ein: ", i + 1);
        fgets(kennung, BUFFER_SIZE, stdin);
        length = strlen(kennung);                               // Wir benutzen den Wert um dynamisch Speicher für den String zu reservieren
        kennung[length - 1] = '\0';                             // fgets speichert \n am Ende des strings. Mit dieser Zeile erstezen wir \n mit \0 (end of string character)
        strings[i] = malloc(length * sizeof(char));             // wir reservieren Speicher für length viele character
        strcpy(strings[i], kennung);
    }

    /*
    Die strings werden bewusst ab Array Stelle 10 rein kopiert
    da Selle 0-11 frei bleiben soll für die Anfangsbuchstaben (3 Stellen)
    das Datum (6 Stellen) und den Doppel punkt (1 Stelle)
    */
    printf("\nDeine unsortierten Kennungen:\n");
    for(int i = 0; i < anz_kennungen; i++){
        printf("%s\n", strings[i]);
    }
    printf("\n");
    
    for(int i = 0; i < anz_kennungen; i++){
        char temp_array_buffer[100] = {0};
        strcpy(temp_array_buffer, strings[i]);
        for(int j = i; j < anz_kennungen; j++){
            printf("\nVergleiche: (%s) mit (%s)", temp_array_buffer, strings[j]);
            if(strcmp(temp_array_buffer, strings[j]) > 0){     // str2 ist kleiner als string 1
                printf("\nString %s ist kleiner", strings[j]);
                kleines_elem_gefunden = true;
                position_j = j;
                strcpy(temp_array_buffer, strings[j]);
            }
            else{
                printf("\nString (%s) ist nicht kleiner", strings[j]);
            }
        }
        if(kleines_elem_gefunden == true){
            strcpy(strings[position_j], strings[i]);
            strcpy(strings[i], temp_array_buffer);
        }

        printf("\n\nUpdated Kennungen");
        for(int i = 0; i < anz_kennungen; i++){
        printf("%s\n", strings[i]);
        }
        printf("\n");
    }

    return 0;
}