; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007       **
; ******************************************************



GLOBAL cpc_UpdScr			;recoge los tiles tocados, los restaura-
GLOBAL tiles_tocados
GLOBAL pantalla_juego					;datos de la pantalla, cada byte indica un tile
GLOBAL posiciones_super_buffer
GLOBAL tiles


GLOBAL ancho_pantalla_bytes




.cpc_UpdScr
;lee la tabla de tiles tocados y va restaurando cada uno en su sitio.

	LD IX,tiles_tocados
.bucle_cpc_UpdScr	
	LD E,(IX+0)
	LD A,$FF
	CP E
	RET Z		;RETORNA SI NO HAY M�S DATOS EN LA LISTA
	LD D,(IX+1)
	INC IX
	INC IX


	

	
.posicionar_superbuffer 
;con la coordenada y nos situamos en la posici�n vertical y con x nos movemos a su sitio definitivo
	LD c,D
	SLA c
	
	;LD C,A	;x2
	LD B,0
	LD HL,posiciones_super_buffer
	ADD HL,BC
	LD C,(HL)
	INC HL
	LD B,(HL)	
	
	LD l,E
	SLA l
	;LD L,A
	LD H,0
	
	ADD HL,BC
	;HL apunta a la posici�n correspondiente en superbuffer
	;RET	
	push hl
	
.posicionar_tile	



;h*e+a
;;;; ___________________________________________________
;;;; RUTINA PARA GEN�RICA PARA MULTIPLICAR 

	ld a,e
	ld e,d

	include "multiplication2.asm"

	ld e,a
	LD D,0
	ADD HL,DE
; EN HL DEBE QUEDAR EL NUMERO MULTIPLICADO POR EL ANCHO EN TILES DE LA PANTALLA	
;;;; ___________________________________________________


	
	LD DE,pantalla_juego
	ADD HL,DE
	
	LD L,(HL)
	LD H,0

	ADD HL,HL
	ADD HL,HL
	ADD HL,HL
	ADD HL,HL	;X16
	LD DE,tiles
	ADD HL,DE
	;HL apunta a los datos del tile
	
	;ex de,hl
	pop de ;hl
	;RET
	

.transferir_map_sbuffer	
	ld bc,ancho_pantalla_bytes-2 ;63
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi
	ex de,hl
	ld c,ancho_pantalla_bytes-2
	add HL,BC	
		ex de,hl
	ldi
	ldi

jp bucle_cpc_UpdScr

