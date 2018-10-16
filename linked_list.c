#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};




void print_list(struct song_node * n){
  while(n){
    printf("Artist: %s\t", n->artist);
    printf("Name: %s\n", n->name);
    n = n->next;
  }
}

struct song_node * insert_front(struct song_node * n, char x[100], char z[100]){
  struct song_node *ans = malloc(sizeof(struct song_node));
  strcpy(ans->name,x);
  strcpy(ans->artist,z);
  ans->next = n;
  return ans;
}


struct song_node * insert_any(struct song_node* n, char x[100], char z[100], struct song_node * last){
  struct song_node * ans = insert_front(n,x,z);
  if(last){
    last->next = ans;
  }
  return ans;
}

struct song_node * insert_order(struct song_node* n, char x[100], char z[100]){
  struct song_node * last;
  struct song_node * first = n;
  while(n){
    if(strcmp(n->artist,z) <= 0){
      if(last){
	return insert_any(n,x,z,last);
      }
      else{
	return first;
      }
    }
    last = n;
    n = n->next;
  }
   return insert_any(NULL,x,z,last);
}


struct song_node * free_list(struct song_node * n){
  struct song_node * f = n;
  while(f->next){
    free(f);
    f=f->next;
  }
  free(f);
  return n;
}

int main(){
  struct song_node * f = insert_front(NULL,"food","down");
  f = insert_order(f, "gref", "jerrison");
  print_list(f);
}
