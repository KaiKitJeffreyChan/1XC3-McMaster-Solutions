//Jeffrey Chan

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.14159265358979323846

double square_area(double side_length) { return (side_length * side_length); }
double volume_sphere(double radius) { return(PI * 4/3 * radius * radius * radius); }
double surface_area(double edge) { return( (edge*edge)*6 ); }

int main() {

  int options;
  double side_length, radius, edge;
  bool leave = true;

  do{
    printf("1) Compute the area of a square\n");
    printf("2) Compute the volume of a sphere\n");
    printf("3) Compute the surface area of a cube\n");
    printf("4) Quit\n");
    printf("Enter an option: ");
    scanf("%d", &options);
    printf("\n");

    switch (options) {
      case 1:
        do {
          printf("Enter side length of square (cm): ");
          scanf("%lf", &side_length);
          if (side_length < 0){
            printf("Please enter positive side length\n");
          }
        } while(side_length < 0);
        printf("Area of square: %.2lf (cm^2)", square_area(side_length));
        printf("\n\n");
        break;

      case 2:
        do {
          printf("Enter the radius (cm): ");
          scanf("%lf", &radius);
          if (radius < 0){
            printf("Please enter positive radius length\n");
          }
        } while(radius < 0);
        printf("volume of sphere: %.2lf (cm^3)", volume_sphere(radius));
        printf("\n\n");
        break;

      case 3:
        do {
          printf("Enter the edge of the cube (cm): ");
          scanf("%lf", &edge);
          if (edge < 0){
            printf("Please enter positive edge length\n");
          }
        } while(edge < 0);
        printf("Surface area of the cube: %.2lf (cm^2)", surface_area(edge));
        printf("\n\n");
        break;

      case 4:
        printf("Goodbye!");
        leave = false;
    }
  }while(leave);
}
