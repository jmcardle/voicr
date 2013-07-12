#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <festival/festival.h>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // BACKEND_H
