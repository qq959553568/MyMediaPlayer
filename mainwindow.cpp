#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置标题
    setWindowTitle("QtCPP");

    //把播放器对象  播放队列对象  显示视频界面的对象做出来
    pPlayer = new QMediaPlayer;
    pPlayerList = new QMediaPlaylist;
    pVideoWidget = new QVideoWidget(ui->label);

    //pVideoWidget->resize(ui->label->size());
    //设置播放器的播放队列
    pPlayer->setPlaylist(pPlayerList);
    //设置播放器的显示窗口
    pPlayer->setVideoOutput(pVideoWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
















//与Slider有关的播放控制变量
QTimer * timer;
int maxValue = 1000;//设置进度条的最大值



//OpenButton按钮被点击
void MainWindow::on_OpenButton_clicked()
{
    //qDebug()<<"这个按钮被点击了";
    //打开一个文件查找框
    //  \微软  /GNU
    QStringList fileNames=QFileDialog::getOpenFileNames(this,"let me see see",
                                                        "C:/Users/DYT/Desktop",
                                                        "allfiles(*.*);;"
                                                        "MP3(*.mp3);;"
                                                        "MP4(*.mp4);;"
                                                        "MKV(*.mkv);;"
                                                        "AVI(*.avi)");
    pPlayerList->clear();//先清空播放队列

    foreach(QString const&str,fileNames){//在QStringList对象中循环
        //qDebug() << str;
        //把选中的音视频文件添加到播放队列中
        QUrl url(str);
        pPlayerList->addMedia(url);

    }
}
//播放函数
void MainWindow::paintEvent(QPaintEvent*e){
    pVideoWidget->resize(ui->label->size());
}
void MainWindow::on_PlayButton_clicked()
{
    pPlayer->play();
}

void MainWindow::on_pauseButton_clicked()
{
    pPlayer->pause();
}

void MainWindow::on_pushButton_4_clicked()
{
    pPlayer->stop();
}
