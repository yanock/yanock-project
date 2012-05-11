#define QT3_SUPPORT
#include <QtCore>
#include <QtNetwork>
#include <iostream>


using namespace std;

    
  
void displayList(QStringList list, string ds)
{
	QString str = "";
	for(int l=0;l<list.size(); l++)
	{
		str.append(list[l]);
		str.append("\r\n");
	}
	cout << ds << " : " << endl;
	cout << str.toStdString() <<endl;
	
}
     
 


int main(int argc, char* argv[])
{
	cout << "debut" << endl;
    QCoreApplication app(argc, argv);
    QTcpSocket *socket = new QTcpSocket(&app); 
	//socket->connectToHost( "smtp.free.fr" , 25 );
    socket->connectToHost("irc.worldnet.net", 6667);
    cout << "1" << endl;
	QString chaine1;
	
	
	if (socket->waitForConnected(1000))
		 cout << "Connected!" << endl;
	else
		 // cout << "nothing!" << endl;
	
	
    while(socket->waitForReadyRead() != true){}
    cout << "2" << endl;
	chaine1 = socket->readAll();
    std::cout<<chaine1.toStdString();
    socket->write("NICK QTcpSocket");
    std::cout<<"NICK QTcpSocket\n";
    socket->write("USER simpsonmaniac . . :?");
    std::cout<<"USER simpsonmaniac\n";
	QString chaine;
	string pass = "test";
	bool continuer = true, envoyer = false;
	while(socket->canReadLine()) // Boucle principale.
	{
		chaine = socket->readLine();
		//Biohazard!Biohazard@ie.freebnc.net PRIVMSG #Biobot hi
		if(chaine.startsWith("PING"))
		{
			std::cout << "PONG " << chaine.split(" ")[1].toStdString() << endl;
			socket->write(("PONG " + chaine.split(" ")[1]).toStdString().c_str());
		}
		else if(chaine.startsWith(":NickServ!NickServ@")&&
				chaine.contains("You have 30 seconds to identify to your nickname before it is changed."))
		{
			QString passCmd = "NICKSERV identify ";
			passCmd.append(pass);
			passCmd.append("\r\n")
			socket->write(passCmd.toStdString().c_str());
		}
		else if(chaine.split(" ")[1]=="PRIVMSG")
		{/*
			QString command = CommandParser::getMessage(chaine);
			if(command.split(" ")[0]=="@hello"&&permissions::getPermission("hello", CommandParser::getName(chaine)))
			{
				const QString text = "PRIVMSG " + CommandParser::getChannel(chaine) + ":hello world!\r\n";
				socket->write(text.toStdString().c_str());
			}
			*/
			cout << "else if" << endl;
		}
		
		displayList(chaine, "liste")
		
	
		cout << "coucou" << endl;
	}
	cout << "out" << endl;
	continuer = true;
	socket->write("JOIN #nc-irc-challs");

	while(continuer)
	{
		while(socket->waitForReadyRead() != true){}
		chaine1.clear();
		chaine1 = socket->readAll();
		std::cout<<"\n"<<chaine1.toStdString();
		if(chaine1.contains("PING", Qt::CaseInsensitive))
		{
			socket->write("PONG");
			continuer = false;
		}
		else if(!envoyer)
		{
			socket->write("PRIVMSG Daneel :.challenge_asciiart start");
		
		}
		
	}
	
	
	
	socket->write("bye bye\r\n");
    socket->flush();
    socket->disconnect();
	
	
    return app.exec();
}



