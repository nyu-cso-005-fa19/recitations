#include <stdio.h>

void initialize(int* k, char** file_name, char* encrypt_input) {
  printf("Hello! Welcome to the Caeser Cipher program.\n");
  printf("\nWould you like to (e)ncrypt or (d)crypt: ");
  scanf("%c", encrypt_input);
  printf("What is the number of shifts in your scheme (k): ");
  scanf("%d", k);
  printf("Name of the file you would like to process: ");
  scanf("%s", *file_name);
  printf("\nPlease wait while we process your input.\n");
}

void open_file(FILE** file_pointer, char** file_name, char* file_mode) {
  *file_pointer = fopen(*file_name, file_mode);
}

void close_file(FILE** file_pointer) {
  fclose(*file_pointer);
}

int read_char_from_file(FILE** input_file) {
  return fgetc(*input_file);
}

int write_char_to_file(FILE** output_file, int c) {
  return fputc(c, *output_file);
}