#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"


char buffer[42069]; //@TODO make this dynamically sized

void head(int fd){ //fd file descriptor
  int i, n, l;
  while((n = read(fd,buffer,sizeof(buffer))) > 0){
    for(i = 0; i < n; ++i){
      printf(1, "%s", buffer[i]);
      if(buffer[i] == '\n'){

        ++l;

      }
    }
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
  }
  exit();
}
