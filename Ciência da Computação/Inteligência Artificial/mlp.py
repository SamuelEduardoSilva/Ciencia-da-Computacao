

class Ponto:

	def __init__(self, cords):
		self.cords = cords

class Neuronio:

	def __init__(self, x):
		self.x = x
		self.w = np.random.rand(len(x[0].cords))

	def treina(self):
		ultimo = len(self.x[0].cords)
		for i in range(len(self.x)):
			saida = limiar * self.w[0]
			for j in range(ultimo-1):
				saida += (self.x[i].cords[j]*self.w[j+1])

		return saida

class MLP:
	neuronios = []
	def __init__(self, x, camadas, lista):
		self.x = x
		self.camadas = camadas
		self.lista = lista
		for i in range(camadas):
			neuronios.append([])

	def treina(self):
		for i in range(camadas):
			pontos = []
			for j in range(lista[i]):
				


#main

print("Digite o número de camadas")
camadas = int(input())
lista = []

for i in range(camadas):
	print("Digite o número de neuronios da camada %d" %(i+1))
	n = int(input())
	lista.append(n)

f = MLP(x,camadas,lista)