#include "types.h"
#include "user.h"
#include "stat.h"

char buffer[512]; //@TODO make this dynamically sized

void head(int fd){ //fd file descriptor
  int i, n, l;
  while(n = read(fd,buffer,sizeof(buffer)) > 0){
    for(i = 0; i < n; ++i){
      printf(1, buffer[i]);
      // if(buffer[i] == "\n"){
      //
      //   ++l;
      //
      // }
    }
  }
}

int main(int argc, char* argv[]){
  int fd;
  if (argc <= 1){
    head(0);
  }
  else{
    fd = open(argv[1]);
    head(fd);
  }

}
