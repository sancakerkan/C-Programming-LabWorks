#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int id; // actor id
    char name[20]; // actor name
	char surname[20]; // actor surname
    char major[20]; // major of actor
    int repIndex; // reputation index of the actor
} actor;

void showRecords(FILE *filePtr);

int modifyRepIndex(FILE *filePtr, unsigned int id, int decreaseRep);
int insertActor(FILE *filePtr, unsigned int id, char name[], char surname[], char major[], int repIndex);
int removeActor(FILE *filePtr, unsigned int id);
int viewMajorReps(FILE *filePtr, char major[], int minRep);

int main()
{
    unsigned int id;
    int decreaseRep;
    int status;

    char name[20];
    char surname[20];
	char major[20];
    int repIndex;

    int count;
	int minReputation;

    FILE *filePtr;
    filePtr = fopen("actor.bin","rb+");
    if (filePtr == NULL)
    {
        printf("Could not open actor.bin");
        return;
    }

    showRecords(filePtr);

    int choice;

    printf("\nWhich operation do you choose?\n");
    printf("1 : Update Reputation Index\n");
    printf("2 : Add Actor\n");
    printf("3 : Delete Actor\n");
    printf("4 : View Major Info with Reputation\n");
    printf("> ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("\nActor id: ");
        scanf("%d",&id);
        printf("Decrease value for reputation index: ");
        scanf("%d",&decreaseRep);
        status = modifyRepIndex(filePtr, id, decreaseRep);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No actor with id %d\n", id);
        break;
    case 2:
        printf("\nActor id: ");
        scanf("%d",&id);
        printf("Name: ");
        scanf("%s",name);
		printf("Surname: ");
        scanf("%s",surname);
        printf("Major: ");
        scanf("%s",major);
        printf("Reputation Index: ");
        scanf("%d",&repIndex);
        status = insertActor(filePtr, id, name, surname, major, repIndex);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("There is already an actor with id %d\n", id);
        break;
    case 3:
        printf("\nActor id: ");
        scanf("%d",&id);
        status = removeActor(filePtr, id);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No actor with id %d\n", id);
        break;
    case 4:
        printf("\nMajor: ");
        scanf("%s",major);
		printf("\nMin reputation Index: ");
        scanf("%d",&minReputation);
        count = viewMajorReps(filePtr, major, minReputation);
        if (count == 0)
            printf("No actor in major %s with reputation index <= %d\n", major, minReputation);
        else
            printf("There are %d actors in major %s with reputation index <= %d\n", count, major, minReputation);
        break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);

    printf("\n%-3s %-20s %-20s %-20s %s\n",
                   "ID",
                   "Name",
				   "Surname",
                   "Major",
                   "Reputation Index");

    while (!feof(filePtr))
    {
        actor a;
        int result = fread(&a, sizeof(actor), 1, filePtr);
        if (result != 0 && a.id != 0)
        {
            printf("%-3d %-20s %-20s %-20s %d\n",
                   a.id,
                   a.name,
				   a.surname,
                   a.major,
                   a.repIndex);
        }
    }
}

int modifyRepIndex(FILE *filePtr, unsigned int id, int decreaseRep)
{
    // Please write your code here
}

int insertActor(FILE *filePtr, unsigned int id, char name[], char surname[], char major[], int repIndex)
{
    // Please write your code here
}

int removeActor(FILE *filePtr, unsigned int id)
{
    // Please write your code here
}

int viewMajorReps(FILE *filePtr, char major[], int maxCit)
{
    // Please write your code here
}
