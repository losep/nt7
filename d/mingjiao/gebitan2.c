//gebitan2.c

inherit ROOM;

void create()
{
        set("short", "戈壁滩");
        set("long", @LONG
眼前是一望无际的戈壁滩，没有路标，也没有一个行人，天显得
很高，远山披雪，苍鹰翱翔，走在这茫茫戈壁之上，你似乎迷路了。
LONG );
         set("outdoors", "mingjiao");
        set("exits",([
            "east" : __DIR__"gebitan1",
            "west" : __DIR__"gebitan3",        
            "north" : __DIR__"gebitan2",
            "south" : __DIR__"gebitan2",                                  
        ]));
        set("objects", ([
                __DIR__"obj/xiaohuangshi": random(3),
        ]));
        setup();
        replace_program(ROOM);
}