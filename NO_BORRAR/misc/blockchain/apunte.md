# BLOCKCHAIN

> Definición: Blockchain es una forma o subconjunto específico de Tecnología de Registro Distribuido (DLT), formado por bloques asociados los unos con los otros en una cadena cronológica.

Contribuidores:  Satoshi Nakamoto (desconocido, Bitcoin), Nick Szabo, Hal Finney, Vitalik Buterin (Etherium)

## 1. Fundamentos

### Distributed Ledger Technologies (DLT)
Las tecnologías de registros distribuidos es una base de datos compartida, donde cada participante/usuario poseé una copia completa de la misma e idéntica a la del resto.

Consta de:
- **modelo de datos**
- **lenguaje de transacciones**
- **protocolo de generación de consenso**


### Características de blockchain:

Blockchain consiste en una base de datos formada por bloques conectados entre ellos de forma consecutiva.

Poseé las siguientes propiedades:
1. Inmutabilidad
2. Sin intermediarios (descentralizada)
3. Consenso
4. Registro creciente (no se puede borrar, para anular se require una nueva transacción)
5. Auditable en todo momento


Cada bloque contiene:
+  *TimeStamp*
+  *Data* Por ejemplo información de transacción
+  *Hash de bloque previo*
+  *Hash* Basada en el contenido de todo el bloque
+  *nonse* es un string que le da al hash del bloque total una propiedad especial


La incorporación del hash del bloque anterior en cada bloque tiene como objetivo:
- Si se detecta que un bloque es erroneo, al eliminarse se anulan automaticamente todos los bloques dependientes de este.
- Para incertar un bloque falso hay que modificar un bloque y recalcular todos los hashes de los bloques anteriores, lo que lo hace muy costoso computacionalmente.

#### Árbol de Merkle:
Es una forma de crear un hash (en forma de arbol) para todo el bloque, de forma tal que sea muy sensible a modificaciones. 



### Proof of work (PoW): 
Mecanísmo que hace lento/ineficiente la creación de nuevos bloques. Es una forma de evitar la creación malintencionada de bloques.
Consiste en resolver algún puzzle matemático solo resolvible mediante *fuerza bruta* (usualmente vinculado a facotrización de primos, ó encontrar string que haga que el hash del bloque empiece con n-ceros), la solución es necesaria para validar la incorporación de bloques a la base de datos.
Los usuarios que se encargan de validar los bloques se los llama **mineros**, y reciben un incentivo por la validación (por ejemplo un porcentaje de la transacción).


### Red *peer-to-peer*
Todos los usuarios de la base de datos poseen una copia de la misma base de datos.



### Otros mecanismos de validación
+ *Proof of stake* (**PoS**) es una alternativa a **proof-of-work** que no involucra el uso de recursos computacionales para validar la incorporación de bloques, sino que se hace medidado por **validadores** que son usuarios cuya confianza está determinada por algún atributo. Es un poco más centralizado que PoW.

+ *Proof of authority* (**PoA**)


### Otros tipos de bloques:
*Smart contracts*  son contratos completamente digitales que permiten automatizar transacciones en una blockchain. Consisten en un programa autoejecutable embebidos en una blockchain que realizan operaciones según las reglas del contrato.



## 2. Usos:

+ Criptomonedas

+ Tracking de bienes en cadena productiva (tracabilidad)

+ Documentación digital

+ Voto digital



