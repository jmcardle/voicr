#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "tumblrclient.h"
#include "texttospeech.h"

class Backend : public QObject
{
	Q_OBJECT
public:
	explicit Backend(QObject *parent = 0);

private:
	TextToSpeech *speechEngine;
	TumblrClient *tumblrClient;

signals:
    
public slots:
    
};

#endif // BACKEND_H
