#include "texttospeech.h"

TextToSpeech::TextToSpeech(QObject *parent, QString voiceToUse) :
	QObject(parent)
{
	int heap_size = 210000;
	int load_init_files = 1;

	// Initialize and define the voice that will be used.
	festival_initialize(load_init_files, heap_size);
	festival_eval_command(voiceToUse.toLocal8Bit().data());

	playlist = new QMediaPlaylist;
	player = new QMediaPlayer;
}

void TextToSpeech::newPage(QStringList paragraphs)
{
	playlist->clear();

	// Go paragraph by paragraph.
	for (int i = 0; i < paragraphs.size(); i++) {

		// Store the contents to a wave structure in memory.
		EST_Wave wave;
		char *paragraph = paragraphs.at(i).toLocal8Bit().data();
		festival_text_to_wave(paragraph, wave);

		// Store the wave structure to a file on disk.
		QString filename = temporaryDir.path() + "paragraph-" +
				QString("%1").arg(i) + ".wav";
		wave.save(filename.toLocal8Bit().data(), "riff");
		festival_wait_for_spooler();

		// Append the file to the list.
		playlist->addMedia(QUrl().fromLocalFile(filename));
	}

	playlist->setCurrentIndex(0);
	player->setPlaylist(playlist);
	player->play();
}
