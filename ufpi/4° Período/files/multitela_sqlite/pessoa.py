class Pessoa:
    def __init__(self,nome,cpf,endereco,nascimento) -> None:
        self._nome = nome
        self._cpf = cpf
        self._endereco = endereco
        self._nascimento = nascimento

    @property
    def nome(self):
        return self._nome
    
    @property
    def cpf(self):
        return self._cpf
    
    @property
    def endereco(self):
        return self._endereco
    

    @property
    def nascimento(self):
        return self._nascimento