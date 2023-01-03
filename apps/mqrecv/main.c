/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: GPL-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-10-20     Bernard      The first version
 */

#include <mqueue.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int flag = O_RDWR;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqd_t mqid = mq_open("/mq_test",flag,mode,NULL);
    if (mqid == -1)
    {
        printf("open mqueue failed!\n");
        return 1;
    }

    struct mq_attr attr;
    mq_getattr(mqid,&attr);
    char buf[256] = {0};
    unsigned priority = 0;
    mq_receive(mqid,buf,attr.mq_msgsize,&priority);
    printf("%s\n",buf);
    mq_close(mqid);    
    return 0;
}