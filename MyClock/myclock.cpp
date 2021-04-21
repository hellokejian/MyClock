#include "myclock.h"

MyClock::MyClock(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pClockTimer = new QTimer(this);
	m_pClockTimer->setInterval(1000);
	m_nClockTimerId = startTimer(1000);
	ui.lcdNumber->setStyleSheet("border: 1px solid black; color: green; background: black;");
	ui.lcdNumber->setSegmentStyle(QLCDNumber::Flat);
	setWindowFlags(Qt::FramelessWindowHint);
}

MyClock::~MyClock()
{
	if (m_pClockTimer != NULL)
	{
		delete m_pClockTimer;
	}
}

void MyClock::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		//计算点击的相对位置,确定鼠标是否点这个位置是否可以拖动
		QPoint pt = mapFromGlobal(event->globalPos());
		//if(!(pt.x() < 200 && pt.y() < 120))
		{
			//orignalPositon.setX(-1);
			//orignalPositon.setY(-1);
			//event->accept();
			//return;
		}
		//使用dragPosition保存开始移动前鼠标点击的位置，用于计算拖动范围。
		dragPosition = event->globalPos();
		//使用orignalPositon保存开始移动前的主窗口位置
		orignalPositon = /*parentWidget()->pos()*/this->pos();
		//qDebug() << tr("click ") << dragPosition.x() << "," << dragPosition.y();
		//qDebug() << tr("parent pos") << parentWidget()->pos().x() << "," << parentWidget()->pos().y();
		event->accept();
	}
	if (event->buttons() & Qt::RightButton)
	{
		//创建菜单对象
		QMenu *pMenu = new QMenu(ui.lcdNumber);
		QAction *pTaskQuit = new QAction(QString::fromLocal8Bit("退出"), this);
		pMenu->setStyleSheet("color: black; background: white");
		//把QAction对象添加到菜单上
		pMenu->addAction(pTaskQuit);

		//连接鼠标右键点击信号
		connect(pTaskQuit, SIGNAL(triggered()), this, SLOT(onTaskMenuEventQuit()));

		//在鼠标右键点击的地方显示菜单
		pMenu->exec(cursor().pos());
	}
}

void MyClock::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		// 当前鼠标的位置减去开始时保存的位置，就是拖动过程中的偏移量
		// 将这个偏移量加上拖动前的父窗口位置，就是父窗口新的位置
		if(!(orignalPositon.x() == -1 && orignalPositon.y() == -1))
		    this->move(orignalPositon + (event->globalPos() - dragPosition));
		event->accept();
	}
}

void MyClock::timerEvent(QTimerEvent* event)
{
	if (m_nClockTimerId == event->timerId())
	{
		OnClockTimer();
	}
}

void MyClock::OnClockTimer()
{
	//ui.label_clock->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));//yyyy-MM-dd \n 
	QDateTime nCurrentDateTime = QDateTime::currentDateTime();
	ui.lcdNumber->display(nCurrentDateTime.toString("hh:mm:ss"));
}

void MyClock::onTaskMenuEventQuit()
{
	close();
}
