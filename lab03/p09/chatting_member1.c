/**
 * chatting_member.c
 * author shimjihun
 */
#define SEND "P1"
#define RECV "P2"

#include "chatt.h"
#include <pthread.h>

int main(int argc, char** argv)
{
	pthread_t sendT, recvT;
	struct mq_attr attr;

	int ret, status=0;
	char namebuf[10];

	sprintf(namebuf, "%d.txt", getpid());
	pthread_mutex_init(&mutex, NULL);

	attr.mq_maxmsg = MAX_MSG;
	attr.mq_msgsize = MSG_SIZE;

	mq1 = mq_open(MQ_1, O_CREAT | O_RDWR, 0666, &attr);
	mq2 = mq_open(MQ_2, O_CREAT | O_RDWR, 0666, &attr);
	fd = open(namebuf, O_WRONLY | O_CREAT, 0666);

	if((mq1 == (mqd_t)-1) || (mq2 == (mqd_t)-1))
	{
		perror("open message queue error");
		exit(0);
	}
	
	ret = pthread_create(&sendT, NULL, send_thread, (void*)&mq1);

	if(ret < 0)
	{
		perror("thread create error : ");
		exit(0);
	}

	ret = pthread_create(&recvT, NULL, recv_thread, (void*)&mq2);
	
	if(ret < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	
	printf("joined.\n");
	strcpy(send_buf, "/s");
	mq_send(mq1, send_buf, strlen(send_buf), 0);
	pthread_join(sendT, (void**)&status);
	pthread_join(recvT, (void**)&status);

	return 0;
}
