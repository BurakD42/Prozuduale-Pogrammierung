#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char string[8];
    
    /**
     * Die scanf Function fordert den User auf einen String/Integer/Character einzugeben
     * und erwartet dafür einen Bezeichner (%d/%s/%c...) als String und anschließend eine Variable
     * in welcher die Eingabe gespeichert werden kann.
     */
    printf("Geben Sie Ihren Gruppennamen ein: ");
    scanf("%s", &string[0]);

    printf("Hello World \n%s", string);                     // Erwartet einen String bzw. ein Array aus Charactern als Input und gibt diesen in der Konsole aus
    return 0;
}
