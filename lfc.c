#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(){
    FILE *fp;
    char cwd[BUFF_SIZE];
    DIR *dir;
    struct dirent *ent;
    char *buffer;
    long filelen;

    if(getcwd(cwd, sizeof(cwd)) == NULL){
        perror("getcwd");
        return 0;
    }

    dir = opendir(cwd);
    if(dir == NULL){
        perror("opendir");
        return 0;
    }

    while((ent = readdir(dir)) != NULL){;
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) continue;
        printf("----------------------------------\n%s:\n\n", ent->d_name);

        fp = fopen(ent->d_name, "rb");

        fseek(fp, 0, SEEK_END);
        filelen = ftell(fp);
        rewind(fp);

        buffer = (char *) malloc((filelen + 1) * sizeof(char));
        fread(buffer, filelen, 1, fp);
        fclose(fp);

        buffer[filelen] = '\0';
        printf("%s\n", buffer);

        free(buffer);
    }

    closedir(dir);

    return 0;
}