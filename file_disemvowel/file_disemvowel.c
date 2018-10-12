#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include<stdio.h>

#define BUF_SIZE 1024


//fread() fwrite() fopen()
bool is_vowel(char c) {
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || \
      c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O'){
        return true;
          }
  return false;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    int i;
    int j = 0;
    for(i = 0; i < num_chars; i++){
      if(is_vowel(in_buf[i]) == false ){
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
    //printf("We read %d chars\n", num_read);
    int num_non_vowels = copy_non_vowels(num_read, in_buf, out_buf);
    //printf("We copied %d chars\n", num_non_vowels);
    fwrite(out_buf, sizeof(char), num_non_vowels, outputFile);
    num_read= fread(in_buf, sizeof(char), BUF_SIZE, inputFile);

  }
  //size_t num_write = fwrite(out_buf, sizeof(char), out_size, outputFile);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    if(argc == 1){
      //takes 0
      inputFile = stdin;
      outputFile =stdout;

    }
    // int n;
    // for(n = 0; n < argc; n++){
    //   puts(argv[n]);
    // }
     if(argc == 3 ){
       //takes 0, 1, 2
       inputFile= fopen(argv[1], "r");
       outputFile = fopen(argv[2], "w");

     }

     if(argc == 2){
       //takes 0, 1
        inputFile= fopen(argv[1], "r");
        outputFile =stdout;
     }

     disemvowel(inputFile, outputFile);
     //arg[0] takes everything. arg 1 and arg 2


    return 0;
}


//find find the name of files in this case, flag count the files or directories
//wc count the number of files or directoly
