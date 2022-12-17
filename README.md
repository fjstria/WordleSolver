*ftria@ucsc.edu*

# Implementation
## score_letter
This function will count the amount of words that contain a certain letter in any place. An
int `score` will keep track of this number.

A for loop will increment indexes to represent the words in `vocabulary`. If the word is
`NULL`, then the loop will `continue` in order to skip that word.

An inner for loop will increment indexes to represent each position in the word, 0 through 4.
Within both loops, if the character in the position being looked at, in the word being looked
at, is equivalent to `letter`, `score` will be incremented and the inner for loop will
`break`.

At the end of both for loops, the function will return `score`.


## score_word
This function will sum up the score of each unique letter in a given word. An int `score`
will keep track of the sum and a char array `letters_used` will keep track of the letters
that have already contributed to the sum.

A for loop will use an int `i` to iterate through every possible position a letter could be 
at in the word. A bool variable `found` is set to `false` at default.

An inner for loop will use an int `j` to iterate through every possible
position again. If the char at word position `i` matches letters_used position `j`, then
the letter has been found, so `found` is set to `true`.

Outside the inner for loop, an if statement checks if `found` is `true`, and if so, will
`continue` past this letter. Otherwise, the score of the letter, which is retreived by
accessing the `letter_scores` index number given by subtracting `'a'` from the letter, is
added onto `score`. At the end of the function, it returns `score`.


## filter_vocabulary_gray
This function will filter words that contain a certain letter within them and return the
number of words that have been filtered. A size_t `count` will keep track of the number of
words filtered.

A for loop will go through the indexes that represent each word. If the current index of
`vocabulary` is `NULL`, then the loop will `continue` past that word.

An inner for loop will go through each possible position a letter could be in within a word,
0 through 4. Within both for loops, if the position currently being looked at of the word 
currently being looked at is equivalent to letter, then the word will be assigned to a
char * variable `temp`. `temp` will be freed, then the index of the word in vocabulary will
be set to `NULL`. Count will be incremented by 1 and the inner for loop will `break`.

At the end of all loops, the function will return `count`.

## filter_vocabulary_yellow
This function will filter words that have a letter in a certain position or do not have that
letter present in them at all and return the number of words that have been filtered. A
size_t `count` will keep track of the number of words filtered.

A for loop will go through the indexes that represent each word. If the current index of
`vocabulary` is `NULL`, then the loop will `continue` past that word.

If the char at the specified `position` of the word of the current iteration is equivalent to
`letter`, then the word will be assigned to a char * variable `temp`. `temp` will be freed,
then the index of the word in vocabulary will be set to `NULL`. Count will be incremented by
1.

Otherwise, a bool `found` will be defaulted to `false`. An inner for loop will iterate from 0
to 5, to represent the positions a letter could be in. If the char at the index specified by
the inner for loop of the word specified by the outer for loop is equivalent to `letter`,
then `found` is set to `true` and the inner for loop will `break`.

An if statement will check if `found` is `false`. If so, then the word currently being looked
at will be assigned to a char * variable `temp`. `temp` will be freed, then the index of the
word in vocabulary will be set to `NULL`. Count will be incremented by 1 and the inner for
loop will `break`.

At the end of the function, `count` will be returned.


## filter_vocabulary_green
This function will filter words that do not contain a specified letter at a specified
position and return the number of words that have been filtered. A size_t `count` will keep
track of the number of words filtered.

A for loop will go through the indexes that represent each word.

If the current index of `vocabulary` is `NULL`, then the loop will `continue` past that word.

If the specified `position` within the current index of `vocabulary` is equivalent to
`letter`, the function will `continue` past that word.

Otherwise, the word will be assigned to a char * variable `temp`. `temp` will be freed, then
the index of the word in vocabulary will be set to `NULL`. Count will be incremented by 1.

After the for loop, the funtion will return `count`.
