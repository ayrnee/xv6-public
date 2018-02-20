#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"


char buffer[512]; //@TODO make this dynamically sized

void head(int fd){ //fd file descriptor
  int i, n, l;
  while((n = read(fd,buffer,sizeof(buffer))) > 0){
      write(1, buffer, n);
        ++l;
        ++i;
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
  }
  exit();
}
