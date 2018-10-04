#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<stdio.h>

#define BUF_SIZE 1024


//fread() fwrite() fopen()
bool is_vowel(char c) {
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || \
      c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O'){
          }
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    int i;
    int j;
    for(i = 0; i < num_chars; i++){
      if( !is_vowel(in_buf[i]) ){
        out_buf[j] = in_buf[i];
        j++;
      }
    }
    return j;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  char *in_buf = (char*)calloc(BUF_SIZE, sizeof(char));
  char *out_buf = (char*)calloc(BUF_SIZE, sizeof(char));

  size_t num_read= fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
  while(num_read != 0){
    int num_non_vowels = copy_non_vowels(num_read, in_buf, out_buf);
    fwrite(out_buf, sizeof(char), num_non_vowels, outputFile));
    num_read= fread(in_buf, sizeof(char), BUF_SIZE, inputFile);

  }
  //size_t num_write = fwrite(out_buf, sizeof(char), out_size, outputFile);

}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    inputFile= fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");
    disemvowel(inputFile, outputFile);

    return 0;
}
