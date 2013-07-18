#include "tumblrclient.h"
#include "credentials.h"

TumblrClient::TumblrClient(QObject *parent) :
	QObject(parent)
{
	tumblrAuth = new TumblrAuth(this);

	connect(tumblrAuth, SIGNAL(requestReply(QString)), this, SLOT(onTumblrReply(QString)));
}

TumblrClient::~TumblrClient()
{
	delete tumblrAuth;
}

void TumblrClient::loadDashboard()
{
	QString url = TUMBLR_API_URL + "user/dashboard";
	tumblrAuth->issueRequest(url);
}

void TumblrClient::loadInfo(QString blogName)
{
	QString url = TUMBLR_API_URL + "blog/" + blogName +
			".tumblr.com/info?api_key=" + OAUTH_CONSUMER_KEY;

	tumblrAuth->issueRequest(url);
}

void TumblrClient::onTumblrReply(QString response)
{
	qDebug() << response;
}
