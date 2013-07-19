#ifndef TUMBLROBJECT_H
#define TUMBLROBJECT_H

#include <QObject>

#define TUMBLR_UNDEFINED 0
#define TUMBLR_BLOG 1

class TumblrObject : public QObject
{
	Q_OBJECT
public:
	TumblrObject(int type = TUMBLR_UNDEFINED, QObject *parent = 0);

	void setType(int);
	int getType();

	void setAskEnabled(bool);
	bool getAskEnabled();

	void setAskAnonEnabled(bool);
	bool getAskAnonEnabled();

	void setDescription(QString);
	QString getDescription();

	void setIsNsfw(bool);
	bool getIsNsfw();

	void setLastUpdated(int);
	int getLastUpdated();

	void setLikesEnabled(bool);
	bool getLikesEnabled();

	void setName(QString);
	QString getName();

	void setTitle(QString);
	QString getTitle();

	void setTotalLikes(int);
	int getTotalLikes();

	void setTotalPosts(int);
	int getTotalPosts();


private:
	int type;
	bool askEnabled;
	bool askAnonEnabled;
	QString description;
	int lastUpdated;
	bool likesEnabled;
	bool isNsfw;
	QString name;
	QString title;
	int totalLikes;
	int totalPosts;

signals:

public slots:

};

#endif // TUMBLROBJECT_H
