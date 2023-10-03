//Student Name: <Vicente Angeles>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int sid;
	char *name;
	double mark;
} Student, *StudentPtr;

typedef struct node {
	Student student;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr head, tail;
} StudentQueueType, *StudentQueue;

//Do NOT MODIFY ANY CODE ABOVE THIS LINE --------------------------------------

void printStudentQueue(StudentQueue sq) {
	//TODO
    if (sq == NULL || sq->head == NULL) {
		puts("NULL");
		return;
	}
		NodePtr current = sq->head;
		double mark = 0;
		int count = 0;

	    while (current != NULL) {
			printf("sid: %d, name: %s, mark: %.2f\n", current->student.sid, current->student.name, current->student.mark);
			mark += current->student.mark;
			count++;
			current = current->next;
		}

	double totalMark = mark / count;
    printf("Count: %d\n", count);
    printf("Average Mark: %.2f\n", totalMark);
}


//Do NOT MODIFY ANY CODE BELOW THIS LINE --------------------------------------

int main() {
	printStudentQueue(NULL);
	
	StudentQueueType sqt = {NULL, NULL};
	StudentQueue sq = &sqt;
	printStudentQueue(sq);
	
	Node n1 = {{123, "Alice", 87.65}, NULL};
	Node n2 = {{234, "Bob", 56.78}, &n1};
	Node n3 = {{345, "Cindy", 76.89}, &n2};
	Node n4 = {{456, "David", 89.76}, &n3};
	sq->head = &n4;
	sq->tail = &n1;
	printStudentQueue(sq);
	printf("StudentQueue head: %s, tail: %s\n", 
		sq->head->student.name, sq->tail->student.name);
}
