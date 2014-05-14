#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QThread>
#include <QCloseEvent>

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
    void playMovie();
    void playMovie(QMovie *movie);
    void print(QString string);
    bool running;
    virtual void MainWindow::closeEvent(QCloseEvent *e);

private slots:
    void on_pushButton_released();

public slots:
    void doWork();

private:
    Ui::MainWindow *ui;
    QPixmap smile1,smile2;
    QMovie *animation;

};


#endif // MAINWINDOW_H
