#ifndef PROJEKTCPP_WINDOW_H
#define PROJEKTCPP_WINDOW_H


#include <QMainWindow>


class Window : public QWidget{
public:
    explicit Window(QWidget *parent = nullptr);
    ~Window() override = default;
};


#endif //PROJEKTCPP_WINDOW_H
