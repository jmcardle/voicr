#include "tumblrauth.h"
#include "credentials.h"

TumblrAuth::TumblrAuth(QObject *parent) :
	QObject(parent)
{
	oauthRequest = new KQOAuthRequest;
	oauthManager = new KQOAuthManager(this);

	connect(oauthManager, SIGNAL(temporaryTokenReceived(QString,QString)),
			this, SLOT(onTemporaryTokenReceived(QString, QString)));

	connect(oauthManager, SIGNAL(authorizationReceived(QString,QString)),
			this, SLOT(onAuthorizationReceived(QString, QString)));

	connect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)),
			this, SLOT(onAccessTokenReceived(QString,QString)));

	connect(oauthManager, SIGNAL(requestReady(QByteArray)),
			this, SLOT(onRequestReady(QByteArray)));

	connect(oauthManager, SIGNAL(authorizedRequestDone()),
			this, SLOT(onAuthorizedRequestDone()));
}

TumblrAuth::~TumblrAuth()
{
	delete oauthRequest;
	delete oauthManager;
}

void TumblrAuth::getAuthorization()
{
	oauthRequest->initRequest(KQOAuthRequest::TemporaryCredentials, QUrl(OAUTH_REQUEST_TOKEN_URL));
	oauthRequest->setConsumerKey(OAUTH_CONSUMER_KEY);
	oauthRequest->setConsumerSecretKey(OAUTH_CONSUMER_SECRET_KEY);
	oauthManager->setHandleUserAuthorization(true);
	oauthManager->executeRequest(oauthRequest);
}

void TumblrAuth::onTemporaryTokenReceived(QString token, QString tokenSecret)
{
	if( oauthManager->lastError() == KQOAuthManager::NoError) {
		oauthManager->getUserAuthorization(QUrl(OAUTH_AUTHORIZE_URL));
	} else {
		qDebug() << oauthManager->lastError();
	}
}

void TumblrAuth::onAuthorizationReceived(QString token, QString verifier)
{
	oauthManager->getUserAccessTokens(QUrl(OAUTH_ACCESS_TOKEN_URL));
	if( oauthManager->lastError() != KQOAuthManager::NoError) {
		qDebug() << oauthManager->lastError();
	}
}

void TumblrAuth::onAccessTokenReceived(QString token, QString tokenSecret)
{
	// Store the received tokens.
	oauthSettings.setValue("oauth_token", token);
	oauthSettings.setValue("oauth_token_secret", tokenSecret);
}

void TumblrAuth::onAuthorizedRequestDone()
{
	// ...
}

void TumblrAuth::onRequestReady(QByteArray response)
{
	// Response back from Tumblr
	emit requestReply(QString(response));
}

void TumblrAuth::issueRequest(QString urlFormat)
{
	// Issue the request with no parameters.
	issueRequest(urlFormat, KQOAuthParameters());
}

void TumblrAuth::issueRequest(QString urlFormat, KQOAuthParameters params)
{
	// If the tokens are missing, abort.
	if(oauthSettings.value("oauth_token").toString().isEmpty() ||
	   oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
		return;
	}

	// Issue the request to Tumblr.
	QUrl infoUrl(urlFormat);
	oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, infoUrl);
	oauthRequest->setConsumerKey(OAUTH_CONSUMER_KEY);
	oauthRequest->setConsumerSecretKey(OAUTH_CONSUMER_SECRET_KEY);
	oauthRequest->setToken(oauthSettings.value("oauth_token").toString());
	oauthRequest->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());
	oauthRequest->setAdditionalParameters(params);
	oauthManager->executeRequest(oauthRequest);
}

