#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "circular.h"

int main() {
  circular *c = circular_create();

  circular_push_back(c, 10);
  circular_push_back(c, 20);
  circular_push_back(c, 30);

  circular_pop_back(c);
  circular_pop_back(c);

  circular_push_back(c, 40);
  circular_push_back(c, 50);
  circular_push_back(c, 60);

  circular_delete(c);

  return EXIT_SUCCESS;
}
