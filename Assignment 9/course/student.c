/**
*
* @file student.c
* @author Jeffrey Chan
* @date April 1st, 2021.
* @brief Functions within Course Library
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
 * Adds a grade to the corresponding student
 * @param student is a pointer to the student whos
 * @param grade is the grade assigned to the student
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;//increments number of grades

  //allocates space for one grade if its the first
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else
  {
    //if not the first student, reallocate space for an additinal grade

    student->grades =
      realloc(student->grades, sizeof(double) * student->num_grades); /**< realloc used to change size of dynamically allocated memory*/
  }
  student->grades[student->num_grades - 1] = grade;
}

/**
 * finds the average of a given student
 * @param student is a pointer to the student whos average is looked for
 * @return average of students grades
 */
double average(Student* student)
{
  //if student has no grades, their grade is 0
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i]; /**< loops over all grades to calculated average */
  return total / ((double) student->num_grades);
}

/**
 * Prints name, id, grade, and average of a single student
 * @param student is a pointer to the student being looked at
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) /**< loops over all students to print info */
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student)); /**< uses fucntion previously defined to return average */
}

/**
 * Generates a new student random information
 * @param grades is the number of grades student will have
 * @return pointer to student struct
 */
Student* generate_random_student(int grades)
{
  //possible first names
  char first_names[][24] =
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  //possible last names
  char last_names[][24] =
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams",
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat",
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};

  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]); /**< creates student with random first name */
  strcpy(new_student->last_name, last_names[rand() % 24]); /**< sets same student with random first name */

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48); /**< creates a random ID for same student*/
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) /**< creates random grade for student */
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}
