/**
*
* @file course.c
* @author Jeffrey Chan
* @date April 1st, 2021.
* @brief Functions within Course Library
*
*/

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Enrolls student into a course
 * @param course is a pointer desired course
 * @param student is a pointer to the student being enrolled
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++; //increments course count

  //allocates space for one student if its the first
  if (course->total_students == 1)
  {
    course->students = calloc(1, sizeof(Student));
  }
  //if not the first student, reallocate space for an additinal student
  else
  {
    course->students = realloc(course->students, course->total_students * sizeof(Student)); /**< realloc used to change size of dynamically allocated memory*/
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * Prints name, code, total students, and the students for a course
 * @param course is a pointer for which the information will be about
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) /**< loops over all students to produce information*/
    print_student(&course->students[i]);
}

/**
 * finds student with the highest average in a given course
 * @param course is a pointer for which course will be looked at
 * @return pointer to student with the highest average in the course
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;

  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];

  for (int i = 1; i < course->total_students; i++)/**< loops all students in the class and continously sets pointer to different students until the student with highest average is picked*/
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average)
    {
      //swap max and curr average
      max_average = student_average;
      student = &course->students[i];
    }
  }

  return student;
}

/**
 * Gives the students passing in the course
 * @param course is a pointer for which course will be looked at
 * @param total_passing pointer to the number of passing students
 * @return student pointer to array of passing students
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;

  for (int i = 0; i < course->total_students; i++) /**< loops over all students and counts passing students */
    if (average(&course->students[i]) >= 50) count++;

  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++) /**< loops over all students within course and filters out passing students */
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++;
    }
  }

  *total_passing = count;

  return passing;
}
