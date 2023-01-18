#!/bin/bash
#-------------------------------------------------------------------
# WEB-CRAWLER
#==============
#uso: ./crawler <file seeds.txt> <file keywords.txt> 
#output en: URLS.out
#autor: Ramiro A. Espada
#-------------------------------------------------------------------

outputfile="URLS.out"
midfile="suburls"
max_deep=3
deep=0

# MAIN FUNC.========================================================
function main(){
	local seeds=$1		#<file> sitios semilla 
	local keywords=$2	#<file> key-words
	local deep=$3		#<int>  nivel de la recursion;

	if [[ $deep -eq 0 ]]	
	then
		cat ${seeds} > ${outputfile}
		seeds=${outputfile}
	fi
	
	echo -e "Semillas: \e[33m";cat $seeds;echo -e "\e[0m"
	
	deep=$(( $deep + 1 ))


	echo -e "Usando archivo:\e[1m ${seeds} \e[0m"
	while read site
	do
		echo -e "\e[1m Nivel: \e[32m $deep \e[0m"
		
		if [[ $deep -eq 1 ]]
		then
			root=$site
			echo -e "Sitio raiz: \e[32m $root \e[0m"
		fi

		echo -e "	Visitando URL: \e[1m $site \e[0m ..."
		curl $site -silent > temp.html			#extraer html

		if [[ $(check_keywords $keywords temp.html) || ${deep} -le ${max_deep} ]]; 
		then
			
			extractLINKS temp.html ${midfile}${deep};		#guarda links en "${midfile}${deep}"
			
			parseLINKS ${midfile}${deep};				#parseo links
			
			saveLINKS ${root} ${midfile}${deep} ${outputfile};	#guardar en "urls" final
			
			if [[ $deep -eq ${max_deep} ]]
			then
				continue
			else
				main ${midfile}${deep} $keywords ${deep};
			fi
		else
			grep -v ${site} ${outputfile} | cat > swap; mv swap ${outputfile}
		fi
	done < ${seeds}
};

# FUNC. ANEXAS======================================================
#

function extractLINKS(){
#uso: extract_links <temp.html> <list.txt>
    #cat $1 | grep href=\" | grep "http\(s\)\?://www" | grep -o "http\(s\)\?:\/\/[^\"]*" > $2
    grep -Eoi '<a [^>]+>' ${1} | grep -Eo 'href="[^\"]+"' | grep -Eo '(http|https)://[^/"]+' > $2

}

function parseLINKS(){
#uso: parseLINKS <midfile>
	
	sed -i "/www\.\|\.com\|\.ar/!d" ${1}					#dejar lineas "www." ò ".com" ò ".ar"
	sed -i "s/<.*$//p" ${1}  						#remover cosas del estilo "</a>"
	sed -i "s/\/#.*$//p" ${1}  						#remover cosas del estilo "/#" 
	sed -i "/youtube\|facebook\|instagram\|whatsapp\|twitter\|linkedin/d" ${1}	#remover redes sociales
	sed -i "/google\|amazon\|mercadolibre\|itunes/d" ${1};				#remover webs comunes
	sed -i "/\.css\|\.js\|\.json/d" ${1};					#remover contenido web
	sed -i "/\.jpg$\|\.jpeg$\|\.png$\|\.pdf$\|\.ico$\|\.bmp$\|\.svg$/d" ${1};	#remover archivos
	sed -i "/adobe\|java\|addtoany\|firefox\|chrome\|apple\|microsoft\|blogspot\|\.veolia/d" ${1};					#
	sed -i "/error\|robot\.txt/d" ${1};					#
	sed -i "/afip\|arba\|\.go[bv]$\|\.edu$\|\.net$/d" ${1};			#

	sort $1 | uniq | cat > swap; mv swap $1					#ordenar y sacar repetidos

	grep -vf ${outputfile} ${1} | cat > swap; mv swap ${1} 			#sacar los que ya aparecen en ${outputfile}
}

function saveLINKS(){
#uso: saveLINKS <root> <midfile> <URLs.txt>

	grep -v "${1:0:20}*" ${2} | cat > swap;	# remover urls que empiezan igual que la pagina raiz (20 primeros char)
	grep -vf ${3} swap >> ${3}
}

function check_keywords(){
#uso: check_keywords <keywords.txt> <temp.html>
	grep -f $1 $2
	return $?
}

function clean(){
	rm ${midfile}*
	rm swap
}

# EJECUCION=========================================================

main $1 $2 $deep
