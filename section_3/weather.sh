#!/bin/bash

while getopts "x:y:" option; do
	case "$option" in
		x) latitude="$OPTARG" ;;
		y) longitude="$OPTARG" ;;
		\?) echo "Использование: $0 -x <ширина> -y <долгота> "
			  exit 1 ;;
	esac
done

if [ -z "$longitude" ] || [ -z "$latitude" ]; then
	echo "Введите обе координаты x и y"
	exit 1
fi

echo "$(curl -s "wttr.in/$latitude,$longitude")"


