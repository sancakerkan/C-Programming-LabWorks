#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */


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

    double minPerimeter, maxPerimeter;
    printf("\nEnter minimum perimeter: \n");
    scanf("%lf" ,&minPerimeter);
    printf("\nEnter maximum perimeter: \n");
    scanf("%lf" , &maxPerimeter);
    printf("\nThe following rectangles satisfy user conditions:\n");
    for (int i = 0; i < numOfShapes; i++) {
        if (isPerimeterBetween(&shapes[i],minPerimeter,maxPerimeter))
        {
            printf("Rectangle %d: ",i+1);
            printShape(&shapes[i]);
        }
    }

    return 0;
}

