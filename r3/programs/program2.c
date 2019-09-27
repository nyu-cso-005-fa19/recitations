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
  struct Point_2D xy_coordinates = *point.xy;
  return xy_coordinates.x * xy_coordinates.x + xy_coordinates.y * xy_coordinates.y + 
    point.z * point.z;
}

int main() {
  struct Point_2D point_a = {3, 4};
  struct Point_3D point_b = {&point_a, 5};

  int b_norm_squared = norm_squared(point_b);

  printf("Norm squared is : %d\n", b_norm_squared);

  point_a.x = 2;

  b_norm_squared = norm_squared(point_b);

  printf("Is this the same norm squared : %d?\n", b_norm_squared);

  return 0;
}