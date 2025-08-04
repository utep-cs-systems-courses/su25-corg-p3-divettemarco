	.global reset_vars
	.extern sleeping, buzzing, ledBlink, tvColor, greenLight, goCar, setZero, setOne

reset_vars:
	mov.w setZero, sleeping
	mov.w setZero, buzzing
	mov.w setZero, ledBlink
	mov.w setZero, tvColor
	mov.w
