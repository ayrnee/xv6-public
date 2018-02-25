#define NULL ((char *)0)
#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"


// char buffer[512]; //@TODO make this dynamically sized

int strToInt(char* arg){
  char* ptr = arg;
  ++ptr;
  int len = 0;
  for (; *ptr != '\0'; ++ptr){
    // printf(1, "%c\n",*ptr);
    ++len;
  }
  char val[len];
  for (int i = 0; i < len ; ++i){
    val[i] = arg[i+1];
  }
  printf(1,"%d\n",atoi(val));
  return atoi(val);
}

char* genBuffer(){
  int size = 1024;
  char *buffer = malloc(size * sizeof(char));
  while (buffer == NULL && size > 0){
    size = size/2;
    buffer = malloc(size * sizeof(char));
  }
  return buffer;
}

void head(int fd, int maxLines){ //fd file descriptor
  char *buffer = genBuffer();
  if (!buffer){
    exit();
  }
  printf(1,"%d\n", maxLines);
  int l = 0;
  int i;

  int n = read(fd,buffer,sizeof(buffer));
  while(n > 0 && l < maxLines){
      for(i = 0; i < n; ++i){
        if(buffer[i] == '\n'){
          ++l;
          if (l >= maxLines){
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
    head(0,10);
    exit();
  }
  else{
    if ( argc == 2 && argv[1][0] == '-' ){
      // printf(1,"%s\n",argv[1]);
      // printf(1,"%d\n",atoi(argv[1]));
      strToInt(argv[1]);
      head(0,atoi(argv[1]));
      exit();
    }
    else if( argc == 2 ){
      fd = open(argv[1], O_RDONLY);
      head(fd,10);
      close(fd);
      exit();
    }
    else if (argc >= 4){
      exit();
    }
    else{
      fd = open(argv[2], O_RDONLY);
      head(fd,(-1)*atoi(argv[1]));
      close(fd);
      exit();
    }

  }
  exit();
}
