#include "openvideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	openvideo w;
	w.show();
	return a.exec();
}
