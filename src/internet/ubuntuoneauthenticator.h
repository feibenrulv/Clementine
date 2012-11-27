#ifndef UBUNTUONEAUTHENTICATOR_H
#define UBUNTUONEAUTHENTICATOR_H

#include <QObject>

class QNetworkReply;
class NetworkAccessManager;

class UbuntuOneAuthenticator : public QObject {
  Q_OBJECT
 public:
  explicit UbuntuOneAuthenticator(QObject* parent = 0);
  void StartAuthorisation(const QString& email, const QString& password);

  QString consumer_key() const { return consumer_key_; }
  QString consumer_secret() const { return consumer_secret_; }
  QString token() const { return token_; }
  QString token_secret() const { return token_secret_; }

 signals:
  void Finished();

 private slots:
  void AuthorisationFinished(QNetworkReply* reply);

 private:
  NetworkAccessManager* network_;

  QString consumer_key_;
  QString consumer_secret_;

  QString token_;
  QString token_secret_;
};

#endif   // UBUNTUONEAUTHENTICATOR_H