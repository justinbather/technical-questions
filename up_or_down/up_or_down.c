/*
 *
 * Determine if your cpu architechture grows your stack up or down in C
 * compile: gcc up_or_down.c -o up_or_down
 * usage: ./up_or_down
 */

#include <stdbool.h>
#include <stdio.h>

bool growsUp(int *addr) {

  int x;

  if (!addr) {
    return growsUp(&x);
  } else {
    return &x > addr;
  }
}

int main() {

  printf("%s\n", growsUp(NULL) ? "Up" : "Down");

  return 0;
}
