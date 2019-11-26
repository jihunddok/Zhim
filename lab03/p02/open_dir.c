/**
 * open_dir.c
 * author shim jihun
 * since 2019.11.11
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dirent;

    if(argc < 2)
    {
        fprintf(stderr, "사용 방법 : %s <path name>\n", argv[0]);
        exit(1);
    }

    if((dir = opendir(argv[1])) < 0)
    {
        printf("open failed.\n");
        exit(1);
    }

    // dirent d_name = 파일 이름 , d_ino = 디렉토리 inode 번호
    while((dirent = readdir(dir)) != NULL)
    {
        printf("%s %ld\n", dirent->d_name, dirent->d_ino);
    }

    closedir(dir);

    return 0;
}
