#pragma once

#include "ui_mainwindow.h"

#include <QChar>
#include <QMainWindow>
#include <QMap>
#include <QString>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void convert();
    void open();
    void save();
    void zoomIn();
    void zoomOut();

private:
    [[nodiscard]] QString encode(const QString &input) const;
    [[nodiscard]] QString decode(const QString &input) const;

    const QMap<QChar, QString> lookUpTable1{
            {'A', ".-"},
            {'B', "-..."},
            {'C', "-.-."},
            {'D', "-.."},
            {'E', "."},
            {'F', "..-."},
            {'G', "--."},
            {'H', "...."},
            {'I', ".."},
            {'J', ".---"},
            {'K', "-.-"},
            {'L', ".-.."},
            {'M', "--"},
            {'N', "-."},
            {'O', "---"},
            {'P', ".--."},
            {'Q', "--.-"},
            {'R', ".-."},
            {'S', "..."},
            {'T', "-"},
            {'U', "..-"},
            {'V', "...-"},
            {'W', ".--"},
            {'X', "-..-"},
            {'Y', "-.--"},
            {'Z', "--.."},
            {'0', "-----"},
            {'1', ".----"},
            {'2', "..---"},
            {'3', "...--"},
            {'4', "....-"},
            {'5', "....."},
            {'6', "-...."},
            {'7', "--..."},
            {'8', "---.."},
            {'9', "----."},
            {' ', "/"},
            {',', "--..--"},
            {'.', ".-.-.-"},
            {'?', "..--.."},
            {'\'', ".----."},
            {'!', "-.-.--"},
            {'/', "-..-."},
            {'(', "-.--."},
            {')', "-.--.-"},
            {'&', ".-..."},
            {':', "---..."},
            {';', "-.-.-."},
            {'=', "-...-"},
            {'+', ".-.-."},
            {'-', "-....-"},
            {'_', "..--.-"},
            {'"', ".-..-."},
            {'$', "...-..-"},
            {'@', ".--.-."},
    };

    QMap<QString, QChar> lookUpTable2;

    std::shared_ptr<Ui::MainWindow> ui = std::make_shared<Ui::MainWindow>();
};
