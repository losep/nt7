#include <ansi.h>

inherit COMBINED_ITEM;
#include "/clone/quarry/item/meat.h"

void create()
{
        set_name(NOR + WHT "狼肉" NOR, ({ "lang rou", "lang", "rou" }));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", NOR + WHT "这是一块散发着腥臊臭的狼肉。\n" NOR);
                set("base_unit", "块");
                set("base_value", 20);
        }
        set("maze_item", 1);
        setup();
        set_amount(1);
}