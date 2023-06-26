#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int id; 
    char name[20]; 
    char surname[20]; 
    char major[20]; 
    int repIndex; 
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
    

    showRecords(filePtr);

    int choice;

    printf("\nWhich operation do you choose?\n");
    printf("1 : Update Reputation Index\n");
    printf("2 : Add Actor\n");
    printf("3 : Delete Actor\n");
    printf("4 : View Major Info with Reputation\n");
    printf("> \n");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\nActor id: ");
            scanf("%d",&id);
            printf("\nDecrease value for reputation index:\n");
            scanf("%d",&decreaseRep);
            status = modifyRepIndex(filePtr, id, decreaseRep);
            if (status == 1)
                showRecords(filePtr);
            else
                printf("No actor with id %d\n", id);
            break;
        case 2:
            printf("Actor id:\n");
            scanf("%d",&id);
            printf("Name:\n");
            scanf("%s",name);
            printf("Surname:\n");
            scanf("%s",surname);
            printf("Major:\n");
            scanf("%s",major);
            printf("Reputation Index:\n");
            scanf("%d",&repIndex);
            status = insertActor(filePtr, id, name, surname, major, repIndex);
            if (status == 1)
                showRecords(filePtr);
            else
                printf("There is already an actor with id %d\n", id);
            break;
        case 3:
            printf("Actor id:");
            scanf("%d",&id);
            status = removeActor(filePtr, id);
            if (status == 1)
                showRecords(filePtr);
            else
                printf("\nNo actor with id %d\n", id);
            break;
        case 4:
            printf("\nMajor: ");
            scanf("%s",major);
            printf("\nMin reputation Index: ");
            scanf("%d",&minReputation);
            count = viewMajorReps(filePtr, major, minReputation);
            if (count == 0)
                printf("No actor in major %s with reputation index >= %d\n", major, minReputation);
            else
                printf("There are %d actors in major %s with reputation index >= %d\n", count, major, minReputation);
            break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);
    actor currentActor;
    printf("\nID  Name                Surname              Major                Reputation Index\n");
    fread(&currentActor, sizeof(actor), 1, filePtr);
    while (!feof(filePtr))
    {
        if (currentActor.id != 0)
        {
            printf("%-4d%-20s%-20s%-20s%d\n", currentActor.id, currentActor.name, currentActor.surname, currentActor.major, currentActor.repIndex);
        }
        fread(&currentActor, sizeof(actor), 1, filePtr);
    }
}

int modifyRepIndex(FILE *filePtr, unsigned int id, int decreaseRep)
{
    fseek(filePtr, (id - 1) * sizeof(actor), SEEK_SET);
    actor currentActor;
    fread(&currentActor, sizeof(actor), 1, filePtr);
    if (currentActor.id == id)
    {
        currentActor.repIndex -= decreaseRep;
        fseek(filePtr, -sizeof(actor), SEEK_CUR);
        fwrite(&currentActor, sizeof(actor), 1, filePtr);
        return 1;
    }
    return 0;
}

int insertActor(FILE *filePtr, unsigned int id, char name[], char surname[], char major[], int repIndex)
{
    fseek(filePtr, (id - 1) * sizeof(actor), SEEK_SET);
    actor currentActor;
    fread(&currentActor, sizeof(actor), 1, filePtr);
    if (currentActor.id == 0)
    {
        currentActor.id = id;
        strcpy(currentActor.name, name);
        strcpy(currentActor.surname, surname);
        strcpy(currentActor.major, major);
        currentActor.repIndex = repIndex;
        fseek(filePtr, -sizeof(actor), SEEK_CUR);
        fwrite(&currentActor, sizeof(actor), 1, filePtr);
        return 1;
    }
    return 0;
}

int removeActor(FILE *filePtr, unsigned int id)
{
    fseek(filePtr, (id - 1) * sizeof(actor), SEEK_SET);
    actor currentActor;
    fread(&currentActor, sizeof(actor), 1, filePtr);
    if (currentActor.id == id)
    {
        currentActor.id = 0;
        strcpy(currentActor.name, "");
        strcpy(currentActor.surname, "");
        strcpy(currentActor.major, "");
        currentActor.repIndex = 0;
        fseek(filePtr, -sizeof(actor), SEEK_CUR);
        fwrite(&currentActor, sizeof(actor), 1, filePtr);
        return 1;
    }
    return 0;
}

int viewMajorReps(FILE *filePtr, char major[], int minRep)
{
    fseek(filePtr, 0, SEEK_SET);
    actor currentActor;
    int count = 0;
    printf("\nID  Name                 Surname              Major                Reputation Index\n");
    fread(&currentActor, sizeof(actor), 1, filePtr);
    while (!feof(filePtr))
    {
        if (strcmp(currentActor.major, major) == 0 && currentActor.repIndex >= minRep)
        {
            printf("%-4d%-20s%-20s%-20s%d\n", currentActor.id, currentActor.name, currentActor.surname, currentActor.major, currentActor.repIndex);
            count++;
        }
        fread(&currentActor, sizeof(actor), 1, filePtr);
    }
    return count;
}
