#ifndef TUMBLRAUTH_H
#define TUMBLRAUTH_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QtKOAuth/QtKOAuth>

#define OAUTH_REQUEST_TOKEN_URL "http://www.tumblr.com/oauth/request_token"
#define OAUTH_AUTHORIZE_URL "http://www.tumblr.com/oauth/authorize"
#define OAUTH_ACCESS_TOKEN_URL "http://www.tumblr.com/oauth/access_token"

class TumblrAuth : public QObject
{
	Q_OBJECT
public:
	TumblrAuth(QObject *parent);
	~TumblrAuth();

	void getAuthorization();
	void issueRequest(QString);
	void issueRequest(QString, KQOAuthParameters);

private:
	KQOAuthRequest *oauthRequest;
	KQOAuthManager *oauthManager;
	QSettings oauthSettings;

signals:
	void requestReply(QString);
	
public slots:
	
private slots:
	void onTemporaryTokenReceived(QString, QString);
	void onAuthorizationReceived(QString, QString);
	void onAccessTokenReceived(QString, QString);
	void onAuthorizedRequestDone();
	void onRequestReady(QByteArray);
};

#endif // TUMBLRAUTH_H
