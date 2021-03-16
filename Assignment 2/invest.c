#include <stdio.h>

int main() {
  float principle, returnRate, contYear, intrest, end;
  int years, countYear;

  do {
    printf("Enter initial investment amount: ");
    scanf("%f", &principle);
    if (principle < 0){
      printf("Please enter an initial investment amount greater than zero, try again\n");
    }
  }
  while (principle < 0);

  do {
    printf("Enter total years: ");
    scanf("%d", &years);
    if (years <= 0){
      printf("Please enter a year greater than zero, try again\n");
    }
  }
  while (years <= 0);

  do {
    printf("Enter return rate: ");
    scanf("%f", &returnRate );
    if (returnRate < 0){
      printf("Please enter a return rate greater than zero, try again\n");
    }
  }
  while (returnRate < 0);

  do {
    printf("Enter additional contribution per year: ");
    scanf("%f", &contYear);
    if (contYear < 0){
      printf("Please enter an additional contribution greater than zero, try again\n");
    }
  }
  while (contYear < 0);
  printf("\n");
  printf("Year      Start Balance       Intrest             End Balance         \n" );
  printf("****************************************\n" );

  for(countYear = 1; countYear <= years; countYear++){
    if (countYear > 1){
      principle = end + contYear;
      intrest = principle * (returnRate/100);
      end = principle + intrest;
    }else{
      intrest = principle * (returnRate/100);
      end = principle + intrest;
    }
    printf("%-10d%-20.2f%-20.2f%-20.2f\n", countYear, principle, intrest, end);
  };
}
