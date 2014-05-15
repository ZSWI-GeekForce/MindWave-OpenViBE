#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QThread>
#include <QCloseEvent>
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

public slots:
    void handleResults();

signals:
    void operate();

private:
    Ui::MainWindow *ui;
    QPixmap smile;
    QMovie *animation;
    QThread workerThread;
    bool animSet;
    virtual void closeEvent(QCloseEvent *e);
};


#endif // MAINWINDOW_H
