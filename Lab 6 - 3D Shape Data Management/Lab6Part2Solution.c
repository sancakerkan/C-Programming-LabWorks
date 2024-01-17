#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SHAPES 50

typedef struct {
    double x;
    double y;
    double z;
} point_t;

typedef struct {
    point_t center;
    double radius;
} sphere_t;

typedef struct {
    point_t center;
    double side;
} cube_t;

typedef struct {
    point_t center;
    double base_side;
    double height;
} square_prism_t;

typedef union {
    cube_t cube;
    square_prism_t square_prism;
    sphere_t sphere;
} shape3d_data_t;

typedef enum {
    CUBE,
    SQUARE_PRISM,
    SPHERE
} class_t;

typedef struct {
    class_t type;
    shape3d_data_t shape;
} shape_t;

int scanShape(FILE *filep, shape_t *objp);
int loadShapes(const char *filename, shape_t shapes[]);
void printShape(const shape_t *objp);
int isVolumeBetween(double minVolume, double maxVolume, const shape_t *objp);

int main()
{
    shape_t shapes[MAX_SHAPES];
    char filename[100];

    printf("Enter the file name to read: ");
    scanf("%s", filename);

    printf("\nOpening %s\n", filename);
    int numOfShapes = loadShapes(filename, shapes);
    if (numOfShapes == -1) {
        
        return 1;
    }
    printf("Loading complete\n");
    printf("Closing %s\n", filename);

    printf("\nShapes 3D:\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    double minV, maxV;
    printf("\nEnter min and max volumes: ");
    scanf("%lf %lf", &minV, &maxV);

    printf("\nVolumes of the following shapes are between %.2lf and %.2lf:\n", minV, maxV);
    for (int i = 0; i < numOfShapes; i++)
        if (isVolumeBetween(minV, maxV, &shapes[i]))
            printShape(&shapes[i]);

    return 0;
}

int scanShape(FILE *filep, shape_t *objp)
{
    char shapeType[15];
    if (fscanf(filep, "%s", shapeType) != 1)
        return 0;

    if (strcmp(shapeType, "cube") == 0) {
        objp->type = CUBE;
        if (fscanf(filep, "%lf %lf %lf %lf",
                   &objp->shape.cube.center.x,
                   &objp->shape.cube.center.y,
                   &objp->shape.cube.center.z,
                   &objp->shape.cube.side) != 4)
            return 0;
    } else if (strcmp(shapeType, "square_prism") == 0) {
        objp->type = SQUARE_PRISM;
        if (fscanf(filep, "%lf %lf %lf %lf %lf",
                   &objp->shape.square_prism.center.x,
                   &objp->shape.square_prism.center.y,
                   &objp->shape.square_prism.center.z,
                   &objp->shape.square_prism.base_side,
                   &objp->shape.square_prism.height) != 5)
            return 0;
    } else if (strcmp(shapeType, "sphere") == 0) {
        objp->type = SPHERE;
        if (fscanf(filep, "%lf %lf %lf %lf",
                   &objp->shape.sphere.center.x,
                   &objp->shape.sphere.center.y,
                   &objp->shape.sphere.center.z,
                   &objp->shape.sphere.radius) != 4)
            return 0;
    } else {
        return 0;
    }

    return 1;
}

int loadShapes(const char *filename, shape_t shapes[])
{
    FILE *filep = fopen(filename, "r");
    if (filep == NULL) {
        return -1;
    }

    int numOfShapes = 0;
    while (numOfShapes < MAX_SHAPES && scanShape(filep, &shapes[numOfShapes])) {
        numOfShapes++;
    }

    fclose(filep);
    return numOfShapes;
}

void printShape(const shape_t *objp)
{
    switch (objp->type) {
        case CUBE:
            printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n",
                   objp->shape.cube.center.x, objp->shape.cube.center.y, objp->shape.cube.center.z,
                   objp->shape.cube.side,
                   pow(objp->shape.cube.side, 3));
            break;
        case SQUARE_PRISM:
            printf("Square_prism: <%.2lf %.2lf %.2lf> <%.2lf %.2lf> <%.2lf>\n",
                   objp->shape.square_prism.center.x, objp->shape.square_prism.center.y, objp->shape.square_prism.center.z,
                   objp->shape.square_prism.base_side, objp->shape.square_prism.height,
                   objp->shape.square_prism.base_side * objp->shape.square_prism.base_side * objp->shape.square_prism.height);
            break;
        case SPHERE:
            printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n",
                   objp->shape.sphere.center.x, objp->shape.sphere.center.y, objp->shape.sphere.center.z,
                   objp->shape.sphere.radius,
                   (4.0 / 3.0) * M_PI * pow(objp->shape.sphere.radius, 3));
            break;
    }
}

int isVolumeBetween(double minVolume, double maxVolume, const shape_t *objp)
{
    switch (objp->type) {
        case CUBE:
            return (pow(objp->shape.cube.side, 3) >= minVolume && pow(objp->shape.cube.side, 3) <= maxVolume);
        case SQUARE_PRISM:
            return (objp->shape.square_prism.base_side * objp->shape.square_prism.base_side * objp->shape.square_prism.height >= minVolume
                    && objp->shape.square_prism.base_side * objp->shape.square_prism.base_side * objp->shape.square_prism.height <= maxVolume);
        case SPHERE:
            return ((4.0 / 3.0) * M_PI * pow(objp->shape.sphere.radius, 3) >= minVolume
                    && (4.0 / 3.0) * M_PI * pow(objp->shape.sphere.radius, 3) <= maxVolume);
        default:
            return 0;
    }
}
