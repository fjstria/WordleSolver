/*
 * FJ Tria (@fjstria)
 * WordleSolver/Search.c
 */

#include "Search.h"

int score_letter(char letter, char **vocabulary, size_t num_words) {
  int score = 0;
  for(size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {  // this word is invalid, do not count
      continue;
    }
    for(size_t j = 0; j < 5; j++) {
      if (vocabulary[i][j] == letter) {  // check if this is the letter we want
        score++;
        break;  // only find first instance of the letter in this word, avoid others
      } 
    }
  }
  return score;
}


int score_word(char *word, int *letter_scores) {
  int score = 0;
  char letters_used[] = "_____";  // array will be edited as loop happens
  for (int i = 0; i < 5; i++) {
    bool found = false;  // a flag for checking if a letter has already been accounted for
    for (int j = 0; j < 5; j++) {
      if (word[i] == letters_used[j]) {  // find the letter in letters_used
        found = true;  // letter found
      }
    }
    if (found) {
      continue;  // skip the letter if found
    }
    else {
      score += letter_scores[word[i]-'a'];  // add the letter's score to score
    }                                       // word[i] - 'a' maps each letter to an int 0-25
    letters_used[i] = word[i];  // add the letter to letters_used
  }
  return score;
}


char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}


size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
  size_t count = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;  // this word has already been removed, skip it
    }
    for (int j = 0; j < 5; j++) {
      if (vocabulary[i][j] == letter) {  // letter that's not in secret word found, remove word
        char *temp = vocabulary[i];
        free(temp);
        vocabulary[i] = NULL;
        count++;  // count this word as removed
        break;  // word doesn't exist anymore, don't search further
      }
    }
  }
  return count;
}


size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words) {
  size_t count = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) { 
      continue;  // this word has already been removed, skip it
    }
    if (vocabulary[i][position] == letter) {  // letter should not be in this position, remove word
      char *temp = vocabulary[i];
      free(temp);
      vocabulary[i] = NULL;
      count++;
    }
    else {
      bool found = false;  // flag for checking if the letter is in the word
      for (int j = 0; j < 5; j++) {
        if (vocabulary[i][j] == letter) {
          found = true;  // letter is found
          break;  // no need to check the word further
        }
      }
      if (!found) {  // if the letter is not found, remove the word
        char *temp = vocabulary[i];
        free(temp);
        vocabulary[i] = NULL;
        count++;
      }
    }
  }
  return count;
}


size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words) {
  size_t count = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;  // this word has already been removed, skip it
    }
    if (vocabulary[i][position] == letter) {  // this char is in the right spot, skip this word
      continue;
    }
    else {  // missing correct letter, remove this word
      char *temp = vocabulary[i];
      free(temp);
      vocabulary[i] = NULL;
      count++;
    }
  }
  return count;
}


void free_vocabulary(char **vocabulary, size_t num_words) {
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
