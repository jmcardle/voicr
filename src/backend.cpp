#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
	speechEngine = new TextToSpeech(this, "(voice_en1_mbrola)");
	speechEngine->speak("Hello!");

	tumblrClient = new TumblrClient(this);
	//tumblrAuth->getAuthorization();
	//tumblrAuth->loadInfo("fruzz");
	tumblrClient->loadDashboard();
}
