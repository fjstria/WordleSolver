/*
 * FJ Tria
 * Demo.c
 * Demo file for the Wordle Solver.
 */

#include "Search.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif", "tense",
    "ultra", "vital", "ether", "nadir" };

  char **vocabulary = calloc(10, sizeof(char *));
  for (int i=0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  free_vocabulary(vocabulary, num_words);
  
  return 0;
}
