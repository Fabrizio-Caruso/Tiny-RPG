; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007       **
; ******************************************************

GLOBAL cpc_PrintGphStrXY

GLOBAL cpc_GetScrAddress0


GLOBAL cpc_PrintGphStr0
GLOBAL direcc_destino0
.cpc_PrintGphStrXY
;preparaci�n datos impresi�n. El ancho y alto son fijos!
	ld ix,2
	add ix,sp
	

 	ld L,(ix+0)
	ld A,(ix+2)	;pantalla
	
	call cpc_GetScrAddress0   
	;ld (cpc_PrintGphStr0+direcc_destino0),hl
	;ex de,hl
	;destino
	
   	ld e,(ix+4)
	ld d,(ix+5)	;texto origen
	xor a
    
 JP cpc_PrintGphStr0