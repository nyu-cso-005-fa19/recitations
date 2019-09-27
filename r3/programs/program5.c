#include <stdio.h>
#include <stdlib.h>

struct Point_2D {
  int x;
  int y;
};

struct Point_3D {
  struct Point_2D* xy;
  int z;
};

struct Point_2D* allocate_2d() {
  struct Point_2D* point_a = malloc(sizeof(struct Point_2D));

  if (point_a == NULL)
    return NULL;

  point_a->x = 3;
  point_a->y = 4;

  return point_a;
}

int norm_squared(struct Point_3D* point) {
  point->xy = allocate_2d();
  if (point->xy == NULL)
    return -1;

  struct Point_2D* xy_coordinates = point->xy;
  return xy_coordinates->x * xy_coordinates->x + xy_coordinates->y * xy_coordinates->y +
    point->z * point->z;
}

int main() {
  struct Point_3D point_b;
  point_b.z = 5;

  int b_norm_squared = norm_squared(&point_b);

  if (b_norm_squared == -1)
    return 7;

  printf("Norm squared is : %d\n", b_norm_squared);

  struct Point_2D tmp = *point_b.xy;

  printf("The (x,y) co-ordinates are : (%d, %d)\n", tmp.x, tmp.y);

  free(point_b.xy);

  return 0;
}