#ifndef RESULT_H
#define RESULT_H
#include <QMainWindow>
#include <QDialog>
namespace Ui {
class result;
}
class result : public QDialog
{
    Q_OBJECT
public:
    explicit result(QWidget *parent = 0);
    ~result();
    void setWinner(char winner);
signals:
    void reset();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::result *ui;
};
#endif // RESULT_H
