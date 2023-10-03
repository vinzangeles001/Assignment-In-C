//Student Name: <Vicente Angeles>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FYI, original insertion sort for sorting an array of integers in ascending order
void insertionSortIntegersAsc(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1; 
		while(j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Do NOT MODIFY ANY CODE ABOVE THIS LINE --------------------------------------

void insertionSortStringsDesc(char* strings[], int length) {
	//TODO	
	for (int i = 1; i < length; i++) {
		char* key = strings[i];
		int j = i - 1; 
		while(j >= 0 && strcmp(strings[j], key) < 0) {
			strings[j + 1] = strings[j];
			j--;
		}
		strings[j + 1] = key;

		// printf("After insertion %d: ", i);
		printf("= Inserting %s to %d\n", key, j+1);

	}
	
	printf("\nSorted array: \n");
    for (int i = 0; i < length; i++){
        printf("%s \n", strings[i]);
    }
    printf("\n");

}

//Do NOT MODIFY ANY CODE BELOW THIS LINE --------------------------------------

int main() {
	char *strings[] = {"canada", "ontario", "toronto", "oakville", "sheridan"};
    insertionSortStringsDesc(strings, sizeof(strings) / sizeof(strings[0]));
}
