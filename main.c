#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.c"

int main(){
  printf("q");
  struct song_node * f = insert_order(NULL,"food","down");
  printf("0");
  f = insert_order(f, "gref", "jerrison");
  printf("1");
  f = insert_order(f,"grief", "jerrison");
  printf("2");
  f = insert_order(f,"shark", "kerrison");
  printf("3");
  print_node(f);
  print_list(f);
  free_list(f);
  print_list(f);
}
