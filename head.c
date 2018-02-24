#define NULL ((char *)0)
#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"


// char buffer[512]; //@TODO make this dynamically sized


char* genBuffer(){
  int size = 1024;
  char *buffer = malloc(size * sizeof(char));
  while (buffer == NULL && size > 0){
    size = size/2;
    buffer = malloc(size * sizeof(char));
  }
  return buffer;
}
void head(int fd){ //fd file descriptor
  char *buffer = genBuffer();
  if (!buffer){
    exit();
  }

  int l = 0;
  int i;

  int n = read(fd,buffer,sizeof(buffer));
  while(n > 0 && l < 10){
      for(i = 0; i < n; ++i){
        if(buffer[i] == '\n'){
          ++l;
          if (l >= 10){
            write(1, buffer, i);
            return;
          }
        }
      }
      write(1, buffer, n);
      n = read(fd,buffer,sizeof(buffer));
  }
}

int main(int argc, char* argv[]){
  int fd;
  if (argc <= 1){
    head(0);
    exit();
  }
  else{
    fd = open(argv[1], O_RDONLY);
    head(fd);
    close(fd);
    exit();
  }
  exit();
}
