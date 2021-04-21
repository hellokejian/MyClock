#ifndef MYCLOCK_H
#define MYCLOCK_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include <QTimerEvent>
#include <QDateTime>
#include "ui_myclock.h"
#include <QMouseEvent>
#include <QMenu>

class MyClock : public QMainWindow
{
	Q_OBJECT

public:
	MyClock(QWidget *parent = 0);
	~MyClock();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

private:
	Ui::MyClockClass ui;
	QTimer* m_pClockTimer;
	int m_nClockTimerId;
	void timerEvent(QTimerEvent* event); // ��Ӧ��ʱ���¼�
	void OnClockTimer();
	QPoint dragPosition;
	QPoint orignalPositon;
public slots:
	void onTaskMenuEventQuit();
};

#endif // MYCLOCK_H
