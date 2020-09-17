#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "avltree.h"

// Lista de keywords em C
static const char *names[] = {
  "auto",
  "break",
  "case",
  "char",
  "const",
  "continue",
  "default",
  "do",
  "double",
  "else",
  "enum",
  "extern",
  "float",
  "for",
  "goto",
  "if",
  "inline",
  "int",
  "long",
  "register",
  "restrict",
  "return",
  "short",
  "signed",
  "sizeof",
  "static",
  "struct",
  "switch",
  "typedef",
  "union",
  "unsigned",
  "void",
  "volatile",
  "while",
  "_Alignas",
  "_Alignof",
  "_Atomic",
  "_Bool",
  "_Complex",
  "_Generic",
  "_Imaginary",
  "_Noreturn",
  "_Static_assert",
  "_Thread_local"
};

int main() {
  srand(time(NULL));

  avltree *t = avltree_create();
  avltree_show(t);

  int count = (sizeof names / sizeof *names);

  printf("Testando INSERÇÕES...\n");
  // Vamos inserir em ordem aleatória para testar!
  while(avltree_size(t) < count) {
    int i = rand() % count;
    // Se já não inserimos...
    if(avltree_lookup(t, names[i]) == 0) {
      printf("* Inserindo %s, com valor %d...\n", names[i], i + 1);
      avltree_insert(t, names[i], i + 1);

      // Estamos MESMO balanceados após inserir um nó aleatório?
      assert(avltree_balanced(t));
    }
  }

  printf("Testando REMOÇÕES...\n");
  while(avltree_size(t) > 0) {
    int i = rand() % count;
    // Se já não removemos...
    if(avltree_lookup(t, names[i]) > 0) {
      printf("* Removendo %s...\n", names[i]);
      avltree_remove(t, names[i]);

      // Estamos MESMO balanceados após remover um nó aleatório?
      assert(avltree_balanced(t));
    }
  }

  avltree_delete(t);

  return EXIT_SUCCESS;
}
