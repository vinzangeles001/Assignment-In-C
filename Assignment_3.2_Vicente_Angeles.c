//Student Name: <Vicente Angeles>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
	int sid;
	char *name;
	double mark;
} Student, *StudentPtr;

//Do NOT MODIFY ANY CODE ABOVE THIS LINE --------------------------------------

StudentPtr getBestStudent(StudentPtr students, int n) {
	//TODO
	clock_t start, stop;
    if(students == NULL || n==0){
		return NULL;
	}
	
	start = clock();
	
	StudentPtr bStud = &students[0];
	for(int i = 0; i < n; i++){
	    if(students[i].mark > bStud->mark){
			bStud = &students[i];
		}
	}
	
	stop = clock();
	double time = (double)(stop - start);
	printf("TIME: %.2f \n", time) / CLOCKS_PER_SEC;
	
	return bStud;
}

//Do NOT MODIFY ANY CODE BELOW THIS LINE --------------------------------------

int main() {	
	printf("Check#1: %s\n", getBestStudent(NULL, 0) == NULL ? "Pass" : "Fail");	
	Student students[] = {{123, "Alice", 87.65}, {234, "Bob", 56.78}, 
						{345, "Cindy", 76.89}, {456, "David", 89.76}};
	printf("Check#2: %s\n", getBestStudent(students, 0) == NULL ? "Pass" : "Fail");
	printf("Best student: %s\n", getBestStudent(students, 4)->name);
	StudentPtr sp = malloc(pow(10, 8) * sizeof(Student));
	for (int i = 0; i < pow(10, 8); i++) { 
		sp[i].sid = i; sp[i].name = "Edward"; sp[i].mark = 92.43; }
	printf("Best student: %s\n", getBestStudent(sp, pow(10, 8))->name);		
}
