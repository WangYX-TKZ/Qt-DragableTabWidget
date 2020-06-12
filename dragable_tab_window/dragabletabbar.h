#ifndef DRAGABLETABBAR_H
#define DRAGABLETABBAR_H

#include <QApplication>
#include <QObject>
#include <QTabBar>
#include <QMouseEvent>
#include <QDebug>

class DragableTabBar : public QTabBar
{
    Q_OBJECT
public:
    DragableTabBar(QWidget* parent = nullptr);

protected:
    void mousePressEvent (QMouseEvent *e);
    void mouseMoveEvent (QMouseEvent *e);
    void mouseReleaseEvent (QMouseEvent *e);
    void focusOutEvent(QFocusEvent* e);

private:

signals:
    void signalStartDrag(int index);
    void signalEndDrag();

public slots:
    void slotDragMouseMoved(QPoint pos);

private:
    bool dragging;    // 是否正在拖拽
    QPoint press_pos, release_pos;
};

#endif // DRAGABLETABBAR_H
