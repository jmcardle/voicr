#ifndef TEXTTOSPEECH_H
#define TEXTTOSPEECH_H

#include <QObject>
#include <QStringList>
#include <QTemporaryDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <festival/festival.h>

class TextToSpeech : public QObject
{
	Q_OBJECT
public:
	TextToSpeech(QObject *parent, QString);
	void newPage(QStringList);
	void nextParagraph();

private:
	QMediaPlayer *player;
	QMediaPlaylist *playlist;
	QTemporaryDir temporaryDir;

signals:
    
public slots:

};

#endif // TEXTTOSPEECH_H
