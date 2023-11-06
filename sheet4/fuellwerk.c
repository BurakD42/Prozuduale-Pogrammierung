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

float calc_mittelwert(float *array){
    float my_mittelwert = 0.0;
    for (int i = 1; i < 11; i++){
                my_mittelwert += array[i];
            }
            my_mittelwert /= 10;
    return my_mittelwert;
}

int main(void) 
{
    /*
    Aktivierung des Start-Schalter
    */
    bool waage;
    bool start = false;
    char userInput[1], userInput_2[1];

    printf("Wollen Sie das Fuellwerk starten? (Y/N): ");
    scanf("%s", &userInput[0]);
    if(userInput[0] == 'Y'){
        start = true;
    }
    if (start == false){
        printf("Fuellwerk ist nicht im Betrieb\n");
        main();
    }else if(start == true){
        printf("Startschalter aktiviert\n");
    
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
            int counter = 1;
            float behaelter[11] = {0}, mittelwert;
            bool alle_becher_gefuellt = false;
            srand(time(NULL));
            char neustart[1];
    /*
    Befüllen der Schüttgutbehälter
    - Verwenden von while- und do-while-Schleifen zum Befüllen und Ablassen des Schüttgut
    - Verwenden einer for-Schleife, um insgesamt 10 Behälter zu befüllen
    */    
            for(int j = 0; j < 10; j++){
                if(behaelter[j] >= 50.0 && behaelter[j] <= 55.0){
                    printf("%0.1fkg ", behaelter[j]);
                    alle_becher_gefuellt = true;
                }else{
                    printf("%0.1fkg ", behaelter[j]);
                    alle_becher_gefuellt = false;
                }
            }
            if(alle_becher_gefuellt == true){
                mittelwert = calc_mittelwert(behaelter);
                printf("Mittelwert: %0.1fkg", mittelwert);            
            }

            //Wenn dieser Punkt erreicht wird, sind noch nicht alle Behälter befüllt
            for(int i = 1; i < 11; i++){
                while(behaelter[i] < 50.0){
                    printf("\nDurchlauf: %d", counter);
                    printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
                    if(behaelter[i] < 50.0){
                        printf("\n  Klappe wird geoeffnet");
                        behaelter[i] += (((float)rand()) / ((float)RAND_MAX) * 10);
                        if(waage){
                            genaue_waage(i, behaelter);
                        }else{
                            printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
                        }
                    }
                    if(behaelter[i] > 55.0){
                        printf("\nGewicht ueberschritten, Ablassstutzen wird geoeffnet");
                        behaelter[i] -= (((float)rand()) / ((float)RAND_MAX) * 5);
                        if(waage){
                            genaue_waage(i, behaelter);
                        }else{
                            printf("\n  Wiege Gewicht von Behaelter %d...\n     Gewicht betraegt: %0.1fkg", i, behaelter[i]);
                        }
                    }
                    counter++;
                }
                if(behaelter[i] > 55.0){
                    do{
                        printf("\nDurchlauf: %d", counter);
                        printf("\n  Gewicht ueberschritten, Ablassstutzen wird geoeffnet");
                        behaelter[i] -= (((float)rand()) / ((float)RAND_MAX) * 5);
                        printf("\n      Neues Gewicht von Behaelter %d: %0.1fkg", i, behaelter[i]);
                        counter++;
                    }
                    while(behaelter[i] > 55.0);
                }
            }

    /*
    Prozess abschließen -> Ausgabe im Terminal*/    
        printf("\n\nAlle Behaelter wurden befuellt:\n");
        for(int i = 1; i < 11; i++){
            printf("|%0.1fkg| ", behaelter[i]);
        }
        mittelwert = calc_mittelwert(behaelter);
        printf("\nMittelwert: %0.1fkg", mittelwert);  
        
        printf("\nWollen Sie das Fuellwerk neustarten? (Y/N): ");
        scanf("%s", &neustart[0]);
        if(neustart[0] == 'Y'){
            main();
        }
    }
    return 0;
}