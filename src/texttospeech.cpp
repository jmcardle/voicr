#include "texttospeech.h"

TextToSpeech::TextToSpeech(QObject *parent) :
    QObject(parent)
{
	// Initialize Festival, the text-to-speech engine.
	int heap_size = 210000;
	int load_init_files = 1;
	festival_initialize(load_init_files,heap_size);

	// Define the voice that will be used.
	festival_eval_command("(voice_en1_mbrola)");
	}

bool TextToSpeech::speak(QString textToSay)
{
	// Synthesize speech from the text.
	int success = festival_say_text(textToSay.toLocal8Bit().data());
	festival_wait_for_spooler();
	return success;
}
