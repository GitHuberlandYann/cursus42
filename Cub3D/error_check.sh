#!/bin/sh

EXEC=./cub3D
MAP_DIR=maps/error

GREEN='\033[0;32m'
NC='\033[0m'

check_file()
{
	echo "$GREEN$EXEC $MAP_DIR/$1$NC"
	printf "\t"
	$EXEC $MAP_DIR/$1
}

check_file nosuffix
check_file doesnotexist.cub

check_file header/-rgb.cub
check_file header/+rgb.cub
check_file header/2rgb.cub
check_file header/4rgb.cub
check_file header/invalidNORTH.cub
check_file header/linkoverflow.cub
check_file header/longlink.cub
check_file header/morestuffrgb.cub
check_file header/multipleNORTH.cub
check_file header/nolink.cub
check_file header/noNORTH.cub
check_file header/norGb.cub
check_file header/strrgb.cub
check_file header/zeropaddedrgb.cub

check_file map_content/3players.cub
check_file map_content/centereddoor.cub
check_file map_content/centeredportal.cub
check_file map_content/emptylineinmap.cub
check_file map_content/noplayer.cub
check_file map_content/openline.cub
check_file map_content/openportal.cub
check_file map_content/spaceinmap.cub
