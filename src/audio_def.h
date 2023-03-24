#define XA_LENGTH(x) (((u64)(x) * 75) / 100 * IO_SECT_SIZE) //Centiseconds to sectors in bytes (w)

typedef struct
{
	XA_File file;
	u32 length;
} XA_TrackDef;

static const XA_TrackDef xa_tracks[] = {
	//MENU.XA
	{XA_Menu, XA_LENGTH(11300)}, //XA_GettinFreaky
	{XA_Menu, XA_LENGTH(3800)},  //XA_GameOver
	//1.XA
	{XA_1, XA_LENGTH(7700)}, //XA_Bopeebo
	{XA_1, XA_LENGTH(8000)}, //XA_Fresh
	//2.XA
	{XA_2, XA_LENGTH(8700)}, //XA_Dadbattle
	{XA_2, XA_LENGTH(6800)}, //XA_Tutorial
};

static const char *xa_paths[] = {
	"\\MUSIC\\MENU.XA;1",   //XA_Menu
	"\\MUSIC\\1.XA;1", //XA_1
	"\\MUSIC\\2.XA;1", //XA_2
	NULL,
};

typedef struct
{
	const char *name;
	boolean vocal;
} XA_Mp3;

static const XA_Mp3 xa_mp3s[] = {
	//MENU.XA
	{"freaky", false},   //XA_GettinFreaky
	{"gameover", false}, //XA_GameOver
	//WEEK1A.XA
	{"bopeebo", true}, //XA_Bopeebo
	{"fresh", true},   //XA_Fresh
	//WEEK1B.XA
	{"dadbattle", true}, //XA_Dadbattle
	{"tutorial", false}, //XA_Tutorial
	
	{NULL, false}
};
