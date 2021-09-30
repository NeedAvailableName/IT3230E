#include<stdio.h>
typedef struct point {
    double x;
    double y;
} point_t;
typedef struct circle {
    point_t center;
    double radius;
} circle_t;
int is_in_circle() {
    printf("enter one point: ");
    scanf("%f %f", &a.x, &a.y);
    printf("Enter the center: ");
    scanf("%f %f", &b.center.x, &b.center.y);
    printf("Enter the radius: ");
    scanf("%f", &b.radius);
    if((a.x-b.center.x)*(a.x-b.center.x)+(a.y-b.center.y)*(a.y-b.center.y)<(b.radius*b.radius)) return 1;
    else return -1;
}
int main() {
    point_t a;
    circle_t b;
    printf("%d\n", is_in_circle);
    return 0;
}