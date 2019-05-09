#ifdef __wasilibc_unmodified_upstream // WASI has no termios
#include <termios.h>
#endif
#define T(t) (t*)0;
#define F(t,n) {t *y = &x.n;}
#define C(n) switch(n){case n:;}
static void f()
{
#ifdef __wasilibc_unmodified_upstream // WASI has no termios
T(cc_t)
T(speed_t)
T(tcflag_t)
T(pid_t)
{
struct termios x;
F(tcflag_t,c_iflag)
F(tcflag_t,c_oflag)
F(tcflag_t,c_cflag)
F(tcflag_t,c_lflag)
F(cc_t,c_cc[NCCS])
}
C(NCCS)
C(VEOF)
C(VEOL)
C(VERASE)
C(VINTR)
C(VKILL)
C(VMIN)
C(VQUIT)
C(VSTART)
C(VSTOP)
C(VSUSP)
C(VTIME)
C(BRKINT)
C(ICRNL)
C(IGNBRK)
C(IGNCR)
C(IGNPAR)
C(INLCR)
C(INPCK)
C(ISTRIP)
C(IXANY)
C(IXOFF)
C(IXON)
C(PARMRK)
C(OPOST)
#ifdef _XOPEN_SOURCE
C(ONLCR)
C(OCRNL)
C(ONOCR)
C(ONLRET)
C(OFDEL)
C(OFILL)
C(NLDLY)
C(NL0)
C(NL1)
C(CRDLY)
C(CR0)
C(CR1)
C(CR2)
C(CR3)
C(TABDLY)
C(TAB0)
C(TAB1)
C(TAB2)
C(TAB3)
C(BSDLY)
C(BS0)
C(BS1)
C(VTDLY)
C(VT0)
C(VT1)
C(FFDLY)
C(FF0)
C(FF1)
#endif
C(B0)
C(B50)
C(B75)
C(B110)
C(B134)
C(B150)
C(B200)
C(B300)
C(B600)
C(B1200)
C(B1800)
C(B2400)
C(B4800)
C(B9600)
C(B19200)
C(B38400)
C(CSIZE)
C(CS5)
C(CS6)
C(CS7)
C(CS8)
C(CSTOPB)
C(CREAD)
C(PARENB)
C(PARODD)
C(HUPCL)
C(CLOCAL)
C(ECHO)
C(ECHOE)
C(ECHOK)
C(ECHONL)
C(ICANON)
C(IEXTEN)
C(ISIG)
C(NOFLSH)
C(TOSTOP)
C(TCSANOW)
C(TCSADRAIN)
C(TCSAFLUSH)
C(TCIFLUSH)
C(TCIOFLUSH)
C(TCOFLUSH)
C(TCIOFF)
C(TCION)
C(TCOOFF)
C(TCOON)
{speed_t(*p)(const struct termios*) = cfgetispeed;}
{speed_t(*p)(const struct termios*) = cfgetospeed;}
{int(*p)(struct termios*,speed_t) = cfsetispeed;}
{int(*p)(struct termios*,speed_t) = cfsetospeed;}
{int(*p)(int) = tcdrain;}
{int(*p)(int,int) = tcflow;}
{int(*p)(int,int) = tcflush;}
{int(*p)(int,struct termios*) = tcgetattr;}
{pid_t(*p)(int) = tcgetsid;}
{int(*p)(int,int) = tcsendbreak;}
{int(*p)(int,int,const struct termios*) = tcsetattr;}
#endif
}
