#include "tumblrobject.h"

TumblrObject::TumblrObject(int initialType, QObject *parent) :
	QObject(parent)
{
	// Set defaults.
	type = initialType;
	askEnabled = false;
	askAnonEnabled = false;
	isNsfw = false;
	lastUpdated = 0;
	likesEnabled = false;
	totalPosts = 0;
	totalLikes = 0;
}

void TumblrObject::setType(int newType)
{
	type = newType;
}

int TumblrObject::getType()
{
	return type;
}

void TumblrObject::setAskEnabled(bool newAskEnabled)
{
	askEnabled = newAskEnabled;
}

bool TumblrObject::getAskEnabled()
{
	return askEnabled;
}

void TumblrObject::setAskAnonEnabled(bool newAskAnonEnabled)
{
	askAnonEnabled = newAskAnonEnabled;
}

void TumblrObject::setDescription(QString newDescription)
{
	description = newDescription;
}

QString TumblrObject::getDescription()
{
	return description;
}

void TumblrObject::setIsNsfw(bool newIsNsfw)
{
	isNsfw = newIsNsfw;
}

bool TumblrObject::getIsNsfw()
{
	return isNsfw;
}

void TumblrObject::setLastUpdated(int newLastUpdated)
{
	lastUpdated = newLastUpdated;
}

int TumblrObject::getLastUpdated()
{
	return lastUpdated;
}

void TumblrObject::setLikesEnabled(bool newLikesEnabled)
{
	likesEnabled = newLikesEnabled;
}

bool TumblrObject::getLikesEnabled()
{
	return likesEnabled;
}

void TumblrObject::setName(QString newName)
{
	name = newName;
}

QString TumblrObject::getName()
{
	return name;
}

void TumblrObject::setTitle(QString newTitle)
{
	title = newTitle;
}

QString TumblrObject::getTitle()
{
	return title;
}

void TumblrObject::setTotalLikes(int newTotalLikes)
{
	totalLikes = newTotalLikes;
}

int TumblrObject::getTotalLikes()
{
	return totalLikes;
}

void TumblrObject::setTotalPosts(int newTotalPosts)
{
	totalPosts = newTotalPosts;
}

int TumblrObject::getTotalPosts()
{
	return totalPosts;
}
