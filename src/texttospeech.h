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

private:
	QMediaPlayer *player;
	QMediaPlaylist *playlist;
	QTemporaryDir temporaryDir;
	QString festivalVoice;

signals:
    
public slots:
	void startReading();
	void stopReading();
	void pauseReading();
	void resumeReading();
	void readNext();

private slots:

};

#endif // TEXTTOSPEECH_H
