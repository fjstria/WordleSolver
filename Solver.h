/*
 * FJ Tria
 * Solver.h
 * Header file for Wordle Solver.
 */

#pragma once
#include "Search.h"

bool score_guess(char *answer, char *guess, char *result);
// Returns true if guess is an exact match with answer. Fills in result with the
// following:
// - 'x' goes in a slot if the corresponding letter in guess does not appear
//   anywhere in answer.
// - 'y' goes in a slot if the corresponding letter in guess appears in answer,
//   but not in the corresponding slot.
// - 'g' goes in a slot if the corresponding letter in guess appears in the
//   corresponding slot in answer.

char **load_word_bank(char *file, int *word_count);
// Returns an array of strings where each string contains a word from the
// specified file. The file is assumed to contain 5-letter words, one per line.
// This function sets the value pointed at by *word_count to be the number of
// words read.
