#ifndef TUMBLRCLIENT_H
#define TUMBLRCLIENT_H

#include <QObject>
#include <QDebug>
#include "tumblrauth.h"
#include "tumblrparser.h"

#define TUMBLR_API_URL "http://api.tumblr.com/v2"

class TumblrClient : public QObject
{
	Q_OBJECT
public:
	TumblrClient(QObject *parent);
	~TumblrClient();

	void loadInfo(QString);
	void loadDashboard();

private:
	TumblrAuth *tumblrAuth;
	TumblrParser *tumblrParser;
	QString getUrl(QString);
	QString getUrl(QString, QString, bool);

signals:
	
public slots:

private slots:
	void onTumblrReply(QByteArray);
	
};

#endif // TUMBLRCLIENT_H
