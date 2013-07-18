#ifndef TUMBLR_H
#define TUMBLR_H

#include <QObject>
#include <QDebug>
#include "tumblrauth.h"

#define TUMBLR_API_URL QString("http://api.tumblr.com/v2/")

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
	
signals:
	
public slots:

private slots:
	void onTumblrReply(QString);
	
};

#endif // TUMBLR_H
