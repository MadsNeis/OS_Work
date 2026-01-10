/* Madison Neiswonger
* CS 374
 * 1/1/26
 * Project 1.1
 */

#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char buffer[2048];
    ssize_t read_bytes;
    int fd;

    if (argc == 1){
        fd = 0;
        while ((read_bytes = read(fd, buffer, 2048)) > 0){
          for (int i = 0; i <read_bytes; i++){
            buffer[i] = toupper(buffer[i]);
          }
            write(1, buffer, read_bytes);
        }
    } else {
        for (int i = 1; i < argc; i++){
            fd = open(argv[i], O_RDONLY);
            while ((read_bytes = read(fd, buffer, 2048)) > 0){
              for (int j = 0; j <read_bytes; j++){
                buffer[j] = toupper(buffer[j]);
              }
                write(1, buffer, read_bytes);
            }
            close(fd);
        }
    }
    return 0;
}