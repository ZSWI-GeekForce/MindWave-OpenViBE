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
    smile2 = QPixmap("../smile2.png");
    animation = new QMovie("../smile.gif");

    //if(animation->isValid()) ui->label->resize(animation->scaledSize());
    ui->label->setText("picture");

    print("Setting connection");
    print("Initializing connection");
    OpenViBEVRDemos::CAbstractVrpnPeripheral *worker = new OpenViBEVRDemos::CAbstractVrpnPeripheral;
    //worker->init();
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &MainWindow::operate, worker, &OpenViBEVRDemos::CAbstractVrpnPeripheral::doWork);
    connect(worker, &OpenViBEVRDemos::CAbstractVrpnPeripheral::resultReady, this, &MainWindow::handleResults);
    connect(worker, &OpenViBEVRDemos::CAbstractVrpnPeripheral::sendMessage, this, &MainWindow::getMessage);
    workerThread.start();

}

MainWindow::~MainWindow()
{
    //workerThread.quit();
    //workerThread.wait();
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
    playMovie(animation);
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
    playMovie(this->animation);
}

void MainWindow::on_actionStart_communication_triggered()
{
    emit operate();
    print("Starting communication");
}

void MainWindow::on_actionClose_comunication_triggered()
{
    workerThread.quit();
    //workerThread.wait();
    print("Communication was closed");
}

void MainWindow::handleResults()
{
    playMovie(this->animation);
}

void MainWindow::getMessage(const char *message)
{
    QString *string = new QString(message);
    print(*string);
}
