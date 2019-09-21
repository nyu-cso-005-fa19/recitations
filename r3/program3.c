#include <stdio.h>

struct Point_2D {
  int x;
  int y;
};

struct Point_3D {
  struct Point_2D* xy;
  int z;
};

int norm_squared(struct Point_3D point) {
  struct Point_2D point_a = {3, 4};
  point.xy = &point_a;
  struct Point_2D xy_coordinates = *point.xy;
  return xy_coordinates.x * xy_coordinates.x + xy_coordinates.y * xy_coordinates.y +
    point.z * point.z;
}

int main() {
  struct Point_3D point_b;
  point_b.z = 5;

  int b_norm_squared = norm_squared(point_b);

  printf("Norm squared is : %d\n", b_norm_squared);

  struct Point_2D tmp = *point_b.xy;

  printf("The (x,y) co-ordinates are : (%d, %d)", tmp.x, tmp.y);

  return 0;
}