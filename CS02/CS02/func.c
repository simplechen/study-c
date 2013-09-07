//
//  func.c
//  CS02
//
//  Created by simple on 13-9-7.
//  Copyright (c) 2013年 simple.com. All rights reserved.
//
#ifndef __USE_XOPEN
#define __USE_XOPEN
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>



/**
    获取当前时间
 */
char *getCrrentTime(const char *df)
{
    char *datetime;
    struct tm *tm_ptr;
    time_t ttime;
    size_t df_len = strlen(df)+1;
    
    datetime=(char*) calloc(df_len, sizeof(char));
    
    (void)time(&ttime);
    tm_ptr = localtime(&ttime);
    
    strftime(datetime,df_len,df,tm_ptr);//格式化时间
    
    printf("current time: %s\n",datetime);
    
    return datetime;
}

void debug(const char *msg)
{
    const char *date_f = "%Y-%m-%d %I:%M:%S";
    char *datetime=getCrrentTime(date_f);
    
    printf("%s\t[DEBUG]%s\n",datetime,msg);
}

void readFile(const char *filename)
{
    FILE *fp;
    char *content;
    long file_len;
    
    
    //判断文件是否存在
    debug(filename);
    
    if (access(filename, F_OK)) {
        debug("文件不存在");
        exit(0);
    }
    
    //读取并输出FILE *fopen( const char *fname, const char *mode );
    fp = fopen(filename, "r");
    
    fseek(fp, 0, SEEK_END);
    file_len = ftell(fp);
    
    printf("文件长度:%ld\n",file_len);
    content = (char*)calloc(file_len, sizeof(char));
    
    fseek(fp, 0, SEEK_SET);
    
    fread(content, file_len, 1, fp);
    
    printf("contnet:%s\n",content);
    
    free(content);
    fclose(fp);
    
    //TODO strcpy fgets
    //一次读一行，并对”＝“进行切分
}