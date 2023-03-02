/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:49:44 by yhuberla          #+#    #+#             */
/*   Updated: 2023/03/02 16:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define MSG_ARGS "Usage :  ./cub3D maps/<insert map name>.cub\n"
# define MSG_MAP " -> invalid map\n"
# define MSG_PREFIX "Map should start with 'maps/'"
# define MSG_SUFFIX "Map should end with '.cub'"
# define MSG_OPEN "Open failed"
# define MSG_TWONO "Two different lines start with 'NO'"
# define MSG_TWOSO "Two different lines start with 'SO'"
# define MSG_TWOWE "Two different lines start with 'WE'"
# define MSG_TWOEA "Two different lines start with 'EA'"
# define MSG_TWOFT "Two different lines start with 'FT'"
# define MSG_TWOCT "Two different lines start with 'CT'"
# define MSG_TWODOORS "Two different lines start with 'D'"
# define MSG_TWODOORSIDES "Two different lines start with 'DS'"
# define MSG_TWOBARRELS "Two different lines start with 'BT'"
# define MSG_TWOPILLARS "Two different lines start with 'PT'"
# define MSG_TWOPOSTS "Two different lines start with 'POSTT'"
# define MSG_TWOCUSTS "Two different lines start with 'CUSTT'"
# define MSG_TWOWINDS "Two different lines start with 'WINDT'"
# define MSG_RGBZEROPAD "RGB values can't be zero-padded"
# define MSG_RGB255 "RGB values can't be greater than 255"
# define MSG_RGBUNSET "Unset or incorrect RGB value"
# define MSG_FCEND "F/C line has unwanted elements ending it"
# define MSG_LINKZEROPAD "Portal index can't be zero-padded"
# define MSG_LINK255 "Portal index can't go above 255"
# define MSG_LINKUNSET "Unset or incorrect portal index"
# define MSG_LINKEND "LINK line has unwanted elements ending it"
# define MSG_OBJZEROPAD "Object position can't be zero-padded"
# define MSG_OBJ255 "Object position can't be greater than 255"
# define MSG_OBJUNSET "Unset or incorrect Object position"
# define MSG_OBJZERO "Object position can't be set at zero"
# define MSG_OBJEND "Object line has unwanted elements ending it"
# define MSG_POSTZEROPAD "Post double can't be zero-padded"
# define MSG_POST255 "Post double can't be greater than 255"
# define MSG_POSTUNSET "Unset or incorrect Post double"
# define MSG_POSTDECI255 "Post double's decimal part can't be greater than 255"
# define MSG_POSTDECIUNSET "Unset or incorrect Post double's decimal part"
# define MSG_POSTDOT "Missing '.' in Post double"
# define MSG_POSTZERO "Object double can't be set at zero"
# define MSG_POSTEND "Post line has unwanted elements ending it"
# define MSG_CUSTZEROPAD "Cust double can't be zero-padded"
# define MSG_CUST255 "Cust double can't be greater than 255"
# define MSG_CUSTUNSET "Unset or incorrect Cust double"
# define MSG_CUSTDECI255 "Cust double's decimal part can't be greater than 255"
# define MSG_CUSTDECIUNSET "Unset or incorrect Cust double's decimal part"
# define MSG_CUSTDOT "Missing '.' in Cust double"
# define MSG_CUSTZERO "Object double can't be set at zero"
# define MSG_CUSTEND "Cust line has unwanted elements ending it"
# define MSG_WINDZEROPAD "Wind double can't be zero-padded"
# define MSG_WIND255 "Wind double can't be greater than 255"
# define MSG_WINDUNSET "Unset or incorrect Wind double"
# define MSG_WINDDECI255 "Wind double's decimal part can't be greater than 255"
# define MSG_WINDDECIUNSET "Unset or incorrect Wind double's decimal part"
# define MSG_WINDDOT "Missing '.' in Wind double"
# define MSG_WINDZERO "Object double can't be set at zero"
# define MSG_WINDEND "Wind line has unwanted elements ending it"
# define MSG_INVALIDCHAR "Invalid char found in map"
# define MSG_NOPLAYER "No player found in map"
# define MSG_DOOR_BORDER "Doors can't be at border of map"
# define MSG_CENTER_DOOR "Doors must be between two walls and be accessible from both sides"
# define MSG_PORTAL_BORDER "Portals can't be at border of map"
# define MSG_CENTER_PORTAL "Portals must be between exactly three walls"
# define MSG_UNCLOSED "Map isn't closed"
# define MSG_UNCLOSEDBIS "Map isn't closed for second player"
# define MSG_UNCLOSEDPORTAL "Portal leads to unclosed room"
# define MSG_TOOMANYPLAYERS "More than 2 players in map"
# define MSG_NOLINK "Link missing for one of the portals"
# define MSG_UNUSEDLINK "No portal matching one of the links"
# define MSG_DOORTEXTURE "Missing D/DS line, no texture for doors"
# define MSG_OBJTEXTURE "Missing BT/PT/POSTT line, no texture for objs"
# define MSG_ANIMTEXTURE "Missing FRAME line, no texture for animated walls"
# define MSG_FDFDF "Failed to open map referenced by FDF line"
# define MSG_FDFEMPTY "Map referenced by FDF line is empty"
# define MSG_FDFVERT "Invalid line 'v' in fdf .obj file"
# define MSG_FDFZEROPAD "Fdf double can't be zero-padded"
# define MSG_FDF255 "Fdf double can't be greater than 255"
# define MSG_FDFUNSET "Unset or incorrect Fdf double"
# define MSG_FDFDECI255 "Fdf double's decimal part can't be greater than 255"
# define MSG_FDFDECIUNSET "Unset or incorrect Fdf double's decimal part"
# define MSG_FDFDOT "Missing '.' in Fdf double"
# define MSG_FDFZERO "Object double can't be set at zero"
# define MSG_FDFEND "Fdf line has unwanted elements ending it"

# if __linux__
#  define WIN_WIDTH 1800
#  define WIN_WIDTH_2 900
#  define WIN_HEIGHT 900
#  define WIN_HEIGHT_2 450
#  define MAP_RADIUS 150
#  define MAP_DIAMETER 300
# else
#  define WIN_WIDTH 1800//2560
#  define WIN_WIDTH_2 900//1280
#  define WIN_HEIGHT 900//1400
#  define WIN_HEIGHT_2 450//700
#  define MAP_RADIUS 150
#  define MAP_DIAMETER 300
# endif

# define WHITE 0xffffff
# define LIGHT_WHITE 0x949494
# define BLACK 0x0
# define RED 0xff0000
# define BROWNISH 0x6e4316
# define BLUEISH 0xC1FF
# define GREENISH 0x26E07
# define TRANSPARENT 0xff000000

# define WIN_FDFX 1000
# define WIN_FDFX_2 500
# define WIN_FDFY 1000
# define WIN_FDFY_2 500

# define PSIZE 5
# define ANIM_FPS 12
# define DOOR_TIMER 3000

# define M_PI_8 M_PI_4 / 2

// Enums
typedef enum e_side {
	EA,
	NO,
	WE,
	SO,
	DOOR,
	DOORSIDE,
	PORTAL,
	CUT,
	CIRCLE,
	CUSTOM, 
	ANIMATED
}			t_side;

typedef enum e_ground {
	FLOOR,
	CEILLING
}			t_ground;

typedef enum e_objtype {
	BARREL,
	PILLAR,
	POST,
	CUST,
	WIN, 
	FDF,
	HUMAN
}				t_objtype;

typedef enum e_doorstate {
	CLOSED,
	OPEN,
	CLOSING,
	OPENING
}				t_doorstate;

typedef enum e_state {
	IDLE,
	RUNNING,
	SHOOTING,
	DEAD
}				t_state;

enum {	//events supported on mac (only a fraction of what can be found on x11)
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum { //mouse buttons
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_WHEEL_DOWN = 4,
	MOUSE_WHEEL_UP = 5,
	MOUSE_WHEEL_RIGHT = 6,
	MOUSE_WHEEL_LEFT = 7
};

# if __linux__
enum {
	KEY_A = 113,
	KEY_D = 100,
	KEY_G = 103,
	KEY_M = 109,
	KEY_S = 115,
	KEY_W = 122,
	KEY_ESC = 65307,
	KEY_PLUS = 61,
	KEY_MINUS = 45,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_SHIFT = 65505,
	KEY_SPACE = 32,
	KEY_0 = 65438,
	KEY_1 = 65436,
	KEY_2 = 65433,
	KEY_3 = 65435,
	KEY_4 = 65430,
	KEY_5 = 65437,
	KEY_ASTERISK = 65450,
	KEY_PLUS_PAD = 65451,
	KEY_MINUS_PAD = 65453
};
# else
enum {
	KEY_A = 0,
	KEY_D = 2,
	KEY_G = 5,
	KEY_M = 46,
	KEY_S = 1,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_SHIFT = 257,
	KEY_SPACE = 49,
	KEY_0 = 82,
	KEY_1 = 83,
	KEY_2 = 84,
	KEY_3 = 85,
	KEY_4 = 86,
	KEY_5 = 87,
	KEY_ASTERISK = 67,
	KEY_PLUS_PAD = 69,
	KEY_MINUS_PAD = 78
};
# endif

#endif
