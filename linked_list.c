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

void print_node(struct song_node * n){
    printf("Artist: %s\t", n->artist);
    printf("Name: %s\n", n->name);
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
  struct song_node * last = NULL;
  struct song_node * first = n;
  printf("%s",n->artist);
  while(n){
    if(strcmp(n->artist,z) >= 0){
      if(!last){
	printf("\n--%s %s--%s %s\n",z,x,n->artist,n->name);
	return insert_any(n,x,z,last);
      }
      else{
	printf("\n--%s %s--%s %s--%s %s--\n", last->artist, last->name, z, x, n->artist,n->name);
	insert_any(n,x,z,last);
	return first;
      }
    }
    last = n;
    n = n->next;
  }
   insert_any(NULL,x,z,last);
   return first;
}

struct song_node * remove_song(struct song_node * wole, struct song_node * bye){
  /* struct song node * next_so = bye.next; */
  /* free(bye); */
  /* insert_order(wole, next_so->name, next_so.artist) */
  struct song_node * neext = wole->next;
  if(wole == bye){
    free(wole);
    return neext;
  }
  struct song_node * last = wole;
  while(neext){
    if(neext == bye){
      last->next = neext->next;
      free(neext);
      return neext;
    }
    last = neext;
  }
}

struct song_node * free_list(struct song_node * n){
  struct song_node * f = n;
  while(f){
    free(f);
    f=f->next;
  }
  free(f);
  return n;
}

struct song_node * search_artist(struct song_node * song, char * name){ 
  while(song){
    if(!strcmp(song->artist,name)){
      return song;
    }
    song = song->next;
  }
  return NULL;
}

struct song_node * search(struct song_node * song, char * song_name, char * name){ 
  while(song){
    if(!(strcmp(song->artist,name) + strcmp(song->name,song_name))){
      return song;
    }
    song = song->next;
  }
  return NULL;
}

