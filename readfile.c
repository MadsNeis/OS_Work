/* Madison Neiswonger
* CS 374
 * 1/1/26
 * Project 1.1
 */
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char buffer[2048];
    int fd;
    ssize_t read_bytes;

    fd = open(argv[1], O_RDONLY);
    read_bytes = read(fd, buffer, 2048);

    write(1, buffer, read_bytes);

    close(fd);
}