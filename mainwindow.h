#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convert();

private:
    Ui::MainWindow *ui;

    QString encode(const QString &input);
    QString decode(const QString &input);

    const QMap<QChar, QString> lookUpTable1{
                                            {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
                                            {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
                                            {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
                                            {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
                                            {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
                                            {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
                                            {'Y', "-.--"},  {'Z', "--.."},  {'0', "-----"}, {'1', ".----"},
                                            {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
                                            {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
                                            {' ', "/"},
                                            };

    const QMap<QString, QChar> lookUpTable2{
                                            {".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},  {"-..", 'D'},
                                            {".", 'E'},     {"..-.", 'F'},  {"--.", 'G'},   {"....", 'H'},
                                            {"..", 'I'},    {".---", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
                                            {"--", 'M'},    {"-.", 'N'},    {"---", 'O'},   {".--.", 'P'},
                                            {"--.-", 'Q'},  {".-.", 'R'},   {"...", 'S'},   {"-", 'T'},
                                            {"..-", 'U'},   {"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
                                            {"-.--", 'Y'},  {"--..", 'Z'},  {"-----", '0'}, {".----", '1'},
                                            {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'},
                                            {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
                                            {"/", ' '},
                                            };
};
#endif // MAINWINDOW_H
