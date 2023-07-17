#10.180.47.232

import socket

# ip = input('digite o ip da conexão: ')
ip = 'localhost'

port = 6060

name = input('Qual seu nome? ')
addr = ((ip,port))
client_sockt = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_sockt.connect(addr)
client_sockt.send(name.encode())

while True:
    mensagem = input('Mensagem: ')
    #recebeu = client_sockt.recv(1024).decode()
    client_sockt.send(mensagem.encode())
    if(mensagem == 'bye'):
        client_sockt.close()
        break
    print('mensagem enviada')
