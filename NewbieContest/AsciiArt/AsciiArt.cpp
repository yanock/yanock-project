#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

using namespace std;

int main(int argc, const char* argv[])
{
    struct sockaddr_in sock;

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);

    sock.sin_family = AF_INET;
    sock.sin_port = htons(6667);
    sock.sin_addr.s_addr = inet_addr("irc.worldnet.net");

    int c = connect(sockfd, (struct sockaddr*)&sock, sizeof sock);

    char *msg = "USER myself 8 * : omgtest\nNICK omgtest\nJOIN #srl\n";

    send(sockfd, msg, strlen(msg), 0);
}


// stream sockets and recv()

struct addrinfo hints, *res;
int sockfd;
char buf[512];
int byte_count;

// get host info, make socket, and connect it
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
hints.ai_socktype = SOCK_STREAM;
getaddrinfo("www.example.com", "3490", &hints, &res);
sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
connect(sockfd, res->ai_addr, res->ai_addrlen);

// all right!  now that we're connected, we can receive some data!
byte_count = recv(sockfd, buf, sizeof buf, 0);
printf("recv()'d %d bytes of data in buf\n", byte_count);
