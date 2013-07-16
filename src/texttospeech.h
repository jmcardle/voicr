#ifndef TEXTTOSPEECH_H
#define TEXTTOSPEECH_H

#include <QObject>
#include <festival/festival.h>

class TextToSpeech : public QObject
{
	Q_OBJECT
public:
	TextToSpeech(QObject *parent = 0);
	bool speak(QString);

signals:
    
public slots:
    
};

#endif // TEXTTOSPEECH_H
