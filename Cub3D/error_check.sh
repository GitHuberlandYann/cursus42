#!/bin/sh

EXEC=./cub3D
MAP_DIR=maps/error

COUNT=0
ERROR_CODES=0

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

check_file()
{
	echo "\t$GREEN$EXEC $MAP_DIR/$1$NC"
	$EXEC $MAP_DIR/$1
	ERROR_CODES=$(( ERROR_CODES + $? ))
	COUNT=$(( COUNT + 1 ))
}

check_file nosuffix
check_file doesnotexist.cub

check_file header/-rgb.cub
check_file header/+rgb.cub
check_file header/2rgb.cub
check_file header/2windt.cub
check_file header/4rgb.cub
check_file header/badDStext.cub
check_file header/badDtext.cub
check_file header/badfdftext.cub
check_file header/custmissingdouble.cub
check_file header/extracomma.cub
check_file header/invalidNORTH.cub
check_file header/linkoverflow.cub
check_file header/longlink.cub
check_file header/morestuffrgb.cub
check_file header/multipleNORTH.cub
check_file header/nocustt.cub
check_file header/nodotdouble.cub
check_file header/nolink.cub
check_file header/noNORTH.cub
check_file header/nopostt.cub
check_file header/norGb.cub
check_file header/nowindt.cub
check_file header/strrgb.cub
check_file header/zeropaddedrgb.cub

check_file map_content/3players.cub
check_file map_content/centereddoor.cub
check_file map_content/centeredportal.cub
check_file map_content/emptylineinmap.cub
check_file map_content/falsestart.cub
check_file map_content/falsestart2.cub
check_file map_content/falsestart3.cub
check_file map_content/lineaftermap.cub
check_file map_content/nomap.cub
check_file map_content/noplayer.cub
check_file map_content/openline.cub
check_file map_content/openplayer.cub
check_file map_content/openplayerbis.cub
check_file map_content/openportal.cub
check_file map_content/spaceinmap.cub

echo "$RED->\t$ERROR_CODES/$COUNT$NC"