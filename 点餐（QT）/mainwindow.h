#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QMap>
#include <QMessageBox>

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
    void on_pushButton1_clicked(); // 下单按钮
    void on_pushButton2_clicked(); // -汉堡
    void on_pushButton3_clicked(); // +汉堡
    void on_pushButton4_clicked(); // +披萨
    void on_pushButton5_clicked(); // -披萨
    void on_pushButton6_clicked(); // +牛角包
    void on_pushButton7_clicked(); // -牛角包
    void on_pushButton8_clicked(); // +羊肉串
    void on_pushButton9_clicked(); // -羊肉串
    void on_pushButton10_clicked(); // +牛肉串
    void on_pushButton11_clicked(); // -牛肉串
    void on_pushButton12_clicked(); // +烤白菜
    void on_pushButton13_clicked(); // -烤白菜
    void on_pushButton14_clicked(); // +烤豆角
    void on_pushButton15_clicked(); // -烤豆角
    void on_pushButton16_clicked(); // +烤韭菜
    void on_pushButton17_clicked(); // -烤韭菜
    void on_pushButton18_clicked(); // +烤土豆
    void on_pushButton19_clicked(); // -烤土豆

private:
    Ui::MainWindow *ui;
    QMap<QString, int> menuCount; // 用于存储菜单项及其数量
    void updateOrderDisplay(); // 更新订单显示
    int moneyAccout;
};

#endif // MAINWINDOW_H
