/***********************************************************/
//     File Name   : file_operation.c
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 12:42:51 PM CST
/**********************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <fcntl.h>

void Print_FileTypeAndPermissions( struct stat *pststat )
{
    switch( pststat->st_mode & S_IFMT )
    {
        case S_IFDIR:
            printf("This is a Directory.\n");
            break;
        case S_IFREG:
            printf("This is a Regular file.\n");
            break;
        case S_IFCHR:
            printf("This is a Character device.\n");
            printf("\tSpecial device: %d.\n", (int)pststat->st_rdev);
            break;
        case S_IFBLK:
            printf("This is a Block device.\n");
            printf("\tSpecial device: %d.\n", (int)pststat->st_rdev);
            break;
        case S_IFIFO:
            printf("This is a named PIPO file.\n");
            break;
        default:
            printf("Unknown type of file.\n");
            break;
    }
    
    if(pststat->st_mode & S_ISUID)
    {
        printf("\tSet UID.\n");
    }
    if(pststat->st_mode & S_ISGID)
    {
        printf("\tSet GID.\n");
    }
    if(pststat->st_mode & S_ISVTX)
    {
        printf("\tSet Sticky.\n");
    }

    printf("\tPermission : %o.\n", pststat->st_mode &  0777 );
    
    return ;
}

void Print_UserAndGroup( struct stat *pststat )
{
    struct passwd *pstpwd;
    struct group  *pstgrp;

    pstpwd = getpwuid(pststat->st_uid);
    pstgrp = getgrgid(pststat->st_gid);

    printf("\tUID: %d Name: %s\n", pststat->st_uid, pstpwd->pw_name);
    printf("\tGID: %d Name: %s\n", pststat->st_gid, pstgrp->gr_name);
    return ;
}

void Print_AccessModifyChangeTime( struct stat *pststat)
{
    printf("\tLast Access time: %s", ctime(&pststat->st_atime));
    printf("\tLast Modify time: %s", ctime(&pststat->st_mtime));
    printf("\tLast Change time: %s", ctime(&pststat->st_mtime));
    return ;
}
