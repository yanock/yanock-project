#define QT3_SUPPORT
#include <QtCore>
#include <QtNetwork>
#include <iostream>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QTcpSocket socket;
    socket.connectToHost("irc.worldnet.net", 6667);
    QString chaine;
    while(socket.waitForReadyRead() != true){}
    chaine = socket.readAll();
    std::cout<<chaine.toStdString();
    socket.write("NICK QTcpSocket");
    std::cout<<"NICK QTcpSocket\n";
    socket.write("USER simpsonmaniac . . :?");
    std::cout<<"USER simpsonmaniac\n";
    while(socket.waitForReadyRead() != true){}
    chaine.clear();
    chaine = socket.readAll();
    std::cout<<"\n"<<chaine.toStdString();
    socket.write("JOIN #nc-irc-challs");
    while(socket.waitForReadyRead() != true){}
    chaine.clear();
    chaine = socket.readAll();
    socket.write("PRIVMSG Daneel :.challenge_asciiart start");
    while(socket.waitForReadyRead() != true){}
    chaine.clear();
    chaine = socket.readAll();
    std::cout<<"\n"<<chaine.toStdString();
    std::cout<<"\nDone";
    return app.exec();
}






/*

#ifdef WIN32

#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define SocketErrno (WSAGetLastError())
#define bcopy(src,dest,len) memmove(dest,src,len)

#else

#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>

#define SocketErrno errno

#define SOCKET int
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1


#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#endif

#include <iostream>
#include <string.h>



using namespace std;

int main(int argc, const char* argv[])
{
    struct sockaddr_in sock;

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);

	char buf[512];
	int byte_count;
	
    sock.sin_family = AF_INET;
    sock.sin_port = htons(6667);
    sock.sin_addr.s_addr = inet_addr("irc.worldnet.net");

    int c = connect(sockfd, (struct sockaddr*)&sock, sizeof sock);

    char *msg = "USER myself 8 * : omgtest\nNICK omgtest\nJOIN #srl\n";

    send(sockfd, msg, strlen(msg), 0);
	
	// all right!  now that we're connected, we can receive some data!
	byte_count = recv(sockfd, buf, sizeof buf, 0);
	cout << "recv() : " << byte_count << endl;
	
}

*/
