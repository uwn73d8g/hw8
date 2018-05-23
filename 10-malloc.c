#include <stdio.h>
#include <stdlib.h>

typedef struct person_t {
  struct person_t *next;
  char            *name;
} Person;

int main(int argc, char *argv[]) {
  char *name[] = {"alice", "bob", "charlie", NULL};
  Person *head = NULL;

  //-------------------------------------------
  // push names onto stack created by malloc'ing
  //-------------------------------------------
  for (char **p=name; *p != NULL; p++) {
    Person *newPerson = malloc(sizeof(Person));
    if ( newPerson == NULL ) exit(1);
    newPerson->name = *p;
    newPerson->next = head;
    head = newPerson;
  }
  
  //-------------------------------------------
  // print stack
  //-------------------------------------------
  for (Person *p=head; p != NULL; p = p->next) {
    printf("%s\n", p->name);
  }

  //-------------------------------------------
  // Free stack
  //-------------------------------------------
  while (head != NULL) {
    Person *p = head->next;
    free(head);
    head = p;
  }
  
  
  return EXIT_SUCCESS;
}