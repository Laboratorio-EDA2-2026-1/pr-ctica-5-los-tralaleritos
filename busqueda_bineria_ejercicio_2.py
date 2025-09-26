def codigo_binario(x, pasos):
    bajo = 0.0
    alto = 1.0
    
    resultado = ""
    for i in range(pasos):
        medio = (bajo + alto)/2
        if x < medio:
            resultado += "0"
            alto = medio
        else:
            resultado += "1"
            bajo = medio

    return resultado

codigo = codigo_binario(0.625, 3)
print(codigo)