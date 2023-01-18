#!/bin/bash
#
#Buscador de semillas
#

outfile="webs"

busquedas=("medio ambiente consultora" "servicios ambientales industria" "servicios ingenieria ambiental" "monitoreo ambiental" "estudios impacto ambiental" "laboratorio ambiental")
common="argentina"

touch ${outfile}

for busqueda in "${busquedas[@]}"
do
	echo -e "Buscando: \e[1m ${busqueda}"
	ddgr --json -r "es-ar" -n 25 "${busqueda} ${common}" | grep "http\(s\)\?://www" | grep -o "http\(s\)\?:\/\/[^\"]*"| grep "http\(s\)\?://www" | grep -o "http\(s\)\?:\/\/[^\"]*" >> ${outfile}

	#puedo hacer lo mismo con "googler"

	sort ${outfile} | uniq | cat > temporal; mv temporal ${outfile}
done
