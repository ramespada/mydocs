#!/bin/bash

#GFS:  resol. espacial 0.5º ~  55.5 km
#
### GLOBAL:
# time_step=240,?	# resol-t?
# dx=25000,     ?	# resol-X?
# dy=25000,     ?	# resol-Y?
# e_vert=45,    ?	# resol-Z?
#
# DT=$(bc -l <<< "60*60*24*2")		# cuanto tiempo antes empezar la corrida? [segs]
#
#
#Bahía  16 marzo 2009 
#		      name  date      clat 	   clon 	DX  	DY
./pltWRFmesh.sh	Bahia 16mar2009 -39.704213 -61.833573   500     500

#Patagonia 28 marzo 2009
#	clat	   clon	      DX   DY
#	-43.034952 -64.143677 1000 1000
./pltWRFmesh.sh	Patagonia 28mar2009 -43.004952 -64.153677 800 1100

#Madryn 05 de abril 2009
#	(misma que patagonia 28 marzo 2009.)

#Marchiquita + Bahía  05 de agosto 2009.

./pltWRFmesh.sh	MarChiquita 05ago2009 -30.562957, -62.506265 300 300

#Cuyo  11-12 julio 2010
./pltWRFmesh.sh	Cuyo 11jul2010 -32.951274 -68.854580 400 600

#Munster 03 noviembre 2016
#	(misma que patagonia 28 marzo 2009.)

#Antofagasta 13 septiembre 2017

./pltWRFmesh.sh	Antofagasta 13sep2017 -22.896295 -67.589588 600 600

