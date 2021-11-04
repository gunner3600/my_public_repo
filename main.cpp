#include "main.h"

GaitState g_state;

int main(int argc, char *argv[]) {
  g_state.m_class.add_test();
  int a = 3;
  square_fun(a);
  printf("hello: %d\n", a);
  return 0;
}