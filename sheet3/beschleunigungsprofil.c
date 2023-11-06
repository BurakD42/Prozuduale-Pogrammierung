#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    /*
    1. Beschleunigungsprofil
    */ 
    //Eingabe/Ausgabe Parameter
    float p_0, p_1, p_2;
        printf("Geben Sie Parameter p_2, p_1, p_0 in dieser Reihenfolge ein:\n");
        scanf("%f%f%f", &p_2, &p_1, &p_0);
        printf("a(t) = %f*t^2 + %f*t^1 + %f\n", p_2, p_1, p_0);
    //Berechnung der Beschleunigungen zu bestimmten Zeitpunkten    
    float a_t_0, t_0 = 0, a_t_1, t_1 = 3;
        a_t_0 = p_2*pow(t_0, 2) + p_1*t_0 + p_0;
        a_t_1 = p_2*pow(t_1, 2) + p_1*t_1 + p_0;
        printf("a_t_0: %f, a_t_1: %f\n", a_t_0, a_t_1);
    //Berechnung der Maximalbeschleunigung -> Überprüfen auf Maximum
        printf("Erste Ableitung: a'(t) = -t + 2\nZweite Ableitung: a''(t) = -1\n"); //Zweite Ableitung ist -1 und somit kleiner als 0 -> Rechts Krümmung
    int t_max = 2;
        printf("Durch die notwendige Bedingung erhalten wir t_max = %.2f s\n", t_max);
        printf("Durch die hinreichende Bedingung wissen wir dass es sich um ein Maximum handelt\n");
    float a_t_max = p_2*pow(t_max, 2) + p_1*t_max + p_0;
        printf("Durch das einsetzen von t_max erhalten wir eine maximale Beschleunigung von: %.2f ms^-2\n", a_t_max); 

    /*
    2. Der Weg ist das Ziel 
    */
    // Berechnung der Zeit t2 -> sqrt(x) 
    printf("Durch das einsetzen von 0,5 ms^-2 und das anschliessende umwandeln in die pq-Form erhalten wir die Gleichung t^2-4t-1 = 0\n");
    float r1, r2, t_2;
        r1 = -(-4 / 2) + sqrt(pow((4 / 2), 2) + 1);
        r2 = -(-4 / 2) - sqrt(pow((4 / 2), 2) + 1);
        t_2 = r1;
    printf("r1: %f, r2: %f -> Also ist t_2 = %0.2f s\n", r1, r2, t_2);
    // Berechnung der Geschwindigkeit zum Endzeitpunkt te = 20s
    float v_0 = 20, t_e = 20, v_t_e, t;
        t = t_e - t_2;
        v_t_e = 0.5 * t + v_0;
        printf("v(t_e) = a * t + v_0 = 0.5 * %f + %f = %0.2f ms^-2\n", t, v_0, v_t_e);
    // Berechnung des zurückgelegten Weges
    float s_0 = a_t_max, s_t;
    s_t = (1/2) * 0.5 * pow(t, 2) + v_0 * t + s_0;
    printf("s(t) = (1/2) * a * t^2 + v_0 * t + s_0 = (1/2) * 0.5 * %f + %f * %f + %f = %0.2f m\n", pow(t,2), v_0, t, s_0, s_t);
    return 0;
}