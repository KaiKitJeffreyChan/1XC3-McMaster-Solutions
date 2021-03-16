/*******************************************************************************
*
* Purpose: Assignment #6 starter code.
*
* Description: This code includes all the linked list functions we defined
* in lecture or in lab.  See the assignment document to understand the
* additional code you are required to write.
*
* Author: Kevin Browne
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Defines a node in our linked list
typedef struct node {
  int value;
  struct node *next; // points to the next node in the list, NULL for tail node
} Node;

// Library of functions for working with linked lists created in week 7 lectures
void print_list(Node *head);
Node* insert_at_head(Node *head, int new_value);
Node* insert_at_tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
int length(Node *head);
int recursive_length(Node *node);
bool is_member(Node *node, int find_value);
int count_matches(Node *node, int find_value);
void replace_matches(Node *node, int find_value, int replace_value);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted);

// More functions for working with linked lists created during week 8 labs
Node *append_list(Node *head1, Node *head2);
Node *reverse_list(Node *head);
void sort_list(Node *head);
void delete_duplicates(Node *head);

// Functions to implement (merge_sorted_lists is a bonus, it is not required)
Node* add_lists(Node *list1, Node *list2);
Node *duplicate_list(Node *head);
Node *efficient_delete_match(Node *head, int delete_value, int *num_deleted);
Node *merge_sorted_lists(Node *list1, Node *list2);

int main()
{
  // Test the add_list function by checking three cases: one where the lists
  // are the same length, one where the first list is shorter, and one where
  // the second list is shorter.
  printf("\nadd_list test\n");
  printf("****************************************\n");
  Node *list1, *list2, *list3, *list4, *list5, *list6;
  list1 = list2 = list3 = list4 = list5 = list6 = NULL; // make ALL lists empty
  for (int i = 1; i <= 5; i++) list1 = insert_at_head(list1, i);
  for (int i = 8; i >= 4 ; i--) list2 = insert_at_head(list2, i);
  printf("\nList 1...\n");
  print_list(list1);
  printf("\nList 2...\n");
  print_list(list2);
  printf("\nList 1 after add...\n");
  add_lists(list1, list2);
  print_list(list1);
  for (int i = 1; i <= 2; i++) list3 = insert_at_head(list3, i);
  for (int i = 4; i <= 7; i++) list4 = insert_at_head(list4, i);
  printf("\nList 3...\n");
  print_list(list3);
  printf("\nList 4...\n");
  print_list(list4);
  printf("\nList 3 after add...\n");
  add_lists(list3, list4);
  print_list(list3);
  for (int i = 4; i <= 7; i++) list5 = insert_at_head(list5, i);
  for (int i = 1; i <= 2; i++) list6 = insert_at_head(list6, i);
  printf("\nList 5...\n");
  print_list(list5);
  printf("\nList 6...\n");
  print_list(list6);
  printf("\nList 5 after add...\n");
  add_lists(list5, list6);
  print_list(list5);


  // Test the duplicate_list function by providing it a list, and printing
  // out the list that is returned from the function
  printf("\n\nduplicate_list test\n");
  printf("****************************************\n");
  Node *list7 = NULL;
  for (int i = 0; i < 10; i++) list7 = insert_at_head(list7, i);
  printf("\nList 7...\n");
  print_list(list7);
  Node *list7_duplicate = duplicate_list(list7);
  printf("\nList 7 duplicate...\n");
  print_list(list7_duplicate);
  //
  //
  // // Test whether efficient_delete_match will delete nodes with matching
  // // values and keep an accurate count of the number of nodes deleted
  printf("\n\nefficient_delete_match test\n");
  printf("****************************************\n");
  Node *list8 = NULL;
  list8 = insert_at_head(list8, 4);
  list8 = insert_at_head(list8, 3);
  list8 = insert_at_head(list8, 4);
  list8 = insert_at_head(list8, 5);
  list8 = insert_at_head(list8, 4);
  list8 = insert_at_head(list8, 4);
  list8 = insert_at_head(list8, 7);
  list8 = insert_at_head(list8, 4);
  list8 = insert_at_head(list8, 4);
  printf("\nList 8...\n");
  print_list(list8);
  int num_deleted = 0;
  list8 = efficient_delete_match(list8, 4, &num_deleted);
  printf("\nList 8 after delete...\n");
  print_list(list8);
  printf("Number of elements deleted: %d\n\n\n", num_deleted);


  // Test the performance of delete_all_matches vs efficient_delete by
  // creating lists with 50000 nodes with values from 0-10 repeated and
  // deleting 4 from both lists.
  printf("Performance test of delete functions\n");
  printf("****************************************\n\n");
  Node *list9 = NULL, *list10 = NULL;
  for (int i = 0; i < 50000; i++) list9 = insert_at_head(list9, i % 10);
  for (int i = 0; i < 50000; i++) list10 = insert_at_head(list10, i % 10);
  clock_t tic, toc;
  tic = clock();
  list9 = delete_all_matches(list9, 4, &num_deleted);
  toc = clock();
  printf("delete_all_matches: %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("elements deleted: %d\n\n", num_deleted);
  tic = clock();
  list10 = efficient_delete_match(list10, 4, &num_deleted);
  toc = clock();
  printf("efficient_delete_match: %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("elements deleted: %d\n\n", num_deleted);

  //
  // // BONUS: Test merge_sorted_lists to see if it is able to merge two sorted
  // // lists correctly by creating two lists of length 10 with random values
  // // between 0 and 98.
  printf("\nmerge_sorted_lists test\n");
  printf("****************************************\n");
  srand(time(NULL));
  Node *list11 = NULL;
  Node *list12 = NULL;
  for (int i = 0; i < 10; i++) list11 = insert_at_head(list11, rand() % 99);
  for (int i = 0; i < 10; i++) list12 = insert_at_head(list12, rand() % 99);
  sort_list(list11);
  sort_list(list12);
  printf("\nList 11...\n");
  print_list(list11);
  printf("\nList 12...\n");
  print_list(list12);
  Node *newhead = merge_sorted_lists(list11, list12);
  printf("\nMerged list...\n");
  print_list(newhead);

}

/*******************************************************************************
 *
 * ASSIGNMENT #6 - WRITE YOUR FUNCTIONS HERE
 *
 * ****************************************************************************/


