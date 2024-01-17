#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */


/* function prototypes*/
/* function prototypes*/
int scanShape(FILE *filep, rectangle_t *objp);
int loadRectangle(rectangle_t shapes[]);
void printShape(const rectangle_t *objp);
int isPerimeterBetween(const rectangle_t *objp, double minPerimeter, double maxPerimeter);

int main()
{
    rectangle_t shapes[MAX_SHAPES];
    int numOfShapes = loadRectangle(shapes);

    printf("\nRectangles:\n");
    for (int i = 0; i < numOfShapes; i++) {
        printf("Rectangle %d: ",i+1);
        printShape(&shapes[i]);
    }

    return 0;
}

