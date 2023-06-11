## Files in this Directory
* `Makefile` - Type `make` to build the program.
* `README.md` - This README.
* `Search.c` - Implementation of the search utility.
* `Search.h` - Header file for the search utility.
* `Solver.c` - Implementation of the Wordle Solver.
* `vocabulary.txt` - Text file containing all possible Wordle answers.

## Details
This project was adapted from an assignment given in CSE 13S (Computer Systems and C Programming) taught by Alex
Rudnick at UC Santa Cruz. This is a rudimentary solver, programmed in C, for the online word game *Wordle*.

## Usage
While in the WordleSolver directory within the terminal, type `make`. The solver can be used in two ways:

Run the program by typing `./Solver <5-letter word>`. This specifies a word that the solver will search toward.

Run the program by typing `./Solver`. The program will prompt you with a first guess to use. Use the feedback
provided by Wordle to tell the program the results of each guess by typing a 5-letter string containing the
letters 'x' (gray), 'y' (yellow), and/or 'g' (green). The program will continue to provide optimized guesses
until provided with the string 'ggggg' or there are no potential guesses from the vocabulary list left that fit
the given feedback.
