#!/bin/bash
function check(){
	if [ -e "/home/$1" ]
		then 
		return 0
	else 
		return 1
	fi
}
