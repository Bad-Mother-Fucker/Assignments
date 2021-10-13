#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define READLINE_READ_SIZE sizeof(char)*11121


char * resize_buffer(char * buf, size_t oldDIm,size_t newSize) {
    if(buf == NULL) {
        buf = (char *)malloc(newSize);
        return buf;
    }
    char * newBuffer = (char *) malloc(newSize);
    for(int i = 0; i<oldDIm; i++) {
        newBuffer[i] = buf[i];
    }
    free(buf);
    return newBuffer;

}

char *my_readline(int fd){
    if(fd < 0) {
        return NULL;
    }

    static char* buffer = NULL; // buffer to store bytes read from stream
    ssize_t read_bytes = 0; // number of bytes read from stream
    char *new_line; // line to return 
    int i=0,j=0; // indexes for strings

    // Read buffer if it is the first time
    if(buffer == NULL) {
        size_t dim = READLINE_READ_SIZE;

        do {
            int oldDim = dim - READLINE_READ_SIZE;
            buffer = resize_buffer(buffer,oldDim,dim);
            read_bytes = read(fd, (char *)buffer+oldDim, READLINE_READ_SIZE);

            if (READLINE_READ_SIZE > read_bytes && read_bytes > 0 && dim == READLINE_READ_SIZE) {
                buffer[read_bytes] = '\0';
                break;
            } else if(read_bytes == 0) {
               buffer[oldDim] = '\0';
            }
            dim += read_bytes;

        }while(read_bytes>0);

        if(read_bytes == -1){
            printf("error in read()");
            return NULL;
        }
    }

    // Check if stream is empty
    if(buffer[0] == '\0' || buffer[0] == EOF) {
        return NULL;
    }

    // Skip LF and CR characters, if there are
    while(buffer[0] == '\n' || buffer[0] == '\r') {
            buffer++;
    }

    // Count number of valid characters in line 
    while(buffer[i] != '\n' && buffer[i] != '\r' &&
            buffer[i] != '\0' && buffer[i] != EOF) {
            i++;
    }
    // If no valid characters are found, return NULL
    if(i == 0) {
        return NULL;
    }

    new_line = (char *) malloc(i+1);
    for(j=0; j<i; j++) {
        new_line[j] = buffer[j];
    }
    new_line[j] = '\0';
    
    // Go to next line
    buffer += i;
    
    return new_line;
}

int my_strlen(char* str) {
    int i=0;

    if(str==NULL) return -1;
    while(str[i]!='\0') i++;

    return i;
}


int main(int argc, char *argv[]){
    int fd;
    char* line;

    if(argc == 1) {
        fd = 0;
    } else if(argc == 2) {
        printf("Trying to open %s\n", argv[1]);
        fd = open(argv[1], O_RDONLY);
        if(fd == -1) {
           perror("Error opening ");
            return -1;
        }
    }


    do {
        line = my_readline(fd);
        if(line != NULL) {
            printf("%s\n", line);
            free(line);
        }
    } while(line != NULL);

    printf("\nStream read completed\n");


    if(fd != 0) {
        close(fd);
    }

    return 0;
}
