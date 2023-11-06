#include <stdio.h>
#include <stdbool.h>
//Einbinden der Header stdlib.h und time.h
#include <stdlib.h>
#include <time.h>

float genaue_waage(int behaelter_no, float *array){
    float startgewicht = 0.0;
    printf("\nWiege Gewicht von Behaelter %d...", behaelter_no);
    printf("\n%0.1fkg...", startgewicht);
    while (startgewicht < array[behaelter_no]){
        startgewicht += 0.1;
        if(startgewicht < array[behaelter_no]){
            printf("\n%0.1fkg...", startgewicht);
        }
    }
    printf("\nGewicht betraegt: %0.1fkg", array[behaelter_no]);
    return 0;
}

bool abtransport(int behaelter_no, float *array, float transporter_max){
    bool ueberstiegen = false;
    printf("\n              Statusmeldung: Abtransport von Behaelter %d erfolgt...\n", behaelter_no);
    if(array[behaelter_no] > transporter_max){
        printf("\n              Gewicht des Behaelters (%0.2fkg) uebersteigt das Gewichtslimit (%0.0fkg) des Transporters... Gewicht des Behaelters wird angepasst...", array[behaelter_no], transporter_max);
        ueberstiegen = true;
    }else{
        printf("\n              Transport abgeschlossen!", array[behaelter_no], transporter_max);
    }
    return ueberstiegen;
}

void befuelle_behaelter(int i, float *behaelter, int zielgewicht_min, int zielgewicht_max, int *counter, int m_in, int m_out, bool waage){
    while(behaelter[i] < zielgewicht_min){
            printf("\nDurchlauf: %d", *counter);
            printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
            if(behaelter[i] < zielgewicht_min){
                printf("\n  Klappe wird geoeffnet");
                behaelter[i] += (((float)rand()) / ((float)RAND_MAX) * m_in);
                if(waage){
                    genaue_waage(i, behaelter);
                }else{
                    printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
                }
            }
            if(behaelter[i] > zielgewicht_max){
                printf("\nGewicht ueberschritten, Ablassstutzen wird geoeffnet");
                behaelter[i] -= (((float)rand()) / ((float)RAND_MAX) * m_out);
                if(waage){
                    genaue_waage(i, behaelter);
                }else{
                    printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
                }
            }
            *counter = *counter + 1;
        }
        if(behaelter[i] > zielgewicht_max){
            do{
                printf("\nDurchlauf: %d", *counter);
                printf("\n  Gewicht ueberschritten, Ablassstutzen wird geoeffnet");
                behaelter[i] -= (((float)rand()) / ((float)RAND_MAX) * 5);
                printf("\n      Neues Gewicht von Behaelter %d: %0.1fkg", i, behaelter[i]);
                *counter = *counter + 1;;
            }
            while(behaelter[i] > zielgewicht_max);
        }
        // return behaelter[i];
}

float calc_mittelwert(float *array, int anz_behaelter){
    float my_mittelwert = 0.0;
    for (int i = 1; i < (anz_behaelter+1); i++){
                my_mittelwert += array[i];
            }
            my_mittelwert /= anz_behaelter;
    return my_mittelwert;
}

int main(void) 
{
    /*
    Aktivierung des Start-Schalter
    */
    float *behaelter, mittelwert, zielgewicht_max, zielgewicht_min, transporter_max;
    bool waage;
    bool start = false;
    char userInput[1], userInput_2[1];
    int anz_behaelter, m_in, m_out;

    printf("Wollen Sie das Fuellwerk starten? (Y/N): ");
    scanf("%s", &userInput[0]);
    if(userInput[0] == 'Y'){
        start = true;
    }
    if (start == false){
        printf("Fuellwerk ist nicht im Betrieb\n");
        main();
    }
    printf("Startschalter aktiviert\n");

    printf("Geben Sie die Anzahl der zu befuellenden Behaelter ein: ");
    scanf("%d", &anz_behaelter);
    behaelter = malloc(anz_behaelter * sizeof(int));
    if(NULL == behaelter){
        printf("Fehler bei Speicherreservierung");
        return EXIT_FAILURE;
    }
    int i = 1;
    while(i <= anz_behaelter){
        behaelter[i] = 0;
        i++;
    }

    for(int i = 1; i < (anz_behaelter+1); i++){
        printf("Behaelter %d: %fkg ", i, behaelter[i]);
    }

    printf("\nGeben Sie ein Intervall fuer das Zielgewicht fuer die Behaelter ein:\nMin: ");
    scanf("%f", &zielgewicht_min);
    printf("Max: ");
    scanf("%f", &zielgewicht_max);

    printf("\nGeben Sie einen Wert fuer m_in ein: ");
    scanf("%d", &m_in);
    printf("\nGeben Sie einen Wert fuer m_out ein: ");
    scanf("%d", &m_out);

    printf("\nWie viel Gewicht kann der Transporter maximal mitnehmen?: ");
    scanf("%f", &transporter_max);

    printf("\nWollen Sie die Waage aktivieren? (Y/N): ");
    scanf("%s", &userInput_2[0]);
    if(userInput_2[0] == 'Y'){
        printf("\nWaage wurde aktiviert");
        waage = true;
    }else{
        printf("\nWaage nicht aktiviert");
        waage = false;
    }
    /*
    Variablen initialisieren */
    int variable;
    int *counter = &variable; 
    *counter = 1;
    float behaelter_gewicht;
    bool alle_becher_gefuellt = false, ueberstiegen;
    srand(time(NULL));
    char neustart[1];
    /*
    Befüllen der Schüttgutbehälter
    - Verwenden von while- und do-while-Schleifen zum Befüllen und Ablassen des Schüttgut
    - Verwenden einer for-Schleife, um insgesamt n Behälter zu befüllen
    */    
    for(int j = 0; j < (anz_behaelter-1); j++){
        if(behaelter[j] >= zielgewicht_min && behaelter[j] <= zielgewicht_max){
            printf("\n%0.1fkg ", behaelter[j]);
            alle_becher_gefuellt = true;
        }else{
            printf("\n%0.1fkg ", behaelter[j]);
            alle_becher_gefuellt = false;
        }
    }
    if(alle_becher_gefuellt == true){
        mittelwert = calc_mittelwert(behaelter, anz_behaelter);
        printf("Mittelwert: %0.1fkg", mittelwert);            
    }

    //Wenn dieser Punkt erreicht wird, sind noch nicht alle Behälter befüllt
    for(int i = 1; i < (anz_behaelter+1); i++){
        while(true){
            befuelle_behaelter(i, behaelter, zielgewicht_min, zielgewicht_max, counter, m_in, m_out, waage);

            ueberstiegen = abtransport(i, behaelter, transporter_max);
            if(ueberstiegen == false){
                break;
            }
            behaelter[i] = 0;
        }
    }

    /*
    Prozess abschließen -> Ausgabe im Terminal*/    
    printf("\n\nAlle Behaelter wurden befuellt:\n");
    for(int i = 1; i < anz_behaelter+1; i++){
        printf("|%0.1fkg| ", behaelter[i]);
    }
    mittelwert = calc_mittelwert(behaelter, anz_behaelter);
    printf("\nMittelwert: %0.1fkg", mittelwert);  
    
    printf("\nWollen Sie das Fuellwerk neustarten? (Y/N): ");
    scanf("%s", &neustart[0]);
    if(neustart[0] == 'Y'){
        main();
    }
    
    free(behaelter);
    return 0;
}