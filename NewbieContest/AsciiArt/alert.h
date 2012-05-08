#ifndef ALERTE_H
#define ALERTE_H

#include <QObject>
class QNetworkReply;
class QNetworkAccessManager;
class QString;

class Alerte : public QObject
{
    Q_OBJECT
public:
    Alerte();
    void requete(const QString &, const QString &);

public slots:
    void reponseRecue(QNetworkReply*);

private:
    QNetworkAccessManager *manager;
};

#endif // ALERTE_H