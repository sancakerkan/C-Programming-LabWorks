#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20
#define MAX_ELEM 10

void findIntersection(char *group1[], char *group2[], int n1, int n2, char *common[], int *commonCountPtr)
{
    
    for (int i = 0; i < n1; i++) {
        
        for (int j = 0; j < n2; j++) {
            
            if (strcmp(group1[i], group2[j]) == 0) {
                
                common[*commonCountPtr] = group1[i];
                (*commonCountPtr)++;
                break;
            }
        }
    }
}

void printStudent(char *common[], int commonCount)
{
    
}

int main()
{
    char list[MAX_ELEM][STR_LEN] = {"", "zoe_lang_85", "sam_rodriguez_70",
    "jack_alonso_50", "david_studi_75", "denzel_feldman_90",
    "james_bale_70", "james_willis_45", "michael_loaf_45", "dustin_vin_35"};

    char *group1[MAX_ELEM];
    int n1;

    char *group2[MAX_ELEM];
    int n2;

    int i;
    int ind;

    printf("Number of elements in group1: ");
    scanf("%d",&n1);
    printf("Entries in group1: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d",&ind);
        group1[i] = list[ind];
    }

    printf("\nNumber of elements in group2: ");
    scanf("%d",&n2);
    printf("Entries in group2: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d",&ind);
        group2[i] = list[ind];
    }

    char *common[MAX_ELEM];
    int commonCount = 0;

    findIntersection(group1, group2, n1, n2, common, &commonCount);

    printf("\ngroup1:\n");
    for (int i = 0; i < n1; i++)
    {
        printf("%s\n",group1[i]);
    }

    printf("\ngroup2:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("%s\n",group2[i]);
    }

    printf("\nintersection of group1 and group2:\n");
    for (int i = 0; i < commonCount; i++)
    {
        printf("%s\n",common[i]);
    }

    printf("\nDo you want to print students in the intersection set in NamE SurnamE Grade format (1/0)? ");
    int response;

    scanf("%d", &response);

    if (response == 1)
    {
        printf("\nStudents in the intersection of group1 and group2:\n");
        printStudent(common, commonCount);

        printf("\nintersection of group1 and group2:\n");
        for (int i = 0; i < commonCount; i++)
        {
            printf("%s\n",common[i]);
        }
    }

    return 0;
}
