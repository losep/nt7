// This program is a part of NT MudLIB

inherit  ROOM;

void create()
{
        set("short",  "长廊");
        set("long",  @LONG
这里是游府的长廊，不少家丁和仆妇正在四处忙碌。
LONG);
        set("exits",  ([  /*  sizeof()  ==  2  */
                "west"  :  __DIR__"changlang5",
                "east"  :  __DIR__"xiaofotang",
                "south" :  __DIR__"yanwuchang",
        ]));

        setup();
        //replace_program(ROOM);
}

#include "/maze/juxianzhuang/zhuang.h"
