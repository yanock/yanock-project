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
