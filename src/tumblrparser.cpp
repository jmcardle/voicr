#include "tumblrparser.h"

TumblrParser::TumblrParser(QObject *parent) :
	QObject(parent)
{
}

void TumblrParser::parseResponse(QString response)
{
	qDebug() << response;
}
