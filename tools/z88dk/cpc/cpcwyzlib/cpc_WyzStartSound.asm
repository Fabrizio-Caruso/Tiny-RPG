; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007           **
; ******************************************************

GLOBAL cpc_WyzStartSound	;No se suele usar directamente. No lo meto en librer�a.

GLOBAL INICIA_SONIDO_WYZ

.cpc_WyzStartSound
	LD HL,2
	ADD HL,SP
	LD A,(HL)
	JP INICIA_SONIDO_WYZ