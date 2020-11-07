; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007       **
; ******************************************************

GLOBAL cpc_SuperbufferAddress		;calcula la posici�n en el superbuffer seg�n las coordenadas	
								;del sprite y lo actualiza

GLOBAL tiles_tocados
GLOBAL pantalla_juego					;datos de la pantalla, cada byte indica un tile
GLOBAL posiciones_super_buffer
GLOBAL tiles
GLOBAL ancho_pantalla_bytes 
GLOBAL posicion_inicial_superbuffer

.cpc_SuperbufferAddress
   ; ld ix,2
   ; add ix,sp

   ; ld l,(ix+0)
   ; ld h,(ix+1)	;HL apunta al sprite
      
    push hl
    pop ix
    
  ;lo cambio para la rutina de multiplicar 
    ld a,(ix+8)
    ld e,(ix+9)
 	include "multiplication1.asm"
 		


	ld b,0
	ld c,a
	add hl,bc
	ld de,posicion_inicial_superbuffer
	add hl,de
	;hl apunta a la posici�n en buffer (destino)
    ld (ix+4),l
    ld (ix+5),h
    ret
    
    ;defb 'm','m','x'