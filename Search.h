/*
 * FJ Tria
 * Search.h
 * Header file for search utility. 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int score_letter(char letter, char **vocabulary, size_t num_words);
// Generates a score for a given letter.

int score_word(char *word, int *letter_scores);
// Generates a score for a given word by summing the scores of its letters. Repeat
// letters are not scored more than once.

char *get_guess(char **vocabulary, size_t num_words);
// Returns the word with the highest score.

size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words);
// Removes words in vocabulary that contain a given letter.

size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
        size_t num_words);
// Removes words in vocabulary that contain a given letter in a certain position.

size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
        size_t num_words);
// Removes words in vocabulary that do not contain a given letter in a certain
// position.

void free_vocabulary(char **vocabulary, size_t num_words);
// Frees the memory allocated to the vocabulary list.
