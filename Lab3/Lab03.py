
def MSD_Sort_Radix(L, i):

	# lista ja esta organizada
	if len(L) <= 1:
		return L

	# divide (primeiro pela largura, depois pela ordem lexicografica)
	baldepronto = []
	baldes = [ [] for x in range(27) ] #letras de a-z

	for s in L:
		if i >= len(s):
			baldepronto.append(s)
			
		else:
			baldes[ord(s[i]) - ord('A') ].append(s)


	# conquista (ordena recursivamente)
	baldes = [ MSD_Sort_Radix(b, i + 1) for b in baldes ]
	# junta todos baldes
	return baldepronto + [ b for blist in baldes for b in blist ]

def NumWords(L):
	#numera as palavras em um dicionario de uma lista
	d = dict() 
	for word in L: 
		if word in d: 
			d[word] = d[word] + 1
		else: 
			d[word] = 1
	return d

# le o txt e o transforma em uma lista
f = open("war_and_peace_clean.txt", "r")
texto = f.read()
texto_lista = texto.split(" ")
textoorganizado = MSD_Sort_Radix(texto_lista, 0)
f.close()

# cria dicionario com todas palavras e numero de ocorrencias
d = NumWords(texto_lista)

# cria txt com numero de ocorrencias
with open('war_and_peace_clean_ocorrencias.txt', 'w') as f: 
	for key in list(d.keys()): 
		G=[key, ":", str(d[key]), "\n"]
		f.writelines(G) 
f.close()

# cria txt com as palavras na ordem lexicografica
with open('war_and_peace_clean_organizado.txt', 'w') as f:
    for item in textoorganizado:
        f.write("%s " % item)
f.close()

# le o txt e o transforma em uma lista
f = open("frankestein_clean.txt", "r")
texto = f.read()
texto_lista = texto.split(" ")
textoorganizado = MSD_Sort_Radix(texto_lista, 0)
f.close()

# cria dicionario com todas palavras e numero de ocorrencias

d = NumWords(texto_lista)

# cria txt com numero de ocorrencias

with open('frankestein_clean_ocorrencias.txt', 'w') as f: 
	for key in list(d.keys()): 
		G=[key, ":", str(d[key]), "\n"]
		f.writelines(G) 
f.close()

# cria txt com as palavras na ordem lexicografica

with open('frankestein_clean_organizado.txt', 'w') as f:
    for item in textoorganizado:
        f.write("%s " % item)
f.close()
