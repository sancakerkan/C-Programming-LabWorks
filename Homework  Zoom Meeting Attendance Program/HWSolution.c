#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTENDEES 500
#define MAX_NAME_LENGTH 100

struct Attendee {
    char name[MAX_NAME_LENGTH];
    double duration;
};

void updateDuration(struct Attendee attendees[], int index, double duration) {
    attendees[index].duration += duration;
}

int compareAttendees(const void* a, const void* b) {
    const struct Attendee* attendeeA = (const struct Attendee*)a;
    const struct Attendee* attendeeB = (const struct Attendee*)b;

    int surnameComparison = strcasecmp(strrchr(attendeeA->name, ' ') + 1, strrchr(attendeeB->name, ' ') + 1);
    if (surnameComparison != 0) {
        return surnameComparison;
    }

    return strcasecmp(attendeeA->name, attendeeB->name);
}

int main() {
    char filename[100];
    char sortedAnswer[4];

    printf("Enter the input file name: ");
    scanf("%99s", filename);

    printf("Sort the results? (yes/no): ");
    scanf("%3s", sortedAnswer);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 1;
    }

    struct Attendee attendees[MAX_ATTENDEES];
    int numAttendees = 0;

    char buffer[200];
    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* token = strtok(buffer, ",");
        int fieldIndex = 0;
        double duration = 0.0;
        char name[MAX_NAME_LENGTH];

        while (token != NULL) {
            switch (fieldIndex) {
                case 2:
                    duration = atof(token);
                    break;
                case 3:
                    strncpy(name, token, MAX_NAME_LENGTH);
                    break;
            }

            token = strtok(NULL, ",");
            fieldIndex++;
        }

        char* formattedName = name;
        while (*formattedName == ' ') {
            formattedName++;
        }
        int nameLength = strlen(formattedName);
        while (nameLength > 0 && formattedName[nameLength - 1] == ' ') {
            nameLength--;
        }
        formattedName[nameLength] = '\0';

        int existingIndex = -1;
        for (int i = 0; i < numAttendees; i++) {
            if (strcasecmp(attendees[i].name, formattedName) == 0) {
                existingIndex = i;
                break;
            }
        }

        if (existingIndex != -1) {
            updateDuration(attendees, existingIndex, duration);
        } else {
            strncpy(attendees[numAttendees].name, formattedName, MAX_NAME_LENGTH);
            attendees[numAttendees].duration = duration;
            numAttendees++;
        }
    }

    fclose(file);

    if (strcasecmp(sortedAnswer, "yes") == 0) {
        qsort(attendees, numAttendees, sizeof(struct Attendee), compareAttendees);
    }

    for (int i = 0; i < numAttendees; i++) {
        printf("%s %.2f\n", attendees[i].name, attendees[i].duration);
    }

    return 0;
}
