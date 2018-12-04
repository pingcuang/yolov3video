#pragma once
#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QDialog>
#include<QListWidgetItem>
#include <opencv2/opencv.hpp>
#include<QString>
#include <QButtonGroup>
#include<QWidget>
#include <QtWidgets/QMainWindow>
#include "ui_openvideo.h"

class openvideo : public QMainWindow
{
	Q_OBJECT

public:
	openvideo(QWidget *parent = Q_NULLPTR);
	void imgdetect();
private slots:
	void on_play_clicked();
	void on_detector_clicked();
	void RecvmodelID(int id);
	void on_ratio_clicked();
	void on_rect1_clicked(); void on_rect2_clicked(); void on_rect3_clicked(); void on_rect4_clicked(); void on_rect5_clicked(); void on_rect6_clicked(); void on_rect7_clicked(); void on_rect8_clicked(); void on_rect9_clicked(); void on_rect10_clicked();
private:
	Ui::openvideoClass ui;
	
	QString  rtsp1, rtsp2, rtsp3, rtsp4, rtsp5, rtsp6, rtsp7, rtsp8, rtsp9, rtsp10;
	
	QButtonGroup *m_pGenderGroup;
	
	//QTimer *timer;//定时器用于定时取帧，上面说的隔一段时间就去取就是用这个实现
};
