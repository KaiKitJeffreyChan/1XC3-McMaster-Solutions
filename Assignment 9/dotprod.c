#include <stdio.h>

int dot_product_fast(int A[], int B[]);
int dot_product_slow(int A[], int B[], int length);

int main(int argc, char *argv[])
{
  int A[3] = {4,5,6};
  int B[3] = {7,8,9};
  int result = 0;

  for (int i = 0; i < 1000000000; i++)
  {
    result = dot_product_fast(A, B);
  }
}

//unrolled loop that calculated dotproduct of two matricies 1x3
int dot_product_fast(int A[], int B[])
{
  return ((A[0] * B[0]) + (A[1] * B[1]) + (A[2] * B[2]));
}

int dot_product_slow(int A[], int B[], int length)
{
  int result = 0;
  for (int i = 0; i < length; i++)
  {
    result += A[i] * B[i];
  }
  return result;
}
