import mysql.connector as mysql

class Cadastro:

    def __init__(self) -> None:
        self.conexao = mysql.connect(host = 'localhost',db = 'pooii' ,user = 'root', passwd = 'meraldo20')
        self.cursor = self.conexao.cursor()
        self.cursor.execute("""CREATE TABLE IF NOT EXISTS usuarios(
                      id INT AUTO_INCREMENT PRIMARY KEY, 
                      nome VARCHAR(100) NOT NULL, 
                      cpf VARCHAR(11) NOT NULL,
                      endereco VARCHAR(100) NOT NULL, 
                      nascimento VARCHAR(20) NOT NULL);""")

    def cadastrar(self,pessoa):

        existe = self.busca(pessoa._cpf)
        if existe == False:
            self.cursor.execute('INSERT INTO usuarios(nome,cpf,endereco,nascimento) VALUES(%s,%s,%s,%s)',(pessoa._nome,pessoa._cpf,pessoa._endereco,pessoa._nascimento))
            self.conexao.commit()
            return True
        else:
            return False
        
    def busca(self,cpf):
        sql = """SELECT * FROM usuarios WHERE cpf = (%s)"""
        val = cpf
        self.cursor.execute(sql,(val,))
        existe = self.cursor.fetchone()
        if existe != None:
            return existe
        else:
            return False

    
    def deletar(self,cpf):
        self.cursor.execute("DELETE FROM usuarios WHERE cpf = (%s)",(cpf,))
        self.conexao.commit()

    def sairExe(self):
        self.conexao.commit()
        self.conexao.close()