import socket
ip = 'localHost'
#ip = '10.180.41.63'
port = 8900
address = ((ip,port))
cliente_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
cliente_socket.connect(address)

while True:
    mensagem = input('Digite uma mensagem: ')
    cliente_socket.send(mensagem.encode())
    recebeu = cliente_socket.recv(1024).decode()
    if recebeu != 'sair':
        if mensagem != 'sair':
            print('mensagem enviada')
            print('mensagem recebida: '+ recebeu)
        else:
            cliente_socket.close()
            break
    else:
        cliente_socket.close()
        break