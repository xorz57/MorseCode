#include "mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    for (auto it = lookUpTable1.constBegin(); it != lookUpTable1.constEnd(); ++it) {
        lookUpTable2.insert(it.value(), it.key());
    }

    ui->setupUi(this);

    connect(ui->inputPlainTextEdit, SIGNAL(textChanged()), this, SLOT(convert()));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(ui->actionZoom_In, SIGNAL(triggered(bool)), this, SLOT(zoomIn()));
    connect(ui->actionZoom_Out, SIGNAL(triggered(bool)), this, SLOT(zoomOut()));
}

QString MainWindow::encode(const QString &input) const {
    QString output;

    for (const QChar &c: input) {
        if (lookUpTable1.contains(c.toUpper())) {
            output += lookUpTable1.value(c.toUpper());
        }
        output += ' ';
    }

    return output;
}

QString MainWindow::decode(const QString &input) const {
    QString output;

    for (const QString &token: input.split(' ')) {
        if (lookUpTable2.contains(token)) {
            output += lookUpTable2.value(token);
        }
    }

    return output;
}

void MainWindow::convert() {
    QString input = ui->inputPlainTextEdit->toPlainText();
    if (input.startsWith('.') || input.startsWith('-')) {
        QString output = decode(input);
        ui->outputPlainTextEdit->setPlainText(output);
    } else {
        QString output = encode(input);
        ui->outputPlainTextEdit->setPlainText(output);
    }
}

void MainWindow::open() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream in(&file);
    ui->inputPlainTextEdit->setPlainText(in.readAll());
    file.close();
}

void MainWindow::save() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QTextStream out(&file);
    out << ui->outputPlainTextEdit->toPlainText();
    file.close();
}

void MainWindow::zoomIn() {
    ui->inputPlainTextEdit->zoomIn(1);
    ui->outputPlainTextEdit->zoomIn(1);
}

void MainWindow::zoomOut() {
    ui->inputPlainTextEdit->zoomOut(1);
    ui->outputPlainTextEdit->zoomOut(1);
}
