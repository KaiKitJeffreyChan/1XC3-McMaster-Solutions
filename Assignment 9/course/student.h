/**
*
* @file student.h
* @author Jeffrey Chan
* @date April 1st, 2021.
* @brief Functions within Course Library
*
*/

/**
 * Struct to represent a student
 */
typedef struct _student
{
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades;/**< pointer to students grade */
  int num_grades;/**< pointer to number of students grades */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades);
