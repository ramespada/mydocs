#!/bin/bash

#objetivo
#	Para una lista navegarlas, y extraer los campos:
#		
urls=$1

while read base_url
do
	current_url=$base_url
	
	echo $current_url
	curl $current_url -silent > temp.html
	
	stat="s"
	while [ $stat -ne "next" ]
	do

		read  -n 1 -p $stat $arg1 $arg2 $arg3


		if [[ $stat == "s" ]] #show
		then
		
			if [[ $arg1 == "links" ]] #links
			then
				echo "hola"
				grep -Eoi '<a [^>]+>' temp.html | grep -Eo 'href="[^\"]+"' | grep -Eo '(http|https)://[^/"]+' 

			elif [[$arg1 == "contacts" ]] #contacts
			then
				grep -Eoi '<a [^>]+>' temp.html | grep -Eo '@*.com"';

			elif [[$arg1 == "services" ]] #services
			then
				grep -Eoi "servicios" temp.html;
	
			else
				continue;

			fi

		#elif [[ $stat == "write" ]]
		#then

		elif [[ $stat == "go" ]]
		then
			current_url=$arg1
			curl $current_url -silent > temp.html

		else 
			continue
		
		fi

	done
done < ${urls}
