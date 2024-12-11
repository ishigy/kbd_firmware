VIA_ENABLE = yes
# VIAL_ENABLE = yes
# VIAL_INSECURE = yes

SRC +=  nicola.c \
	key_duration.c

# 16-bit timer (TIMER1) を使用したタイムアウト
# 一定時間経過すると、key down 状態のままでもキーが出力される
OPT_DEFS = -DTIMEOUT_INTERRUPT

EXTRAFLAGS += -flto
