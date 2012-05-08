#include "alerte.h"
#include <QDebug>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

Alerte::Alerte()
        : manager(new QNetworkAccessManager(this))
{
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(reponseRecue(QNetworkReply*)));
}

void Alerte::requete(const QString & pseudo, const QString & password)
{
    qDebug() << "Nous sommes bien dans le void alerte::requete debut";

    QNetworkRequest request(QUrl("http://localhost/page.php"));
    request.setRawHeader("User-Agent", "User Agent");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QString PostVariable = "username=";
    PostVariable+=pseudo;
    PostVariable+="&password=";
    PostVariable+=password;

    QNetworkReply *reply = manager->post(request, PostVariable.toUtf8());
    Q_UNUSED(reply);

    qDebug() << "Nous sommes bien dans le void alerte::requete fin";
}

void Alerte::reponseRecue(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
   {
       qDebug() << reply->readAll();       
       QMessageBox::information(0, tr("Connexion"), tr("Pas d'erreur !"));
   }
   else
   {
       QMessageBox::information(0, tr("Connexion"), tr("Erreur !"));
   }
   delete reply;
}