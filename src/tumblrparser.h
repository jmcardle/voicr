#ifndef TUMBLRPARSER_H
#define TUMBLRPARSER_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QStringList>
#include "tumblrobject.h"

class TumblrParser : public QObject
{
	Q_OBJECT
public:
	TumblrParser(QObject *parent = 0);
	void parse(QByteArray);

private:
	bool parseMeta(QJsonValue);
	void parseResponse(QJsonValue);
	TumblrObject *parseResponseBlog(QJsonValue);

signals:
	
public slots:
	
};

#endif // TUMBLRPARSER_H
