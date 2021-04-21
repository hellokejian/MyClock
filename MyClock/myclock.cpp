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
		//�����������λ��,ȷ������Ƿ�����λ���Ƿ�����϶�
		QPoint pt = mapFromGlobal(event->globalPos());
		//if(!(pt.x() < 200 && pt.y() < 120))
		{
			//orignalPositon.setX(-1);
			//orignalPositon.setY(-1);
			//event->accept();
			//return;
		}
		//ʹ��dragPosition���濪ʼ�ƶ�ǰ�������λ�ã����ڼ����϶���Χ��
		dragPosition = event->globalPos();
		//ʹ��orignalPositon���濪ʼ�ƶ�ǰ��������λ��
		orignalPositon = /*parentWidget()->pos()*/this->pos();
		//qDebug() << tr("click ") << dragPosition.x() << "," << dragPosition.y();
		//qDebug() << tr("parent pos") << parentWidget()->pos().x() << "," << parentWidget()->pos().y();
		event->accept();
	}
	if (event->buttons() & Qt::RightButton)
	{
		//�����˵�����
		QMenu *pMenu = new QMenu(ui.lcdNumber);
		QAction *pTaskQuit = new QAction(QString::fromLocal8Bit("�˳�"), this);
		pMenu->setStyleSheet("color: black; background: white");
		//��QAction������ӵ��˵���
		pMenu->addAction(pTaskQuit);

		//��������Ҽ�����ź�
		connect(pTaskQuit, SIGNAL(triggered()), this, SLOT(onTaskMenuEventQuit()));

		//������Ҽ�����ĵط���ʾ�˵�
		pMenu->exec(cursor().pos());
	}
}

void MyClock::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		// ��ǰ����λ�ü�ȥ��ʼʱ�����λ�ã������϶������е�ƫ����
		// �����ƫ���������϶�ǰ�ĸ�����λ�ã����Ǹ������µ�λ��
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
