# Curl

> es un proyecto de software libre consistente en una biblioteca (libcurl) y un intérprete de comandos (curl) orientado a la transferencia de archivos. Soporta los protocolos FTP, FTPS, HTTP, HTTPS, TFTP, SCP, SFTP, Telnet, DICT, FILE y LDAP, entre otros. 


cURL soporta certificados HTTPS, HTTP POST, HTTP PUT, subidas FTP, Kerberos, subidas mediante formulario HTTP, proxies, cookies, autenticación mediante usuario y contraseña (Basic, DIgest, NTLM y Negotiate para HTTP y kerberos 4 para FTP), continuación de transferencia de archivos, tunneling de proxy HTTP y otras prestaciones. cURL es de código abierto, software libre distribuido bajo la Licencia MIT.

El principal propósito y uso para cURL es automatizar transferencias de archivos o secuencias de operaciones no supervisadas. Es por ejemplo, una herramienta válida para simular las acciones de usuarios en un navegador web. 



Tine cerca de 230 flags (opciones de ejecución).
Algunos flags:

- `` -s `` (``--silent``)
- `` -s ``
- `` -s ``
- `` -s ``
- `` -s ``


Tiene comportamiento minimalista por default.


## HTTP

Consiste en:
+ Request:
   - method +  path
   - headers
   - body
+ Respuesta


### GET
Simple get:
```bash
$ curl example.com
```

GET + mostrar headers respuesta
```bash
$ curl -i example.com
```
GET + mostrar headers respuesta sin body
```bash
$ curl -I example.com
```

GET +  mostrar JSON:
```bash
$ curl -i example.com/json | jq
```


GET + redireccion
```bash
$ curl -I -L example.com/redirected
```


#### URL "globbing"
```bash
$ curl -I -L example.com/[1-9].html
$ curl -I -L example.com/[01-99].html
$ curl -I -L example.com/[a-z].html
$ curl -I -L example.com/[1-9:2].html
$ curl -I -L example.com/[a-z:3].html
```

Guardar según parametro:
```bash
$ curl example.com/[1-9].html -o save_#1.html
$ curl example.com/{ham,cheese,pinapple}.jpg -o save_#1.jpg
```


```bash
curl -X POST https://reqbin.com/echo/post/json
   -H 'Content-Type: application/json'
   -d '{"login":"my_login","password":"my_password"}'
```



Pass en headers HTTP custom:
```bash
$ curl https://example.com/ -H "User-agent: disc0 1n th3 n1gh7"
$ curl https://reqbin.com/echo/get/json -H "Accept: application/json" 
```


### POST:

Enviar datos a un servidor:

```bash
$ curl -d @file https://example.com/receiver -o saved
$ ls -l | curl -d @- https://example.com/receiver -o saved
$ curl --data-binary @file.json -H "Content-Type: application/json" https://example.com/receiver -o saved
```


```bash
$ curl -X POST https://reqbin.com/echo/post/form
   -H "Content-Type: application/x-www-form-urlencoded" 
   -d "param1=value1&param2=value2" 
```


### PUT:
Reemplazar datos en un servidor:

```bash 
curl -T localfile -i https://example.com/remote_name

```



### Cookies:
```bash 
curl -c cookiejar.txt -i https://example.com/login_form
curl -b cookiejar.txt -i https://example.com/login -d user=daniel -d password=1234
curl -c cookiejar.txt -b cookiejar.txt -i https://example.com/profile
```



### Servidores locales:
```bash 
curl https://127.0.0.1/
curl -k https://127.0.0.1/
curl -k https://127.0.0.1/ -H "Host: example.com"
curl https://example.com/ --resolve example.com:443:127.0.0.1
```







### Convertir a aplicación:

Convierte comando en un programa en "c"

```bash 
curl https://example.com/ --libcurl sourcecode.c
gcc sourcecode.c -lcurl -o ./myapp
```



