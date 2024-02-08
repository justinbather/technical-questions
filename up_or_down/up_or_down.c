/*
 *
 * Determine if your cpu architechture grows your stack up or down in C
 * compile: gcc up_or_down.c -o up_or_down
 * usage: ./up_or_down
 */

#include <stdbool.h>
#include <stdio.h>

/*
 * we can do this in 2 ways, by instantiating 2 variables and comparing the
 * addresses, which the compiler could do this in a weird way so its not optimal
 * (can use volatile but still, we can't be sure) OR we can utilize the fact
 * that function calls also get stored on the stack
 *
 * first we will call our growsUp function that takes in a pointer to an int,
 * and give it NULL first we then create a variable x of type int, and check if
 * the function was given a pointer if not, we will recursively call the
 * function again, passing it the x variable memory location we just created if
 * there is a pointer given we compare the address of the passed in pointer to
 * the address of our newly created int x variable
 *
 */

bool growsUp(int *addr) {

  int x;

  // Base case
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
