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

void debug(char *msg)
{
    const char *date_f = "%Y-%m-%d %I:%M:%S";
    char *datetime=getCrrentTime(date_f);
    
    printf("%s\t[DEBUG]%s\n",datetime,msg);
}