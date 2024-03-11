"""

Grupo: João Neto, Jorge Luis, Marcos Vinicius e Alisson Rodrigo

"""

import numpy as np
import matplotlib.pyplot as plt

def histograma(imagem):

    h = np.zeros(256, dtype=int)
    for i in range(imagem.shape[0]):
        for j in range(imagem.shape[1]):
            h[imagem[i, j]] += 1

    return h

def equalizacao_histograma(imagem):

    h = histograma(imagem)
    cdf = np.cumsum(h)
    cdf_min = cdf.min()
    num_pixels = imagem.shape[0] * imagem.shape[1]
    eq_imagem = np.floor((cdf[imagem] - cdf_min) / (num_pixels - cdf_min) * 255)
    
    return eq_imagem.astype(np.uint8)

imagem = plt.imread('picos_claro.jpg')

imagem_equalizada = equalizacao_histograma(imagem)

fig,ax = plt.subplots(2,1,figsize=(20,10))

ax[0].imshow(imagem_equalizada,cmap = "gray")
ax[0].set_title('Imagem Equalizada')
ax[1].hist(imagem_equalizada.ravel(),range(256))
ax[1].set_title('Equalização')

plt.show()