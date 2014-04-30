#include <Windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("picture");
    smile1 = QPixmap("../smile1.png");
    smile2 = QPixmap("../smile2.png");
    animation = new QMovie("../smile2.gif");
    //drawPicture(smile1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print(QString string){
     ui->textBrowser->append(string);
}

void MainWindow::setLabelText(QString string){
    ui->label->setText(string);
}

void MainWindow::drawPicture(QPixmap picture){
    //ui->label->clear();
    if(picture.isNull()) ui->label->setText("None picture");
    else{
        ui->label->resize(picture.size());
        ui->label->setPixmap(picture);
    }
}

void MainWindow::playMovie(QMovie *movie){
    if(!movie->isValid()) ui->label->setText("None animation");
    else{
        ui->label->setMovie(movie);
        movie->start();
    }

}

void MainWindow::on_pushButton_released()
{
    /*setLabelText("mrk");
    drawPicture(this->smile2);
    int i;
    for(i=-1000; i<1000; i++){}
    setLabelText("mrk");
   // drawPicture(this->smile1);
    */
    playMovie(this->animation);
}
