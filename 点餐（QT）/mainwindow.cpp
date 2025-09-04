#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QLabel 显示静态图(图片时windows下的绝对路径把右斜杠'\'换成左斜杠'/') 注意路径使用的是绝对路径
    QPixmap pic1(":/image/image/1.jpg");
    //当图片的大小和QLabel的大小不一致时，根据控件的大小调整图片的大小比例缩放
    pic1 = pic1.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(pic1);

    QPixmap pic2(":/image/image/2.jpg");
    pic2 = pic2.scaled(ui->label->width(),ui->label->height());
    ui->label_2->setPixmap(pic2);

    QPixmap pic3(":/image/image/3.jpg");
    pic3 = pic3.scaled(ui->label->width(),ui->label->height());
    ui->label_3->setPixmap(pic3);

    QPixmap pic4(":/image/image/4.jpg");
    pic4 = pic4.scaled(ui->label->width(),ui->label->height());
    ui->label_4->setPixmap(pic4);

    QPixmap pic5(":/image/image/5.jpg");
    pic5 = pic5.scaled(ui->label->width(),ui->label->height());
    ui->label_5->setPixmap(pic5);

    QPixmap pic6(":/image/image/6.jpg");
    pic6 = pic6.scaled(ui->label->width(),ui->label->height());
    ui->label_6->setPixmap(pic6);

    QPixmap pic7(":/image/image/7.jpg");
    pic7 = pic7.scaled(ui->label->width(),ui->label->height());
    ui->label_7->setPixmap(pic7);

    QPixmap pic8(":/image/image/8.jpg");
    pic8 = pic8.scaled(ui->label->width(),ui->label->height());
    ui->label_8->setPixmap(pic8);

    QPixmap pic9(":/image/image/10.jpg");
    pic9 = pic9.scaled(ui->label->width(),ui->label->height());
    ui->label_9->setPixmap(pic9);

    // 初始化菜单数量
    menuCount["汉堡"] = 0;
    menuCount["披萨"] = 0;
    menuCount["牛角包"] = 0;
    menuCount["羊肉串"] = 0;
    menuCount["牛肉串"] = 0;
    menuCount["烤白菜"] = 0;
    menuCount["烤豆角"] = 0;
    menuCount["烤韭菜"] = 0;
    menuCount["烤土豆"] = 0;

   moneyAccout = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateOrderDisplay()
{
    ui->textEdit->clear();
    for (auto it = menuCount.constBegin(); it != menuCount.constEnd(); ++it)
    {
        if (it.value() > 0)
        {
            QString orderLine = QString("%1\tx%2").arg(it.key()).arg(it.value());
            ui->textEdit->append(orderLine);
        }
    }
}

// 下单
void MainWindow::on_pushButton1_clicked()
{
    QString message = QString("总金额:%1 元").arg(moneyAccout); // 使用 arg 方法插入金额
    QMessageBox::information(this, "下单成功！", message); // 显示对话框
}

// -汉堡 8元
void MainWindow::on_pushButton2_clicked()
{
    if (menuCount["汉堡"] > 0)
    {
        menuCount["汉堡"]--;
        updateOrderDisplay();
        moneyAccout -= 8;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +汉堡
void MainWindow::on_pushButton3_clicked()
{
    menuCount["汉堡"]++;
    updateOrderDisplay();
    moneyAccout += 8;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -披萨 38
void MainWindow::on_pushButton4_clicked()
{
    if (menuCount["披萨"] > 0)
    {
        menuCount["披萨"]--;
        updateOrderDisplay();
        moneyAccout -= 38;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +披萨
void MainWindow::on_pushButton5_clicked()
{
    menuCount["披萨"]++;
    updateOrderDisplay();
    moneyAccout += 38;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -牛角包 8
void MainWindow::on_pushButton6_clicked()
{
    if (menuCount["牛角包"] > 0)
    {
        menuCount["牛角包"]--;
        updateOrderDisplay();
        moneyAccout -= 8;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +牛角包
void MainWindow::on_pushButton7_clicked()
{
    menuCount["牛角包"]++;
    updateOrderDisplay();
    moneyAccout += 8;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -羊肉串 3
void MainWindow::on_pushButton8_clicked()
{
    if (menuCount["羊肉串"] > 0)
    {
        menuCount["羊肉串"]--;
        updateOrderDisplay();
        moneyAccout -= 3;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +羊肉串
void MainWindow::on_pushButton9_clicked()
{
    menuCount["羊肉串"]++;
    updateOrderDisplay();
    moneyAccout += 3;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -牛肉串 3
void MainWindow::on_pushButton10_clicked()
{
    if (menuCount["牛肉串"] > 0)
    {
        menuCount["牛肉串"]--;
        updateOrderDisplay();
        moneyAccout -= 3;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +牛肉串
void MainWindow::on_pushButton11_clicked()
{
    menuCount["牛肉串"]++;
    updateOrderDisplay();
    moneyAccout += 3;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -烤白菜 2
void MainWindow::on_pushButton12_clicked()
{
    if (menuCount["烤白菜"] > 0)
    {
        menuCount["烤白菜"]--;
        updateOrderDisplay();
        moneyAccout -= 2;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +烤白菜
void MainWindow::on_pushButton13_clicked()
{
    menuCount["烤白菜"]++;
    updateOrderDisplay();
    moneyAccout += 2;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -烤豆角 2
void MainWindow::on_pushButton14_clicked()
{
    if (menuCount["烤豆角"] > 0)
    {
        menuCount["烤豆角"]--;
        updateOrderDisplay();
        moneyAccout -= 2;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +烤豆角
void MainWindow::on_pushButton15_clicked()
{
    menuCount["烤豆角"]++;
    updateOrderDisplay();
    moneyAccout += 2;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -烤韭菜 2
void MainWindow::on_pushButton16_clicked()
{
    if (menuCount["烤韭菜"] > 0)
    {
        menuCount["烤韭菜"]--;
        updateOrderDisplay();
        moneyAccout -= 2;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +烤韭菜
void MainWindow::on_pushButton17_clicked()
{
    menuCount["烤韭菜"]++;
    updateOrderDisplay();
    moneyAccout += 2;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}
// -烤土豆 2
void MainWindow::on_pushButton18_clicked()
{
    if (menuCount["烤土豆"] > 0)
    {
        menuCount["烤土豆"]--;
        updateOrderDisplay();
         moneyAccout -= 2;

        QString str = QString::number(moneyAccout);
        ui->money->setText(str+" 元");
    }
}
// +烤土豆
void MainWindow::on_pushButton19_clicked()
{
    menuCount["烤土豆"]++;
    updateOrderDisplay();
    moneyAccout += 2;

    QString str = QString::number(moneyAccout);
    ui->money->setText(str+" 元");
}



