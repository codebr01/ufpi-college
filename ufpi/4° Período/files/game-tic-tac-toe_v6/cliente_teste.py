import socket
ip = 'localhost'
# ip = '10.180.42.110'
port = 1618
address = ((ip, port))
cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cliente_socket.connect(address)