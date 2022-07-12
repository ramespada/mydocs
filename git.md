# Git

> Git es un sistema de control de cambios que permite llevar registro de modificaciones realizadas en los archivos de un repositorio, asi como facilitar la colaboración entre otras cosas.
 

### Iniciar un repositorio:
```shell
	git init
```

### Agregar archivo y preparar para commit

```shell
	cat "hello world" > hello.txt
	git add hello.txt
```

### Ver estado de repositorio
```shell
	git status
```

### Commit cambios

```shell
	git commit -m "add hello file"
```
Cada commit es como una *fotografía* del repositorio que queda guardada.


### Ver historia del repostorio
```shell
	git log --all --graph --decorate
```

### Ver historial de cambios comandos usados

```shell
	git reflog

```

### Crear branch
```shell
	git branch myBranch
	git checkout myBranch
```


```shell
	git checkout -b myBranch
```

### Merge:

```shell
	git merge -b myBranch
```

### Ir a otros commits o branches:
```shell
	git checkout myBranch
```



### Respositorio remoto

Clonar repositorio remoto:
```shell
	git clone origin master
```

Crear respositorio remoto:
```shell
	git remote
```

Llevar cambios a repositorio remoto:

```shell
	git push
```

Traer objetos y referencias de repo remoto:
```shell
	git fetch
```

Traer la version existente en repositorio remoto al repositorio local
```shell
	git pull
```

es lo mismo que hacer:
```shell
	git pull; git merge
```


### Avanzado:

```shell
	git rebase
```