Node* add_lists(Node* list1, Node* list2){
  // if either list ends, stop adding
  if ((list1 == NULL) || (list2 == NULL)) return 0;
  else{
    // if values exist at corresponding nodes, add their values
    list1->value += list2->value;
    // return rest of both lists
    return add_lists(list1->next, list2->next);
  }
 }

Node* duplicate_list(Node* head){
  Node* current;
  Node* dup;
  current = head;
  //dynamically allocate space for first node, set value and next to NULL
  dup = calloc(1, sizeof(Node));
  dup->value = current->value;
  dup->next = NULL;
  current = current->next;
  //traverse through the rest of the list and add to the end of new list
  for (int i = 0; i < ((recursive_length(head)-1)); i++){
    insert_at_tail(dup, current->value);
    current = current->next;
  }
  return dup;
}


Node* efficient_delete_match(Node *head, int delete_value, int *num_deleted){
  Node* next_node = head->next;
  Node* current_node = head;
  Node* store_head = head;
  *num_deleted = 0;
  //as long as the head is the delete value, remove it
  while (current_node->value == delete_value)
  {
    current_node = store_head->next;
    free(store_head); //free deleted head node
    store_head = current_node;
    next_node = store_head->next;
    *num_deleted += 1;
  }
  while(next_node != NULL){
    // if the next node is the target value, delete
    while(next_node != NULL && next_node->value != delete_value){
      current_node = next_node;
      next_node = next_node->next;
    }
    //loop stops while loop from executing code below / prevent seg fault
    if (next_node == NULL){
      break;
    }
    //set current->next to next_node->next, then free deleted node
    current_node->next = next_node->next;
    free(next_node);
    next_node = current_node->next;
    *num_deleted += 1;
  }
  return store_head;
}


Node *merge_sorted_lists(Node *list1, Node *list2){
  Node* sorted_list;
  //base cases, if one of the lists ends return the other list
  //previous nodes would already be sorted, point to remaining portion
  //both equal length would append null, different length add remaining values
  if (list1 == NULL){
    return list2;
  }else if (list2 == NULL){
    return list1;
  }
  //if list1 value is less than list2, set sorted list to list1
  //set sorted_list->next to the remaining lists sorted
  if( list1->value < list2-> value){
    sorted_list = list1;
    sorted_list->next = merge_sorted_lists(list1->next, list2);

  //if list2 value is less than list1, set sorted list to list1
  //set sorted_list->next to the remaining lists sorted
  }else if (list1->value >= list2-> value){
    sorted_list = list2;
    sorted_list->next = merge_sorted_lists(list1, list2->next);
  }
	return sorted_list;
}

/*******************************************************************************
 *
 * The functions below were created during the week 8 labs.
 *
 * ****************************************************************************/

