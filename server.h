#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MODE_PP 0x01
#define MODE_SV 0x02

/* A linked list node data structure to maintain application
information related to a connected socket */
struct node
{
	int socket;
	struct sockaddr_in client_addr;
	int pending_data; /* flag to indicate whether there is more data to send */
	struct node *next;
};

/* functions in common.c */
int checkmode(int argc, char* argv[]);
int establish(unsigned short server_port);
void dump(struct node *head, int socket);
void add(struct node *head, int socket, struct sockaddr_in addr);
