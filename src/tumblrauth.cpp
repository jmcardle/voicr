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
			this, SLOT( onAuthorizationReceived(QString, QString)));

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
	}
}

void TumblrAuth::onAuthorizationReceived(QString token, QString verifier)
{
	oauthManager->getUserAccessTokens(QUrl(OAUTH_ACCESS_TOKEN_URL));
	if( oauthManager->lastError() != KQOAuthManager::NoError) {
		// Yay no errors.
	}
}

void TumblrAuth::onAccessTokenReceived(QString token, QString tokenSecret)
{
	oauthSettings.setValue("oauth_token", token);
	oauthSettings.setValue("oauth_token_secret", tokenSecret);

	// Yay now ready to access Tumblr posts.
}

void TumblrAuth::onAuthorizedRequestDone()
{
	// Request sent to Tumblr
}

void TumblrAuth::onRequestReady(QByteArray response)
{
	// Response back from Tumblr
	qDebug() << response;
}

void TumblrAuth::loadDashboard()
{
	QString url = TUMBLR_API_URL + "user/dashboard";
	issueRequest(url);
}

void TumblrAuth::loadInfo(QString blogName)
{
	QString url = TUMBLR_API_URL + "blog/" + blogName + ".tumblr.com/info?api_key=" + OAUTH_CONSUMER_KEY;
	issueRequest(url);
}

void TumblrAuth::issueRequest(QString urlFormat)
{
	issueRequest(urlFormat, KQOAuthParameters());
}

void TumblrAuth::issueRequest(QString urlFormat, KQOAuthParameters params)
{
	if( oauthSettings.value("oauth_token").toString().isEmpty() ||
		oauthSettings.value("oauth_token_secret").toString().isEmpty()) {
		return;
	}

	QUrl infoUrl(urlFormat);
	oauthRequest->initRequest(KQOAuthRequest::AuthorizedRequest, infoUrl);
	oauthRequest->setConsumerKey(OAUTH_CONSUMER_KEY);
	oauthRequest->setConsumerSecretKey(OAUTH_CONSUMER_SECRET_KEY);
	oauthRequest->setToken(oauthSettings.value("oauth_token").toString());
	oauthRequest->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());

	oauthRequest->setAdditionalParameters(params);

	//params.insert("status", tweet);
	//oauthRequest->setAdditionalParameters(params);

	oauthManager->executeRequest(oauthRequest);
}

