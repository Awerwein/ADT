#include <stdlib.h>
#include <stdio.h>

struct Link{
  int key;
  struct Link *next;
  int sent;
};

// struct List {
//   struct Link *sentinel;
// };

struct Link* init(){
  struct Link* sentinel = malloc(sizeof(struct Link));
  sentinel->key = 0;
  sentinel->next = sentinel;
  sentinel->sent = 1;
  return sentinel;
}

void insert (struct Link *l, int k){
  struct Link* newLink = malloc(sizeof(struct Link));
  newLink->key = k;
  newLink->sent = 0;
  newLink->next = l->next;
  l->next = newLink;
}

struct Link* search(struct Link *l, int k){
  struct Link* current = l->next;
  while (current->key != k && current->sent == 0) {
    current = current->next;
  }
  if (current->key == k) {
    return current;
  }
  printf("%d not found\n", k);
  return NULL;
}

void deleteLink (struct Link* l, int k) {
  struct Link* prev = search(l->next, k);
  if (prev != NULL) {
    struct Link* deletedLink = prev->next;
    prev->next = deletedLink->next;
    free(deletedLink);
  }
  return;

}

int main(int argc, char const *argv[]) {
  struct Link* L = init();
  printf("%d\n", L->sent);
  insert(L, 4);
  printf("%d\n", L->next->key);
  deleteLink(L, 4);
  search(L, 4);

  return 0;
}
