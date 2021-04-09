/**
 * @mainpage Program to manage courses and students.
 *
 * Following program contains different types of fucnctions that manage
 * the interactions between students and courses
 *
 * Functions include...
 * - Enrolling student in a course
 * - Find highest graded student within a given course
 * - Find passing students within a course
 * - Find/add average to a student, Generate random students
 *
 *
 * @file main.c
 * @author Jeffrey Chan
 * @date April 1st, 2021.
 * @brief Functions within Course Library
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"


/**
 * Displays the works of the following functions and interactions between students and courses
 * the given example is students within a math course
 *
 * Enrolls students, prints course info, creates students, finds highest score, and amount of passing students
 * @return Program status 0 or 1
 */
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  //create 20 students for this math class
  for (int i = 0; i < 20; i++)
    enroll_student(MATH101, generate_random_student(8));

  print_course(MATH101);

  Student *student;
  //find highest grade student and print their info
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  //for all passing students, print their information
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);

  return 0;
}
