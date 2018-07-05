#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(GetScreen()));
    ui->pushButton->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    int timeS = ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString::number(timeS));
    if(timeS!= 0)
    {
       time->start(timeS*1000);
    }
    else
    {
        //如果时间为空 填默认时间
       time->start(10*1000);
       ui->lineEdit->setText("10");
    }
    //如果路径为空 填默认路径
    if(ui->lineEdit_2->text()==NULL)
    {
        ui->lineEdit_2->setText("C:\\");
    }

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);

}
//定时触发，创建文件夹---截屏---存储
void Widget::GetScreen()
{
    dir_str = ui->lineEdit_2->text();

    if(dir_str==NULL)
    {
        dir_str = "C:\\";
        ui->lineEdit_2->setText("C:\\");
    }
    dir_str +="\\Get_ScreenDir";

    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(dir_str))
    {
        bool res = dir.mkpath(dir_str);
        qDebug() << "新建目录是否成功" << res;
    }
    qDebug()<<"1"<<dir_str;
    slotGrabFullScreen();
}

//截屏存储
void Widget::slotGrabFullScreen()

{
    qDebug()<<"2"<<dir_str;
    QScreen *screen = QGuiApplication::primaryScreen();
    QString filePathName = dir_str;
    filePathName += "\\";
    filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss");
    filePathName += ".jpg";
    if(!screen->grabWindow(0).save(filePathName, "JPEG"))

    {
        qDebug()<<"save full screen failed"<<endl;
    }
}
void Widget::on_pushButton_clicked()
{
    time->stop();

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
}
