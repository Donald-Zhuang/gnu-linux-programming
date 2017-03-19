/***********************************************************/
//     File Name   : file_operation.h
//     Author      : Donald Zhuang
//     E-Mail      : 
//     Create Time : Sun 19 Mar 2017 01:14:45 PM CST
/**********************************************************/

#ifndef __FILE_OPERATION_H__
#define __FILE_OPERATION_H__

extern void Print_FileTypeAndPermissions(struct stat *pststat);
extern void Print_UserAndGroup(struct stat *pststat);
extern void Print_AccessModifyChangeTime(struct stat *pststat);

#endif
