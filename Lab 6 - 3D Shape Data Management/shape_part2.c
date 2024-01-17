#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */


/* function prototypes*/
int scanShape(FILE *filep, shape_t *objp);
int loadShapes(shape_t shapes[]);
void printShape(const shape_t *objp);
int isVolumeBetween(double minVolume, double maxVolume, const shape_t *objp);

int main()
{
    shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes 3D:\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    double minV,maxV;
    printf("\nEnter min and max volumes: ");
    scanf("%lf %lf",&minV,&maxV);

    printf("\nVolumes of the following shapes are between %.2lf and %.2lf:\n",minV,maxV);
    for (int i = 0; i < numOfShapes; i++)
        if (isVolumeBetween(minV,maxV,&shapes[i]))
            printShape(&shapes[i]);

    return 0;
}
