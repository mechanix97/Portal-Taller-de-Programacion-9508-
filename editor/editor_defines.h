#ifndef EDITOR_DEFINES_H
#define EDITOR_DEFINES_H

#define WINDOWS_SIZE_W 1920
#define WINDOWS_SIZE_H 1056

#define CELL_SIZE_W 32
#define CELL_SIZE_H 32

#define DIALOG_SIZE_W 640 
#define DIALOG_SIZE_H 240

#define QUANTITY_CELLS (((WINDOWS_SIZE_W)/(CELL_SIZE_W))*((WINDOWS_SIZE_H)/(CELL_SIZE_H)))

#define IDCLASS_NULL 0
#define IDCLASS_CHELL 1
#define IDCLASS_BLOQUE_ROCA 2
#define IDCLASS_BLOQUE_METAL 3
#define IDCLASS_COMPUERTA_REG 4
#define IDCLASS_COMPUERTA_AND 5
#define IDCLASS_COMPUERTA_OR 6
#define IDCLASS_BOTON 7
#define IDCLASS_RECEPTOR 8
#define IDCLASS_PASTEL 9
#define IDCLASS_ACIDO 10
#define IDCLASS_ROCA 11
#define IDCLASS_BARRERA_VERTICAL 12
#define IDCLASS_BARRERA_HORIZONTAL 13
#define IDCLASS_DIAGONAL_0 14
#define IDCLASS_DIAGONAL_90 15
#define IDCLASS_DIAGONAL_180 16
#define IDCLASS_DIAGONAL_270 17
#define IDCLASS_EMISOR_0 18
#define IDCLASS_EMISOR_90 19
#define IDCLASS_EMISOR_180 20
#define IDCLASS_EMISOR_270 21

#define DIR_IMAGEN_CHELL_A ":/resources/shell.png"
#define DIR_IMAGEN_BLOQUE_ROCA ":/resources/bloqueRoca.png"
#define DIR_IMAGEN_BLOQUE_METAL ":/resources/bloqueMetal.png"
#define DIR_IMAGEN_COMPUERTA_REG ":/resources/compuerta1.png"
#define DIR_IMAGEN_COMPUERTA_AND ":/resources/compuerta2.png"
#define DIR_IMAGEN_COMPUERTA_OR ":/resources/compuerta3.png"
#define DIR_IMAGEN_BOTON ":/resources/boton.png"
#define DIR_IMAGEN_RECEPTOR ":/resources/receptorEnergia270.png"
#define DIR_IMAGEN_PASTEL ":/resources/cake.png"
#define DIR_IMAGEN_ACIDO ":/resources/acido2.png"
#define DIR_IMAGEN_ROCA ":/resources/roca1.png"
#define DIR_IMAGEN_BARRERA_V ":/resources/barreraDeEnergiaVertical.png"
#define DIR_IMAGEN_BARRERA_H ":/resources/barreraDeEnergiaHorizontal.png"
#define DIR_IMAGEN_DIAGONAL_0 ":/resources/bloquesMetalDiagonal0.png"
#define DIR_IMAGEN_DIAGONAL_90 ":/resources/bloquesMetalDiagonal90.png"
#define DIR_IMAGEN_DIAGONAL_180 ":/resources/bloquesMetalDiagonal180.png"
#define DIR_IMAGEN_DIAGONAL_270 ":/resources/bloquesMetalDiagonal270.png"
#define DIR_IMAGEN_EMISOR_0 ":/resources/emisorEnergia0.png"
#define DIR_IMAGEN_EMISOR_90 ":/resources/emisorEnergia90.png"
#define DIR_IMAGEN_EMISOR_180 ":/resources/emisorEnergia180.png"
#define DIR_IMAGEN_EMISOR_270 ":/resources/emisorEnergia270.png"

#endif // EDITOR_DEFINES_H
