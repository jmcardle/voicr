#include "backend.h"

Backend::Backend(QObject *parent) :
    QObject(parent)
{
	speechEngine = new TextToSpeech(this, "(voice_en1_mbrola)");
	speechEngine->newPage(QStringList() << "Hello!");

	tumblrClient = new TumblrClient(this);
	//tumblrClient->getAuthorization();
	tumblrClient->loadInfo("fruzz");
	//tumblrClient->loadDashboard();

}
