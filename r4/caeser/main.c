#include <stdio.h>
#include <string.h>
#include "input_manager.h"
#include "cipher_manager.h"

#define RESULT_FILE_NAME "RESULT"

int main() {

  int k;
  char* in_file_name;
  char encrypt_input;
  initialize(&k, &in_file_name, &encrypt_input);

  if (encrypt_input != 'e' && encrypt_input != 'd') {
    printf("Something went wrong while you were inputting your request.\n");
    printf("You may only enter \'e\' for encryption and \'d\' for decryption.\n");
    printf("Please try again.");

    return 2;
  }

  FILE* in_file;
  open_file(&in_file, &in_file_name, "r");

  if (in_file == NULL) {
    printf("No file named %s found. Please try again.\n", in_file_name);

    return 3;
  }

  FILE* out_file;
  char* out_file_name = RESULT_FILE_NAME;
  open_file(&out_file, &out_file_name, "w");

  int res;
  if (encrypt_input == 'e') {
    res = encrypt(&in_file, &out_file, k);
  } else {
    res = decrypt(&in_file, &out_file, k);
  }

  close_file(&in_file);
  close_file(&out_file);

  if (res == 0) {
    printf("Something went wrong while encrypting or decrypting your file.\n");
    printf("Please try again later.\n");

    return 4;
  }
  
  printf("Your operation was successfully completed. See %s for the output.\n", RESULT_FILE_NAME);
  return 0;
}