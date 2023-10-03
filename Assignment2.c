// Name: Gregory Lee Wo  
// Student#: 991 638 141

// Name: Vicente Angeles
// Student#: 991 480 645

#include <stdbool.h>
#include "Assignment2.h"
#include <string.h>
#include <ctype.h>

int main()
{
        ProvincePtr listPtr, currentPtr;
        listPtr = NULL;

        char provinceName[50]; //variable for province name
        int numberOfTestCenters; //variable for number of the test centers in the province
        int totalNumberOfInfections = 0; //variable for number of infections in the province
        char temp[9];
        char dec; //variable for decision
        bool valid; //variable 

        //loop will ask 13 times.
        //getting the province name, number of test centers, and number of infections
        for (int z = 0; z < 13; z++)
        {
                valid = false;

                 //this loop will check if the province name already exist
                 //if the name doesnt exist it will continue the loop
                while (!valid)
                {
                        currentPtr = listPtr; //use for checking the list

                        //ask the user for province name
                        puts("Enter a province: ");
                        fgets(provinceName, 50, stdin);//gets the province name
                        provinceName[strcspn(provinceName, "\n")] = '\0';

                        //if currentPtr is null valid will become true
                        if (currentPtr == NULL)
                        {
                                valid = true;
                        }//end of if

                        //checks every single names in the list
                        while (currentPtr != NULL)
                        {
                                //compares the province name    
                                if (strcmp(provinceName, currentPtr->provinceName) == 0)
                                {
                                        printf("\n%s is already in the list. ", provinceName);
                                        valid = false;
                                        break;
                                }
                                currentPtr = currentPtr->nextPtr;
                                valid = true;
                        }//end of while
                }//end of while loop

                valid = false;

                //this loop will ask the number of test centers
                while (!valid)
                {
                        //gets the number of test Centers from the user
                        printf("\nEnter the number of test centers in %s: \n", provinceName);
                        numberOfTestCenters = (int)strtol(fgets(temp, 4, stdin), NULL, 0); 

                        //if the user input a value more than 1 and less than 
                        if (numberOfTestCenters <= 10 && numberOfTestCenters >= 1)
                        {       
                                //saves the value too this functions
                                listPtr = insertAndComputeTotalNumberOfInfections(listPtr, provinceName, numberOfTestCenters);
                                valid = true;
                        }//end of if
                        else
                        {
                                //if the user inputs less than 1 and more than 10
                                puts("Num must be between 1 and 10. Try again");
                        }//end of else
                }//end of while loop
                if (z != 12)
                {
                        //if the user wants to add more province or not. 
                        printf("\nDo you want to continue adding provinces Y/N: ");
                        fgets(temp, 3, stdin);
                        dec = temp[0];

                        if (toupper(dec) != 'Y')
                        {
                                break;
                        }
                }
        }//end of for loop

        printList(listPtr);//prints the list
        deleteAndDetermineLeastInfectedProvince(listPtr); //determine what provinces has the least infected
}