# Skips these instructions that load from the player's vtable and does a null check
nop # lwz	r3, -0x7FC4 (r13)
nop # cmpwi	r3, 0
nop # beq-	 ->0x80131E44
nop # lwz	r9, 0x0004 (r3)
nop # lwz	r0, 0x020C (r9)
nop # cmpwi	r3, 0

# Jumps to custom function
bl gamedraw_loop
