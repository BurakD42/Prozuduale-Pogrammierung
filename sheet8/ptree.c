#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//Konstanten definieren
#ifndef M_PI
#  define M_PI 3.1415926535897932
#endif

#define NUM_COLORS 10
char colors[NUM_COLORS][10] = {"black", "brown", "grey", "yellow", "cyan", "pink", "orange", "green", "blue", "red"};

// Funktion: Zeichnen eines Rechteckes
void zeichne_quadrat(FILE *fp, double x_koordinate, double y_koordinate, double seitenlaenge, double rotation, double rx, double ry, char *color){
  fprintf(fp, "<rect x='%lf' y='%lf' width='%lf' height='%lf' transform='rotate(%lf %lf %lf)' style='fill:%s; stroke-width:0;' />\n",x_koordinate , y_koordinate, seitenlaenge, seitenlaenge, rotation, rx, ry, color);
}
// Funktion: Berechnung der Eckpunkte/Referenzpunkte
void berechne_eckpunkte_rotation_seitenlaenge(double side, double rot, double drot, double x, double y, double *new_x_L, double *new_y_L, double *new_rot_L, double *side_l, double *new_x_R, double *new_y_R, double *new_rot_R, double *side_r){
                                                                    // Werte fuer die Erste Iteration:
  *new_x_L = x - side * sin((rot * M_PI) / 180);                    // 0
  *new_y_L = y + side * cos((rot * M_PI) / 180);                    // 20
  *new_rot_L = rot + drot;                                          // 26.565051
  *side_l = cos((drot * M_PI) / 180) * side;                        // 17.88854385

  *new_x_R = *new_x_L + cos((*new_rot_L * M_PI) / 180) * *side_l;   // 16   
  *new_y_R = *new_y_L + sin((*new_rot_L * M_PI) / 180) * *side_l;   // 28
  *new_rot_R = ((((rot * M_PI) / 180) + ((drot * M_PI) / 180) - M_PI / 2) * 180) / M_PI;        // -24.994255     // ToDo
  *side_r = sin((drot * M_PI) / 180) * side;                        // 8.944271855

  return;
}

// weitere Funktionen, falls nötig
void draw_pythagoras_tree(FILE *fp, double x, double y, double side, double rot, double drot, int depth, int index) {
  double new_x_L, new_y_L, new_rot_L, side_l, new_x_R, new_y_R, new_rot_R, side_r;
  // Draw the current square
  

  berechne_eckpunkte_rotation_seitenlaenge(side, rot, drot, x, y, &new_x_L, &new_y_L, &new_rot_L, &side_l, &new_x_R, &new_y_R, &new_rot_R, &side_r);
  
  zeichne_quadrat(fp, x, y, side, rot, x, y, colors[depth % NUM_COLORS]);

  // Check if the current depth is less than the desired depth
  if (depth > 0) {
    // Call the function recursively to draw the next two squares
    draw_pythagoras_tree(fp, new_x_L, new_y_L, side_l, new_rot_L, drot, depth-1, 2*index);

    draw_pythagoras_tree(fp, new_x_R, new_y_R, side_r, new_rot_R, drot, depth-1, 2*index+1);
  }
}

/*
Main-Funktion
*/

int main(int argc, char* argv[])
{
  // Check if a depth argument was provided
  if (argc < 2){
    printf("Usage: %s depth\n", argv[0]);
    return 1;
  }

  // Parse the depth argument
  int depth = atoi(argv[1]);

  //Initialisierung
  double x = 0.0;
  double y = -50.0;
  double side = 20.0;
  double rot = 0.0;
  double drot = 26.565051;

  FILE * fp; //Zeiger vom Typ FILE -> Zur Verarbeitung von Dateien

  fp = fopen("svg_test.svg","w");
  if (fp == NULL) {
    // Handle the error
    // ...
    printf("File not opened correctly");
    return 1; // Return an error code
  }
  fprintf(fp, "<?xml version='1.0' encoding='UTF-8'?>\n"
    "<svg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' version='1.1' width='100%%' height='100%%' viewBox='-50 -50 100 100' transform='scale(1 -1)'>\n"
    "  <title>Exampel</title>\n");

  //Pythagorasbaum -> im SVG-Format
  draw_pythagoras_tree(fp, x, y, side, rot, drot, depth, 0);

  fprintf(fp, "</svg>\n");
  fclose(fp);
  return 0;
}
