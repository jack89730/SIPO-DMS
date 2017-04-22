#ifndef EXAMINER_H
#define EXAMINER_H

#include <QWidget>

namespace Ui {
class Examiner;
}

class Examiner : public QWidget
{
    Q_OBJECT

public:
    explicit Examiner(QWidget *parent = 0);
    ~Examiner();

private:
    Ui::Examiner *ui;
};

#endif // EXAMINER_H