// Appends the list beginning with head2 to the tail of the list beginning with
// head1, returns the potentially new head of the list.
Node *append_list(Node *head1, Node *head2)
{
  // if the first list is empty, the 2nd list's head becomes the beginning of
  // the new list
  if (head1 == NULL) return head2;

  // Otherwise traverse the first list until we reach the tail, and set the
  // tail of the list to point to the head of the list to be appended
  Node *current = head1;
  while (current->next != NULL) current = current->next;
  current->next = head2;
  return head1;
}

// Reverses a linked list starting with head and returns the new head of the
// reversed list.  By reverse the list, we mean reverse the direction of all
// the pointers in the list.
Node *reverse_list(Node *head)
{
  // do nothing in the case of an empty list
  if (head == NULL) return NULL;

  // a list with one node is identical to it's "reversal"
  if (head->next == NULL) return head;

  // will need to keep track of two nodes to perform reversal
  Node *current = head;
  Node *next_node = head->next;

  // current head becomes the tail, so points to NULL!
  current->next = NULL;

  // traverse through the list until we reach the (old) tail
  while (next_node != NULL)
  {
    // Reverse the pointer, so that next_node points to current.
    // Then set the next_node to whatever the next_node was previously
    // pointing to (with the assistance of a temp value), and set current
    // to the old next_node.
    Node *tmp = next_node->next;
    next_node->next = current;
    current = next_node;
    next_node = tmp;
  }

  // the previous tail becomes the new head!
  return current;
}

// Sorts a list from lowest to highest values beginning with head using the
// bubble sort algorithm: https://en.wikipedia.org/wiki/Bubble_sort
// Note that we only swap node values rather than re-arrange node pointers
// themselves.
void sort_list(Node *head)
{
  // An empty list or a list of one node are already sorted, just return them
  if (head == NULL) return ;
  if (head->next == NULL) return ;

  bool swapped = false;

  // keep attempting to swap node values until no swap occurs
  do
  {
    swapped = false;
    Node *current = head;
    Node *prev = NULL;

    // keep track of the next and previous nodes while traversing the list
    while (current->next != NULL)
    {
      prev = current;
      current = current->next;

      // swap node values if they are not in the correct order
      if (current != NULL)
      {
        if (current->value < prev->value)
        {
          int temp;
          temp = prev->value;
          prev->value = current->value;
          current->value = temp;
          swapped = true;
        }
      }
    }
  } while (swapped);
}

// Deletes duplicate nodes from a list beginning with head
void delete_duplicates(Node *head)
{
  // empty lists and lists with one node have no duplicates!
  if (head == NULL) return ;
  if (head->next == NULL) return ;

  // We use current1 and current2 to traverse the list
  Node *current1, *current2, *duplicate;
  current1 = head;

  // The outter loop "increments" current1 (i.e. traverses to the next node)
  // after removing any nodes with duplicate values to current1
  while (current1 != NULL && current1->next != NULL)
  {

    // The inner loop uses current2 to traverse the list
    current2 = current1;
    while (current2->next != NULL)
    {
      // Whenever current1's value is equal to the value in the next node
      // that current2 points to, we delete that node from the list and have
      // current2 point to the node after the next node ("the next next node")
      if (current1->value == current2->next->value)
      {
        duplicate = current2->next;
        current2->next = current2->next->next;
        free(duplicate);
      }
      // if what current 2 is pointing to doesn't contain a duplicate, just
      // have current2 point to the next node and keep checking for duplicates
      else current2 = current2->next;
    }

    // have current1 point to the next node in the list
    current1 = current1->next;
  }
}


/*******************************************************************************
 *
 * The below functions were created during week 7 in-lecture and are identical
 * to the code posted under Week 7.
 *
 * ****************************************************************************/

// Deletes all nodes with a value matching delete_value in a linked list
// starting with *head, repeatedly calls delete_first_match until no mathces
// are found making the implementation not particularly efficient.  Keeps
// track of the number of nodes deleted with pass-by-reference num_deleted.
// Returns the current head of the list after deletions have taken place.
Node *delete_all_matches(Node *head, int delete_value, int *num_deleted)
{
  Node *current = head;
  bool deleted = true;
  *num_deleted = 0;
  int i = 0;

  // keep calling delete_first_match until nothing is deleted
  do
  {
    current = delete_first_match(current, delete_value, &deleted);
    if (deleted) *num_deleted  = *num_deleted + 1;
  } while(deleted);

  return current;
}

