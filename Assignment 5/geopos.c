#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

 //Defines position type with latitude and longitude
typedef struct pos {
  double latitude, longitude;
} Pos;

struct pos create_position();
void print_position(Pos* all_places, int size);
void selection_sort(Pos* all_places, int size);

int main(){
  bool stay = true;
  int size = 1, i;
  char cont;
  Pos* all_places;
  all_places = calloc(size, sizeof(Pos)); //dynamic allocation
  all_places[(size-1)] = create_position();
  do {
    printf("Enter another geographic position(y/n): ");
    while (getchar() != '\n'); //removes newline character from buffer
    scanf("%c", &cont);  // check input(y/n) in comparision to ascii value
    if ((int)cont == 121){
      size++;
      all_places = realloc(all_places, size * sizeof(Pos));  //reallocate space for new position
      all_places[(size-1)] = create_position();  //add new position to dynamically allocated array
    }else if((int)cont == 110){
      stay = false;
    }
  } while(stay);
  //print positions before and after selection sort
  printf("\nPositions");
  print_position(all_places, size);
  selection_sort(all_places, size);
  printf("\nPositions");
  print_position(all_places, size);
  free(all_places); //free allocation
}

//function creates a new Position -> takes two inputs returns pos struct
struct pos create_position(){
  struct pos position;
  double latitude, longitude;
  printf("Enter latitude: ");
  scanf("%lf", &position.latitude);
  printf("Enter longitude: ");
  scanf("%lf", &position.longitude);

  return position;
}

//function prints out latitudes and longitudes
void print_position(Pos* all_places, int size){
  int i;
  printf("\n");
  for (i = 0; i < size; i++)
    printf("%.6lf,  %.6lf\n", all_places[i].latitude, all_places[i].longitude);
}

//function sorts dynamically allocated array with selection sort
void selection_sort(Pos* all_places, int size){
  int i, j, index;
  Pos temp;

  for (i = 0; i < (size-1); i++){
    index = i;
    for (j = (i+1); j < size; j++){
      if(all_places[j].latitude > all_places[index].latitude)
        index = j;
    }

  // swap latitudes and longitudes
  temp = all_places[index];
  all_places[index] = all_places[i];
  all_places[i] = temp;
  }
}
