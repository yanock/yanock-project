#include "Network.h"  
  
CNetwork::CNetwork(void)  
{  
	download();  
}  
  
CNetwork::~CNetwork(void)  
{  
}  
  
void CNetwork::download()  
{  
	manager = new QNetworkAccessManager;  
	connect(manager, SIGNAL(),this, SLOT(replyFinished(QNetworkReply* r)));  
	manager->get(QNetworkRequest(QUrl("http://www.newbiecontest.org/epreuves/prog/prog14.php")));  
}  
  
void CNetwork::replyFinished(QNetworkReply* r)  
{  
	QFile file("test.txt");  
	file.open(QIODevice::ReadWrite);  
	QByteArray tab = r->readAll();  
	file.write(tab);  
	file.close();  
}  