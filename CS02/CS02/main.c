//
//  main.c
//  CS02
//
//  Created by simple on 13-9-7.
//  Copyright (c) 2013年 simple.com. All rights reserved.
//

#include <stdio.h> 
#include <unistd.h>
#include "func.h"


int main(int argc, const char * argv[])
{
    char *filename = "/Users/simple/Documents/study/c/study-c/CS02/CS02/config.ini";
    char buf[200];
    getcwd(buf,sizeof(buf));
    
    printf("current working directory: %s\n", buf);
    
    
    debug("你好，测试功能");
    
    readFile(filename);
    
    return 0;
}
