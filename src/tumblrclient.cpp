#include "tumblrclient.h"
#include "credentials.h"

TumblrClient::TumblrClient(QObject *parent) :
	QObject(parent)
{
	tumblrAuth = new TumblrAuth(this);
	tumblrParser = new TumblrParser(this);

	connect(tumblrAuth, SIGNAL(requestReply(QString)), this, SLOT(onTumblrReply(QString)));
}

TumblrClient::~TumblrClient()
{
	delete tumblrAuth;
}

QString TumblrClient::getUrl(QString method)
{
	return QString(TUMBLR_API_URL) + method;
}

QString TumblrClient::getUrl(QString method, QString blogName, bool withKey)
{
	QString url = QString(TUMBLR_API_URL) + "/blog/" + blogName +
			".tumblr.com" + method;

	if (withKey) {
		url.append("?api_key=" + QString(OAUTH_CONSUMER_KEY));
	}

	return url;
}

void TumblrClient::loadDashboard()
{
	tumblrAuth->issueRequest(getUrl("/user/dashboard"));
}

void TumblrClient::loadInfo(QString blogName)
{
	tumblrAuth->issueRequest(getUrl("/info", blogName, true));
}

void TumblrClient::onTumblrReply(QString response)
{
	tumblrParser->parseResponse(response);
}
