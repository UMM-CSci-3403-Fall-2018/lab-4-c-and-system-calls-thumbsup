#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

#define BUF_SIZE 1024
static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb int typeflag){


}
bool is_dir(const char* path) {
  struct stat *buf = (struct stat*)calloc(BUF_SIZE, sizeof(struct stat));
  int answer = stat(path, buf);
  if(answer == 0){
    if(S_ISDIR(buf->st_mode)){
      return true;
    } else {
      return false;
    }
  } else {
    // print and die
    exit(1);
  }
  /*
   * Use the stat() function (try "man 2 stat") to determine if the file
   * referenced by path is a directory or not.  Call stat, and then use
   * S_ISDIR to see if the file is a directory. Make sure you check the
   * return value from stat in case there is a problem, e.g., maybe the
   * the file doesn't actually exist.
   */
 }

/*
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

void process_directory(const char* path) {
  DIR *dir = opendir(path);
  chdir(path);
  num_dirs = num_dirs + 1;
  while(struct dirent *entry = readdir(dir)){
    // entry->d_name is the filename of this entry
    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..")!= 0) {
      process_path(entry->d_name);
    }
  }
  chdir("..");

  closedir(dir);

  //chdir give the home address to fred.
  //increment counter
  /*
   * Update the number of directories seen, use opendir() to open the
   * directory, and then use readdir() to loop through the entries
   * and process them. You have to be careful not to process the
   * "." and ".." directory entries, or you'll end up spinning in
   * (infinite) loops. Also make sure you closedir() when you're done.
   *
   * You'll also want to use chdir() to move into this new directory,
   * with a matching call to chdir() to move back out of it when you're
   * done.
   */
}

void process_file(const char* path) {
  num_regular = num_regular + 1;

  // while(files = readdir(path)){
  //   num_regular = num_regular + 1;
  //   process_path(files);
  // }
  // chdir("..");
  // closedir()
  /*
   * Update the number of regular files.
   */
}

void process_path(const char* path) {
  //printf("Processing path %s.\n", path);
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  ftw(argv[1], callback, MAX_FTW_DEPTH);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
