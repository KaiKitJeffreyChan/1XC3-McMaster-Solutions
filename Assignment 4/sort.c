#include <stdio.h>
#include <stdlib.h>

int main() {
double* nums;
int j, size, counter;
double temp;

    //input for number of elements in array
    printf("Please enter the number of elements you would like to sort: ");
    scanf("%d", &size);

    //dynamic memory allocation
    nums = calloc(size, sizeof(double));

    //getting input for specified number of elements
    for(counter = 0; counter < size; counter++){
      printf("Enter element %d: ", counter);
      scanf("%lf", &nums[counter]);
    }

    //print unsorted array
    printf("\nUnsorted array: \n");
    for(counter = 0; counter < size; counter++){
      printf("%.2lf  ", nums[counter]);
    }

    //insertion sort
    for(counter = 0; counter < size; counter++){
      j = counter;
      while (j > 0 && nums[j-1] < nums[j]){
        temp = nums[j-1];
        nums[j-1] = nums[j];
        nums[j] = temp;
        j--;
      }
    }

    //print the sorted array
    printf("\n\nSorted array: \n");
    for(counter = 0; counter < size; counter++){
      printf("%.2lf  ", nums[counter]);
    }

    //free allocation
    free(nums);
}
