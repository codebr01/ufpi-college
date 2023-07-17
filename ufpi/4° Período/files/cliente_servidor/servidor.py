import socket

host = 'localhost'
port = 8900
address = (host,port)
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(address)
server_socket.listen(10)
con, cliente = server_socket.accept()

while True:
    recebe = con.recv(1024)
    if recebe.decode() != 'sair':
        print('mensagem recebida: '+ recebe.decode())
        enviar = input('Digite uma mensagem: ')
        if enviar != 'sair':
            con.send(enviar.encode())
        else:
            con.send(enviar.encode())
            server_socket.close()
            break
    else:
       server_socket.close()
       break