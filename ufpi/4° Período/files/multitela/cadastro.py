class Cadastro:

    __slots__ = ['_lista_de_pessoas']

    def __init__(self) -> None:
        self._lista_de_pessoas = []

    def cadastrar(self,pessoa):
        existe = self.busca(pessoa._cpf)
        if(existe == None):
            self._lista_de_pessoas.append(pessoa)
            return True
        else:
            return False
        
    def busca(self,cpf):
        for lista in self._lista_de_pessoas:
            if lista._cpf == cpf:
                return lista
        return None