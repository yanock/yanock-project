#pragma once  
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QFile>

  
class CNetwork : public QObject  
{  
	Q_OBJECT  
public:  
	CNetwork(void);  
	~CNetwork(void);  
	QNetworkAccessManager *manager;  
	void creationSlots();   
public slots:  
	void download();  
	void replyFinished(QNetworkReply *r);  
};  