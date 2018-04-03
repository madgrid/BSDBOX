xmodmap -e "pointer = 1 2 3 5 4"   &
xset led 3 &
xset -dpms
xset s off
xset s noexpose
xset s noblank
export LANG="en_US.UTF-8"
export LC_ALL="en_US.UTF-8"
export LC_CTYPE="en_US.UTF-8"
export LC_COLLATE="en_US.UTF-8"
export LC_MESSAGES="en_US.UTF-8"
xset +fp $HOME/.font &
#nitrogen --restore &
feh --bg-scale ~/bsdbox-bg5.png &
compton &
while true
do
#UPTIME=$(uptime)
XMMS2NP=$(xmms2np)
MEMUSE=$(memuse)
UPTIMEDWM=$(uptimedwm)
TIMEDWM=$(timedwm)
xsetroot -name "$XMMS2NP - Mem: $MEMUSE - Uptime: $UPTIMEDWM - $TIMEDWM" 
sleep 1
done &
exec dwm


