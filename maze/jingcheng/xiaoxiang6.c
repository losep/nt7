#include <ansi.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"小巷内"NOR);
        set("long", @LONG
这里是京城街头的小巷，里面三三两两来往着些着装怪异的人群，你忍不住朝
其中的一位多看了两眼，只见对方满脸凶横，看来还是少惹为妙，赶快离开的好。
LONG
        );
        set("indoors", "city");
        set("exits", ([
                "northeast"  :  __DIR__"dadao",
                "southeast"  :  __DIR__"dadao",
                "northwest"  :  __DIR__"dadao",
                "southwest"  :  __DIR__"dadao",
        ]));
        set("no_fly",1);
        setup();
        replace_program(ROOM);
}