// Deletes the first node from a linked list that matches the delete_value.
// The linked list starts with head, and we keep track of whether a node was
// deleted with the pass-by-reference was_deleted.  Returns the current head
// of the list after a deletion may have taken place
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
  // if the list is empty, no delete occurs, and return empty list
  if (head == NULL)
  {
    *was_deleted = false;
    return NULL;
  }

  // if the head node needs to be deleted, return the next node as the new head
  // of the list (which could be null), and free the existing head node
  if (head->value == delete_value)
  {
    Node *temp = head->next;
    free(head);
    *was_deleted = true;
    return temp;
  }

  Node *current = head->next;
  Node *prev = head;

  // Traverse list keeping track of node previous to the current, if the
  // current node needs to be deleted, free the current node and have the
  // previous node point to what the current node was pointing to.  In this
  // case the head of our list has not changed so we can return the same head.
  while (current != NULL)
  {
    if (current->value == delete_value)
    {
      prev->next = current->next;
      free(current);
      *was_deleted = true;
      return head;
    }
    prev = current;
    current = current->next;
  }

  // if no deletion occurred
  *was_deleted = false;
  return head;
}

// Recursively traverses the list starting with node replacing find_value with
// replace_value wherever it occurs.
void replace_matches(Node *node, int find_value, int replace_value)
{
  if (node != NULL)
  {
    if (node->value == find_value) node->value = replace_value;
    replace_matches(node->next, find_value, replace_value);
  }
}

// Recursively traverses the list starting with node, returning a count of how
// many times find_value occurs in the list.
int count_matches(Node *node, int find_value)
{
  if (node == NULL) return 0;
  else if (node->value == find_value)
    return 1 + count_matches(node->next, find_value);
  else return count_matches(node->next, find_value);
}

// Recursively traverses the list starting with node, returning true or false
// whether find_value is found in one of the list nodes.
bool is_member(Node *node, int find_value)
{
  if (node == NULL) return false;
  else if (node->value == find_value) return true;
  else return is_member(node->next, find_value);
}

// Recursively traverses the list starting with node, returning the length of
// the list.
int recursive_length(Node *node)
{
  if (node == NULL) return 0;
  else return 1 + recursive_length(node->next);
}

// Traverses the list starting with head and keeps track of the length in
// order to return it.
int length(Node *head)
{
  Node *current;
  current = head;
  int length = 0;
  while (current != NULL)
  {
    length++;
    current = current->next;
  }
  return length;
}

// Deletes the node at at the tail of the linked list, returning the
// (potentially altered) head node.
Node *delete_at_tail(Node *head)
{
  // if the list is empty, we do nothing
  if (head == NULL) return NULL;
  // if the head is the only node, delete it and return an empty list
  else if (head->next == NULL)
  {
    free(head);
    return NULL;
  }
  // Otherwise we traverse the list and keep track of the node previous to
  // the current node so that when we do reach the tail we can free it and
  // set the previous node's next pointer to NULL (in order to make it the
  // new tail).
  else
  {
    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL)
    {
      prev = current;
      current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
  }
}

// Deletes the node at the head of the list and returns the potentially altered
// head node
Node *delete_at_head(Node *head)
{
  // if the list is empty, return an empty list (NULL)
  if (head == NULL) return NULL;
  // otherwise delete/free the head node and return what the head was pointing
  // to (potentially NULL) as the new head of the list
  else
  {
    Node *to_return = head->next;
    free(head);
    return to_return;
  }
}

// Creates and inserts a node with new_value as its value at the head of the
// list, returning the new head of the list.
Node* insert_at_head(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  new_node->next = NULL;
  if (head == NULL) return new_node;
  else
  {
    new_node->next = head;
    return new_node;
  }
}

// Creates and inserts a new node with value set to new_value, returning the
// new head of the list (if the list is empty, this new node will be the
// new head of the list).
Node* insert_at_tail(Node *head, int new_value)
{
  Node *new_node = calloc(1, sizeof(Node));
  new_node->value = new_value;
  new_node->next = NULL;
  if (head == NULL) return new_node;
  else
  {
    // traverses the list in order to reach the tail, sets that node's next
    // to point to the newly created node
    Node *current = head;
    while (current->next != NULL) current = current->next;
    current->next = new_node;
    return head;
  }
}

// Traverses a linked list starting with head and prints out each node's
// value. Also prints out a position or index for each node in the list.
void print_list(Node *head)
{
  Node *current;
  current = head;
  int i = 0;
  while (current != NULL)
  {
    printf("Node %d: %d\n", i, current->value);
    current = current->next;
    i++;
  }
}