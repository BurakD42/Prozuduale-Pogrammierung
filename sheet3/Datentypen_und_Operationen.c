#include <stdio.h>
#include <stdlib.h>

int main(void){
    // First Part
    /*
     * Datentypen werden nicht verändert. 
     * Entspricht das eigentliche Ergebnis jedoch nicht dem Format der Datentyps, wird das Ergebnis entsprechend angepasst.
     */
    int a = 1 + 2 / 3.5;            // Umwandlung des Ergebnisses in ein integer -> 0,83 wird aufgerundet -> 1
    printf("a: %d\n", a);
    double b = 1 + 2 / 3e5;
    printf("b: %lf\n", b);
    float c = 1 * 5 / 2;            // Rechnung wird mit integern durchgefuehrt -> Ergebnis: 2 (da keine nachkommastellen) -> Bei der Zuweisung wird das Ergebnis in ein float umgewandelt -> 2.00000
    printf("c: %f\n", c);
    int d = 6 / 5 * 2 - 10;         // Umwandlung des Ergebnisses in ein integer -> -7,6 wird aufgerundet -> -8
    printf("d: %d\n", d);
    int e = 6 / (5 * 2)- 10;        // Umwandlung des Ergebnisses in ein integer -> -9,4 wird aufgerundet -> -10
    printf("e: %d", e);
    //int f = 6 / (5 * 2 - 10);     // Division mit 0 -> Keine Zuweisung -> Programm bricht ab
    //printf("f: %d", f);

    // Second Part
    short int a_16, b_16, c_16;             // Max Value: 32767
    int a_32, b_32, c_32;                   // Max Value: 2147483647
    unsigned short int a_u16, b_u16, c_u16; // Max Value: 65535

    /*
    a_u16 = 1130 da ein u_short_int einen max Wert von 65535 haben kann.
    a_16 + a_32 + b_32 ergibt jedoch 66666 weshalb es zu einem overflow kommt und
    der Wert nach 65535 wieder bei 0 anfängt. Also quasi 66666 - 65535 = 1130
    */
    b_16 = a_16 = 22222;
    b_32 = a_32 = 22222;
    c_32 = a_32 + b_32;
    a_u16 = a_16 + a_32 + b_32;

    a_u16 = 2222;
    b_u16 = 222;
    c_u16 = a_u16 - b_u16;
    b_u16 = -222;                           // 65535 - 222 = 65314
    c_u16 = a_u16 + b_u16;                  // a_u16 + b_u16 = 2222 + 65314 = 2000 --> Weil der max Wert überschritten Wert und wieder von 0 angefangen wird

    a_32 = 555;
    b_32 = 1001;
    c_16 = c_32 = a_32 * b_32;              // c_32 = 308025, c_16 = 31267 -> c_16 macht mehrere Wrap arounds. Kein Plan wie viele
    c_32 = c_16 = a_32 * b_32;              // c_16 = 31267, c_32 = 31267
    return 0;
}
