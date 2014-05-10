#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QThread>
#include "ovaCAbstractVrpnPeripheral.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setLabelText(QString string);
    void drawPicture(QPixmap picture);
    void playMovie(void);
    void playMovie(QMovie *movie);
    void print(QString string);


public slots:
    void handleResults();
    void getMessage(const char *message);


signals:
    void operate();

private slots:
    void on_pushButton_released();

    void on_actionClose_comunication_triggered();

    void on_actionStart_communication_triggered();

private:
    Ui::MainWindow *ui;
    QPixmap smile1,smile2;
    QMovie *animation;


    QThread workerThread;
};


#endif // MAINWINDOW_H
