#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H

#include <QWidget>
#include <QKeyEvent>

class keypressevent : public QWidget
{
    Q_OBJECT
public:
    explicit keypressevent(QWidget *parent = 0,int Square[4][4]);

signals:

public slots:

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // KEYPRESSEVENT_H
