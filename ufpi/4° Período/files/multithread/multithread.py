import threading
import time

class myThread(threading.Thread):
    def __init__(self, nome, contador, delay):
        self.nome = nome
        self.contador = contador
        self.delay = delay
        # self.sinc = sinc
        super().__init__()

    def run(self):
        print("Iniciando " + self.nome)
        # self.sinc.acquire()
        self.print_time(self.nome, self.contador, self.delay)
        # self.sinc.release()
        print("Finalizando " + self.nome)

    def print_time(self, threadName, contador, delay):
        while contador:
            time.sleep(delay)
            print(f"{threadName}: {time.ctime(time.time())}")
            contador -= 1

# sinc = threading.Lock()

thread1 = myThread("Thread-1", 5, 1)
thread2 = myThread("Thread-2", 5, 1)

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print("Finalizando Thread Principal.")