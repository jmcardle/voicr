#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
	speechEngine = new TextToSpeech(this, "(voice_en1_mbrola)");
	speechEngine->speak("Hello!");

	tumblrAuth = new TumblrAuth(this);
	//tumblrAuth->getAuthorization();
	//tumblrAuth->loadInfo("fruzz");
	tumblrAuth->loadDashboard();
}
