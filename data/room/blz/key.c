// File(/data/room/blz/key.c) of blz's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

int query_autoload() { return 1; }

void create()
{
        set_name(YEL "暴雪家的钥匙" NOR, ({ "key", "1 of blz" }));
        set_weight(10);
        set("long", @LONG
一把用来开启逍遥洞(blz)的钥匙。
这是原配钥匙。
LONG );
        set("unit", "把");
        set("no_pawn", 1);
        set("no_sell", 1);
        set("no_store", 1);
        set("item_make", 1);
        set("value", 1);
}
