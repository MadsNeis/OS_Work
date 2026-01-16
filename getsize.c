/* Madison Neiswonger
    * CS 374
 * 1/15/26
 * ICC 2.2
 */

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  // Check if argc is correct
  if (argc < 2){
    fprintf(stderr, "Usage: getsize file [ file ... ]\n");
    return 1;
    }

  for(int i = 1; i < argc; i++){

    struct stat sb;

    if(stat(argv[i], &sb) == 0 ) {

      printf("%s: %lld\n", argv[i], (long long)sb.st_size);
    } else {
      printf("%s: ", argv[i]);
      perror("");
    }
  }
  return 0;
}