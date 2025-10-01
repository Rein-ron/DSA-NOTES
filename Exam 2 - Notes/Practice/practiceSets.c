#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8

typedef struct {
    int id;
    char name[50];
    unsigned int courses; // bitvector set of courses
} Student;


void init(Student* s, int id, char name[]){
    s->courses = 0;
    strcpy(s->name, name);
    s->id = id;
}

void insertStudent(Student* s, int index){
    if(index >= 0 && index < MAX){
        s->courses |= (1 << index);
    }

}

void deleteStudent(Student* s, int index){
    if(index >= 0 && index < MAX){
        s->courses &= ~(1 << index);
    }
}

bool findStudent(Student* s, int index){
    if(index >= 0 && index < MAX) return (s->courses & (1 << index)) != 0;
    return false;
}

unsigned int courseUnion(Student* s, Student* s2){
    return s->courses | s2->courses;
}

void unifedCourses(Student A[], int Stud1, int Stud2){
    printf("Name: %s | ID: %d\n", A[Stud1].name, A[Stud1].id);
    printf("Name: %s | ID: %d\n", A[Stud2].name, A[Stud2].id);

    unsigned int u = courseUnion(&A[Stud1], &A[Stud2]);
    int i;
    printf("Course Union\n");
    for(i = 0;i < MAX;i++){
        if(u & (1 << i)){
            printf("%d\n", i);
        }
    }
    printf("\n");
}

void display(Student s){
    int i;

    printf("Name: %s | ID: %d | Course:\n", s.name, s.id);
    for(i = 0;i < MAX;i++){
        if(findStudent(&s, i)){
            printf("%d\n", i);
        }
    }
    printf("\n");
}

void displayStudents(Student A[], int count){
    int i;
    for(i = 0; i < count;i++){
        display(A[i]);
    }
}

int main(){
    Student A[100];
    int count = 0;

    init(&A[count++], 1, "Ronald");
    init(&A[count++], 2, "Humphrey");
    init(&A[count++], 3, "Toji");

    insertStudent(&A[0], 0);
    insertStudent(&A[0], 3);
    insertStudent(&A[1], 7);
    insertStudent(&A[1], 0);
    insertStudent(&A[2], 4);
    insertStudent(&A[1], 6);
    insertStudent(&A[0], 7);
    insertStudent(&A[0], 1);
    insertStudent(&A[2], 1);
    insertStudent(&A[2], 3);
    insertStudent(&A[1], 2);
    displayStudents(A, count);
    unifedCourses(A, 0, 2);
  
}