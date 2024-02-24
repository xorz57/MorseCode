#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::encode(const QString &input) {
    QString output;

    for (const QChar &c : input) {
        if (lookUpTable1.contains(c.toUpper())) {
            output += lookUpTable1.value(c.toUpper());
        }
        output += ' ';
    }

    return output;
}

QString MainWindow::decode(const QString &input) {
    QString output;

    for (const QString &token : input.split(' ')) {
        if (lookUpTable2.contains(token)) {
            output += lookUpTable2.value(token);
        }
    }

    return output;
}

void MainWindow::on_plainTextEdit1_textChanged()
{
    QString input = ui->plainTextEdit1->toPlainText();
    if (input.startsWith('.') || input.startsWith('-')) {
        QString output = decode(input);
        ui->plainTextEdit2->setPlainText(output);
    } else {
        QString output = encode(input);
        ui->plainTextEdit2->setPlainText(output);
    }
}

