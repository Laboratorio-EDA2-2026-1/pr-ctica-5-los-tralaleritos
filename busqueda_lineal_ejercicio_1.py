def busqueda_lineal(arr, num):
    if num in arr:
        return f"El numero que buscas esta en el indice: {arr.index(num)}"
    else:
        return f"El numero que buscas no esta en el arreglo"


arreglo = [12,3434,678,14,789,1,6,8,9,0,11]

print(busqueda_lineal(arreglo, 14))
