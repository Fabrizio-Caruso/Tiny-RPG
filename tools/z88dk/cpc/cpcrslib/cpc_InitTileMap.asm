; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007           **
; ******************************************************

GLOBAL cpc_InitTileMap


GLOBAL tiles

.cpc_InitTileMap

	;*LD IX,2
	;*ADD IX,SP
	
	;*LD L,(IX+0)
	;*LD H,(IX+1)
	LD (tiles),HL
	RET