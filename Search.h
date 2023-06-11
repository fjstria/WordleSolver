/*
 * FJ Tria (@fjstria)
 * WordleSolver/Search.h
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// int score_letter()
// Generates a score for a given letter.
int score_letter(char letter, char **vocabulary, size_t num_words);

// int score_word()
// Generates a score for a given word by summing the scores of its letters. Repeat letters are not scored more
// than once.
int score_word(char *word, int *letter_scores);

// char *get_guess()
// Returns the word with the highest score.
char *get_guess(char **vocabulary, size_t num_words);

// size_t filter_vocabulary_gray()
// Removes words from the array of potential guesses that contain a given letter.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words);

// size_t filter_vocabulary_yellow()
// Removes words from the array of potential guesses that contain a given letter in a given position.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary, size_t num_words);

// size_t filter_vocabulary_green()
// Removes words from the array of potential guesses that do not contain a given letter in a given position.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary, size_t num_words);

// void free_vocabulary()
// Frees the memory allocated to the array of potential guesses.
void free_vocabulary(char **vocabulary, size_t num_words);
