import sys
import os
import sqlite3

import typing
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QMainWindow, QApplication, QFileDialog, QMessageBox, QWidget
from PyQt5.QtCore import QCoreApplication

from tela_cadastro import Tela_Cadastro
from tela_busca import Tela_Busca
from tela_principal import Tela_Principal
from pessoa import Pessoa
from cadastro import Cadastro

class Ui_Main(QtWidgets.QWidget):
    def setupUi(self, Main):
        Main.setObjectName('Main')
        Main.resize(800,600)

        self.QtStack = QtWidgets.QStackedLayout()

        self.stack0 = QtWidgets.QMainWindow()
        self.stack1 = QtWidgets.QMainWindow()
        self.stack2 = QtWidgets.QMainWindow()

        self.tela_principal = Tela_Principal()
        self.tela_principal.setupUi(self.stack0)

        self.tela_cadastro = Tela_Cadastro()
        self.tela_cadastro.setupUi(self.stack1)

        self.tela_busca = Tela_Busca()
        self.tela_busca.setupUi(self.stack2)

        self.QtStack.addWidget(self.stack0)
        self.QtStack.addWidget(self.stack1)
        self.QtStack.addWidget(self.stack2)

class Main(QMainWindow,Ui_Main):
    def __init__(self, parent = None):
        super(Main,self).__init__(parent)
        self.setupUi(self)

        self.cad = Cadastro()
        
        self.tela_principal.pushButton.clicked.connect(self.abrirTelaCadastro)
        self.tela_principal.pushButton_2.clicked.connect(self.abrirTelaBusca)
        self.tela_principal.pushButton_3.clicked.connect(self.sairExe)

        self.tela_cadastro.pushButton_2.clicked.connect(self.voltarTelaPrincipal)
        self.tela_cadastro.pushButton.clicked.connect(self.botaoCadastrar)
        self.tela_busca.pushButton_3.clicked.connect(self.botaoDeletar)

        self.tela_busca.pushButton_2.clicked.connect(self.voltarTelaPrincipal)
        self.tela_busca.pushButton.clicked.connect(self.botaoBuscar)
        self.conexao = sqlite3.connect('teste.sqlite')
        self.cursor = self.conexao.cursor()
        self.sql = """CREATE TABLE IF NOT EXISTS usuarios(id integer PRIMARY KEY, 
                      nome text NOT NULL, 
                      cpf text NOT NULL,
                      endereco text NOT NULL, 
                      nascimento text NOT NULL);"""
    
    def botaoCadastrar(self):
        nome = self.tela_cadastro.lineEdit.text()
        cpf = self.tela_cadastro.lineEdit_3.text()
        endereco = self.tela_cadastro.lineEdit_2.text()
        nascimento = self.tela_cadastro.lineEdit_4.text()
        if not(nome == '' or cpf == '' or endereco == '' or nascimento == ''):
            p = Pessoa(nome,cpf,endereco,nascimento)
            if self.cad.cadastrar(p):
                self.cursor.execute(self.sql)
                self.cursor.execute('INSERT INTO usuarios(nome,cpf,endereco,nascimento) VALUES(?,?,?,?)',(nome,cpf,endereco,nascimento))
                self.conexao.commit()
                QMessageBox.information(None,'POO II','Cadastro Realizado!')
                self.tela_cadastro.lineEdit.setText('')
                self.tela_cadastro.lineEdit_2.setText('')
                self.tela_cadastro.lineEdit_3.setText('')
                self.tela_cadastro.lineEdit_4.setText('')
            else:
                QMessageBox.information(None,'POOII','Cadastrado já existe!')
        else:
            QMessageBox.information(None,'POOII','Todo os campos devem estar preenchidos!')

    def botaoBuscar(self):
        pessoa = self.tela_busca.lineEdit.text()
        #existe = self.cad.busca(pessoa)
        self.cursor.execute('SELECT * from usuarios WHERE cpf = (?)',(pessoa))
        existe = self.cursor.fetchone() 
        if existe != None:
            self.tela_busca.lineEdit_2.setText(existe[1])#nome
            self.tela_busca.lineEdit_3.setText(existe[3])#nascimento
            self.tela_busca.lineEdit_4.setText(existe[4])#endereço

        elif pessoa == '':
            QMessageBox.information(None,'POO II','Nenhum campo informado!')
        else:
            QMessageBox.information(None,'POO II','Pessoa não cadastrada!')

    def botaoDeletar(self):
        pessoa = self.tela_busca.lineEdit.text()
        self.cursor.execute('SELECT * from usuarios WHERE cpf = (?)',(pessoa))
        existe = self.cursor.fetchone()
        if existe != None:
            option = QMessageBox.question(None,'DELETAR DADO','Você deseja deletar?',QMessageBox.Yes | QMessageBox.No)
            if option == QMessageBox.Yes:
                self.cursor.execute('DELETE FROM usuarios WHERE cpf = (?)',(pessoa))
                self.conexao.commit()
                self.cad.deletar(pessoa)
                QMessageBox.information(None,'POO II','CPF CANCELADO')
            elif QMessageBox.No:
                QMessageBox.information(None,'POO II','CPF NAO CANCELADO')
        else:
            QMessageBox.information(None,'POO II','Pessoa não cadastrada!')


    def voltarTelaPrincipal(self):
        self.QtStack.setCurrentIndex(0)

    def abrirTelaCadastro(self):
        self.QtStack.setCurrentIndex(1)

    def abrirTelaBusca(self):
        self.QtStack.setCurrentIndex(2)

    def sairExe(self):
        self.conexao.commit()
        self.conexao.close()
        exit()
        

if __name__ == '__main__':
    app = QApplication(sys.argv)
    show_main = Main()
    sys.exit(app.exec_())