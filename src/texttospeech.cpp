#include "texttospeech.h"

TextToSpeech::TextToSpeech(QObject *parent, QString voiceToUse) :
    QObject(parent)
{
	int heap_size = 210000;
	int load_init_files = 1;

	// Initialize and define the voice that will be used.
	festival_initialize(load_init_files, heap_size);
	festival_eval_command(voiceToUse.toLocal8Bit().data());
}

bool TextToSpeech::speak(QString textToSay)
{
	// Synthesize speech from the text.
	int success = festival_say_text(textToSay.toLocal8Bit().data());
	festival_wait_for_spooler();
	return success;
}
