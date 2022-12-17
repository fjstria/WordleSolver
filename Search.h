/*
 * FJ Tria
 * Search.h
 * Header file for the search utility used in Wordle Solver.
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int score_letter(char letter, char **word_bank, int word_count);
// Generates a score for an individual letter.

int score_word(char *word, int *letter_scores);
// Generates a score for a word by summing the scores of each individual letter.
// Repeat letters add to score only once.

char *get_guess(char **word_bank, int word_count);
// Generates the best possible guess by selecting the word from the word bank that
// has the highest score.

int filter_gray(char letter, char **word_bank, int word_count);
// Removes words that contain the letter from the word bank. The slot that removed
// words reside in is set to NULL.

int filter_yellow(char letter, int position, char **word_bank, int word_count);
// Removes words that contain the letter in a given position. The slot that
// removed words reside in is set to NULL.

int filter_green(char letter, int position, char **word_bank, int word_count);
// Removes words that do not contain the letter in a given position. The slot that
// removed words reside in is set to NULL.

void free_word_bank(char **word_bank, int word_count);
// Frees the memory allocated to the word bank.
