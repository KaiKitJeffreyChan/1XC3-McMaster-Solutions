#include <stdio.h>
#include <string.h>

int occurances (char *sentance, char target);

int main() {
    char c, text[1024], highestChar, lowestChar;
    int counter, highest = 0, lowest = 1024;
    double percentage, len, times;

    printf("Enter text for analysis: ");
    //fgets() to avoid cutting off at spaces
    fgets(text, sizeof(text), stdin);
    printf("\n");
    printf("Letter Analysis Complete!");
    printf("\n\n");
    printf("Letter    Occurrences    Percentage     \n");
    printf("****************************************\n" );
    for (c = 'A'; c <= 'Z'; ++c){
        //need to cast length of string and occurances to double to avoid 0 rounding
        len = (double)(strlen(text));
        times = (occurances(text,c));
        percentage = ((double)times/len)*100;
        //two if statments checks for most/least occuring characters
        if (times > highest){
          highest = times;
          highestChar = c;
        }
        if (times < lowest){
          lowest = times;
          lowestChar = c;
        }
        // Occurances function is called for second column --> returns an int
        // Third column is number of occurances divided by total number of characters
        printf("%-10c%-15d%-15.2f\n", c, occurances(text,c), percentage);
    }
    printf("The most frequently occurring character is %c\n", highestChar);
    printf("The least frequently occurring character is %c\n", lowestChar);
}
// Function that counts the number of times each character is present within sentence
int occurances (char *sentance, char target){
  //Add 32 to capital character to get lowercase
  int i, loop, amount = 0, lowercase = (target + 32);
  //Loops through sentence to find if current selected character is present
  for(i = 0; i < strlen(sentance); i++){
    if ((sentance[i]) == target){
      amount++;
    } else if((sentance[i]) == lowercase){
      amount++;
    }
  }
  return amount;
}
