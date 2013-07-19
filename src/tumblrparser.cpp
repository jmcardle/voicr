#include "tumblrparser.h"

TumblrParser::TumblrParser(QObject *parent) :
	QObject(parent)
{
}

void TumblrParser::parse(QByteArray jsonAsText)
{
	QJsonParseError jsonError;
	QJsonObject json;

	// Load the JSON response from Tumblr into a callable object.
	json = QJsonDocument::fromJson(jsonAsText, &jsonError).object();
	if (jsonError.error != QJsonParseError::NoError) {
		qDebug() << jsonError.errorString();
		return;
	}

	// If there's no status on the request, or it failed, abort.
	if (!json.contains("meta") || !parseMeta(json["meta"])) {
		return;
	}

	// Parse the content provided by Tumblr.
	parseResponse(json["response"]);
}

bool TumblrParser::parseMeta(QJsonValue meta)
{
	// Return True if the status is OK.
	if (meta.isObject() && meta.toObject()["status"] == 200) { return true; }
	else { return false; }
}

void TumblrParser::parseResponse(QJsonValue response)
{
	// If this isn't an object, abort. Otherwise get it.
	if (!response.isObject()) return;
	QJsonObject json = response.toObject();

	// Get the list of entries in the response.
	QStringList keys = json.keys();

	// Prepare a list of items to be readied for display/reading.
	QList <TumblrObject *> tumblrObjects;
	TumblrObject *tumblrObject;

	// Parse blog information.
	if (keys.contains("blog")) {
		tumblrObject = parseResponseBlog(json["blog"]);
		if (tumblrObject != NULL) tumblrObjects.append(tumblrObject);
	}


}

TumblrObject *TumblrParser::parseResponseBlog(QJsonValue responseBlog)
{
	// If this isn't an object, abort. Otherwise get it.
	if (!responseBlog.isObject()) return NULL;
	QJsonObject json = responseBlog.toObject();

	// Parse the JSON object.
	QString name = json["name"].toString();
	QString title = json["title"].toString();
	QString description = json["description"].toString();
	bool askEnabled = json["ask"].toBool();
	bool askAnonEnabled = (askEnabled) ? json["ask_anon"].toBool() : false;
	bool isNsfw = json["is_nsfw"].toBool();
	bool likesEnabled = json["share_likes"].toBool();
	int lastUpdated = json["updated"].toDouble();
	int totalPosts = json["posts"].toDouble();
	int totalLikes = (likesEnabled) ? json["likes"].toDouble() : 0;

	// Set the parameters for the tumblr object.
	TumblrObject *tumblr = new TumblrObject(TUMBLR_BLOG);
	tumblr->setName(name);
	tumblr->setTitle(title);
	tumblr->setDescription(description);
	tumblr->setAskEnabled(askEnabled);
	tumblr->setAskAnonEnabled(askAnonEnabled);
	tumblr->setIsNsfw(isNsfw);
	tumblr->setLikesEnabled(likesEnabled);
	tumblr->setLastUpdated(lastUpdated);
	tumblr->setTotalPosts(totalPosts);
	tumblr->setTotalLikes(totalLikes);
	return tumblr;
}
