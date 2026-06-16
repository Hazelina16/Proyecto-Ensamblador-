
global contarCaracteres
global validarMovimiento
global calcularPuntaje
global detectarObjeto
global contarCeldasLibres

section .text

    ;DATOS
    ;RCX = direccion del mapa
    ;RDX = total de celdas
    ;R8B = caracter a buscar
    ;RAX = contador
    ;R9 = 
    

;contar caracteres en el mapa

contarCaracteres:
    XOR RAX, RAX
    XOR R9, R9

recorrerMapa:
    CMP R9, RDX
    JGE finContarCaracteres
    MOV BL, [RCX + R9]
    CMP BL, R8B
    JNE siguienteCelda
    INC RAX

siguienteCelda:
    INC R9
    JMP recorrerMapa

finContarCaracteres:
    RET

;validar movimientos del jugador

validarMovimiento:
    MOV R10, R8
    IMUL R10, RDX
    ADD R10, R9
    MOV AL, [RCX + R10]
    CMP AL, '#'
    JE movimientoBloqueado

movimientoValido:
    MOV RAX, 1
    RET

movimientoBloqueado:
    XOR RAX, RAX
    RET

;calcular puntajes del jugador

calcularPuntaje:
    MOV RAX, RCX
    IMUL RAX, 100
    MOV R10, R8
    IMUL R10, 500
    ADD RAX, R10
    MOV R11, RDX
    IMUL R11, 2
    SUB RAX, R11
    RET

;detectar objetos en el mapa

detectarObjeto:
    MOV R10B, byte [RSP + 40]
    MOV R11, R8
    IMUL R11, RDX
    ADD R11, R9
    MOV AL, [RCX + R11]
    CMP AL, R10B
    JE objetoEncontrado

objetoNoEncontrado:
    XOR RAX, RAX
    RET

objetoEncontrado:
    MOV RAX, 1
    RET

; contar celdas libres en el mapa

contarCeldasLibres:
    XOR RAX, RAX
    XOR R8, R8

recorrerLibres:
    CMP R8, RDX
    JGE finencontrarLibres
    MOV BL, [RCX + R8]
    CMP BL, '.'
    JE siguienteLibre
    INC RAX

siguienteLibre:
    INC R8
    JMP recorrerLibres

finencontrarLibres:
    RET
    