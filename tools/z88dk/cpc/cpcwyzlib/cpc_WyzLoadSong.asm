; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007           **
; ******************************************************

GLOBAL cpc_WyzLoadSong

GLOBAL cpc_WyzPlayer
GLOBAL CARGA_CANCION_WYZ

.cpc_WyzLoadSong	
	;LD HL,2
	;ADD HL,SP
	;LD A,(HL)
	ld a,l
	JP CARGA_CANCION_WYZ+cpc_WyzPlayer
