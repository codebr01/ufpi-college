import socket
import threading


class ClientThread(threading.Thread):
    def __ini__(self, clientAddress, clientsocket):
        self.csocket = clientsocket
        self.name = ''
        print("Nova conexão: ", clientAddress)
        super().__init__()

    def run(self):
        sair = True
        while sair:
            data = self.csocket.recv(1024).decode()
            msg = data.decode()
            print("From ", self.name+": ", msg)
            if ((msg == 'bye') or (msg == None) or (msg == ' ')):
                self.csocket.send(msg.encode())
                sair = False


if __name__ == "__main__":
    LOCALHOST = 'localhost'
    PORT = 6060
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((LOCALHOST, PORT))
    print("server iniciado")
    print("aguardando nova conexão")
    while True:
        server.listen(20)
        clientsock, clientAddress = server.accept()
        newThread = ClientThread(clientAddress, clientsock)
        newThread.start()
