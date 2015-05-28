#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
/*#include "result.h"*/
namespace Ui {
class game;
}
class game : public QWidget
{
    Q_OBJECT
public:
    explicit game(QWidget *parent=0);
    ~game();
signals:
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
protected:
    virtual void keyPressEvent(QKeyEvent *event);
private:
    Ui::game *ui;
    QWidget *mainWindow;
    int Square[4][4];
    int Score;
    int Best;
    int old_Square[4][4];
    int old_Score;
    char checkWin();
    void display();
    void score();
    void best();
};
#endif // GAME_H
