#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.c"

int main(){
  struct song_node * f = insert_order(NULL,"food","down");
  f = insert_order(f, "gref", "jerrison");
  f = insert_order(f,"grief", "jerrison");
  f = insert_order(f,"shark", "kerrison");
  print_list(f);
  free_list(f);
  print_list(f);
}
