# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\tela_principal.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Tela_Principal(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(807, 596)
        MainWindow.setStyleSheet("background-color: rgb(220, 138, 221);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(360, 30, 81, 31))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Condensed")
        font.setPointSize(22)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(9)
        self.label.setFont(font)
        self.label.setStyleSheet("font: 75 22pt \"Ubuntu Condensed\";")
        self.label.setObjectName("label")
        self.botaoJogarOffline = QtWidgets.QPushButton(self.centralwidget)
        self.botaoJogarOffline.setGeometry(QtCore.QRect(330, 240, 151, 61))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Condensed")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(9)
        self.botaoJogarOffline.setFont(font)
        self.botaoJogarOffline.setStyleSheet("font: 75 18pt \"Ubuntu Condensed\";")
        self.botaoJogarOffline.setObjectName("botaoJogarOffline")
        self.botarSair = QtWidgets.QPushButton(self.centralwidget)
        self.botarSair.setGeometry(QtCore.QRect(10, 540, 151, 28))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Condensed")
        font.setPointSize(15)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(9)
        self.botarSair.setFont(font)
        self.botarSair.setStyleSheet("font: 75 15pt \"Ubuntu Condensed\";")
        self.botarSair.setObjectName("botarSair")
        self.botarDesconectar = QtWidgets.QPushButton(self.centralwidget)
        self.botarDesconectar.setGeometry(QtCore.QRect(650, 540, 151, 28))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Condensed")
        font.setPointSize(15)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(9)
        self.botarDesconectar.setFont(font)
        self.botarDesconectar.setStyleSheet("font: 75 15pt \"Ubuntu Condensed\";")
        self.botarDesconectar.setObjectName("botarDesconectar")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(360, 120, 171, 17))
        self.label_6.setStyleSheet("")
        self.label_6.setText("")
        self.label_6.setObjectName("label_6")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(270, 120, 81, 17))
        self.label_9.setStyleSheet("font: 11pt \"URW Gothic\";")
        self.label_9.setObjectName("label_9")
        self.botaoJogarOnline = QtWidgets.QPushButton(self.centralwidget)
        self.botaoJogarOnline.setGeometry(QtCore.QRect(330, 350, 151, 61))
        font = QtGui.QFont()
        font.setFamily("Ubuntu Condensed")
        font.setPointSize(18)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(9)
        self.botaoJogarOnline.setFont(font)
        self.botaoJogarOnline.setStyleSheet("font: 75 18pt \"Ubuntu Condensed\";")
        self.botaoJogarOnline.setObjectName("botaoJogarOnline")
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "PERFIL"))
        self.botaoJogarOffline.setText(_translate("MainWindow", "JOGAR OFFLINE"))
        self.botarSair.setText(_translate("MainWindow", "SAIR"))
        self.botarDesconectar.setText(_translate("MainWindow", "DESCONECTAR"))
        self.label_9.setText(_translate("MainWindow", "NICKNAME"))
        self.botaoJogarOnline.setText(_translate("MainWindow", "JOGAR ONLINE"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Tela_Principal()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
