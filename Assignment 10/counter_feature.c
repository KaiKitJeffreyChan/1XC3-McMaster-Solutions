#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024


int max(int count[]);
int min(int count[]);

int main()
{
  char buffer[BUFFER_SIZE], input, curchar;
  int i = 0, count[26];
  int spaces = 0;

  // request and read in the string from the user
  printf("Enter text for analysis: ");
  while ( ((input = getchar()) != '\n') && (i < (BUFFER_SIZE - 1))) {
    buffer[i++] = input;
  }
  buffer[i] = '\0';

  // set the letter counts to zero
  for (i = 0; i < 26; i++) count[i] = 0;

  // Count the occurences of each letter a-z in the string (case insenstive)
  // in the count array with count[0] for 'a', count[1] for 'b' and so on.
  // We ensure the character being examined is an uppercase character with
  // toupper() and then we check if it is in the ASCII range for A-Z (65-90)
  // to determine if we need to increment a count... if it is we increment
  // the right index using 65 as an 'offset'.
  for (i = 0; i < strlen(buffer); i++) {
    curchar = toupper(buffer[i]);
    if (curchar >= 65 && curchar <= 90) count[curchar - 65]++;
    if (curchar == ' ') spaces++;
  }

  // Create the letter analysis table
  printf("\n\nLetter Analysis Complete!");
  printf("\n\nLetter    Occurrences    Percentage\n");
  printf("*****************************************\n");
  for (i = 0; i < 26; i++) {
    printf("%-10c%-15d%-15.2f\n", i + 65,
                               count[i],
                               (((float) count[i]) / strlen(buffer)) * 100);
  }
  printf("\nTotal spaces: %d\n", spaces);


  // Find the max and min occuring character in the string, in particular the
  // position in the count array of each character
  int max_pos = max(count);
  int min_pos = min(count);

  // Output the max and min occuring character, again using 65 as an offset to
  // output the character character given ASCII A-Z range from 65-90
  printf("\nMost frequently occuring character: %c\n",
         max_pos + 65);
  printf("Least frequently occurring character: %c.\n",
         min_pos + 65);

  return 0;
}

// Returns the position in array count of the associated letter that
// occurred the maximum number of times
int max(int count[])
{
  int max = count[0];
  int max_pos = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] > max)
    {
      max_pos = i;
      max = count[i];
    }
  }
  return max_pos;
}

// Returns the position in array count of the associated letter that
// occurred the minimum number of times
int min(int count[])
{
  int min = count[0];
  int min_pos = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] < min)
    {
      min_pos = i;
      min = count[i];
    }
  }
  return min_pos;
}
