#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
	speechEngine = new TextToSpeech(this);
	speechEngine->speak("Hello! I am making sure this works");
}
