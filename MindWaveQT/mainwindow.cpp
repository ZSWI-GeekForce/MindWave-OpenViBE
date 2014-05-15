#include <Windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ovaCAbstractVrpnPeripheral.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
    smile = QPixmap("Smajlik.gif");

    animation = new QMovie("Smajlik.gif");
    animSet = false;
    if(!smile.isNull()){
        smile = smile.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->label->setPixmap(smile);
    }

    if(animation->isValid()){
        animation->setScaledSize(smile.size());
    }
    else{
        ui->label->setText("None animation");
        workerThread.exit(0);
    }

    OpenViBEVRDemos::CAbstractVrpnPeripheral *worker = new OpenViBEVRDemos::CAbstractVrpnPeripheral;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &MainWindow::operate, worker, &OpenViBEVRDemos::CAbstractVrpnPeripheral::doWork);
    connect(worker, &OpenViBEVRDemos::CAbstractVrpnPeripheral::resultReady, this, &MainWindow::handleResults);
    workerThread.start();
    emit operate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelText(QString string){
    ui->label->setText(string);
}

void MainWindow::drawPicture(QPixmap picture){
    if(picture.isNull()) ui->label->setText("None picture");
    else{
        ui->label->resize(picture.size());
        ui->label->setPixmap(picture);
    }
}

void MainWindow::playMovie()
{
    if(!animSet){
       ui->label->setMovie(animation);
       animSet = true;
    }
    animation->start();
}

void MainWindow::handleResults()
{
    playMovie();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    workerThread.exit(0);
    e->accept();
}
