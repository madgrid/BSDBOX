/* BSDBOX Twilight Scheme DWM 6.1 config.h */

/* appearance */
static const char *fonts[] = {
	"Monaco:size=12"
};
static const char dmenufont[]       = "Monaco:size=12";
static const char normbordercolor[] = "#222222";
static const char normbgcolor[]     = "#181512";
static const char normfgcolor[]     = "#FFFFD4";
static const char selbordercolor[]  = "#C06D44";
static const char selbgcolor[]      = "#C06D44";
static const char selfgcolor[]      = "#FFFFD4";
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging */
static const char *tags[] = { "BSDBOX--»", "www", "irc", "term", "edit", "devel" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "><>",      NULL },    /* first entry is default */
	{ "[]=",      tile },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", "-e", "bash", NULL };
static const char *irccmd[] = { "urxvt", "-e", "irssi", NULL };
static const char *editcmd[] = { "geany", NULL };
static const char *lxappcmd[] = { "lxappearance", NULL };
static const char *filecmd[] = { "thunar", NULL };
static const char *mccmd[] = { "urxvt", "-e", "mc", NULL };
static const char *openshot[] = { "openshot", NULL };
static const char *netcmd[] = { "firefox", NULL };
static const char *gimpcmd[] = { "gimp", NULL };
static const char *padcmd[] = { "leafpad", NULL };
static const char *lxmusic[] = { "lxmusic", NULL };
static const char *nitrogen[] = { "nigtrogen", NULL };
/* Black Template for Key Bindings
static const char *blank[] = { "", NULL };
static const char *blank[] = { "", NULL };
*/
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_i,      spawn,          {.v = irccmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = editcmd } },
    { MODKEY,                       XK_l,      spawn,          {.v = lxappcmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = filecmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = netcmd } },
	{ MODKEY,                       XK_g,      spawn,          {.v = gimpcmd } },
	{ MODKEY,                       XK_m,      spawn,          {.v = mccmd } },
    { MODKEY,                       XK_d,      spawn,          {.v = padcmd } },
    { MODKEY,                       XK_a,      spawn,          {.v = lxmusic } },
    { MODKEY,                       XK_n,      spawn,          {.v = nitrogen } },  
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
        /* click                event mask      button          function        argument */
        { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
        { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
        { ClkWinTitle,          0,              Button2,        zoom,           {0} },
        { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
        { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
        { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
        { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
        { ClkTagBar,            0,              Button1,        view,           {0} },
        { ClkTagBar,            0,              Button3,        toggleview,     {0} },
        { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
        { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

