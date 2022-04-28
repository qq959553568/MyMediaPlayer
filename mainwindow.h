#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDebug>
#include<QFileDialog>  //文件查找对话框
#include<QMediaPlayer>  //播放器
#include<QMediaPlaylist>  //播放队列
#include<QVideoWidget>  //视频显示窗口
#include<QPaintEvent>   //绘图事件
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_OpenButton_clicked();

    void on_PlayButton_clicked();

    void on_pauseButton_clicked();

    void on_pushButton_4_clicked();
protected:
    void paintEvent(QPaintEvent*e);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* pPlayer;
    QMediaPlaylist* pPlayerList;
    QVideoWidget* pVideoWidget;
};
#endif // MAINWINDOW_H
