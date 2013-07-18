#ifndef TUMBLRPARSER_H
#define TUMBLRPARSER_H

#include <QObject>
#include <QDebug>

class TumblrParser : public QObject
{
	Q_OBJECT
public:
	TumblrParser(QObject *parent = 0);
	void parseResponse(QString);

signals:
	
public slots:
	
};

#endif // TUMBLRPARSER_H
