#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QPixmap>
#include <QDir>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTimer *time;
    QString dir_str;
private slots:
    void on_pushButton_2_clicked();
    void GetScreen();
    void on_pushButton_clicked();
    void slotGrabFullScreen();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
