#include <stdio.h>
//sonstige Header
#include <stdlib.h>
#include <math.h>

//Konstanten definieren
#define POLY_DEG 4
//Funktionen
float dpoly1(float array[5], float x){
  float res = 0;
  for(unsigned i = 1; i <= POLY_DEG; i++){
    res += (i * array[i] * pow(x, (i-1)));
  }
  return res;
}

float dpoly2(float array[5], float x){
  float res = 0;
  for(unsigned i = 2; i <= POLY_DEG; i++){
    res += i * (i - 1) * array[i] * pow(x, i-2);
  }
  return res;
}

float bisection(float a, float b){
  float nullstelle, temp1, temp2, abbruch = 0.00002, x_m;
  temp1 = (3.f/2.f)+pow(a, 3)-(3.f)*pow(a, 2)-(1.f/10.f);
  temp2 = (3.f/2.f)+pow(b, 3)-(3.f)*pow(b, 2)-(1.f/10.f);

  if((temp1 >= 0 && temp2 >= 0) || (temp1 < 0 && temp2 < 0)){
    printf("\nIntervall falsch gewaehlt");
    return 0;
  }

  while(abbruch > 0.00001){
    x_m = (a + b) / 2;

    temp1 = (3.f/2.f)+pow(a, 3)-(3.f)*pow(a, 2)-(1.f/10.f);
    temp2 = (3.f/2.f)+pow(x_m, 3)-(3.f)*pow(x_m, 2)-(1.f/10.f);

    // Waehle Teilintervall in dem Funktionswerte unterschiedliche Vorzeichen haben
    if((temp1 >= 0 && temp2 >= 0) || (temp1 < 0 && temp2 < 0)){
      a = x_m;
      b = b; 
    }else{
      a = a;
      b = x_m;
    }

    abbruch = b - a;
  }

  nullstelle = (a + b)/2;
  return nullstelle;
}

void dpoly(float *array, float degree, float nullst){
  float res = 0;
  
  // Checke input
  if(!array){
    printf("Input der Koeffizienten war nicht korrekt");
    return;
  }

  // Berechnen der Koeffizienten der Ableitung
  float *ableitung = (float *)malloc(degree * sizeof(float));
  for(int i = 0; i < degree; i++){
    ableitung[i] = array[i] * (degree - i);
  }

  // Gebe die Ableitung visuell aus
  printf("\nArray: ");
  for (int i = 0; i < degree; i++)
  {
      printf("%f ", ableitung[i]);
  }
  
  printf("\n\nDurch dpoly() berechnete\nAbleitung: f'(x) = ");
  for(int i = 0; i < degree; i++){
    printf("%.3f", ableitung[i]);
    if(i < degree-1){
      printf("*x^%.0f + ", degree-(i+1));
    }
  }
  printf("\nFunktionswert: f'(%f) = ", nullst);
  for(int i = 0; i < degree-1; i++){
    res += ableitung[i] * pow(nullst, degree-(i+1));
  }
  res += ableitung[((int)degree)-1];
  printf("%f", res);

  free(ableitung);

}

//Hauptprogramm
int main(void)
{
  float a, a_backup, b, b_backup, x_m, temp1, temp2, temp3, temp4, abbruch = 1, nullstelle, extremwert;

  printf("Geben Sie ihre Intervall Grenzen ein:\nWert fuer a: ");
  scanf("%f", &a);
  printf("\nWert fuer b: ");
  scanf("%f", &b);
  
  a_backup = a;
  b_backup = b;

  temp1 = (3/8)*pow(a, 4)-pow(a, 3)-(1/10)*a+2;
  temp2 = (3/8)*pow(b, 4)-pow(b, 3)-(1/10)*b+2;
  printf("\nf(a): f(%f) = %f", a, temp1);
  printf("\nf(b): f(%f) = %f", b, temp2);

  if((temp1 >= 0 && temp2 >= 0) || (temp1 < 0 && temp2 < 0)){
    printf("\nIntervall falsch gewaehlt");
    return 0;
  }

  printf("\nIhr momentanes Intervall: [%f, %f]", a, b);

  while(abbruch > 0.001){
    x_m = (a + b) / 2;

    printf("\n  Teilintervall 1: [%f, %f]", a, x_m);
    printf("\n  Teilintervall 2: [%f, %f]", x_m, b);

    printf("\n    Funktionswerte an den Grenzen von Teilintervall 1:");
    temp1 = (3/8)*pow(a, 4)-pow(a, 3)-(1/10)*a+2;
    temp2 = (3/8)*pow(x_m, 4)-pow(x_m, 3)-(1/10)*x_m+2;
    printf("\n    f(a): f(%f) = %f", a, temp1);
    printf("\n    f(x_m): f(%f) = %f", x_m, temp2);
    
    printf("\n    Funktionswerte an den Grenzen von Teilintervall 2:");
    temp3 = (3/8)*pow(x_m, 4)-pow(x_m, 3)-(1/10)*x_m+2;
    temp4 = (3/8)*pow(b, 4)-pow(b, 3)-(1/10)*b+2;
    printf("\n    f(x_m): f(%f) = %f", a, temp3);
    printf("\n    f(b): f(%f) = %f", x_m, temp4);

    // Waehle Teilintervall in dem Funktionswerte unterschiedliche Vorzeichen haben
    if((temp1 >= 0 && temp2 >= 0) || (temp1 < 0 && temp2 < 0)){
      a = x_m;
      b = b; 
    }else{
      a = a;
      b = x_m;
    }

    printf("\nIhr momentanes Intervall: [%f, %f]", a, b);
    abbruch = b - a;
  }

  printf("\na: %f\nb: %f\n\n", a, b);

  float x = b; // b = Ergebnis des Bisektionsverfahrens
  float array[5] = {2, -(1.f/10.f), 0, -1, (3.f/8.f)};          
  float y_1 = dpoly1(array, x);
  printf("\nf'(%f)  = %f", b, y_1);

  float y_2 = dpoly2(array, x);
  printf("\nf''(%f) = %f", b, y_2);
  
  // Berechne Nulstelle der ersten Ableitung
  nullstelle = bisection(a_backup, b_backup);
  printf("\n\nNustelle der zweiten Ableitung: %f", nullstelle);

  // 
  extremwert = dpoly2(array, nullstelle);
  printf("\n\nIhr Extremwert: f''(%f) = %f", nullstelle, extremwert);
  if(extremwert > 0){
    printf("\nEs handelt sich um ein Minimum");
  }else{
    printf("\nEs handelt sich um ein Maximum");
  }

  float coeffs[] = {(3.f/8.f), -1, 0, -(1.f/10.f), 2};
  dpoly(coeffs, 4, x);

  return 0;
}
