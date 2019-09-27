#include <stdio.h>
#include <stdlib.h>
#include "input_manager.h"

#define NUM_DIFF 10
#define LETTER_DIFF 26

int encrypt(FILE** input_file, FILE** output_file, int k) {
  int curr ;
  
  while ((curr = read_char_from_file(input_file)) != -1) {
    int res;

    if (curr >= 48 && curr <= 57) {
      res = ((curr - 48 + k) % NUM_DIFF) + 48;
    } else if (curr >= 65 && curr <= 90) {
      res = ((curr - 65 + k) % LETTER_DIFF) + 65;
    } else if (curr >= 97 && curr <= 122) {
      res = ((curr - 97 + k) % LETTER_DIFF) + 97;
    } else {
      res = curr;
    }

    if (write_char_to_file(output_file, res) == -1)
      return 0;
  }

  return 1;
}

int decrypt(FILE** input_file, FILE** output_file, int k) {
  int curr ;
  
  while ((curr = read_char_from_file(input_file)) != -1) {
    int res;

    if (curr >= 48 && curr <= 57) {
      res = (abs((curr - 48 - k)) % NUM_DIFF) + 48;
    } else if (curr >= 65 && curr <= 90) {
      res = (abs((curr - 65 - k)) % LETTER_DIFF) + 65;
    } else if (curr >= 97 && curr <= 122) {
      res = (abs((curr - 97 - k)) % LETTER_DIFF) + 97;
    } else {
      res = curr;
    }

    if (write_char_to_file(output_file, res) == -1)
      return 0;
  }

  return 1;
}