#include <Windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ovaCAbstractVrpnPeripheral.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    smile1 = QPixmap("../smile1.png");
    animation = new QMovie("../smile.gif");
    ui->label->setText("picture");
    if(!animation->isValid()) ui->label->setText("None animation");
    else  ui->label->setMovie(animation);

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

void MainWindow::playMovie(){
    //playMovie(animation);

        animation->start();

}

void MainWindow::playMovie(QMovie *movie){
    if(!movie->isValid()) ui->label->setText("None animation");
    else{
        ui->label->setMovie(movie);
        movie->start();
    }

}

void MainWindow::doWork(){
    playMovie();
}

void MainWindow::closeEvent(QCloseEvent *e){
    running = false;
    e->accept();
}

void MainWindow::on_pushButton_released()
{
    playMovie();
    //playMovie(this->animation);
}
