#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t bottomLeft;
    double width;
    double height;
    double perimeter;
} rectangle_t;

int scanShape(FILE *filep, rectangle_t *objp);
int loadShapes(rectangle_t shapes[]);
void printShape(const rectangle_t *objp);

int main()
{
    rectangle_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nRectangles:\n");
    for (int i = 0; i < numOfShapes; i++) {
        printf("Rectangle %d: ", i + 1);
        printShape(&shapes[i]);
    }

    return 0;
}

int scanShape(FILE *filep, rectangle_t *objp)
{
    char shapeType[20];
    double centerX, centerY, width, height;

    if (fscanf(filep, "%s %lf %lf %lf %lf", shapeType, &centerX, &centerY, &width, &height) != 5) {
        return 0; 
    }

    objp->bottomLeft.x = centerX - (width / 2.0);
    objp->bottomLeft.y = centerY - (height / 2.0);
    objp->width = width;
    objp->height = height;
    objp->perimeter = 2 * (width + height);

    return 1; 
}

int loadShapes(rectangle_t shapes[])
{
    char filename[100];
    int numOfShapes = 0;

    printf("Enter the file name to read: ");
    scanf("%s", filename);

    FILE *filep = fopen(filename, "r");
    if (filep == NULL) {
        printf("Error opening %s\n", filename);
        return 0;
    }

    printf("\nOpening %s\n", filename);

    while (numOfShapes < MAX_SHAPES && scanShape(filep, &shapes[numOfShapes])) {
        numOfShapes++;
    }

    printf("Loading complete\n");
    fclose(filep);
    printf("Closing %s\n", filename);

    return numOfShapes;
}

void printShape(const rectangle_t *objp)
{
    printf("<%.2lf %.2lf> <%.2lf %.2lf> <%.2lf %.2lf> <%.2lf %.2lf> P <%.2lf>\n",
        objp->bottomLeft.x, objp->bottomLeft.y,
        objp->bottomLeft.x + objp->width, objp->bottomLeft.y,
        objp->bottomLeft.x, objp->bottomLeft.y + objp->height,
        objp->bottomLeft.x + objp->width, objp->bottomLeft.y + objp->height,
        objp->perimeter);
}
