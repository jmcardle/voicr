#ifndef TUMBLRAUTH_H
#define TUMBLRAUTH_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QtKOAuth/QtKOAuth>

class TumblrAuth : public QObject
{
	Q_OBJECT
public:
	TumblrAuth(QObject *parent);
	~TumblrAuth();

	void getAccess();
	void loadInfo();

private:
	KQOAuthRequest *oauthRequest;
	KQOAuthManager *oauthManager;
	QSettings oauthSettings;
	
signals:
	
public slots:
	
private slots:
	void onTemporaryTokenReceived(QString, QString);
	void onAuthorizationReceived(QString, QString);
	void onAccessTokenReceived(QString, QString);
	void onAuthorizedRequestDone();
	void onRequestReady(QByteArray);
};

#endif // TUMBLRAUTH_H
