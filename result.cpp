#include "result.h"
#include "ui_result.h"
result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}
result::~result()
{
    delete ui;
}
void result::setWinner(char winner)
{
    if(winner=='w'){ui->label_2->setText("Win");}
    if(winner=='l'){ui->label_2->setText("Lose");}
}
void result::on_pushButton_clicked()
{
    emit reset();
}
void result::on_pushButton_2_clicked()//quit
{
    QApplication::exit(0);
}
