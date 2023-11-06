#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void manipuliere_grosser_buffer(char grosser_buffer[10][100], char *neues_datum_buffer, char *anfangsbuchstaben, int i){
    // Schreibe Anfangsbuchstaben (z.B. TKP) an Stelle 0, 1 und 2 des Arrays
    for(int i = 1; i < 4; i++){
        printf("\nStelle %d: %c\n", i, anfangsbuchstaben[i]);
    }

    // Schreibe 
    grosser_buffer[i][0] = anfangsbuchstaben[0];                    // Das ist der newline character: kriege den irgendwie nicht weg
    grosser_buffer[i][1] = anfangsbuchstaben[1];
    grosser_buffer[i][2] = anfangsbuchstaben[2];
    grosser_buffer[i][3] = anfangsbuchstaben[3];

    // Schreibe Datum (z.B. 220915) an Stelle 3 bis 9 des Arrays
    for(int j = 4; j-4 < 6; j++){
        grosser_buffer[i][j] = neues_datum_buffer[j-4];
    }

    // Schreibe ':' an Stelle 10 des Arrays
    grosser_buffer[i][10] = ':';
}

void manipuliere_datum(char *buffer, char *datum){
    char neues_datum[6];

    neues_datum[0] = datum[6];
    neues_datum[1] = datum[7];
    neues_datum[2] = datum[3];
    neues_datum[3] = datum[4];
    neues_datum[4] = datum[0];
    neues_datum[5] = datum[1];
    
    for(int i = 0; i < 6; i++){
        buffer[i] = neues_datum[i];
    }
}

int main (void){
    //Variablen definieren
    int anz_kennungen = 0;
    int length = 0;                                             // Keep track of length of each string entered by user
    int string_length;
    char kennung[BUFFER_SIZE], **strings;
    char *token, anfangsbuchstaben[3]; 
    char datum[8];                                              // Original Datum welches wir aus dem String extrahieren             z.B. "15.09.22"
    const char *sign = ":";
    char neues_datum_buffer[6];                                 // In diesem "Buffer" wird später das manipulierte Datum gespeichert z.B. "220915"
    char grosser_buffer[30][100] = {{0}};
    //Eckdaten einlesen
    printf("Anzahl der Nutzerkennungen: ");
    scanf("%d", &anz_kennungen);
    
    strings = malloc(anz_kennungen * sizeof(char *));

    while(getchar() != '\n');

    printf("\n");

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
    printf("\nDeine Kennungen:\n");
    for(int i = 0; i < anz_kennungen; i++){
        printf("Kopiere strings[%d] = %s in grosser_buffer...\n", i , strings[i]);
        string_length = strlen(strings[i]);
        for(int j = 11; (j-11) < string_length; j++){
            grosser_buffer[i][j] = strings[i][j-11];
        }
    }
    
    printf("\nGrosser Buffer:\n");
    for(int i = 0; i < anz_kennungen; i++){
        for(int j = 0; j < 100; j++){
            printf("%c", grosser_buffer[i][j]);
        }
        printf("\n");
    }

    printf("\n");  
    for(int i = 0; i < anz_kennungen; i++){
        int counter = 1;
        token = strtok(strings[i], sign);
        anfangsbuchstaben[0] = token[0];
        while (token != NULL){
            if(counter == 4){
                strcpy(datum, token);
            }
            printf("Token: %s, First: %c\n", token, token[0]);
            anfangsbuchstaben[counter] = token[0];
            token = strtok(NULL, sign);                                  // token wird auf NULL gesetzt
            counter++;
        }
        printf("BuchstabenStr: ");
        for(int j = 0; j < 4; j++){
            printf("%c", anfangsbuchstaben[j]);
        }
        printf("\nDatumStr: ");
        manipuliere_datum(neues_datum_buffer, datum);
        for(int i = 0; i < 6; i++){
            printf("%c", neues_datum_buffer[i]);
        }

        manipuliere_grosser_buffer(grosser_buffer, neues_datum_buffer, anfangsbuchstaben, i);
        printf("\n\n");

    }

    for(int i = 0; i < anz_kennungen; i++){
        for(int j = 0; j < 100; j++){
            printf("%c", grosser_buffer[i][j]);
        }
        printf("\n");
    }

    free(strings);
    return 0;
}
