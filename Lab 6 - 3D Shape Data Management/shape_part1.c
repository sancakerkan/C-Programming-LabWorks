#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */


/* function prototypes*/
int scanShape(FILE *filep, shape_t *objp);
int loadShapes(shape_t shapes[]);
void printShape(const shape_t *objp);

int main()
{
    shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes:\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    return 0;
}
