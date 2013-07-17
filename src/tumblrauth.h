#ifndef TUMBLRAUTH_H
#define TUMBLRAUTH_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QtKOAuth/QtKOAuth>

#define TUMBLR_API_URL QString("http://api.tumblr.com/v2/")

class TumblrAuth : public QObject
{
	Q_OBJECT
public:
	TumblrAuth(QObject *parent);
	~TumblrAuth();

	void getAuthorization();
	void loadInfo(QString);
	void loadDashboard();

private:
	KQOAuthRequest *oauthRequest;
	KQOAuthManager *oauthManager;
	QSettings oauthSettings;

	void issueRequest(QString);
	void issueRequest(QString, KQOAuthParameters);
	
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
