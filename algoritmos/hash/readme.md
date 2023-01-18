# Hashing

> El objetivo del **hashing** es mapear un conjunto de datos de dimensión arbitraria en uno de dimensión conocida.


El resultado de una función de hash se conoce como números ó códigos de hash.

## Función de Hash

Una función de hash (*hash function*) es cualquier función que puede ser usada para *mapear* datos de tamaño arbitrario en valores de tamaño fijo.
Los valores de salida de una hash function son llamados hash values, hash codes, digests or simplemente hashes.

Los valores son usados para indexar una tabla de tamaño fijo conocida como *hash table*. El uso de hash functions para indexar una hash table es llamado hashing (ó scatter storage addressing).

Hashing es la transformación de strings de caracterres en un valore de longitud fija usualmente más corta. Esto es usado para indexar y obtener items de una base de datos debido a su rapidez para encontrar items usando hashed keys más cortos en lugar de usar el valor original. 

También tiene uso en algoritmos de encriptación. 


![hashing-algorithm](hashing_algorithm.png)


### Beneficios del hashing

Uno de los principales usos es comprobar si dos archivos son idénticos sin tener que abrirlos para comparar palabra a palabra. 

Hashing tambien es usado para verificar la integridad de un archivo luego de se transferido de un lugar a otro. 

En algunas situaciones un archivo encriptado puede ser diseñado para nunca cambiar el tamaño ni la ultima fecha de modificacion. En estos casos sería imposible distinguir si dos archivos similares son diferentes, pero comparando los hashes se vuelve una tarea posible.

### Propiedades deseables de una función de Hash:
- Bajo costo computacional.
- Compresión
- Uniformidad
- De rango variable
- Inyectividad ( si k1 &ne; k2 &hArr; h(k1) &ne; h(k2) )
- Determinista


## Hash tables



